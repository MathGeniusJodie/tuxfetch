// pull request to add your own gpu
// https://pci-ids.ucw.cz/read/PC/1002
// https://pci-ids.ucw.cz/read/PC/10de
// https://pci-ids.ucw.cz/read/PC/8086
// https://linux-hardware.org/?view=search
// https://en.wikipedia.org/wiki/List_of_Intel_graphics_processing_units
// https://dgpu-docs.intel.com/devices/hardware-table.html

static struct keyval intel_gpus[] = {
    {0x0042, "HD (Ironlake)"},
    {0x0046, "HD (Ironlake)"},
    {0x0102, "HD 2000 (Sandybridge)"},
    {0x0106, "HD 2000 (Sandybridge)"},
    {0x010a, "HD 2000 (Sandybridge)"},
    {0x0112, "HD 3000 (Sandybridge)"},
    {0x0116, "HD 3000 (Sandybridge)"},
    {0x0122, "HD 3000 (Sandybridge)"},
    {0x0126, "HD 3000 (Sandybridge)"},
    {0x0152, "HD 2500 (Ivy Bridge)"},
    {0x0155, "HD (Bay Trail)"},
    {0x0156, "HD 2500 (Ivy Bridge)"},
    {0x0157, "HD (Bay Trail)"},
    {0x015a, "HD (Ivy Bridge)"},
    {0x0162, "HD 4000 (Ivy Bridge)"},
    {0x0166, "HD 4000 (Ivy Bridge)"},
    {0x016a, "HD P4000 (Ivy Bridge)"},
    {0x0402, "HD (Haswell)"},
    {0x006, "HD (Haswell)"},
    {0x040a, "HD (Haswell)"},
    {0x040b, "HD (Haswell)"},
    {0x040e, "HD (Haswell)"},
    {0x0412, "HD 4600 (Haswell)"},
    {0x0416, "HD 4600 (Haswell)"},
    {0x041a, "HD P4600/P4700 (Haswell)"},
    {0x041b, "HD (Haswell)"},
    {0x041e, "HD 4400 (Haswell)"},
    {0x0422, "HD (Haswell)"},
    {0x0426, "HD (Haswell)"},
    {0x042a, "HD (Haswell)"},
    {0x042b, "HD (Haswell)"},
    {0x042e, "HD (Haswell)"},
    {0x08cf, "GMA"},
    {0x0a02, "HD (Haswell)"},
    {0x0a06, "HD (Haswell)"},
    {0x0a0a, "HD (Haswell)"},
    {0x0a0b, "HD (Haswell)"},
    {0x0a0e, "HD (Haswell)"},
    {0x0a12, "HD (Haswell)"},
    {0x0a16, "HD 4400 (Haswell)"},
    {0x0a1a, "HD (Haswell)"},
    {0x0a1b, "HD (Haswell)"},
    {0x0a1e, "HD 4200 (Haswell)"},
    {0x0a22, "HD (Haswell)"},
    {0x0a26, "HD 5000 (Haswell)"},
    {0x0a2a, "HD (Haswell)"},
    {0x0a2b, "HD (Haswell)"},
    {0x0a2e, "Iris 5100 (Haswell)"},
    {0x0a84, "HD (Apollo Lake)"},
    {0x0be0, "GMA 3600"},
    {0x0be1, "GMA 3600"},
    {0x0be2, "GMA 3650"},
    {0x0be3, "GMA 3650"},
    {0x0c02, "HD (Haswell)"},
    {0x0c06, "HD (Haswell)"},
    {0x0c0a, "HD (Haswell)"},
    {0x0c0b, "HD (Haswell)"},
    {0x0c0e, "HD (Haswell)"},
    {0x0c12, "HD (Haswell)"},
    {0x0c16, "HD (Haswell)"},
    {0x0c1a, "HD (Haswell)"},
    {0x0c1b, "HD (Haswell)"},
    {0x0c1e, "HD (Haswell)"},
    {0x0c22, "HD (Haswell)"},
    {0x0c26, "HD (Haswell)"},
    {0x0c2a, "HD (Haswell)"},
    {0x0c2b, "HD (Haswell)"},
    {0x0c2e, "HD (Haswell)"},
    {0x0d02, "HD (Haswell)"},
    {0x0d06, "HD (Haswell)"},
    {0x0d0a, "HD (Haswell)"},
    {0x0d0b, "HD (Haswell)"},
    {0x0d0e, "HD (Haswell)"},
    {0x0d12, "HD 4600 (Haswell)"},
    {0x0d16, "HD (Haswell)"},
    {0x0d1a, "HD (Haswell)"},
    {0x0d1b, "HD (Haswell)"},
    {0x0d1e, "HD (Haswell)"},
    {0x0d22, "Iris Pro 5200 (Haswell)"},
    {0x0d26, "Iris Pro P5200 (Haswell)"},
    {0x0d2a, "HD (Haswell)"},
    {0x0d2b, "HD (Haswell)"},
    {0x0d2e, "HD (Haswell)"},
    {0x0f31, "HD (Bay Trail)"},
    {0x0f32, "HD (Bay Trail)"},
    {0x0f33, "HD (Bay Trail)"},
    {0x1132, "Solano"},
    {0x1240, "752"},
    {0x1602, "HD (Broadwell)"},
    {0x1606, "HD (Broadwell)"},
    {0x160a, "HD (Broadwell)"},
    {0x160b, "HD (Broadwell)"},
    {0x160d, "HD (Broadwell)"},
    {0x160e, "HD (Broadwell)"},
    {0x1612, "HD 5600 (Broadwell)"},
    {0x1616, "HD 5500 (Broadwell)"},
    {0x161A, "HD P5700 (Broadwell)"},
    {0x161B, "HD (Broadwell)"},
    {0x161D, "HD (Broadwell)"},
    {0x161E, "HD 5300 (Broadwell)"},
    {0x1622, "Iris Pro 6200 (Broadwell)"},
    {0x1626, "HD 6000 (Broadwell)"},
    {0x162a, "Iris Pro P6300 (Broadwell)"},
    {0x162b, "Iris 6100 (Broadwell)"},
    {0x162d, "HD (Broadwell)"},
    {0x162e, "HD (Broadwell)"},
    {0x1632, "Broadwell-U Integrated Graphics"},
    {0x1636, "Broadwell-U Integrated Graphics"},
    {0x163a, "Broadwell-U Integrated Graphics"},
    {0x163b, "Broadwell-U Integrated Graphics"},
    {0x163d, "Broadwell-U Integrated Graphics"},
    {0x163e, "Broadwell-U Integrated Graphics"},
    {0x1902, "HD 510 (Skylake)"},
    {0x1906, "HD 510 (Skylake)"},
    {0x190a, "HD (Skylake)"},
    {0x190b, "HD 510 (Skylake)"},
    {0x190e, "HD (Skylake)"},
    {0x1912, "HD 530 (Skylake)"},
    {0x1913, "HD (Skylake)"},
    {0x1915, "HD (Skylake)"},
    {0x1916, "HD 520 (Skylake)"},
    {0x1917, "HD (Skylake)"},
    {0x191a, "HD (Skylake)"},
    {0x191b, "HD 530 (Skylake)"},
    {0x191d, "HD P530 (Skylake)"},
    {0x191e, "HD 515 (Skylake)"},
    {0x1921, "HD 520 (Skylake)"},
    {0x1923, "HD 535 (Skylake)"},
    {0x1926, "Iris 540 (Skylake)"},
    {0x1927, "Iris 550 (Skylake)"},
    {0x192a, "HD (Skylake)"},
    {0x192b, "Iris 555 (Skylake)"},
    {0x192d, "Iris P555 (Skylake)"},
    {0x1932, "Iris Pro 580 (Skylake)"},
    {0x193a, "Iris Pro P580 (Skylake)"},
    {0x193b, "Iris Pro 580 (Skylake)"},
    {0x193d, "Iris Pro P580 (Skylake)"},
    {0x1a84, "HD (Apollo Lake)"},
    {0x1a85, "HD (Apollo Lake)"},
    {0x22b0, "HD (Cherryview)"},
    {0x22b1, "HD (Cherryview)"},
    {0x22b2, "HD (Cherryview)"},
    {0x22b3, "HD (Cherryview)"},
    {0x2562, "845G"},
    {0x2572, "865G"},
    {0x2582, "915G"},
    {0x258a, "i915"},
    {0x2592, "915GM"},
    {0x2772, "945G"},
    {0x2776, "945G"},
    {0x2782, "915G"},
    {0x2792, "915GM"},
    {0x27a2, "945GM"},
    {0x27a6, "945GM"},
    {0x27ae, "945GME"},
    {0x2972, "946GZ"},
    {0x2973, "946GZ"},
    {0x2982, "965G"},
    {0x2983, "GMA X3500"},
    {0x2992, "965Q"},
    {0x2993, "965Q"},
    {0x29a2, "965G"},
    {0x29a3, "965G"},
    {0x29b2, "Q35"},
    {0x29b3, "Q35"},
    {0x29c2, "G33"},
    {0x29c3, "G33"},
    {0x29d2, "Q33"},
    {0x29d3, "Q33"},
    {0x2a02, "965GM"},
    {0x2a03, "GMA X3100"},
    {0x2a12, "965GME/GLE"},
    {0x2a13, "GMA X3100"},
    {0x2a42, "GMA 4500MHD"},
    {0x2a43, "GMA 4500MHD"},
    {0x2e02, "Integrated Graphics Device"},
    {0x2e03, "Integrated Graphics Device"},
    {0x2e12, "Q45/Q43"},
    {0x2e13, "Q45/Q43"},
    {0x2e22, "GMA X4500HD"},
    {0x2e23, "GMA X4500HD"},
    {0x2e32, "G41"},
    {0x2e33, "GMA X4500"},
    {0x2e42, "B43"},
    {0x2e43, "B43"},
    {0x2e5b, "GMA 500"},
    {0x2e92, "B43"},
    {0x2e93, "B43"},
    {0x3184, "UHD 605 (Gemini Lake)"},
    {0x3185, "UHD 600 (Gemini Lake)"},
    {0x3572, "Extreme Graphics 2"},
    {0x3577, "830M"},
    {0x3582, "852GM/855GM"},
    {0x358e, "854"},
    {0x3ba5, "UHD 610 (Coffee Lake)"},
    {0x3ba8, "UHD 610 (Coffee Lake)"},
    {0x3e90, "UHD 610 (Coffee Lake)"},
    {0x3e91, "UHD 630 (Coffee Lake)"},
    {0x3e92, "UHD 630 (Coffee Lake)"},
    {0x3e93, "UHD 610 (Coffee Lake)"},
    {0x3e94, "UHD P630 (Coffee Lake)"},
    {0x3e96, "UHD P630 (Coffee Lake)"},
    {0x3e98, "UHD 630 (Coffee Lake)"},
    {0x3e99, "UHD 610 (Coffee Lake)"},
    {0x3e9a, "UHD P630 (Coffee Lake)"},
    {0x3e9b, "UHD 630 (Coffee Lake)"},
    {0x3e9c, "UHD 610 (Coffee Lake)"},
    {0x3ea0, "UHD 620 (Coffee Lake)"},
    {0x3ea1, "UHD 610 (Coffee Lake)"},
    {0x3ea2, "UHD (Coffee Lake)"},
    {0x3ea3, "UHD (Coffee Lake)"},
    {0x3ea4, "UHD (Coffee Lake)"},
    {0x3ea5, "Iris Plus 655 (Coffee Lake)"},
    {0x3ea6, "Iris Plus 645 (Coffee Lake)"},
    {0x3ea7, "HD (Coffee Lake)"},
    {0x3ea8, "Iris Plus 655 (Coffee Lake)"},
    {0x3ea9, "UHD 620 (Coffee Lake)"},
    {0x4100, "GMA 500"},
    {0x4108, "GMA 600"},
    {0x4109, "GMA 600"},
    {0x410a, "GMA 600"},
    {0x410b, "GMA 600"},
    {0x410c, "GMA 600"},
    {0x410d, "GMA 600"},
    {0x410e, "GMA 600"},
    {0x410f, "GMA 600"},
    {0x4626, "Iris Xe (Alder Lake) // unsure"},
    {0x46a1, "UHD (Alder Lake) // unsure"},
    {0x46a3, "UHD (Alder Lake) // unsure"},
    {0x46a6, "Iris Xe (Alder Lake) // unsure"},
    {0x46c0, "UHD (Alder Lake) // unsure"},
    {0x4905, "Iris Xe MAX"},
    {0x4906, "Iris Xe Pod"},
    {0x4907, "Server GPU"},
    {0x4908, "Iris Xe DG1"},
    {0x4c8a, "UHD 750 (Rocket Lake)"},
    {0x4c8b, "UHD 730 (Rocket Lake)"},
    {0x4c90, "UHD P750 (Rocket Lake)"},
    {0x4c9a, "UHD (Rocket Lake)"},
    {0x4e55, "UHD (Jasper Lake)"},
    {0x4e61, "UHD (Jasper Lake)"},
    {0x4e71, "UHD (Jasper Lake)"},
    {0x5902, "HD 610 (Kaby Lake)"},
    {0x5906, "HD 610 (Kaby Lake)"},
    {0x5908, "HD (Kaby Lake)"},
    {0x590a, "HD (Kaby Lake)"},
    {0x590b, "HD 610 (Kaby Lake)"},
    {0x590e, "HD (Kaby Lake)"},
    {0x5912, "HD 630 (Kaby Lake)"},
    {0x5913, "HD (Kaby Lake)"},
    {0x5915, "HD (Kaby Lake)"},
    {0x5916, "HD 620 (Kaby Lake)"},
    {0x5917, "UHD 620 (Kaby Lake)"},
    {0x591a, "HD P630 (Kaby Lake)"},
    {0x591b, "HD 630 (Kaby Lake)"},
    {0x591c, "UHD 615 (Kaby Lake)"},
    {0x591d, "HD P630 (Kaby Lake)"},
    {0x591e, "HD 615 (Kaby Lake)"},
    {0x5921, "HD 620 (Kaby Lake)"},
    {0x5923, "HD 635 (Kaby Lake)"},
    {0x5926, "Iris Plus 640 (Kaby Lake)"},
    {0x5927, "Iris Plus 650 (Kaby Lake)"},
    {0x593b, "HD (Kaby Lake)"},
    {0x5a84, "HD 505 (Apollo Lake)"},
    {0x5a85, "HD 500 (Apollo Lake)"},
    {0x7800, "i740"},
    {0x7121, "Whitney"},
    {0x7123, "Whitney"},
    {0x7125, "Whitney"},
    {0x8108, "GMA 500"},
    {0x8109, "GMA 500"},
    {0x8182, "GMA 3150"},
    {0x87c0, "UHD 617 (Kaby Lake)"},
    {0x87ca, "UHD (Coffee Lake)"},
    {0x8a50, "HD (Ice Lake)"},
    {0x8a51, "Iris Plus (Ice Lake)"},
    {0x8a52, "Iris Plus (Ice Lake)"},
    {0x8a53, "Iris Plus (Ice Lake)"},
    {0x8a54, "Iris Plus (Ice Lake)"},
    {0x8a56, "UHD (Ice Lake)"},
    {0x8a57, "HD (Ice Lake)"},
    {0x8a58, "UHD (Ice Lake)"},
    {0x8a59, "HD (Ice Lake)"},
    {0x8a5a, "Iris Plus (Ice Lake)"},
    {0x8a5b, "HD (Ice Lake)"},
    {0x8a5c, "Iris Plus (Ice Lake)"},
    {0x8a5d, "HD (Ice Lake)"},
    {0x8a71, "UHD (Ice Lake)"},
    {0x9a40, "Iris Xe (Tiger Lake)"},
    {0x9a49, "Iris Xe (Tiger Lake)"},
    {0x9a60, "UHD (Tiger Lake)"},
    {0x9a68, "UHD (Tiger Lake)"},
    {0x9a70, "UHD (Tiger Lake)"},
    {0x9a78, "UHD (Tiger Lake)"},
    {0x9ac0, "UHD (Tiger Lake)"},
    {0x9ac9, "UHD (Tiger Lake)"},
    {0x9ad9, "UHD (Tiger Lake)"},
    {0x9af8, "UHD (Tiger Lake)"},
    {0x9b21, "UHD (Coffee Lake)"},
    {0x9b41, "UHD (Coffee Lake)"},
    {0x9ba0, "UHD (Coffee Lake)"},
    {0x9ba2, "UHD (Coffee Lake)"},
    {0x9ba4, "UHD (Coffee Lake)"},
    {0x9baa, "UHD (Coffee Lake)"},
    {0x9bab, "UHD (Coffee Lake)"},
    {0x9bac, "UHD (Coffee Lake)"},
    {0x9bc0, "UHD (Coffee Lake)"},
    {0x9bc2, "UHD (Coffee Lake)"},
    {0x9bc4, "UHD (Coffee Lake)"},
    {0x9bc5, "UHD 630 (Coffee Lake)"},
    {0x9bc6, "UHD P630 (Coffee Lake)"},
    {0x9bc8, "UHD 630 (Coffee Lake)"},
    {0x9bca, "UHD (Comet Lake)"},
    {0x9bcb, "UHD (Comet Lake)"},
    {0x9bcc, "UHD (Comet Lake)"},
    {0x9be6, "UHD P630 (Coffee Lake)"},
    {0x9bf6, "UHD P630 (Coffee Lake)"},
    {0xa001, "Pineview"},
    {0xa002, "GMA 3150"},
    {0xa011, "Pineview M"},
    {0xa012, "GMA 3150"}};

// legacy ati shit

// 3150	Radeon X600
// 3151	FireMV 2400
// 3152	Radeon X300
// 3154	FireGL V3200
// 3155	FireMV 2400
// 3171	FireMV 2400
// 3e50	Radeon X550/X600
// 3e54	FireGL V3200
// 3e70	Radeon X550/X600
// 4136	Radeon IGP 320M
// 4137	Radeon IGP 340
// 4144	Radeon 9500
// 4146	Radeon 9700 PRO
// 4147	FireGL Z1
// 4148	Radeon 9800
// 4150	Radeon 9550/9600/X1050 Series
// 4151	Radeon 9600 Series
// 4152	Radeon 9600/X1050 Series
// 4153	Radeon 9550
// 4154	FireGL T2
// 4155	Radeon 9600
// 4157	FireGL T2
// 4164	Radeon 9500 PRO
// 4165	Radeon 9700 PRO
// 4166	Radeon 9700 PRO
// 4168	Radeon 9800 SE
// 4170	Radeon 9550/9600/X1050 Series
// 4171	Radeon 9600
// 4172	Radeon 9600/X1050 Series
// 4173	Radeon 9550
// 4242	Radeon 8500 DV
// 4337	Radeon IGP 3XXM
// 4437	Radeon 7000 IGP
// 4742	3D Rage PRO
// 4744	3D Rage PRO
// 4749	3D Rage PRO
// 474d	Rage XL
// 474e	Rage XC
// 474f	Rage XL
// 4750	3D Rage Pro
// 4752	Rage XL
// 4753	Rage XC
// 4754	3D Rage
// 4756	3D Rage IIC
// 4757	3D Rage IIC
// 4759	3D Rage IIC
// 475a	3D Rage IIC
// 4966	Radeon 9000 Series
// 496e	Radeon 9000
// 4a49	Radeon X800 PRO/GTO
// 4a4a	Radeon X800 GT
// 4a4b	Radeon X800
// 4a4d	FireGL X3-256
// 4a4e	Radeon 9800
// 4a4f	Radeon X850
// 4a50	Radeon X800 XT Platinum Edition
// 4a54	Radeon X800 VE AGP
// 4a69	Radeon X800 PRO/GTO
// 4a6a	Radeon X800
// 4a6b	Radeon X800 XT
// 4a70	Radeon X800 XT Platinum Edition
// 4a74	Radeon X800 VE
// 4b49	Radeon X850 XT
// 4b4b	Radeon X850 PRO
// 4b4c	Radeon X850 XT Platinum Edition
// 4b69	Radeon X850 XT
// 4b6b	Radeon X850 PRO
// 4b6c	Radeon X850 XT Platinum Edition
// 4c42	3D Rage LT PRO
// 4c49	3D Rage LT PRO
// 4c4d	Rage Mobility 2x Series
// 4c50	3D Rage LT PRO
// 4c52	Rage Mobility-M1 PCI
// 4c57	Radeon 7500
// 4c58	FireGL 7800
// 4c59	Rage/Radeon Mobility Series
// 4c66	Radeon 9000
// 4c6e	Radeon 9000
// 4d46	Rage Mobility 128
// 4e44	Radeon 9700
// 4e45	Radeon 9500 PRO/9700
// 4e46	Radeon 9600 TX
// 4e47	FireGL X1
// 4e48	Radeon 9800
// 4e49	Radeon 9800
// 4e4a	Radeon 9800 XXL/XT
// 4e4b	FireGL X2
// 4e50	Radeon 9600 (PRO) / 9700
// 4e51	Radeon 9550/9600/X1050 Series
// 4e52	Radeon 9500/9700 SE
// 4e54	FireGL T2
// 4e56	Radeon 9550
// 4e64	Radeon 9700 PRO
// 4e65	Radeon 9500 PRO
// 4e66	Radeon 9600
// 4e67	FireGL X1
// 4e68	Radeon 9800 PRO
// 4e69	Radeon 9800
// 4e6a	Radeon 9800 XT
// 4e71	Radeon 9600
// 4f72	Radeon 9000 Series
// 4f73	Radeon 9000 Series
// 5044	All-In-Wonder 128
// 5046	Rage 128 PRO
// 5050	Rage 128 PRO / Xpert 128
// 5052	Rage 128 PRO
// 5144	Radeon 7200
// 5148	FireGL 8800
// 514c	Radeon 8500
// 514d	Radeon 9100
// 5157	Radeon 7500
// 5159	Radeon 7000 / Radeon VE
// 515e	ES1000
// 5245	Rage 128 GL
// 5246	Rage 128
// 524b	Rage 128 VR
// 524c	Rage 128 VR
// 534d	Rage 128 4X
// 5446	Rage 128 PRO Ultra
/*
5460	Radeon X300
5461	Radeon X300
5462	Radeon X600 SE
5464	FireGL V3100
5549	Radeon X800 GTO
554a	Radeon X800 XT Platinum Edition
554b	Radeon X800 GT/SE
554d	Radeon X800 GTO2/XL
554e	All-In-Wonder X800 GT
554f	Radeon X800
5550	FireGL V7100
5551	FireGL V5100
5569	Radeon X800 PRO
556b	Radeon X800 GT
556d	Radeon X800 GTO2/XL
556f	Radeon X800
5571	FireGL V5100
564b	Mobility FireGL V5000
564f	Radeon X700 XL
5652	Radeon X700
5653	Radeon X700
5656	Video Xpression+
5657	Radeon X550 XTX / X700
5834	Radeon 9100 IGP
5835	Radeon 9100 IGP
5854	Radeon Xpress 200 Series
5874	Radeon Xpress 1150
5940	Radeon 9200 PRO
5941	Radeon 9200
5944	Radeon 9200 SE
5954	Radeon Xpress 200 Series
5955	Radeon Xpress 200
5960	Radeon 9200 PRO / 9250
5961	Radeon 9200
5962	Radeon 9200
5964	Radeon 9200 SE
5965	FireMV 2200
5974	Radeon Xpress 1100/1150
5975	Radeon Xpress 200
5a41	Radeon Xpress 200
5a42	Radeon Xpress 200M
5a61	Radeon Xpress 200/1100
5a62	Radeon Xpress 200M
5b60	Radeon X300
5b62	Radeon X600/X600 SE
5b63	Radeon X300/X550/X1050 Series
5b64	FireGL V3100
5b65	FireMV 2200
5b66	RV370X
5b70	Radeon X300 SE
5b72	Radeon X300/X550/X1050 Series
5b73	Radeon X300/X550/X1050 Series
5b74	FireGL V3100
5b75	FireMV 2200
5c61	Radeon 9200
5c63	Radeon 9200
5d44	Radeon 9200 SE
5d45	FireMV 2200
5d48	Radeon X800 XT
5d49	FireGL V5100
5d4a	Radeon X800
5d4d	Radeon X850 XT Platinum Edition
5d4e	Radeon X850 SE
5d4f	Radeon X800 GTO
5d50	FireGL V7200
5d52	Radeon X850 XT
5d57	Radeon X800 XT
5d6d	Radeon X850 XT Platinum Edition
5d6f	Radeon X800 GTO
5d72	Radeon X850 XT
5d77	Radeon X800 XT
5e48	FireGL V5000
5e49	Radeon X700 Series
5e4a	Radeon X700 XT
5e4b	Radeon X700 PRO
5e4c	Radeon X700 SE
5e4d	Radeon X700
5e4f	Radeon X700
5e6b	Radeon X700 PRO
5e6d	Radeon X700
5f57	Radeon X800 XT
*/
/*
7100	Radeon X1800 XT
7101	Radeon X1800 XT
7102	Radeon X1800
7104	FireGL V7200
7109	Radeon X1800 XL
710a	Radeon X1800 GTO
710b	Radeon X1800 GTO
710e	FireGL V7300
710f	FireGL V7350
7120	Radeon X1800
7124	FireGL V7200
7129	Radeon X1800
712e	FireGL V7300
712f	FireGL V7350
7140	Radeon X1300/X1550/X1600 Series
7142	Radeon X1300/X1550 Series
7143	Radeon X1300/X1550 Series
7145	Radeon X1400
7146	Radeon X1300/X1550
7147	Radeon X1550
7149	Radeon X1300
714a	Radeon X1300
7152	FireGL V3300
7153	FireGL V3350
715f	Radeon X1550
7162	Radeon X1300/X1550 Series
7163	Radeon X1550 Series
7166	Radeon X1300/X1550 Series
7167	Radeon X1550
7172	FireGL V3300
7173	FireGL V3350
7181	Radeon X1600/X1650 Series
7183	Radeon X1300/X1550 Series
7186	Radeon X1450
7187	Radeon X1300/X1550 Series
7188	Radeon X2300
718a	Radeon X2300
718b	Radeon X1350
718c	Radeon X1350
718d	Radeon X1450
7193	Radeon X1550 Series
7196	Radeon X1350
719b	FireMV 2250
719f	Radeon X1550 Series
71a0	Radeon X1300/X1550 Series
71a1	Radeon X1600/X1650 Series
71a3	Radeon X1300/X1550 Series
71a7	Radeon X1300/X1550 Series
71bb	FireMV 2250
71c0	Radeon X1600 XT/X1650 GTO
71c1	Radeon X1650 PRO
71c2	Radeon X1600 PRO
71c3	Radeon X1600 PRO
71c4	FireGL V5200
71c5	Radeon X1600
71c6	Radeon X1600/X1650 PRO
71c7	Radeon X1650 PRO
71ce	Radeon X1300 XT/X1600 PRO
71d2	FireGL V3400
71d4	FireGL V5250
71d5	Radeon X1700
71d6	Radeon X1700
71de	Radeon X1700/X2500
71e0	Radeon X1600
71e1	Radeon X1650 PRO
71e2	Radeon X1600
71e6	Radeon X1650
71e7	Radeon X1650 PRO
71f2	FireGL V3400
7210	Radeon HD 2300
7211	Radeon X2300 HD
7240	Radeon X1950 XTX
7244	Radeon X1950 XT
7248	Radeon X1950
7249	Radeon X1900 XT
724b	Radeon X1900 GT
724e	FireGL V7350
7269	Radeon X1900 XT
726b	Radeon X1900 GT
7280	Radeon X1950 PRO
7288	Radeon X1950 GT
7291	Radeon X1650 XT
7293	Radeon X1650 GT
72a0	Radeon X1950 PRO
72a8	Radeon X1950 GT
72b1	Radeon X1650 XT
72b3	Radeon X1650 GT
7834	Radeon 9100 PRO/XT IGP
7835	Radeon 9000 IGP
791e	Radeon X1200
791f	Radeon Xpress 1200/1250/1270
793f	Radeon Xpress 1200/1250/1270
7941	Radeon Xpress 1250
7942	Radeon Xpress 1250
796e	Radeon 2100
9400	Radeon HD 2900 PRO/XT
9401	Radeon HD 2900 XT
9403	Radeon HD 2900 PRO
9405	Radeon HD 2900 GT
940a	FireGL V8650
940b	FireGL V8600
940f	FireGL V7600
9440	Radeon HD 4870
9441	Radeon HD 4870 X2
9442	Radeon HD 4850
9443	Radeon HD 4850 X2
9444	FirePro V8750
9446	FirePro V7760
944a	Radeon HD 4850
944b	Radeon HD 4850 X2
944c	Radeon HD 4830
944e	Radeon HD 4710
9450	FireStream 9270
9452	FireStream 9250
9456	FirePro V8700
945a	Radeon HD 4870
9460	Radeon HD 4890
9462	Radeon HD 4860
946a	FirePro M7750
9480	Radeon HD 4650/5165
9488	Radeon HD 4670
9489	FireGL V5725
9490	Radeon HD 4670
9491	Radeon E4690
9495	Radeon HD 4600
9498	Radeon HD 4650
949c	FirePro V7750
949e	FirePro V5700
949f	FirePro V3750
94a0	Mobility Radeon HD 4830
94a1	Mobility Radeon HD 4860
94a3	FirePro M7740
94b3	Radeon HD 4770
94b4	Radeon HD 4750
94c1	Radeon HD 2400 PRO/X
94c3	Radeon HD 2400 PRO
94c4	Radeon HD 2400 PRO AGP
94c5	Radeon HD 2400 LE
94c7	Radeon HD 2350
94c8	Radeon HD 2400 XT
94c9	Radeon HD 2400
94cb	Radeon E2400
94cc	Radeon HD 2400 PRO
9500	Radeon HD 3850 X2
9501	Radeon HD 3870
9504	Radeon HD 3850
9505	Radeon HD 3690/3850
9506	Radeon HD 3850 X2
9507	Radeon HD 3830
9508	Radeon HD 3870
9509	Radeon HD 3870 X2
950f	Radeon HD 3870 X2
9511	FireGL V7700
9513	Radeon HD 3850 X2
9515	Radeon HD 3850
9519	FireStream 9170
9540	Radeon HD 4550
954f	Radeon HD 4350/4550
9552	Radeon HD 4330/4350/4550
9553	Radeon HD 4530/4570/545v
9555	Radeon HD 4350/4550
9557	FirePro RG220
955f	Radeon HD 4330
9580	Radeon HD 2600 PRO
9581	Radeon HD 2600
9583	Radeon HD 2600 XT/2700
9586	Radeon HD 2600 XT AGP
9587	Radeon HD 2600 PRO AGP
9588	Radeon HD 2600 XT
9589	Radeon HD 2600 PRO
958a	Radeon HD 2600 X2
958b	Radeon HD 2600 XT
958c	FireGL V5600
958d	FireGL V3600
9591	Radeon HD 3650
9593	Radeon HD 3670
9595	FireGL V5700
9596	Radeon HD 3650
9597	Radeon HD 3650
9598	Radeon HD 3650/3750/4570/4580
9599	Radeon HD 3650
95c0	Radeon HD 3470
95c2	Radeon HD 3410/3430
95c4	Radeon HD 3450/3470
95c5	Radeon HD 3450
95c6	Radeon HD 3450
95c9	Radeon HD 3450
95cc	FirePro V3700
95cd	FirePro 2450
95cf	FirePro 2260
9610	Radeon HD 3200
9611	Radeon 3100
9612	Radeon HD 3200
9613	Radeon HD 3100
9614	Radeon HD 3300
9615	Radeon HD 3200
9616	Radeon 3000
9710	Radeon HD 4200
9712	Radeon HD 4225/4250
9713	Radeon HD 4100
9714	Radeon HD 4290
9715	Radeon HD 4250
*/

struct keyval amd_gpus[] = {{0x1304, "Kaveri"},
                            {0x1305, "Kaveri"},
                            {0x1306, "Kaveri"},
                            {0x1307, "Kaveri"},
                            {0x1309, "Radeon R6/R7"},
                            {0x130a, "Radeon R6"},
                            {0x130b, "Radeon R4"},
                            {0x130c, "Radeon R7"},
                            {0x130d, "Radeon R6"},
                            {0x130e, "Radeon R5"},
                            {0x130f, "Radeon R7"},
                            {0x1310, "Kaveri"},
                            {0x1311, "Kaveri"},
                            {0x1312, "Kaveri"},
                            {0x1313, "Radeon R7"},
                            {0x1315, "Radeon R5"},
                            {0x1316, "Radeon R5"},
                            {0x1317, "Kaveri"},
                            {0x1318, "Radeon R5"},
                            {0x131b, "Radeon R4"},
                            {0x131c, "Radeon R7"},
                            {0x131d, "Radeon R6"},
                            {0x154c, "Radeon RX 350"},
                            {0x15d8, "Picasso"},
                            {0x15dd, "Raven Ridge"},
                            {0x1636, "Renoir"},
                            {0x1638, "Cezanne"},
                            {0x163f, "VanGogh"},
                            {0x164c, "Lucienne"},
                            {0x164d, "Rembrandt"},
                            {0x1681, "Rembrandt"},
                            {0x6600, "Radeon HD 8670A/8670M/8750M / R7 M370"},
                            {0x6601, "Radeon HD 8730M"},
                            {0x6604, "Radeon R7 M265/M365X/M465"},
                            {0x6605, "Radeon R7 M260X"},
                            {0x6606, "Radeon HD 8790M"},
                            {0x6607, "Radeon HD 8530M / R5 M240"},
                            {0x6608, "FirePro W2100"},
                            {0x6609, "FirePro W2100"},
                            {0x6610, "Radeon HD 8670"},
                            {0x6611, "Radeon HD 8570 / R7 240/340"},
                            {0x6613, "Radeon R7 240/340"},
                            {0x6631, "Oland"},
                            {0x6640, "FirePro M6100"},
                            {0x6641, "Radeon HD 8930M"},
                            {0x6646, "Radeon R9 M280X"},
                            {0x6647, "Radeon R9 M270X/M280X"},
                            {0x6649, "FirePro W5100"},
                            {0x664d, "FirePro W5100"},
                            {0x6650, "Bonaire"},
                            {0x6651, "Bonaire"},
                            {0x6658, "Radeon R7 260X/360"},
                            {0x665c, "Radeon HD 7790/8770 / R7 360"},
                            {0x665d, "Radeon R7 200 Series"},
                            {0x665f, "Radeon R7 360"},
                            {0x6660, "Sun XT"},
                            {0x6663, "Radeon HD 8570A/8570M"},
                            {0x6664, "Radeon R5 M240"},
                            {0x6665, "Jet PRO"},
                            {0x6667, "Radeon R5 M230"},
                            {0x666f, "Radeon HD 8550M / R5 M230"},
                            {0x66a0, "Radeon Instinct"},
                            {0x66a1, "Radeon Pro VII/Radeon Instinct MI50"},
                            {0x66a2, "Vega 20"},
                            {0x66a3, "Radeon Pro Vega II"},
                            {0x66a7, "Radeon Pro Vega 20"},
                            {0x66af, "Radeon VII"},
                            {0x6704, "FirePro V7900"},
                            {0x6707, "FirePro V5900"},
                            {0x6718, "Radeon HD 6970"},
                            {0x6719, "Radeon HD 6950"},
                            {0x671c, "Radeon HD 6990"},
                            {0x671d, "Radeon HD 6990"},
                            {0x671f, "Radeon HD 6930"},
                            {0x6720, "Radeon HD 6970M/6990M"},
                            {0x6738, "Radeon HD 6870"},
                            {0x6739, "Radeon HD 6850"},
                            {0x673e, "Radeon HD 6790"},
                            {0x6740, "Whistler"},
                            {0x6741, "Whistler"},
                            {0x6742, "Radeon HD 6610M/7610M"},
                            {0x6743, "Radeon E6760"},
                            {0x6749, "FirePro V4900"},
                            {0x674a, "FirePro V3900"},
                            {0x6750, "Radeon HD 6650A/7650A"},
                            {0x6751, "Radeon HD 7650A/7670A"},
                            {0x6758, "Radeon HD 6670/7670"},
                            {0x6759, "Turks PRO"},
                            {0x675b, "Radeon HD 7600 Series"},
                            {0x675d, "Radeon HD 7570"},
                            {0x675f, "Turks LE"},
                            {0x6760, "Radeon HD 6400M/7400M Series"},
                            {0x6761, "Radeon HD 6430M"},
                            {0x6763, "Radeon E6460"},
                            {0x6764, "Radeon HD 6400M Series"},
                            {0x6765, "Radeon HD 6400M Series"},
                            {0x6766, "Caico"},
                            {0x6767, "Caicos"},
                            {0x6768, "Caicos"},
                            {0x6770, "Radeon HD 6450A/7450A"},
                            {0x6771, "Radeon HD 8490"},
                            {0x6772, "Radeon HD 7450A"},
                            {0x6778, "Radeon HD 7470/8470"},
                            {0x6779, "Radeon HD 6450/7450/8450"},
                            {0x677b, "Radeon HD 7450"},
                            {0x6780, "FirePro W9000"},
                            {0x6784, "Tahiti"},
                            {0x6788, "Tahiti"},
                            {0x678a, "Tahiti PRO GL"},
                            {0x6798, "Radeon R9 280X"},
                            {0x679a, "R9 280"},
                            {0x679b, "Radeon HD 7990"},
                            {0x679e, "Radeon HD 7870 XT"},
                            {0x679f, "Tahiti"},
                            {0x67a0, "FirePro W9100"},
                            {0x67a1, "FirePro W8100"},
                            {0x67a2, "Hawaii GL"},
                            {0x67a8, "Hawaii"},
                            {0x67a9, "Hawaii"},
                            {0x67aa, "Hawaii"},
                            {0x67b0, "Radeon R9 290X/390X"},
                            {0x67b1, "Radeon R9 290/390"},
                            {0x67b8, "Radeon R9 290X"},
                            {0x67b9, "Radeon R9 295X2"},
                            {0x67be, "Hawaii LE"},
                            {0x67c0, "Radeon Pro WX 7100"},
                            {0x67c2, "Radeon Pro V7300X / V7350x2"},
                            {0x67c4, "Radeon Pro WX 7100"},
                            {0x67c7, "Radeon Pro WX 5100"},
                            {0x67ca, "Polaris10"},
                            {0x67cc, "Polaris10"},
                            {0x67cf, "Polaris10"},
                            {0x67d0, "Radeon Pro V7300X / V7350x2"},
                            {0x67d4, "Radeon Pro WX 7100"},
                            {0x67d7, "Radeon Pro WX 5100"},
                            {0x67df, "Radeon RX 470/480/570/580/590"},
                            {0x67e0, "Radeon Pro WX 4170"},
                            {0x67e1, "Polaris11"},
                            {0x67e3, "Radeon Pro WX 4100"},
                            {0x67e8, "Radeon Pro WX 4130/4150"},
                            {0x67e9, "Polaris11"},
                            {0x67eb, "Radeon Pro V5300X"},
                            {0x67ef, "Radeon RX 450/455/460/555/560"},
                            {0x67ff, "Radeon RX 550 640SP/560"},
                            {0x6800, "Radeon HD 7970M"},
                            {0x6801, "Radeon HD 8970M"},
                            {0x6802, "Wimbledon"},
                            {0x6806, "Neptune"},
                            {0x6808, "FirePro W7000"},
                            {0x6809, "FirePro W5000"},
                            {0x6810, "Radeon R7 370"},
                            {0x6811, "Radeon R7 370"},
                            {0x6816, "Pitcairn"},
                            {0x6817, "Pitcairn"},
                            {0x6818, "Radeon HD 7870"},
                            {0x6819, "Radeon HD 7850 / R7 265 / R9 270 1024SP"},
                            {0x6820, "Radeon HD 8890M / R9 M275X/M375X"},
                            {0x6821, "Radeon HD 8870M / R9 M270X/M370X"},
                            {0x6822, "Radeon E8860"},
                            {0x6823, "Radeon HD 8850M / R9 M265X"},
                            {0x6825, "Radeon HD 7870M"},
                            {0x6826, "Radeon HD 7700M Series"},
                            {0x6827, "Radeon HD 7850M/8850M"},
                            {0x6828, "FirePro W600"},
                            {0x6829, "Cape Verde	"},
                            {0x682a, "Venus PRO	"},
                            {0x682b, "Radeon HD 8830M / R7 250 / R7 M465X"},
                            {0x682c, "FirePro W4100"},
                            {0x682d, "FirePro M4000"},
                            {0x682f, "Radeon HD 7730M"},
                            {0x6835, "Radeon R9 255"},
                            {0x6837, "Radeon HD 7730/8730"},
                            {0x683d, "Radeon HD 7770/8760 / R7 250X"},
                            {0x683f, "Radeon HD 7750/8740 / R7 250E"},
                            {0x6840, "Radeon HD 7500M/7600M Series"},
                            {0x6841, "Radeon HD 7550M/7570M/7650M"},
                            {0x6842, "Radeon HD 7000M Series"},
                            {0x6843, "Radeon HD 7670M"},
                            {0x6860, "Radeon Instinct MI25"},
                            {0x6861, "Radeon PRO WX 9100"},
                            {0x6862, "Radeon PRO SSG"},
                            {0x6863, "Radeon Vega Frontier Edition"},
                            {0x6864, "Radeon Pro V340"},
                            {0x6867, "Radeon Pro Vega 56"},
                            {0x6868, "Radeon PRO WX 8100/8200"},
                            {0x6869, "Radeon Pro Vega 48"},
                            {0x686a, "Vega 10"},
                            {0x686b, "Radeon Pro Vega 64X"},
                            {0x686c, "Radeon Instinct MI25"},
                            {0x686d, "Vega 10"},
                            {0x686e, "Vega 10"},
                            {0x687f, "Radeon RX Vega 56/64"},
                            {0x6880, "Radeon HD 6550M"},
                            {0x6888, "FirePro V8800"},
                            {0x6889, "FirePro V7800"},
                            {0x688a, "FirePro V9800"},
                            {0x688c, "FireStream 9370"},
                            {0x688d, "FireStream 9350"},
                            {0x6898, "Radeon HD 5870"},
                            {0x6899, "Radeon HD 5850"},
                            {0x689b, "Radeon HD 6800 Series"},
                            {0x689c, "Radeon HD 5970"},
                            {0x689d, "Radeon HD 5970"},
                            {0x689e, "Radeon HD 5830"},
                            {0x68a0, "Radeon HD 5870"},
                            {0x68a1, "Radeon HD 5850"},
                            {0x68a8, "Radeon HD 6850M/6870M"},
                            {0x68a9, "FirePro V5800"},
                            {0x68b8, "Radeon HD 5770"},
                            {0x68b9, "Radeon HD 5670 640SP"},
                            {0x68ba, "Radeon HD 6770"},
                            {0x68be, "Radeon HD 5750"},
                            {0x68bf, "Radeon HD 6750"},
                            {0x68c0, "Radeon HD 5730 / 6570M"},
                            {0x68c1, "Radeon HD 5650/5750/6530M/6550M"},
                            {0x68c7, "Radeon HD 5570/6550A"},
                            {0x68c8, "FirePro V4800"},
                            {0x68c9, "FirePro V3800"},
                            {0x68d8, "Radeon HD 5670/5690/5730"},
                            {0x68d9, "Redwood"},
                            {0x68da, "Redwood"},
                            {0x68de, "Redwood"},
                            {0x68e0, "Radeon HD 5430/5450/5470"},
                            {0x68e1, "Radeon HD 5430"},
                            {0x68e4, "Radeon HD 6370M/7370M"},
                            {0x68e5, "Radeon HD 6330M"},
                            {0x68e8, "Cedar"},
                            {0x68e9, "Cedar"},
                            {0x68f1, "FirePro 2460"},
                            {0x68f2, "FirePro 2270"},
                            {0x68f8, "Radeon HD 7300 Series"},
                            {0x68f9, "Cedar"},
                            {0x68fa, "Cedar"},
                            {0x68fe, "Cedar"},
                            {0x6900, "Topaz XT"},
                            {0x6901, "Radeon R5 M255"},
                            {0x6907, "Radeon R5 M315"},
                            {0x6920, "Radeon R9 M395"},
                            {0x6921, "Radeon R9 M295X / M390X"},
                            {0x6929, "FirePro S7150"},
                            {0x692b, "FirePro W7100"},
                            {0x692f, "FirePro S7150V"},
                            {0x6938, "Radeon R9 380X / R9 M295X"},
                            {0x6939, "Radeon R9 285/380"},
                            {0x693b, "FirePro W7100"},
                            {0x694c, "Radeon RX Vega M GH"},
                            {0x694e, "Radeon RX Vega M GL"},
                            {0x694f, "Radeon Pro WX Vega M GL"},
                            {0x6980, "Polaris12"},
                            {0x6981, "Radeon PRO WX 3200"},
                            {0x6985, "Radeon PRO WX 3100"},
                            {0x6986, "Polaris12"},
                            {0x6987, "Radeon 540X/550X/630 / RX 640"},
                            {0x698f, "Radeon PRO WX 3100"},
                            {0x6995, "Radeon PRO WX 2100"},
                            {0x699f, "Radeon 540/550"},
                            {0x69a0, "Vega 12"},
                            {0x69a1, "Vega 12"},
                            {0x69a2, "Vega 12"},
                            {0x69a3, "Vega 12"},
                            {0x69af, "Radeon Pro Vega 20"},
                            {0x6fdf, "Radeon RX 580"},
                            {0x7300, "Radeon R9 FURY"},
                            {0x7310, "Radeon Pro W5700X"},
                            {0x7312, "Radeon Pro W5700"},
                            {0x731f, "Radeon RX 5600XT/5700/5700XT"},
                            {0x7340, "Radeon RX 5500"},
                            {0x7341, "Radeon Pro W5500"},
                            {0x7347, "Radeon Pro W5500M"},
                            {0x734f, "Radeon Pro W5300M"},
                            {0x7360, "Radeon Pro 5600M / V520"},
                            {0x7362, "Radeon Pro V520"},
                            {0x7388, "Arcturus"},
                            {0x738c, "Instinct MI100"},
                            {0x738e, "Instinct MI100"},
                            {0x73a2, "Radeon Pro W6900X"},
                            {0x73a3, "Radeon PRO W6800"},
                            {0x73ab, "Radeon Pro W6800X"},
                            {0x73af, "Radeon RX 6900 XT"},
                            {0x73bf, "Radeon RX 6800/6900"},
                            {0x73c3, "Navi 22"},
                            {0x73df, "Radeon RX 6700/6800M"},
                            {0x73e0, "Navi 23"},
                            {0x73e1, "Radeon PRO W6600M"},
                            {0x73e3, "Radeon PRO W6600"},
                            {0x73ff, "Radeon RX 6600"},
                            {0x9640, "Radeon HD 6550D"},
                            {0x9641, "Radeon HD 6620G"},
                            {0x9642, "Radeon HD 6370D"},
                            {0x9643, "Radeon HD 6380G"},
                            {0x9644, "Radeon HD 6410D"},
                            {0x9645, "Radeon HD 6410D"},
                            {0x9647, "Radeon HD 6520G"},
                            {0x9648, "Radeon HD 6480G"},
                            {0x9649, "Radeon HD 6480G"},
                            {0x964a, "Radeon HD 6530D"},
                            {0x964b, "Sumo"},
                            {0x964c, "Sumo"},
                            {0x964e, "Sumo"},
                            {0x964f, "Sumo"},
                            {0x9802, "Radeon HD 6310"},
                            {0x9803, "Radeon HD 6310"},
                            {0x9804, "Radeon HD 6250"},
                            {0x9805, "Radeon HD 6250"},
                            {0x9806, "Radeon HD 6320"},
                            {0x9807, "Radeon HD 6290"},
                            {0x9808, "Radeon HD 7340"},
                            {0x9809, "Radeon HD 7310"},
                            {0x980a, "Radeon HD 7290"},
                            {0x9830, "Radeon HD 8400"},
                            {0x9831, "Radeon HD 8400E"},
                            {0x9832, "Radeon HD 8330"},
                            {0x9833, "Radeon HD 8330E"},
                            {0x9834, "Radeon HD 8210"},
                            {0x9835, "Radeon HD 8310E"},
                            {0x9836, "Radeon HD 8280"},
                            {0x9837, "Radeon HD 8280E"},
                            {0x9838, "Radeon HD 8240"},
                            {0x9839, "Radeon HD 8180"},
                            {0x983d, "Radeon HD 8250/8280G"},
                            {0x9850, "Radeon R3"},
                            {0x9851, "Radeon R4/R5"},
                            {0x9852, "Radeon R2"},
                            {0x9853, "Radeon R2"},
                            {0x9854, "Radeon R3E"},
                            {0x9855, "Radeon R6"},
                            {0x9856, "Radeon R1E/R2E"},
                            {0x9857, "Radeon R2"},
                            {0x9858, "Mullins"},
                            {0x9859, "Mullins"},
                            {0x985a, "Mullins"},
                            {0x985b, "Mullins"},
                            {0x985c, "Mullins"},
                            {0x985d, "Mullins"},
                            {0x985e, "Mullins"},
                            {0x985f, "Mullins"},
                            {0x9874, "Wani"},
                            {0x9890, "Amur"},
                            {0x98c0, "Nolan"},
                            {0x98e4, "Stoney Ridge"},
                            {0x9900, "Radeon HD 7660G"},
                            {0x9901, "Radeon HD 7660D"},
                            {0x9903, "Radeon HD 7640G"},
                            {0x9904, "Radeon HD 7560D"},
                            {0x9905, "FirePro A300"},
                            {0x9906, "FirePro A320"},
                            {0x9907, "Radeon HD 7620G"},
                            {0x9908, "Radeon HD 7600G"},
                            {0x9909, "Radeon HD 7500G"},
                            {0x990a, "Radeon HD 7500G"},
                            {0x990b, "Radeon HD 8650G"},
                            {0x990c, "Radeon HD 8670D"},
                            {0x990d, "Radeon HD 8550G"},
                            {0x990e, "Radeon HD 8570D"},
                            {0x990f, "Radeon HD 8610G"},
                            {0x9910, "Radeon HD 7660G"},
                            {0x9913, "Radeon HD 7640G"},
                            {0x9917, "Radeon HD 7620G"},
                            {0x9918, "Radeon HD 7600G"},
                            {0x9919, "Radeon HD 7500G"},
                            {0x991e, "Bishop"},
                            {0x9924, "Gladius"},
                            {0x9990, "Radeon HD 7520G"},
                            {0x9991, "Radeon HD 7540D"},
                            {0x9992, "Radeon HD 7420G"},
                            {0x9993, "Radeon HD 7480D"},
                            {0x9994, "Radeon HD 7400G"},
                            {0x9995, "Radeon HD 8450G"},
                            {0x9996, "Radeon HD 8470D"},
                            {0x9997, "Radeon HD 8350G"},
                            {0x9998, "Radeon HD 8370D"},
                            {0x9999, "Radeon HD 8510G"},
                            {0x999a, "Radeon HD 8410G"},
                            {0x999b, "Radeon HD 8310G"},
                            {0x999c, "Radeon HD 8650D"},
                            {0x999d, "Radeon HD 8550D"},
                            {0x99a0, "Radeon HD 7520G"},
                            {0x99a2, "Radeon HD 7420G"},
                            {0x99a4, "Radeon HD 7400G"}};

struct keyval nv_gpus[] = {
    {0x0190, "8800 GTS / 8800 GTX"},
    {0x0191, "8800 GTX"},
    {0x0192, "8800 GTS"},
    {0x0193, "8800 GTS"},
    {0x0194, "8800 Ultra"},
    {0x0197, "Tesla C870"},
    {0x019d, "Quadro FX 5600"},
    {0x019e, "Quadro FX 4600"},
    {0x0400, "8600 GTS"},
    {0x0401, "8600 GT"},
    {0x0402, "8600 GT"},
    {0x0403, "8600 GS"},
    {0x0404, "8400 GS"},
    {0x0405, "9500M GS"},
    {0x0406, "8300 GS"},
    {0x0407, "8600M GT"},
    {0x0408, "9650M GS"},
    {0x0409, "8700M GT"},
    {0x040a, "Quadro FX 370"},
    {0x040b, "Quadro NVS 320M"},
    {0x040c, "Quadro FX 570M"},
    {0x040d, "Quadro FX 1600M"},
    {0x040e, "Quadro FX 570"},
    {0x040f, "Quadro FX 1700"},
    {0x0410, "GT 330"},
    {0x0414, "9800 GT"},
    {0x0418, "GT 330"},
    {0x0420, "8400 SE"},
    {0x0421, "8500 GT"},
    {0x0422, "8400 GS"},
    {0x0423, "8300 GS"},
    {0x0424, "8400 GS"},
    {0x0425, "8600M GS"},
    {0x0426, "8400M GT"},
    {0x0427, "8400M GS"},
    {0x0428, "8400M G"},
    {0x0429, "Quadro NVS 140M"},
    {0x042a, "Quadro NVS 130M"},
    {0x042b, "Quadro NVS 135M"},
    {0x042c, "9400 GT"},
    {0x042d, "Quadro FX 360M"},
    {0x042e, "9300M G"},
    {0x042f, "Quadro NVS 290"},
    {0x05e0, "GTX 295"},
    {0x05e1, "GTX 280"},
    {0x05e2, "GTX 260"},
    {0x05e3, "GTX 285"},
    {0x05e6, "GTX 275"},
    {0x05e7, "Tesla C1060 / M1060"},
    {0x05ea, "GTX 260"},
    {0x05eb, "GTX 295"},
    {0x05ed, "Quadro Plex 2200 D2"},
    {0x05f1, "GeForce GTX 280"},
    {0x05f2, "GeForce GTX 260"},
    {0x05f8, "Quadro Plex 2200 S4"},
    {0x05f9, "Quadro CX"},
    {0x05fd, "Quadro FX 5800"},
    {0x05fe, "Quadro FX 4800"},
    {0x05ff, "Quadro FX 3800"},
    {0x0600, "8800 GTS 512"},
    {0x0601, "9800 GT"},
    {0x0602, "8800 GT"},
    {0x0603, "GT 230"},
    {0x0604, "9800 GX2"},
    {0x0605, "9800 GT"},
    {0x0606, "8800 GS"},
    {0x0607, "GTS 240"},
    {0x0608, "9800M GTX"},
    {0x0609, "8800M GTS"},
    {0x060a, "GTX 280M"},
    {0x060b, "9800M GT"},
    {0x060c, "8800M GTX"},
    {0x060d, "8800 GS"},
    {0x060f, "GTX 285M"},
    {0x0610, "9600 GSO"},
    {0x0611, "8800 GT"},
    {0x0612, "9800 GTX / 9800 GTX+"},
    {0x0613, "9800 GTX+"},
    {0x0614, "9800 GT"},
    {0x0615, "GTS 250"},
    {0x0617, "9800M GTX"},
    {0x0618, "GTX 260M"},
    {0x0619, "Quadro FX 4700 X2"},
    {0x061a, "Quadro FX 3700"},
    {0x061b, "Quadro VX 200"},
    {0x061c, "Quadro FX 3600M"},
    {0x061d, "Quadro FX 2800M"},
    {0x061e, "Quadro FX 3700M"},
    {0x061f, "Quadro FX 3800M"},
    {0x0620, "9800 GT"},
    {0x0621, "GT 230"},
    {0x0622, "9600 GT"},
    {0x0623, "9600 GS"},
    {0x0624, "9600 GT Green Edition"},
    {0x0625, "9600 GSO 512"},
    {0x0626, "GT 130"},
    {0x0627, "GT 140"},
    {0x0628, "9800M GTS"},
    {0x062a, "9700M GTS"},
    {0x062b, "9800M GS"},
    {0x062c, "9800M GTS"},
    {0x062d, "9600 GT"},
    {0x062e, "9600 GT"},
    {0x062f, "9800 S"},
    {0x0630, "9600 GT"},
    {0x0631, "GTS 160M"},
    {0x0632, "GTS 150M"},
    {0x0633, "GT 220"},
    {0x0635, "9600 GSO"},
    {0x0637, "9600 GT"},
    {0x0638, "Quadro FX 1800"},
    {0x063a, "Quadro FX 2700M"},
    {0x063f, "9600 GE"},
    {0x0640, "9500 GT"},
    {0x0641, "9400 GT"},
    {0x0642, "D9M-10"},
    {0x0643, "9500 GT"},
    {0x0644, "9500 GS"},
    {0x0645, "9500 GS"},
    {0x0646, "GT 120"},
    {0x0647, "9600M GT"},
    {0x0648, "9600M GS"},
    {0x0649, "9600M GT"},
    {0x064a, "9700M GT"},
    {0x064b, "9500M G"},
    {0x064c, "9650M GT"},
    {0x064e, "9600 GSO / 9800 GT"},
    {0x0651, "G 110M"},
    {0x0652, "GT 130M"},
    {0x0653, "GT 120M"},
    {0x0654, "GT 220M"},
    {0x0655, "GT 120"},
    {0x0656, "GT 120"},
    {0x0658, "Quadro FX 380"},
    {0x0659, "Quadro FX 580"},
    {0x065a, "Quadro FX 1700M"},
    {0x065b, "9400 GT"},
    {0x065c, "Quadro FX 770M"},
    {0x065d, "9500 GA / 9600 GT / GTS 250"},
    {0x065f, "G210"},
    {0x06c0, "GTX 480"},
    {0x06c4, "GTX 465"},
    {0x06ca, "GTX 480M"},
    {0x06cb, "GTX 480"},
    {0x06cd, "GTX 470"},
    {0x06d0, "GF100GL"},
    {0x06d1, "Tesla C2050 / C2070"},
    {0x06d2, "Tesla M2070"},
    {0x06d8, "Quadro 6000"},
    {0x06d9, "Quadro 5000"},
    {0x06da, "Quadro 5000M"},
    {0x06dc, "Quadro 6000"},
    {0x06dd, "Quadro 4000"},
    {0x06de, "Tesla T20 Processor"},
    {0x06df, "Tesla M2070-Q"},
    {0x06e0, "9300 GE"},
    {0x06e1, "9300 GS"},
    {0x06e2, "8400"},
    {0x06e3, "8300 GS"},
    {0x06e4, "8400 GS"},
    {0x06e5, "9300M GS"},
    {0x06e6, "G 100"},
    {0x06e7, "9300 SE"},
    {0x06e8, "9200M GS"},
    {0x06e9, "9300M GS"},
    {0x06ea, "Quadro NVS 150M"},
    {0x06eb, "Quadro NVS 160M"},
    {0x06ec, "G 105M"},
    {0x06ed, "9600 GT / 9800 GT"},
    {0x06ee, "9600 GT / 9800 GT / GT 240"},
    {0x06ef, "G 103M"},
    {0x06f1, "G 105M"},
    {0x06f8, "Quadro NVS 420"},
    {0x06f9, "Quadro FX 370 LP"},
    {0x06fa, "Quadro NVS 450"},
    {0x06fb, "Quadro FX 370M"},
    {0x06fd, "Quadro NVS 295"},
    {0x06ff, "HICx16 + Graphics"},
    {0x0840, "8200M"},
    {0x0844, "9100M G"},
    {0x0845, "8200M G"},
    {0x0846, "9200"},
    {0x0847, "9100"},
    {0x0848, "8300"},
    {0x0849, "8200"},
    {0x084a, "nForce 730a"},
    {0x084b, "8200"},
    {0x084c, "nForce 780a/980a SLI"},
    {0x084d, "nForce 750a SLI"},
    {0x084f, "8100 / nForce 720a"},
    {0x0860, "9300"},
    {0x0861, "9400"},
    {0x0862, "9400M G"},
    {0x0863, "9400M"},
    {0x0864, "9300"},
    {0x0865, "9300 / ION"},
    {0x0866, "9400M G"},
    {0x0867, "9400"},
    {0x0868, "nForce 760i SLI"},
    {0x0869, "9400"},
    {0x086a, "9400"},
    {0x086c, "9300 / nForce 730i"},
    {0x086d, "9200"},
    {0x086e, "9100M G"},
    {0x086f, "8200M G"},
    {0x0870, "9400M"},
    {0x0871, "9200"},
    {0x0872, "G102M"},
    {0x0873, "G102M"},
    {0x0874, "ION"},
    {0x0876, "9400M / ION"},
    {0x087a, "9400"},
    {0x087d, "ION"},
    {0x087e, "ION LE"},
    {0x087f, "ION LE"},
    {0x08a0, "320M"},
    {0x08a2, "320M"},
    {0x08a3, "320M"},
    {0x08a4, "320M"},
    {0x08a5, "320M"},
    {0x0a20, "GT 220"},
    {0x0a21, "GT 330M"},
    {0x0a22, "315"},
    {0x0a23, "210"},
    {0x0a24, "405"},
    {0x0a26, "405"},
    {0x0a27, "405"},
    {0x0a28, "GT 230M"},
    {0x0a29, "GT 330M"},
    {0x0a2a, "GT 230M"},
    {0x0a2b, "GT 330M"},
    {0x0a2c, "NVS 5100M"},
    {0x0a2d, "GT 320M"},
    {0x0a30, "505"},
    {0x0a32, "GT 415"},
    {0x0a34, "GT 240M"},
    {0x0a35, "GT 325M"},
    {0x0a38, "Quadro 400"},
    {0x0a3c, "Quadro FX 880M"},
    {0x0a60, "G210"},
    {0x0a62, "205"},
    {0x0a63, "310"},
    {0x0a64, "ION"},
    {0x0a65, "210"},
    {0x0a66, "310"},
    {0x0a67, "315"},
    {0x0a68, "G 105M"},
    {0x0a69, "G 105M"},
    {0x0a6a, "NVS 2100M"},
    {0x0a6c, "NVS 3100M"},
    {0x0a6e, "305M"},
    {0x0a6f, "ION"},
    {0x0a70, "310M"},
    {0x0a71, "305M"},
    {0x0a72, "310M"},
    {0x0a73, "305M"},
    {0x0a74, "G210M"},
    {0x0a75, "310M"},
    {0x0a76, "ION 2"},
    {0x0a78, "Quadro FX 380 LP"},
    {0x0a7a, "GeForce 315M"},
    {0x0a7b, "GeForce 505"},
    {0x0a7c, "Quadro FX 380M"},
    {0x0ca0, "GT 330"},
    {0x0ca2, "GT 320"},
    {0x0ca3, "GT 240"},
    {0x0ca4, "GT 340"},
    {0x0ca5, "GT 220"},
    {0x0ca7, "GT 330"},
    {0x0ca8, "GTS 260M"},
    {0x0ca9, "GTS 250M"},
    {0x0cac, "GT 220/315"},
    {0x0caf, "GT 335M"},
    {0x0cb0, "GTS 350M"},
    {0x0cb1, "GTS 360M"},
    {0x0cbc, "Quadro FX 1800M"},
    {0x0dc0, "GT 440"},
    {0x0dc4, "GTS 450"},
    {0x0dc5, "GTS 450"},
    {0x0dc6, "GTS 450"},
    {0x0dcd, "GT 555M"},
    {0x0dce, "GT 555M"},
    {0x0dd1, "GTX 460M"},
    {0x0dd2, "GT 445M"},
    {0x0dd3, "GT 435M"},
    {0x0dd6, "GT 550M"},
    {0x0dd8, "Quadro 2000"},
    {0x0dda, "Quadro 2000M"},
    {0x0de0, "GT 440"},
    {0x0de1, "GT 430"},
    {0x0de2, "GT 420"},
    {0x0de3, "GT 635M"},
    {0x0de4, "GT 520"},
    {0x0de5, "GT 530"},
    {0x0de7, "GT 610"},
    {0x0de8, "GT 620M"},
    {0x0de9, "GT 620M/630M/635M/640M LE"},
    {0x0dea, "610M"},
    {0x0deb, "GT 555M"},
    {0x0dec, "GT 525M"},
    {0x0ded, "GT 520M"},
    {0x0dee, "GT 415M"},
    {0x0def, "NVS 5400M"},
    {0x0df0, "GT 425M"},
    {0x0df1, "GT 420M"},
    {0x0df2, "GT 435M"},
    {0x0df3, "GT 420M"},
    {0x0df4, "GT 540M"},
    {0x0df5, "GT 525M"},
    {0x0df6, "GT 550M"},
    {0x0df7, "GT 520M"},
    {0x0df8, "Quadro 600"},
    {0x0df9, "Quadro 500M"},
    {0x0dfa, "Quadro 1000M"},
    {0x0dfc, "NVS 5200M"},
    {0x0e22, "GTX 460"},
    {0x0e23, "GTX 460 SE"},
    {0x0e24, "GTX 460"},
    {0x0e30, "GTX 470M"},
    {0x0e31, "GTX 485M"},
    {0x0e3a, "Quadro 3000M"},
    {0x0e3b, "Quadro 4000M"},
    {0x0f00, "GT 630"},
    {0x0f01, "GT 620"},
    {0x0f02, "GT 730"},
    {0x0f03, "GT 610"},
    {0x0f06, "GT 730"},
    {0x0fc0, "GT 640"},
    {0x0fc1, "GT 640"},
    {0x0fc2, "GT 630"},
    {0x0fc5, "GT 1030"},
    {0x0fc6, "GTX 650"},
    {0x0fc8, "GT 740"},
    {0x0fc9, "GT 730"},
    {0x0fcd, "GT 755M"},
    {0x0fce, "GT 640M LE"},
    {0x0fd1, "GT 650M"},
    {0x0fd2, "GT 640M"},
    {0x0fd3, "GT 640M LE"},
    {0x0fd4, "GTX 660M"},
    {0x0fd5, "GT 650M"},
    {0x0fd6, "GK107M"},
    {0x0fd8, "GT 640M"},
    {0x0fd9, "GT 645M"},
    {0x0fdb, "GK107M"},
    {0x0fdf, "GT 740M"},
    {0x0fe0, "GTX 660M"},
    {0x0fe1, "GT 730M"},
    {0x0fe2, "GT 745M"},
    {0x0fe3, "GT 745M"},
    {0x0fe4, "GT 750M"},
    {0x0fe5, "GeForce K340 USM"},
    {0x0fe6, "GRID K1 NVS USM"},
    {0x0fe7, "GRID K100 vGPU"},
    {0x0fe8, "GK107M"},
    {0x0fe9, "GeForce GT 750M"},
    {0x0fea, "GeForce GT 755M"},
    {0x0fec, "GeForce 710A"},
    {0x0fed, "GeForce 820M"},
    {0x0fee, "GeForce 810M"},
    {0x0fef, "GRID K340"},
    {0x0ff1, "NVS 1000"},
    {0x0ff2, "GRID K1"},
    {0x0ff3, "Quadro K420"},
    {0x0ff5, "GRID K1 Tesla USM"},
    {0x0ff6, "Quadro K1100M"},
    {0x0ff7, "GRID K140Q vGPU"},
    {0x0ff8, "Quadro K500M"},
    {0x0ff9, "Quadro K2000D"},
    {0x0ffa, "Quadro K600"},
    {0x0ffb, "Quadro K2000M"},
    {0x0ffc, "Quadro K1000M"},
    {0x0ffd, "NVS 510"},
    {0x0ffe, "Quadro K2000"},
    {0x0fff, "Quadro 410"},
    {0x1001, "GeForce GTX TITAN Z"},
    {0x1003, "GTX Titan LE"},
    {0x1004, "GTX 780"},
    {0x1005, "GTX TITAN"},
    {0x1007, "GTX 780"},
    {0x1008, "GTX 780 Ti 6GB"},
    {0x100a, "GTX 780 Ti"},
    {0x100c, "GTX TITAN Black"},
    {0x101e, "Tesla K20X"},
    {0x101f, "Tesla K20"},
    {0x1020, "Tesla K20X"},
    {0x1021, "Tesla K20Xm"},
    {0x1022, "Tesla K20c"},
    {0x1023, "Tesla K40m"},
    {0x1024, "Tesla K40c"},
    {0x1026, "Tesla K20s"},
    {0x1027, "Tesla K40st"},
    {0x1028, "Tesla K20m"},
    {0x1029, "Tesla K40s"},
    {0x102a, "Tesla K40t"},
    {0x102d, "Tesla K80"},
    {0x102e, "Tesla K40d"},
    {0x102f, "Tesla Stella Solo"},
    {0x103a, "Quadro K6000"},
    {0x103c, "Quadro K5200"},
    {0x103f, "Tesla Stella SXM"},
    {0x1040, "GT 520"},
    {0x1042, "GeForce 510"},
    {0x1045, "GF119"},
    {0x1048, "GeForce 605"},
    {0x1049, "GT 620"},
    {0x104a, "GT 610"},
    {0x104b, "GT 625"},
    {0x104c, "GT 705"},
    {0x104d, "GT 710"},
    {0x1050, "GT 520M"},
    {0x1051, "GT 520MX"},
    {0x1052, "GT 520M"},
    {0x1054, "GeForce 410M"},
    {0x1055, "GeForce 410M"},
    {0x1056, "NVS 4200M"},
    {0x1057, "Quadro NVS 4200M"},
    {0x1058, "610M"},
    {0x1059, "610M"},
    {0x105a, "610M"},
    {0x105b, "705M"},
    {0x107c, "NVS 315"},
    {0x107d, "NVS 310"},
    {0x1080, "GTX 580"},
    {0x1081, "GTX 570"},
    {0x1082, "GTX 560 Ti"},
    {0x1084, "GTX 560"},
    {0x1086, "GTX 570"},
    {0x1087, "GTX 560 Ti 448 Cores"},
    {0x1088, "GTX 590"},
    {0x1089, "GTX 580"},
    {0x108b, "GTX 580"},
    {0x108e, "Tesla C2090"},
    {0x1091, "Tesla M2090"},
    {0x1094, "Tesla M2075"},
    {0x1096, "Tesla C2050 / C2075"},
    {0x109a, "Quadro 5010M"},
    {0x109b, "Quadro 7000"},
    {0x10c0, "GeForce 9300 GS"},
    {0x10c3, "GeForce 8400 GS"},
    {0x10c5, "GeForce 405"},
    {0x10d8, "NVS 300"},
    {0x1140, "GeForce 610M/710M/810M/820M / GT 620M/625M/630M/720M"},
    {0x1180, "GTX 680"},
    {0x1182, "GTX 760 Ti"},
    {0x1183, "GTX 660 Ti"},
    {0x1184, "GTX 770"},
    {0x1185, "GTX 660"},
    {0x1186, "GTX 660 Ti"},
    {0x1187, "GTX 760"},
    {0x1188, "GTX 690"},
    {0x1189, "GTX 670"},
    {0x118a, "GRID K520"},
    {0x118b, "GRID K2 GeForce USM"},
    {0x118c, "GRID K2 NVS USM"},
    {0x118d, "GRID K200 vGPU"},
    {0x118e, "GTX 760"},
    {0x118f, "Tesla K10"},
    {0x1191, "GTX 760"},
    {0x1193, "GTX 760 Ti"},
    {0x1194, "Tesla K8"},
    {0x1195, "GTX 660"},
    {0x1198, "GTX 880M"},
    {0x1199, "GTX 870M"},
    {0x119a, "GTX 860M"},
    {0x119d, "GTX 775M"},
    {0x119e, "GTX 780M"},
    {0x119f, "GTX 780M"},
    {0x11a0, "GTX 680M"},
    {0x11a1, "GTX 670MX"},
    {0x11a2, "GTX 675MX"},
    {0x11a3, "GTX 680MX"},
    {0x11a7, "GTX 675MX"},
    {0x11a9, "GTX 870M"},
    {0x11af, "GRID IceCube"},
    {0x11b0, "GRID K240Q / K260Q vGPU"},
    {0x11b1, "GRID K2 Tesla USM"},
    {0x11b4, "Quadro K4200"},
    {0x11b6, "Quadro K3100M"},
    {0x11b7, "Quadro K4100M"},
    {0x11b8, "Quadro K5100M"},
    {0x11b9, "GK104GLM"},
    {0x11ba, "Quadro K5000"},
    {0x11bb, "Quadro 4100"},
    {0x11bc, "Quadro K5000M"},
    {0x11bd, "Quadro K4000M"},
    {0x11be, "Quadro K3000M"},
    {0x11bf, "GRID K2"},
    {0x11c0, "GTX 660"},
    {0x11c2, "GTX 650 Ti Boost"},
    {0x11c3, "GTX 650 Ti OEM"},
    {0x11c4, "GTX 645 OEM"},
    {0x11c5, "GT 740"},
    {0x11c6, "GTX 650 Ti"},
    {0x11c7, "GTX 750 Ti"},
    {0x11c8, "GTX 650"},
    {0x11cb, "GT 740"},
    {0x11e0, "GTX 770M"},
    {0x11e1, "GTX 765M"},
    {0x11e2, "GTX 765M"},
    {0x11e3, "GTX 760M"},
    {0x11e7, "GK106M"},
    {0x11fa, "Quadro K4000"},
    {0x11fc, "Quadro K2100M"},
    {0x1200, "GTX 560 Ti"},
    {0x1201, "GTX 560"},
    {0x1202, "GTX 560 Ti"},
    {0x1203, "GTX 460 SE"},
    {0x1205, "GTX 460"},
    {0x1206, "GTX 555"},
    {0x1207, "GT 645"},
    {0x1208, "GTX 560 SE"},
    {0x1210, "GTX 570M"},
    {0x1211, "GTX 580M"},
    {0x1212, "GTX 675M"},
    {0x1213, "GTX 670M"},
    {0x1241, "GT 545"},
    {0x1243, "GT 545"},
    {0x1244, "GTX 550 Ti"},
    {0x1245, "GTS 450"},
    {0x1246, "GT 550M"},
    {0x1247, "GT 555M/635M"},
    {0x1248, "GT 555M/635M"},
    {0x1249, "GTS 450"},
    {0x124b, "GT 640"},
    {0x124d, "GT 555M/635M"},
    {0x1251, "GT 560M"},
    {0x1280, "GT 635"},
    {0x1281, "GT 710"},
    {0x1282, "GT 640"},
    {0x1284, "GT 630"},
    {0x1286, "GT 720"},
    {0x1287, "GT 730"},
    {0x1288, "GT 720"},
    {0x1289, "GT 710"},
    {0x128a, "GK208B"},
    {0x128b, "GT 710"},
    {0x128c, "GK208B"},
    {0x1290, "GT 730M"},
    {0x1291, "GT 735M"},
    {0x1292, "GT 740M"},
    {0x1293, "GT 730M"},
    {0x1294, "GT 740M"},
    {0x1295, "GeForce 710M"},
    {0x1296, "GeForce 825M"},
    {0x1298, "GT 720M"},
    {0x1299, "GeForce 920M"},
    {0x129a, "GeForce 910M"},
    {0x12a0, "GK208"},
    {0x12b9, "Quadro K610M"},
    {0x12ba, "Quadro K510M"},
    {0x1340, "GeForce 830M"},
    {0x1341, "GeForce 840M"},
    {0x1344, "GeForce 845M"},
    {0x1346, "GeForce 930M"},
    {0x1347, "GeForce 940M"},
    {0x1348, "GeForce 945M / 945A"},
    {0x1349, "GeForce 930M"},
    {0x134b, "GeForce 940MX"},
    {0x134d, "GeForce 940MX"},
    {0x134e, "GeForce 930MX"},
    {0x134f, "GeForce 920MX"},
    {0x137a, "Quadro K620M / Quadro M500M"},
    {0x137b, "Quadro M520 Mobile"},
    {0x137d, "GeForce 940A"},
    {0x1380, "GTX 750 Ti"},
    {0x1381, "GTX 750"},
    {0x1382, "GTX 745"},
    {0x1389, "GRID M30"},
    {0x1390, "GeForce 845M"},
    {0x1391, "GTX 850M"},
    {0x1392, "GTX 860M"},
    {0x1393, "GeForce 840M"},
    {0x1398, "GeForce 845M"},
    {0x1399, "GeForce 945M"},
    {0x139a, "GTX 950M"},
    {0x139b, "GTX 960M"},
    {0x139c, "940M"},
    {0x139d, "GTX 750 Ti"},
    {0x13b0, "Quadro M2000M"},
    {0x13b1, "Quadro M1000M"},
    {0x13b2, "Quadro M600M"},
    {0x13b3, "Quadro K2200M"},
    {0x13b4, "Quadro M620 Mobile"},
    {0x13b6, "Quadro M1200 Mobile"},
    {0x13b9, "NVS 810"},
    {0x13ba, "Quadro K2200"},
    {0x13bb, "Quadro K620"},
    {0x13bc, "Quadro K1200"},
    {0x13bd, "Tesla M10"},
    {0x13c0, "GeForce GTX 980"},
    {0x13c1, "GM204"},
    {0x13c2, "GeForce GTX 970"},
    {0x13c3, "GM204"},
    {0x13d7, "GTX 980M"},
    {0x13d8, "GTX 970M"},
    {0x13d9, "GTX 965M"},
    {0x13da, "GTX 980 Mobile"},
    {0x13e7, "GTX 980"},
    {0x13f0, "Quadro M5000"},
    {0x13f1, "Quadro M4000"},
    {0x13f2, "Tesla M60"},
    {0x13f3, "Tesla M6"},
    {0x13f8, "Quadro M5000M / M5000 SE"},
    {0x13f9, "Quadro M4000M"},
    {0x13fa, "Quadro M3000M"},
    {0x13fb, "Quadro M5500"},
    {0x1401, "GTX 960"},
    {0x1402, "GTX 950"},
    {0x1404, "GTX 960"},
    {0x1406, "GTX 960"},
    {0x1407, "GTX 750"},
    {0x1427, "GTX 965M"},
    {0x1430, "Quadro M2000"},
    {0x1431, "Tesla M4"},
    {0x1436, "Quadro M2200 Mobile"},
    {0x15f0, "Quadro GP100"},
    {0x15f1, "GP100GL"},
    {0x15f7, "Tesla P100"},
    {0x15f8, "Tesla P100"},
    {0x15f9, "Tesla P100"},
    {0x1617, "GTX 980M"},
    {0x1618, "GTX 970M"},
    {0x1619, "TX 965M"},
    {0x161a, "GTX 980 Mobile"},
    {0x1667, "GTX 965M"},
    {0x1725, "GP100"},
    {0x172e, "GP100"},
    {0x172f, "GP100"},
    {0x174d, "MX130"},
    {0x174e, "MX110"},
    {0x179c, "940MX"},
    {0x17c2, "GTX TITAN X"},
    {0x17c8, "GTX 980 Ti"},
    {0x17f0, "Quadro M6000"},
    {0x17f1, "Quadro M6000 24GB"},
    {0x17fd, "Tesla M40"},
    {0x1b00, "TITAN X"},
    {0x1b01, "GTX 1080 Ti 10GB"},
    {0x1b02, "TITAN Xp"},
    {0x1b04, "GP102"},
    {0x1b06, "GTX 1080 Ti"},
    {0x1b07, "P102-100"},
    {0x1b30, "Quadro P6000"},
    {0x1b38, "Tesla P40"},
    {0x1b39, "Tesla P10"},
    {0x1b70, "GP102GL"},
    {0x1b78, "GP102GL"},
    {0x1b80, "GTX 1080"},
    {0x1b81, "GTX 1070"},
    {0x1b82, "GTX 1070 Ti"},
    {0x1b83, "GTX 1060 6GB"},
    {0x1b84, "GTX 1060 3GB"},
    {0x1b87, "P104-100"},
    {0x1ba0, "GTX 1080 Mobile"},
    {0x1ba1, "GTX 1070 Mobile"},
    {0x1ba2, "GTX 1070 Mobile"},
    {0x1ba9, "GP104M"},
    {0x1baa, "GP104M"},
    {0x1bad, "GTX 1070 Engineering Sample"},
    {0x1bb0, "Quadro P5000"},
    {0x1bb1, "Quadro P4000"},
    {0x1bb3, "Tesla P4"},
    {0x1bb4, "Tesla P6"},
    {0x1bb5, "Quadro P5200 Mobile"},
    {0x1bb6, "Quadro P5000 Mobile"},
    {0x1bb7, "Quadro P4000 Mobile"},
    {0x1bb8, "Quadro P3000 Mobile"},
    {0x1bb9, "Quadro P4200 Mobile"},
    {0x1bbb, "Quadro P3200 Mobile"},
    {0x1bc7, "P104-101"},
    {0x1be0, "GTX 1080 Mobile"},
    {0x1be1, "GTX 1070 Mobile"},
    {0x1c00, "GP106"},
    {0x1c01, "GP106"},
    {0x1c02, "GTX 1060 3GB"},
    {0x1c03, "GTX 1060 6GB"},
    {0x1c04, "GTX 1060 5GB"},
    {0x1c06, "GTX 1060 6GB"},
    {0x1c07, "P106-100"},
    {0x1c09, "P106-090"},
    {0x1c20, "GTX 1060 Mobile"},
    {0x1c21, "GTX 1050 Ti Mobile"},
    {0x1c22, "GTX 1050 Mobile"},
    {0x1c23, "GTX 1060 Mobile"},
    {0x1c2d, "GP106M"},
    {0x1c30, "Quadro P2000"},
    {0x1c31, "Quadro P2200"},
    {0x1c35, "Quadro P2000 Mobile"},
    {0x1c36, "P106M"},
    {0x1c60, "GTX 1060 Mobile 6GB"},
    {0x1c61, "GTX 1050 Ti Mobile"},
    {0x1c62, "GTX 1050 Mobile"},
    {0x1c70, "GP106GL"},
    {0x1c81, "GTX 1050"},
    {0x1c82, "GTX 1050 Ti"},
    {0x1c83, "GTX 1050 3GB"},
    {0x1c8c, "GTX 1050 Ti Mobile"},
    {0x1c8d, "GTX 1050 Mobile"},
    {0x1c8e, "GP107M"},
    {0x1c8f, "GTX 1050 Ti Max-Q"},
    {0x1c90, "MX150"},
    {0x1c91, "GTX 1050 3GB Max-Q"},
    {0x1c92, "GTX 1050 Mobile"},
    {0x1c94, "MX350"},
    {0x1c96, "MX350"},
    {0x1ca7, "GP107GL"},
    {0x1ca8, "GP107GL"},
    {0x1caa, "GP107GL"},
    {0x1cb1, "Quadro P1000"},
    {0x1cb2, "Quadro P600"},
    {0x1cb3, "Quadro P400"},
    {0x1cb6, "Quadro P620"},
    {0x1cba, "Quadro P2000 Mobile"},
    {0x1cbb, "Quadro P1000 Mobile"},
    {0x1cbc, "Quadro P600 Mobile"},
    {0x1cbd, "Quadro P620"},
    {0x1ccc, "GTX 1050 Ti Mobile"},
    {0x1ccd, "GTX 1050 Mobile"},
    {0x1cfa, "Quadro P2000"},
    {0x1cfb, "Quadro P1000"},
    {0x1d01, "GT 1030"},
    {0x1d02, "GT 1010"},
    {0x1d10, "MX150"},
    {0x1d11, "MX230"},
    {0x1d12, "MX150"},
    {0x1d13, "MX250"},
    {0x1d16, "MX330"},
    {0x1d33, "Quadro P500 Mobile"},
    {0x1d34, "Quadro P520"},
    {0x1d52, "MX250"},
    {0x1d56, "MX330"},
    {0x1d81, "TITAN V"},
    {0x1dba, "Quadro GV100"},
    {0x1e02, "TITAN RTX"},
    {0x1e04, "RTX 2080 Ti"},
    {0x1e07, "RTX 2080 Ti"},
    {0x1e09, "CMP 50HX"},
    {0x1e2d, "RTX 2080 Ti"},
    {0x1e2e, "RTX 2080 Ti 12GB"},
    {0x1e30, "Quadro RTX 6000/8000"},
    {0x1e36, "Quadro RTX 6000"},
    {0x1e38, "TU102GL"},
    {0x1e3c, "TU102GL"},
    {0x1e3d, "TU102GL"},
    {0x1e3e, "TU102GL"},
    {0x1e78, "Quadro RTX 6000/8000"},
    {0x1e81, "RTX 2080 SUPER"},
    {0x1e82, "RTX 2080"},
    {0x1e84, "RTX 2070 SUPER"},
    {0x1e87, "RTX 2080"},
    {0x1e89, "RTX 2060"},
    {0x1e90, "RTX 2080 Mobile"},
    {0x1e91, "RTX 2070 SUPER Mobile / Max-Q"},
    {0x1e93, "RTX 2080 SUPER Mobile / Max-Q"},
    {0x1eab, "TU104M"},
    {0x1eae, "TU104M"},
    {0x1eb0, "Quadro RTX 5000"},
    {0x1eb1, "Quadro RTX 4000"},
    {0x1eb5, "Quadro RTX 5000 Mobile / Max-Q"},
    {0x1eb6, "Quadro RTX 4000 Mobile / Max-Q"},
    {0x1eb8, "Tesla T4"},
    {0x1eb9, "TU104GL"},
    {0x1ebe, "TU104GL"},
    {0x1ec2, "RTX 2070 SUPER"},
    {0x1ec7, "RTX 2070 SUPER"},
    {0x1ed0, "RTX 2080 Mobile"},
    {0x1ed1, "RTX 2070 SUPER Mobile / Max-Q"},
    {0x1ed3, "RTX 2080 SUPER Mobile / Max-Q"},
    {0x1ef5, "Quadro RTX 5000 Mobile"},
    {0x1f02, "RTX 2070"},
    {0x1f03, "RTX 2060 12GB"},
    {0x1f04, "TU106"},
    {0x1f06, "RTX 2060 SUPER"},
    {0x1f07, "RTX 2070"},
    {0x1f08, "RTX 2060"},
    {0x1f09, "GTX 1660 SUPER"},
    {0x1f0a, "GTX 1650"},
    {0x1f0b, "CMP 40HX"},
    {0x1f10, "RTX 2070 Mobile"},
    {0x1f11, "RTX 2060 Mobile"},
    {0x1f12, "RTX 2060 Max-Q"},
    {0x1f14, "RTX 2070 Mobile / Max-Q"},
    {0x1f15, "RTX 2060 Mobile"},
    {0x1f2e, "TU106M"},
    {0x1f36, "Quadro RTX 3000 Mobile / Max-Q"},
    {0x1f42, "RTX 2060 SUPER"},
    {0x1f47, "RTX 2060 SUPER"},
    {0x1f50, "RTX 2070 Mobile / Max-Q"},
    {0x1f51, "RTX 2060 Mobile"},
    {0x1f54, "RTX 2070 Mobile"},
    {0x1f55, "RTX 2060 Mobile"},
    {0x1f76, "Quadro RTX 3000 Mobile"},
    {0x1f81, "TU117"},
    {0x1f82, "GTX 1650"},
    {0x1f91, "GTX 1650 Mobile / Max-Q"},
    {0x1f92, "GTX 1650 Mobile"},
    {0x1f94, "GTX 1650 Mobile"},
    {0x1f95, "GTX 1650 Ti Mobile"},
    {0x1f96, "GTX 1650 Mobile / Max-Q"},
    {0x1f97, "MX450"},
    {0x1f98, "MX450"},
    {0x1f99, "TU117M"},
    {0x1f9c, "MX450"},
    {0x1f9d, "GTX 1650 Mobile / Max-Q"},
    {0x1f9f, "MX550"},
    {0x1fa0, "MX550"},
    {0x1fae, "TU117GL"},
    {0x1fb0, "Quadro T1000 Mobile"},
    {0x1fb1, "T600"},
    {0x1fb2, "Quadro T400 Mobile"},
    {0x1fb8, "Quadro T2000 Mobile / Max-Q"},
    {0x1fb9, "Quadro T1000 Mobile"},
    {0x1fba, "T600 Mobile"},
    {0x1fbb, "Quadro T500 Mobile"},
    {0x1fbc, "T1200 Laptop GPU"},
    {0x1fbf, "TU117GL"},
    {0x1fd9, "GTX 1650 Mobile"},
    {0x1fdd, "GTX 1650 Mobile"},
    {0x1ff0, "T1000 8GB"},
    {0x1ff2, "T400 4GB"},
    {0x1ff9, "Quadro T1000 Mobile"},
    {0x20b0, "A100"},
    {0x20b1, "A100"},
    {0x20b2, "A100"},
    {0x20b5, "A100"},
    {0x20b6, "PG506-232"},
    {0x20b7, "A30	"},
    {0x20c2, "CMP 170HX"},
    {0x20f1, "A100"},
    {0x2182, "GTX 1660 Ti"},
    {0x2183, "TU116"},
    {0x2184, "GTX 1660"},
    {0x2187, "GTX 1650 SUPER"},
    {0x2188, "GTX 1650"},
    {0x2189, "CMP 30HX"},
    {0x2191, "GTX 1660 Ti Mobile"},
    {0x2192, "GTX 1650 Ti Mobile"},
    {0x21ae, "TU116GL"},
    {0x21bf, "TU116GL"},
    {0x21c2, "TU116"},
    {0x21c4, "GTX 1660 SUPER"},
    {0x21d1, "GTX 1660 Ti Mobile"},
    {0x2200, "GA102"},
    {0x2204, "RTX 3090"},
    {0x2205, "RTX 3080 Ti 20GB"},
    {0x2206, "RTX 3080"},
    {0x2208, "RTX 3080 Ti"},
    {0x220a, "RTX 3080 12GB"},
    {0x220d, "CMP 90HX"},
    {0x2216, "RTX 3080 Lite Hash Rate"},
    {0x222b, "RTX 3090 Engineering Sample"},
    {0x222f, "RTX 3080 11GB / 12GB Engineering Sample"},
    {0x2230, "RTX A6000"},
    {0x2231, "RTX A5000"},
    {0x2232, "RTX A4500"},
    {0x2235, "A40"},
    {0x2236, "A10"},
    {0x2237, "A10G"},
    {0x223f, "GA102GL"},
    {0x2302, "GA103"},
    {0x2321, "GA103"},
    {0x2414, "RTX 3060 Ti"},
    {0x2420, "RTX 3080 Ti Mobile"},
    {0x2482, "RTX 3070 Ti"},
    {0x2483, "GA104"},
    {0x2484, "RTX 3070"},
    {0x2486, "RTX 3060 Ti"},
    {0x2487, "RTX 3060"},
    {0x2488, "RTX 3070"},
    {0x2489, "RTX 3060 Ti"},
    {0x248a, "CMP 70HX"},
    {0x249c, "RTX 3080 Mobile / Max-Q"},
    {0x249d, "RTX 3070 Mobile / Max-Q"},
    {0x249f, "GA104M"},
    {0x24a0, "RTX 3070 Ti"},
    {0x24ac, "GA104"},
    {0x24ad, "RTX 3060"},
    {0x24af, "RTX 3070"},
    {0x24b0, "RTX A4000"},
    {0x24b6, "RTX A5000 Mobile"},
    {0x24b7, "RTX A4000 Mobile"},
    {0x24b8, "RTX A3000 Mobile"},
    {0x24bf, "RTX 3070"},
    {0x24dc, "RTX 3080 Mobile / Max-Q"},
    {0x24dd, "RTX 3070 Mobile / Max-Q"},
    {0x2501, "RTX 3060"},
    {0x2503, "RTX 3060"},
    {0x2504, "RTX 3060"},
    {0x2505, "GA106"},
    {0x2520, "RTX 3060 Mobile / Max-Q"},
    {0x2523, "RTX 3050 Ti Mobile / Max-Q"},
    {0x252f, "RTX 3060"},
    {0x2531, "RTX A2000"},
    {0x2560, "RTX 3060 Mobile / Max-Q"},
    {0x2563, "RTX 3050 Ti Mobile / Max-Q"},
    {0x2571, "RTX A2000 12GB"},
    {0x2583, "RTX 3050"},
    {0x25a0, "RTX 3050 Ti Mobile"},
    {0x25a2, "RTX 3050 Mobile"},
    {0x25a4, "GA107"},
    {0x25a5, "RTX 3050 Mobile"},
    {0x25a6, "MX570"},
    {0x25a7, "MX570"},
    {0x25a9, "RTX 2050"},
    {0x25af, "RTX 3050"},
    {0x25b5, "RTX A4 Mobile"},
    {0x25b8, "RTX A2000 Mobile"},
    {0x25e0, "RTX 3050 Ti Mobile"},
    {0x25e2, "RTX 3050 Mobile"},
    {0x25e5, "RTX 3050 Mobile"}};
