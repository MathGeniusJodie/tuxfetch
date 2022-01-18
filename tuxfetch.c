//usr/bin/clang tuxfetch.c -lpthread -Wpedantic -std=c11 -O3 -g3 -o tuxfetch; exec ./tuxfetch

#define MAX_LENGTH 50

// replace cpuid.h with this for tcc support
int __get_cpuid(unsigned int leaf, unsigned int *a, unsigned int *b,
                unsigned int *c, unsigned int *d) {

	__asm__ __volatile__("cpuid\n\t"
	                     : "=a"(*a), "=b"(*b), "=c"(*c), "=d"(*d)
	                     : "0"(leaf));
	return 1;
}

//#include <cpuid.h>
#include <ctype.h>
#define _GNU_SOURCE
#define _LARGEFILE64_SOURCE
#define __USE_LARGEFILE64
#include <dirent.h> // pacman package count and wm fetch
#include <fcntl.h>  // open
#include <linux/limits.h>
#include <stdbool.h>
#include <stddef.h> // offsetof
#include <stdio.h>  // printf
#include <stdlib.h> // malloc
#include <string.h>
#include <sys/mman.h>    // mmap
#include <sys/stat.h>    // get size of file
#include <sys/sysinfo.h> // uptime fetch
#include <sys/time.h>    // benchmarking
#include <sys/utsname.h> // kernel fetch
#include <syscall.h>     // dirents
#include <threads.h>
#include <unistd.h> // read

#define TIME_INIT struct timeval start, end
#define TIME_START gettimeofday(&start, NULL)
#define TIME_END                                                               \
	gettimeofday(&end, NULL);                                                  \
	printf("\033[90mtime %lu us\033[0m\n",                                     \
	       (end.tv_sec - start.tv_sec) * 1000000 + end.tv_usec -               \
	           start.tv_usec)

char tux[] = "\033[1m\n\
\033[37m       ,--.   \n\
\033[37m      |0\033[33m_\033[37m0 |\n\
\033[37m      |\033[33mL_/\033[37m |\n\
\033[37m     //   \\ \\  \n\
\033[37m    ((     ) )    \n\
\033[33m   /`\\     /`\\ \033[37m \n\
\033[33m   \\__)\033[37m===\033[33m(__/\033[37m ";

void read_first_line(char *path, char *buffer, size_t size) {
	int file = open(path, O_RDONLY);
	buffer[read(file, buffer, size) - 1] = '\0'; // remove newline
	close(file);
}

char *read_file(char *path) {
	size_t chunk_size = 65536;
	int file = open(path, O_RDONLY);
	char *buffer = malloc(0);
	size_t total_length = 0;
	while (true) {
		buffer = realloc(buffer, total_length + chunk_size);
		size_t length = read(file, buffer + total_length, chunk_size);
		if (!length)
			break;
		total_length += length;
	}
	buffer[total_length - 1] = '\0';
	close(file);
	return buffer;
}

pid_t ppid_from_pid(pid_t pid) {
	char path[PATH_MAX];
	snprintf(path, PATH_MAX, "/proc/%d/stat", pid);
	char *buffer = read_file(path);
	buffer = strrchr(buffer, ')') + 2;
	pid_t ppid;
	sscanf(buffer, "%*c %d", &ppid);
	return ppid;
}

char *name_from_pid(pid_t pid) {
	char path[PATH_MAX];
	char *name = malloc(MAX_LENGTH);
	snprintf(path, PATH_MAX, "/proc/%d/comm", pid);
	read_first_line(path, name, MAX_LENGTH);
	return name;
}

#define WM_COUNT 41
#define WM_NAME_LENGTH 16
static char wms[WM_COUNT][WM_NAME_LENGTH] = {"9wm",
                                             "awesome",
                                             "blackbox",
                                             "bspwm",
                                             "compiz",
                                             "dwl",
                                             "dwm",
                                             "enlightenment",
                                             "evilwm",
                                             "fluxbox",
                                             "gnome-shell",
                                             "herbstluftwm",
                                             "i3",
                                             "icewm",
                                             "leftwm",
                                             "jwm",
                                             "kwin_x11",
                                             "kwin_wayland",
                                             "matchbox",
                                             "metacity",
                                             "mutter",
                                             "openbox",
                                             "pekwm",
                                             "qtile",
                                             "spectrwm",
                                             "sowm",
                                             "sway",
                                             "twm",
                                             "waymonad",
                                             "weston",
                                             "xfwm",
                                             "xmonad"
                                             "lwm",
                                             "flwm",
                                             "aewm",
                                             "wmx",
                                             "wm2",
                                             "ratpoison",
                                             "labwc",
                                             "waybox",
                                             "newm"};

bool dir_find(int dir, bool callback(int, struct dirent64 *, void *),
              void *userdata) {
	int sum = 0;
	size_t dirent_size = offsetof(struct dirent64, d_name) + NAME_MAX + 1;
	char buffer[dirent_size];

	while (true) {
		size_t entries_length =
			syscall(SYS_getdents64, dir, buffer, dirent_size);
		if (entries_length <= 0)
			break;
		for (int p = 0; p < entries_length;) {
			struct dirent64 *entry = (struct dirent64 *)(buffer + p);
			p += entry->d_reclen;
			if (callback(dir, entry, userdata)) {
				return true;
			}
		}
	}
	return false;
}

int dir_sumby(int dir, int callback(int, struct dirent64 *, void *),
              void *userdata) {
	int sum = 0;
	size_t dirent_size = offsetof(struct dirent64, d_name) + NAME_MAX + 1;
	char buffer[dirent_size];

	while (true) {
		size_t entries_length =
			syscall(SYS_getdents64, dir, buffer, dirent_size);
		if (entries_length <= 0)
			break;
		for (int p = 0; p < entries_length;) {
			struct dirent64 *entry = (struct dirent64 *)(buffer + p);
			p += entry->d_reclen;
			sum += callback(dir, entry, userdata);
		}
	}
	return sum;
}

int dirent_isdir(int dir, struct dirent64 *entry, void *userdata) {
	return entry->d_type == DT_DIR;
}

bool path_find(char *path, bool callback(int, struct dirent64 *, void *),
               void *userdata) {
	int dir = open(path, O_RDONLY | O_DIRECTORY);
	if (dir == -1)
		return false;
	bool ret = dir_find(dir, callback, userdata);
	close(dir);
	return ret;
}

int path_sumby(char *path, int callback(int, struct dirent64 *, void *),
               void *userdata) {
	int dir = open(path, O_RDONLY | O_DIRECTORY);
	if (dir == -1)
		return 0;
	int ret = dir_sumby(dir, callback, userdata);
	close(dir);
	return ret;
}

bool dirent_is_wm(int proc_dir, struct dirent64 *entry, void *userdata) {
	char *process_name = userdata;
	// check if process directory (dir name is a number)
	if (isdigit(entry->d_name[0])) {
		int pid_dir = openat(proc_dir, entry->d_name, O_RDONLY | O_DIRECTORY);
		int comm_file = openat(pid_dir, "comm", O_RDONLY);
		close(pid_dir);
		size_t length = read(comm_file, process_name, WM_NAME_LENGTH);
		close(comm_file);
		// remove trailing newline
		process_name[length - 1] = '\0';
		for (int j = 0; j < WM_COUNT; j++) {
			if (!strcmp(wms[j], process_name)) {
				return true;
			}
		}
	}
	return false;
}

int fetch_wm() {
	char wm_name[WM_NAME_LENGTH] = "not found";
	path_find("/proc/", dirent_is_wm, wm_name);
	printf("\033[18C%13s%s\n", "WM: ", wm_name);
	return 0;
}

int fetch_terminal() {
	char *terminal = name_from_pid(ppid_from_pid(getppid()));
	printf("\033[18C%13s%s (%s)\n", "terminal: ", terminal, getenv("TERM"));
	return 0;
}

int fetch_model() {
	char name[MAX_LENGTH];
	read_first_line("/sys/class/dmi/id/product_name", name, MAX_LENGTH);
	char version[MAX_LENGTH];
	read_first_line("/sys/class/dmi/id/product_version", version, MAX_LENGTH);
	printf("\033[18C%13s%s %s\n", "model: ", name, version);
	return 0;
}

int fetch_uname() {
	struct utsname uname_info;
	uname(&uname_info);
	printf("\033[18C%13s%s\n", "kernel: ", uname_info.release);
	printf("\033[18C%13s%s\n", "host: ", uname_info.nodename);
	return 0;
}

int fetch_os(char *buffer) {
	char *id = strstr(buffer, "NAME=");
	static char name[MAX_LENGTH];
	sscanf(id, "NAME=\"%[^\"]+", name);
	printf("\033[18C%13s%s\n", "OS: ", name);
	return 0;
}

char alpine_logo[] = "\033[1m\n\
\033[31m   .8BBBBBBBBB.  \n\
\033[33m  .888888888888. \n\
\033[32m .8888* *88*8888.\n\
\033[36m 888* ,8, `. *888\n\
\033[36m `* ,88888, `, *`\n\
\033[34m  `888888888888` \n\
\033[35m   `8BBBBBBBBB`   ";

char arch_logo[] = "\033[1m\n\
\033[31m        A \n\
\033[31m       a8s \n\
\033[33m      ao88s \n\
\033[32m     a88888s \n\
\033[36m    a88Y*Y88s \n\
\033[34m   a88H   B8bs \n\
\033[35m  /*`       `*\\ ";

char celos_logo[] = "\033[1m\n\
\033[35m    _~a8B6s~_   \n\
\033[35m  .88888`  `Y6, \n\
\033[35m  J8888:     8l \n\
\033[35m  B88888,  .d88 \n\
\033[35m  V8P* `Y88888P \n\
\033[35m  `9b, .d88888` \n\
\033[35m    `~9BBB8~`   ";

char debian_logo[] = "\033[1m\n\
\033[31m    ,gA88bq.  \n\
\033[33m   dP      `9.\n\
\033[32m  d7  ,*`.  )8\n\
\033[36m  9:  A    ,Q*\n\
\033[34m  *1  `^vsv\" \n\
\033[35m   *b         \n\
\033[35m     \"~. ";

char mint_logo[] = "\033[1m\n\
\033[32m BBBBBBBBBBBs~. \n\
\033[32m BB8  88**88**8,\n\
\033[32m   H  H  a  a  l\n\
\033[32m   H  H  H  H  H\n\
\033[32m   V, *88888* .H\n\
\033[32m   `8,_______.=H\n\
\033[32m     *YBBBBBBBBH ";

char ubuntu_logo[] = "\033[1m\n\
\033[31m          \033[35m($)\n\
\033[31m    \033[33m .\033[31m s88~..\n\
\033[31m    \033[33m.8*  \033[31m `*9.\n\
\033[31m \033[31m($) \033[33m8\n\
\033[31m    \033[33m`6-  \033[35m _-8`\n\
\033[31m     \033[33m`\033[35m ^88*``\n\
\033[31m          \033[33m($) ";

int fetch_art(char *buffer) {
	char *id = strstr(buffer, "\nID=");
	static char os_id[MAX_LENGTH];
	sscanf(id, "\nID=%[^\n]", os_id);

	if (strcmp("alpine", os_id) == 0) {
		write(1, alpine_logo, sizeof(alpine_logo));
	}
	if (strcmp("arch", os_id) == 0) {
		write(1, arch_logo, sizeof(arch_logo));
	}
	if (strcmp("celos", os_id) == 0) {
		write(1, celos_logo, sizeof(celos_logo));
	}
	if (strcmp("debian", os_id) == 0) {
		write(1, debian_logo, sizeof(debian_logo));
	}
	if (strcmp("mint", os_id) == 0) {
		write(1, mint_logo, sizeof(mint_logo));
	}
	if (strcmp("ubuntu", os_id) == 0) {
		write(1, ubuntu_logo, sizeof(ubuntu_logo));
	}

	return 0;
}

int fetch_uptime() {
	struct sysinfo a;
	sysinfo(&a);
	unsigned long long seconds = a.uptime;
	unsigned long long minute = 60;
	unsigned long long hour = 60 * minute;
	unsigned long long day = 24 * hour;
	printf("\033[18C%13s%llu%c %llu%c %llu%c\n", "uptime: ", seconds / day, 'd',
	       (seconds % day) / hour, 'h', (seconds % hour) / minute, 'm');
	return 0;
}

int fetch_packages_apk() {
	int file = open("/lib/apk/db/installed", O_RDONLY);
	struct stat filestat;
	fstat(file, &filestat);
	if (filestat.st_size == 0)
		return 0;
	char *buffer = mmap(NULL, filestat.st_size, PROT_READ, MAP_SHARED, file, 0);
	int packages = 0;
	size_t bytes = filestat.st_size - 1;

	for (size_t i = 0; i < bytes; i++) {
		packages += (buffer[i] == '\n') & (buffer[i + 1] == 'P');
	}

	close(file);
	return packages;
}

int fetch_packages_dpkg() {
	int file = open("/var/lib/dpkg/status", O_RDONLY);
	struct stat filestat;
	fstat(file, &filestat);
	if (filestat.st_size == 0)
		return 0;
	char *buffer = mmap(NULL, filestat.st_size, PROT_READ, MAP_SHARED, file, 0);
	int packages = 0;
	size_t bytes = filestat.st_size - 1;

	for (size_t i = 0; i < bytes; i++) {
		packages += (buffer[i] == '\n') & (buffer[i + 1] == 'I');
	}

	close(file);
	return packages;
}

int fetch_packages() {
	int packages = 0;
	char *package_manager = "unknown";
	int pacman_dir = open("/var/lib/pacman/local", O_RDONLY | O_DIRECTORY);

	if (pacman_dir != -1) {
		packages += dir_sumby(pacman_dir, dirent_isdir, NULL);
		package_manager = "pacman";
	} else if (!access("/lib/apk/db/installed", R_OK)) {
		packages += fetch_packages_apk();
		package_manager = "apk";
	} else if (!access("/var/lib/dpkg/status", R_OK)) {
		packages += fetch_packages_dpkg();
		package_manager = "dpkg";
	}

	int flatpaks = path_sumby("/var/lib/flatpak/app", dirent_isdir, NULL) +
	               path_sumby("/var/lib/flatpak/runtime", dirent_isdir, NULL);

	printf("\033[18C%13s%d (%s) %d (flatpak)\n", "packages: ", packages,
	       package_manager, flatpaks);

	return 0;
}

int fetch_env() {
	printf("\033[18C%13s%s\n", "shell: ", getenv("SHELL"));
	printf("\033[18C%13s%s\n", "username: ", getenv("USER"));
	char *desktop = getenv("XDG_CURRENT_DESKTOP");
	if (!desktop)
		desktop = "none";
	printf("\033[18C%13s%s\n", "DE: ", desktop);
	return 0;
}

#ifdef __x86_64__
int fetch_cpu() {
	static char cpu[48];
	unsigned int *x = (unsigned int *)cpu;

	__get_cpuid(0x80000002, x + 0, x + 1, x + 2, x + 3);
	__get_cpuid(0x80000003, x + 4, x + 5, x + 6, x + 7);
	__get_cpuid(0x80000004, x + 8, x + 9, x + 10, x + 11);

	// remove duplicate spaces at the end
	for (int i = 47; i--;) {
		if (cpu[i] != ' ') {
			cpu[i + 1] = '\0';
			break;
		}
	}

	printf("\033[18C%13s%s (%ld)\n", "CPU: ", cpu,
	       sysconf(_SC_NPROCESSORS_CONF));
	return 0;
}
#else
int fetch_cpu() {
	char *buffer = read_file("/proc/cpuinfo");
	char *line = strstr(buffer, "model name	: ");
	char cpu[MAX_LENGTH];
	sscanf(line, "model name	: %[^\n]", cpu);
	printf("\033[18C%13s%s (%ld)\n", "CPU: ", cpu,
	       sysconf(_SC_NPROCESSORS_CONF));
	return 0;
}
#endif

int fetch_resolution() {
	int width, height;
	char modes[MAX_LENGTH];
	read_first_line("/sys/class/graphics/fb0/virtual_size", modes, MAX_LENGTH);
	sscanf(modes, "%d,%d", &width, &height);
	printf("\033[18C%13s%dx%d\n", "resolution: ", width, height);
	return 0;
}

struct keyval {
	unsigned int key;
	const char *value;
};

#include "gpu-database.h"

int compare_keyval(const void *a, const void *b) {
	return ((struct keyval *)a)->key - ((struct keyval *)b)->key;
}

int fetch_gpu() {
	char vendorstring[7];
	read_first_line("/sys/class/drm/card0/device/vendor", vendorstring, 7);
	char devicestring[7];
	read_first_line("/sys/class/drm/card0/device/device", devicestring, 7);
	unsigned int vendorn, devicen;
	sscanf(vendorstring, "%x", &vendorn);
	sscanf(devicestring, "%x", &devicen);

	char *vendor = "unknown vendor";
	struct keyval *gpus = NULL;
	size_t gpu_count = 0;

	switch (vendorn) {
	case 0x1002:
		vendor = "AMD";
		gpus = amd_gpus;
		gpu_count = sizeof(amd_gpus) / sizeof(amd_gpus[0]);
		break;
	case 0x10de:
		vendor = "NVIDIA";
		gpus = nv_gpus;
		gpu_count = sizeof(nv_gpus) / sizeof(nv_gpus[0]);
		break;
	case 0x8086:
		vendor = "Intel";
		gpus = intel_gpus;
		gpu_count = sizeof(intel_gpus) / sizeof(intel_gpus[0]);
		break;
	}

	struct keyval device_key = {devicen, NULL};
	struct keyval *device_keyval = bsearch(
		&device_key, gpus, gpu_count, sizeof(struct keyval), compare_keyval);

	if (device_keyval != NULL) {
		printf("\033[18C%13s%s %s\n", "GPU: ", vendor, device_keyval->value);
		return 0;
	}

	printf("\033[18C%13s%s (id: %x)\n", "GPU: ", vendor, devicen);
	return 0;
}

int fetch_memory() {
	char *meminfo = read_file("/proc/meminfo");
	int available;
	char *available_line = strstr(meminfo, "MemAvailable:");
	sscanf(available_line, "%*s%d kB", &available);
	int total;
	char *total_line = strstr(meminfo, "MemTotal:");
	sscanf(total_line, "%*s%d kB", &total);
	int used = total - available;

	printf("\033[18C%13s%d.%03dGB / %d.%03dGB\n",
	       "memory: ", used / 1024 / 1000, (used / 1024) % 1000,
	       total / 1024 / 1000, (total / 1024) % 1000);
	return 0;
}

int main() {
	TIME_INIT;
	TIME_START;

	char *release = read_file("/etc/os-release");

	// draw ascii art
	printf("\n");
	fetch_art(release);
	printf("\n");
	printf("%s\n", tux);
	printf("%s", "\033[16A");

	thrd_t packages_thread;
	thrd_create(&packages_thread, fetch_packages, NULL);

	thrd_t wm_thread;
	thrd_create(&wm_thread, fetch_wm, NULL);

	// run quick tasks synchronously in main thread
	fetch_uptime();
	fetch_terminal();
	fetch_model();
	fetch_uname();
	fetch_os(release);
	fetch_memory();
	fetch_env();
	fetch_cpu();
	fetch_gpu();
	fetch_resolution();

	// wait for threads to end
	int packages_result;
	int wm_result;
	thrd_join(packages_thread, &packages_result);
	thrd_join(wm_thread, &wm_result);

	printf("\n");
	printf(
		"\033[18C%13s%s\n", "palette: ",
		"\033[0m\033[100m\033[30m▀▀\033[101m\033[31m▀▀\033[102m\033[32m▀▀\033["
		"103m\033[33m▀▀\033["
		"104m\033[34m▀▀\033[105m\033[35m▀▀\033[106m\033[36m▀▀\033[107m\033["
		"37m▀▀\033[0m");
	TIME_END;

	return 0;
}
