#pragma once
#include "common.h"
static inline void gen_reproject_gen2_axis_angle(FLT *out, const LinmathAxisAnglePose *obj_p, const FLT *sensor_pt,
												 const LinmathAxisAnglePose *lh_p, const BaseStationCal *bsd) {
	const GEN_FLT obj_px = (*obj_p).Pos[0];
	const GEN_FLT obj_py = (*obj_p).Pos[1];
	const GEN_FLT obj_pz = (*obj_p).Pos[2];
	const GEN_FLT obj_qi = (*obj_p).AxisAngleRot[0];
	const GEN_FLT obj_qj = (*obj_p).AxisAngleRot[1];
	const GEN_FLT obj_qk = (*obj_p).AxisAngleRot[2];
	const GEN_FLT sensor_x = sensor_pt[0];
	const GEN_FLT sensor_y = sensor_pt[1];
	const GEN_FLT sensor_z = sensor_pt[2];
	const GEN_FLT lh_px = (*lh_p).Pos[0];
	const GEN_FLT lh_py = (*lh_p).Pos[1];
	const GEN_FLT lh_pz = (*lh_p).Pos[2];
	const GEN_FLT lh_qi = (*lh_p).AxisAngleRot[0];
	const GEN_FLT lh_qj = (*lh_p).AxisAngleRot[1];
	const GEN_FLT lh_qk = (*lh_p).AxisAngleRot[2];
	const GEN_FLT phase_0 = bsd[0].phase;
	const GEN_FLT tilt_0 = bsd[0].tilt;
	const GEN_FLT curve_0 = bsd[0].curve;
	const GEN_FLT gibPhase_0 = bsd[0].gibpha;
	const GEN_FLT gibMag_0 = bsd[0].gibmag;
	const GEN_FLT ogeeMag_0 = bsd[0].ogeephase;
	const GEN_FLT ogeePhase_0 = bsd[0].ogeemag;
	const GEN_FLT phase_1 = bsd[1].phase;
	const GEN_FLT tilt_1 = bsd[1].tilt;
	const GEN_FLT curve_1 = bsd[1].curve;
	const GEN_FLT gibPhase_1 = bsd[1].gibpha;
	const GEN_FLT gibMag_1 = bsd[1].gibmag;
	const GEN_FLT ogeeMag_1 = bsd[1].ogeephase;
	const GEN_FLT ogeePhase_1 = bsd[1].ogeemag;
	const GEN_FLT x0 = obj_qk * obj_qk;
	const GEN_FLT x1 = obj_qi * obj_qi;
	const GEN_FLT x2 = obj_qj * obj_qj;
	const GEN_FLT x3 = 1e-10 + x2 + x0 + x1;
	const GEN_FLT x4 = sqrt(x3);
	const GEN_FLT x5 = cos(x4);
	const GEN_FLT x6 = (1. / x3) * (1 + (-1 * x5));
	const GEN_FLT x7 = (1. / x4) * sin(x4);
	const GEN_FLT x8 = x7 * obj_qj;
	const GEN_FLT x9 = x6 * obj_qi;
	const GEN_FLT x10 = x9 * obj_qk;
	const GEN_FLT x11 = x7 * obj_qi;
	const GEN_FLT x12 = x6 * obj_qk * obj_qj;
	const GEN_FLT x13 =
		((x12 + x11) * sensor_y) + obj_pz + ((x10 + (-1 * x8)) * sensor_x) + ((x5 + (x0 * x6)) * sensor_z);
	const GEN_FLT x14 = lh_qk * lh_qk;
	const GEN_FLT x15 = lh_qi * lh_qi;
	const GEN_FLT x16 = lh_qj * lh_qj;
	const GEN_FLT x17 = 1e-10 + x14 + x16 + x15;
	const GEN_FLT x18 = sqrt(x17);
	const GEN_FLT x19 = cos(x18);
	const GEN_FLT x20 = (1. / x17) * (1 + (-1 * x19));
	const GEN_FLT x21 = x7 * obj_qk;
	const GEN_FLT x22 = x9 * obj_qj;
	const GEN_FLT x23 =
		((x22 + (-1 * x21)) * sensor_y) + ((x10 + x8) * sensor_z) + ((x5 + (x1 * x6)) * sensor_x) + obj_px;
	const GEN_FLT x24 = (1. / x18) * sin(x18);
	const GEN_FLT x25 = x24 * lh_qj;
	const GEN_FLT x26 = x20 * lh_qk * lh_qi;
	const GEN_FLT x27 =
		((x5 + (x2 * x6)) * sensor_y) + ((x22 + x21) * sensor_x) + obj_py + ((x12 + (-1 * x11)) * sensor_z);
	const GEN_FLT x28 = x24 * lh_qi;
	const GEN_FLT x29 = x20 * lh_qj;
	const GEN_FLT x30 = x29 * lh_qk;
	const GEN_FLT x31 = ((x30 + x28) * x27) + ((x26 + (-1 * x25)) * x23) + lh_pz + (x13 * (x19 + (x20 * x14)));
	const GEN_FLT x32 = x24 * lh_qk;
	const GEN_FLT x33 = x29 * lh_qi;
	const GEN_FLT x34 = ((x33 + (-1 * x32)) * x27) + (x23 * (x19 + (x20 * x15))) + lh_px + ((x26 + x25) * x13);
	const GEN_FLT x35 = atan2(-1 * x31, x34);
	const GEN_FLT x36 = -1 * x35;
	const GEN_FLT x37 = 0.523598775598299 + tilt_0;
	const GEN_FLT x38 = cos(x37);
	const GEN_FLT x39 = (x27 * (x19 + (x20 * x16))) + ((x33 + x32) * x23) + lh_py + ((x30 + (-1 * x28)) * x13);
	const GEN_FLT x40 = (x34 * x34) + (x31 * x31);
	const GEN_FLT x41 = x39 * (1. / sqrt(x40 + (x39 * x39)));
	const GEN_FLT x42 = asin(x41 * (1. / x38));
	const GEN_FLT x43 = 0.0028679863 + (x42 * (-8.0108022e-06 + (-8.0108022e-06 * x42)));
	const GEN_FLT x44 = 5.3685255e-06 + (x42 * x43);
	const GEN_FLT x45 = 0.0076069798 + (x42 * x44);
	const GEN_FLT x46 = (1. / sqrt(x40)) * x39;
	const GEN_FLT x47 = x46 * tan(x37);
	const GEN_FLT x48 = (sin((-1 * asin(x47)) + x35 + ogeeMag_0) * ogeePhase_0) + curve_0;
	const GEN_FLT x49 = asin(
		x47 +
		((x42 * x42) * x45 * x48 *
		 (1. /
		  (x38 + (-1 * x48 * sin(x37) *
				  ((x42 * (x45 + (x42 * (x44 + (x42 * (x43 + (x42 * (-8.0108022e-06 + (-1.60216044e-05 * x42))))))))) +
				   (x42 * x45)))))));
	const GEN_FLT x50 = -1.5707963267949 + x35;
	const GEN_FLT x51 = 0.523598775598299 + (-1 * tilt_1);
	const GEN_FLT x52 = -1 * x46 * tan(x51);
	const GEN_FLT x53 = (sin((-1 * asin(x52)) + ogeeMag_1 + x35) * ogeePhase_1) + curve_1;
	const GEN_FLT x54 = cos(x51);
	const GEN_FLT x55 = asin((1. / x54) * x41);
	const GEN_FLT x56 = 0.0028679863 + (x55 * (-8.0108022e-06 + (-8.0108022e-06 * x55)));
	const GEN_FLT x57 = 5.3685255e-06 + (x56 * x55);
	const GEN_FLT x58 = 0.0076069798 + (x57 * x55);
	const GEN_FLT x59 = asin(
		x52 +
		(x53 * x58 * (x55 * x55) *
		 (1. /
		  (x54 + (x53 * sin(x51) *
				  ((x55 * (x58 + (x55 * (x57 + (x55 * (x56 + (x55 * (-8.0108022e-06 + (-1.60216044e-05 * x55))))))))) +
				   (x58 * x55)))))));
	out[0] = (-1 * x49) + x50 + (-1 * phase_0) + (-1 * sin((-1 * gibPhase_0) + x49 + x36) * gibMag_0);
	out[1] = (-1 * x59) + (-1 * phase_1) + x50 + (-1 * sin(x36 + x59 + (-1 * gibPhase_1)) * gibMag_1);
}

// Jacobian of reproject_gen2 wrt [obj_px, obj_py, obj_pz, obj_qi, obj_qj, obj_qk]
static inline void gen_reproject_gen2_jac_obj_p_axis_angle(FLT *out, const LinmathAxisAnglePose *obj_p,
														   const FLT *sensor_pt, const LinmathAxisAnglePose *lh_p,
														   const BaseStationCal *bsd) {
	const GEN_FLT obj_px = (*obj_p).Pos[0];
	const GEN_FLT obj_py = (*obj_p).Pos[1];
	const GEN_FLT obj_pz = (*obj_p).Pos[2];
	const GEN_FLT obj_qi = (*obj_p).AxisAngleRot[0];
	const GEN_FLT obj_qj = (*obj_p).AxisAngleRot[1];
	const GEN_FLT obj_qk = (*obj_p).AxisAngleRot[2];
	const GEN_FLT sensor_x = sensor_pt[0];
	const GEN_FLT sensor_y = sensor_pt[1];
	const GEN_FLT sensor_z = sensor_pt[2];
	const GEN_FLT lh_px = (*lh_p).Pos[0];
	const GEN_FLT lh_py = (*lh_p).Pos[1];
	const GEN_FLT lh_pz = (*lh_p).Pos[2];
	const GEN_FLT lh_qi = (*lh_p).AxisAngleRot[0];
	const GEN_FLT lh_qj = (*lh_p).AxisAngleRot[1];
	const GEN_FLT lh_qk = (*lh_p).AxisAngleRot[2];
	const GEN_FLT phase_0 = bsd[0].phase;
	const GEN_FLT tilt_0 = bsd[0].tilt;
	const GEN_FLT curve_0 = bsd[0].curve;
	const GEN_FLT gibPhase_0 = bsd[0].gibpha;
	const GEN_FLT gibMag_0 = bsd[0].gibmag;
	const GEN_FLT ogeeMag_0 = bsd[0].ogeephase;
	const GEN_FLT ogeePhase_0 = bsd[0].ogeemag;
	const GEN_FLT phase_1 = bsd[1].phase;
	const GEN_FLT tilt_1 = bsd[1].tilt;
	const GEN_FLT curve_1 = bsd[1].curve;
	const GEN_FLT gibPhase_1 = bsd[1].gibpha;
	const GEN_FLT gibMag_1 = bsd[1].gibmag;
	const GEN_FLT ogeeMag_1 = bsd[1].ogeephase;
	const GEN_FLT ogeePhase_1 = bsd[1].ogeemag;
	const GEN_FLT x0 = lh_qk * lh_qk;
	const GEN_FLT x1 = lh_qi * lh_qi;
	const GEN_FLT x2 = lh_qj * lh_qj;
	const GEN_FLT x3 = 1e-10 + x2 + x0 + x1;
	const GEN_FLT x4 = sqrt(x3);
	const GEN_FLT x5 = (1. / x4) * sin(x4);
	const GEN_FLT x6 = x5 * lh_qi;
	const GEN_FLT x7 = cos(x4);
	const GEN_FLT x8 = (1. / x3) * (1 + (-1 * x7));
	const GEN_FLT x9 = x8 * lh_qj;
	const GEN_FLT x10 = x9 * lh_qk;
	const GEN_FLT x11 = x10 + (-1 * x6);
	const GEN_FLT x12 = obj_qk * obj_qk;
	const GEN_FLT x13 = obj_qi * obj_qi;
	const GEN_FLT x14 = obj_qj * obj_qj;
	const GEN_FLT x15 = 1e-10 + x14 + x12 + x13;
	const GEN_FLT x16 = 1. / x15;
	const GEN_FLT x17 = sqrt(x15);
	const GEN_FLT x18 = cos(x17);
	const GEN_FLT x19 = 1 + (-1 * x18);
	const GEN_FLT x20 = x19 * x16;
	const GEN_FLT x21 = sin(x17);
	const GEN_FLT x22 = x21 * (1. / x17);
	const GEN_FLT x23 = x22 * obj_qj;
	const GEN_FLT x24 = -1 * x23;
	const GEN_FLT x25 = x20 * obj_qi;
	const GEN_FLT x26 = x25 * obj_qk;
	const GEN_FLT x27 = x22 * obj_qi;
	const GEN_FLT x28 = x20 * obj_qj;
	const GEN_FLT x29 = x28 * obj_qk;
	const GEN_FLT x30 = ((x29 + x27) * sensor_y) + ((x26 + x24) * sensor_x) + obj_pz + ((x18 + (x20 * x12)) * sensor_z);
	const GEN_FLT x31 = x22 * obj_qk;
	const GEN_FLT x32 = -1 * x31;
	const GEN_FLT x33 = x28 * obj_qi;
	const GEN_FLT x34 = ((x26 + x23) * sensor_z) + ((x18 + (x20 * x13)) * sensor_x) + ((x33 + x32) * sensor_y) + obj_px;
	const GEN_FLT x35 = x5 * lh_qk;
	const GEN_FLT x36 = x9 * lh_qi;
	const GEN_FLT x37 = x36 + x35;
	const GEN_FLT x38 = -1 * x27;
	const GEN_FLT x39 = ((x18 + (x20 * x14)) * sensor_y) + ((x33 + x31) * sensor_x) + obj_py + ((x29 + x38) * sensor_z);
	const GEN_FLT x40 = x7 + (x2 * x8);
	const GEN_FLT x41 = (x40 * x39) + (x34 * x37) + lh_py + (x30 * x11);
	const GEN_FLT x42 = x41 * x41;
	const GEN_FLT x43 = x7 + (x0 * x8);
	const GEN_FLT x44 = x5 * lh_qj;
	const GEN_FLT x45 = x8 * lh_qk * lh_qi;
	const GEN_FLT x46 = x45 + (-1 * x44);
	const GEN_FLT x47 = x10 + x6;
	const GEN_FLT x48 = (x46 * x34) + lh_pz + (x47 * x39) + (x43 * x30);
	const GEN_FLT x49 = x45 + x44;
	const GEN_FLT x50 = x7 + (x1 * x8);
	const GEN_FLT x51 = x36 + (-1 * x35);
	const GEN_FLT x52 = (x50 * x34) + (x51 * x39) + lh_px + (x49 * x30);
	const GEN_FLT x53 = x52 * x52;
	const GEN_FLT x54 = x53 + (x48 * x48);
	const GEN_FLT x55 = x54 + x42;
	const GEN_FLT x56 = 1. / sqrt(x55);
	const GEN_FLT x57 = 0.523598775598299 + tilt_0;
	const GEN_FLT x58 = cos(x57);
	const GEN_FLT x59 = 1. / x58;
	const GEN_FLT x60 = x56 * x59;
	const GEN_FLT x61 = asin(x60 * x41);
	const GEN_FLT x62 = 8.0108022e-06 * x61;
	const GEN_FLT x63 = -8.0108022e-06 + (-1 * x62);
	const GEN_FLT x64 = 0.0028679863 + (x63 * x61);
	const GEN_FLT x65 = 5.3685255e-06 + (x64 * x61);
	const GEN_FLT x66 = 0.0076069798 + (x61 * x65);
	const GEN_FLT x67 = x61 * x66;
	const GEN_FLT x68 = -8.0108022e-06 + (-1.60216044e-05 * x61);
	const GEN_FLT x69 = x64 + (x61 * x68);
	const GEN_FLT x70 = x65 + (x61 * x69);
	const GEN_FLT x71 = x66 + (x70 * x61);
	const GEN_FLT x72 = (x71 * x61) + x67;
	const GEN_FLT x73 = atan2(-1 * x48, x52);
	const GEN_FLT x74 = 1. / sqrt(x54);
	const GEN_FLT x75 = tan(x57);
	const GEN_FLT x76 = x75 * x74;
	const GEN_FLT x77 = x76 * x41;
	const GEN_FLT x78 = x73 + (-1 * asin(x77)) + ogeeMag_0;
	const GEN_FLT x79 = (sin(x78) * ogeePhase_0) + curve_0;
	const GEN_FLT x80 = sin(x57);
	const GEN_FLT x81 = x80 * x79;
	const GEN_FLT x82 = x58 + (-1 * x81 * x72);
	const GEN_FLT x83 = 1. / x82;
	const GEN_FLT x84 = x61 * x61;
	const GEN_FLT x85 = x84 * x79;
	const GEN_FLT x86 = x83 * x85;
	const GEN_FLT x87 = x77 + (x86 * x66);
	const GEN_FLT x88 = 1. / sqrt(1 + (-1 * (x87 * x87)));
	const GEN_FLT x89 = (1. / x55) * x42;
	const GEN_FLT x90 = 1. / sqrt(1 + (-1 * x89 * (1. / (x58 * x58))));
	const GEN_FLT x91 = 2 * x41;
	const GEN_FLT x92 = 2 * x52;
	const GEN_FLT x93 = 2 * x48;
	const GEN_FLT x94 = (x93 * x46) + (x50 * x92);
	const GEN_FLT x95 = x94 + (x91 * x37);
	const GEN_FLT x96 = 1.0 / 2.0 * x41;
	const GEN_FLT x97 = (1. / (x55 * sqrt(x55))) * x96;
	const GEN_FLT x98 = x59 * x97;
	const GEN_FLT x99 = (x60 * x37) + (-1 * x98 * x95);
	const GEN_FLT x100 = x90 * x99;
	const GEN_FLT x101 = 2 * x83 * x79 * x67;
	const GEN_FLT x102 = x63 * x90;
	const GEN_FLT x103 = x99 * x102;
	const GEN_FLT x104 = (x61 * (x103 + (-1 * x62 * x100))) + (x64 * x100);
	const GEN_FLT x105 = (x61 * x104) + (x65 * x100);
	const GEN_FLT x106 = 1. / x54;
	const GEN_FLT x107 = x42 * x106;
	const GEN_FLT x108 = 1. / sqrt(1 + (-1 * (x75 * x75) * x107));
	const GEN_FLT x109 = (1. / (x54 * sqrt(x54))) * x96;
	const GEN_FLT x110 = x94 * x109;
	const GEN_FLT x111 = x74 * x37;
	const GEN_FLT x112 = (x75 * x111) + (-1 * x75 * x110);
	const GEN_FLT x113 = 1. / x52;
	const GEN_FLT x114 = (1. / x53) * x48;
	const GEN_FLT x115 = x53 * x106;
	const GEN_FLT x116 = ((x50 * x114) + (-1 * x46 * x113)) * x115;
	const GEN_FLT x117 = cos(x78) * ogeePhase_0;
	const GEN_FLT x118 = x117 * (x116 + (-1 * x108 * x112));
	const GEN_FLT x119 = x83 * x84 * x66;
	const GEN_FLT x120 = 2.40324066e-05 * x61;
	const GEN_FLT x121 = x80 * x72;
	const GEN_FLT x122 = (1. / (x82 * x82)) * x85 * x66;
	const GEN_FLT x123 =
		x88 * (x112 + (x118 * x119) +
			   (-1 * x122 *
				((-1 * x118 * x121) +
				 (-1 * x81 *
				  ((x66 * x100) + (x71 * x100) +
				   (x61 * ((x61 * (x104 + (x69 * x100) + (x61 * ((-1 * x100 * x120) + x103 + (x68 * x100))))) + x105 +
						   (x70 * x100))) +
				   (x61 * x105))))) +
			   (x101 * x100) + (x86 * x105));
	const GEN_FLT x124 = -1 * x116;
	const GEN_FLT x125 = -1 * x73;
	const GEN_FLT x126 = cos(asin(x87) + (-1 * gibPhase_0) + x125) * gibMag_0;
	const GEN_FLT x127 = (x93 * x47) + (x51 * x92);
	const GEN_FLT x128 = x75 * x109;
	const GEN_FLT x129 = (x76 * x40) + (-1 * x128 * x127);
	const GEN_FLT x130 = ((x51 * x114) + (-1 * x47 * x113)) * x115;
	const GEN_FLT x131 = x130 + (-1 * x108 * x129);
	const GEN_FLT x132 = x119 * x117;
	const GEN_FLT x133 = x127 + (x91 * x40);
	const GEN_FLT x134 = (x60 * x40) + (-1 * x98 * x133);
	const GEN_FLT x135 = x90 * x134;
	const GEN_FLT x136 = x102 * x134;
	const GEN_FLT x137 = (x61 * (x136 + (-1 * x62 * x135))) + (x64 * x135);
	const GEN_FLT x138 = (x61 * x137) + (x65 * x135);
	const GEN_FLT x139 = x117 * x121;
	const GEN_FLT x140 =
		x88 * ((x131 * x132) + x129 +
			   (-1 * x122 *
				((-1 * x131 * x139) +
				 (-1 * x81 *
				  ((x66 * x135) + (x71 * x135) +
				   (x61 * (x138 + (x61 * (x137 + (x69 * x135) + (x61 * ((-1 * x120 * x135) + x136 + (x68 * x135))))) +
						   (x70 * x135))) +
				   (x61 * x138))))) +
			   (x86 * x138) + (x101 * x135));
	const GEN_FLT x141 = -1 * x130;
	const GEN_FLT x142 = (x93 * x43) + (x92 * x49);
	const GEN_FLT x143 = x142 + (x91 * x11);
	const GEN_FLT x144 = (x60 * x11) + (-1 * x98 * x143);
	const GEN_FLT x145 = x90 * x144;
	const GEN_FLT x146 = (x76 * x11) + (-1 * x128 * x142);
	const GEN_FLT x147 = ((x49 * x114) + (-1 * x43 * x113)) * x115;
	const GEN_FLT x148 = x147 + (-1 * x108 * x146);
	const GEN_FLT x149 = x102 * x144;
	const GEN_FLT x150 = (x61 * (x149 + (-1 * x62 * x145))) + (x64 * x145);
	const GEN_FLT x151 = (x61 * x150) + (x65 * x145);
	const GEN_FLT x152 =
		x88 * (x146 + (x86 * x151) + (x101 * x145) +
			   (-1 * x122 *
				((-1 * x139 * x148) +
				 (-1 * x81 *
				  ((x66 * x145) + (x61 * x151) + (x71 * x145) +
				   (x61 * (x151 + (x61 * (x150 + (x69 * x145) + (x61 * ((-1 * x120 * x145) + x149 + (x68 * x145))))) +
						   (x70 * x145))))))) +
			   (x132 * x148));
	const GEN_FLT x153 = -1 * x147;
	const GEN_FLT x154 = 2 * (1. / (x15 * x15)) * x19;
	const GEN_FLT x155 = x154 * obj_qi;
	const GEN_FLT x156 = x21 * (1. / (x15 * sqrt(x15)));
	const GEN_FLT x157 = x14 * x156;
	const GEN_FLT x158 = (x157 * obj_qi) + (-1 * x14 * x155);
	const GEN_FLT x159 = x18 * x16;
	const GEN_FLT x160 = x13 * x159;
	const GEN_FLT x161 = x13 * x156;
	const GEN_FLT x162 = obj_qk * obj_qj;
	const GEN_FLT x163 = x156 * obj_qj;
	const GEN_FLT x164 = x163 * obj_qk;
	const GEN_FLT x165 = (x164 * obj_qi) + (-1 * x162 * x155);
	const GEN_FLT x166 = x165 + (-1 * x22);
	const GEN_FLT x167 = x156 * obj_qk * obj_qi;
	const GEN_FLT x168 = x159 * obj_qi;
	const GEN_FLT x169 = x168 * obj_qk;
	const GEN_FLT x170 = x169 + (-1 * x167);
	const GEN_FLT x171 = x154 * obj_qj;
	const GEN_FLT x172 = (x161 * obj_qj) + (-1 * x13 * x171);
	const GEN_FLT x173 = x172 + x28;
	const GEN_FLT x174 =
		((x173 + x170) * sensor_x) + ((x158 + x38) * sensor_y) + ((x166 + (-1 * x160) + x161) * sensor_z);
	const GEN_FLT x175 = x12 * x156;
	const GEN_FLT x176 = (x175 * obj_qi) + (-1 * x12 * x155);
	const GEN_FLT x177 = x165 + x22;
	const GEN_FLT x178 = x20 * obj_qk;
	const GEN_FLT x179 = x154 * obj_qk;
	const GEN_FLT x180 = (x161 * obj_qk) + (-1 * x13 * x179);
	const GEN_FLT x181 = x180 + x178;
	const GEN_FLT x182 = x163 * obj_qi;
	const GEN_FLT x183 = x168 * obj_qj;
	const GEN_FLT x184 = (-1 * x183) + x182;
	const GEN_FLT x185 =
		((x176 + x38) * sensor_z) + ((x184 + x181) * sensor_x) + ((x177 + x160 + (-1 * x161)) * sensor_y);
	const GEN_FLT x186 = obj_qi * obj_qi * obj_qi;
	const GEN_FLT x187 = (-1 * x169) + x167;
	const GEN_FLT x188 = x183 + (-1 * x182);
	const GEN_FLT x189 = ((x188 + x181) * sensor_z) +
						 (((2 * x25) + (x186 * x156) + x38 + (-1 * x186 * x154)) * sensor_x) +
						 ((x173 + x187) * sensor_y);
	const GEN_FLT x190 = (x50 * x189) + (x51 * x174) + (x49 * x185);
	const GEN_FLT x191 = (x46 * x189) + (x47 * x174) + (x43 * x185);
	const GEN_FLT x192 = (x93 * x191) + (x92 * x190);
	const GEN_FLT x193 = (x37 * x189) + (x11 * x185) + (x40 * x174);
	const GEN_FLT x194 = (x76 * x193) + (-1 * x128 * x192);
	const GEN_FLT x195 = ((x114 * x190) + (-1 * x113 * x191)) * x115;
	const GEN_FLT x196 = x195 + (-1 * x108 * x194);
	const GEN_FLT x197 = x192 + (x91 * x193);
	const GEN_FLT x198 = ((x60 * x193) + (-1 * x98 * x197)) * x90;
	const GEN_FLT x199 = x63 * x198;
	const GEN_FLT x200 = (x61 * (x199 + (-1 * x62 * x198))) + (x64 * x198);
	const GEN_FLT x201 = (x61 * x200) + (x65 * x198);
	const GEN_FLT x202 =
		x88 * (x194 +
			   (-1 * x122 *
				((-1 * x196 * x139) +
				 (-1 * x81 *
				  ((x66 * x198) + (x61 * x201) +
				   (x61 * (x201 + (x61 * ((x69 * x198) + x200 + (x61 * ((-1 * x120 * x198) + x199 + (x68 * x198))))) +
						   (x70 * x198))) +
				   (x71 * x198))))) +
			   (x86 * x201) + (x196 * x132) + (x101 * x198));
	const GEN_FLT x203 = -1 * x195;
	const GEN_FLT x204 = obj_qj * obj_qj * obj_qj;
	const GEN_FLT x205 = (x157 * obj_qk) + (-1 * x14 * x179);
	const GEN_FLT x206 = x205 + x178;
	const GEN_FLT x207 = x162 * x159;
	const GEN_FLT x208 = x207 + (-1 * x164);
	const GEN_FLT x209 = x158 + x25;
	const GEN_FLT x210 = ((x209 + x208) * sensor_x) +
						 (((2 * x28) + (x204 * x156) + x24 + (-1 * x204 * x154)) * sensor_y) +
						 ((x206 + x184) * sensor_z);
	const GEN_FLT x211 = (x175 * obj_qj) + (-1 * x12 * x171);
	const GEN_FLT x212 = x14 * x159;
	const GEN_FLT x213 =
		((x166 + (-1 * x212) + x157) * sensor_x) + ((x206 + x188) * sensor_y) + ((x211 + x24) * sensor_z);
	const GEN_FLT x214 = (-1 * x207) + x164;
	const GEN_FLT x215 =
		((x177 + x212 + (-1 * x157)) * sensor_z) + ((x214 + x209) * sensor_y) + ((x172 + x24) * sensor_x);
	const GEN_FLT x216 = (x37 * x215) + (x40 * x210) + (x11 * x213);
	const GEN_FLT x217 = (x50 * x215) + (x51 * x210) + (x49 * x213);
	const GEN_FLT x218 = (x46 * x215) + (x47 * x210) + (x43 * x213);
	const GEN_FLT x219 = (x93 * x218) + (x92 * x217);
	const GEN_FLT x220 = x219 + (x91 * x216);
	const GEN_FLT x221 = ((x60 * x216) + (-1 * x98 * x220)) * x90;
	const GEN_FLT x222 = (x76 * x216) + (-1 * x219 * x128);
	const GEN_FLT x223 = ((x217 * x114) + (-1 * x218 * x113)) * x115;
	const GEN_FLT x224 = x223 + (-1 * x222 * x108);
	const GEN_FLT x225 = x63 * x221;
	const GEN_FLT x226 = (x61 * (x225 + (-1 * x62 * x221))) + (x64 * x221);
	const GEN_FLT x227 = (x61 * x226) + (x65 * x221);
	const GEN_FLT x228 =
		x88 * (x222 + (x86 * x227) +
			   (-1 * x122 *
				((-1 * x224 * x139) +
				 (-1 * x81 *
				  ((x66 * x221) + (x61 * x227) + (x71 * x221) +
				   (x61 * (x227 + (x61 * (x226 + (x69 * x221) + (x61 * (x225 + (-1 * x221 * x120) + (x68 * x221))))) +
						   (x70 * x221))))))) +
			   (x221 * x101) + (x224 * x132));
	const GEN_FLT x229 = -1 * x223;
	const GEN_FLT x230 = x211 + x28;
	const GEN_FLT x231 = x12 * x159;
	const GEN_FLT x232 =
		((x177 + (-1 * x175) + x231) * sensor_x) + ((x205 + x32) * sensor_y) + ((x187 + x230) * sensor_z);
	const GEN_FLT x233 = obj_qk * obj_qk * obj_qk;
	const GEN_FLT x234 = x176 + x25;
	const GEN_FLT x235 = ((x214 + x234) * sensor_x) + ((x170 + x230) * sensor_y) +
						 (((2 * x178) + (-1 * x233 * x154) + x32 + (x233 * x156)) * sensor_z);
	const GEN_FLT x236 =
		((x208 + x234) * sensor_z) + ((x166 + x175 + (-1 * x231)) * sensor_y) + ((x180 + x32) * sensor_x);
	const GEN_FLT x237 = (x50 * x236) + (x51 * x232) + (x49 * x235);
	const GEN_FLT x238 = (x47 * x232) + (x46 * x236) + (x43 * x235);
	const GEN_FLT x239 = (x93 * x238) + (x92 * x237);
	const GEN_FLT x240 = (x37 * x236) + (x40 * x232) + (x11 * x235);
	const GEN_FLT x241 = (x76 * x240) + (-1 * x239 * x128);
	const GEN_FLT x242 = ((x237 * x114) + (-1 * x238 * x113)) * x115;
	const GEN_FLT x243 = x242 + (-1 * x241 * x108);
	const GEN_FLT x244 = x239 + (x91 * x240);
	const GEN_FLT x245 = ((x60 * x240) + (-1 * x98 * x244)) * x90;
	const GEN_FLT x246 = x63 * x245;
	const GEN_FLT x247 = (x61 * (x246 + (-1 * x62 * x245))) + (x64 * x245);
	const GEN_FLT x248 = (x61 * x247) + (x65 * x245);
	const GEN_FLT x249 =
		x88 * (x241 +
			   (-1 * x122 *
				((-1 * x243 * x139) +
				 (-1 * x81 *
				  ((x66 * x245) + (x61 * x248) + (x71 * x245) +
				   (x61 * (x248 + (x61 * (x247 + (x69 * x245) + (x61 * ((x68 * x245) + (-1 * x245 * x120) + x246)))) +
						   (x70 * x245))))))) +
			   (x245 * x101) + (x243 * x132) + (x86 * x248));
	const GEN_FLT x250 = -1 * x242;
	const GEN_FLT x251 = 0.523598775598299 + (-1 * tilt_1);
	const GEN_FLT x252 = cos(x251);
	const GEN_FLT x253 = 1. / x252;
	const GEN_FLT x254 = x56 * x253;
	const GEN_FLT x255 = asin(x41 * x254);
	const GEN_FLT x256 = 8.0108022e-06 * x255;
	const GEN_FLT x257 = -8.0108022e-06 + (-1 * x256);
	const GEN_FLT x258 = 0.0028679863 + (x255 * x257);
	const GEN_FLT x259 = 5.3685255e-06 + (x255 * x258);
	const GEN_FLT x260 = 0.0076069798 + (x255 * x259);
	const GEN_FLT x261 = x260 * x255;
	const GEN_FLT x262 = -8.0108022e-06 + (-1.60216044e-05 * x255);
	const GEN_FLT x263 = x258 + (x262 * x255);
	const GEN_FLT x264 = x259 + (x263 * x255);
	const GEN_FLT x265 = x260 + (x264 * x255);
	const GEN_FLT x266 = (x265 * x255) + x261;
	const GEN_FLT x267 = tan(x251);
	const GEN_FLT x268 = x74 * x267;
	const GEN_FLT x269 = -1 * x41 * x268;
	const GEN_FLT x270 = (-1 * asin(x269)) + ogeeMag_1 + x73;
	const GEN_FLT x271 = (sin(x270) * ogeePhase_1) + curve_1;
	const GEN_FLT x272 = sin(x251);
	const GEN_FLT x273 = x272 * x271;
	const GEN_FLT x274 = x252 + (x273 * x266);
	const GEN_FLT x275 = 1. / x274;
	const GEN_FLT x276 = x255 * x255;
	const GEN_FLT x277 = x276 * x271;
	const GEN_FLT x278 = x277 * x275;
	const GEN_FLT x279 = x269 + (x278 * x260);
	const GEN_FLT x280 = 1. / sqrt(1 + (-1 * (x279 * x279)));
	const GEN_FLT x281 = 1. / sqrt(1 + (-1 * x89 * (1. / (x252 * x252))));
	const GEN_FLT x282 = x97 * x253;
	const GEN_FLT x283 = ((x37 * x254) + (-1 * x95 * x282)) * x281;
	const GEN_FLT x284 = x283 * x257;
	const GEN_FLT x285 = (x283 * x258) + (x255 * (x284 + (-1 * x283 * x256)));
	const GEN_FLT x286 = (x283 * x259) + (x285 * x255);
	const GEN_FLT x287 = 1. / sqrt(1 + (-1 * (x267 * x267) * x107));
	const GEN_FLT x288 = (-1 * x267 * x111) + (x267 * x110);
	const GEN_FLT x289 = cos(x270) * ogeePhase_1;
	const GEN_FLT x290 = x289 * (x116 + (-1 * x287 * x288));
	const GEN_FLT x291 = x272 * x266;
	const GEN_FLT x292 = 2.40324066e-05 * x255;
	const GEN_FLT x293 = x277 * (1. / (x274 * x274)) * x260;
	const GEN_FLT x294 = x276 * x275 * x260;
	const GEN_FLT x295 = 2 * x275 * x271 * x261;
	const GEN_FLT x296 =
		x280 *
		((x295 * x283) + (x294 * x290) + x288 + (x278 * x286) +
		 (-1 * x293 *
		  ((x273 * ((x260 * x283) + (x265 * x283) + (x286 * x255) +
					(x255 * ((x255 * (x285 + (x263 * x283) + (x255 * ((-1 * x292 * x283) + x284 + (x262 * x283))))) +
							 x286 + (x264 * x283))))) +
		   (x291 * x290))));
	const GEN_FLT x297 = cos(asin(x279) + x125 + (-1 * gibPhase_1)) * gibMag_1;
	const GEN_FLT x298 = x267 * x109;
	const GEN_FLT x299 = (-1 * x40 * x268) + (x298 * x127);
	const GEN_FLT x300 = x130 + (-1 * x299 * x287);
	const GEN_FLT x301 = x294 * x289;
	const GEN_FLT x302 = x281 * ((x40 * x254) + (-1 * x282 * x133));
	const GEN_FLT x303 = x257 * x302;
	const GEN_FLT x304 = (x258 * x302) + (x255 * (x303 + (-1 * x256 * x302)));
	const GEN_FLT x305 = (x259 * x302) + (x255 * x304);
	const GEN_FLT x306 = x291 * x289;
	const GEN_FLT x307 =
		x280 *
		(x299 + (x295 * x302) +
		 (-1 * x293 *
		  ((x273 *
			((x260 * x302) + (x255 * x305) + (x265 * x302) +
			 (x255 * (x305 + (x255 * (x304 + (x263 * x302) + (x255 * ((-1 * x292 * x302) + x303 + (x262 * x302))))) +
					  (x264 * x302))))) +
		   (x300 * x306))) +
		 (x301 * x300) + (x278 * x305));
	const GEN_FLT x308 = (x11 * x254) + (-1 * x282 * x143);
	const GEN_FLT x309 = x281 * x308;
	const GEN_FLT x310 = x257 * x309;
	const GEN_FLT x311 = (x258 * x309) + (x255 * (x310 + (-1 * x256 * x309)));
	const GEN_FLT x312 = (x259 * x309) + (x255 * x311);
	const GEN_FLT x313 = (-1 * x11 * x268) + (x298 * x142);
	const GEN_FLT x314 = x147 + (-1 * x287 * x313);
	const GEN_FLT x315 = x265 * x281;
	const GEN_FLT x316 =
		x280 *
		((x295 * x309) + (x301 * x314) + (x278 * x312) + x313 +
		 (-1 * x293 *
		  ((x273 *
			((x260 * x309) + (x308 * x315) + (x255 * x312) +
			 (x255 * (x312 + (x255 * ((x263 * x309) + x311 + (x255 * ((-1 * x292 * x309) + x310 + (x262 * x309))))) +
					  (x264 * x309))))) +
		   (x306 * x314))));
	const GEN_FLT x317 = (x254 * x193) + (-1 * x282 * x197);
	const GEN_FLT x318 = x281 * x317;
	const GEN_FLT x319 = x257 * x318;
	const GEN_FLT x320 = (x258 * x318) + (x255 * (x319 + (-1 * x256 * x318)));
	const GEN_FLT x321 = (x259 * x318) + (x255 * x320);
	const GEN_FLT x322 = (-1 * x268 * x193) + (x298 * x192);
	const GEN_FLT x323 = x195 + (-1 * x287 * x322);
	const GEN_FLT x324 =
		x280 *
		(x322 + (x295 * x318) + (x301 * x323) + (x278 * x321) +
		 (-1 * x293 *
		  ((x273 *
			((x260 * x318) + (x255 * x321) + (x315 * x317) +
			 (x255 * (x321 + (x255 * (x320 + (x263 * x318) + (x255 * ((-1 * x292 * x318) + x319 + (x262 * x318))))) +
					  (x264 * x318))))) +
		   (x306 * x323))));
	const GEN_FLT x325 = (-1 * x216 * x268) + (x219 * x298);
	const GEN_FLT x326 = x223 + (-1 * x287 * x325);
	const GEN_FLT x327 = (x216 * x254) + (-1 * x282 * x220);
	const GEN_FLT x328 = x281 * x327;
	const GEN_FLT x329 = x257 * x328;
	const GEN_FLT x330 = (x258 * x328) + (x255 * (x329 + (-1 * x256 * x328)));
	const GEN_FLT x331 = (x259 * x328) + (x255 * x330);
	const GEN_FLT x332 =
		x280 *
		(x325 +
		 (-1 * x293 *
		  ((x273 * ((x260 * x328) +
					(x255 * ((x255 * (x330 + (x263 * x328) + (x255 * ((-1 * x292 * x328) + x329 + (x262 * x328))))) +
							 x331 + (x264 * x328))) +
					(x327 * x315) + (x255 * x331))) +
		   (x306 * x326))) +
		 (x295 * x328) + (x278 * x331) + (x301 * x326));
	const GEN_FLT x333 = ((x254 * x240) + (-1 * x282 * x244)) * x281;
	const GEN_FLT x334 = x257 * x333;
	const GEN_FLT x335 = (x258 * x333) + (x255 * (x334 + (-1 * x256 * x333)));
	const GEN_FLT x336 = (x259 * x333) + (x255 * x335);
	const GEN_FLT x337 = (-1 * x268 * x240) + (x239 * x298);
	const GEN_FLT x338 = x242 + (-1 * x287 * x337);
	const GEN_FLT x339 =
		x280 *
		((x295 * x333) + x337 +
		 (-1 * x293 *
		  ((x273 *
			((x260 * x333) + (x255 * x336) + (x265 * x333) +
			 (x255 * (x336 + (x255 * (x335 + (x263 * x333) + (x255 * ((-1 * x292 * x333) + (x262 * x333) + x334)))) +
					  (x264 * x333))))) +
		   (x306 * x338))) +
		 (x278 * x336) + (x301 * x338));
	out[0] = x116 + (-1 * x123) + (-1 * (x124 + x123) * x126);
	out[1] = x130 + (-1 * x140) + (-1 * (x141 + x140) * x126);
	out[2] = x147 + (-1 * x152) + (-1 * (x153 + x152) * x126);
	out[3] = x195 + (-1 * x202) + (-1 * (x203 + x202) * x126);
	out[4] = x223 + (-1 * x228) + (-1 * (x229 + x228) * x126);
	out[5] = x242 + (-1 * x249) + (-1 * (x250 + x249) * x126);
	out[6] = (-1 * (x124 + x296) * x297) + (-1 * x296) + x116;
	out[7] = (-1 * x307) + (-1 * (x141 + x307) * x297) + x130;
	out[8] = (-1 * (x153 + x316) * x297) + (-1 * x316) + x147;
	out[9] = (-1 * (x203 + x324) * x297) + x195 + (-1 * x324);
	out[10] = (-1 * (x229 + x332) * x297) + (-1 * x332) + x223;
	out[11] = (-1 * (x250 + x339) * x297) + (-1 * x339) + x242;
}

// Jacobian of reproject_gen2 wrt [sensor_x, sensor_y, sensor_z]
static inline void gen_reproject_gen2_jac_sensor_pt_axis_angle(FLT *out, const LinmathAxisAnglePose *obj_p,
															   const FLT *sensor_pt, const LinmathAxisAnglePose *lh_p,
															   const BaseStationCal *bsd) {
	const GEN_FLT obj_px = (*obj_p).Pos[0];
	const GEN_FLT obj_py = (*obj_p).Pos[1];
	const GEN_FLT obj_pz = (*obj_p).Pos[2];
	const GEN_FLT obj_qi = (*obj_p).AxisAngleRot[0];
	const GEN_FLT obj_qj = (*obj_p).AxisAngleRot[1];
	const GEN_FLT obj_qk = (*obj_p).AxisAngleRot[2];
	const GEN_FLT sensor_x = sensor_pt[0];
	const GEN_FLT sensor_y = sensor_pt[1];
	const GEN_FLT sensor_z = sensor_pt[2];
	const GEN_FLT lh_px = (*lh_p).Pos[0];
	const GEN_FLT lh_py = (*lh_p).Pos[1];
	const GEN_FLT lh_pz = (*lh_p).Pos[2];
	const GEN_FLT lh_qi = (*lh_p).AxisAngleRot[0];
	const GEN_FLT lh_qj = (*lh_p).AxisAngleRot[1];
	const GEN_FLT lh_qk = (*lh_p).AxisAngleRot[2];
	const GEN_FLT phase_0 = bsd[0].phase;
	const GEN_FLT tilt_0 = bsd[0].tilt;
	const GEN_FLT curve_0 = bsd[0].curve;
	const GEN_FLT gibPhase_0 = bsd[0].gibpha;
	const GEN_FLT gibMag_0 = bsd[0].gibmag;
	const GEN_FLT ogeeMag_0 = bsd[0].ogeephase;
	const GEN_FLT ogeePhase_0 = bsd[0].ogeemag;
	const GEN_FLT phase_1 = bsd[1].phase;
	const GEN_FLT tilt_1 = bsd[1].tilt;
	const GEN_FLT curve_1 = bsd[1].curve;
	const GEN_FLT gibPhase_1 = bsd[1].gibpha;
	const GEN_FLT gibMag_1 = bsd[1].gibmag;
	const GEN_FLT ogeeMag_1 = bsd[1].ogeephase;
	const GEN_FLT ogeePhase_1 = bsd[1].ogeemag;
	const GEN_FLT x0 = 0.523598775598299 + tilt_0;
	const GEN_FLT x1 = tan(x0);
	const GEN_FLT x2 = obj_qk * obj_qk;
	const GEN_FLT x3 = obj_qi * obj_qi;
	const GEN_FLT x4 = obj_qj * obj_qj;
	const GEN_FLT x5 = 1e-10 + x4 + x2 + x3;
	const GEN_FLT x6 = sqrt(x5);
	const GEN_FLT x7 = cos(x6);
	const GEN_FLT x8 = (1. / x5) * (1 + (-1 * x7));
	const GEN_FLT x9 = x7 + (x2 * x8);
	const GEN_FLT x10 = (1. / x6) * sin(x6);
	const GEN_FLT x11 = x10 * obj_qj;
	const GEN_FLT x12 = x8 * obj_qi;
	const GEN_FLT x13 = x12 * obj_qk;
	const GEN_FLT x14 = x13 + (-1 * x11);
	const GEN_FLT x15 = x10 * obj_qi;
	const GEN_FLT x16 = x8 * obj_qk * obj_qj;
	const GEN_FLT x17 = x16 + x15;
	const GEN_FLT x18 = (x14 * sensor_x) + obj_pz + (x17 * sensor_y) + (x9 * sensor_z);
	const GEN_FLT x19 = lh_qk * lh_qk;
	const GEN_FLT x20 = lh_qi * lh_qi;
	const GEN_FLT x21 = lh_qj * lh_qj;
	const GEN_FLT x22 = 1e-10 + x21 + x19 + x20;
	const GEN_FLT x23 = sqrt(x22);
	const GEN_FLT x24 = cos(x23);
	const GEN_FLT x25 = (1. / x22) * (1 + (-1 * x24));
	const GEN_FLT x26 = x24 + (x25 * x19);
	const GEN_FLT x27 = x7 + (x3 * x8);
	const GEN_FLT x28 = x13 + x11;
	const GEN_FLT x29 = x10 * obj_qk;
	const GEN_FLT x30 = x12 * obj_qj;
	const GEN_FLT x31 = x30 + (-1 * x29);
	const GEN_FLT x32 = (x31 * sensor_y) + (x27 * sensor_x) + (x28 * sensor_z) + obj_px;
	const GEN_FLT x33 = (1. / x23) * sin(x23);
	const GEN_FLT x34 = x33 * lh_qj;
	const GEN_FLT x35 = x25 * lh_qk;
	const GEN_FLT x36 = x35 * lh_qi;
	const GEN_FLT x37 = x36 + (-1 * x34);
	const GEN_FLT x38 = x16 + (-1 * x15);
	const GEN_FLT x39 = x30 + x29;
	const GEN_FLT x40 = x7 + (x4 * x8);
	const GEN_FLT x41 = (x39 * sensor_x) + obj_py + (x40 * sensor_y) + (x38 * sensor_z);
	const GEN_FLT x42 = x33 * lh_qi;
	const GEN_FLT x43 = x35 * lh_qj;
	const GEN_FLT x44 = x43 + x42;
	const GEN_FLT x45 = (x41 * x44) + (x32 * x37) + lh_pz + (x26 * x18);
	const GEN_FLT x46 = x36 + x34;
	const GEN_FLT x47 = x24 + (x25 * x20);
	const GEN_FLT x48 = x33 * lh_qk;
	const GEN_FLT x49 = x25 * lh_qj * lh_qi;
	const GEN_FLT x50 = x49 + (-1 * x48);
	const GEN_FLT x51 = (x50 * x41) + (x47 * x32) + lh_px + (x46 * x18);
	const GEN_FLT x52 = x51 * x51;
	const GEN_FLT x53 = x52 + (x45 * x45);
	const GEN_FLT x54 = 1. / x53;
	const GEN_FLT x55 = x43 + (-1 * x42);
	const GEN_FLT x56 = x49 + x48;
	const GEN_FLT x57 = x24 + (x25 * x21);
	const GEN_FLT x58 = (x57 * x41) + (x56 * x32) + lh_py + (x55 * x18);
	const GEN_FLT x59 = x58 * x58;
	const GEN_FLT x60 = x54 * x59;
	const GEN_FLT x61 = 1. / sqrt(1 + (-1 * (x1 * x1) * x60));
	const GEN_FLT x62 = (x47 * x27) + (x50 * x39) + (x46 * x14);
	const GEN_FLT x63 = 2 * x51;
	const GEN_FLT x64 = (x37 * x27) + (x44 * x39) + (x26 * x14);
	const GEN_FLT x65 = 2 * x45;
	const GEN_FLT x66 = (x64 * x65) + (x63 * x62);
	const GEN_FLT x67 = 1.0 / 2.0 * x58;
	const GEN_FLT x68 = x67 * (1. / (x53 * sqrt(x53)));
	const GEN_FLT x69 = x68 * x66;
	const GEN_FLT x70 = (x56 * x27) + (x57 * x39) + (x55 * x14);
	const GEN_FLT x71 = 1. / sqrt(x53);
	const GEN_FLT x72 = x71 * x70;
	const GEN_FLT x73 = (x1 * x72) + (-1 * x1 * x69);
	const GEN_FLT x74 = 1. / x51;
	const GEN_FLT x75 = (1. / x52) * x45;
	const GEN_FLT x76 = x54 * x52;
	const GEN_FLT x77 = ((x75 * x62) + (-1 * x74 * x64)) * x76;
	const GEN_FLT x78 = x77 + (-1 * x73 * x61);
	const GEN_FLT x79 = atan2(-1 * x45, x51);
	const GEN_FLT x80 = x71 * x58;
	const GEN_FLT x81 = x1 * x80;
	const GEN_FLT x82 = (-1 * asin(x81)) + x79 + ogeeMag_0;
	const GEN_FLT x83 = cos(x82) * ogeePhase_0;
	const GEN_FLT x84 = x53 + x59;
	const GEN_FLT x85 = 1. / sqrt(x84);
	const GEN_FLT x86 = cos(x0);
	const GEN_FLT x87 = 1. / x86;
	const GEN_FLT x88 = x85 * x87;
	const GEN_FLT x89 = asin(x88 * x58);
	const GEN_FLT x90 = 8.0108022e-06 * x89;
	const GEN_FLT x91 = -8.0108022e-06 + (-1 * x90);
	const GEN_FLT x92 = 0.0028679863 + (x89 * x91);
	const GEN_FLT x93 = 5.3685255e-06 + (x89 * x92);
	const GEN_FLT x94 = 0.0076069798 + (x89 * x93);
	const GEN_FLT x95 = x89 * x89;
	const GEN_FLT x96 = x89 * x94;
	const GEN_FLT x97 = -8.0108022e-06 + (-1.60216044e-05 * x89);
	const GEN_FLT x98 = x92 + (x89 * x97);
	const GEN_FLT x99 = x93 + (x89 * x98);
	const GEN_FLT x100 = x94 + (x89 * x99);
	const GEN_FLT x101 = (x89 * x100) + x96;
	const GEN_FLT x102 = (sin(x82) * ogeePhase_0) + curve_0;
	const GEN_FLT x103 = sin(x0);
	const GEN_FLT x104 = x103 * x102;
	const GEN_FLT x105 = x86 + (-1 * x101 * x104);
	const GEN_FLT x106 = 1. / x105;
	const GEN_FLT x107 = x95 * x94 * x106;
	const GEN_FLT x108 = x83 * x107;
	const GEN_FLT x109 = (1. / x84) * x59;
	const GEN_FLT x110 = 1. / sqrt(1 + (-1 * (1. / (x86 * x86)) * x109));
	const GEN_FLT x111 = 2 * x58;
	const GEN_FLT x112 = x66 + (x70 * x111);
	const GEN_FLT x113 = (1. / (x84 * sqrt(x84))) * x67;
	const GEN_FLT x114 = x87 * x113;
	const GEN_FLT x115 = x110 * ((x88 * x70) + (-1 * x112 * x114));
	const GEN_FLT x116 = x91 * x115;
	const GEN_FLT x117 = (x89 * (x116 + (-1 * x90 * x115))) + (x92 * x115);
	const GEN_FLT x118 = (x89 * x117) + (x93 * x115);
	const GEN_FLT x119 = x95 * x102;
	const GEN_FLT x120 = x106 * x119;
	const GEN_FLT x121 = 2 * x96 * x102 * x106;
	const GEN_FLT x122 = 2.40324066e-05 * x89;
	const GEN_FLT x123 = x101 * x103;
	const GEN_FLT x124 = x83 * x123;
	const GEN_FLT x125 = x94 * (1. / (x105 * x105)) * x119;
	const GEN_FLT x126 = x81 + (x94 * x120);
	const GEN_FLT x127 = 1. / sqrt(1 + (-1 * (x126 * x126)));
	const GEN_FLT x128 =
		x127 * (x73 +
				(-1 * x125 *
				 ((-1 * x78 * x124) +
				  (-1 * x104 *
				   ((x89 * x118) + (x94 * x115) + (x100 * x115) +
					(x89 * (x118 + (x89 * (x117 + (x98 * x115) + (x89 * ((-1 * x115 * x122) + x116 + (x97 * x115))))) +
							(x99 * x115))))))) +
				(x115 * x121) + (x78 * x108) + (x118 * x120));
	const GEN_FLT x129 = -1 * x77;
	const GEN_FLT x130 = -1 * x79;
	const GEN_FLT x131 = cos(asin(x126) + (-1 * gibPhase_0) + x130) * gibMag_0;
	const GEN_FLT x132 = (x47 * x31) + (x50 * x40) + (x46 * x17);
	const GEN_FLT x133 = (x40 * x44) + (x31 * x37) + (x26 * x17);
	const GEN_FLT x134 = (x65 * x133) + (x63 * x132);
	const GEN_FLT x135 = x68 * x134;
	const GEN_FLT x136 = (x55 * x17) + (x56 * x31) + (x57 * x40);
	const GEN_FLT x137 = x71 * x136;
	const GEN_FLT x138 = (x1 * x137) + (-1 * x1 * x135);
	const GEN_FLT x139 = ((x75 * x132) + (-1 * x74 * x133)) * x76;
	const GEN_FLT x140 = x83 * (x139 + (-1 * x61 * x138));
	const GEN_FLT x141 = x134 + (x111 * x136);
	const GEN_FLT x142 = x110 * ((x88 * x136) + (-1 * x114 * x141));
	const GEN_FLT x143 = x91 * x142;
	const GEN_FLT x144 = (x89 * (x143 + (-1 * x90 * x142))) + (x92 * x142);
	const GEN_FLT x145 = (x89 * x144) + (x93 * x142);
	const GEN_FLT x146 =
		x127 * ((-1 * x125 *
				 ((-1 * x123 * x140) +
				  (-1 * x104 *
				   ((x94 * x142) + (x89 * x145) + (x100 * x142) +
					(x89 * (x145 + (x89 * (x144 + (x98 * x142) + (x89 * (x143 + (-1 * x122 * x142) + (x97 * x142))))) +
							(x99 * x142))))))) +
				x138 + (x120 * x145) + (x107 * x140) + (x121 * x142));
	const GEN_FLT x147 = -1 * x139;
	const GEN_FLT x148 = (x56 * x28) + (x57 * x38) + (x9 * x55);
	const GEN_FLT x149 = (x47 * x28) + (x50 * x38) + (x9 * x46);
	const GEN_FLT x150 = (x37 * x28) + (x44 * x38) + (x9 * x26);
	const GEN_FLT x151 = (x65 * x150) + (x63 * x149);
	const GEN_FLT x152 = x151 + (x111 * x148);
	const GEN_FLT x153 = x85 * x148;
	const GEN_FLT x154 = x110 * ((x87 * x153) + (-1 * x114 * x152));
	const GEN_FLT x155 = x91 * x154;
	const GEN_FLT x156 = (x89 * (x155 + (-1 * x90 * x154))) + (x92 * x154);
	const GEN_FLT x157 = (x89 * x156) + (x93 * x154);
	const GEN_FLT x158 = x68 * x151;
	const GEN_FLT x159 = x71 * x148;
	const GEN_FLT x160 = (x1 * x159) + (-1 * x1 * x158);
	const GEN_FLT x161 = ((x75 * x149) + (-1 * x74 * x150)) * x76;
	const GEN_FLT x162 = x161 + (-1 * x61 * x160);
	const GEN_FLT x163 =
		x127 * ((-1 * x125 *
				 ((-1 * x124 * x162) +
				  (-1 * x104 *
				   ((x94 * x154) + (x89 * x157) + (x100 * x154) +
					(x89 * (x157 + (x89 * (x156 + (x98 * x154) + (x89 * (x155 + (-1 * x122 * x154) + (x97 * x154))))) +
							(x99 * x154))))))) +
				x160 + (x108 * x162) + (x121 * x154) + (x120 * x157));
	const GEN_FLT x164 = -1 * x161;
	const GEN_FLT x165 = 0.523598775598299 + (-1 * tilt_1);
	const GEN_FLT x166 = cos(x165);
	const GEN_FLT x167 = 1. / x166;
	const GEN_FLT x168 = x85 * x167;
	const GEN_FLT x169 = asin(x58 * x168);
	const GEN_FLT x170 = 8.0108022e-06 * x169;
	const GEN_FLT x171 = 1. / sqrt(1 + (-1 * x109 * (1. / (x166 * x166))));
	const GEN_FLT x172 = x113 * x167;
	const GEN_FLT x173 = (x70 * x168) + (-1 * x112 * x172);
	const GEN_FLT x174 = x171 * x173;
	const GEN_FLT x175 = -8.0108022e-06 + (-1 * x170);
	const GEN_FLT x176 = x174 * x175;
	const GEN_FLT x177 = 0.0028679863 + (x169 * x175);
	const GEN_FLT x178 = (x177 * x174) + (x169 * (x176 + (-1 * x170 * x174)));
	const GEN_FLT x179 = 5.3685255e-06 + (x169 * x177);
	const GEN_FLT x180 = (x179 * x174) + (x169 * x178);
	const GEN_FLT x181 = 0.0076069798 + (x169 * x179);
	const GEN_FLT x182 = x169 * x181;
	const GEN_FLT x183 = -8.0108022e-06 + (-1.60216044e-05 * x169);
	const GEN_FLT x184 = x177 + (x169 * x183);
	const GEN_FLT x185 = x179 + (x169 * x184);
	const GEN_FLT x186 = x181 + (x169 * x185);
	const GEN_FLT x187 = (x169 * x186) + x182;
	const GEN_FLT x188 = tan(x165);
	const GEN_FLT x189 = -1 * x80 * x188;
	const GEN_FLT x190 = (-1 * asin(x189)) + ogeeMag_1 + x79;
	const GEN_FLT x191 = (sin(x190) * ogeePhase_1) + curve_1;
	const GEN_FLT x192 = sin(x165);
	const GEN_FLT x193 = x191 * x192;
	const GEN_FLT x194 = x166 + (x187 * x193);
	const GEN_FLT x195 = 1. / x194;
	const GEN_FLT x196 = x169 * x169;
	const GEN_FLT x197 = x191 * x196;
	const GEN_FLT x198 = x197 * x195;
	const GEN_FLT x199 = 1. / sqrt(1 + (-1 * x60 * (x188 * x188)));
	const GEN_FLT x200 = (-1 * x72 * x188) + (x69 * x188);
	const GEN_FLT x201 = cos(x190) * ogeePhase_1;
	const GEN_FLT x202 = x201 * (x77 + (-1 * x200 * x199));
	const GEN_FLT x203 = x187 * x192;
	const GEN_FLT x204 = 2.40324066e-05 * x169;
	const GEN_FLT x205 = x171 * x185;
	const GEN_FLT x206 = x181 * x197 * (1. / (x194 * x194));
	const GEN_FLT x207 = 2 * x182 * x191 * x195;
	const GEN_FLT x208 = x181 * x196 * x195;
	const GEN_FLT x209 = x189 + (x181 * x198);
	const GEN_FLT x210 = 1. / sqrt(1 + (-1 * (x209 * x209)));
	const GEN_FLT x211 =
		x210 *
		(x200 + (x202 * x208) + (x207 * x174) + (x180 * x198) +
		 (-1 * x206 *
		  ((x193 *
			((x174 * x181) +
			 (x169 * (x180 + (x169 * (x178 + (x174 * x184) + (x169 * ((-1 * x204 * x174) + x176 + (x174 * x183))))) +
					  (x205 * x173))) +
			 (x169 * x180) + (x174 * x186))) +
		   (x202 * x203))));
	const GEN_FLT x212 = cos(asin(x209) + x130 + (-1 * gibPhase_1)) * gibMag_1;
	const GEN_FLT x213 = (x168 * x136) + (-1 * x172 * x141);
	const GEN_FLT x214 = x213 * x171;
	const GEN_FLT x215 = x214 * x175;
	const GEN_FLT x216 = (x214 * x177) + (x169 * (x215 + (-1 * x214 * x170)));
	const GEN_FLT x217 = (x214 * x179) + (x216 * x169);
	const GEN_FLT x218 = (-1 * x188 * x137) + (x188 * x135);
	const GEN_FLT x219 = x139 + (-1 * x218 * x199);
	const GEN_FLT x220 = x201 * x203;
	const GEN_FLT x221 = x201 * x208;
	const GEN_FLT x222 =
		x210 *
		((x214 * x207) + (x217 * x198) + x218 + (x219 * x221) +
		 (-1 * x206 *
		  ((x193 *
			((x214 * x181) + (x217 * x169) + (x214 * x186) +
			 (x169 * (x217 + (x169 * (x216 + (x214 * x184) + (x169 * ((-1 * x214 * x204) + x215 + (x214 * x183))))) +
					  (x213 * x205))))) +
		   (x219 * x220))));
	const GEN_FLT x223 = (-1 * x188 * x159) + (x188 * x158);
	const GEN_FLT x224 = x161 + (-1 * x223 * x199);
	const GEN_FLT x225 = (x167 * x153) + (-1 * x172 * x152);
	const GEN_FLT x226 = x225 * x171;
	const GEN_FLT x227 = x226 * x175;
	const GEN_FLT x228 = (x226 * x177) + (x169 * (x227 + (-1 * x226 * x170)));
	const GEN_FLT x229 = (x226 * x179) + (x228 * x169);
	const GEN_FLT x230 =
		x210 *
		(x223 + (x207 * x226) +
		 (-1 * x206 *
		  ((x193 *
			((x226 * x181) + (x229 * x169) + (x226 * x186) +
			 (x169 * (x229 + (x169 * (x228 + (x226 * x184) + (x169 * ((-1 * x204 * x226) + (x226 * x183) + x227)))) +
					  (x205 * x225))))) +
		   (x220 * x224))) +
		 (x229 * x198) + (x224 * x221));
	out[0] = x77 + (-1 * x128) + (-1 * (x129 + x128) * x131);
	out[1] = x139 + (-1 * x146) + (-1 * (x147 + x146) * x131);
	out[2] = x161 + (-1 * x163) + (-1 * (x164 + x163) * x131);
	out[3] = (-1 * (x129 + x211) * x212) + (-1 * x211) + x77;
	out[4] = (-1 * (x147 + x222) * x212) + x139 + (-1 * x222);
	out[5] = (-1 * (x164 + x230) * x212) + (-1 * x230) + x161;
}

// Jacobian of reproject_gen2 wrt [lh_px, lh_py, lh_pz, lh_qi, lh_qj, lh_qk]
static inline void gen_reproject_gen2_jac_lh_p_axis_angle(FLT *out, const LinmathAxisAnglePose *obj_p,
														  const FLT *sensor_pt, const LinmathAxisAnglePose *lh_p,
														  const BaseStationCal *bsd) {
	const GEN_FLT obj_px = (*obj_p).Pos[0];
	const GEN_FLT obj_py = (*obj_p).Pos[1];
	const GEN_FLT obj_pz = (*obj_p).Pos[2];
	const GEN_FLT obj_qi = (*obj_p).AxisAngleRot[0];
	const GEN_FLT obj_qj = (*obj_p).AxisAngleRot[1];
	const GEN_FLT obj_qk = (*obj_p).AxisAngleRot[2];
	const GEN_FLT sensor_x = sensor_pt[0];
	const GEN_FLT sensor_y = sensor_pt[1];
	const GEN_FLT sensor_z = sensor_pt[2];
	const GEN_FLT lh_px = (*lh_p).Pos[0];
	const GEN_FLT lh_py = (*lh_p).Pos[1];
	const GEN_FLT lh_pz = (*lh_p).Pos[2];
	const GEN_FLT lh_qi = (*lh_p).AxisAngleRot[0];
	const GEN_FLT lh_qj = (*lh_p).AxisAngleRot[1];
	const GEN_FLT lh_qk = (*lh_p).AxisAngleRot[2];
	const GEN_FLT phase_0 = bsd[0].phase;
	const GEN_FLT tilt_0 = bsd[0].tilt;
	const GEN_FLT curve_0 = bsd[0].curve;
	const GEN_FLT gibPhase_0 = bsd[0].gibpha;
	const GEN_FLT gibMag_0 = bsd[0].gibmag;
	const GEN_FLT ogeeMag_0 = bsd[0].ogeephase;
	const GEN_FLT ogeePhase_0 = bsd[0].ogeemag;
	const GEN_FLT phase_1 = bsd[1].phase;
	const GEN_FLT tilt_1 = bsd[1].tilt;
	const GEN_FLT curve_1 = bsd[1].curve;
	const GEN_FLT gibPhase_1 = bsd[1].gibpha;
	const GEN_FLT gibMag_1 = bsd[1].gibmag;
	const GEN_FLT ogeeMag_1 = bsd[1].ogeephase;
	const GEN_FLT ogeePhase_1 = bsd[1].ogeemag;
	const GEN_FLT x0 = 0.523598775598299 + tilt_0;
	const GEN_FLT x1 = tan(x0);
	const GEN_FLT x2 = lh_qk * lh_qk;
	const GEN_FLT x3 = lh_qi * lh_qi;
	const GEN_FLT x4 = lh_qj * lh_qj;
	const GEN_FLT x5 = 1e-10 + x4 + x2 + x3;
	const GEN_FLT x6 = sqrt(x5);
	const GEN_FLT x7 = sin(x6);
	const GEN_FLT x8 = (1. / x6) * x7;
	const GEN_FLT x9 = x8 * lh_qj;
	const GEN_FLT x10 = cos(x6);
	const GEN_FLT x11 = 1 + (-1 * x10);
	const GEN_FLT x12 = 1. / x5;
	const GEN_FLT x13 = x12 * x11;
	const GEN_FLT x14 = x13 * lh_qi;
	const GEN_FLT x15 = x14 * lh_qk;
	const GEN_FLT x16 = obj_qk * obj_qk;
	const GEN_FLT x17 = obj_qi * obj_qi;
	const GEN_FLT x18 = obj_qj * obj_qj;
	const GEN_FLT x19 = 1e-10 + x18 + x16 + x17;
	const GEN_FLT x20 = sqrt(x19);
	const GEN_FLT x21 = cos(x20);
	const GEN_FLT x22 = (1. / x19) * (1 + (-1 * x21));
	const GEN_FLT x23 = (1. / x20) * sin(x20);
	const GEN_FLT x24 = x23 * obj_qj;
	const GEN_FLT x25 = x22 * obj_qk;
	const GEN_FLT x26 = x25 * obj_qi;
	const GEN_FLT x27 = x23 * obj_qi;
	const GEN_FLT x28 = x25 * obj_qj;
	const GEN_FLT x29 =
		((x28 + x27) * sensor_y) + ((x26 + (-1 * x24)) * sensor_x) + obj_pz + ((x21 + (x22 * x16)) * sensor_z);
	const GEN_FLT x30 = x23 * obj_qk;
	const GEN_FLT x31 = x22 * obj_qj * obj_qi;
	const GEN_FLT x32 =
		((x31 + (-1 * x30)) * sensor_y) + ((x26 + x24) * sensor_z) + ((x21 + (x22 * x17)) * sensor_x) + obj_px;
	const GEN_FLT x33 =
		((x31 + x30) * sensor_x) + obj_py + ((x21 + (x22 * x18)) * sensor_y) + ((x28 + (-1 * x27)) * sensor_z);
	const GEN_FLT x34 = x8 * lh_qk;
	const GEN_FLT x35 = -1 * x34;
	const GEN_FLT x36 = x13 * lh_qj;
	const GEN_FLT x37 = x36 * lh_qi;
	const GEN_FLT x38 = ((x37 + x35) * x33) + (x32 * (x10 + (x3 * x13))) + lh_px + (x29 * (x15 + x9));
	const GEN_FLT x39 = x8 * lh_qi;
	const GEN_FLT x40 = -1 * x39;
	const GEN_FLT x41 = x36 * lh_qk;
	const GEN_FLT x42 = ((x37 + x34) * x32) + lh_py + (x33 * (x10 + (x4 * x13))) + ((x41 + x40) * x29);
	const GEN_FLT x43 = -1 * x9;
	const GEN_FLT x44 = ((x41 + x39) * x33) + ((x15 + x43) * x32) + lh_pz + (x29 * (x10 + (x2 * x13)));
	const GEN_FLT x45 = x38 * x38;
	const GEN_FLT x46 = x45 + (x44 * x44);
	const GEN_FLT x47 = x42 * (1. / (x46 * sqrt(x46)));
	const GEN_FLT x48 = x47 * x38;
	const GEN_FLT x49 = x1 * x48;
	const GEN_FLT x50 = cos(x0);
	const GEN_FLT x51 = 1. / x50;
	const GEN_FLT x52 = x42 * x42;
	const GEN_FLT x53 = x46 + x52;
	const GEN_FLT x54 = 1. / sqrt(x53);
	const GEN_FLT x55 = x54 * x51;
	const GEN_FLT x56 = asin(x55 * x42);
	const GEN_FLT x57 = -8.0108022e-06 + (-1.60216044e-05 * x56);
	const GEN_FLT x58 = 8.0108022e-06 * x56;
	const GEN_FLT x59 = -8.0108022e-06 + (-1 * x58);
	const GEN_FLT x60 = 0.0028679863 + (x56 * x59);
	const GEN_FLT x61 = x60 + (x57 * x56);
	const GEN_FLT x62 = 5.3685255e-06 + (x60 * x56);
	const GEN_FLT x63 = x62 + (x61 * x56);
	const GEN_FLT x64 = 0.0076069798 + (x62 * x56);
	const GEN_FLT x65 = x64 + (x63 * x56);
	const GEN_FLT x66 = 1. / (x53 * sqrt(x53));
	const GEN_FLT x67 = x66 * x42;
	const GEN_FLT x68 = x67 * x38;
	const GEN_FLT x69 = (1. / x53) * x52;
	const GEN_FLT x70 = 1. / sqrt(1 + (-1 * x69 * (1. / (x50 * x50))));
	const GEN_FLT x71 = x70 * x51;
	const GEN_FLT x72 = x71 * x68;
	const GEN_FLT x73 = -1 * x72 * x59;
	const GEN_FLT x74 = 2.40324066e-05 * x56;
	const GEN_FLT x75 = x71 * x60;
	const GEN_FLT x76 = (x56 * (x73 + (x72 * x58))) + (-1 * x75 * x68);
	const GEN_FLT x77 = (x76 * x56) + (-1 * x72 * x62);
	const GEN_FLT x78 = atan2(-1 * x44, x38);
	const GEN_FLT x79 = 1. / sqrt(x46);
	const GEN_FLT x80 = x1 * x79;
	const GEN_FLT x81 = x80 * x42;
	const GEN_FLT x82 = (-1 * asin(x81)) + x78 + ogeeMag_0;
	const GEN_FLT x83 = (sin(x82) * ogeePhase_0) + curve_0;
	const GEN_FLT x84 = sin(x0);
	const GEN_FLT x85 = x83 * x84;
	const GEN_FLT x86 = 1. / x46;
	const GEN_FLT x87 = x86 * x52;
	const GEN_FLT x88 = 1. / sqrt(1 + (-1 * (x1 * x1) * x87));
	const GEN_FLT x89 = x86 * x44;
	const GEN_FLT x90 = x89 + (x88 * x49);
	const GEN_FLT x91 = cos(x82) * ogeePhase_0;
	const GEN_FLT x92 = x64 * x56;
	const GEN_FLT x93 = (x65 * x56) + x92;
	const GEN_FLT x94 = x84 * x93;
	const GEN_FLT x95 = x91 * x94;
	const GEN_FLT x96 = x50 + (-1 * x85 * x93);
	const GEN_FLT x97 = x56 * x56;
	const GEN_FLT x98 = x83 * x97;
	const GEN_FLT x99 = x64 * x98 * (1. / (x96 * x96));
	const GEN_FLT x100 = 2 * x38;
	const GEN_FLT x101 = x67 * x100;
	const GEN_FLT x102 = 1. / x96;
	const GEN_FLT x103 = x83 * x92 * x102;
	const GEN_FLT x104 = x71 * x103;
	const GEN_FLT x105 = x98 * x102;
	const GEN_FLT x106 = x64 * x97 * x102;
	const GEN_FLT x107 = x91 * x106;
	const GEN_FLT x108 = x81 + (x64 * x105);
	const GEN_FLT x109 = 1. / sqrt(1 + (-1 * (x108 * x108)));
	const GEN_FLT x110 =
		x109 * ((x90 * x107) + (x77 * x105) + (-1 * x49) + (-1 * x101 * x104) +
				(-1 * x99 *
				 ((-1 * x90 * x95) +
				  (-1 * x85 *
				   ((-1 * x72 * x64) + (x77 * x56) + (-1 * x72 * x65) +
					(x56 * (x77 + (x56 * (x76 + (-1 * x72 * x61) + (x56 * ((x72 * x74) + x73 + (-1 * x72 * x57))))) +
							(-1 * x72 * x63))))))));
	const GEN_FLT x111 = -1 * x89;
	const GEN_FLT x112 = -1 * x78;
	const GEN_FLT x113 = cos(asin(x108) + (-1 * gibPhase_0) + x112) * gibMag_0;
	const GEN_FLT x114 = x66 * x52;
	const GEN_FLT x115 = x70 * (x55 + (-1 * x51 * x114));
	const GEN_FLT x116 = x59 * x115;
	const GEN_FLT x117 = (x56 * (x116 + (-1 * x58 * x115))) + (x60 * x115);
	const GEN_FLT x118 = (x56 * x117) + (x62 * x115);
	const GEN_FLT x119 = x80 * x88;
	const GEN_FLT x120 = 2 * x103;
	const GEN_FLT x121 =
		x109 * ((x115 * x120) + (x105 * x118) + (-1 * x107 * x119) + x80 +
				(-1 * x99 *
				 ((x95 * x119) +
				  (-1 * x85 *
				   ((x64 * x115) + (x56 * x118) + (x65 * x115) +
					(x56 * (x118 + (x56 * ((x61 * x115) + x117 + (x56 * ((-1 * x74 * x115) + x116 + (x57 * x115))))) +
							(x63 * x115))))))));
	const GEN_FLT x122 = x44 * x47;
	const GEN_FLT x123 = x1 * x122;
	const GEN_FLT x124 = x67 * x44;
	const GEN_FLT x125 = x71 * x124;
	const GEN_FLT x126 = -1 * x59 * x125;
	const GEN_FLT x127 = (x56 * (x126 + (x58 * x125))) + (-1 * x75 * x124);
	const GEN_FLT x128 = (x56 * x127) + (-1 * x62 * x125);
	const GEN_FLT x129 = x86 * x38;
	const GEN_FLT x130 = -1 * x129;
	const GEN_FLT x131 = x130 + (x88 * x123);
	const GEN_FLT x132 = 2 * x42;
	const GEN_FLT x133 = x66 * x44 * x132;
	const GEN_FLT x134 =
		x109 *
		((x105 * x128) + (-1 * x104 * x133) + (-1 * x123) + (x107 * x131) +
		 (-1 * x99 *
		  ((-1 * x95 * x131) +
		   (-1 * x85 *
			((x56 * (x128 + (x56 * (x127 + (-1 * x61 * x125) + (x56 * ((x74 * x125) + x126 + (-1 * x57 * x125))))) +
					 (-1 * x63 * x125))) +
			 (-1 * x65 * x125) + (-1 * x64 * x125) + (x56 * x128))))));
	const GEN_FLT x135 = 2 * (1. / (x5 * x5)) * x11;
	const GEN_FLT x136 = x135 * lh_qi;
	const GEN_FLT x137 = (1. / (x5 * sqrt(x5))) * x7;
	const GEN_FLT x138 = x4 * x137;
	const GEN_FLT x139 = (x138 * lh_qi) + (-1 * x4 * x136);
	const GEN_FLT x140 = x12 * x10;
	const GEN_FLT x141 = x3 * x140;
	const GEN_FLT x142 = x3 * x137;
	const GEN_FLT x143 = lh_qk * lh_qi;
	const GEN_FLT x144 = x137 * x143;
	const GEN_FLT x145 = x135 * lh_qj;
	const GEN_FLT x146 = (-1 * x143 * x145) + (x144 * lh_qj);
	const GEN_FLT x147 = x146 + (-1 * x8);
	const GEN_FLT x148 = (x142 * lh_qj) + (-1 * x3 * x145);
	const GEN_FLT x149 = x148 + x36;
	const GEN_FLT x150 = x140 * x143;
	const GEN_FLT x151 = (-1 * x144) + x150;
	const GEN_FLT x152 = (x33 * (x139 + x40)) + ((x151 + x149) * x32) + (x29 * (x147 + (-1 * x141) + x142));
	const GEN_FLT x153 = x144 + (-1 * x150);
	const GEN_FLT x154 = x13 * lh_qk;
	const GEN_FLT x155 = x135 * lh_qk;
	const GEN_FLT x156 = (x142 * lh_qk) + (-1 * x3 * x155);
	const GEN_FLT x157 = x156 + x154;
	const GEN_FLT x158 = x140 * lh_qj;
	const GEN_FLT x159 = x158 * lh_qi;
	const GEN_FLT x160 = x137 * lh_qj;
	const GEN_FLT x161 = x160 * lh_qi;
	const GEN_FLT x162 = (-1 * x161) + x159;
	const GEN_FLT x163 = lh_qi * lh_qi * lh_qi;
	const GEN_FLT x164 =
		(((-1 * x163 * x135) + x40 + (2 * x14) + (x163 * x137)) * x32) + ((x153 + x149) * x33) + ((x162 + x157) * x29);
	const GEN_FLT x165 = x146 + x8;
	const GEN_FLT x166 = x2 * x137;
	const GEN_FLT x167 = (x166 * lh_qi) + (-1 * x2 * x136);
	const GEN_FLT x168 = x161 + (-1 * x159);
	const GEN_FLT x169 = (x33 * (x165 + x141 + (-1 * x142))) + ((x168 + x157) * x32) + (x29 * (x167 + x40));
	const GEN_FLT x170 = 2 * x44;
	const GEN_FLT x171 = (x169 * x170) + (x100 * x164);
	const GEN_FLT x172 = 1.0 / 2.0 * x67;
	const GEN_FLT x173 = x172 * (x171 + (x132 * x152));
	const GEN_FLT x174 = ((x55 * x152) + (-1 * x51 * x173)) * x70;
	const GEN_FLT x175 = x59 * x174;
	const GEN_FLT x176 = (x56 * (x175 + (-1 * x58 * x174))) + (x60 * x174);
	const GEN_FLT x177 = (x56 * x176) + (x62 * x174);
	const GEN_FLT x178 = 1.0 / 2.0 * x47;
	const GEN_FLT x179 = x171 * x178;
	const GEN_FLT x180 = (x80 * x152) + (-1 * x1 * x179);
	const GEN_FLT x181 = 1. / x38;
	const GEN_FLT x182 = x44 * (1. / x45);
	const GEN_FLT x183 = x86 * x45;
	const GEN_FLT x184 = ((x164 * x182) + (-1 * x169 * x181)) * x183;
	const GEN_FLT x185 = x91 * (x184 + (-1 * x88 * x180));
	const GEN_FLT x186 =
		x109 * (x180 +
				(-1 * x99 *
				 ((-1 * x94 * x185) +
				  (-1 * x85 *
				   ((x64 * x174) + (x56 * x177) +
					(x56 * ((x56 * (x176 + (x61 * x174) + (x56 * ((-1 * x74 * x174) + x175 + (x57 * x174))))) + x177 +
							(x63 * x174))) +
					(x65 * x174))))) +
				(x105 * x177) + (x106 * x185) + (x120 * x174));
	const GEN_FLT x187 = -1 * x184;
	const GEN_FLT x188 = lh_qj * lh_qj * lh_qj;
	const GEN_FLT x189 = (x138 * lh_qk) + (-1 * x4 * x155);
	const GEN_FLT x190 = x189 + x154;
	const GEN_FLT x191 = x139 + x14;
	const GEN_FLT x192 = x158 * lh_qk;
	const GEN_FLT x193 = x160 * lh_qk;
	const GEN_FLT x194 = (-1 * x193) + x192;
	const GEN_FLT x195 =
		((x194 + x191) * x32) + (((-1 * x188 * x135) + (x188 * x137) + x43 + (2 * x36)) * x33) + ((x190 + x168) * x29);
	const GEN_FLT x196 = x193 + (-1 * x192);
	const GEN_FLT x197 = x4 * x140;
	const GEN_FLT x198 = (x32 * (x148 + x43)) + ((x196 + x191) * x33) + (x29 * (x165 + x197 + (-1 * x138)));
	const GEN_FLT x199 = (x166 * lh_qj) + (-1 * x2 * x145);
	const GEN_FLT x200 = (x32 * (x147 + (-1 * x197) + x138)) + ((x190 + x162) * x33) + (x29 * (x199 + x43));
	const GEN_FLT x201 = (x200 * x170) + (x100 * x198);
	const GEN_FLT x202 = x172 * (x201 + (x195 * x132));
	const GEN_FLT x203 = ((x55 * x195) + (-1 * x51 * x202)) * x70;
	const GEN_FLT x204 = x59 * x203;
	const GEN_FLT x205 = (x56 * (x204 + (-1 * x58 * x203))) + (x60 * x203);
	const GEN_FLT x206 = (x56 * x205) + (x62 * x203);
	const GEN_FLT x207 = x201 * x178;
	const GEN_FLT x208 = (x80 * x195) + (-1 * x1 * x207);
	const GEN_FLT x209 = ((x182 * x198) + (-1 * x200 * x181)) * x183;
	const GEN_FLT x210 = x209 + (-1 * x88 * x208);
	const GEN_FLT x211 =
		x109 * (x208 +
				(-1 * x99 *
				 ((-1 * x95 * x210) +
				  (-1 * x85 *
				   ((x56 * x206) + (x65 * x203) + (x64 * x203) +
					(x56 * (x206 + (x56 * (x205 + (x61 * x203) + (x56 * ((x57 * x203) + (-1 * x74 * x203) + x204)))) +
							(x63 * x203))))))) +
				(x203 * x120) + (x206 * x105) + (x210 * x107));
	const GEN_FLT x212 = -1 * x209;
	const GEN_FLT x213 = x199 + x36;
	const GEN_FLT x214 = x2 * x140;
	const GEN_FLT x215 = (x32 * (x165 + (-1 * x166) + x214)) + ((x213 + x153) * x29) + (x33 * (x189 + x35));
	const GEN_FLT x216 = x167 + x14;
	const GEN_FLT x217 = (x32 * (x156 + x35)) + (x33 * (x147 + x166 + (-1 * x214))) + ((x216 + x194) * x29);
	const GEN_FLT x218 = lh_qk * lh_qk * lh_qk;
	const GEN_FLT x219 =
		((x216 + x196) * x32) + ((x213 + x151) * x33) + (x29 * (x35 + (2 * x154) + (x218 * x137) + (-1 * x218 * x135)));
	const GEN_FLT x220 = (x219 * x170) + (x217 * x100);
	const GEN_FLT x221 = x172 * (x220 + (x215 * x132));
	const GEN_FLT x222 = ((x55 * x215) + (-1 * x51 * x221)) * x70;
	const GEN_FLT x223 = x220 * x178;
	const GEN_FLT x224 = (x80 * x215) + (-1 * x1 * x223);
	const GEN_FLT x225 = ((x217 * x182) + (-1 * x219 * x181)) * x183;
	const GEN_FLT x226 = x225 + (-1 * x88 * x224);
	const GEN_FLT x227 = x59 * x222;
	const GEN_FLT x228 = (x56 * (x227 + (-1 * x58 * x222))) + (x60 * x222);
	const GEN_FLT x229 = (x56 * x228) + (x62 * x222);
	const GEN_FLT x230 =
		x109 * (x224 +
				(-1 * x99 *
				 ((-1 * x95 * x226) +
				  (-1 * x85 *
				   ((x64 * x222) + (x56 * x229) + (x65 * x222) +
					(x56 * (x229 + (x56 * (x228 + (x61 * x222) + (x56 * ((-1 * x74 * x222) + x227 + (x57 * x222))))) +
							(x63 * x222))))))) +
				(x229 * x105) + (x222 * x120) + (x226 * x107));
	const GEN_FLT x231 = -1 * x225;
	const GEN_FLT x232 = 0.523598775598299 + (-1 * tilt_1);
	const GEN_FLT x233 = cos(x232);
	const GEN_FLT x234 = 1. / x233;
	const GEN_FLT x235 = x54 * x234;
	const GEN_FLT x236 = asin(x42 * x235);
	const GEN_FLT x237 = 8.0108022e-06 * x236;
	const GEN_FLT x238 = -8.0108022e-06 + (-1 * x237);
	const GEN_FLT x239 = 0.0028679863 + (x238 * x236);
	const GEN_FLT x240 = 5.3685255e-06 + (x236 * x239);
	const GEN_FLT x241 = 0.0076069798 + (x236 * x240);
	const GEN_FLT x242 = x236 * x241;
	const GEN_FLT x243 = -8.0108022e-06 + (-1.60216044e-05 * x236);
	const GEN_FLT x244 = x239 + (x236 * x243);
	const GEN_FLT x245 = x240 + (x236 * x244);
	const GEN_FLT x246 = x241 + (x236 * x245);
	const GEN_FLT x247 = (x236 * x246) + x242;
	const GEN_FLT x248 = tan(x232);
	const GEN_FLT x249 = x79 * x248;
	const GEN_FLT x250 = -1 * x42 * x249;
	const GEN_FLT x251 = (-1 * asin(x250)) + ogeeMag_1 + x78;
	const GEN_FLT x252 = (sin(x251) * ogeePhase_1) + curve_1;
	const GEN_FLT x253 = sin(x232);
	const GEN_FLT x254 = x252 * x253;
	const GEN_FLT x255 = x233 + (x254 * x247);
	const GEN_FLT x256 = 1. / x255;
	const GEN_FLT x257 = x236 * x236;
	const GEN_FLT x258 = x252 * x257;
	const GEN_FLT x259 = x256 * x258;
	const GEN_FLT x260 = x250 + (x259 * x241);
	const GEN_FLT x261 = 1. / sqrt(1 + (-1 * (x260 * x260)));
	const GEN_FLT x262 = x48 * x248;
	const GEN_FLT x263 = 1. / sqrt(1 + (-1 * x69 * (1. / (x233 * x233))));
	const GEN_FLT x264 = x234 * x263;
	const GEN_FLT x265 = x252 * x256 * x242;
	const GEN_FLT x266 = x264 * x265;
	const GEN_FLT x267 = 1. / sqrt(1 + (-1 * x87 * (x248 * x248)));
	const GEN_FLT x268 = x89 + (-1 * x267 * x262);
	const GEN_FLT x269 = cos(x251) * ogeePhase_1;
	const GEN_FLT x270 = x253 * x247;
	const GEN_FLT x271 = x270 * x269;
	const GEN_FLT x272 = x263 * x246;
	const GEN_FLT x273 = x68 * x234;
	const GEN_FLT x274 = x263 * x244;
	const GEN_FLT x275 = x68 * x264;
	const GEN_FLT x276 = -1 * x238 * x275;
	const GEN_FLT x277 = 2.40324066e-05 * x236;
	const GEN_FLT x278 = (-1 * x239 * x275) + (x236 * (x276 + (x237 * x275)));
	const GEN_FLT x279 = (-1 * x275 * x240) + (x236 * x278);
	const GEN_FLT x280 = (1. / (x255 * x255)) * x258 * x241;
	const GEN_FLT x281 = x256 * x257 * x241;
	const GEN_FLT x282 = x269 * x281;
	const GEN_FLT x283 =
		x261 *
		((x268 * x282) + (x279 * x259) + x262 +
		 (-1 * x280 *
		  ((x254 *
			((-1 * x275 * x241) + (-1 * x273 * x272) + (x236 * x279) +
			 (x236 * ((x236 * (x278 + (-1 * x274 * x273) + (x236 * ((x277 * x275) + x276 + (-1 * x275 * x243))))) +
					  x279 + (-1 * x275 * x245))))) +
		   (x271 * x268))) +
		 (-1 * x266 * x101));
	const GEN_FLT x284 = cos(asin(x260) + x112 + (-1 * gibPhase_1)) * gibMag_1;
	const GEN_FLT x285 = x235 + (-1 * x234 * x114);
	const GEN_FLT x286 = x263 * x285;
	const GEN_FLT x287 = 2 * x265;
	const GEN_FLT x288 = x267 * x249;
	const GEN_FLT x289 = x238 * x286;
	const GEN_FLT x290 = (x239 * x286) + (x236 * (x289 + (-1 * x237 * x286)));
	const GEN_FLT x291 = (x286 * x240) + (x236 * x290);
	const GEN_FLT x292 =
		x261 *
		((x291 * x259) + (x288 * x282) + (x286 * x287) + (-1 * x249) +
		 (-1 * x280 *
		  ((x254 *
			((x286 * x241) + (x236 * x291) + (x272 * x285) +
			 (x236 * (x291 + (x236 * (x290 + (x274 * x285) + (x236 * ((-1 * x277 * x286) + x289 + (x286 * x243))))) +
					  (x286 * x245))))) +
		   (x271 * x288))));
	const GEN_FLT x293 = x248 * x122;
	const GEN_FLT x294 = x130 + (-1 * x293 * x267);
	const GEN_FLT x295 = x234 * x124;
	const GEN_FLT x296 = x264 * x124;
	const GEN_FLT x297 = -1 * x238 * x296;
	const GEN_FLT x298 = (-1 * x239 * x296) + (x236 * (x297 + (x237 * x296)));
	const GEN_FLT x299 = (-1 * x296 * x240) + (x236 * x298);
	const GEN_FLT x300 =
		x261 *
		((x299 * x259) + (x294 * x282) + x293 +
		 (-1 * x280 *
		  ((x254 *
			((x236 * x299) + (-1 * x296 * x241) + (-1 * x272 * x295) +
			 (x236 *
			  (x299 + (x236 * (x298 + (-1 * x274 * x295) + (x236 * ((x277 * x296) + (-1 * x296 * x243) + x297)))) +
			   (-1 * x296 * x245))))) +
		   (x271 * x294))) +
		 (-1 * x266 * x133));
	const GEN_FLT x301 = (x235 * x152) + (-1 * x234 * x173);
	const GEN_FLT x302 = x263 * x301;
	const GEN_FLT x303 = x238 * x302;
	const GEN_FLT x304 = (x239 * x302) + (x236 * (x303 + (-1 * x237 * x302)));
	const GEN_FLT x305 = (x240 * x302) + (x236 * x304);
	const GEN_FLT x306 = (-1 * x249 * x152) + (x248 * x179);
	const GEN_FLT x307 = x184 + (-1 * x267 * x306);
	const GEN_FLT x308 =
		x261 *
		(x306 + (x287 * x302) + (x259 * x305) +
		 (-1 * x280 *
		  ((x254 *
			((x272 * x301) + (x241 * x302) + (x236 * x305) +
			 (x236 * (x305 + (x236 * (x304 + (x274 * x301) + (x236 * ((-1 * x277 * x302) + x303 + (x243 * x302))))) +
					  (x245 * x302))))) +
		   (x271 * x307))) +
		 (x282 * x307));
	const GEN_FLT x309 = (x235 * x195) + (-1 * x234 * x202);
	const GEN_FLT x310 = x263 * x309;
	const GEN_FLT x311 = x238 * x310;
	const GEN_FLT x312 = (x239 * x310) + (x236 * (x311 + (-1 * x237 * x310)));
	const GEN_FLT x313 = (x240 * x310) + (x236 * x312);
	const GEN_FLT x314 = (-1 * x249 * x195) + (x207 * x248);
	const GEN_FLT x315 = x209 + (-1 * x267 * x314);
	const GEN_FLT x316 =
		x261 *
		((x287 * x310) +
		 (-1 * x280 *
		  ((x254 * ((x241 * x310) +
					(x236 * ((x236 * (x312 + (x274 * x309) + (x236 * ((-1 * x277 * x310) + x311 + (x243 * x310))))) +
							 x313 + (x245 * x310))) +
					(x272 * x309) + (x236 * x313))) +
		   (x271 * x315))) +
		 (x259 * x313) + x314 + (x282 * x315));
	const GEN_FLT x317 = (-1 * x215 * x249) + (x223 * x248);
	const GEN_FLT x318 = x269 * (x225 + (-1 * x267 * x317));
	const GEN_FLT x319 = (x215 * x235) + (-1 * x234 * x221);
	const GEN_FLT x320 = x263 * x319;
	const GEN_FLT x321 = x238 * x320;
	const GEN_FLT x322 = (x239 * x320) + (x236 * (x321 + (-1 * x237 * x320)));
	const GEN_FLT x323 = (x240 * x320) + (x236 * x322);
	const GEN_FLT x324 =
		x261 *
		(x317 +
		 (-1 * x280 *
		  ((x254 *
			((x241 * x320) + (x236 * x323) + (x272 * x319) +
			 (x236 * (x323 + (x236 * ((x274 * x319) + x322 + (x236 * ((-1 * x277 * x320) + x321 + (x243 * x320))))) +
					  (x245 * x320))))) +
		   (x270 * x318))) +
		 (x287 * x320) + (x281 * x318) + (x259 * x323));
	out[0] = x89 + (-1 * (x111 + x110) * x113) + (-1 * x110);
	out[1] = (-1 * x113 * x121) + (-1 * x121);
	out[2] = (-1 * x134) + x130 + (-1 * (x129 + x134) * x113);
	out[3] = x184 + (-1 * x186) + (-1 * (x187 + x186) * x113);
	out[4] = x209 + (-1 * x211) + (-1 * (x212 + x211) * x113);
	out[5] = x225 + (-1 * x230) + (-1 * (x231 + x230) * x113);
	out[6] = (-1 * (x111 + x283) * x284) + x89 + (-1 * x283);
	out[7] = (-1 * x292 * x284) + (-1 * x292);
	out[8] = (-1 * (x129 + x300) * x284) + x130 + (-1 * x300);
	out[9] = (-1 * (x187 + x308) * x284) + (-1 * x308) + x184;
	out[10] = (-1 * (x212 + x316) * x284) + (-1 * x316) + x209;
	out[11] = (-1 * (x231 + x324) * x284) + (-1 * x324) + x225;
}

// Jacobian of reproject_gen2 wrt [phase_0, tilt_0, curve_0, gibPhase_0, gibMag_0, ogeeMag_0, ogeePhase_0, phase_1,
// tilt_1, curve_1, gibPhase_1, gibMag_1, ogeeMag_1, ogeePhase_1]
static inline void gen_reproject_gen2_jac_bsd_axis_angle(FLT *out, const LinmathAxisAnglePose *obj_p,
														 const FLT *sensor_pt, const LinmathAxisAnglePose *lh_p,
														 const BaseStationCal *bsd) {
	const GEN_FLT obj_px = (*obj_p).Pos[0];
	const GEN_FLT obj_py = (*obj_p).Pos[1];
	const GEN_FLT obj_pz = (*obj_p).Pos[2];
	const GEN_FLT obj_qi = (*obj_p).AxisAngleRot[0];
	const GEN_FLT obj_qj = (*obj_p).AxisAngleRot[1];
	const GEN_FLT obj_qk = (*obj_p).AxisAngleRot[2];
	const GEN_FLT sensor_x = sensor_pt[0];
	const GEN_FLT sensor_y = sensor_pt[1];
	const GEN_FLT sensor_z = sensor_pt[2];
	const GEN_FLT lh_px = (*lh_p).Pos[0];
	const GEN_FLT lh_py = (*lh_p).Pos[1];
	const GEN_FLT lh_pz = (*lh_p).Pos[2];
	const GEN_FLT lh_qi = (*lh_p).AxisAngleRot[0];
	const GEN_FLT lh_qj = (*lh_p).AxisAngleRot[1];
	const GEN_FLT lh_qk = (*lh_p).AxisAngleRot[2];
	const GEN_FLT phase_0 = bsd[0].phase;
	const GEN_FLT tilt_0 = bsd[0].tilt;
	const GEN_FLT curve_0 = bsd[0].curve;
	const GEN_FLT gibPhase_0 = bsd[0].gibpha;
	const GEN_FLT gibMag_0 = bsd[0].gibmag;
	const GEN_FLT ogeeMag_0 = bsd[0].ogeephase;
	const GEN_FLT ogeePhase_0 = bsd[0].ogeemag;
	const GEN_FLT phase_1 = bsd[1].phase;
	const GEN_FLT tilt_1 = bsd[1].tilt;
	const GEN_FLT curve_1 = bsd[1].curve;
	const GEN_FLT gibPhase_1 = bsd[1].gibpha;
	const GEN_FLT gibMag_1 = bsd[1].gibmag;
	const GEN_FLT ogeeMag_1 = bsd[1].ogeephase;
	const GEN_FLT ogeePhase_1 = bsd[1].ogeemag;
	const GEN_FLT x0 = obj_qk * obj_qk;
	const GEN_FLT x1 = obj_qi * obj_qi;
	const GEN_FLT x2 = obj_qj * obj_qj;
	const GEN_FLT x3 = 1e-10 + x2 + x0 + x1;
	const GEN_FLT x4 = sqrt(x3);
	const GEN_FLT x5 = cos(x4);
	const GEN_FLT x6 = (1. / x3) * (1 + (-1 * x5));
	const GEN_FLT x7 = (1. / x4) * sin(x4);
	const GEN_FLT x8 = x7 * obj_qj;
	const GEN_FLT x9 = x6 * obj_qi;
	const GEN_FLT x10 = x9 * obj_qk;
	const GEN_FLT x11 = x7 * obj_qi;
	const GEN_FLT x12 = x6 * obj_qk * obj_qj;
	const GEN_FLT x13 =
		((x12 + x11) * sensor_y) + obj_pz + ((x10 + (-1 * x8)) * sensor_x) + ((x5 + (x0 * x6)) * sensor_z);
	const GEN_FLT x14 = lh_qk * lh_qk;
	const GEN_FLT x15 = lh_qi * lh_qi;
	const GEN_FLT x16 = lh_qj * lh_qj;
	const GEN_FLT x17 = 1e-10 + x14 + x16 + x15;
	const GEN_FLT x18 = sqrt(x17);
	const GEN_FLT x19 = cos(x18);
	const GEN_FLT x20 = (1. / x17) * (1 + (-1 * x19));
	const GEN_FLT x21 = x7 * obj_qk;
	const GEN_FLT x22 = x9 * obj_qj;
	const GEN_FLT x23 =
		((x22 + (-1 * x21)) * sensor_y) + ((x10 + x8) * sensor_z) + ((x5 + (x1 * x6)) * sensor_x) + obj_px;
	const GEN_FLT x24 = (1. / x18) * sin(x18);
	const GEN_FLT x25 = x24 * lh_qj;
	const GEN_FLT x26 = x20 * lh_qk * lh_qi;
	const GEN_FLT x27 =
		((x5 + (x2 * x6)) * sensor_y) + ((x22 + x21) * sensor_x) + obj_py + ((x12 + (-1 * x11)) * sensor_z);
	const GEN_FLT x28 = x24 * lh_qi;
	const GEN_FLT x29 = x20 * lh_qj;
	const GEN_FLT x30 = x29 * lh_qk;
	const GEN_FLT x31 = ((x30 + x28) * x27) + ((x26 + (-1 * x25)) * x23) + lh_pz + (x13 * (x19 + (x20 * x14)));
	const GEN_FLT x32 = x24 * lh_qk;
	const GEN_FLT x33 = x29 * lh_qi;
	const GEN_FLT x34 = ((x33 + (-1 * x32)) * x27) + (x23 * (x19 + (x20 * x15))) + lh_px + ((x26 + x25) * x13);
	const GEN_FLT x35 = atan2(-1 * x31, x34);
	const GEN_FLT x36 = 0.523598775598299 + tilt_0;
	const GEN_FLT x37 = tan(x36);
	const GEN_FLT x38 = (x27 * (x19 + (x20 * x16))) + ((x33 + x32) * x23) + lh_py + ((x30 + (-1 * x28)) * x13);
	const GEN_FLT x39 = (x34 * x34) + (x31 * x31);
	const GEN_FLT x40 = x38 * (1. / sqrt(x39));
	const GEN_FLT x41 = x40 * x37;
	const GEN_FLT x42 = (-1 * asin(x41)) + x35 + ogeeMag_0;
	const GEN_FLT x43 = sin(x42);
	const GEN_FLT x44 = (x43 * ogeePhase_0) + curve_0;
	const GEN_FLT x45 = cos(x36);
	const GEN_FLT x46 = x38 * x38;
	const GEN_FLT x47 = x39 + x46;
	const GEN_FLT x48 = (1. / sqrt(x47)) * x38;
	const GEN_FLT x49 = asin((1. / x45) * x48);
	const GEN_FLT x50 = 8.0108022e-06 * x49;
	const GEN_FLT x51 = -8.0108022e-06 + (-1 * x50);
	const GEN_FLT x52 = 0.0028679863 + (x51 * x49);
	const GEN_FLT x53 = 5.3685255e-06 + (x52 * x49);
	const GEN_FLT x54 = 0.0076069798 + (x53 * x49);
	const GEN_FLT x55 = x49 * x49;
	const GEN_FLT x56 = x54 * x49;
	const GEN_FLT x57 = -8.0108022e-06 + (-1.60216044e-05 * x49);
	const GEN_FLT x58 = x52 + (x57 * x49);
	const GEN_FLT x59 = x53 + (x58 * x49);
	const GEN_FLT x60 = x54 + (x59 * x49);
	const GEN_FLT x61 = (x60 * x49) + x56;
	const GEN_FLT x62 = sin(x36);
	const GEN_FLT x63 = x62 * x44;
	const GEN_FLT x64 = x63 * x61;
	const GEN_FLT x65 = x45 + (-1 * x64);
	const GEN_FLT x66 = 1. / x65;
	const GEN_FLT x67 = x66 * x55;
	const GEN_FLT x68 = x67 * x54;
	const GEN_FLT x69 = x41 + (x68 * x44);
	const GEN_FLT x70 = 1. / sqrt(1 + (-1 * (x69 * x69)));
	const GEN_FLT x71 = cos(x42) * ogeePhase_0;
	const GEN_FLT x72 = x37 * x37;
	const GEN_FLT x73 = x46 * (1. / x39);
	const GEN_FLT x74 = x40 * (1 + x72);
	const GEN_FLT x75 = x74 * (1. / sqrt(1 + (-1 * x73 * x72)));
	const GEN_FLT x76 = 1. / (x45 * x45);
	const GEN_FLT x77 = x46 * (1. / x47);
	const GEN_FLT x78 = x76 * x48 * (1. / sqrt(1 + (-1 * x77 * x76)));
	const GEN_FLT x79 = x78 * x62;
	const GEN_FLT x80 = x79 * x51;
	const GEN_FLT x81 = (x49 * (x80 + (-1 * x79 * x50))) + (x79 * x52);
	const GEN_FLT x82 = (x81 * x49) + (x79 * x53);
	const GEN_FLT x83 = (1. / (x65 * x65)) * x54 * x55;
	const GEN_FLT x84 = x71 * x68;
	const GEN_FLT x85 =
		x70 *
		((-1 * x84 * x75) + (x82 * x67 * x44) + (2 * x78 * x63 * x66 * x56) +
		 (-1 * x83 * x44 *
		  ((-1 * x63 *
			((x79 * x54) + (x79 * x60) +
			 (x49 * (x82 + (x49 * ((x79 * x58) + x81 + (x49 * ((-2.40324066e-05 * x79 * x49) + x80 + (x79 * x57))))) +
					 (x79 * x59))) +
			 (x82 * x49))) +
		   (-1 * x61 * x44 * x45) + (x71 * x75 * x61 * x62) + (-1 * x62))) +
		 x74);
	const GEN_FLT x86 = -1 * x35;
	const GEN_FLT x87 = asin(x69) + (-1 * gibPhase_0) + x86;
	const GEN_FLT x88 = cos(x87) * gibMag_0;
	const GEN_FLT x89 = x83 * x64;
	const GEN_FLT x90 = (x68 + x89) * x70;
	const GEN_FLT x91 = x70 * (x84 + (x89 * x71));
	const GEN_FLT x92 = ((x68 * x43) + (x89 * x43)) * x70;
	const GEN_FLT x93 = 0.523598775598299 + (-1 * tilt_1);
	const GEN_FLT x94 = tan(x93);
	const GEN_FLT x95 = -1 * x94 * x40;
	const GEN_FLT x96 = (-1 * asin(x95)) + ogeeMag_1 + x35;
	const GEN_FLT x97 = sin(x96);
	const GEN_FLT x98 = (x97 * ogeePhase_1) + curve_1;
	const GEN_FLT x99 = cos(x93);
	const GEN_FLT x100 = asin((1. / x99) * x48);
	const GEN_FLT x101 = 8.0108022e-06 * x100;
	const GEN_FLT x102 = -8.0108022e-06 + (-1 * x101);
	const GEN_FLT x103 = 0.0028679863 + (x100 * x102);
	const GEN_FLT x104 = 5.3685255e-06 + (x100 * x103);
	const GEN_FLT x105 = 0.0076069798 + (x100 * x104);
	const GEN_FLT x106 = x100 * x100;
	const GEN_FLT x107 = x100 * x105;
	const GEN_FLT x108 = -8.0108022e-06 + (-1.60216044e-05 * x100);
	const GEN_FLT x109 = x103 + (x100 * x108);
	const GEN_FLT x110 = x104 + (x100 * x109);
	const GEN_FLT x111 = x105 + (x100 * x110);
	const GEN_FLT x112 = (x100 * x111) + x107;
	const GEN_FLT x113 = sin(x93);
	const GEN_FLT x114 = x98 * x113;
	const GEN_FLT x115 = x112 * x114;
	const GEN_FLT x116 = x99 + x115;
	const GEN_FLT x117 = 1. / x116;
	const GEN_FLT x118 = x106 * x117;
	const GEN_FLT x119 = x105 * x118;
	const GEN_FLT x120 = x95 + (x98 * x119);
	const GEN_FLT x121 = 1. / sqrt(1 + (-1 * (x120 * x120)));
	const GEN_FLT x122 = x94 * x94;
	const GEN_FLT x123 = x40 * (1 + x122);
	const GEN_FLT x124 = 1. / (x99 * x99);
	const GEN_FLT x125 = x48 * x124 * (1. / sqrt(1 + (-1 * x77 * x124)));
	const GEN_FLT x126 = cos(x96) * ogeePhase_1;
	const GEN_FLT x127 = x119 * x126;
	const GEN_FLT x128 = x123 * (1. / sqrt(1 + (-1 * x73 * x122)));
	const GEN_FLT x129 = x113 * x125;
	const GEN_FLT x130 = -1 * x102 * x129;
	const GEN_FLT x131 = (-1 * x103 * x129) + (x100 * (x130 + (x101 * x129)));
	const GEN_FLT x132 = (-1 * x104 * x129) + (x100 * x131);
	const GEN_FLT x133 = x105 * x106 * (1. / (x116 * x116));
	const GEN_FLT x134 =
		x121 * ((x98 * x118 * x132) +
				(-1 * x98 * x133 *
				 (x113 + (-1 * x112 * x113 * x128 * x126) +
				  (x114 * ((-1 * x105 * x129) + (-1 * x111 * x129) +
						   (x100 * (x132 +
									(x100 * (x131 + (-1 * x109 * x129) +
											 (x100 * ((2.40324066e-05 * x100 * x129) + x130 + (-1 * x108 * x129))))) +
									(-1 * x110 * x129))) +
						   (x100 * x132))) +
				  (-1 * x99 * x98 * x112))) +
				(-1 * x128 * x127) + x123 + (-2 * x107 * x114 * x117 * x125));
	const GEN_FLT x135 = asin(x120) + x86 + (-1 * gibPhase_1);
	const GEN_FLT x136 = cos(x135) * gibMag_1;
	const GEN_FLT x137 = x115 * x133;
	const GEN_FLT x138 = ((-1 * x137) + x119) * x121;
	const GEN_FLT x139 = x121 * ((-1 * x126 * x137) + x127);
	const GEN_FLT x140 = ((-1 * x97 * x137) + (x97 * x119)) * x121;
	out[0] = -1;
	out[1] = (-1 * x88 * x85) + (-1 * x85);
	out[2] = (-1 * x88 * x90) + (-1 * x90);
	out[3] = x88;
	out[4] = -1 * sin(x87);
	out[5] = (-1 * x88 * x91) + (-1 * x91);
	out[6] = (-1 * x88 * x92) + (-1 * x92);
	out[7] = 0;
	out[8] = 0;
	out[9] = 0;
	out[10] = 0;
	out[11] = 0;
	out[12] = 0;
	out[13] = 0;
	out[14] = 0;
	out[15] = 0;
	out[16] = 0;
	out[17] = 0;
	out[18] = 0;
	out[19] = 0;
	out[20] = 0;
	out[21] = -1;
	out[22] = (-1 * x134 * x136) + (-1 * x134);
	out[23] = (-1 * x138 * x136) + (-1 * x138);
	out[24] = x136;
	out[25] = -1 * sin(x135);
	out[26] = (-1 * x136 * x139) + (-1 * x139);
	out[27] = (-1 * x136 * x140) + (-1 * x140);
}

static inline FLT gen_reproject_axis_x_gen2_axis_angle(const LinmathAxisAnglePose *obj_p, const FLT *sensor_pt,
													   const LinmathAxisAnglePose *lh_p, const BaseStationCal *bsc0) {
	const GEN_FLT obj_px = (*obj_p).Pos[0];
	const GEN_FLT obj_py = (*obj_p).Pos[1];
	const GEN_FLT obj_pz = (*obj_p).Pos[2];
	const GEN_FLT obj_qi = (*obj_p).AxisAngleRot[0];
	const GEN_FLT obj_qj = (*obj_p).AxisAngleRot[1];
	const GEN_FLT obj_qk = (*obj_p).AxisAngleRot[2];
	const GEN_FLT sensor_x = sensor_pt[0];
	const GEN_FLT sensor_y = sensor_pt[1];
	const GEN_FLT sensor_z = sensor_pt[2];
	const GEN_FLT lh_px = (*lh_p).Pos[0];
	const GEN_FLT lh_py = (*lh_p).Pos[1];
	const GEN_FLT lh_pz = (*lh_p).Pos[2];
	const GEN_FLT lh_qi = (*lh_p).AxisAngleRot[0];
	const GEN_FLT lh_qj = (*lh_p).AxisAngleRot[1];
	const GEN_FLT lh_qk = (*lh_p).AxisAngleRot[2];
	const GEN_FLT phase_0 = (*bsc0).phase;
	const GEN_FLT tilt_0 = (*bsc0).tilt;
	const GEN_FLT curve_0 = (*bsc0).curve;
	const GEN_FLT gibPhase_0 = (*bsc0).gibpha;
	const GEN_FLT gibMag_0 = (*bsc0).gibmag;
	const GEN_FLT ogeeMag_0 = (*bsc0).ogeephase;
	const GEN_FLT ogeePhase_0 = (*bsc0).ogeemag;
	const GEN_FLT x0 = obj_qk * obj_qk;
	const GEN_FLT x1 = obj_qi * obj_qi;
	const GEN_FLT x2 = obj_qj * obj_qj;
	const GEN_FLT x3 = 1e-10 + x2 + x0 + x1;
	const GEN_FLT x4 = sqrt(x3);
	const GEN_FLT x5 = cos(x4);
	const GEN_FLT x6 = (1. / x3) * (1 + (-1 * x5));
	const GEN_FLT x7 = (1. / x4) * sin(x4);
	const GEN_FLT x8 = x7 * obj_qj;
	const GEN_FLT x9 = x6 * obj_qk;
	const GEN_FLT x10 = x9 * obj_qi;
	const GEN_FLT x11 = x7 * obj_qi;
	const GEN_FLT x12 = x9 * obj_qj;
	const GEN_FLT x13 =
		((x12 + x11) * sensor_y) + obj_pz + ((x10 + (-1 * x8)) * sensor_x) + ((x5 + (x0 * x6)) * sensor_z);
	const GEN_FLT x14 = lh_qk * lh_qk;
	const GEN_FLT x15 = lh_qi * lh_qi;
	const GEN_FLT x16 = lh_qj * lh_qj;
	const GEN_FLT x17 = 1e-10 + x14 + x16 + x15;
	const GEN_FLT x18 = sqrt(x17);
	const GEN_FLT x19 = cos(x18);
	const GEN_FLT x20 = (1. / x17) * (1 + (-1 * x19));
	const GEN_FLT x21 = x7 * obj_qk;
	const GEN_FLT x22 = x6 * obj_qj * obj_qi;
	const GEN_FLT x23 =
		((x22 + (-1 * x21)) * sensor_y) + ((x10 + x8) * sensor_z) + ((x5 + (x1 * x6)) * sensor_x) + obj_px;
	const GEN_FLT x24 = (1. / x18) * sin(x18);
	const GEN_FLT x25 = x24 * lh_qj;
	const GEN_FLT x26 = x20 * lh_qk * lh_qi;
	const GEN_FLT x27 =
		((x5 + (x2 * x6)) * sensor_y) + ((x22 + x21) * sensor_x) + obj_py + ((x12 + (-1 * x11)) * sensor_z);
	const GEN_FLT x28 = x24 * lh_qi;
	const GEN_FLT x29 = x20 * lh_qj;
	const GEN_FLT x30 = x29 * lh_qk;
	const GEN_FLT x31 = ((x30 + x28) * x27) + ((x26 + (-1 * x25)) * x23) + lh_pz + (x13 * (x19 + (x20 * x14)));
	const GEN_FLT x32 = x24 * lh_qk;
	const GEN_FLT x33 = x29 * lh_qi;
	const GEN_FLT x34 = ((x33 + (-1 * x32)) * x27) + (x23 * (x19 + (x20 * x15))) + lh_px + ((x26 + x25) * x13);
	const GEN_FLT x35 = atan2(-1 * x31, x34);
	const GEN_FLT x36 = (x27 * (x19 + (x20 * x16))) + ((x33 + x32) * x23) + lh_py + ((x30 + (-1 * x28)) * x13);
	const GEN_FLT x37 = 0.523598775598299 + tilt_0;
	const GEN_FLT x38 = cos(x37);
	const GEN_FLT x39 = (x34 * x34) + (x31 * x31);
	const GEN_FLT x40 = asin(x36 * (1. / x38) * (1. / sqrt(x39 + (x36 * x36))));
	const GEN_FLT x41 = 0.0028679863 + (x40 * (-8.0108022e-06 + (-8.0108022e-06 * x40)));
	const GEN_FLT x42 = 5.3685255e-06 + (x40 * x41);
	const GEN_FLT x43 = 0.0076069798 + (x40 * x42);
	const GEN_FLT x44 = x36 * (1. / sqrt(x39)) * tan(x37);
	const GEN_FLT x45 = (sin((-1 * asin(x44)) + x35 + ogeeMag_0) * ogeePhase_0) + curve_0;
	const GEN_FLT x46 = asin(
		x44 +
		((x40 * x40) * x43 * x45 *
		 (1. /
		  (x38 + (-1 * x45 * sin(x37) *
				  ((x40 * (x43 + (x40 * (x42 + (x40 * (x41 + (x40 * (-8.0108022e-06 + (-1.60216044e-05 * x40))))))))) +
				   (x40 * x43)))))));
	return -1.5707963267949 + (-1 * x46) + x35 + (-1 * phase_0) +
		   (-1 * sin(x46 + (-1 * gibPhase_0) + (-1 * x35)) * gibMag_0);
}

// Jacobian of reproject_axis_x_gen2 wrt [obj_px, obj_py, obj_pz, obj_qi, obj_qj, obj_qk]
static inline void gen_reproject_axis_x_gen2_jac_obj_p_axis_angle(FLT *out, const LinmathAxisAnglePose *obj_p,
																  const FLT *sensor_pt,
																  const LinmathAxisAnglePose *lh_p,
																  const BaseStationCal *bsc0) {
	const GEN_FLT obj_px = (*obj_p).Pos[0];
	const GEN_FLT obj_py = (*obj_p).Pos[1];
	const GEN_FLT obj_pz = (*obj_p).Pos[2];
	const GEN_FLT obj_qi = (*obj_p).AxisAngleRot[0];
	const GEN_FLT obj_qj = (*obj_p).AxisAngleRot[1];
	const GEN_FLT obj_qk = (*obj_p).AxisAngleRot[2];
	const GEN_FLT sensor_x = sensor_pt[0];
	const GEN_FLT sensor_y = sensor_pt[1];
	const GEN_FLT sensor_z = sensor_pt[2];
	const GEN_FLT lh_px = (*lh_p).Pos[0];
	const GEN_FLT lh_py = (*lh_p).Pos[1];
	const GEN_FLT lh_pz = (*lh_p).Pos[2];
	const GEN_FLT lh_qi = (*lh_p).AxisAngleRot[0];
	const GEN_FLT lh_qj = (*lh_p).AxisAngleRot[1];
	const GEN_FLT lh_qk = (*lh_p).AxisAngleRot[2];
	const GEN_FLT phase_0 = (*bsc0).phase;
	const GEN_FLT tilt_0 = (*bsc0).tilt;
	const GEN_FLT curve_0 = (*bsc0).curve;
	const GEN_FLT gibPhase_0 = (*bsc0).gibpha;
	const GEN_FLT gibMag_0 = (*bsc0).gibmag;
	const GEN_FLT ogeeMag_0 = (*bsc0).ogeephase;
	const GEN_FLT ogeePhase_0 = (*bsc0).ogeemag;
	const GEN_FLT x0 = lh_qk * lh_qk;
	const GEN_FLT x1 = lh_qi * lh_qi;
	const GEN_FLT x2 = lh_qj * lh_qj;
	const GEN_FLT x3 = 1e-10 + x2 + x0 + x1;
	const GEN_FLT x4 = sqrt(x3);
	const GEN_FLT x5 = (1. / x4) * sin(x4);
	const GEN_FLT x6 = x5 * lh_qi;
	const GEN_FLT x7 = cos(x4);
	const GEN_FLT x8 = (1. / x3) * (1 + (-1 * x7));
	const GEN_FLT x9 = x8 * lh_qj;
	const GEN_FLT x10 = x9 * lh_qk;
	const GEN_FLT x11 = x10 + (-1 * x6);
	const GEN_FLT x12 = obj_qk * obj_qk;
	const GEN_FLT x13 = obj_qi * obj_qi;
	const GEN_FLT x14 = obj_qj * obj_qj;
	const GEN_FLT x15 = 1e-10 + x14 + x12 + x13;
	const GEN_FLT x16 = 1. / x15;
	const GEN_FLT x17 = sqrt(x15);
	const GEN_FLT x18 = cos(x17);
	const GEN_FLT x19 = 1 + (-1 * x18);
	const GEN_FLT x20 = x19 * x16;
	const GEN_FLT x21 = sin(x17);
	const GEN_FLT x22 = x21 * (1. / x17);
	const GEN_FLT x23 = x22 * obj_qj;
	const GEN_FLT x24 = -1 * x23;
	const GEN_FLT x25 = x20 * obj_qk;
	const GEN_FLT x26 = x25 * obj_qi;
	const GEN_FLT x27 = x22 * obj_qi;
	const GEN_FLT x28 = x25 * obj_qj;
	const GEN_FLT x29 = ((x26 + x24) * sensor_x) + obj_pz + ((x28 + x27) * sensor_y) + ((x18 + (x20 * x12)) * sensor_z);
	const GEN_FLT x30 = x22 * obj_qk;
	const GEN_FLT x31 = -1 * x30;
	const GEN_FLT x32 = x20 * obj_qi;
	const GEN_FLT x33 = x32 * obj_qj;
	const GEN_FLT x34 = ((x33 + x31) * sensor_y) + ((x26 + x23) * sensor_z) + ((x18 + (x20 * x13)) * sensor_x) + obj_px;
	const GEN_FLT x35 = x5 * lh_qk;
	const GEN_FLT x36 = x9 * lh_qi;
	const GEN_FLT x37 = x36 + x35;
	const GEN_FLT x38 = -1 * x27;
	const GEN_FLT x39 = ((x18 + (x20 * x14)) * sensor_y) + ((x33 + x30) * sensor_x) + obj_py + ((x28 + x38) * sensor_z);
	const GEN_FLT x40 = x7 + (x2 * x8);
	const GEN_FLT x41 = (x40 * x39) + (x34 * x37) + lh_py + (x29 * x11);
	const GEN_FLT x42 = 0.523598775598299 + tilt_0;
	const GEN_FLT x43 = cos(x42);
	const GEN_FLT x44 = 1. / x43;
	const GEN_FLT x45 = x41 * x41;
	const GEN_FLT x46 = x7 + (x0 * x8);
	const GEN_FLT x47 = x5 * lh_qj;
	const GEN_FLT x48 = x8 * lh_qk * lh_qi;
	const GEN_FLT x49 = x48 + (-1 * x47);
	const GEN_FLT x50 = x10 + x6;
	const GEN_FLT x51 = (x50 * x39) + (x49 * x34) + lh_pz + (x46 * x29);
	const GEN_FLT x52 = x48 + x47;
	const GEN_FLT x53 = x7 + (x1 * x8);
	const GEN_FLT x54 = x36 + (-1 * x35);
	const GEN_FLT x55 = (x54 * x39) + (x53 * x34) + lh_px + (x52 * x29);
	const GEN_FLT x56 = x55 * x55;
	const GEN_FLT x57 = x56 + (x51 * x51);
	const GEN_FLT x58 = x57 + x45;
	const GEN_FLT x59 = (1. / sqrt(x58)) * x44;
	const GEN_FLT x60 = asin(x59 * x41);
	const GEN_FLT x61 = 8.0108022e-06 * x60;
	const GEN_FLT x62 = -8.0108022e-06 + (-1 * x61);
	const GEN_FLT x63 = 0.0028679863 + (x60 * x62);
	const GEN_FLT x64 = 5.3685255e-06 + (x60 * x63);
	const GEN_FLT x65 = 0.0076069798 + (x60 * x64);
	const GEN_FLT x66 = x60 * x65;
	const GEN_FLT x67 = -8.0108022e-06 + (-1.60216044e-05 * x60);
	const GEN_FLT x68 = x63 + (x60 * x67);
	const GEN_FLT x69 = x64 + (x60 * x68);
	const GEN_FLT x70 = x65 + (x60 * x69);
	const GEN_FLT x71 = (x70 * x60) + x66;
	const GEN_FLT x72 = atan2(-1 * x51, x55);
	const GEN_FLT x73 = tan(x42);
	const GEN_FLT x74 = x73 * (1. / sqrt(x57));
	const GEN_FLT x75 = x74 * x41;
	const GEN_FLT x76 = (-1 * asin(x75)) + x72 + ogeeMag_0;
	const GEN_FLT x77 = (sin(x76) * ogeePhase_0) + curve_0;
	const GEN_FLT x78 = sin(x42);
	const GEN_FLT x79 = x78 * x77;
	const GEN_FLT x80 = x43 + (-1 * x71 * x79);
	const GEN_FLT x81 = 1. / x80;
	const GEN_FLT x82 = x60 * x60;
	const GEN_FLT x83 = x82 * x77;
	const GEN_FLT x84 = x81 * x83;
	const GEN_FLT x85 = x75 + (x84 * x65);
	const GEN_FLT x86 = 1. / sqrt(1 + (-1 * (x85 * x85)));
	const GEN_FLT x87 = 1. / sqrt(1 + (-1 * (1. / x58) * (1. / (x43 * x43)) * x45));
	const GEN_FLT x88 = 2 * x41;
	const GEN_FLT x89 = 2 * x55;
	const GEN_FLT x90 = 2 * x51;
	const GEN_FLT x91 = (x90 * x49) + (x89 * x53);
	const GEN_FLT x92 = 1.0 / 2.0 * x41;
	const GEN_FLT x93 = (1. / (x58 * sqrt(x58))) * x92 * x44;
	const GEN_FLT x94 = x87 * ((x59 * x37) + (-1 * x93 * (x91 + (x88 * x37))));
	const GEN_FLT x95 = 2 * x81 * x77 * x66;
	const GEN_FLT x96 = x62 * x94;
	const GEN_FLT x97 = (x60 * (x96 + (-1 * x61 * x94))) + (x63 * x94);
	const GEN_FLT x98 = (x60 * x97) + (x64 * x94);
	const GEN_FLT x99 = 1. / x57;
	const GEN_FLT x100 = 1. / sqrt(1 + (-1 * (x73 * x73) * x99 * x45));
	const GEN_FLT x101 = x73 * (1. / (x57 * sqrt(x57))) * x92;
	const GEN_FLT x102 = (x74 * x37) + (-1 * x91 * x101);
	const GEN_FLT x103 = 1. / x55;
	const GEN_FLT x104 = x51 * (1. / x56);
	const GEN_FLT x105 = x56 * x99;
	const GEN_FLT x106 = ((x53 * x104) + (-1 * x49 * x103)) * x105;
	const GEN_FLT x107 = cos(x76) * ogeePhase_0;
	const GEN_FLT x108 = x107 * (x106 + (-1 * x100 * x102));
	const GEN_FLT x109 = x81 * x82 * x65;
	const GEN_FLT x110 = 2.40324066e-05 * x60;
	const GEN_FLT x111 = x71 * x78;
	const GEN_FLT x112 = (1. / (x80 * x80)) * x83 * x65;
	const GEN_FLT x113 =
		x86 * (x102 + (x109 * x108) + (x95 * x94) +
			   (-1 * x112 *
				((-1 * x108 * x111) +
				 (-1 * x79 *
				  ((x65 * x94) + (x70 * x94) +
				   (x60 * (x98 + (x60 * (x97 + (x68 * x94) + (x60 * ((-1 * x94 * x110) + x96 + (x67 * x94))))) +
						   (x69 * x94))) +
				   (x60 * x98))))) +
			   (x84 * x98));
	const GEN_FLT x114 = cos((-1 * asin(x85)) + gibPhase_0 + x72) * gibMag_0;
	const GEN_FLT x115 = (x50 * x90) + (x89 * x54);
	const GEN_FLT x116 = (x74 * x40) + (-1 * x101 * x115);
	const GEN_FLT x117 = ((x54 * x104) + (-1 * x50 * x103)) * x105;
	const GEN_FLT x118 = x117 + (-1 * x100 * x116);
	const GEN_FLT x119 = x109 * x107;
	const GEN_FLT x120 = x87 * ((x59 * x40) + (-1 * x93 * (x115 + (x88 * x40))));
	const GEN_FLT x121 = x62 * x120;
	const GEN_FLT x122 = (x60 * (x121 + (-1 * x61 * x120))) + (x63 * x120);
	const GEN_FLT x123 = (x60 * x122) + (x64 * x120);
	const GEN_FLT x124 = x107 * x111;
	const GEN_FLT x125 =
		x86 * (x116 + (x84 * x123) +
			   (-1 * x112 *
				((-1 * x118 * x124) +
				 (-1 * x79 *
				  ((x65 * x120) + (x70 * x120) +
				   (x60 * (x123 + (x60 * (x122 + (x68 * x120) + (x60 * ((-1 * x110 * x120) + x121 + (x67 * x120))))) +
						   (x69 * x120))) +
				   (x60 * x123))))) +
			   (x118 * x119) + (x95 * x120));
	const GEN_FLT x126 = (x90 * x46) + (x89 * x52);
	const GEN_FLT x127 = x87 * ((x59 * x11) + (-1 * x93 * (x126 + (x88 * x11))));
	const GEN_FLT x128 = (x74 * x11) + (-1 * x101 * x126);
	const GEN_FLT x129 = ((x52 * x104) + (-1 * x46 * x103)) * x105;
	const GEN_FLT x130 = x129 + (-1 * x100 * x128);
	const GEN_FLT x131 = x62 * x127;
	const GEN_FLT x132 = (x60 * (x131 + (-1 * x61 * x127))) + (x63 * x127);
	const GEN_FLT x133 = (x60 * x132) + (x64 * x127);
	const GEN_FLT x134 =
		x86 * (x128 +
			   (-1 * x112 *
				((-1 * x124 * x130) +
				 (-1 * x79 *
				  ((x65 * x127) + (x60 * x133) + (x70 * x127) +
				   (x60 * (x133 + (x60 * (x132 + (x68 * x127) + (x60 * ((-1 * x110 * x127) + x131 + (x67 * x127))))) +
						   (x69 * x127))))))) +
			   (x95 * x127) + (x84 * x133) + (x119 * x130));
	const GEN_FLT x135 = 2 * (1. / (x15 * x15)) * x19;
	const GEN_FLT x136 = x135 * obj_qi;
	const GEN_FLT x137 = x21 * (1. / (x15 * sqrt(x15)));
	const GEN_FLT x138 = x14 * x137;
	const GEN_FLT x139 = (x138 * obj_qi) + (-1 * x14 * x136);
	const GEN_FLT x140 = x18 * x16;
	const GEN_FLT x141 = x13 * x140;
	const GEN_FLT x142 = x13 * x137;
	const GEN_FLT x143 = obj_qj * obj_qi;
	const GEN_FLT x144 = x135 * obj_qk;
	const GEN_FLT x145 = x137 * x143;
	const GEN_FLT x146 = (x145 * obj_qk) + (-1 * x144 * x143);
	const GEN_FLT x147 = x146 + (-1 * x22);
	const GEN_FLT x148 = x137 * obj_qk;
	const GEN_FLT x149 = x148 * obj_qi;
	const GEN_FLT x150 = x140 * obj_qk;
	const GEN_FLT x151 = x150 * obj_qi;
	const GEN_FLT x152 = x151 + (-1 * x149);
	const GEN_FLT x153 = x20 * obj_qj;
	const GEN_FLT x154 = x13 * x135;
	const GEN_FLT x155 = (x142 * obj_qj) + (-1 * x154 * obj_qj);
	const GEN_FLT x156 = x155 + x153;
	const GEN_FLT x157 =
		((x156 + x152) * sensor_x) + ((x139 + x38) * sensor_y) + ((x147 + (-1 * x141) + x142) * sensor_z);
	const GEN_FLT x158 = x12 * x137;
	const GEN_FLT x159 = (x158 * obj_qi) + (-1 * x12 * x136);
	const GEN_FLT x160 = x146 + x22;
	const GEN_FLT x161 = x140 * x143;
	const GEN_FLT x162 = (-1 * x161) + x145;
	const GEN_FLT x163 = (x142 * obj_qk) + (-1 * x154 * obj_qk);
	const GEN_FLT x164 = x163 + x25;
	const GEN_FLT x165 =
		((x164 + x162) * sensor_x) + ((x159 + x38) * sensor_z) + ((x160 + x141 + (-1 * x142)) * sensor_y);
	const GEN_FLT x166 = obj_qi * obj_qi * obj_qi;
	const GEN_FLT x167 = (-1 * x151) + x149;
	const GEN_FLT x168 = x161 + (-1 * x145);
	const GEN_FLT x169 = ((x168 + x164) * sensor_z) +
						 (((2 * x32) + (x166 * x137) + x38 + (-1 * x166 * x135)) * sensor_x) +
						 ((x156 + x167) * sensor_y);
	const GEN_FLT x170 = (x53 * x169) + (x54 * x157) + (x52 * x165);
	const GEN_FLT x171 = (x49 * x169) + (x50 * x157) + (x46 * x165);
	const GEN_FLT x172 = (x90 * x171) + (x89 * x170);
	const GEN_FLT x173 = (x37 * x169) + (x11 * x165) + (x40 * x157);
	const GEN_FLT x174 = (x74 * x173) + (-1 * x101 * x172);
	const GEN_FLT x175 = ((x104 * x170) + (-1 * x103 * x171)) * x105;
	const GEN_FLT x176 = x175 + (-1 * x100 * x174);
	const GEN_FLT x177 = x87 * ((x59 * x173) + (-1 * x93 * (x172 + (x88 * x173))));
	const GEN_FLT x178 = x62 * x177;
	const GEN_FLT x179 = (x60 * (x178 + (-1 * x61 * x177))) + (x63 * x177);
	const GEN_FLT x180 = (x60 * x179) + (x64 * x177);
	const GEN_FLT x181 =
		x86 * (x174 + (x84 * x180) +
			   (-1 * x112 *
				((-1 * x124 * x176) +
				 (-1 * x79 *
				  ((x60 * x180) +
				   (x60 * (x180 + (x60 * (x179 + (x68 * x177) + (x60 * ((-1 * x110 * x177) + x178 + (x67 * x177))))) +
						   (x69 * x177))) +
				   (x65 * x177) + (x70 * x177))))) +
			   (x119 * x176) + (x95 * x177));
	const GEN_FLT x182 = obj_qj * obj_qj * obj_qj;
	const GEN_FLT x183 = (x138 * obj_qk) + (-1 * x14 * x144);
	const GEN_FLT x184 = x183 + x25;
	const GEN_FLT x185 = x139 + x32;
	const GEN_FLT x186 = x148 * obj_qj;
	const GEN_FLT x187 = x150 * obj_qj;
	const GEN_FLT x188 = x187 + (-1 * x186);
	const GEN_FLT x189 = ((x188 + x185) * sensor_x) +
						 (((x182 * x137) + (2 * x153) + x24 + (-1 * x182 * x135)) * sensor_y) +
						 ((x162 + x184) * sensor_z);
	const GEN_FLT x190 = (x158 * obj_qj) + (-1 * x12 * x135 * obj_qj);
	const GEN_FLT x191 = x14 * x140;
	const GEN_FLT x192 =
		((x147 + (-1 * x191) + x138) * sensor_x) + ((x168 + x184) * sensor_y) + ((x190 + x24) * sensor_z);
	const GEN_FLT x193 = (-1 * x187) + x186;
	const GEN_FLT x194 =
		((x160 + x191 + (-1 * x138)) * sensor_z) + ((x193 + x185) * sensor_y) + ((x155 + x24) * sensor_x);
	const GEN_FLT x195 = (x40 * x189) + (x37 * x194) + (x11 * x192);
	const GEN_FLT x196 = (x54 * x189) + (x53 * x194) + (x52 * x192);
	const GEN_FLT x197 = (x49 * x194) + (x50 * x189) + (x46 * x192);
	const GEN_FLT x198 = (x90 * x197) + (x89 * x196);
	const GEN_FLT x199 = x87 * ((x59 * x195) + (-1 * x93 * (x198 + (x88 * x195))));
	const GEN_FLT x200 = (x74 * x195) + (-1 * x101 * x198);
	const GEN_FLT x201 = ((x104 * x196) + (-1 * x103 * x197)) * x105;
	const GEN_FLT x202 = x201 + (-1 * x200 * x100);
	const GEN_FLT x203 = x62 * x199;
	const GEN_FLT x204 = (x60 * (x203 + (-1 * x61 * x199))) + (x63 * x199);
	const GEN_FLT x205 = (x60 * x204) + (x64 * x199);
	const GEN_FLT x206 =
		x86 * (x200 + (x84 * x205) +
			   (-1 * x112 *
				((-1 * x202 * x124) +
				 (-1 * x79 *
				  ((x65 * x199) + (x70 * x199) + (x60 * x205) +
				   (x60 * (x205 + (x60 * (x204 + (x68 * x199) + (x60 * ((-1 * x110 * x199) + x203 + (x67 * x199))))) +
						   (x69 * x199))))))) +
			   (x95 * x199) + (x202 * x119));
	const GEN_FLT x207 = x190 + x153;
	const GEN_FLT x208 = x12 * x140;
	const GEN_FLT x209 =
		((x183 + x31) * sensor_y) + ((x160 + (-1 * x158) + x208) * sensor_x) + ((x167 + x207) * sensor_z);
	const GEN_FLT x210 = obj_qk * obj_qk * obj_qk;
	const GEN_FLT x211 = x159 + x32;
	const GEN_FLT x212 = ((x211 + x193) * sensor_x) + ((x152 + x207) * sensor_y) +
						 (((2 * x25) + (-1 * x210 * x135) + x31 + (x210 * x137)) * sensor_z);
	const GEN_FLT x213 =
		((x211 + x188) * sensor_z) + ((x147 + x158 + (-1 * x208)) * sensor_y) + ((x163 + x31) * sensor_x);
	const GEN_FLT x214 = (x53 * x213) + (x54 * x209) + (x52 * x212);
	const GEN_FLT x215 = (x49 * x213) + (x50 * x209) + (x46 * x212);
	const GEN_FLT x216 = (x90 * x215) + (x89 * x214);
	const GEN_FLT x217 = (x37 * x213) + (x40 * x209) + (x11 * x212);
	const GEN_FLT x218 = (x74 * x217) + (-1 * x216 * x101);
	const GEN_FLT x219 = ((x214 * x104) + (-1 * x215 * x103)) * x105;
	const GEN_FLT x220 = x219 + (-1 * x218 * x100);
	const GEN_FLT x221 = x87 * ((x59 * x217) + (-1 * x93 * (x216 + (x88 * x217))));
	const GEN_FLT x222 = x62 * x221;
	const GEN_FLT x223 = (x60 * (x222 + (-1 * x61 * x221))) + (x63 * x221);
	const GEN_FLT x224 = (x60 * x223) + (x64 * x221);
	const GEN_FLT x225 =
		x86 * ((-1 * x112 *
				((-1 * x220 * x124) +
				 (-1 * x79 *
				  ((x65 * x221) + (x60 * x224) + (x70 * x221) +
				   (x60 * ((x60 * (x223 + (x68 * x221) + (x60 * ((-1 * x221 * x110) + (x67 * x221) + x222)))) + x224 +
						   (x69 * x221))))))) +
			   (x95 * x221) + (x220 * x119) + x218 + (x84 * x224));
	out[0] = x106 + (-1 * x113) + (-1 * ((-1 * x106) + x113) * x114);
	out[1] = x117 + (-1 * x125) + (-1 * ((-1 * x117) + x125) * x114);
	out[2] = x129 + (-1 * x134) + (-1 * ((-1 * x129) + x134) * x114);
	out[3] = (-1 * x181) + x175 + (-1 * ((-1 * x175) + x181) * x114);
	out[4] = x201 + (-1 * x206) + (-1 * ((-1 * x201) + x206) * x114);
	out[5] = (-1 * x225) + x219 + (-1 * ((-1 * x219) + x225) * x114);
}

// Jacobian of reproject_axis_x_gen2 wrt [sensor_x, sensor_y, sensor_z]
static inline void gen_reproject_axis_x_gen2_jac_sensor_pt_axis_angle(FLT *out, const LinmathAxisAnglePose *obj_p,
																	  const FLT *sensor_pt,
																	  const LinmathAxisAnglePose *lh_p,
																	  const BaseStationCal *bsc0) {
	const GEN_FLT obj_px = (*obj_p).Pos[0];
	const GEN_FLT obj_py = (*obj_p).Pos[1];
	const GEN_FLT obj_pz = (*obj_p).Pos[2];
	const GEN_FLT obj_qi = (*obj_p).AxisAngleRot[0];
	const GEN_FLT obj_qj = (*obj_p).AxisAngleRot[1];
	const GEN_FLT obj_qk = (*obj_p).AxisAngleRot[2];
	const GEN_FLT sensor_x = sensor_pt[0];
	const GEN_FLT sensor_y = sensor_pt[1];
	const GEN_FLT sensor_z = sensor_pt[2];
	const GEN_FLT lh_px = (*lh_p).Pos[0];
	const GEN_FLT lh_py = (*lh_p).Pos[1];
	const GEN_FLT lh_pz = (*lh_p).Pos[2];
	const GEN_FLT lh_qi = (*lh_p).AxisAngleRot[0];
	const GEN_FLT lh_qj = (*lh_p).AxisAngleRot[1];
	const GEN_FLT lh_qk = (*lh_p).AxisAngleRot[2];
	const GEN_FLT phase_0 = (*bsc0).phase;
	const GEN_FLT tilt_0 = (*bsc0).tilt;
	const GEN_FLT curve_0 = (*bsc0).curve;
	const GEN_FLT gibPhase_0 = (*bsc0).gibpha;
	const GEN_FLT gibMag_0 = (*bsc0).gibmag;
	const GEN_FLT ogeeMag_0 = (*bsc0).ogeephase;
	const GEN_FLT ogeePhase_0 = (*bsc0).ogeemag;
	const GEN_FLT x0 = lh_qk * lh_qk;
	const GEN_FLT x1 = lh_qi * lh_qi;
	const GEN_FLT x2 = lh_qj * lh_qj;
	const GEN_FLT x3 = 1e-10 + x2 + x0 + x1;
	const GEN_FLT x4 = sqrt(x3);
	const GEN_FLT x5 = (1. / x4) * sin(x4);
	const GEN_FLT x6 = x5 * lh_qi;
	const GEN_FLT x7 = cos(x4);
	const GEN_FLT x8 = (1. / x3) * (1 + (-1 * x7));
	const GEN_FLT x9 = x8 * lh_qk * lh_qj;
	const GEN_FLT x10 = x9 + (-1 * x6);
	const GEN_FLT x11 = obj_qk * obj_qk;
	const GEN_FLT x12 = obj_qi * obj_qi;
	const GEN_FLT x13 = obj_qj * obj_qj;
	const GEN_FLT x14 = 1e-10 + x13 + x11 + x12;
	const GEN_FLT x15 = sqrt(x14);
	const GEN_FLT x16 = cos(x15);
	const GEN_FLT x17 = (1. / x14) * (1 + (-1 * x16));
	const GEN_FLT x18 = x16 + (x11 * x17);
	const GEN_FLT x19 = (1. / x15) * sin(x15);
	const GEN_FLT x20 = x19 * obj_qj;
	const GEN_FLT x21 = x17 * obj_qk;
	const GEN_FLT x22 = x21 * obj_qi;
	const GEN_FLT x23 = x22 + (-1 * x20);
	const GEN_FLT x24 = x19 * obj_qi;
	const GEN_FLT x25 = x21 * obj_qj;
	const GEN_FLT x26 = x25 + x24;
	const GEN_FLT x27 = (x26 * sensor_y) + (x23 * sensor_x) + obj_pz + (x18 * sensor_z);
	const GEN_FLT x28 = x16 + (x12 * x17);
	const GEN_FLT x29 = x22 + x20;
	const GEN_FLT x30 = x19 * obj_qk;
	const GEN_FLT x31 = x17 * obj_qj * obj_qi;
	const GEN_FLT x32 = x31 + (-1 * x30);
	const GEN_FLT x33 = (x32 * sensor_y) + (x29 * sensor_z) + (x28 * sensor_x) + obj_px;
	const GEN_FLT x34 = x5 * lh_qk;
	const GEN_FLT x35 = x8 * lh_qi;
	const GEN_FLT x36 = x35 * lh_qj;
	const GEN_FLT x37 = x36 + x34;
	const GEN_FLT x38 = x25 + (-1 * x24);
	const GEN_FLT x39 = x31 + x30;
	const GEN_FLT x40 = x16 + (x13 * x17);
	const GEN_FLT x41 = (x39 * sensor_x) + obj_py + (x40 * sensor_y) + (x38 * sensor_z);
	const GEN_FLT x42 = x7 + (x2 * x8);
	const GEN_FLT x43 = (x33 * x37) + lh_py + (x41 * x42) + (x27 * x10);
	const GEN_FLT x44 = x43 * x43;
	const GEN_FLT x45 = 0.523598775598299 + tilt_0;
	const GEN_FLT x46 = tan(x45);
	const GEN_FLT x47 = x7 + (x0 * x8);
	const GEN_FLT x48 = x5 * lh_qj;
	const GEN_FLT x49 = x35 * lh_qk;
	const GEN_FLT x50 = x49 + (-1 * x48);
	const GEN_FLT x51 = x9 + x6;
	const GEN_FLT x52 = (x51 * x41) + (x50 * x33) + lh_pz + (x47 * x27);
	const GEN_FLT x53 = x49 + x48;
	const GEN_FLT x54 = x7 + (x1 * x8);
	const GEN_FLT x55 = x36 + (-1 * x34);
	const GEN_FLT x56 = (x55 * x41) + (x54 * x33) + lh_px + (x53 * x27);
	const GEN_FLT x57 = x56 * x56;
	const GEN_FLT x58 = x57 + (x52 * x52);
	const GEN_FLT x59 = 1. / x58;
	const GEN_FLT x60 = 1. / sqrt(1 + (-1 * x59 * x44 * (x46 * x46)));
	const GEN_FLT x61 = (x54 * x28) + (x55 * x39) + (x53 * x23);
	const GEN_FLT x62 = 2 * x56;
	const GEN_FLT x63 = (x50 * x28) + (x51 * x39) + (x47 * x23);
	const GEN_FLT x64 = 2 * x52;
	const GEN_FLT x65 = (x63 * x64) + (x61 * x62);
	const GEN_FLT x66 = 1.0 / 2.0 * x43;
	const GEN_FLT x67 = x66 * (1. / (x58 * sqrt(x58))) * x46;
	const GEN_FLT x68 = (x37 * x28) + (x42 * x39) + (x23 * x10);
	const GEN_FLT x69 = (1. / sqrt(x58)) * x46;
	const GEN_FLT x70 = (x68 * x69) + (-1 * x67 * x65);
	const GEN_FLT x71 = 1. / x56;
	const GEN_FLT x72 = x52 * (1. / x57);
	const GEN_FLT x73 = x57 * x59;
	const GEN_FLT x74 = ((x72 * x61) + (-1 * x71 * x63)) * x73;
	const GEN_FLT x75 = x74 + (-1 * x70 * x60);
	const GEN_FLT x76 = atan2(-1 * x52, x56);
	const GEN_FLT x77 = x69 * x43;
	const GEN_FLT x78 = x76 + (-1 * asin(x77)) + ogeeMag_0;
	const GEN_FLT x79 = cos(x78) * ogeePhase_0;
	const GEN_FLT x80 = cos(x45);
	const GEN_FLT x81 = 1. / x80;
	const GEN_FLT x82 = x58 + x44;
	const GEN_FLT x83 = x81 * (1. / sqrt(x82));
	const GEN_FLT x84 = asin(x83 * x43);
	const GEN_FLT x85 = 8.0108022e-06 * x84;
	const GEN_FLT x86 = -8.0108022e-06 + (-1 * x85);
	const GEN_FLT x87 = 0.0028679863 + (x84 * x86);
	const GEN_FLT x88 = 5.3685255e-06 + (x84 * x87);
	const GEN_FLT x89 = 0.0076069798 + (x88 * x84);
	const GEN_FLT x90 = x84 * x84;
	const GEN_FLT x91 = x89 * x84;
	const GEN_FLT x92 = -8.0108022e-06 + (-1.60216044e-05 * x84);
	const GEN_FLT x93 = x87 + (x84 * x92);
	const GEN_FLT x94 = x88 + (x84 * x93);
	const GEN_FLT x95 = x89 + (x84 * x94);
	const GEN_FLT x96 = (x84 * x95) + x91;
	const GEN_FLT x97 = (sin(x78) * ogeePhase_0) + curve_0;
	const GEN_FLT x98 = sin(x45);
	const GEN_FLT x99 = x98 * x97;
	const GEN_FLT x100 = x80 + (-1 * x99 * x96);
	const GEN_FLT x101 = 1. / x100;
	const GEN_FLT x102 = x89 * x90 * x101;
	const GEN_FLT x103 = x79 * x102;
	const GEN_FLT x104 = 2 * x43;
	const GEN_FLT x105 = x81 * (1. / (x82 * sqrt(x82))) * x66;
	const GEN_FLT x106 = (x83 * x68) + (-1 * x105 * (x65 + (x68 * x104)));
	const GEN_FLT x107 = 1. / sqrt(1 + (-1 * (1. / (x80 * x80)) * (1. / x82) * x44));
	const GEN_FLT x108 = x88 * x107;
	const GEN_FLT x109 = x107 * x106;
	const GEN_FLT x110 = x86 * x109;
	const GEN_FLT x111 = (x84 * (x110 + (-1 * x85 * x109))) + (x87 * x109);
	const GEN_FLT x112 = (x84 * x111) + (x108 * x106);
	const GEN_FLT x113 = x90 * x97;
	const GEN_FLT x114 = x101 * x113;
	const GEN_FLT x115 = 2 * x91 * x97 * x101;
	const GEN_FLT x116 = 2.40324066e-05 * x84;
	const GEN_FLT x117 = x98 * x96;
	const GEN_FLT x118 = x79 * x117;
	const GEN_FLT x119 = x89 * (1. / (x100 * x100)) * x113;
	const GEN_FLT x120 = x77 + (x89 * x114);
	const GEN_FLT x121 = 1. / sqrt(1 + (-1 * (x120 * x120)));
	const GEN_FLT x122 =
		x121 * (x70 +
				(-1 * x119 *
				 ((-1 * x75 * x118) +
				  (-1 * x99 *
				   ((x89 * x109) + (x84 * x112) + (x95 * x109) +
					(x84 * (x112 + (x84 * (x111 + (x93 * x109) + (x84 * ((-1 * x109 * x116) + x110 + (x92 * x109))))) +
							(x94 * x109))))))) +
				(x109 * x115) + (x75 * x103) + (x112 * x114));
	const GEN_FLT x123 = cos((-1 * asin(x120)) + gibPhase_0 + x76) * gibMag_0;
	const GEN_FLT x124 = (x54 * x32) + (x55 * x40) + (x53 * x26);
	const GEN_FLT x125 = (x50 * x32) + (x51 * x40) + (x47 * x26);
	const GEN_FLT x126 = (x64 * x125) + (x62 * x124);
	const GEN_FLT x127 = (x32 * x37) + (x26 * x10) + (x40 * x42);
	const GEN_FLT x128 = (x69 * x127) + (-1 * x67 * x126);
	const GEN_FLT x129 = ((x72 * x124) + (-1 * x71 * x125)) * x73;
	const GEN_FLT x130 = x129 + (-1 * x60 * x128);
	const GEN_FLT x131 = (x83 * x127) + (-1 * x105 * (x126 + (x104 * x127)));
	const GEN_FLT x132 = x107 * x131;
	const GEN_FLT x133 = x86 * x132;
	const GEN_FLT x134 = (x84 * (x133 + (-1 * x85 * x132))) + (x87 * x132);
	const GEN_FLT x135 = (x84 * x134) + (x108 * x131);
	const GEN_FLT x136 =
		x121 * (x128 +
				(-1 * x119 *
				 ((-1 * x118 * x130) +
				  (-1 * x99 *
				   ((x89 * x132) + (x84 * x135) + (x95 * x132) +
					(x84 * (x135 + (x84 * (x134 + (x93 * x132) + (x84 * ((-1 * x116 * x132) + x133 + (x92 * x132))))) +
							(x94 * x132))))))) +
				(x114 * x135) + (x103 * x130) + (x115 * x132));
	const GEN_FLT x137 = (x37 * x29) + (x42 * x38) + (x10 * x18);
	const GEN_FLT x138 = (x54 * x29) + (x55 * x38) + (x53 * x18);
	const GEN_FLT x139 = (x51 * x38) + (x50 * x29) + (x47 * x18);
	const GEN_FLT x140 = (x64 * x139) + (x62 * x138);
	const GEN_FLT x141 = (x83 * x137) + (-1 * x105 * (x140 + (x104 * x137)));
	const GEN_FLT x142 = x107 * x141;
	const GEN_FLT x143 = x86 * x142;
	const GEN_FLT x144 = (x84 * (x143 + (-1 * x85 * x142))) + (x87 * x142);
	const GEN_FLT x145 = (x84 * x144) + (x108 * x141);
	const GEN_FLT x146 = (x69 * x137) + (-1 * x67 * x140);
	const GEN_FLT x147 = ((x72 * x138) + (-1 * x71 * x139)) * x73;
	const GEN_FLT x148 = x79 * (x147 + (-1 * x60 * x146));
	const GEN_FLT x149 =
		x121 * ((x102 * x148) +
				(-1 * x119 *
				 ((-1 * x117 * x148) +
				  (-1 * x99 *
				   ((x89 * x142) + (x95 * x142) + (x84 * x145) +
					(x84 * (x145 + (x84 * (x144 + (x93 * x142) + (x84 * ((-1 * x116 * x142) + x143 + (x92 * x142))))) +
							(x94 * x142))))))) +
				x146 + (x115 * x142) + (x114 * x145));
	out[0] = x74 + (-1 * x122) + (-1 * x123 * ((-1 * x74) + x122));
	out[1] = x129 + (-1 * x136) + (-1 * ((-1 * x129) + x136) * x123);
	out[2] = (-1 * x149) + x147 + (-1 * ((-1 * x147) + x149) * x123);
}

// Jacobian of reproject_axis_x_gen2 wrt [lh_px, lh_py, lh_pz, lh_qi, lh_qj, lh_qk]
static inline void gen_reproject_axis_x_gen2_jac_lh_p_axis_angle(FLT *out, const LinmathAxisAnglePose *obj_p,
																 const FLT *sensor_pt, const LinmathAxisAnglePose *lh_p,
																 const BaseStationCal *bsc0) {
	const GEN_FLT obj_px = (*obj_p).Pos[0];
	const GEN_FLT obj_py = (*obj_p).Pos[1];
	const GEN_FLT obj_pz = (*obj_p).Pos[2];
	const GEN_FLT obj_qi = (*obj_p).AxisAngleRot[0];
	const GEN_FLT obj_qj = (*obj_p).AxisAngleRot[1];
	const GEN_FLT obj_qk = (*obj_p).AxisAngleRot[2];
	const GEN_FLT sensor_x = sensor_pt[0];
	const GEN_FLT sensor_y = sensor_pt[1];
	const GEN_FLT sensor_z = sensor_pt[2];
	const GEN_FLT lh_px = (*lh_p).Pos[0];
	const GEN_FLT lh_py = (*lh_p).Pos[1];
	const GEN_FLT lh_pz = (*lh_p).Pos[2];
	const GEN_FLT lh_qi = (*lh_p).AxisAngleRot[0];
	const GEN_FLT lh_qj = (*lh_p).AxisAngleRot[1];
	const GEN_FLT lh_qk = (*lh_p).AxisAngleRot[2];
	const GEN_FLT phase_0 = (*bsc0).phase;
	const GEN_FLT tilt_0 = (*bsc0).tilt;
	const GEN_FLT curve_0 = (*bsc0).curve;
	const GEN_FLT gibPhase_0 = (*bsc0).gibpha;
	const GEN_FLT gibMag_0 = (*bsc0).gibmag;
	const GEN_FLT ogeeMag_0 = (*bsc0).ogeephase;
	const GEN_FLT ogeePhase_0 = (*bsc0).ogeemag;
	const GEN_FLT x0 = lh_qk * lh_qk;
	const GEN_FLT x1 = lh_qi * lh_qi;
	const GEN_FLT x2 = lh_qj * lh_qj;
	const GEN_FLT x3 = 1e-10 + x2 + x0 + x1;
	const GEN_FLT x4 = sqrt(x3);
	const GEN_FLT x5 = sin(x4);
	const GEN_FLT x6 = (1. / x4) * x5;
	const GEN_FLT x7 = x6 * lh_qj;
	const GEN_FLT x8 = 1. / x3;
	const GEN_FLT x9 = cos(x4);
	const GEN_FLT x10 = 1 + (-1 * x9);
	const GEN_FLT x11 = x8 * x10;
	const GEN_FLT x12 = x11 * lh_qi;
	const GEN_FLT x13 = x12 * lh_qk;
	const GEN_FLT x14 = obj_qk * obj_qk;
	const GEN_FLT x15 = obj_qi * obj_qi;
	const GEN_FLT x16 = obj_qj * obj_qj;
	const GEN_FLT x17 = 1e-10 + x14 + x16 + x15;
	const GEN_FLT x18 = sqrt(x17);
	const GEN_FLT x19 = cos(x18);
	const GEN_FLT x20 = (1. / x17) * (1 + (-1 * x19));
	const GEN_FLT x21 = (1. / x18) * sin(x18);
	const GEN_FLT x22 = x21 * obj_qj;
	const GEN_FLT x23 = x20 * obj_qk;
	const GEN_FLT x24 = x23 * obj_qi;
	const GEN_FLT x25 = x21 * obj_qi;
	const GEN_FLT x26 = x23 * obj_qj;
	const GEN_FLT x27 =
		((x26 + x25) * sensor_y) + ((x24 + (-1 * x22)) * sensor_x) + obj_pz + ((x19 + (x20 * x14)) * sensor_z);
	const GEN_FLT x28 = x21 * obj_qk;
	const GEN_FLT x29 = x20 * obj_qj * obj_qi;
	const GEN_FLT x30 =
		((x29 + (-1 * x28)) * sensor_y) + ((x24 + x22) * sensor_z) + ((x19 + (x20 * x15)) * sensor_x) + obj_px;
	const GEN_FLT x31 =
		((x29 + x28) * sensor_x) + ((x19 + (x20 * x16)) * sensor_y) + obj_py + ((x26 + (-1 * x25)) * sensor_z);
	const GEN_FLT x32 = x6 * lh_qk;
	const GEN_FLT x33 = -1 * x32;
	const GEN_FLT x34 = x11 * lh_qj;
	const GEN_FLT x35 = x34 * lh_qi;
	const GEN_FLT x36 = ((x35 + x33) * x31) + lh_px + (x30 * (x9 + (x1 * x11))) + (x27 * (x13 + x7));
	const GEN_FLT x37 = x6 * lh_qi;
	const GEN_FLT x38 = -1 * x37;
	const GEN_FLT x39 = x34 * lh_qk;
	const GEN_FLT x40 = (x31 * (x9 + (x2 * x11))) + lh_py + ((x35 + x32) * x30) + ((x39 + x38) * x27);
	const GEN_FLT x41 = x40 * x36;
	const GEN_FLT x42 = 0.523598775598299 + tilt_0;
	const GEN_FLT x43 = tan(x42);
	const GEN_FLT x44 = -1 * x7;
	const GEN_FLT x45 = ((x39 + x37) * x31) + ((x13 + x44) * x30) + lh_pz + (x27 * (x9 + (x0 * x11)));
	const GEN_FLT x46 = x36 * x36;
	const GEN_FLT x47 = x46 + (x45 * x45);
	const GEN_FLT x48 = x43 * (1. / (x47 * sqrt(x47)));
	const GEN_FLT x49 = x41 * x48;
	const GEN_FLT x50 = cos(x42);
	const GEN_FLT x51 = 1. / x50;
	const GEN_FLT x52 = x40 * x40;
	const GEN_FLT x53 = x47 + x52;
	const GEN_FLT x54 = (1. / sqrt(x53)) * x51;
	const GEN_FLT x55 = asin(x54 * x40);
	const GEN_FLT x56 = -8.0108022e-06 + (-1.60216044e-05 * x55);
	const GEN_FLT x57 = 8.0108022e-06 * x55;
	const GEN_FLT x58 = -8.0108022e-06 + (-1 * x57);
	const GEN_FLT x59 = 0.0028679863 + (x58 * x55);
	const GEN_FLT x60 = x59 + (x56 * x55);
	const GEN_FLT x61 = 5.3685255e-06 + (x55 * x59);
	const GEN_FLT x62 = x61 + (x60 * x55);
	const GEN_FLT x63 = 0.0076069798 + (x61 * x55);
	const GEN_FLT x64 = x63 + (x62 * x55);
	const GEN_FLT x65 = 1. / sqrt(1 + (-1 * (1. / (x50 * x50)) * (1. / x53) * x52));
	const GEN_FLT x66 = (1. / (x53 * sqrt(x53))) * x51;
	const GEN_FLT x67 = x66 * x41;
	const GEN_FLT x68 = x67 * x65;
	const GEN_FLT x69 = -1 * x68 * x58;
	const GEN_FLT x70 = 2.40324066e-05 * x55;
	const GEN_FLT x71 = x65 * x59;
	const GEN_FLT x72 = (x55 * (x69 + (x68 * x57))) + (-1 * x71 * x67);
	const GEN_FLT x73 = (x72 * x55) + (-1 * x61 * x68);
	const GEN_FLT x74 = atan2(-1 * x45, x36);
	const GEN_FLT x75 = x43 * (1. / sqrt(x47));
	const GEN_FLT x76 = x75 * x40;
	const GEN_FLT x77 = (-1 * asin(x76)) + x74 + ogeeMag_0;
	const GEN_FLT x78 = (sin(x77) * ogeePhase_0) + curve_0;
	const GEN_FLT x79 = sin(x42);
	const GEN_FLT x80 = x79 * x78;
	const GEN_FLT x81 = 1. / x47;
	const GEN_FLT x82 = 1. / sqrt(1 + (-1 * x81 * x52 * (x43 * x43)));
	const GEN_FLT x83 = x81 * x45;
	const GEN_FLT x84 = x83 + (x82 * x49);
	const GEN_FLT x85 = cos(x77) * ogeePhase_0;
	const GEN_FLT x86 = x63 * x55;
	const GEN_FLT x87 = (x64 * x55) + x86;
	const GEN_FLT x88 = x87 * x79;
	const GEN_FLT x89 = x88 * x85;
	const GEN_FLT x90 = x50 + (-1 * x80 * x87);
	const GEN_FLT x91 = x55 * x55;
	const GEN_FLT x92 = x78 * x91;
	const GEN_FLT x93 = x63 * x92 * (1. / (x90 * x90));
	const GEN_FLT x94 = 2 * x36;
	const GEN_FLT x95 = x66 * x40;
	const GEN_FLT x96 = 1. / x90;
	const GEN_FLT x97 = x86 * x78 * x96;
	const GEN_FLT x98 = x65 * x97 * x95;
	const GEN_FLT x99 = x92 * x96;
	const GEN_FLT x100 = x63 * x91 * x96;
	const GEN_FLT x101 = x85 * x100;
	const GEN_FLT x102 = x76 + (x63 * x99);
	const GEN_FLT x103 = 1. / sqrt(1 + (-1 * (x102 * x102)));
	const GEN_FLT x104 =
		x103 * ((x84 * x101) + (x73 * x99) + (-1 * x98 * x94) + (-1 * x49) +
				(-1 * x93 *
				 ((-1 * x89 * x84) +
				  (-1 * x80 *
				   ((x73 * x55) + (-1 * x63 * x68) + (-1 * x64 * x68) +
					(x55 * (x73 + (x55 * (x72 + (-1 * x60 * x68) + (x55 * ((x70 * x68) + x69 + (-1 * x68 * x56))))) +
							(-1 * x62 * x68))))))));
	const GEN_FLT x105 = cos((-1 * asin(x102)) + gibPhase_0 + x74) * gibMag_0;
	const GEN_FLT x106 = x65 * (x54 + (-1 * x66 * x52));
	const GEN_FLT x107 = x58 * x106;
	const GEN_FLT x108 = (x55 * (x107 + (-1 * x57 * x106))) + (x59 * x106);
	const GEN_FLT x109 = (x55 * x108) + (x61 * x106);
	const GEN_FLT x110 = x82 * x75;
	const GEN_FLT x111 = 2 * x97;
	const GEN_FLT x112 =
		x103 * ((x106 * x111) + (-1 * x101 * x110) + (x99 * x109) + x75 +
				(-1 * x93 *
				 ((x89 * x110) +
				  (-1 * x80 *
				   ((x63 * x106) + (x55 * x109) + (x64 * x106) +
					(x55 * (x109 + (x55 * (x108 + (x60 * x106) + (x55 * (x107 + (-1 * x70 * x106) + (x56 * x106))))) +
							(x62 * x106))))))));
	const GEN_FLT x113 = x40 * x48;
	const GEN_FLT x114 = x45 * x113;
	const GEN_FLT x115 = x95 * x45;
	const GEN_FLT x116 = x65 * x115;
	const GEN_FLT x117 = -1 * x58 * x116;
	const GEN_FLT x118 = (x55 * (x117 + (x57 * x116))) + (-1 * x71 * x115);
	const GEN_FLT x119 = (x55 * x118) + (-1 * x61 * x116);
	const GEN_FLT x120 = x81 * x36;
	const GEN_FLT x121 = -1 * x120;
	const GEN_FLT x122 = x121 + (x82 * x114);
	const GEN_FLT x123 = 2 * x45;
	const GEN_FLT x124 =
		x103 *
		((-1 * x98 * x123) + (x101 * x122) + (-1 * x114) + (x99 * x119) +
		 (-1 * x93 *
		  ((-1 * x89 * x122) +
		   (-1 * x80 *
			((-1 * x63 * x116) +
			 (x55 * (x119 + (x55 * (x118 + (-1 * x60 * x116) + (x55 * ((x70 * x116) + x117 + (-1 * x56 * x116))))) +
					 (-1 * x62 * x116))) +
			 (-1 * x64 * x116) + (x55 * x119))))));
	const GEN_FLT x125 = 2 * (1. / (x3 * x3)) * x10;
	const GEN_FLT x126 = x125 * lh_qi;
	const GEN_FLT x127 = (1. / (x3 * sqrt(x3))) * x5;
	const GEN_FLT x128 = x2 * x127;
	const GEN_FLT x129 = (x128 * lh_qi) + (-1 * x2 * x126);
	const GEN_FLT x130 = x8 * x9;
	const GEN_FLT x131 = x1 * x130;
	const GEN_FLT x132 = x1 * x127;
	const GEN_FLT x133 = lh_qj * lh_qi;
	const GEN_FLT x134 = x127 * lh_qk;
	const GEN_FLT x135 = x125 * lh_qk;
	const GEN_FLT x136 = (-1 * x133 * x135) + (x133 * x134);
	const GEN_FLT x137 = x136 + (-1 * x6);
	const GEN_FLT x138 = x125 * lh_qj;
	const GEN_FLT x139 = (x132 * lh_qj) + (-1 * x1 * x138);
	const GEN_FLT x140 = x139 + x34;
	const GEN_FLT x141 = x130 * lh_qk;
	const GEN_FLT x142 = x141 * lh_qi;
	const GEN_FLT x143 = x134 * lh_qi;
	const GEN_FLT x144 = (-1 * x143) + x142;
	const GEN_FLT x145 = ((x144 + x140) * x30) + (x31 * (x129 + x38)) + (x27 * (x137 + (-1 * x131) + x132));
	const GEN_FLT x146 = 2 * x40;
	const GEN_FLT x147 = x143 + (-1 * x142);
	const GEN_FLT x148 = x11 * lh_qk;
	const GEN_FLT x149 = (x132 * lh_qk) + (-1 * x1 * x135);
	const GEN_FLT x150 = x149 + x148;
	const GEN_FLT x151 = x130 * x133;
	const GEN_FLT x152 = x127 * x133;
	const GEN_FLT x153 = (-1 * x152) + x151;
	const GEN_FLT x154 = lh_qi * lh_qi * lh_qi;
	const GEN_FLT x155 =
		(((2 * x12) + (-1 * x125 * x154) + x38 + (x127 * x154)) * x30) + ((x147 + x140) * x31) + ((x153 + x150) * x27);
	const GEN_FLT x156 = x136 + x6;
	const GEN_FLT x157 = x0 * x127;
	const GEN_FLT x158 = (x157 * lh_qi) + (-1 * x0 * x126);
	const GEN_FLT x159 = x152 + (-1 * x151);
	const GEN_FLT x160 = ((x159 + x150) * x30) + (x31 * (x156 + x131 + (-1 * x132))) + (x27 * (x158 + x38));
	const GEN_FLT x161 = (x123 * x160) + (x94 * x155);
	const GEN_FLT x162 = 1.0 / 2.0 * x95;
	const GEN_FLT x163 = x65 * ((x54 * x145) + (-1 * x162 * (x161 + (x146 * x145))));
	const GEN_FLT x164 = x58 * x163;
	const GEN_FLT x165 = (x55 * (x164 + (-1 * x57 * x163))) + (x59 * x163);
	const GEN_FLT x166 = (x55 * x165) + (x61 * x163);
	const GEN_FLT x167 = 1.0 / 2.0 * x113;
	const GEN_FLT x168 = (x75 * x145) + (-1 * x161 * x167);
	const GEN_FLT x169 = 1. / x36;
	const GEN_FLT x170 = x45 * (1. / x46);
	const GEN_FLT x171 = x81 * x46;
	const GEN_FLT x172 = ((x170 * x155) + (-1 * x160 * x169)) * x171;
	const GEN_FLT x173 = x172 + (-1 * x82 * x168);
	const GEN_FLT x174 =
		x103 * ((-1 * x93 *
				 ((-1 * x89 * x173) +
				  (-1 * x80 *
				   ((x55 * x166) +
					(x55 * (x166 + (x55 * (x165 + (x60 * x163) + (x55 * ((-1 * x70 * x163) + x164 + (x56 * x163))))) +
							(x62 * x163))) +
					(x63 * x163) + (x64 * x163))))) +
				(x101 * x173) + x168 + (x99 * x166) + (x111 * x163));
	const GEN_FLT x175 = lh_qj * lh_qj * lh_qj;
	const GEN_FLT x176 = (x128 * lh_qk) + (-1 * x2 * x135);
	const GEN_FLT x177 = x176 + x148;
	const GEN_FLT x178 = x129 + x12;
	const GEN_FLT x179 = x141 * lh_qj;
	const GEN_FLT x180 = x134 * lh_qj;
	const GEN_FLT x181 = (-1 * x180) + x179;
	const GEN_FLT x182 =
		((x181 + x178) * x30) + (((-1 * x125 * x175) + (x127 * x175) + x44 + (2 * x34)) * x31) + ((x177 + x159) * x27);
	const GEN_FLT x183 = x180 + (-1 * x179);
	const GEN_FLT x184 = x2 * x130;
	const GEN_FLT x185 = (x30 * (x139 + x44)) + ((x183 + x178) * x31) + (x27 * (x156 + x184 + (-1 * x128)));
	const GEN_FLT x186 = (x157 * lh_qj) + (-1 * x0 * x138);
	const GEN_FLT x187 = ((x177 + x153) * x31) + (x30 * (x137 + (-1 * x184) + x128)) + (x27 * (x186 + x44));
	const GEN_FLT x188 = (x123 * x187) + (x94 * x185);
	const GEN_FLT x189 = x65 * ((x54 * x182) + (-1 * x162 * (x188 + (x182 * x146))));
	const GEN_FLT x190 = x58 * x189;
	const GEN_FLT x191 = (x55 * (x190 + (-1 * x57 * x189))) + (x59 * x189);
	const GEN_FLT x192 = (x55 * x191) + (x61 * x189);
	const GEN_FLT x193 = (x75 * x182) + (-1 * x167 * x188);
	const GEN_FLT x194 = ((x170 * x185) + (-1 * x169 * x187)) * x171;
	const GEN_FLT x195 = x194 + (-1 * x82 * x193);
	const GEN_FLT x196 =
		x103 * ((x111 * x189) + x193 + (x99 * x192) +
				(-1 * x93 *
				 ((-1 * x89 * x195) +
				  (-1 * x80 *
				   ((x63 * x189) + (x55 * x192) + (x64 * x189) +
					(x55 * (x192 + (x55 * ((x60 * x189) + x191 + (x55 * ((-1 * x70 * x189) + (x56 * x189) + x190)))) +
							(x62 * x189))))))) +
				(x101 * x195));
	const GEN_FLT x197 = x186 + x34;
	const GEN_FLT x198 = x0 * x130;
	const GEN_FLT x199 = ((x197 + x147) * x27) + (x30 * (x156 + (-1 * x157) + x198)) + (x31 * (x176 + x33));
	const GEN_FLT x200 = x158 + x12;
	const GEN_FLT x201 = (x30 * (x149 + x33)) + (x31 * (x137 + x157 + (-1 * x198))) + ((x200 + x181) * x27);
	const GEN_FLT x202 = lh_qk * lh_qk * lh_qk;
	const GEN_FLT x203 =
		((x200 + x183) * x30) + ((x197 + x144) * x31) + (x27 * (x33 + (2 * x148) + (x202 * x127) + (-1 * x202 * x125)));
	const GEN_FLT x204 = (x203 * x123) + (x94 * x201);
	const GEN_FLT x205 = x65 * ((x54 * x199) + (-1 * x162 * (x204 + (x199 * x146))));
	const GEN_FLT x206 = (x75 * x199) + (-1 * x204 * x167);
	const GEN_FLT x207 = ((x201 * x170) + (-1 * x203 * x169)) * x171;
	const GEN_FLT x208 = x85 * (x207 + (-1 * x82 * x206));
	const GEN_FLT x209 = x58 * x205;
	const GEN_FLT x210 = (x55 * (x209 + (-1 * x57 * x205))) + (x59 * x205);
	const GEN_FLT x211 = (x55 * x210) + (x61 * x205);
	const GEN_FLT x212 =
		x103 * (x206 +
				(-1 * x93 *
				 ((-1 * x88 * x208) +
				  (-1 * x80 *
				   ((x63 * x205) + (x64 * x205) + (x55 * x211) +
					(x55 * (x211 + (x55 * (x210 + (x60 * x205) + (x55 * ((-1 * x70 * x205) + x209 + (x56 * x205))))) +
							(x62 * x205))))))) +
				(x99 * x211) + (x205 * x111) + (x208 * x100));
	out[0] = (-1 * x105 * ((-1 * x83) + x104)) + x83 + (-1 * x104);
	out[1] = (-1 * x105 * x112) + (-1 * x112);
	out[2] = x121 + (-1 * x124) + (-1 * (x120 + x124) * x105);
	out[3] = x172 + (-1 * x174) + (-1 * ((-1 * x172) + x174) * x105);
	out[4] = x194 + (-1 * x196) + (-1 * ((-1 * x194) + x196) * x105);
	out[5] = x207 + (-1 * x212) + (-1 * ((-1 * x207) + x212) * x105);
}

// Jacobian of reproject_axis_x_gen2 wrt [phase_0, tilt_0, curve_0, gibPhase_0, gibMag_0, ogeeMag_0, ogeePhase_0]
static inline void gen_reproject_axis_x_gen2_jac_bsc0_axis_angle(FLT *out, const LinmathAxisAnglePose *obj_p,
																 const FLT *sensor_pt, const LinmathAxisAnglePose *lh_p,
																 const BaseStationCal *bsc0) {
	const GEN_FLT obj_px = (*obj_p).Pos[0];
	const GEN_FLT obj_py = (*obj_p).Pos[1];
	const GEN_FLT obj_pz = (*obj_p).Pos[2];
	const GEN_FLT obj_qi = (*obj_p).AxisAngleRot[0];
	const GEN_FLT obj_qj = (*obj_p).AxisAngleRot[1];
	const GEN_FLT obj_qk = (*obj_p).AxisAngleRot[2];
	const GEN_FLT sensor_x = sensor_pt[0];
	const GEN_FLT sensor_y = sensor_pt[1];
	const GEN_FLT sensor_z = sensor_pt[2];
	const GEN_FLT lh_px = (*lh_p).Pos[0];
	const GEN_FLT lh_py = (*lh_p).Pos[1];
	const GEN_FLT lh_pz = (*lh_p).Pos[2];
	const GEN_FLT lh_qi = (*lh_p).AxisAngleRot[0];
	const GEN_FLT lh_qj = (*lh_p).AxisAngleRot[1];
	const GEN_FLT lh_qk = (*lh_p).AxisAngleRot[2];
	const GEN_FLT phase_0 = (*bsc0).phase;
	const GEN_FLT tilt_0 = (*bsc0).tilt;
	const GEN_FLT curve_0 = (*bsc0).curve;
	const GEN_FLT gibPhase_0 = (*bsc0).gibpha;
	const GEN_FLT gibMag_0 = (*bsc0).gibmag;
	const GEN_FLT ogeeMag_0 = (*bsc0).ogeephase;
	const GEN_FLT ogeePhase_0 = (*bsc0).ogeemag;
	const GEN_FLT x0 = obj_qk * obj_qk;
	const GEN_FLT x1 = obj_qi * obj_qi;
	const GEN_FLT x2 = obj_qj * obj_qj;
	const GEN_FLT x3 = 1e-10 + x2 + x0 + x1;
	const GEN_FLT x4 = sqrt(x3);
	const GEN_FLT x5 = cos(x4);
	const GEN_FLT x6 = (1. / x3) * (1 + (-1 * x5));
	const GEN_FLT x7 = (1. / x4) * sin(x4);
	const GEN_FLT x8 = x7 * obj_qj;
	const GEN_FLT x9 = x6 * obj_qk;
	const GEN_FLT x10 = x9 * obj_qi;
	const GEN_FLT x11 = x7 * obj_qi;
	const GEN_FLT x12 = x9 * obj_qj;
	const GEN_FLT x13 =
		((x12 + x11) * sensor_y) + obj_pz + ((x10 + (-1 * x8)) * sensor_x) + ((x5 + (x0 * x6)) * sensor_z);
	const GEN_FLT x14 = lh_qk * lh_qk;
	const GEN_FLT x15 = lh_qi * lh_qi;
	const GEN_FLT x16 = lh_qj * lh_qj;
	const GEN_FLT x17 = 1e-10 + x14 + x16 + x15;
	const GEN_FLT x18 = sqrt(x17);
	const GEN_FLT x19 = cos(x18);
	const GEN_FLT x20 = (1. / x17) * (1 + (-1 * x19));
	const GEN_FLT x21 = x7 * obj_qk;
	const GEN_FLT x22 = x6 * obj_qj * obj_qi;
	const GEN_FLT x23 =
		((x22 + (-1 * x21)) * sensor_y) + ((x10 + x8) * sensor_z) + ((x5 + (x1 * x6)) * sensor_x) + obj_px;
	const GEN_FLT x24 = (1. / x18) * sin(x18);
	const GEN_FLT x25 = x24 * lh_qj;
	const GEN_FLT x26 = x20 * lh_qk * lh_qi;
	const GEN_FLT x27 =
		((x5 + (x2 * x6)) * sensor_y) + ((x22 + x21) * sensor_x) + obj_py + ((x12 + (-1 * x11)) * sensor_z);
	const GEN_FLT x28 = x24 * lh_qi;
	const GEN_FLT x29 = x20 * lh_qj;
	const GEN_FLT x30 = x29 * lh_qk;
	const GEN_FLT x31 = ((x30 + x28) * x27) + ((x26 + (-1 * x25)) * x23) + lh_pz + (x13 * (x19 + (x20 * x14)));
	const GEN_FLT x32 = x24 * lh_qk;
	const GEN_FLT x33 = x29 * lh_qi;
	const GEN_FLT x34 = ((x33 + (-1 * x32)) * x27) + (x23 * (x19 + (x20 * x15))) + lh_px + ((x26 + x25) * x13);
	const GEN_FLT x35 = atan2(-1 * x31, x34);
	const GEN_FLT x36 = 0.523598775598299 + tilt_0;
	const GEN_FLT x37 = tan(x36);
	const GEN_FLT x38 = (x27 * (x19 + (x20 * x16))) + ((x33 + x32) * x23) + lh_py + ((x30 + (-1 * x28)) * x13);
	const GEN_FLT x39 = (x34 * x34) + (x31 * x31);
	const GEN_FLT x40 = x38 * (1. / sqrt(x39));
	const GEN_FLT x41 = x40 * x37;
	const GEN_FLT x42 = (-1 * asin(x41)) + x35 + ogeeMag_0;
	const GEN_FLT x43 = sin(x42);
	const GEN_FLT x44 = (x43 * ogeePhase_0) + curve_0;
	const GEN_FLT x45 = cos(x36);
	const GEN_FLT x46 = x38 * x38;
	const GEN_FLT x47 = x39 + x46;
	const GEN_FLT x48 = (1. / sqrt(x47)) * x38;
	const GEN_FLT x49 = asin((1. / x45) * x48);
	const GEN_FLT x50 = 8.0108022e-06 * x49;
	const GEN_FLT x51 = -8.0108022e-06 + (-1 * x50);
	const GEN_FLT x52 = 0.0028679863 + (x51 * x49);
	const GEN_FLT x53 = 5.3685255e-06 + (x52 * x49);
	const GEN_FLT x54 = 0.0076069798 + (x53 * x49);
	const GEN_FLT x55 = x49 * x49;
	const GEN_FLT x56 = sin(x36);
	const GEN_FLT x57 = x54 * x49;
	const GEN_FLT x58 = -8.0108022e-06 + (-1.60216044e-05 * x49);
	const GEN_FLT x59 = x52 + (x58 * x49);
	const GEN_FLT x60 = x53 + (x59 * x49);
	const GEN_FLT x61 = x54 + (x60 * x49);
	const GEN_FLT x62 = (x61 * x49) + x57;
	const GEN_FLT x63 = x62 * x44;
	const GEN_FLT x64 = x63 * x56;
	const GEN_FLT x65 = x45 + (-1 * x64);
	const GEN_FLT x66 = 1. / x65;
	const GEN_FLT x67 = x66 * x55;
	const GEN_FLT x68 = x67 * x54;
	const GEN_FLT x69 = x41 + (x68 * x44);
	const GEN_FLT x70 = 1. / sqrt(1 + (-1 * (x69 * x69)));
	const GEN_FLT x71 = cos(x42) * ogeePhase_0;
	const GEN_FLT x72 = x37 * x37;
	const GEN_FLT x73 = x40 * (1 + x72);
	const GEN_FLT x74 = x73 * (1. / sqrt(1 + (-1 * x72 * x46 * (1. / x39))));
	const GEN_FLT x75 = 1. / (x45 * x45);
	const GEN_FLT x76 = x75 * x48 * (1. / sqrt(1 + (-1 * x75 * x46 * (1. / x47))));
	const GEN_FLT x77 = x76 * x56;
	const GEN_FLT x78 = x77 * x51;
	const GEN_FLT x79 = (x49 * (x78 + (-1 * x77 * x50))) + (x77 * x52);
	const GEN_FLT x80 = (x79 * x49) + (x77 * x53);
	const GEN_FLT x81 = x56 * x44;
	const GEN_FLT x82 = (1. / (x65 * x65)) * x54 * x55;
	const GEN_FLT x83 = x71 * x68;
	const GEN_FLT x84 =
		x70 *
		((-1 * x83 * x74) + (x80 * x67 * x44) + (2 * x81 * x76 * x66 * x57) +
		 (-1 * x82 * x44 *
		  ((-1 * x81 *
			((x77 * x54) + (x77 * x61) +
			 (x49 * (x80 + (x49 * ((x77 * x59) + x79 + (x49 * ((-2.40324066e-05 * x77 * x49) + x78 + (x77 * x58))))) +
					 (x77 * x60))) +
			 (x80 * x49))) +
		   (-1 * x63 * x45) + (x71 * x74 * x62 * x56) + (-1 * x56))) +
		 x73);
	const GEN_FLT x85 = asin(x69) + (-1 * gibPhase_0) + (-1 * x35);
	const GEN_FLT x86 = cos(x85) * gibMag_0;
	const GEN_FLT x87 = x82 * x64;
	const GEN_FLT x88 = (x68 + x87) * x70;
	const GEN_FLT x89 = x70 * (x83 + (x87 * x71));
	const GEN_FLT x90 = ((x68 * x43) + (x87 * x43)) * x70;
	out[0] = -1;
	out[1] = (-1 * x84 * x86) + (-1 * x84);
	out[2] = (-1 * x88 * x86) + (-1 * x88);
	out[3] = x86;
	out[4] = -1 * sin(x85);
	out[5] = (-1 * x89 * x86) + (-1 * x89);
	out[6] = (-1 * x86 * x90) + (-1 * x90);
}

static inline FLT gen_reproject_axis_y_gen2_axis_angle(const LinmathAxisAnglePose *obj_p, const FLT *sensor_pt,
													   const LinmathAxisAnglePose *lh_p, const BaseStationCal *bsc1) {
	const GEN_FLT obj_px = (*obj_p).Pos[0];
	const GEN_FLT obj_py = (*obj_p).Pos[1];
	const GEN_FLT obj_pz = (*obj_p).Pos[2];
	const GEN_FLT obj_qi = (*obj_p).AxisAngleRot[0];
	const GEN_FLT obj_qj = (*obj_p).AxisAngleRot[1];
	const GEN_FLT obj_qk = (*obj_p).AxisAngleRot[2];
	const GEN_FLT sensor_x = sensor_pt[0];
	const GEN_FLT sensor_y = sensor_pt[1];
	const GEN_FLT sensor_z = sensor_pt[2];
	const GEN_FLT lh_px = (*lh_p).Pos[0];
	const GEN_FLT lh_py = (*lh_p).Pos[1];
	const GEN_FLT lh_pz = (*lh_p).Pos[2];
	const GEN_FLT lh_qi = (*lh_p).AxisAngleRot[0];
	const GEN_FLT lh_qj = (*lh_p).AxisAngleRot[1];
	const GEN_FLT lh_qk = (*lh_p).AxisAngleRot[2];
	const GEN_FLT phase_1 = (*bsc1).phase;
	const GEN_FLT tilt_1 = (*bsc1).tilt;
	const GEN_FLT curve_1 = (*bsc1).curve;
	const GEN_FLT gibPhase_1 = (*bsc1).gibpha;
	const GEN_FLT gibMag_1 = (*bsc1).gibmag;
	const GEN_FLT ogeeMag_1 = (*bsc1).ogeephase;
	const GEN_FLT ogeePhase_1 = (*bsc1).ogeemag;
	const GEN_FLT x0 = obj_qk * obj_qk;
	const GEN_FLT x1 = obj_qi * obj_qi;
	const GEN_FLT x2 = obj_qj * obj_qj;
	const GEN_FLT x3 = 1e-10 + x2 + x0 + x1;
	const GEN_FLT x4 = sqrt(x3);
	const GEN_FLT x5 = cos(x4);
	const GEN_FLT x6 = (1. / x3) * (1 + (-1 * x5));
	const GEN_FLT x7 = (1. / x4) * sin(x4);
	const GEN_FLT x8 = x7 * obj_qj;
	const GEN_FLT x9 = x6 * obj_qk;
	const GEN_FLT x10 = x9 * obj_qi;
	const GEN_FLT x11 = x7 * obj_qi;
	const GEN_FLT x12 = x9 * obj_qj;
	const GEN_FLT x13 =
		((x12 + x11) * sensor_y) + obj_pz + ((x10 + (-1 * x8)) * sensor_x) + ((x5 + (x0 * x6)) * sensor_z);
	const GEN_FLT x14 = lh_qk * lh_qk;
	const GEN_FLT x15 = lh_qi * lh_qi;
	const GEN_FLT x16 = lh_qj * lh_qj;
	const GEN_FLT x17 = 1e-10 + x14 + x16 + x15;
	const GEN_FLT x18 = sqrt(x17);
	const GEN_FLT x19 = cos(x18);
	const GEN_FLT x20 = (1. / x17) * (1 + (-1 * x19));
	const GEN_FLT x21 = x7 * obj_qk;
	const GEN_FLT x22 = x6 * obj_qj * obj_qi;
	const GEN_FLT x23 =
		((x22 + (-1 * x21)) * sensor_y) + ((x10 + x8) * sensor_z) + ((x5 + (x1 * x6)) * sensor_x) + obj_px;
	const GEN_FLT x24 = (1. / x18) * sin(x18);
	const GEN_FLT x25 = x24 * lh_qj;
	const GEN_FLT x26 = x20 * lh_qk * lh_qi;
	const GEN_FLT x27 =
		((x5 + (x2 * x6)) * sensor_y) + ((x22 + x21) * sensor_x) + obj_py + ((x12 + (-1 * x11)) * sensor_z);
	const GEN_FLT x28 = x24 * lh_qi;
	const GEN_FLT x29 = x20 * lh_qj;
	const GEN_FLT x30 = x29 * lh_qk;
	const GEN_FLT x31 = ((x30 + x28) * x27) + ((x26 + (-1 * x25)) * x23) + lh_pz + (x13 * (x19 + (x20 * x14)));
	const GEN_FLT x32 = x24 * lh_qk;
	const GEN_FLT x33 = x29 * lh_qi;
	const GEN_FLT x34 = ((x33 + (-1 * x32)) * x27) + (x23 * (x19 + (x20 * x15))) + lh_px + ((x26 + x25) * x13);
	const GEN_FLT x35 = atan2(-1 * x31, x34);
	const GEN_FLT x36 = (x27 * (x19 + (x20 * x16))) + ((x33 + x32) * x23) + lh_py + ((x30 + (-1 * x28)) * x13);
	const GEN_FLT x37 = 0.523598775598299 + (-1 * tilt_1);
	const GEN_FLT x38 = (x34 * x34) + (x31 * x31);
	const GEN_FLT x39 = -1 * x36 * (1. / sqrt(x38)) * tan(x37);
	const GEN_FLT x40 = (sin((-1 * asin(x39)) + ogeeMag_1 + x35) * ogeePhase_1) + curve_1;
	const GEN_FLT x41 = cos(x37);
	const GEN_FLT x42 = asin((1. / x41) * x36 * (1. / sqrt(x38 + (x36 * x36))));
	const GEN_FLT x43 = 0.0028679863 + (x42 * (-8.0108022e-06 + (-8.0108022e-06 * x42)));
	const GEN_FLT x44 = 5.3685255e-06 + (x42 * x43);
	const GEN_FLT x45 = 0.0076069798 + (x42 * x44);
	const GEN_FLT x46 = asin(
		x39 +
		(x40 * (x42 * x42) * x45 *
		 (1. /
		  (x41 + (x40 * sin(x37) *
				  ((x42 * (x45 + (x42 * (x44 + (x42 * (x43 + (x42 * (-8.0108022e-06 + (-1.60216044e-05 * x42))))))))) +
				   (x42 * x45)))))));
	return -1.5707963267949 + (-1 * x46) + (-1 * phase_1) +
		   (-1 * sin((-1 * x35) + x46 + (-1 * gibPhase_1)) * gibMag_1) + x35;
}

// Jacobian of reproject_axis_y_gen2 wrt [obj_px, obj_py, obj_pz, obj_qi, obj_qj, obj_qk]
static inline void gen_reproject_axis_y_gen2_jac_obj_p_axis_angle(FLT *out, const LinmathAxisAnglePose *obj_p,
																  const FLT *sensor_pt,
																  const LinmathAxisAnglePose *lh_p,
																  const BaseStationCal *bsc1) {
	const GEN_FLT obj_px = (*obj_p).Pos[0];
	const GEN_FLT obj_py = (*obj_p).Pos[1];
	const GEN_FLT obj_pz = (*obj_p).Pos[2];
	const GEN_FLT obj_qi = (*obj_p).AxisAngleRot[0];
	const GEN_FLT obj_qj = (*obj_p).AxisAngleRot[1];
	const GEN_FLT obj_qk = (*obj_p).AxisAngleRot[2];
	const GEN_FLT sensor_x = sensor_pt[0];
	const GEN_FLT sensor_y = sensor_pt[1];
	const GEN_FLT sensor_z = sensor_pt[2];
	const GEN_FLT lh_px = (*lh_p).Pos[0];
	const GEN_FLT lh_py = (*lh_p).Pos[1];
	const GEN_FLT lh_pz = (*lh_p).Pos[2];
	const GEN_FLT lh_qi = (*lh_p).AxisAngleRot[0];
	const GEN_FLT lh_qj = (*lh_p).AxisAngleRot[1];
	const GEN_FLT lh_qk = (*lh_p).AxisAngleRot[2];
	const GEN_FLT phase_1 = (*bsc1).phase;
	const GEN_FLT tilt_1 = (*bsc1).tilt;
	const GEN_FLT curve_1 = (*bsc1).curve;
	const GEN_FLT gibPhase_1 = (*bsc1).gibpha;
	const GEN_FLT gibMag_1 = (*bsc1).gibmag;
	const GEN_FLT ogeeMag_1 = (*bsc1).ogeephase;
	const GEN_FLT ogeePhase_1 = (*bsc1).ogeemag;
	const GEN_FLT x0 = lh_qk * lh_qk;
	const GEN_FLT x1 = lh_qi * lh_qi;
	const GEN_FLT x2 = lh_qj * lh_qj;
	const GEN_FLT x3 = 1e-10 + x2 + x0 + x1;
	const GEN_FLT x4 = sqrt(x3);
	const GEN_FLT x5 = (1. / x4) * sin(x4);
	const GEN_FLT x6 = x5 * lh_qi;
	const GEN_FLT x7 = cos(x4);
	const GEN_FLT x8 = (1. / x3) * (1 + (-1 * x7));
	const GEN_FLT x9 = x8 * lh_qk * lh_qj;
	const GEN_FLT x10 = x9 + (-1 * x6);
	const GEN_FLT x11 = obj_qk * obj_qk;
	const GEN_FLT x12 = obj_qi * obj_qi;
	const GEN_FLT x13 = obj_qj * obj_qj;
	const GEN_FLT x14 = 1e-10 + x13 + x11 + x12;
	const GEN_FLT x15 = 1. / x14;
	const GEN_FLT x16 = sqrt(x14);
	const GEN_FLT x17 = cos(x16);
	const GEN_FLT x18 = 1 + (-1 * x17);
	const GEN_FLT x19 = x15 * x18;
	const GEN_FLT x20 = sin(x16);
	const GEN_FLT x21 = x20 * (1. / x16);
	const GEN_FLT x22 = x21 * obj_qj;
	const GEN_FLT x23 = -1 * x22;
	const GEN_FLT x24 = x19 * obj_qi;
	const GEN_FLT x25 = x24 * obj_qk;
	const GEN_FLT x26 = x21 * obj_qi;
	const GEN_FLT x27 = x19 * obj_qj;
	const GEN_FLT x28 = x27 * obj_qk;
	const GEN_FLT x29 = ((x28 + x26) * sensor_y) + ((x25 + x23) * sensor_x) + obj_pz + ((x17 + (x11 * x19)) * sensor_z);
	const GEN_FLT x30 = x21 * obj_qk;
	const GEN_FLT x31 = -1 * x30;
	const GEN_FLT x32 = x27 * obj_qi;
	const GEN_FLT x33 = ((x32 + x31) * sensor_y) + ((x25 + x22) * sensor_z) + ((x17 + (x12 * x19)) * sensor_x) + obj_px;
	const GEN_FLT x34 = x5 * lh_qk;
	const GEN_FLT x35 = x8 * lh_qi;
	const GEN_FLT x36 = x35 * lh_qj;
	const GEN_FLT x37 = x36 + x34;
	const GEN_FLT x38 = -1 * x26;
	const GEN_FLT x39 = ((x17 + (x13 * x19)) * sensor_y) + ((x32 + x30) * sensor_x) + obj_py + ((x28 + x38) * sensor_z);
	const GEN_FLT x40 = x7 + (x2 * x8);
	const GEN_FLT x41 = (x40 * x39) + (x33 * x37) + lh_py + (x29 * x10);
	const GEN_FLT x42 = 0.523598775598299 + (-1 * tilt_1);
	const GEN_FLT x43 = cos(x42);
	const GEN_FLT x44 = 1. / x43;
	const GEN_FLT x45 = x41 * x41;
	const GEN_FLT x46 = x7 + (x0 * x8);
	const GEN_FLT x47 = x5 * lh_qj;
	const GEN_FLT x48 = x35 * lh_qk;
	const GEN_FLT x49 = x48 + (-1 * x47);
	const GEN_FLT x50 = x9 + x6;
	const GEN_FLT x51 = (x50 * x39) + (x49 * x33) + lh_pz + (x46 * x29);
	const GEN_FLT x52 = x48 + x47;
	const GEN_FLT x53 = x7 + (x1 * x8);
	const GEN_FLT x54 = x36 + (-1 * x34);
	const GEN_FLT x55 = (x54 * x39) + (x53 * x33) + lh_px + (x52 * x29);
	const GEN_FLT x56 = x55 * x55;
	const GEN_FLT x57 = x56 + (x51 * x51);
	const GEN_FLT x58 = x57 + x45;
	const GEN_FLT x59 = (1. / sqrt(x58)) * x44;
	const GEN_FLT x60 = asin(x59 * x41);
	const GEN_FLT x61 = 8.0108022e-06 * x60;
	const GEN_FLT x62 = -8.0108022e-06 + (-1 * x61);
	const GEN_FLT x63 = 0.0028679863 + (x60 * x62);
	const GEN_FLT x64 = 5.3685255e-06 + (x60 * x63);
	const GEN_FLT x65 = 0.0076069798 + (x60 * x64);
	const GEN_FLT x66 = x60 * x60;
	const GEN_FLT x67 = atan2(-1 * x51, x55);
	const GEN_FLT x68 = tan(x42);
	const GEN_FLT x69 = x68 * (1. / sqrt(x57));
	const GEN_FLT x70 = -1 * x69 * x41;
	const GEN_FLT x71 = (-1 * asin(x70)) + ogeeMag_1 + x67;
	const GEN_FLT x72 = (sin(x71) * ogeePhase_1) + curve_1;
	const GEN_FLT x73 = x60 * x65;
	const GEN_FLT x74 = -8.0108022e-06 + (-1.60216044e-05 * x60);
	const GEN_FLT x75 = x63 + (x74 * x60);
	const GEN_FLT x76 = x64 + (x75 * x60);
	const GEN_FLT x77 = x65 + (x76 * x60);
	const GEN_FLT x78 = (x77 * x60) + x73;
	const GEN_FLT x79 = sin(x42);
	const GEN_FLT x80 = x72 * x79;
	const GEN_FLT x81 = x43 + (x80 * x78);
	const GEN_FLT x82 = 1. / x81;
	const GEN_FLT x83 = x82 * x72;
	const GEN_FLT x84 = x83 * x66;
	const GEN_FLT x85 = x70 + (x84 * x65);
	const GEN_FLT x86 = 1. / sqrt(1 + (-1 * (x85 * x85)));
	const GEN_FLT x87 = 1. / sqrt(1 + (-1 * (1. / x58) * (1. / (x43 * x43)) * x45));
	const GEN_FLT x88 = 2 * x41;
	const GEN_FLT x89 = 2 * x55;
	const GEN_FLT x90 = 2 * x51;
	const GEN_FLT x91 = (x90 * x49) + (x89 * x53);
	const GEN_FLT x92 = 1.0 / 2.0 * x41;
	const GEN_FLT x93 = (1. / (x58 * sqrt(x58))) * x92 * x44;
	const GEN_FLT x94 = (x59 * x37) + (-1 * x93 * (x91 + (x88 * x37)));
	const GEN_FLT x95 = x87 * x94;
	const GEN_FLT x96 = x62 * x95;
	const GEN_FLT x97 = (x63 * x95) + (x60 * (x96 + (-1 * x61 * x95)));
	const GEN_FLT x98 = (x64 * x95) + (x60 * x97);
	const GEN_FLT x99 = 1. / x57;
	const GEN_FLT x100 = 1. / sqrt(1 + (-1 * (x68 * x68) * x99 * x45));
	const GEN_FLT x101 = x68 * (1. / (x57 * sqrt(x57))) * x92;
	const GEN_FLT x102 = (-1 * x69 * x37) + (x91 * x101);
	const GEN_FLT x103 = 1. / x55;
	const GEN_FLT x104 = x51 * (1. / x56);
	const GEN_FLT x105 = x56 * x99;
	const GEN_FLT x106 = ((x53 * x104) + (-1 * x49 * x103)) * x105;
	const GEN_FLT x107 = x106 + (-1 * x100 * x102);
	const GEN_FLT x108 = cos(x71) * ogeePhase_1;
	const GEN_FLT x109 = x79 * x78;
	const GEN_FLT x110 = x109 * x108;
	const GEN_FLT x111 = x87 * x77;
	const GEN_FLT x112 = 2.40324066e-05 * x60;
	const GEN_FLT x113 = x65 * x66;
	const GEN_FLT x114 = (1. / (x81 * x81)) * x72 * x113;
	const GEN_FLT x115 = x82 * x113;
	const GEN_FLT x116 = x108 * x115;
	const GEN_FLT x117 = 2 * x83 * x73;
	const GEN_FLT x118 =
		x86 * ((x95 * x117) + x102 + (x107 * x116) + (x84 * x98) +
			   (-1 * x114 *
				((x80 * ((x65 * x95) + (x94 * x111) + (x60 * x98) +
						 (x60 * (x98 + (x60 * (x97 + (x75 * x95) + (x60 * (x96 + (-1 * x95 * x112) + (x74 * x95))))) +
								 (x76 * x95))))) +
				 (x107 * x110))));
	const GEN_FLT x119 = cos((-1 * asin(x85)) + x67 + gibPhase_1) * gibMag_1;
	const GEN_FLT x120 = (x50 * x90) + (x89 * x54);
	const GEN_FLT x121 = (-1 * x69 * x40) + (x101 * x120);
	const GEN_FLT x122 = ((x54 * x104) + (-1 * x50 * x103)) * x105;
	const GEN_FLT x123 = x108 * (x122 + (-1 * x100 * x121));
	const GEN_FLT x124 = (x59 * x40) + (-1 * x93 * (x120 + (x88 * x40)));
	const GEN_FLT x125 = x87 * x124;
	const GEN_FLT x126 = x62 * x125;
	const GEN_FLT x127 = (x63 * x125) + (x60 * (x126 + (-1 * x61 * x125)));
	const GEN_FLT x128 = (x64 * x125) + (x60 * x127);
	const GEN_FLT x129 =
		x86 *
		(x121 + (x117 * x125) +
		 (-1 * x114 *
		  ((x80 * ((x65 * x125) + (x60 * x128) + (x111 * x124) +
				   (x60 * (x128 + (x60 * (x127 + (x75 * x125) + (x60 * ((-1 * x112 * x125) + x126 + (x74 * x125))))) +
						   (x76 * x125))))) +
		   (x109 * x123))) +
		 (x115 * x123) + (x84 * x128));
	const GEN_FLT x130 = (x90 * x46) + (x89 * x52);
	const GEN_FLT x131 = (x59 * x10) + (-1 * x93 * (x130 + (x88 * x10)));
	const GEN_FLT x132 = x87 * x131;
	const GEN_FLT x133 = x62 * x132;
	const GEN_FLT x134 = (x63 * x132) + (x60 * (x133 + (-1 * x61 * x132)));
	const GEN_FLT x135 = (x64 * x132) + (x60 * x134);
	const GEN_FLT x136 = (-1 * x69 * x10) + (x101 * x130);
	const GEN_FLT x137 = ((x52 * x104) + (-1 * x46 * x103)) * x105;
	const GEN_FLT x138 = x137 + (-1 * x100 * x136);
	const GEN_FLT x139 =
		x86 *
		((x117 * x132) + x136 + (x116 * x138) + (x84 * x135) +
		 (-1 * x114 *
		  ((x80 * ((x65 * x132) + (x60 * x135) + (x111 * x131) +
				   (x60 * (x135 + (x60 * (x134 + (x75 * x132) + (x60 * ((-1 * x112 * x132) + x133 + (x74 * x132))))) +
						   (x76 * x132))))) +
		   (x110 * x138))));
	const GEN_FLT x140 = 2 * (1. / (x14 * x14)) * x18;
	const GEN_FLT x141 = x140 * obj_qi;
	const GEN_FLT x142 = x20 * (1. / (x14 * sqrt(x14)));
	const GEN_FLT x143 = x13 * x142;
	const GEN_FLT x144 = (x143 * obj_qi) + (-1 * x13 * x141);
	const GEN_FLT x145 = x15 * x17;
	const GEN_FLT x146 = x12 * x145;
	const GEN_FLT x147 = x12 * x142;
	const GEN_FLT x148 = obj_qj * obj_qi;
	const GEN_FLT x149 = x140 * obj_qk;
	const GEN_FLT x150 = x142 * x148;
	const GEN_FLT x151 = (x150 * obj_qk) + (-1 * x148 * x149);
	const GEN_FLT x152 = x151 + (-1 * x21);
	const GEN_FLT x153 = x142 * obj_qk;
	const GEN_FLT x154 = x153 * obj_qi;
	const GEN_FLT x155 = x145 * obj_qk;
	const GEN_FLT x156 = x155 * obj_qi;
	const GEN_FLT x157 = x156 + (-1 * x154);
	const GEN_FLT x158 = x12 * x140;
	const GEN_FLT x159 = (x147 * obj_qj) + (-1 * x158 * obj_qj);
	const GEN_FLT x160 = x159 + x27;
	const GEN_FLT x161 =
		((x160 + x157) * sensor_x) + ((x144 + x38) * sensor_y) + ((x152 + (-1 * x146) + x147) * sensor_z);
	const GEN_FLT x162 = x11 * x142;
	const GEN_FLT x163 = (x162 * obj_qi) + (-1 * x11 * x141);
	const GEN_FLT x164 = x151 + x21;
	const GEN_FLT x165 = x19 * obj_qk;
	const GEN_FLT x166 = (x147 * obj_qk) + (-1 * x158 * obj_qk);
	const GEN_FLT x167 = x166 + x165;
	const GEN_FLT x168 = x145 * x148;
	const GEN_FLT x169 = (-1 * x168) + x150;
	const GEN_FLT x170 =
		((x169 + x167) * sensor_x) + ((x163 + x38) * sensor_z) + ((x164 + x146 + (-1 * x147)) * sensor_y);
	const GEN_FLT x171 = obj_qi * obj_qi * obj_qi;
	const GEN_FLT x172 = (-1 * x156) + x154;
	const GEN_FLT x173 = x168 + (-1 * x150);
	const GEN_FLT x174 = ((x167 + x173) * sensor_z) +
						 (((2 * x24) + x38 + (x171 * x142) + (-1 * x171 * x140)) * sensor_x) +
						 ((x160 + x172) * sensor_y);
	const GEN_FLT x175 = (x49 * x174) + (x50 * x161) + (x46 * x170);
	const GEN_FLT x176 = (x53 * x174) + (x54 * x161) + (x52 * x170);
	const GEN_FLT x177 = ((x104 * x176) + (-1 * x103 * x175)) * x105;
	const GEN_FLT x178 = (x37 * x174) + (x10 * x170) + (x40 * x161);
	const GEN_FLT x179 = (x90 * x175) + (x89 * x176);
	const GEN_FLT x180 = (x59 * x178) + (-1 * x93 * (x179 + (x88 * x178)));
	const GEN_FLT x181 = x87 * x180;
	const GEN_FLT x182 = x62 * x181;
	const GEN_FLT x183 = (x63 * x181) + (x60 * (x182 + (-1 * x61 * x181)));
	const GEN_FLT x184 = (x64 * x181) + (x60 * x183);
	const GEN_FLT x185 = (-1 * x69 * x178) + (x101 * x179);
	const GEN_FLT x186 = x177 + (-1 * x100 * x185);
	const GEN_FLT x187 =
		x86 *
		((x117 * x181) + x185 + (x116 * x186) + (x84 * x184) +
		 (-1 * x114 *
		  ((x80 * ((x65 * x181) + (x60 * x184) + (x111 * x180) +
				   (x60 * (x184 + (x60 * ((x75 * x181) + x183 + (x60 * (x182 + (-1 * x112 * x181) + (x74 * x181))))) +
						   (x76 * x181))))) +
		   (x110 * x186))));
	const GEN_FLT x188 = obj_qj * obj_qj * obj_qj;
	const GEN_FLT x189 = (x143 * obj_qk) + (-1 * x13 * x149);
	const GEN_FLT x190 = x189 + x165;
	const GEN_FLT x191 = x144 + x24;
	const GEN_FLT x192 = x153 * obj_qj;
	const GEN_FLT x193 = x155 * obj_qj;
	const GEN_FLT x194 = x193 + (-1 * x192);
	const GEN_FLT x195 = ((x194 + x191) * sensor_x) +
						 (((2 * x27) + (x188 * x142) + x23 + (-1 * x188 * x140)) * sensor_y) +
						 ((x169 + x190) * sensor_z);
	const GEN_FLT x196 = (x162 * obj_qj) + (-1 * x11 * x140 * obj_qj);
	const GEN_FLT x197 = x13 * x145;
	const GEN_FLT x198 =
		((x173 + x190) * sensor_y) + ((x152 + (-1 * x197) + x143) * sensor_x) + ((x196 + x23) * sensor_z);
	const GEN_FLT x199 = (-1 * x193) + x192;
	const GEN_FLT x200 =
		((x164 + x197 + (-1 * x143)) * sensor_z) + ((x199 + x191) * sensor_y) + ((x159 + x23) * sensor_x);
	const GEN_FLT x201 = (x53 * x200) + (x54 * x195) + (x52 * x198);
	const GEN_FLT x202 = (x49 * x200) + (x50 * x195) + (x46 * x198);
	const GEN_FLT x203 = (x90 * x202) + (x89 * x201);
	const GEN_FLT x204 = (x40 * x195) + (x37 * x200) + (x10 * x198);
	const GEN_FLT x205 = (-1 * x69 * x204) + (x203 * x101);
	const GEN_FLT x206 = ((x201 * x104) + (-1 * x202 * x103)) * x105;
	const GEN_FLT x207 = x206 + (-1 * x205 * x100);
	const GEN_FLT x208 = (x59 * x204) + (-1 * x93 * (x203 + (x88 * x204)));
	const GEN_FLT x209 = x87 * x208;
	const GEN_FLT x210 = x62 * x209;
	const GEN_FLT x211 = (x63 * x209) + (x60 * (x210 + (-1 * x61 * x209)));
	const GEN_FLT x212 = (x64 * x209) + (x60 * x211);
	const GEN_FLT x213 =
		x86 *
		((x209 * x117) + (x84 * x212) + x205 +
		 (-1 * x114 *
		  ((x80 * ((x60 * (x212 + (x60 * (x211 + (x75 * x209) + (x60 * (x210 + (-1 * x209 * x112) + (x74 * x209))))) +
						   (x76 * x209))) +
				   (x208 * x111) + (x65 * x209) + (x60 * x212))) +
		   (x207 * x110))) +
		 (x207 * x116));
	const GEN_FLT x214 = x196 + x27;
	const GEN_FLT x215 = x11 * x145;
	const GEN_FLT x216 =
		((x164 + (-1 * x162) + x215) * sensor_x) + ((x189 + x31) * sensor_y) + ((x172 + x214) * sensor_z);
	const GEN_FLT x217 = obj_qk * obj_qk * obj_qk;
	const GEN_FLT x218 = x163 + x24;
	const GEN_FLT x219 = ((x218 + x199) * sensor_x) + ((x157 + x214) * sensor_y) +
						 ((x31 + (2 * x165) + (-1 * x217 * x140) + (x217 * x142)) * sensor_z);
	const GEN_FLT x220 =
		((x218 + x194) * sensor_z) + ((x152 + x162 + (-1 * x215)) * sensor_y) + ((x166 + x31) * sensor_x);
	const GEN_FLT x221 = (x37 * x220) + (x40 * x216) + (x10 * x219);
	const GEN_FLT x222 = (x53 * x220) + (x54 * x216) + (x52 * x219);
	const GEN_FLT x223 = (x49 * x220) + (x50 * x216) + (x46 * x219);
	const GEN_FLT x224 = (x90 * x223) + (x89 * x222);
	const GEN_FLT x225 = (x59 * x221) + (-1 * x93 * (x224 + (x88 * x221)));
	const GEN_FLT x226 = x87 * x225;
	const GEN_FLT x227 = x62 * x226;
	const GEN_FLT x228 = (x63 * x226) + (x60 * (x227 + (-1 * x61 * x226)));
	const GEN_FLT x229 = (x64 * x226) + (x60 * x228);
	const GEN_FLT x230 = (-1 * x69 * x221) + (x224 * x101);
	const GEN_FLT x231 = ((x222 * x104) + (-1 * x223 * x103)) * x105;
	const GEN_FLT x232 = x231 + (-1 * x230 * x100);
	const GEN_FLT x233 =
		x86 * (x230 +
			   (-1 * x114 *
				((x80 * ((x65 * x226) + (x60 * x229) + (x225 * x111) +
						 (x60 * ((x60 * (x228 + (x75 * x226) + (x60 * ((-1 * x226 * x112) + (x74 * x226) + x227)))) +
								 x229 + (x76 * x226))))) +
				 (x232 * x110))) +
			   (x226 * x117) + (x84 * x229) + (x232 * x116));
	out[0] = (-1 * x118) + (-1 * ((-1 * x106) + x118) * x119) + x106;
	out[1] = (-1 * ((-1 * x122) + x129) * x119) + (-1 * x129) + x122;
	out[2] = (-1 * ((-1 * x137) + x139) * x119) + (-1 * x139) + x137;
	out[3] = (-1 * ((-1 * x177) + x187) * x119) + x177 + (-1 * x187);
	out[4] = (-1 * ((-1 * x206) + x213) * x119) + (-1 * x213) + x206;
	out[5] = (-1 * ((-1 * x231) + x233) * x119) + (-1 * x233) + x231;
}

// Jacobian of reproject_axis_y_gen2 wrt [sensor_x, sensor_y, sensor_z]
static inline void gen_reproject_axis_y_gen2_jac_sensor_pt_axis_angle(FLT *out, const LinmathAxisAnglePose *obj_p,
																	  const FLT *sensor_pt,
																	  const LinmathAxisAnglePose *lh_p,
																	  const BaseStationCal *bsc1) {
	const GEN_FLT obj_px = (*obj_p).Pos[0];
	const GEN_FLT obj_py = (*obj_p).Pos[1];
	const GEN_FLT obj_pz = (*obj_p).Pos[2];
	const GEN_FLT obj_qi = (*obj_p).AxisAngleRot[0];
	const GEN_FLT obj_qj = (*obj_p).AxisAngleRot[1];
	const GEN_FLT obj_qk = (*obj_p).AxisAngleRot[2];
	const GEN_FLT sensor_x = sensor_pt[0];
	const GEN_FLT sensor_y = sensor_pt[1];
	const GEN_FLT sensor_z = sensor_pt[2];
	const GEN_FLT lh_px = (*lh_p).Pos[0];
	const GEN_FLT lh_py = (*lh_p).Pos[1];
	const GEN_FLT lh_pz = (*lh_p).Pos[2];
	const GEN_FLT lh_qi = (*lh_p).AxisAngleRot[0];
	const GEN_FLT lh_qj = (*lh_p).AxisAngleRot[1];
	const GEN_FLT lh_qk = (*lh_p).AxisAngleRot[2];
	const GEN_FLT phase_1 = (*bsc1).phase;
	const GEN_FLT tilt_1 = (*bsc1).tilt;
	const GEN_FLT curve_1 = (*bsc1).curve;
	const GEN_FLT gibPhase_1 = (*bsc1).gibpha;
	const GEN_FLT gibMag_1 = (*bsc1).gibmag;
	const GEN_FLT ogeeMag_1 = (*bsc1).ogeephase;
	const GEN_FLT ogeePhase_1 = (*bsc1).ogeemag;
	const GEN_FLT x0 = lh_qk * lh_qk;
	const GEN_FLT x1 = lh_qi * lh_qi;
	const GEN_FLT x2 = lh_qj * lh_qj;
	const GEN_FLT x3 = 1e-10 + x2 + x0 + x1;
	const GEN_FLT x4 = sqrt(x3);
	const GEN_FLT x5 = (1. / x4) * sin(x4);
	const GEN_FLT x6 = x5 * lh_qi;
	const GEN_FLT x7 = cos(x4);
	const GEN_FLT x8 = (1. / x3) * (1 + (-1 * x7));
	const GEN_FLT x9 = x8 * lh_qk;
	const GEN_FLT x10 = x9 * lh_qj;
	const GEN_FLT x11 = x10 + (-1 * x6);
	const GEN_FLT x12 = obj_qk * obj_qk;
	const GEN_FLT x13 = obj_qi * obj_qi;
	const GEN_FLT x14 = obj_qj * obj_qj;
	const GEN_FLT x15 = 1e-10 + x14 + x12 + x13;
	const GEN_FLT x16 = sqrt(x15);
	const GEN_FLT x17 = cos(x16);
	const GEN_FLT x18 = (1. / x15) * (1 + (-1 * x17));
	const GEN_FLT x19 = x17 + (x12 * x18);
	const GEN_FLT x20 = (1. / x16) * sin(x16);
	const GEN_FLT x21 = x20 * obj_qj;
	const GEN_FLT x22 = x18 * obj_qi;
	const GEN_FLT x23 = x22 * obj_qk;
	const GEN_FLT x24 = x23 + (-1 * x21);
	const GEN_FLT x25 = x20 * obj_qi;
	const GEN_FLT x26 = x18 * obj_qk * obj_qj;
	const GEN_FLT x27 = x26 + x25;
	const GEN_FLT x28 = (x27 * sensor_y) + (x24 * sensor_x) + obj_pz + (x19 * sensor_z);
	const GEN_FLT x29 = x17 + (x13 * x18);
	const GEN_FLT x30 = x23 + x21;
	const GEN_FLT x31 = x20 * obj_qk;
	const GEN_FLT x32 = x22 * obj_qj;
	const GEN_FLT x33 = x32 + (-1 * x31);
	const GEN_FLT x34 = (x29 * sensor_x) + (x33 * sensor_y) + (x30 * sensor_z) + obj_px;
	const GEN_FLT x35 = x5 * lh_qk;
	const GEN_FLT x36 = x8 * lh_qj * lh_qi;
	const GEN_FLT x37 = x36 + x35;
	const GEN_FLT x38 = x26 + (-1 * x25);
	const GEN_FLT x39 = x32 + x31;
	const GEN_FLT x40 = x17 + (x14 * x18);
	const GEN_FLT x41 = (x39 * sensor_x) + obj_py + (x40 * sensor_y) + (x38 * sensor_z);
	const GEN_FLT x42 = x7 + (x2 * x8);
	const GEN_FLT x43 = (x41 * x42) + (x34 * x37) + lh_py + (x28 * x11);
	const GEN_FLT x44 = 0.523598775598299 + (-1 * tilt_1);
	const GEN_FLT x45 = cos(x44);
	const GEN_FLT x46 = 1. / x45;
	const GEN_FLT x47 = x43 * x43;
	const GEN_FLT x48 = x7 + (x0 * x8);
	const GEN_FLT x49 = x5 * lh_qj;
	const GEN_FLT x50 = x9 * lh_qi;
	const GEN_FLT x51 = x50 + (-1 * x49);
	const GEN_FLT x52 = x10 + x6;
	const GEN_FLT x53 = (x52 * x41) + lh_pz + (x51 * x34) + (x48 * x28);
	const GEN_FLT x54 = x50 + x49;
	const GEN_FLT x55 = x7 + (x1 * x8);
	const GEN_FLT x56 = x36 + (-1 * x35);
	const GEN_FLT x57 = (x56 * x41) + (x55 * x34) + lh_px + (x54 * x28);
	const GEN_FLT x58 = x57 * x57;
	const GEN_FLT x59 = x58 + (x53 * x53);
	const GEN_FLT x60 = x59 + x47;
	const GEN_FLT x61 = (1. / sqrt(x60)) * x46;
	const GEN_FLT x62 = asin(x61 * x43);
	const GEN_FLT x63 = 8.0108022e-06 * x62;
	const GEN_FLT x64 = 1. / sqrt(1 + (-1 * (1. / x60) * (1. / (x45 * x45)) * x47));
	const GEN_FLT x65 = (x37 * x29) + (x42 * x39) + (x24 * x11);
	const GEN_FLT x66 = 2 * x43;
	const GEN_FLT x67 = (x55 * x29) + (x56 * x39) + (x54 * x24);
	const GEN_FLT x68 = 2 * x57;
	const GEN_FLT x69 = (x52 * x39) + (x51 * x29) + (x48 * x24);
	const GEN_FLT x70 = 2 * x53;
	const GEN_FLT x71 = (x70 * x69) + (x67 * x68);
	const GEN_FLT x72 = 1.0 / 2.0 * x43;
	const GEN_FLT x73 = x72 * (1. / (x60 * sqrt(x60))) * x46;
	const GEN_FLT x74 = x64 * ((x61 * x65) + (-1 * x73 * (x71 + (x65 * x66))));
	const GEN_FLT x75 = -8.0108022e-06 + (-1 * x63);
	const GEN_FLT x76 = x75 * x74;
	const GEN_FLT x77 = 0.0028679863 + (x75 * x62);
	const GEN_FLT x78 = (x74 * x77) + (x62 * (x76 + (-1 * x74 * x63)));
	const GEN_FLT x79 = 5.3685255e-06 + (x77 * x62);
	const GEN_FLT x80 = (x79 * x74) + (x78 * x62);
	const GEN_FLT x81 = 0.0076069798 + (x79 * x62);
	const GEN_FLT x82 = x81 * x62;
	const GEN_FLT x83 = -8.0108022e-06 + (-1.60216044e-05 * x62);
	const GEN_FLT x84 = x77 + (x83 * x62);
	const GEN_FLT x85 = x79 + (x84 * x62);
	const GEN_FLT x86 = x81 + (x85 * x62);
	const GEN_FLT x87 = (x86 * x62) + x82;
	const GEN_FLT x88 = atan2(-1 * x53, x57);
	const GEN_FLT x89 = tan(x44);
	const GEN_FLT x90 = x89 * (1. / sqrt(x59));
	const GEN_FLT x91 = -1 * x90 * x43;
	const GEN_FLT x92 = (-1 * asin(x91)) + ogeeMag_1 + x88;
	const GEN_FLT x93 = (sin(x92) * ogeePhase_1) + curve_1;
	const GEN_FLT x94 = sin(x44);
	const GEN_FLT x95 = x93 * x94;
	const GEN_FLT x96 = x45 + (x87 * x95);
	const GEN_FLT x97 = 1. / x96;
	const GEN_FLT x98 = x62 * x62;
	const GEN_FLT x99 = x93 * x98;
	const GEN_FLT x100 = x99 * x97;
	const GEN_FLT x101 = 1. / x59;
	const GEN_FLT x102 = 1. / sqrt(1 + (-1 * (x89 * x89) * x47 * x101));
	const GEN_FLT x103 = x89 * x72 * (1. / (x59 * sqrt(x59)));
	const GEN_FLT x104 = (-1 * x65 * x90) + (x71 * x103);
	const GEN_FLT x105 = 1. / x57;
	const GEN_FLT x106 = x53 * (1. / x58);
	const GEN_FLT x107 = x58 * x101;
	const GEN_FLT x108 = ((x67 * x106) + (-1 * x69 * x105)) * x107;
	const GEN_FLT x109 = cos(x92) * ogeePhase_1;
	const GEN_FLT x110 = x109 * (x108 + (-1 * x102 * x104));
	const GEN_FLT x111 = x87 * x94;
	const GEN_FLT x112 = 2.40324066e-05 * x62;
	const GEN_FLT x113 = x81 * x99 * (1. / (x96 * x96));
	const GEN_FLT x114 = 2 * x82 * x93 * x97;
	const GEN_FLT x115 = x81 * x98 * x97;
	const GEN_FLT x116 = x91 + (x81 * x100);
	const GEN_FLT x117 = 1. / sqrt(1 + (-1 * (x116 * x116)));
	const GEN_FLT x118 =
		x117 * (x104 + (x110 * x115) + (x80 * x100) + (x74 * x114) +
				(-1 * x113 *
				 ((x95 * ((x81 * x74) +
						  (x62 * (x80 + (x62 * (x78 + (x84 * x74) + (x62 * ((-1 * x74 * x112) + x76 + (x83 * x74))))) +
								  (x85 * x74))) +
						  (x80 * x62) + (x86 * x74))) +
				  (x110 * x111))));
	const GEN_FLT x119 = cos((-1 * asin(x116)) + x88 + gibPhase_1) * gibMag_1;
	const GEN_FLT x120 = (x51 * x33) + (x52 * x40) + (x48 * x27);
	const GEN_FLT x121 = (x55 * x33) + (x56 * x40) + (x54 * x27);
	const GEN_FLT x122 = ((x106 * x121) + (-1 * x105 * x120)) * x107;
	const GEN_FLT x123 = (x33 * x37) + (x27 * x11) + (x40 * x42);
	const GEN_FLT x124 = (x70 * x120) + (x68 * x121);
	const GEN_FLT x125 = x64 * ((x61 * x123) + (-1 * x73 * (x124 + (x66 * x123))));
	const GEN_FLT x126 = x75 * x125;
	const GEN_FLT x127 = (x77 * x125) + (x62 * (x126 + (-1 * x63 * x125)));
	const GEN_FLT x128 = (x79 * x125) + (x62 * x127);
	const GEN_FLT x129 = (-1 * x90 * x123) + (x103 * x124);
	const GEN_FLT x130 = x122 + (-1 * x102 * x129);
	const GEN_FLT x131 = x109 * x111;
	const GEN_FLT x132 = x109 * x115;
	const GEN_FLT x133 =
		x117 *
		((x130 * x132) + (x100 * x128) + x129 + (x114 * x125) +
		 (-1 * x113 *
		  ((x95 * ((x81 * x125) + (x86 * x125) + (x62 * x128) +
				   (x62 * (x128 + (x62 * (x127 + (x84 * x125) + (x62 * ((-1 * x112 * x125) + x126 + (x83 * x125))))) +
						   (x85 * x125))))) +
		   (x130 * x131))));
	const GEN_FLT x134 = (x56 * x38) + (x55 * x30) + (x54 * x19);
	const GEN_FLT x135 = (x51 * x30) + (x52 * x38) + (x48 * x19);
	const GEN_FLT x136 = (x70 * x135) + (x68 * x134);
	const GEN_FLT x137 = (x30 * x37) + (x42 * x38) + (x11 * x19);
	const GEN_FLT x138 = (-1 * x90 * x137) + (x103 * x136);
	const GEN_FLT x139 = ((x106 * x134) + (-1 * x105 * x135)) * x107;
	const GEN_FLT x140 = x139 + (-1 * x102 * x138);
	const GEN_FLT x141 = x64 * ((x61 * x137) + (-1 * x73 * (x136 + (x66 * x137))));
	const GEN_FLT x142 = x75 * x141;
	const GEN_FLT x143 = (x77 * x141) + (x62 * (x142 + (-1 * x63 * x141)));
	const GEN_FLT x144 = (x79 * x141) + (x62 * x143);
	const GEN_FLT x145 =
		x117 *
		((x100 * x144) + (x114 * x141) +
		 (-1 * x113 *
		  ((x95 * ((x81 * x141) + (x62 * x144) + (x86 * x141) +
				   (x62 * (x144 + (x62 * (x143 + (x84 * x141) + (x62 * ((x83 * x141) + (-1 * x112 * x141) + x142)))) +
						   (x85 * x141))))) +
		   (x131 * x140))) +
		 x138 + (x132 * x140));
	out[0] = (-1 * ((-1 * x108) + x118) * x119) + (-1 * x118) + x108;
	out[1] = (-1 * ((-1 * x122) + x133) * x119) + x122 + (-1 * x133);
	out[2] = (-1 * x145) + (-1 * ((-1 * x139) + x145) * x119) + x139;
}

// Jacobian of reproject_axis_y_gen2 wrt [lh_px, lh_py, lh_pz, lh_qi, lh_qj, lh_qk]
static inline void gen_reproject_axis_y_gen2_jac_lh_p_axis_angle(FLT *out, const LinmathAxisAnglePose *obj_p,
																 const FLT *sensor_pt, const LinmathAxisAnglePose *lh_p,
																 const BaseStationCal *bsc1) {
	const GEN_FLT obj_px = (*obj_p).Pos[0];
	const GEN_FLT obj_py = (*obj_p).Pos[1];
	const GEN_FLT obj_pz = (*obj_p).Pos[2];
	const GEN_FLT obj_qi = (*obj_p).AxisAngleRot[0];
	const GEN_FLT obj_qj = (*obj_p).AxisAngleRot[1];
	const GEN_FLT obj_qk = (*obj_p).AxisAngleRot[2];
	const GEN_FLT sensor_x = sensor_pt[0];
	const GEN_FLT sensor_y = sensor_pt[1];
	const GEN_FLT sensor_z = sensor_pt[2];
	const GEN_FLT lh_px = (*lh_p).Pos[0];
	const GEN_FLT lh_py = (*lh_p).Pos[1];
	const GEN_FLT lh_pz = (*lh_p).Pos[2];
	const GEN_FLT lh_qi = (*lh_p).AxisAngleRot[0];
	const GEN_FLT lh_qj = (*lh_p).AxisAngleRot[1];
	const GEN_FLT lh_qk = (*lh_p).AxisAngleRot[2];
	const GEN_FLT phase_1 = (*bsc1).phase;
	const GEN_FLT tilt_1 = (*bsc1).tilt;
	const GEN_FLT curve_1 = (*bsc1).curve;
	const GEN_FLT gibPhase_1 = (*bsc1).gibpha;
	const GEN_FLT gibMag_1 = (*bsc1).gibmag;
	const GEN_FLT ogeeMag_1 = (*bsc1).ogeephase;
	const GEN_FLT ogeePhase_1 = (*bsc1).ogeemag;
	const GEN_FLT x0 = obj_qk * obj_qk;
	const GEN_FLT x1 = obj_qi * obj_qi;
	const GEN_FLT x2 = obj_qj * obj_qj;
	const GEN_FLT x3 = 1e-10 + x2 + x0 + x1;
	const GEN_FLT x4 = sqrt(x3);
	const GEN_FLT x5 = cos(x4);
	const GEN_FLT x6 = (1. / x3) * (1 + (-1 * x5));
	const GEN_FLT x7 = (1. / x4) * sin(x4);
	const GEN_FLT x8 = x7 * obj_qj;
	const GEN_FLT x9 = x6 * obj_qk;
	const GEN_FLT x10 = x9 * obj_qi;
	const GEN_FLT x11 = x7 * obj_qi;
	const GEN_FLT x12 = x9 * obj_qj;
	const GEN_FLT x13 =
		((x12 + x11) * sensor_y) + obj_pz + ((x10 + (-1 * x8)) * sensor_x) + ((x5 + (x0 * x6)) * sensor_z);
	const GEN_FLT x14 = lh_qk * lh_qk;
	const GEN_FLT x15 = lh_qi * lh_qi;
	const GEN_FLT x16 = lh_qj * lh_qj;
	const GEN_FLT x17 = 1e-10 + x14 + x16 + x15;
	const GEN_FLT x18 = 1. / x17;
	const GEN_FLT x19 = sqrt(x17);
	const GEN_FLT x20 = cos(x19);
	const GEN_FLT x21 = 1 + (-1 * x20);
	const GEN_FLT x22 = x21 * x18;
	const GEN_FLT x23 = x7 * obj_qk;
	const GEN_FLT x24 = x6 * obj_qj * obj_qi;
	const GEN_FLT x25 =
		((x10 + x8) * sensor_z) + ((x24 + (-1 * x23)) * sensor_y) + ((x5 + (x1 * x6)) * sensor_x) + obj_px;
	const GEN_FLT x26 = sin(x19);
	const GEN_FLT x27 = x26 * (1. / x19);
	const GEN_FLT x28 = x27 * lh_qj;
	const GEN_FLT x29 = -1 * x28;
	const GEN_FLT x30 = x22 * lh_qk;
	const GEN_FLT x31 = x30 * lh_qi;
	const GEN_FLT x32 =
		((x5 + (x2 * x6)) * sensor_y) + ((x24 + x23) * sensor_x) + obj_py + ((x12 + (-1 * x11)) * sensor_z);
	const GEN_FLT x33 = x27 * lh_qi;
	const GEN_FLT x34 = x30 * lh_qj;
	const GEN_FLT x35 = ((x34 + x33) * x32) + ((x31 + x29) * x25) + lh_pz + (x13 * (x20 + (x22 * x14)));
	const GEN_FLT x36 = x27 * lh_qk;
	const GEN_FLT x37 = -1 * x36;
	const GEN_FLT x38 = x22 * lh_qi;
	const GEN_FLT x39 = x38 * lh_qj;
	const GEN_FLT x40 = ((x39 + x37) * x32) + (x25 * (x20 + (x22 * x15))) + lh_px + ((x31 + x28) * x13);
	const GEN_FLT x41 = x40 * x40;
	const GEN_FLT x42 = x41 + (x35 * x35);
	const GEN_FLT x43 = 1. / x42;
	const GEN_FLT x44 = x43 * x35;
	const GEN_FLT x45 = -1 * x33;
	const GEN_FLT x46 = (x32 * (x20 + (x22 * x16))) + ((x39 + x36) * x25) + lh_py + ((x34 + x45) * x13);
	const GEN_FLT x47 = 0.523598775598299 + (-1 * tilt_1);
	const GEN_FLT x48 = cos(x47);
	const GEN_FLT x49 = 1. / x48;
	const GEN_FLT x50 = x46 * x46;
	const GEN_FLT x51 = x42 + x50;
	const GEN_FLT x52 = (1. / sqrt(x51)) * x49;
	const GEN_FLT x53 = asin(x52 * x46);
	const GEN_FLT x54 = 8.0108022e-06 * x53;
	const GEN_FLT x55 = -8.0108022e-06 + (-1 * x54);
	const GEN_FLT x56 = 0.0028679863 + (x53 * x55);
	const GEN_FLT x57 = 5.3685255e-06 + (x53 * x56);
	const GEN_FLT x58 = 0.0076069798 + (x53 * x57);
	const GEN_FLT x59 = x53 * x53;
	const GEN_FLT x60 = atan2(-1 * x35, x40);
	const GEN_FLT x61 = tan(x47);
	const GEN_FLT x62 = x61 * (1. / sqrt(x42));
	const GEN_FLT x63 = -1 * x62 * x46;
	const GEN_FLT x64 = ogeeMag_1 + (-1 * asin(x63)) + x60;
	const GEN_FLT x65 = (sin(x64) * ogeePhase_1) + curve_1;
	const GEN_FLT x66 = x53 * x58;
	const GEN_FLT x67 = -8.0108022e-06 + (-1.60216044e-05 * x53);
	const GEN_FLT x68 = x56 + (x67 * x53);
	const GEN_FLT x69 = x57 + (x68 * x53);
	const GEN_FLT x70 = x58 + (x69 * x53);
	const GEN_FLT x71 = (x70 * x53) + x66;
	const GEN_FLT x72 = sin(x47);
	const GEN_FLT x73 = x72 * x65;
	const GEN_FLT x74 = x48 + (x71 * x73);
	const GEN_FLT x75 = 1. / x74;
	const GEN_FLT x76 = x75 * x65;
	const GEN_FLT x77 = x76 * x59;
	const GEN_FLT x78 = x63 + (x77 * x58);
	const GEN_FLT x79 = 1. / sqrt(1 + (-1 * (x78 * x78)));
	const GEN_FLT x80 = x40 * x46;
	const GEN_FLT x81 = x61 * (1. / (x42 * sqrt(x42)));
	const GEN_FLT x82 = x80 * x81;
	const GEN_FLT x83 = 1. / sqrt(1 + (-1 * x50 * (1. / x51) * (1. / (x48 * x48))));
	const GEN_FLT x84 = 2 * x46;
	const GEN_FLT x85 = (1. / (x51 * sqrt(x51))) * x49;
	const GEN_FLT x86 = x76 * x66;
	const GEN_FLT x87 = x83 * x84 * x85 * x86;
	const GEN_FLT x88 = 1. / sqrt(1 + (-1 * (x61 * x61) * x50 * x43));
	const GEN_FLT x89 = x44 + (-1 * x82 * x88);
	const GEN_FLT x90 = cos(x64) * ogeePhase_1;
	const GEN_FLT x91 = x71 * x72;
	const GEN_FLT x92 = x91 * x90;
	const GEN_FLT x93 = x83 * x70;
	const GEN_FLT x94 = x80 * x85;
	const GEN_FLT x95 = x83 * x94;
	const GEN_FLT x96 = x83 * x55;
	const GEN_FLT x97 = -1 * x96 * x94;
	const GEN_FLT x98 = 2.40324066e-05 * x53;
	const GEN_FLT x99 = (-1 * x56 * x95) + (x53 * (x97 + (x54 * x95)));
	const GEN_FLT x100 = (-1 * x57 * x95) + (x53 * x99);
	const GEN_FLT x101 = x83 * x58;
	const GEN_FLT x102 = x58 * x59;
	const GEN_FLT x103 = (1. / (x74 * x74)) * x65 * x102;
	const GEN_FLT x104 = x75 * x102;
	const GEN_FLT x105 = x90 * x104;
	const GEN_FLT x106 =
		x79 *
		((x77 * x100) + (x89 * x105) + x82 +
		 (-1 * x103 *
		  ((x73 * ((x53 * x100) + (-1 * x94 * x101) + (-1 * x93 * x94) +
				   (x53 * (x100 + (x53 * (x99 + (-1 * x68 * x95) + (x53 * (x97 + (x98 * x95) + (-1 * x67 * x95))))) +
						   (-1 * x69 * x95))))) +
		   (x89 * x92))) +
		 (-1 * x87 * x40));
	const GEN_FLT x107 = cos((-1 * asin(x78)) + x60 + gibPhase_1) * gibMag_1;
	const GEN_FLT x108 = x52 + (-1 * x85 * x50);
	const GEN_FLT x109 = x83 * x108;
	const GEN_FLT x110 = 2 * x86;
	const GEN_FLT x111 = x88 * x62;
	const GEN_FLT x112 = x96 * x108;
	const GEN_FLT x113 = (x56 * x109) + (x53 * (x112 + (-1 * x54 * x109)));
	const GEN_FLT x114 = (x57 * x109) + (x53 * x113);
	const GEN_FLT x115 =
		x79 *
		((x105 * x111) + (x77 * x114) + (-1 * x62) + (x109 * x110) +
		 (-1 * x103 *
		  ((x73 * ((x53 * x114) + (x58 * x109) + (x70 * x109) +
				   (x53 * (x114 + (x53 * (x113 + (x68 * x109) + (x53 * ((-1 * x98 * x109) + x112 + (x67 * x109))))) +
						   (x69 * x109))))) +
		   (x92 * x111))));
	const GEN_FLT x116 = x40 * x43;
	const GEN_FLT x117 = -1 * x116;
	const GEN_FLT x118 = x81 * x46;
	const GEN_FLT x119 = x35 * x118;
	const GEN_FLT x120 = x117 + (-1 * x88 * x119);
	const GEN_FLT x121 = x85 * x46;
	const GEN_FLT x122 = x35 * x121;
	const GEN_FLT x123 = x83 * x122;
	const GEN_FLT x124 = -1 * x96 * x122;
	const GEN_FLT x125 = (-1 * x56 * x123) + (x53 * (x124 + (x54 * x123)));
	const GEN_FLT x126 = (-1 * x57 * x123) + (x53 * x125);
	const GEN_FLT x127 =
		x79 *
		((x77 * x126) +
		 (-1 * x103 *
		  ((x73 *
			((-1 * x101 * x122) + (x53 * x126) + (-1 * x93 * x122) +
			 (x53 * (x126 + (x53 * (x125 + (-1 * x68 * x123) + (x53 * ((x98 * x123) + (-1 * x67 * x123) + x124)))) +
					 (-1 * x69 * x123))))) +
		   (x92 * x120))) +
		 (x105 * x120) + x119 + (-1 * x87 * x35));
	const GEN_FLT x128 = 2 * x21 * (1. / (x17 * x17));
	const GEN_FLT x129 = x26 * (1. / (x17 * sqrt(x17)));
	const GEN_FLT x130 = x16 * x129;
	const GEN_FLT x131 = (x130 * lh_qi) + (-1 * x16 * x128 * lh_qi);
	const GEN_FLT x132 = x20 * x18;
	const GEN_FLT x133 = x15 * x132;
	const GEN_FLT x134 = x15 * x129;
	const GEN_FLT x135 = x129 * lh_qk;
	const GEN_FLT x136 = x135 * lh_qi;
	const GEN_FLT x137 = lh_qk * lh_qi;
	const GEN_FLT x138 = x128 * lh_qj;
	const GEN_FLT x139 = (-1 * x137 * x138) + (x136 * lh_qj);
	const GEN_FLT x140 = x139 + (-1 * x27);
	const GEN_FLT x141 = x22 * lh_qj;
	const GEN_FLT x142 = (x134 * lh_qj) + (-1 * x15 * x138);
	const GEN_FLT x143 = x142 + x141;
	const GEN_FLT x144 = x132 * x137;
	const GEN_FLT x145 = (-1 * x136) + x144;
	const GEN_FLT x146 = ((x145 + x143) * x25) + (x32 * (x131 + x45)) + (x13 * (x140 + (-1 * x133) + x134));
	const GEN_FLT x147 = x136 + (-1 * x144);
	const GEN_FLT x148 = x128 * lh_qk;
	const GEN_FLT x149 = (x134 * lh_qk) + (-1 * x15 * x148);
	const GEN_FLT x150 = x149 + x30;
	const GEN_FLT x151 = x132 * lh_qj;
	const GEN_FLT x152 = x151 * lh_qi;
	const GEN_FLT x153 = x129 * lh_qj * lh_qi;
	const GEN_FLT x154 = (-1 * x153) + x152;
	const GEN_FLT x155 = lh_qi * lh_qi * lh_qi;
	const GEN_FLT x156 =
		(((2 * x38) + (-1 * x128 * x155) + x45 + (x129 * x155)) * x25) + ((x147 + x143) * x32) + ((x154 + x150) * x13);
	const GEN_FLT x157 = 2 * x40;
	const GEN_FLT x158 = x139 + x27;
	const GEN_FLT x159 = x14 * x128;
	const GEN_FLT x160 = x14 * x129;
	const GEN_FLT x161 = (x160 * lh_qi) + (-1 * x159 * lh_qi);
	const GEN_FLT x162 = x153 + (-1 * x152);
	const GEN_FLT x163 = ((x162 + x150) * x25) + (x32 * (x133 + x158 + (-1 * x134))) + (x13 * (x161 + x45));
	const GEN_FLT x164 = 2 * x35;
	const GEN_FLT x165 = (x164 * x163) + (x156 * x157);
	const GEN_FLT x166 = 1.0 / 2.0 * x121;
	const GEN_FLT x167 = (x52 * x146) + (-1 * x166 * (x165 + (x84 * x146)));
	const GEN_FLT x168 = x83 * x167;
	const GEN_FLT x169 = x96 * x167;
	const GEN_FLT x170 = (x56 * x168) + (x53 * (x169 + (-1 * x54 * x168)));
	const GEN_FLT x171 = (x57 * x168) + (x53 * x170);
	const GEN_FLT x172 = 1.0 / 2.0 * x118;
	const GEN_FLT x173 = (-1 * x62 * x146) + (x165 * x172);
	const GEN_FLT x174 = 1. / x40;
	const GEN_FLT x175 = (1. / x41) * x35;
	const GEN_FLT x176 = x41 * x43;
	const GEN_FLT x177 = ((x175 * x156) + (-1 * x163 * x174)) * x176;
	const GEN_FLT x178 = x177 + (-1 * x88 * x173);
	const GEN_FLT x179 =
		x79 *
		((-1 * x103 *
		  ((x73 * ((x58 * x168) + (x53 * x171) + (x70 * x168) +
				   (x53 * (x171 + (x53 * (x170 + (x68 * x168) + (x53 * ((-1 * x98 * x168) + x169 + (x67 * x168))))) +
						   (x69 * x168))))) +
		   (x92 * x178))) +
		 (x77 * x171) + x173 + (x110 * x168) + (x105 * x178));
	const GEN_FLT x180 = lh_qj * lh_qj * lh_qj;
	const GEN_FLT x181 = (x130 * lh_qk) + (-1 * x16 * x148);
	const GEN_FLT x182 = x181 + x30;
	const GEN_FLT x183 = x131 + x38;
	const GEN_FLT x184 = x151 * lh_qk;
	const GEN_FLT x185 = x135 * lh_qj;
	const GEN_FLT x186 = (-1 * x185) + x184;
	const GEN_FLT x187 =
		((x186 + x183) * x25) + (x32 * ((-1 * x128 * x180) + (x129 * x180) + x29 + (2 * x141))) + ((x162 + x182) * x13);
	const GEN_FLT x188 = x185 + (-1 * x184);
	const GEN_FLT x189 = x16 * x132;
	const GEN_FLT x190 = (x25 * (x142 + x29)) + ((x188 + x183) * x32) + (x13 * (x158 + x189 + (-1 * x130)));
	const GEN_FLT x191 = (x160 * lh_qj) + (-1 * x159 * lh_qj);
	const GEN_FLT x192 = (x25 * ((-1 * x189) + x140 + x130)) + ((x182 + x154) * x32) + (x13 * (x191 + x29));
	const GEN_FLT x193 = (x164 * x192) + (x190 * x157);
	const GEN_FLT x194 = x83 * ((x52 * x187) + (-1 * x166 * (x193 + (x84 * x187))));
	const GEN_FLT x195 = x55 * x194;
	const GEN_FLT x196 = (x56 * x194) + (x53 * (x195 + (-1 * x54 * x194)));
	const GEN_FLT x197 = (x57 * x194) + (x53 * x196);
	const GEN_FLT x198 = (-1 * x62 * x187) + (x172 * x193);
	const GEN_FLT x199 = ((x175 * x190) + (-1 * x174 * x192)) * x176;
	const GEN_FLT x200 = x199 + (-1 * x88 * x198);
	const GEN_FLT x201 =
		x79 *
		((-1 * x103 *
		  ((x73 * ((x70 * x194) +
				   (x53 * (x197 + (x53 * (x196 + (x68 * x194) + (x53 * ((-1 * x98 * x194) + x195 + (x67 * x194))))) +
						   (x69 * x194))) +
				   (x58 * x194) + (x53 * x197))) +
		   (x92 * x200))) +
		 (x77 * x197) + x198 + (x110 * x194) + (x200 * x105));
	const GEN_FLT x202 = x14 * x132;
	const GEN_FLT x203 = x161 + x38;
	const GEN_FLT x204 = (x25 * (x149 + x37)) + (x32 * (x140 + x160 + (-1 * x202))) + ((x203 + x186) * x13);
	const GEN_FLT x205 = x191 + x141;
	const GEN_FLT x206 = lh_qk * lh_qk * lh_qk;
	const GEN_FLT x207 =
		((x203 + x188) * x25) + ((x205 + x145) * x32) + (((2 * x30) + x37 + (x206 * x129) + (-1 * x206 * x128)) * x13);
	const GEN_FLT x208 = (x207 * x164) + (x204 * x157);
	const GEN_FLT x209 = (x25 * ((-1 * x160) + x158 + x202)) + ((x205 + x147) * x13) + (x32 * (x181 + x37));
	const GEN_FLT x210 = (-1 * x62 * x209) + (x208 * x172);
	const GEN_FLT x211 = ((x204 * x175) + (-1 * x207 * x174)) * x176;
	const GEN_FLT x212 = x90 * (x211 + (-1 * x88 * x210));
	const GEN_FLT x213 = (x52 * x209) + (-1 * x166 * (x208 + (x84 * x209)));
	const GEN_FLT x214 = x83 * x213;
	const GEN_FLT x215 = x96 * x213;
	const GEN_FLT x216 = (x56 * x214) + (x53 * (x215 + (-1 * x54 * x214)));
	const GEN_FLT x217 = (x57 * x214) + (x53 * x216);
	const GEN_FLT x218 =
		x79 *
		(x210 +
		 (-1 * x103 *
		  ((x73 * ((x53 * x217) + (x70 * x214) + (x58 * x214) +
				   (x53 * (x217 + (x53 * (x216 + (x68 * x214) + (x53 * (x215 + (-1 * x98 * x214) + (x67 * x214))))) +
						   (x69 * x214))))) +
		   (x91 * x212))) +
		 (x214 * x110) + (x212 * x104) + (x77 * x217));
	out[0] = (-1 * x107 * ((-1 * x44) + x106)) + x44 + (-1 * x106);
	out[1] = (-1 * x107 * x115) + (-1 * x115);
	out[2] = (-1 * (x116 + x127) * x107) + x117 + (-1 * x127);
	out[3] = (-1 * ((-1 * x177) + x179) * x107) + (-1 * x179) + x177;
	out[4] = (-1 * ((-1 * x199) + x201) * x107) + (-1 * x201) + x199;
	out[5] = (-1 * ((-1 * x211) + x218) * x107) + (-1 * x218) + x211;
}

// Jacobian of reproject_axis_y_gen2 wrt [phase_1, tilt_1, curve_1, gibPhase_1, gibMag_1, ogeeMag_1, ogeePhase_1]
static inline void gen_reproject_axis_y_gen2_jac_bsc1_axis_angle(FLT *out, const LinmathAxisAnglePose *obj_p,
																 const FLT *sensor_pt, const LinmathAxisAnglePose *lh_p,
																 const BaseStationCal *bsc1) {
	const GEN_FLT obj_px = (*obj_p).Pos[0];
	const GEN_FLT obj_py = (*obj_p).Pos[1];
	const GEN_FLT obj_pz = (*obj_p).Pos[2];
	const GEN_FLT obj_qi = (*obj_p).AxisAngleRot[0];
	const GEN_FLT obj_qj = (*obj_p).AxisAngleRot[1];
	const GEN_FLT obj_qk = (*obj_p).AxisAngleRot[2];
	const GEN_FLT sensor_x = sensor_pt[0];
	const GEN_FLT sensor_y = sensor_pt[1];
	const GEN_FLT sensor_z = sensor_pt[2];
	const GEN_FLT lh_px = (*lh_p).Pos[0];
	const GEN_FLT lh_py = (*lh_p).Pos[1];
	const GEN_FLT lh_pz = (*lh_p).Pos[2];
	const GEN_FLT lh_qi = (*lh_p).AxisAngleRot[0];
	const GEN_FLT lh_qj = (*lh_p).AxisAngleRot[1];
	const GEN_FLT lh_qk = (*lh_p).AxisAngleRot[2];
	const GEN_FLT phase_1 = (*bsc1).phase;
	const GEN_FLT tilt_1 = (*bsc1).tilt;
	const GEN_FLT curve_1 = (*bsc1).curve;
	const GEN_FLT gibPhase_1 = (*bsc1).gibpha;
	const GEN_FLT gibMag_1 = (*bsc1).gibmag;
	const GEN_FLT ogeeMag_1 = (*bsc1).ogeephase;
	const GEN_FLT ogeePhase_1 = (*bsc1).ogeemag;
	const GEN_FLT x0 = obj_qk * obj_qk;
	const GEN_FLT x1 = obj_qi * obj_qi;
	const GEN_FLT x2 = obj_qj * obj_qj;
	const GEN_FLT x3 = 1e-10 + x2 + x0 + x1;
	const GEN_FLT x4 = sqrt(x3);
	const GEN_FLT x5 = cos(x4);
	const GEN_FLT x6 = (1. / x3) * (1 + (-1 * x5));
	const GEN_FLT x7 = (1. / x4) * sin(x4);
	const GEN_FLT x8 = x7 * obj_qj;
	const GEN_FLT x9 = x6 * obj_qi;
	const GEN_FLT x10 = x9 * obj_qk;
	const GEN_FLT x11 = x7 * obj_qi;
	const GEN_FLT x12 = x6 * obj_qk * obj_qj;
	const GEN_FLT x13 =
		((x12 + x11) * sensor_y) + obj_pz + ((x10 + (-1 * x8)) * sensor_x) + ((x5 + (x0 * x6)) * sensor_z);
	const GEN_FLT x14 = lh_qk * lh_qk;
	const GEN_FLT x15 = lh_qi * lh_qi;
	const GEN_FLT x16 = lh_qj * lh_qj;
	const GEN_FLT x17 = 1e-10 + x14 + x16 + x15;
	const GEN_FLT x18 = sqrt(x17);
	const GEN_FLT x19 = cos(x18);
	const GEN_FLT x20 = (1. / x17) * (1 + (-1 * x19));
	const GEN_FLT x21 = x7 * obj_qk;
	const GEN_FLT x22 = x9 * obj_qj;
	const GEN_FLT x23 =
		((x22 + (-1 * x21)) * sensor_y) + ((x10 + x8) * sensor_z) + ((x5 + (x1 * x6)) * sensor_x) + obj_px;
	const GEN_FLT x24 = (1. / x18) * sin(x18);
	const GEN_FLT x25 = x24 * lh_qj;
	const GEN_FLT x26 = x20 * lh_qk;
	const GEN_FLT x27 = x26 * lh_qi;
	const GEN_FLT x28 =
		((x5 + (x2 * x6)) * sensor_y) + ((x22 + x21) * sensor_x) + obj_py + ((x12 + (-1 * x11)) * sensor_z);
	const GEN_FLT x29 = x24 * lh_qi;
	const GEN_FLT x30 = x26 * lh_qj;
	const GEN_FLT x31 = ((x30 + x29) * x28) + ((x27 + (-1 * x25)) * x23) + lh_pz + (x13 * (x19 + (x20 * x14)));
	const GEN_FLT x32 = x24 * lh_qk;
	const GEN_FLT x33 = x20 * lh_qj * lh_qi;
	const GEN_FLT x34 = ((x33 + (-1 * x32)) * x28) + (x23 * (x19 + (x20 * x15))) + lh_px + ((x27 + x25) * x13);
	const GEN_FLT x35 = atan2(-1 * x31, x34);
	const GEN_FLT x36 = 0.523598775598299 + (-1 * tilt_1);
	const GEN_FLT x37 = tan(x36);
	const GEN_FLT x38 = (x28 * (x19 + (x20 * x16))) + ((x33 + x32) * x23) + lh_py + ((x30 + (-1 * x29)) * x13);
	const GEN_FLT x39 = (x34 * x34) + (x31 * x31);
	const GEN_FLT x40 = x38 * (1. / sqrt(x39));
	const GEN_FLT x41 = -1 * x40 * x37;
	const GEN_FLT x42 = (-1 * asin(x41)) + ogeeMag_1 + x35;
	const GEN_FLT x43 = sin(x42);
	const GEN_FLT x44 = (x43 * ogeePhase_1) + curve_1;
	const GEN_FLT x45 = cos(x36);
	const GEN_FLT x46 = x38 * x38;
	const GEN_FLT x47 = x39 + x46;
	const GEN_FLT x48 = (1. / sqrt(x47)) * x38;
	const GEN_FLT x49 = asin((1. / x45) * x48);
	const GEN_FLT x50 = 8.0108022e-06 * x49;
	const GEN_FLT x51 = -8.0108022e-06 + (-1 * x50);
	const GEN_FLT x52 = 0.0028679863 + (x51 * x49);
	const GEN_FLT x53 = 5.3685255e-06 + (x52 * x49);
	const GEN_FLT x54 = 0.0076069798 + (x53 * x49);
	const GEN_FLT x55 = x49 * x49;
	const GEN_FLT x56 = x54 * x49;
	const GEN_FLT x57 = -8.0108022e-06 + (-1.60216044e-05 * x49);
	const GEN_FLT x58 = x52 + (x57 * x49);
	const GEN_FLT x59 = x53 + (x58 * x49);
	const GEN_FLT x60 = x54 + (x59 * x49);
	const GEN_FLT x61 = (x60 * x49) + x56;
	const GEN_FLT x62 = sin(x36);
	const GEN_FLT x63 = x62 * x44;
	const GEN_FLT x64 = x63 * x61;
	const GEN_FLT x65 = x45 + x64;
	const GEN_FLT x66 = 1. / x65;
	const GEN_FLT x67 = x66 * x55;
	const GEN_FLT x68 = x67 * x54;
	const GEN_FLT x69 = x41 + (x68 * x44);
	const GEN_FLT x70 = 1. / sqrt(1 + (-1 * (x69 * x69)));
	const GEN_FLT x71 = x37 * x37;
	const GEN_FLT x72 = x40 * (1 + x71);
	const GEN_FLT x73 = 1. / (x45 * x45);
	const GEN_FLT x74 = x73 * x48 * (1. / sqrt(1 + (-1 * x73 * x46 * (1. / x47))));
	const GEN_FLT x75 = cos(x42) * ogeePhase_1;
	const GEN_FLT x76 = x75 * x68;
	const GEN_FLT x77 = x72 * (1. / sqrt(1 + (-1 * x71 * x46 * (1. / x39))));
	const GEN_FLT x78 = x74 * x62;
	const GEN_FLT x79 = -1 * x78 * x51;
	const GEN_FLT x80 = (-1 * x78 * x52) + (x49 * (x79 + (x78 * x50)));
	const GEN_FLT x81 = (-1 * x78 * x53) + (x80 * x49);
	const GEN_FLT x82 = (1. / (x65 * x65)) * x54 * x55;
	const GEN_FLT x83 =
		x70 * ((x81 * x67 * x44) +
			   (-1 * x82 * x44 *
				((-1 * x75 * x77 * x61 * x62) + x62 +
				 (x63 * ((-1 * x78 * x54) +
						 (x49 * (x81 +
								 (x49 * (x80 + (-1 * x78 * x58) +
										 (x49 * ((2.40324066e-05 * x78 * x49) + x79 + (-1 * x78 * x57))))) +
								 (-1 * x78 * x59))) +
						 (-1 * x78 * x60) + (x81 * x49))) +
				 (-1 * x61 * x44 * x45))) +
			   (-1 * x77 * x76) + x72 + (-2 * x74 * x63 * x66 * x56));
	const GEN_FLT x84 = asin(x69) + (-1 * x35) + (-1 * gibPhase_1);
	const GEN_FLT x85 = cos(x84) * gibMag_1;
	const GEN_FLT x86 = x82 * x64;
	const GEN_FLT x87 = ((-1 * x86) + x68) * x70;
	const GEN_FLT x88 = x70 * ((-1 * x86 * x75) + x76);
	const GEN_FLT x89 = ((-1 * x86 * x43) + (x68 * x43)) * x70;
	out[0] = -1;
	out[1] = (-1 * x83 * x85) + (-1 * x83);
	out[2] = (-1 * x85 * x87) + (-1 * x87);
	out[3] = x85;
	out[4] = -1 * sin(x84);
	out[5] = (-1 * x88 * x85) + (-1 * x88);
	out[6] = (-1 * x89 * x85) + (-1 * x89);
}

static inline void gen_reproject_axis_angle(FLT *out, const LinmathAxisAnglePose *obj_p, const FLT *sensor_pt,
											const LinmathAxisAnglePose *lh_p, const BaseStationCal *bsd) {
	const GEN_FLT obj_px = (*obj_p).Pos[0];
	const GEN_FLT obj_py = (*obj_p).Pos[1];
	const GEN_FLT obj_pz = (*obj_p).Pos[2];
	const GEN_FLT obj_qi = (*obj_p).AxisAngleRot[0];
	const GEN_FLT obj_qj = (*obj_p).AxisAngleRot[1];
	const GEN_FLT obj_qk = (*obj_p).AxisAngleRot[2];
	const GEN_FLT sensor_x = sensor_pt[0];
	const GEN_FLT sensor_y = sensor_pt[1];
	const GEN_FLT sensor_z = sensor_pt[2];
	const GEN_FLT lh_px = (*lh_p).Pos[0];
	const GEN_FLT lh_py = (*lh_p).Pos[1];
	const GEN_FLT lh_pz = (*lh_p).Pos[2];
	const GEN_FLT lh_qi = (*lh_p).AxisAngleRot[0];
	const GEN_FLT lh_qj = (*lh_p).AxisAngleRot[1];
	const GEN_FLT lh_qk = (*lh_p).AxisAngleRot[2];
	const GEN_FLT phase_0 = bsd[0].phase;
	const GEN_FLT tilt_0 = bsd[0].tilt;
	const GEN_FLT curve_0 = bsd[0].curve;
	const GEN_FLT gibPhase_0 = bsd[0].gibpha;
	const GEN_FLT gibMag_0 = bsd[0].gibmag;
	const GEN_FLT ogeeMag_0 = bsd[0].ogeephase;
	const GEN_FLT ogeePhase_0 = bsd[0].ogeemag;
	const GEN_FLT phase_1 = bsd[1].phase;
	const GEN_FLT tilt_1 = bsd[1].tilt;
	const GEN_FLT curve_1 = bsd[1].curve;
	const GEN_FLT gibPhase_1 = bsd[1].gibpha;
	const GEN_FLT gibMag_1 = bsd[1].gibmag;
	const GEN_FLT ogeeMag_1 = bsd[1].ogeephase;
	const GEN_FLT ogeePhase_1 = bsd[1].ogeemag;
	const GEN_FLT x0 = lh_qk * lh_qk;
	const GEN_FLT x1 = lh_qi * lh_qi;
	const GEN_FLT x2 = lh_qj * lh_qj;
	const GEN_FLT x3 = 1e-10 + x2 + x0 + x1;
	const GEN_FLT x4 = sqrt(x3);
	const GEN_FLT x5 = (1. / x4) * sin(x4);
	const GEN_FLT x6 = x5 * lh_qi;
	const GEN_FLT x7 = cos(x4);
	const GEN_FLT x8 = (1. / x3) * (1 + (-1 * x7));
	const GEN_FLT x9 = x8 * lh_qj;
	const GEN_FLT x10 = x9 * lh_qk;
	const GEN_FLT x11 = obj_qk * obj_qk;
	const GEN_FLT x12 = obj_qi * obj_qi;
	const GEN_FLT x13 = obj_qj * obj_qj;
	const GEN_FLT x14 = 1e-10 + x13 + x11 + x12;
	const GEN_FLT x15 = sqrt(x14);
	const GEN_FLT x16 = cos(x15);
	const GEN_FLT x17 = (1. / x14) * (1 + (-1 * x16));
	const GEN_FLT x18 = (1. / x15) * sin(x15);
	const GEN_FLT x19 = x18 * obj_qj;
	const GEN_FLT x20 = x17 * obj_qk;
	const GEN_FLT x21 = x20 * obj_qi;
	const GEN_FLT x22 = x18 * obj_qi;
	const GEN_FLT x23 = x20 * obj_qj;
	const GEN_FLT x24 =
		((x23 + x22) * sensor_y) + ((x21 + (-1 * x19)) * sensor_x) + obj_pz + ((x16 + (x11 * x17)) * sensor_z);
	const GEN_FLT x25 = x18 * obj_qk;
	const GEN_FLT x26 = x17 * obj_qj * obj_qi;
	const GEN_FLT x27 =
		((x26 + (-1 * x25)) * sensor_y) + ((x21 + x19) * sensor_z) + ((x16 + (x12 * x17)) * sensor_x) + obj_px;
	const GEN_FLT x28 = x5 * lh_qk;
	const GEN_FLT x29 = x9 * lh_qi;
	const GEN_FLT x30 =
		((x26 + x25) * sensor_x) + obj_py + ((x16 + (x13 * x17)) * sensor_y) + ((x23 + (-1 * x22)) * sensor_z);
	const GEN_FLT x31 = ((x29 + x28) * x27) + lh_py + (x30 * (x7 + (x2 * x8))) + (x24 * (x10 + (-1 * x6)));
	const GEN_FLT x32 = x5 * lh_qj;
	const GEN_FLT x33 = x8 * lh_qk * lh_qi;
	const GEN_FLT x34 = ((x33 + (-1 * x32)) * x27) + lh_pz + (x30 * (x10 + x6)) + (x24 * (x7 + (x0 * x8)));
	const GEN_FLT x35 = -1 * x34;
	const GEN_FLT x36 = x34 * x34;
	const GEN_FLT x37 = ((x29 + (-1 * x28)) * x30) + (x27 * (x7 + (x1 * x8))) + lh_px + ((x33 + x32) * x24);
	const GEN_FLT x38 = atan2(x37, x35);
	const GEN_FLT x39 = (-1 * phase_0) + (-1 * asin(x31 * (1. / sqrt((x37 * x37) + x36)) * tilt_0)) + (-1 * x38);
	const GEN_FLT x40 =
		(-1 * asin(x37 * (1. / sqrt((x31 * x31) + x36)) * tilt_1)) + (-1 * phase_1) + (-1 * atan2(-1 * x31, x35));
	out[0] = x39 + ((atan2(x31, x35) * atan2(x31, x35)) * curve_0) +
			 (-1 * cos(1.5707963267949 + x39 + gibPhase_0) * gibMag_0);
	out[1] = x40 + ((x38 * x38) * curve_1) + (-1 * cos(1.5707963267949 + x40 + gibPhase_1) * gibMag_1);
}

// Jacobian of reproject wrt [obj_px, obj_py, obj_pz, obj_qi, obj_qj, obj_qk]
static inline void gen_reproject_jac_obj_p_axis_angle(FLT *out, const LinmathAxisAnglePose *obj_p, const FLT *sensor_pt,
													  const LinmathAxisAnglePose *lh_p, const BaseStationCal *bsd) {
	const GEN_FLT obj_px = (*obj_p).Pos[0];
	const GEN_FLT obj_py = (*obj_p).Pos[1];
	const GEN_FLT obj_pz = (*obj_p).Pos[2];
	const GEN_FLT obj_qi = (*obj_p).AxisAngleRot[0];
	const GEN_FLT obj_qj = (*obj_p).AxisAngleRot[1];
	const GEN_FLT obj_qk = (*obj_p).AxisAngleRot[2];
	const GEN_FLT sensor_x = sensor_pt[0];
	const GEN_FLT sensor_y = sensor_pt[1];
	const GEN_FLT sensor_z = sensor_pt[2];
	const GEN_FLT lh_px = (*lh_p).Pos[0];
	const GEN_FLT lh_py = (*lh_p).Pos[1];
	const GEN_FLT lh_pz = (*lh_p).Pos[2];
	const GEN_FLT lh_qi = (*lh_p).AxisAngleRot[0];
	const GEN_FLT lh_qj = (*lh_p).AxisAngleRot[1];
	const GEN_FLT lh_qk = (*lh_p).AxisAngleRot[2];
	const GEN_FLT phase_0 = bsd[0].phase;
	const GEN_FLT tilt_0 = bsd[0].tilt;
	const GEN_FLT curve_0 = bsd[0].curve;
	const GEN_FLT gibPhase_0 = bsd[0].gibpha;
	const GEN_FLT gibMag_0 = bsd[0].gibmag;
	const GEN_FLT ogeeMag_0 = bsd[0].ogeephase;
	const GEN_FLT ogeePhase_0 = bsd[0].ogeemag;
	const GEN_FLT phase_1 = bsd[1].phase;
	const GEN_FLT tilt_1 = bsd[1].tilt;
	const GEN_FLT curve_1 = bsd[1].curve;
	const GEN_FLT gibPhase_1 = bsd[1].gibpha;
	const GEN_FLT gibMag_1 = bsd[1].gibmag;
	const GEN_FLT ogeeMag_1 = bsd[1].ogeephase;
	const GEN_FLT ogeePhase_1 = bsd[1].ogeemag;
	const GEN_FLT x0 = lh_qk * lh_qk;
	const GEN_FLT x1 = lh_qi * lh_qi;
	const GEN_FLT x2 = lh_qj * lh_qj;
	const GEN_FLT x3 = 1e-10 + x2 + x0 + x1;
	const GEN_FLT x4 = sqrt(x3);
	const GEN_FLT x5 = (1. / x4) * sin(x4);
	const GEN_FLT x6 = x5 * lh_qj;
	const GEN_FLT x7 = cos(x4);
	const GEN_FLT x8 = (1. / x3) * (1 + (-1 * x7));
	const GEN_FLT x9 = x8 * lh_qk;
	const GEN_FLT x10 = x9 * lh_qi;
	const GEN_FLT x11 = x10 + (-1 * x6);
	const GEN_FLT x12 = x5 * lh_qi;
	const GEN_FLT x13 = x9 * lh_qj;
	const GEN_FLT x14 = x13 + (-1 * x12);
	const GEN_FLT x15 = obj_qk * obj_qk;
	const GEN_FLT x16 = obj_qi * obj_qi;
	const GEN_FLT x17 = obj_qj * obj_qj;
	const GEN_FLT x18 = 1e-10 + x17 + x15 + x16;
	const GEN_FLT x19 = 1. / x18;
	const GEN_FLT x20 = sqrt(x18);
	const GEN_FLT x21 = cos(x20);
	const GEN_FLT x22 = 1 + (-1 * x21);
	const GEN_FLT x23 = x22 * x19;
	const GEN_FLT x24 = sin(x20);
	const GEN_FLT x25 = x24 * (1. / x20);
	const GEN_FLT x26 = x25 * obj_qj;
	const GEN_FLT x27 = -1 * x26;
	const GEN_FLT x28 = x23 * obj_qk;
	const GEN_FLT x29 = x28 * obj_qi;
	const GEN_FLT x30 = x25 * obj_qi;
	const GEN_FLT x31 = x28 * obj_qj;
	const GEN_FLT x32 = ((x31 + x30) * sensor_y) + ((x29 + x27) * sensor_x) + obj_pz + ((x21 + (x23 * x15)) * sensor_z);
	const GEN_FLT x33 = x25 * obj_qk;
	const GEN_FLT x34 = -1 * x33;
	const GEN_FLT x35 = x23 * obj_qi;
	const GEN_FLT x36 = x35 * obj_qj;
	const GEN_FLT x37 = ((x36 + x34) * sensor_y) + ((x29 + x26) * sensor_z) + ((x21 + (x23 * x16)) * sensor_x) + obj_px;
	const GEN_FLT x38 = x5 * lh_qk;
	const GEN_FLT x39 = x8 * lh_qj * lh_qi;
	const GEN_FLT x40 = x39 + x38;
	const GEN_FLT x41 = -1 * x30;
	const GEN_FLT x42 = ((x21 + (x23 * x17)) * sensor_y) + ((x36 + x33) * sensor_x) + obj_py + ((x31 + x41) * sensor_z);
	const GEN_FLT x43 = x7 + (x2 * x8);
	const GEN_FLT x44 = (x40 * x37) + lh_py + (x42 * x43) + (x32 * x14);
	const GEN_FLT x45 = x7 + (x0 * x8);
	const GEN_FLT x46 = x13 + x12;
	const GEN_FLT x47 = (x42 * x46) + (x37 * x11) + lh_pz + (x45 * x32);
	const GEN_FLT x48 = x47 * x47;
	const GEN_FLT x49 = 1. / x48;
	const GEN_FLT x50 = x44 * x49;
	const GEN_FLT x51 = x50 * x11;
	const GEN_FLT x52 = 1. / x47;
	const GEN_FLT x53 = x52 * x40;
	const GEN_FLT x54 = -1 * x47;
	const GEN_FLT x55 = x44 * x44;
	const GEN_FLT x56 = x48 + x55;
	const GEN_FLT x57 = 1. / x56;
	const GEN_FLT x58 = x57 * x48;
	const GEN_FLT x59 = 2 * x58 * atan2(x44, x54) * curve_0;
	const GEN_FLT x60 = x10 + x6;
	const GEN_FLT x61 = x7 + (x1 * x8);
	const GEN_FLT x62 = x39 + (-1 * x38);
	const GEN_FLT x63 = (x61 * x37) + lh_px + (x62 * x42) + (x60 * x32);
	const GEN_FLT x64 = x63 * x49;
	const GEN_FLT x65 = x63 * x63;
	const GEN_FLT x66 = x48 + x65;
	const GEN_FLT x67 = 1. / x66;
	const GEN_FLT x68 = x67 * x48;
	const GEN_FLT x69 = ((-1 * x61 * x52) + (x64 * x11)) * x68;
	const GEN_FLT x70 = 2 * x63;
	const GEN_FLT x71 = 2 * x47;
	const GEN_FLT x72 = x71 * x11;
	const GEN_FLT x73 = 1.0 / 2.0 * (1. / (x66 * sqrt(x66))) * x44 * tilt_0;
	const GEN_FLT x74 = (1. / sqrt(x66)) * tilt_0;
	const GEN_FLT x75 = 1. / sqrt(1 + (-1 * x67 * x55 * (tilt_0 * tilt_0)));
	const GEN_FLT x76 = (-1 * x75 * ((x74 * x40) + (-1 * x73 * (x72 + (x70 * x61))))) + (-1 * x69);
	const GEN_FLT x77 = atan2(x63, x54);
	const GEN_FLT x78 =
		sin(1.5707963267949 + (-1 * phase_0) + (-1 * x77) + (-1 * asin(x74 * x44)) + gibPhase_0) * gibMag_0;
	const GEN_FLT x79 = x50 * x46;
	const GEN_FLT x80 = x52 * x43;
	const GEN_FLT x81 = ((-1 * x62 * x52) + (x64 * x46)) * x68;
	const GEN_FLT x82 = x71 * x46;
	const GEN_FLT x83 = (-1 * x75 * ((x74 * x43) + (-1 * x73 * (x82 + (x70 * x62))))) + (-1 * x81);
	const GEN_FLT x84 = x50 * x45;
	const GEN_FLT x85 = x52 * x14;
	const GEN_FLT x86 = ((-1 * x60 * x52) + (x64 * x45)) * x68;
	const GEN_FLT x87 = x71 * x45;
	const GEN_FLT x88 = (-1 * x75 * ((x74 * x14) + (-1 * x73 * (x87 + (x70 * x60))))) + (-1 * x86);
	const GEN_FLT x89 = 2 * x22 * (1. / (x18 * x18));
	const GEN_FLT x90 = x89 * obj_qi;
	const GEN_FLT x91 = x24 * (1. / (x18 * sqrt(x18)));
	const GEN_FLT x92 = x91 * x17;
	const GEN_FLT x93 = (x92 * obj_qi) + (-1 * x90 * x17);
	const GEN_FLT x94 = x21 * x19;
	const GEN_FLT x95 = x94 * x16;
	const GEN_FLT x96 = x91 * x16;
	const GEN_FLT x97 = obj_qk * obj_qj;
	const GEN_FLT x98 = x91 * x97;
	const GEN_FLT x99 = (x98 * obj_qi) + (-1 * x90 * x97);
	const GEN_FLT x100 = x99 + (-1 * x25);
	const GEN_FLT x101 = x23 * obj_qj;
	const GEN_FLT x102 = x89 * x16;
	const GEN_FLT x103 = (x96 * obj_qj) + (-1 * x102 * obj_qj);
	const GEN_FLT x104 = x103 + x101;
	const GEN_FLT x105 = obj_qk * obj_qi;
	const GEN_FLT x106 = x91 * x105;
	const GEN_FLT x107 = x94 * x105;
	const GEN_FLT x108 = x107 + (-1 * x106);
	const GEN_FLT x109 = ((x108 + x104) * sensor_x) + ((x93 + x41) * sensor_y) + ((x100 + (-1 * x95) + x96) * sensor_z);
	const GEN_FLT x110 = x91 * x15;
	const GEN_FLT x111 = (x110 * obj_qi) + (-1 * x90 * x15);
	const GEN_FLT x112 = x99 + x25;
	const GEN_FLT x113 = (x96 * obj_qk) + (-1 * x102 * obj_qk);
	const GEN_FLT x114 = x113 + x28;
	const GEN_FLT x115 = obj_qj * obj_qi;
	const GEN_FLT x116 = x91 * x115;
	const GEN_FLT x117 = x94 * x115;
	const GEN_FLT x118 = (-1 * x117) + x116;
	const GEN_FLT x119 =
		((x111 + x41) * sensor_z) + ((x118 + x114) * sensor_x) + ((x112 + x95 + (-1 * x96)) * sensor_y);
	const GEN_FLT x120 = obj_qi * obj_qi * obj_qi;
	const GEN_FLT x121 = (-1 * x107) + x106;
	const GEN_FLT x122 = x117 + (-1 * x116);
	const GEN_FLT x123 = ((x122 + x114) * sensor_z) +
						 (((2 * x35) + (x91 * x120) + x41 + (-1 * x89 * x120)) * sensor_x) + ((x121 + x104) * sensor_y);
	const GEN_FLT x124 = (x11 * x123) + (x46 * x109) + (x45 * x119);
	const GEN_FLT x125 = x50 * x124;
	const GEN_FLT x126 = (x40 * x123) + (x14 * x119) + (x43 * x109);
	const GEN_FLT x127 = x52 * x126;
	const GEN_FLT x128 = (x62 * x109) + (x61 * x123) + (x60 * x119);
	const GEN_FLT x129 = ((-1 * x52 * x128) + (x64 * x124)) * x68;
	const GEN_FLT x130 = x71 * x124;
	const GEN_FLT x131 = (-1 * x75 * ((x74 * x126) + (-1 * x73 * (x130 + (x70 * x128))))) + (-1 * x129);
	const GEN_FLT x132 = obj_qj * obj_qj * obj_qj;
	const GEN_FLT x133 = (x92 * obj_qk) + (-1 * x89 * x17 * obj_qk);
	const GEN_FLT x134 = x133 + x28;
	const GEN_FLT x135 = x97 * x94;
	const GEN_FLT x136 = x135 + (-1 * x98);
	const GEN_FLT x137 = x93 + x35;
	const GEN_FLT x138 = ((x137 + x136) * sensor_x) +
						 (((x91 * x132) + (2 * x101) + x27 + (-1 * x89 * x132)) * sensor_y) +
						 ((x134 + x118) * sensor_z);
	const GEN_FLT x139 = (x110 * obj_qj) + (-1 * x89 * x15 * obj_qj);
	const GEN_FLT x140 = x94 * x17;
	const GEN_FLT x141 =
		((x100 + (-1 * x140) + x92) * sensor_x) + ((x122 + x134) * sensor_y) + ((x139 + x27) * sensor_z);
	const GEN_FLT x142 = (-1 * x135) + x98;
	const GEN_FLT x143 =
		((x137 + x142) * sensor_y) + ((x112 + x140 + (-1 * x92)) * sensor_z) + ((x103 + x27) * sensor_x);
	const GEN_FLT x144 = (x11 * x143) + (x46 * x138) + (x45 * x141);
	const GEN_FLT x145 = x50 * x144;
	const GEN_FLT x146 = (x40 * x143) + (x43 * x138) + (x14 * x141);
	const GEN_FLT x147 = x52 * x146;
	const GEN_FLT x148 = (x61 * x143) + (x62 * x138) + (x60 * x141);
	const GEN_FLT x149 = ((-1 * x52 * x148) + (x64 * x144)) * x68;
	const GEN_FLT x150 = x71 * x144;
	const GEN_FLT x151 = (-1 * x75 * ((x74 * x146) + (-1 * x73 * (x150 + (x70 * x148))))) + (-1 * x149);
	const GEN_FLT x152 = x139 + x101;
	const GEN_FLT x153 = x94 * x15;
	const GEN_FLT x154 =
		((x112 + (-1 * x110) + x153) * sensor_x) + ((x133 + x34) * sensor_y) + ((x152 + x121) * sensor_z);
	const GEN_FLT x155 = obj_qk * obj_qk * obj_qk;
	const GEN_FLT x156 = x111 + x35;
	const GEN_FLT x157 = ((x142 + x156) * sensor_x) + ((x152 + x108) * sensor_y) +
						 (((2 * x28) + (-1 * x89 * x155) + x34 + (x91 * x155)) * sensor_z);
	const GEN_FLT x158 =
		((x136 + x156) * sensor_z) + ((x100 + x110 + (-1 * x153)) * sensor_y) + ((x113 + x34) * sensor_x);
	const GEN_FLT x159 = (x11 * x158) + (x46 * x154) + (x45 * x157);
	const GEN_FLT x160 = x50 * x159;
	const GEN_FLT x161 = (x40 * x158) + (x43 * x154) + (x14 * x157);
	const GEN_FLT x162 = x52 * x161;
	const GEN_FLT x163 = (x61 * x158) + (x62 * x154) + (x60 * x157);
	const GEN_FLT x164 = ((-1 * x52 * x163) + (x64 * x159)) * x68;
	const GEN_FLT x165 = x71 * x159;
	const GEN_FLT x166 = (-1 * x75 * ((x74 * x161) + (-1 * x73 * (x165 + (x70 * x163))))) + (-1 * x164);
	const GEN_FLT x167 = 2 * x77 * curve_1;
	const GEN_FLT x168 = 1. / sqrt(1 + (-1 * x65 * x57 * (tilt_1 * tilt_1)));
	const GEN_FLT x169 = 2 * x44;
	const GEN_FLT x170 = 1.0 / 2.0 * x63 * (1. / (x56 * sqrt(x56))) * tilt_1;
	const GEN_FLT x171 = (1. / sqrt(x56)) * tilt_1;
	const GEN_FLT x172 =
		(-1 * x168 * ((x61 * x171) + (-1 * x170 * (x72 + (x40 * x169))))) + (-1 * (x53 + (-1 * x51)) * x58);
	const GEN_FLT x173 =
		sin(1.5707963267949 + (-1 * atan2(-1 * x44, x54)) + gibPhase_1 + (-1 * phase_1) + (-1 * asin(x63 * x171))) *
		gibMag_1;
	const GEN_FLT x174 =
		(-1 * x168 * ((x62 * x171) + (-1 * x170 * (x82 + (x43 * x169))))) + (-1 * (x80 + (-1 * x79)) * x58);
	const GEN_FLT x175 =
		(-1 * x168 * ((x60 * x171) + (-1 * x170 * (x87 + (x14 * x169))))) + (-1 * (x85 + (-1 * x84)) * x58);
	const GEN_FLT x176 =
		(-1 * x168 * ((x128 * x171) + (-1 * x170 * (x130 + (x126 * x169))))) + (-1 * (x127 + (-1 * x125)) * x58);
	const GEN_FLT x177 =
		(-1 * x168 * ((x171 * x148) + (-1 * x170 * (x150 + (x169 * x146))))) + (-1 * (x147 + (-1 * x145)) * x58);
	const GEN_FLT x178 =
		(-1 * x168 * ((x163 * x171) + (-1 * x170 * (x165 + (x161 * x169))))) + (-1 * (x162 + (-1 * x160)) * x58);
	out[0] = x76 + (((-1 * x53) + x51) * x59) + (x78 * x76);
	out[1] = (((-1 * x80) + x79) * x59) + x83 + (x83 * x78);
	out[2] = x88 + (((-1 * x85) + x84) * x59) + (x88 * x78);
	out[3] = x131 + (((-1 * x127) + x125) * x59) + (x78 * x131);
	out[4] = x151 + (((-1 * x147) + x145) * x59) + (x78 * x151);
	out[5] = x166 + (((-1 * x162) + x160) * x59) + (x78 * x166);
	out[6] = x172 + (x69 * x167) + (x172 * x173);
	out[7] = (x81 * x167) + x174 + (x174 * x173);
	out[8] = x175 + (x86 * x167) + (x175 * x173);
	out[9] = x176 + (x129 * x167) + (x176 * x173);
	out[10] = x177 + (x167 * x149) + (x177 * x173);
	out[11] = x178 + (x167 * x164) + (x178 * x173);
}

// Jacobian of reproject wrt [sensor_x, sensor_y, sensor_z]
static inline void gen_reproject_jac_sensor_pt_axis_angle(FLT *out, const LinmathAxisAnglePose *obj_p,
														  const FLT *sensor_pt, const LinmathAxisAnglePose *lh_p,
														  const BaseStationCal *bsd) {
	const GEN_FLT obj_px = (*obj_p).Pos[0];
	const GEN_FLT obj_py = (*obj_p).Pos[1];
	const GEN_FLT obj_pz = (*obj_p).Pos[2];
	const GEN_FLT obj_qi = (*obj_p).AxisAngleRot[0];
	const GEN_FLT obj_qj = (*obj_p).AxisAngleRot[1];
	const GEN_FLT obj_qk = (*obj_p).AxisAngleRot[2];
	const GEN_FLT sensor_x = sensor_pt[0];
	const GEN_FLT sensor_y = sensor_pt[1];
	const GEN_FLT sensor_z = sensor_pt[2];
	const GEN_FLT lh_px = (*lh_p).Pos[0];
	const GEN_FLT lh_py = (*lh_p).Pos[1];
	const GEN_FLT lh_pz = (*lh_p).Pos[2];
	const GEN_FLT lh_qi = (*lh_p).AxisAngleRot[0];
	const GEN_FLT lh_qj = (*lh_p).AxisAngleRot[1];
	const GEN_FLT lh_qk = (*lh_p).AxisAngleRot[2];
	const GEN_FLT phase_0 = bsd[0].phase;
	const GEN_FLT tilt_0 = bsd[0].tilt;
	const GEN_FLT curve_0 = bsd[0].curve;
	const GEN_FLT gibPhase_0 = bsd[0].gibpha;
	const GEN_FLT gibMag_0 = bsd[0].gibmag;
	const GEN_FLT ogeeMag_0 = bsd[0].ogeephase;
	const GEN_FLT ogeePhase_0 = bsd[0].ogeemag;
	const GEN_FLT phase_1 = bsd[1].phase;
	const GEN_FLT tilt_1 = bsd[1].tilt;
	const GEN_FLT curve_1 = bsd[1].curve;
	const GEN_FLT gibPhase_1 = bsd[1].gibpha;
	const GEN_FLT gibMag_1 = bsd[1].gibmag;
	const GEN_FLT ogeeMag_1 = bsd[1].ogeephase;
	const GEN_FLT ogeePhase_1 = bsd[1].ogeemag;
	const GEN_FLT x0 = obj_qk * obj_qk;
	const GEN_FLT x1 = obj_qi * obj_qi;
	const GEN_FLT x2 = obj_qj * obj_qj;
	const GEN_FLT x3 = 1e-10 + x2 + x0 + x1;
	const GEN_FLT x4 = sqrt(x3);
	const GEN_FLT x5 = (1. / x4) * sin(x4);
	const GEN_FLT x6 = x5 * obj_qk;
	const GEN_FLT x7 = cos(x4);
	const GEN_FLT x8 = (1. / x3) * (1 + (-1 * x7));
	const GEN_FLT x9 = x8 * obj_qj * obj_qi;
	const GEN_FLT x10 = x9 + x6;
	const GEN_FLT x11 = lh_qk * lh_qk;
	const GEN_FLT x12 = lh_qi * lh_qi;
	const GEN_FLT x13 = lh_qj * lh_qj;
	const GEN_FLT x14 = 1e-10 + x13 + x11 + x12;
	const GEN_FLT x15 = sqrt(x14);
	const GEN_FLT x16 = (1. / x15) * sin(x15);
	const GEN_FLT x17 = x16 * lh_qi;
	const GEN_FLT x18 = cos(x15);
	const GEN_FLT x19 = (1. / x14) * (1 + (-1 * x18));
	const GEN_FLT x20 = x19 * lh_qk;
	const GEN_FLT x21 = x20 * lh_qj;
	const GEN_FLT x22 = x21 + x17;
	const GEN_FLT x23 = x5 * obj_qj;
	const GEN_FLT x24 = x8 * obj_qk;
	const GEN_FLT x25 = x24 * obj_qi;
	const GEN_FLT x26 = x25 + (-1 * x23);
	const GEN_FLT x27 = x18 + (x11 * x19);
	const GEN_FLT x28 = x16 * lh_qj;
	const GEN_FLT x29 = x20 * lh_qi;
	const GEN_FLT x30 = x29 + (-1 * x28);
	const GEN_FLT x31 = x7 + (x1 * x8);
	const GEN_FLT x32 = (x30 * x31) + (x22 * x10) + (x26 * x27);
	const GEN_FLT x33 = x21 + (-1 * x17);
	const GEN_FLT x34 = x7 + (x0 * x8);
	const GEN_FLT x35 = x5 * obj_qi;
	const GEN_FLT x36 = x24 * obj_qj;
	const GEN_FLT x37 = x36 + x35;
	const GEN_FLT x38 = (x37 * sensor_y) + (x26 * sensor_x) + obj_pz + (x34 * sensor_z);
	const GEN_FLT x39 = x25 + x23;
	const GEN_FLT x40 = x9 + (-1 * x6);
	const GEN_FLT x41 = (x40 * sensor_y) + (x39 * sensor_z) + (x31 * sensor_x) + obj_px;
	const GEN_FLT x42 = x16 * lh_qk;
	const GEN_FLT x43 = x19 * lh_qj * lh_qi;
	const GEN_FLT x44 = x43 + x42;
	const GEN_FLT x45 = x36 + (-1 * x35);
	const GEN_FLT x46 = x7 + (x2 * x8);
	const GEN_FLT x47 = (x46 * sensor_y) + (x10 * sensor_x) + obj_py + (x45 * sensor_z);
	const GEN_FLT x48 = x18 + (x13 * x19);
	const GEN_FLT x49 = (x47 * x48) + (x41 * x44) + lh_py + (x33 * x38);
	const GEN_FLT x50 = (x41 * x30) + (x47 * x22) + lh_pz + (x38 * x27);
	const GEN_FLT x51 = x50 * x50;
	const GEN_FLT x52 = 1. / x51;
	const GEN_FLT x53 = x52 * x49;
	const GEN_FLT x54 = x53 * x32;
	const GEN_FLT x55 = (x44 * x31) + (x48 * x10) + (x33 * x26);
	const GEN_FLT x56 = 1. / x50;
	const GEN_FLT x57 = x56 * x55;
	const GEN_FLT x58 = -1 * x50;
	const GEN_FLT x59 = x49 * x49;
	const GEN_FLT x60 = x51 + x59;
	const GEN_FLT x61 = 1. / x60;
	const GEN_FLT x62 = x61 * x51;
	const GEN_FLT x63 = 2 * x62 * atan2(x49, x58) * curve_0;
	const GEN_FLT x64 = x29 + x28;
	const GEN_FLT x65 = x18 + (x12 * x19);
	const GEN_FLT x66 = x43 + (-1 * x42);
	const GEN_FLT x67 = (x66 * x47) + lh_px + (x65 * x41) + (x64 * x38);
	const GEN_FLT x68 = x67 * x52;
	const GEN_FLT x69 = (x65 * x31) + (x66 * x10) + (x64 * x26);
	const GEN_FLT x70 = x67 * x67;
	const GEN_FLT x71 = x70 + x51;
	const GEN_FLT x72 = 1. / x71;
	const GEN_FLT x73 = x72 * x51;
	const GEN_FLT x74 = ((-1 * x69 * x56) + (x68 * x32)) * x73;
	const GEN_FLT x75 = 1. / sqrt(1 + (-1 * x72 * x59 * (tilt_0 * tilt_0)));
	const GEN_FLT x76 = 2 * x67;
	const GEN_FLT x77 = 2 * x50;
	const GEN_FLT x78 = x77 * x32;
	const GEN_FLT x79 = 1.0 / 2.0 * (1. / (x71 * sqrt(x71))) * x49 * tilt_0;
	const GEN_FLT x80 = (1. / sqrt(x71)) * tilt_0;
	const GEN_FLT x81 = (-1 * x75 * ((x80 * x55) + (-1 * x79 * (x78 + (x76 * x69))))) + (-1 * x74);
	const GEN_FLT x82 = atan2(x67, x58);
	const GEN_FLT x83 =
		sin(1.5707963267949 + (-1 * phase_0) + (-1 * x82) + (-1 * asin(x80 * x49)) + gibPhase_0) * gibMag_0;
	const GEN_FLT x84 = (x40 * x30) + (x46 * x22) + (x37 * x27);
	const GEN_FLT x85 = x84 * x53;
	const GEN_FLT x86 = (x40 * x44) + (x33 * x37) + (x46 * x48);
	const GEN_FLT x87 = x86 * x56;
	const GEN_FLT x88 = (x65 * x40) + (x66 * x46) + (x64 * x37);
	const GEN_FLT x89 = ((-1 * x88 * x56) + (x84 * x68)) * x73;
	const GEN_FLT x90 = x84 * x77;
	const GEN_FLT x91 = (-1 * x75 * ((x80 * x86) + (-1 * x79 * (x90 + (x88 * x76))))) + (-1 * x89);
	const GEN_FLT x92 = (x30 * x39) + (x45 * x22) + (x34 * x27);
	const GEN_FLT x93 = x53 * x92;
	const GEN_FLT x94 = (x45 * x48) + (x44 * x39) + (x34 * x33);
	const GEN_FLT x95 = x56 * x94;
	const GEN_FLT x96 = (x66 * x45) + (x65 * x39) + (x64 * x34);
	const GEN_FLT x97 = ((-1 * x56 * x96) + (x68 * x92)) * x73;
	const GEN_FLT x98 = x77 * x92;
	const GEN_FLT x99 = (-1 * x75 * ((x80 * x94) + (-1 * x79 * (x98 + (x76 * x96))))) + (-1 * x97);
	const GEN_FLT x100 = 2 * x82 * curve_1;
	const GEN_FLT x101 = 1. / sqrt(1 + (-1 * x70 * x61 * (tilt_1 * tilt_1)));
	const GEN_FLT x102 = 2 * x49;
	const GEN_FLT x103 = 1.0 / 2.0 * (1. / (x60 * sqrt(x60))) * x67 * tilt_1;
	const GEN_FLT x104 = (1. / sqrt(x60)) * tilt_1;
	const GEN_FLT x105 =
		(-1 * x101 * ((x69 * x104) + (-1 * x103 * (x78 + (x55 * x102))))) + (-1 * (x57 + (-1 * x54)) * x62);
	const GEN_FLT x106 =
		sin(1.5707963267949 + (-1 * phase_1) + (-1 * atan2(-1 * x49, x58)) + gibPhase_1 + (-1 * asin(x67 * x104))) *
		gibMag_1;
	const GEN_FLT x107 =
		(-1 * x101 * ((x88 * x104) + (-1 * x103 * (x90 + (x86 * x102))))) + (-1 * (x87 + (-1 * x85)) * x62);
	const GEN_FLT x108 =
		(-1 * x101 * ((x96 * x104) + (-1 * x103 * (x98 + (x94 * x102))))) + (-1 * (x95 + (-1 * x93)) * x62);
	out[0] = x81 + (((-1 * x57) + x54) * x63) + (x81 * x83);
	out[1] = (((-1 * x87) + x85) * x63) + x91 + (x83 * x91);
	out[2] = x99 + (((-1 * x95) + x93) * x63) + (x83 * x99);
	out[3] = x105 + (x74 * x100) + (x105 * x106);
	out[4] = x107 + (x89 * x100) + (x107 * x106);
	out[5] = x108 + (x97 * x100) + (x108 * x106);
}

// Jacobian of reproject wrt [lh_px, lh_py, lh_pz, lh_qi, lh_qj, lh_qk]
static inline void gen_reproject_jac_lh_p_axis_angle(FLT *out, const LinmathAxisAnglePose *obj_p, const FLT *sensor_pt,
													 const LinmathAxisAnglePose *lh_p, const BaseStationCal *bsd) {
	const GEN_FLT obj_px = (*obj_p).Pos[0];
	const GEN_FLT obj_py = (*obj_p).Pos[1];
	const GEN_FLT obj_pz = (*obj_p).Pos[2];
	const GEN_FLT obj_qi = (*obj_p).AxisAngleRot[0];
	const GEN_FLT obj_qj = (*obj_p).AxisAngleRot[1];
	const GEN_FLT obj_qk = (*obj_p).AxisAngleRot[2];
	const GEN_FLT sensor_x = sensor_pt[0];
	const GEN_FLT sensor_y = sensor_pt[1];
	const GEN_FLT sensor_z = sensor_pt[2];
	const GEN_FLT lh_px = (*lh_p).Pos[0];
	const GEN_FLT lh_py = (*lh_p).Pos[1];
	const GEN_FLT lh_pz = (*lh_p).Pos[2];
	const GEN_FLT lh_qi = (*lh_p).AxisAngleRot[0];
	const GEN_FLT lh_qj = (*lh_p).AxisAngleRot[1];
	const GEN_FLT lh_qk = (*lh_p).AxisAngleRot[2];
	const GEN_FLT phase_0 = bsd[0].phase;
	const GEN_FLT tilt_0 = bsd[0].tilt;
	const GEN_FLT curve_0 = bsd[0].curve;
	const GEN_FLT gibPhase_0 = bsd[0].gibpha;
	const GEN_FLT gibMag_0 = bsd[0].gibmag;
	const GEN_FLT ogeeMag_0 = bsd[0].ogeephase;
	const GEN_FLT ogeePhase_0 = bsd[0].ogeemag;
	const GEN_FLT phase_1 = bsd[1].phase;
	const GEN_FLT tilt_1 = bsd[1].tilt;
	const GEN_FLT curve_1 = bsd[1].curve;
	const GEN_FLT gibPhase_1 = bsd[1].gibpha;
	const GEN_FLT gibMag_1 = bsd[1].gibmag;
	const GEN_FLT ogeeMag_1 = bsd[1].ogeephase;
	const GEN_FLT ogeePhase_1 = bsd[1].ogeemag;
	const GEN_FLT x0 = lh_qk * lh_qk;
	const GEN_FLT x1 = lh_qi * lh_qi;
	const GEN_FLT x2 = lh_qj * lh_qj;
	const GEN_FLT x3 = 1e-10 + x2 + x0 + x1;
	const GEN_FLT x4 = sqrt(x3);
	const GEN_FLT x5 = sin(x4);
	const GEN_FLT x6 = (1. / x4) * x5;
	const GEN_FLT x7 = x6 * lh_qj;
	const GEN_FLT x8 = cos(x4);
	const GEN_FLT x9 = 1 + (-1 * x8);
	const GEN_FLT x10 = 1. / x3;
	const GEN_FLT x11 = x9 * x10;
	const GEN_FLT x12 = x11 * lh_qi;
	const GEN_FLT x13 = x12 * lh_qk;
	const GEN_FLT x14 = obj_qk * obj_qk;
	const GEN_FLT x15 = obj_qi * obj_qi;
	const GEN_FLT x16 = obj_qj * obj_qj;
	const GEN_FLT x17 = 1e-10 + x14 + x16 + x15;
	const GEN_FLT x18 = sqrt(x17);
	const GEN_FLT x19 = cos(x18);
	const GEN_FLT x20 = (1. / x17) * (1 + (-1 * x19));
	const GEN_FLT x21 = (1. / x18) * sin(x18);
	const GEN_FLT x22 = x21 * obj_qj;
	const GEN_FLT x23 = x20 * obj_qi;
	const GEN_FLT x24 = x23 * obj_qk;
	const GEN_FLT x25 = x21 * obj_qi;
	const GEN_FLT x26 = x20 * obj_qk * obj_qj;
	const GEN_FLT x27 =
		((x26 + x25) * sensor_y) + ((x24 + (-1 * x22)) * sensor_x) + obj_pz + ((x19 + (x20 * x14)) * sensor_z);
	const GEN_FLT x28 = x21 * obj_qk;
	const GEN_FLT x29 = x23 * obj_qj;
	const GEN_FLT x30 =
		((x29 + (-1 * x28)) * sensor_y) + ((x24 + x22) * sensor_z) + ((x19 + (x20 * x15)) * sensor_x) + obj_px;
	const GEN_FLT x31 =
		((x29 + x28) * sensor_x) + ((x19 + (x20 * x16)) * sensor_y) + obj_py + ((x26 + (-1 * x25)) * sensor_z);
	const GEN_FLT x32 = x6 * lh_qk;
	const GEN_FLT x33 = -1 * x32;
	const GEN_FLT x34 = x11 * lh_qj;
	const GEN_FLT x35 = x34 * lh_qi;
	const GEN_FLT x36 = ((x35 + x33) * x31) + (x30 * (x8 + (x1 * x11))) + lh_px + (x27 * (x13 + x7));
	const GEN_FLT x37 = x36 * x36;
	const GEN_FLT x38 = -1 * x7;
	const GEN_FLT x39 = x6 * lh_qi;
	const GEN_FLT x40 = x34 * lh_qk;
	const GEN_FLT x41 = ((x40 + x39) * x31) + lh_pz + ((x13 + x38) * x30) + (x27 * (x8 + (x0 * x11)));
	const GEN_FLT x42 = x41 * x41;
	const GEN_FLT x43 = x42 + x37;
	const GEN_FLT x44 = 1. / x43;
	const GEN_FLT x45 = x41 * x44;
	const GEN_FLT x46 = -1 * x39;
	const GEN_FLT x47 = lh_py + (x31 * (x8 + (x2 * x11))) + ((x35 + x32) * x30) + ((x40 + x46) * x27);
	const GEN_FLT x48 = x47 * x47;
	const GEN_FLT x49 = 1. / sqrt(1 + (-1 * x44 * x48 * (tilt_0 * tilt_0)));
	const GEN_FLT x50 = (1. / (x43 * sqrt(x43))) * x47 * tilt_0;
	const GEN_FLT x51 = x50 * x49;
	const GEN_FLT x52 = (x51 * x36) + x45;
	const GEN_FLT x53 = (1. / sqrt(x43)) * tilt_0;
	const GEN_FLT x54 = -1 * x41;
	const GEN_FLT x55 = atan2(x36, x54);
	const GEN_FLT x56 =
		sin(1.5707963267949 + (-1 * phase_0) + (-1 * x55) + (-1 * asin(x53 * x47)) + gibPhase_0) * gibMag_0;
	const GEN_FLT x57 = x53 * x49;
	const GEN_FLT x58 = x42 + x48;
	const GEN_FLT x59 = 1. / x58;
	const GEN_FLT x60 = x59 * x41;
	const GEN_FLT x61 = 2 * atan2(x47, x54) * curve_0;
	const GEN_FLT x62 = x59 * x47;
	const GEN_FLT x63 = x44 * x36;
	const GEN_FLT x64 = (x51 * x41) + (-1 * x63);
	const GEN_FLT x65 = x8 * x10;
	const GEN_FLT x66 = x1 * x65;
	const GEN_FLT x67 = (1. / (x3 * sqrt(x3))) * x5;
	const GEN_FLT x68 = x1 * x67;
	const GEN_FLT x69 = x67 * lh_qk;
	const GEN_FLT x70 = x69 * lh_qi;
	const GEN_FLT x71 = lh_qj * lh_qi;
	const GEN_FLT x72 = 2 * (1. / (x3 * x3)) * x9;
	const GEN_FLT x73 = (-1 * x71 * x72 * lh_qk) + (x70 * lh_qj);
	const GEN_FLT x74 = x73 + x6;
	const GEN_FLT x75 = x0 * x72;
	const GEN_FLT x76 = x0 * x67;
	const GEN_FLT x77 = (x76 * lh_qi) + (-1 * x75 * lh_qi);
	const GEN_FLT x78 = x11 * lh_qk;
	const GEN_FLT x79 = x1 * x72;
	const GEN_FLT x80 = (x68 * lh_qk) + (-1 * x79 * lh_qk);
	const GEN_FLT x81 = x80 + x78;
	const GEN_FLT x82 = x71 * x65;
	const GEN_FLT x83 = x71 * x67;
	const GEN_FLT x84 = x83 + (-1 * x82);
	const GEN_FLT x85 = (x31 * (x66 + x74 + (-1 * x68))) + ((x84 + x81) * x30) + ((x77 + x46) * x27);
	const GEN_FLT x86 = 1. / x42;
	const GEN_FLT x87 = x86 * x47;
	const GEN_FLT x88 = x85 * x87;
	const GEN_FLT x89 = x2 * x72;
	const GEN_FLT x90 = x2 * x67;
	const GEN_FLT x91 = (x90 * lh_qi) + (-1 * x89 * lh_qi);
	const GEN_FLT x92 = x73 + (-1 * x6);
	const GEN_FLT x93 = (x68 * lh_qj) + (-1 * x79 * lh_qj);
	const GEN_FLT x94 = x93 + x34;
	const GEN_FLT x95 = x65 * lh_qk;
	const GEN_FLT x96 = x95 * lh_qi;
	const GEN_FLT x97 = (-1 * x70) + x96;
	const GEN_FLT x98 = ((x97 + x94) * x30) + ((x91 + x46) * x31) + (x27 * (x92 + (-1 * x66) + x68));
	const GEN_FLT x99 = 1. / x41;
	const GEN_FLT x100 = x99 * x98;
	const GEN_FLT x101 = x59 * x42;
	const GEN_FLT x102 = x61 * x101;
	const GEN_FLT x103 = x86 * x36;
	const GEN_FLT x104 = x70 + (-1 * x96);
	const GEN_FLT x105 = (-1 * x83) + x82;
	const GEN_FLT x106 = lh_qi * lh_qi * lh_qi;
	const GEN_FLT x107 =
		(((2 * x12) + (-1 * x72 * x106) + x46 + (x67 * x106)) * x30) + (x31 * (x104 + x94)) + (x27 * (x105 + x81));
	const GEN_FLT x108 = x42 * x44;
	const GEN_FLT x109 = ((-1 * x99 * x107) + (x85 * x103)) * x108;
	const GEN_FLT x110 = 2 * x36;
	const GEN_FLT x111 = 2 * x41;
	const GEN_FLT x112 = x85 * x111;
	const GEN_FLT x113 = 1.0 / 2.0 * x50;
	const GEN_FLT x114 = (-1 * x49 * ((x53 * x98) + (-1 * x113 * (x112 + (x107 * x110))))) + (-1 * x109);
	const GEN_FLT x115 = (x90 * lh_qk) + (-1 * x89 * lh_qk);
	const GEN_FLT x116 = x115 + x78;
	const GEN_FLT x117 = (x76 * lh_qj) + (-1 * x75 * lh_qj);
	const GEN_FLT x118 = x2 * x65;
	const GEN_FLT x119 = (x30 * (x92 + (-1 * x118) + x90)) + ((x116 + x105) * x31) + (x27 * (x117 + x38));
	const GEN_FLT x120 = x87 * x119;
	const GEN_FLT x121 = lh_qj * lh_qj * lh_qj;
	const GEN_FLT x122 = x91 + x12;
	const GEN_FLT x123 = x95 * lh_qj;
	const GEN_FLT x124 = x69 * lh_qj;
	const GEN_FLT x125 = (-1 * x124) + x123;
	const GEN_FLT x126 =
		((x125 + x122) * x30) + (((-1 * x72 * x121) + (x67 * x121) + x38 + (2 * x34)) * x31) + (x27 * (x116 + x84));
	const GEN_FLT x127 = x99 * x126;
	const GEN_FLT x128 = x124 + (-1 * x123);
	const GEN_FLT x129 = ((x93 + x38) * x30) + ((x128 + x122) * x31) + (x27 * (x74 + x118 + (-1 * x90)));
	const GEN_FLT x130 = x108 * ((-1 * x99 * x129) + (x103 * x119));
	const GEN_FLT x131 = x111 * x119;
	const GEN_FLT x132 = (-1 * x49 * ((x53 * x126) + (-1 * x113 * (x131 + (x110 * x129))))) + (-1 * x130);
	const GEN_FLT x133 = x117 + x34;
	const GEN_FLT x134 = lh_qk * lh_qk * lh_qk;
	const GEN_FLT x135 = x77 + x12;
	const GEN_FLT x136 =
		((x135 + x128) * x30) + (x31 * (x133 + x97)) + (((2 * x78) + x33 + (x67 * x134) + (-1 * x72 * x134)) * x27);
	const GEN_FLT x137 = x87 * x136;
	const GEN_FLT x138 = x0 * x65;
	const GEN_FLT x139 = (x30 * (x74 + (-1 * x76) + x138)) + ((x133 + x104) * x27) + (x31 * (x115 + x33));
	const GEN_FLT x140 = x99 * x139;
	const GEN_FLT x141 = ((x80 + x33) * x30) + (x31 * (x92 + x76 + (-1 * x138))) + ((x135 + x125) * x27);
	const GEN_FLT x142 = x108 * ((-1 * x99 * x141) + (x103 * x136));
	const GEN_FLT x143 = x111 * x136;
	const GEN_FLT x144 = (-1 * x49 * ((x53 * x139) + (-1 * x113 * (x143 + (x110 * x141))))) + (-1 * x142);
	const GEN_FLT x145 = 1. / sqrt(1 + (-1 * x59 * x37 * (tilt_1 * tilt_1)));
	const GEN_FLT x146 = (1. / sqrt(x58)) * tilt_1;
	const GEN_FLT x147 = x146 * x145;
	const GEN_FLT x148 = 2 * x55 * curve_1;
	const GEN_FLT x149 =
		sin(1.5707963267949 + (-1 * phase_1) + gibPhase_1 + (-1 * atan2(-1 * x47, x54)) + (-1 * asin(x36 * x146))) *
		gibMag_1;
	const GEN_FLT x150 = (1. / (x58 * sqrt(x58))) * x36 * tilt_1;
	const GEN_FLT x151 = x145 * x150;
	const GEN_FLT x152 = (x47 * x151) + (-1 * x60);
	const GEN_FLT x153 = (x41 * x151) + x62;
	const GEN_FLT x154 = 2 * x47;
	const GEN_FLT x155 = 1.0 / 2.0 * x150;
	const GEN_FLT x156 =
		(-1 * x145 * ((x107 * x146) + (-1 * x155 * (x112 + (x98 * x154))))) + (-1 * x101 * (x100 + (-1 * x88)));
	const GEN_FLT x157 =
		(-1 * x145 * ((x129 * x146) + (-1 * x155 * (x131 + (x126 * x154))))) + (-1 * (x127 + (-1 * x120)) * x101);
	const GEN_FLT x158 =
		(-1 * x145 * ((x141 * x146) + (-1 * x155 * (x143 + (x139 * x154))))) + (-1 * (x140 + (-1 * x137)) * x101);
	out[0] = x52 + (x52 * x56);
	out[1] = (-1 * x57 * x56) + (-1 * x57) + (-1 * x60 * x61);
	out[2] = x64 + (x61 * x62) + (x64 * x56);
	out[3] = (x102 * ((-1 * x100) + x88)) + x114 + (x56 * x114);
	out[4] = x132 + (((-1 * x127) + x120) * x102) + (x56 * x132);
	out[5] = x144 + (((-1 * x140) + x137) * x102) + (x56 * x144);
	out[6] = (-1 * x147 * x149) + (-1 * x147) + (-1 * x45 * x148);
	out[7] = x152 + (x149 * x152);
	out[8] = (x63 * x148) + x153 + (x149 * x153);
	out[9] = x156 + (x109 * x148) + (x149 * x156);
	out[10] = x157 + (x130 * x148) + (x149 * x157);
	out[11] = x158 + (x142 * x148) + (x149 * x158);
}

// Jacobian of reproject wrt [phase_0, tilt_0, curve_0, gibPhase_0, gibMag_0, ogeeMag_0, ogeePhase_0, phase_1, tilt_1,
// curve_1, gibPhase_1, gibMag_1, ogeeMag_1, ogeePhase_1]
static inline void gen_reproject_jac_bsd_axis_angle(FLT *out, const LinmathAxisAnglePose *obj_p, const FLT *sensor_pt,
													const LinmathAxisAnglePose *lh_p, const BaseStationCal *bsd) {
	const GEN_FLT obj_px = (*obj_p).Pos[0];
	const GEN_FLT obj_py = (*obj_p).Pos[1];
	const GEN_FLT obj_pz = (*obj_p).Pos[2];
	const GEN_FLT obj_qi = (*obj_p).AxisAngleRot[0];
	const GEN_FLT obj_qj = (*obj_p).AxisAngleRot[1];
	const GEN_FLT obj_qk = (*obj_p).AxisAngleRot[2];
	const GEN_FLT sensor_x = sensor_pt[0];
	const GEN_FLT sensor_y = sensor_pt[1];
	const GEN_FLT sensor_z = sensor_pt[2];
	const GEN_FLT lh_px = (*lh_p).Pos[0];
	const GEN_FLT lh_py = (*lh_p).Pos[1];
	const GEN_FLT lh_pz = (*lh_p).Pos[2];
	const GEN_FLT lh_qi = (*lh_p).AxisAngleRot[0];
	const GEN_FLT lh_qj = (*lh_p).AxisAngleRot[1];
	const GEN_FLT lh_qk = (*lh_p).AxisAngleRot[2];
	const GEN_FLT phase_0 = bsd[0].phase;
	const GEN_FLT tilt_0 = bsd[0].tilt;
	const GEN_FLT curve_0 = bsd[0].curve;
	const GEN_FLT gibPhase_0 = bsd[0].gibpha;
	const GEN_FLT gibMag_0 = bsd[0].gibmag;
	const GEN_FLT ogeeMag_0 = bsd[0].ogeephase;
	const GEN_FLT ogeePhase_0 = bsd[0].ogeemag;
	const GEN_FLT phase_1 = bsd[1].phase;
	const GEN_FLT tilt_1 = bsd[1].tilt;
	const GEN_FLT curve_1 = bsd[1].curve;
	const GEN_FLT gibPhase_1 = bsd[1].gibpha;
	const GEN_FLT gibMag_1 = bsd[1].gibmag;
	const GEN_FLT ogeeMag_1 = bsd[1].ogeephase;
	const GEN_FLT ogeePhase_1 = bsd[1].ogeemag;
	const GEN_FLT x0 = lh_qk * lh_qk;
	const GEN_FLT x1 = lh_qi * lh_qi;
	const GEN_FLT x2 = lh_qj * lh_qj;
	const GEN_FLT x3 = 1e-10 + x2 + x0 + x1;
	const GEN_FLT x4 = sqrt(x3);
	const GEN_FLT x5 = (1. / x4) * sin(x4);
	const GEN_FLT x6 = x5 * lh_qi;
	const GEN_FLT x7 = cos(x4);
	const GEN_FLT x8 = (1. / x3) * (1 + (-1 * x7));
	const GEN_FLT x9 = x8 * lh_qj;
	const GEN_FLT x10 = x9 * lh_qk;
	const GEN_FLT x11 = obj_qk * obj_qk;
	const GEN_FLT x12 = obj_qi * obj_qi;
	const GEN_FLT x13 = obj_qj * obj_qj;
	const GEN_FLT x14 = 1e-10 + x13 + x11 + x12;
	const GEN_FLT x15 = sqrt(x14);
	const GEN_FLT x16 = cos(x15);
	const GEN_FLT x17 = (1. / x14) * (1 + (-1 * x16));
	const GEN_FLT x18 = (1. / x15) * sin(x15);
	const GEN_FLT x19 = x18 * obj_qj;
	const GEN_FLT x20 = x17 * obj_qk;
	const GEN_FLT x21 = x20 * obj_qi;
	const GEN_FLT x22 = x18 * obj_qi;
	const GEN_FLT x23 = x20 * obj_qj;
	const GEN_FLT x24 =
		((x23 + x22) * sensor_y) + ((x21 + (-1 * x19)) * sensor_x) + obj_pz + ((x16 + (x11 * x17)) * sensor_z);
	const GEN_FLT x25 = x18 * obj_qk;
	const GEN_FLT x26 = x17 * obj_qj * obj_qi;
	const GEN_FLT x27 =
		((x26 + (-1 * x25)) * sensor_y) + ((x21 + x19) * sensor_z) + ((x16 + (x12 * x17)) * sensor_x) + obj_px;
	const GEN_FLT x28 = x5 * lh_qk;
	const GEN_FLT x29 = x9 * lh_qi;
	const GEN_FLT x30 =
		((x26 + x25) * sensor_x) + obj_py + ((x16 + (x13 * x17)) * sensor_y) + ((x23 + (-1 * x22)) * sensor_z);
	const GEN_FLT x31 = ((x29 + x28) * x27) + lh_py + (x30 * (x7 + (x2 * x8))) + (x24 * (x10 + (-1 * x6)));
	const GEN_FLT x32 = x5 * lh_qj;
	const GEN_FLT x33 = x8 * lh_qk * lh_qi;
	const GEN_FLT x34 = ((x33 + (-1 * x32)) * x27) + lh_pz + (x30 * (x10 + x6)) + (x24 * (x7 + (x0 * x8)));
	const GEN_FLT x35 = x34 * x34;
	const GEN_FLT x36 = ((x29 + (-1 * x28)) * x30) + (x27 * (x7 + (x1 * x8))) + lh_px + ((x33 + x32) * x24);
	const GEN_FLT x37 = x36 * x36;
	const GEN_FLT x38 = x37 + x35;
	const GEN_FLT x39 = x31 * (1. / sqrt(x38));
	const GEN_FLT x40 = -1 * x34;
	const GEN_FLT x41 = atan2(x36, x40);
	const GEN_FLT x42 = 1.5707963267949 + (-1 * phase_0) + (-1 * x41) + (-1 * asin(x39 * tilt_0)) + gibPhase_0;
	const GEN_FLT x43 = sin(x42) * gibMag_0;
	const GEN_FLT x44 = x31 * x31;
	const GEN_FLT x45 = x39 * (1. / sqrt(1 + (-1 * x44 * (1. / x38) * (tilt_0 * tilt_0))));
	const GEN_FLT x46 = x44 + x35;
	const GEN_FLT x47 = (1. / sqrt(x46)) * x36;
	const GEN_FLT x48 =
		1.5707963267949 + (-1 * phase_1) + (-1 * atan2(-1 * x31, x40)) + gibPhase_1 + (-1 * asin(x47 * tilt_1));
	const GEN_FLT x49 = sin(x48) * gibMag_1;
	const GEN_FLT x50 = x47 * (1. / sqrt(1 + (-1 * (1. / x46) * x37 * (tilt_1 * tilt_1))));
	out[0] = -1 + (-1 * x43);
	out[1] = (-1 * x43 * x45) + (-1 * x45);
	out[2] = atan2(x31, x40) * atan2(x31, x40);
	out[3] = x43;
	out[4] = -1 * cos(x42);
	out[5] = 0;
	out[6] = 0;
	out[7] = 0;
	out[8] = 0;
	out[9] = 0;
	out[10] = 0;
	out[11] = 0;
	out[12] = 0;
	out[13] = 0;
	out[14] = 0;
	out[15] = 0;
	out[16] = 0;
	out[17] = 0;
	out[18] = 0;
	out[19] = 0;
	out[20] = 0;
	out[21] = -1 + (-1 * x49);
	out[22] = (-1 * x50 * x49) + (-1 * x50);
	out[23] = x41 * x41;
	out[24] = x49;
	out[25] = -1 * cos(x48);
	out[26] = 0;
	out[27] = 0;
}

static inline FLT gen_reproject_axis_x_axis_angle(const LinmathAxisAnglePose *obj_p, const FLT *sensor_pt,
												  const LinmathAxisAnglePose *lh_p, const BaseStationCal *bsc0) {
	const GEN_FLT obj_px = (*obj_p).Pos[0];
	const GEN_FLT obj_py = (*obj_p).Pos[1];
	const GEN_FLT obj_pz = (*obj_p).Pos[2];
	const GEN_FLT obj_qi = (*obj_p).AxisAngleRot[0];
	const GEN_FLT obj_qj = (*obj_p).AxisAngleRot[1];
	const GEN_FLT obj_qk = (*obj_p).AxisAngleRot[2];
	const GEN_FLT sensor_x = sensor_pt[0];
	const GEN_FLT sensor_y = sensor_pt[1];
	const GEN_FLT sensor_z = sensor_pt[2];
	const GEN_FLT lh_px = (*lh_p).Pos[0];
	const GEN_FLT lh_py = (*lh_p).Pos[1];
	const GEN_FLT lh_pz = (*lh_p).Pos[2];
	const GEN_FLT lh_qi = (*lh_p).AxisAngleRot[0];
	const GEN_FLT lh_qj = (*lh_p).AxisAngleRot[1];
	const GEN_FLT lh_qk = (*lh_p).AxisAngleRot[2];
	const GEN_FLT phase_0 = (*bsc0).phase;
	const GEN_FLT tilt_0 = (*bsc0).tilt;
	const GEN_FLT curve_0 = (*bsc0).curve;
	const GEN_FLT gibPhase_0 = (*bsc0).gibpha;
	const GEN_FLT gibMag_0 = (*bsc0).gibmag;
	const GEN_FLT ogeeMag_0 = (*bsc0).ogeephase;
	const GEN_FLT ogeePhase_0 = (*bsc0).ogeemag;
	const GEN_FLT x0 = lh_qk * lh_qk;
	const GEN_FLT x1 = lh_qi * lh_qi;
	const GEN_FLT x2 = lh_qj * lh_qj;
	const GEN_FLT x3 = 1e-10 + x2 + x0 + x1;
	const GEN_FLT x4 = sqrt(x3);
	const GEN_FLT x5 = (1. / x4) * sin(x4);
	const GEN_FLT x6 = x5 * lh_qi;
	const GEN_FLT x7 = cos(x4);
	const GEN_FLT x8 = (1. / x3) * (1 + (-1 * x7));
	const GEN_FLT x9 = x8 * lh_qj;
	const GEN_FLT x10 = x9 * lh_qk;
	const GEN_FLT x11 = obj_qk * obj_qk;
	const GEN_FLT x12 = obj_qi * obj_qi;
	const GEN_FLT x13 = obj_qj * obj_qj;
	const GEN_FLT x14 = 1e-10 + x13 + x11 + x12;
	const GEN_FLT x15 = sqrt(x14);
	const GEN_FLT x16 = cos(x15);
	const GEN_FLT x17 = (1. / x14) * (1 + (-1 * x16));
	const GEN_FLT x18 = (1. / x15) * sin(x15);
	const GEN_FLT x19 = x18 * obj_qj;
	const GEN_FLT x20 = x17 * obj_qk;
	const GEN_FLT x21 = x20 * obj_qi;
	const GEN_FLT x22 = x18 * obj_qi;
	const GEN_FLT x23 = x20 * obj_qj;
	const GEN_FLT x24 =
		((x23 + x22) * sensor_y) + ((x21 + (-1 * x19)) * sensor_x) + obj_pz + ((x16 + (x11 * x17)) * sensor_z);
	const GEN_FLT x25 = x18 * obj_qk;
	const GEN_FLT x26 = x17 * obj_qj * obj_qi;
	const GEN_FLT x27 =
		((x26 + (-1 * x25)) * sensor_y) + ((x21 + x19) * sensor_z) + ((x16 + (x12 * x17)) * sensor_x) + obj_px;
	const GEN_FLT x28 = x5 * lh_qk;
	const GEN_FLT x29 = x9 * lh_qi;
	const GEN_FLT x30 =
		((x26 + x25) * sensor_x) + obj_py + ((x16 + (x13 * x17)) * sensor_y) + ((x23 + (-1 * x22)) * sensor_z);
	const GEN_FLT x31 = ((x29 + x28) * x27) + lh_py + (x30 * (x7 + (x2 * x8))) + (x24 * (x10 + (-1 * x6)));
	const GEN_FLT x32 = x5 * lh_qj;
	const GEN_FLT x33 = x8 * lh_qk * lh_qi;
	const GEN_FLT x34 = ((x33 + (-1 * x32)) * x27) + lh_pz + (x30 * (x10 + x6)) + (x24 * (x7 + (x0 * x8)));
	const GEN_FLT x35 = -1 * x34;
	const GEN_FLT x36 = ((x29 + (-1 * x28)) * x30) + (x27 * (x7 + (x1 * x8))) + lh_px + ((x33 + x32) * x24);
	const GEN_FLT x37 =
		(-1 * phase_0) + (-1 * asin((1. / sqrt((x36 * x36) + (x34 * x34))) * x31 * tilt_0)) + (-1 * atan2(x36, x35));
	return x37 + ((atan2(x31, x35) * atan2(x31, x35)) * curve_0) +
		   (-1 * cos(1.5707963267949 + x37 + gibPhase_0) * gibMag_0);
}

// Jacobian of reproject_axis_x wrt [obj_px, obj_py, obj_pz, obj_qi, obj_qj, obj_qk]
static inline void gen_reproject_axis_x_jac_obj_p_axis_angle(FLT *out, const LinmathAxisAnglePose *obj_p,
															 const FLT *sensor_pt, const LinmathAxisAnglePose *lh_p,
															 const BaseStationCal *bsc0) {
	const GEN_FLT obj_px = (*obj_p).Pos[0];
	const GEN_FLT obj_py = (*obj_p).Pos[1];
	const GEN_FLT obj_pz = (*obj_p).Pos[2];
	const GEN_FLT obj_qi = (*obj_p).AxisAngleRot[0];
	const GEN_FLT obj_qj = (*obj_p).AxisAngleRot[1];
	const GEN_FLT obj_qk = (*obj_p).AxisAngleRot[2];
	const GEN_FLT sensor_x = sensor_pt[0];
	const GEN_FLT sensor_y = sensor_pt[1];
	const GEN_FLT sensor_z = sensor_pt[2];
	const GEN_FLT lh_px = (*lh_p).Pos[0];
	const GEN_FLT lh_py = (*lh_p).Pos[1];
	const GEN_FLT lh_pz = (*lh_p).Pos[2];
	const GEN_FLT lh_qi = (*lh_p).AxisAngleRot[0];
	const GEN_FLT lh_qj = (*lh_p).AxisAngleRot[1];
	const GEN_FLT lh_qk = (*lh_p).AxisAngleRot[2];
	const GEN_FLT phase_0 = (*bsc0).phase;
	const GEN_FLT tilt_0 = (*bsc0).tilt;
	const GEN_FLT curve_0 = (*bsc0).curve;
	const GEN_FLT gibPhase_0 = (*bsc0).gibpha;
	const GEN_FLT gibMag_0 = (*bsc0).gibmag;
	const GEN_FLT ogeeMag_0 = (*bsc0).ogeephase;
	const GEN_FLT ogeePhase_0 = (*bsc0).ogeemag;
	const GEN_FLT x0 = lh_qk * lh_qk;
	const GEN_FLT x1 = lh_qi * lh_qi;
	const GEN_FLT x2 = lh_qj * lh_qj;
	const GEN_FLT x3 = 1e-10 + x2 + x0 + x1;
	const GEN_FLT x4 = sqrt(x3);
	const GEN_FLT x5 = (1. / x4) * sin(x4);
	const GEN_FLT x6 = x5 * lh_qj;
	const GEN_FLT x7 = cos(x4);
	const GEN_FLT x8 = (1. / x3) * (1 + (-1 * x7));
	const GEN_FLT x9 = x8 * lh_qk * lh_qi;
	const GEN_FLT x10 = x9 + (-1 * x6);
	const GEN_FLT x11 = obj_qk * obj_qk;
	const GEN_FLT x12 = obj_qi * obj_qi;
	const GEN_FLT x13 = obj_qj * obj_qj;
	const GEN_FLT x14 = 1e-10 + x13 + x11 + x12;
	const GEN_FLT x15 = 1. / x14;
	const GEN_FLT x16 = sqrt(x14);
	const GEN_FLT x17 = cos(x16);
	const GEN_FLT x18 = 1 + (-1 * x17);
	const GEN_FLT x19 = x15 * x18;
	const GEN_FLT x20 = sin(x16);
	const GEN_FLT x21 = x20 * (1. / x16);
	const GEN_FLT x22 = x21 * obj_qj;
	const GEN_FLT x23 = -1 * x22;
	const GEN_FLT x24 = x19 * obj_qi;
	const GEN_FLT x25 = x24 * obj_qk;
	const GEN_FLT x26 = x21 * obj_qi;
	const GEN_FLT x27 = x19 * obj_qj;
	const GEN_FLT x28 = x27 * obj_qk;
	const GEN_FLT x29 = ((x28 + x26) * sensor_y) + ((x25 + x23) * sensor_x) + obj_pz + ((x17 + (x11 * x19)) * sensor_z);
	const GEN_FLT x30 = x7 + (x0 * x8);
	const GEN_FLT x31 = x21 * obj_qk;
	const GEN_FLT x32 = -1 * x31;
	const GEN_FLT x33 = x27 * obj_qi;
	const GEN_FLT x34 = ((x25 + x22) * sensor_z) + ((x33 + x32) * sensor_y) + ((x17 + (x12 * x19)) * sensor_x) + obj_px;
	const GEN_FLT x35 = -1 * x26;
	const GEN_FLT x36 = ((x17 + (x13 * x19)) * sensor_y) + ((x33 + x31) * sensor_x) + obj_py + ((x28 + x35) * sensor_z);
	const GEN_FLT x37 = x5 * lh_qi;
	const GEN_FLT x38 = x8 * lh_qj;
	const GEN_FLT x39 = x38 * lh_qk;
	const GEN_FLT x40 = x39 + x37;
	const GEN_FLT x41 = (x40 * x36) + (x34 * x10) + lh_pz + (x30 * x29);
	const GEN_FLT x42 = x41 * x41;
	const GEN_FLT x43 = 1. / x42;
	const GEN_FLT x44 = x39 + (-1 * x37);
	const GEN_FLT x45 = x5 * lh_qk;
	const GEN_FLT x46 = x38 * lh_qi;
	const GEN_FLT x47 = x46 + x45;
	const GEN_FLT x48 = x7 + (x2 * x8);
	const GEN_FLT x49 = (x48 * x36) + (x47 * x34) + lh_py + (x44 * x29);
	const GEN_FLT x50 = x43 * x49;
	const GEN_FLT x51 = 1. / x41;
	const GEN_FLT x52 = -1 * x41;
	const GEN_FLT x53 = x49 * x49;
	const GEN_FLT x54 = 2 * (1. / (x42 + x53)) * x42 * atan2(x49, x52) * curve_0;
	const GEN_FLT x55 = x9 + x6;
	const GEN_FLT x56 = x7 + (x1 * x8);
	const GEN_FLT x57 = x46 + (-1 * x45);
	const GEN_FLT x58 = (x57 * x36) + (x56 * x34) + lh_px + (x55 * x29);
	const GEN_FLT x59 = x58 * x43;
	const GEN_FLT x60 = x42 + (x58 * x58);
	const GEN_FLT x61 = 1. / x60;
	const GEN_FLT x62 = x61 * x42;
	const GEN_FLT x63 = 2 * x58;
	const GEN_FLT x64 = 2 * x41;
	const GEN_FLT x65 = 1.0 / 2.0 * (1. / (x60 * sqrt(x60))) * x49 * tilt_0;
	const GEN_FLT x66 = (1. / sqrt(x60)) * tilt_0;
	const GEN_FLT x67 = 1. / sqrt(1 + (-1 * x61 * x53 * (tilt_0 * tilt_0)));
	const GEN_FLT x68 = (-1 * x67 * ((x66 * x47) + (-1 * ((x64 * x10) + (x63 * x56)) * x65))) +
						(-1 * ((-1 * x51 * x56) + (x59 * x10)) * x62);
	const GEN_FLT x69 =
		sin(1.5707963267949 + (-1 * phase_0) + (-1 * atan2(x58, x52)) + (-1 * asin(x66 * x49)) + gibPhase_0) * gibMag_0;
	const GEN_FLT x70 = (-1 * x67 * ((x66 * x48) + (-1 * ((x64 * x40) + (x63 * x57)) * x65))) +
						(-1 * ((-1 * x51 * x57) + (x59 * x40)) * x62);
	const GEN_FLT x71 = (-1 * x67 * ((x66 * x44) + (-1 * ((x64 * x30) + (x63 * x55)) * x65))) +
						(-1 * ((-1 * x51 * x55) + (x59 * x30)) * x62);
	const GEN_FLT x72 = 2 * (1. / (x14 * x14)) * x18;
	const GEN_FLT x73 = x72 * obj_qi;
	const GEN_FLT x74 = x20 * (1. / (x14 * sqrt(x14)));
	const GEN_FLT x75 = x74 * x13;
	const GEN_FLT x76 = (x75 * obj_qi) + (-1 * x73 * x13);
	const GEN_FLT x77 = x15 * x17;
	const GEN_FLT x78 = x77 * x12;
	const GEN_FLT x79 = x74 * x12;
	const GEN_FLT x80 = obj_qj * obj_qi;
	const GEN_FLT x81 = x72 * obj_qk;
	const GEN_FLT x82 = x74 * obj_qk;
	const GEN_FLT x83 = x82 * obj_qj;
	const GEN_FLT x84 = (x83 * obj_qi) + (-1 * x80 * x81);
	const GEN_FLT x85 = x84 + (-1 * x21);
	const GEN_FLT x86 = x72 * obj_qj;
	const GEN_FLT x87 = (x79 * obj_qj) + (-1 * x86 * x12);
	const GEN_FLT x88 = x87 + x27;
	const GEN_FLT x89 = x82 * obj_qi;
	const GEN_FLT x90 = x77 * obj_qk;
	const GEN_FLT x91 = x90 * obj_qi;
	const GEN_FLT x92 = x91 + (-1 * x89);
	const GEN_FLT x93 = ((x92 + x88) * sensor_x) + ((x76 + x35) * sensor_y) + ((x85 + (-1 * x78) + x79) * sensor_z);
	const GEN_FLT x94 = x74 * x11;
	const GEN_FLT x95 = (x94 * obj_qi) + (-1 * x73 * x11);
	const GEN_FLT x96 = x84 + x21;
	const GEN_FLT x97 = x19 * obj_qk;
	const GEN_FLT x98 = (x79 * obj_qk) + (-1 * x81 * x12);
	const GEN_FLT x99 = x98 + x97;
	const GEN_FLT x100 = x80 * x74;
	const GEN_FLT x101 = x80 * x77;
	const GEN_FLT x102 = (-1 * x101) + x100;
	const GEN_FLT x103 = ((x95 + x35) * sensor_z) + ((x102 + x99) * sensor_x) + ((x96 + x78 + (-1 * x79)) * sensor_y);
	const GEN_FLT x104 = obj_qi * obj_qi * obj_qi;
	const GEN_FLT x105 = (-1 * x91) + x89;
	const GEN_FLT x106 = x101 + (-1 * x100);
	const GEN_FLT x107 = ((x106 + x99) * sensor_z) + (((x74 * x104) + x35 + (2 * x24) + (-1 * x72 * x104)) * sensor_x) +
						 ((x105 + x88) * sensor_y);
	const GEN_FLT x108 = (x10 * x107) + (x93 * x40) + (x30 * x103);
	const GEN_FLT x109 = (x44 * x103) + (x47 * x107) + (x93 * x48);
	const GEN_FLT x110 = (x56 * x107) + (x57 * x93) + (x55 * x103);
	const GEN_FLT x111 = (-1 * x67 * ((x66 * x109) + (-1 * ((x64 * x108) + (x63 * x110)) * x65))) +
						 (-1 * ((-1 * x51 * x110) + (x59 * x108)) * x62);
	const GEN_FLT x112 = obj_qj * obj_qj * obj_qj;
	const GEN_FLT x113 = (x75 * obj_qk) + (-1 * x81 * x13);
	const GEN_FLT x114 = x113 + x97;
	const GEN_FLT x115 = x90 * obj_qj;
	const GEN_FLT x116 = x115 + (-1 * x83);
	const GEN_FLT x117 = x76 + x24;
	const GEN_FLT x118 = ((x117 + x116) * sensor_x) +
						 ((x23 + (2 * x27) + (x74 * x112) + (-1 * x72 * x112)) * sensor_y) + ((x102 + x114) * sensor_z);
	const GEN_FLT x119 = (x94 * obj_qj) + (-1 * x86 * x11);
	const GEN_FLT x120 = x77 * x13;
	const GEN_FLT x121 =
		((x85 + (-1 * x120) + x75) * sensor_x) + ((x114 + x106) * sensor_y) + ((x119 + x23) * sensor_z);
	const GEN_FLT x122 = (-1 * x115) + x83;
	const GEN_FLT x123 = ((x96 + x120 + (-1 * x75)) * sensor_z) + ((x117 + x122) * sensor_y) + ((x87 + x23) * sensor_x);
	const GEN_FLT x124 = (x10 * x123) + (x40 * x118) + (x30 * x121);
	const GEN_FLT x125 = x43 * x124;
	const GEN_FLT x126 = (x48 * x118) + (x47 * x123) + (x44 * x121);
	const GEN_FLT x127 = (x56 * x123) + (x57 * x118) + (x55 * x121);
	const GEN_FLT x128 = (-1 * x67 * ((x66 * x126) + (-1 * ((x64 * x124) + (x63 * x127)) * x65))) +
						 (-1 * ((-1 * x51 * x127) + (x58 * x125)) * x62);
	const GEN_FLT x129 = x119 + x27;
	const GEN_FLT x130 = x77 * x11;
	const GEN_FLT x131 =
		((x96 + (-1 * x94) + x130) * sensor_x) + ((x113 + x32) * sensor_y) + ((x129 + x105) * sensor_z);
	const GEN_FLT x132 = obj_qk * obj_qk * obj_qk;
	const GEN_FLT x133 = x95 + x24;
	const GEN_FLT x134 = ((x122 + x133) * sensor_x) + ((x129 + x92) * sensor_y) +
						 (((-1 * x72 * x132) + (2 * x97) + x32 + (x74 * x132)) * sensor_z);
	const GEN_FLT x135 = ((x116 + x133) * sensor_z) + ((x85 + x94 + (-1 * x130)) * sensor_y) + ((x98 + x32) * sensor_x);
	const GEN_FLT x136 = (x10 * x135) + (x40 * x131) + (x30 * x134);
	const GEN_FLT x137 = (x47 * x135) + (x48 * x131) + (x44 * x134);
	const GEN_FLT x138 = (x56 * x135) + (x57 * x131) + (x55 * x134);
	const GEN_FLT x139 = (-1 * x67 * ((x66 * x137) + (-1 * ((x64 * x136) + (x63 * x138)) * x65))) +
						 (-1 * ((-1 * x51 * x138) + (x59 * x136)) * x62);
	out[0] = x68 + (((-1 * x51 * x47) + (x50 * x10)) * x54) + (x68 * x69);
	out[1] = x70 + (((-1 * x51 * x48) + (x50 * x40)) * x54) + (x70 * x69);
	out[2] = x71 + (((-1 * x51 * x44) + (x50 * x30)) * x54) + (x71 * x69);
	out[3] = (((-1 * x51 * x109) + (x50 * x108)) * x54) + x111 + (x69 * x111);
	out[4] = x128 + (((-1 * x51 * x126) + (x49 * x125)) * x54) + (x69 * x128);
	out[5] = (((-1 * x51 * x137) + (x50 * x136)) * x54) + x139 + (x69 * x139);
}

// Jacobian of reproject_axis_x wrt [sensor_x, sensor_y, sensor_z]
static inline void gen_reproject_axis_x_jac_sensor_pt_axis_angle(FLT *out, const LinmathAxisAnglePose *obj_p,
																 const FLT *sensor_pt, const LinmathAxisAnglePose *lh_p,
																 const BaseStationCal *bsc0) {
	const GEN_FLT obj_px = (*obj_p).Pos[0];
	const GEN_FLT obj_py = (*obj_p).Pos[1];
	const GEN_FLT obj_pz = (*obj_p).Pos[2];
	const GEN_FLT obj_qi = (*obj_p).AxisAngleRot[0];
	const GEN_FLT obj_qj = (*obj_p).AxisAngleRot[1];
	const GEN_FLT obj_qk = (*obj_p).AxisAngleRot[2];
	const GEN_FLT sensor_x = sensor_pt[0];
	const GEN_FLT sensor_y = sensor_pt[1];
	const GEN_FLT sensor_z = sensor_pt[2];
	const GEN_FLT lh_px = (*lh_p).Pos[0];
	const GEN_FLT lh_py = (*lh_p).Pos[1];
	const GEN_FLT lh_pz = (*lh_p).Pos[2];
	const GEN_FLT lh_qi = (*lh_p).AxisAngleRot[0];
	const GEN_FLT lh_qj = (*lh_p).AxisAngleRot[1];
	const GEN_FLT lh_qk = (*lh_p).AxisAngleRot[2];
	const GEN_FLT phase_0 = (*bsc0).phase;
	const GEN_FLT tilt_0 = (*bsc0).tilt;
	const GEN_FLT curve_0 = (*bsc0).curve;
	const GEN_FLT gibPhase_0 = (*bsc0).gibpha;
	const GEN_FLT gibMag_0 = (*bsc0).gibmag;
	const GEN_FLT ogeeMag_0 = (*bsc0).ogeephase;
	const GEN_FLT ogeePhase_0 = (*bsc0).ogeemag;
	const GEN_FLT x0 = obj_qk * obj_qk;
	const GEN_FLT x1 = obj_qi * obj_qi;
	const GEN_FLT x2 = obj_qj * obj_qj;
	const GEN_FLT x3 = 1e-10 + x2 + x0 + x1;
	const GEN_FLT x4 = sqrt(x3);
	const GEN_FLT x5 = (1. / x4) * sin(x4);
	const GEN_FLT x6 = x5 * obj_qk;
	const GEN_FLT x7 = cos(x4);
	const GEN_FLT x8 = (1. / x3) * (1 + (-1 * x7));
	const GEN_FLT x9 = x8 * obj_qj * obj_qi;
	const GEN_FLT x10 = x9 + x6;
	const GEN_FLT x11 = lh_qk * lh_qk;
	const GEN_FLT x12 = lh_qi * lh_qi;
	const GEN_FLT x13 = lh_qj * lh_qj;
	const GEN_FLT x14 = 1e-10 + x13 + x11 + x12;
	const GEN_FLT x15 = sqrt(x14);
	const GEN_FLT x16 = (1. / x15) * sin(x15);
	const GEN_FLT x17 = x16 * lh_qi;
	const GEN_FLT x18 = cos(x15);
	const GEN_FLT x19 = (1. / x14) * (1 + (-1 * x18));
	const GEN_FLT x20 = x19 * lh_qk * lh_qj;
	const GEN_FLT x21 = x20 + x17;
	const GEN_FLT x22 = x5 * obj_qj;
	const GEN_FLT x23 = x8 * obj_qk;
	const GEN_FLT x24 = x23 * obj_qi;
	const GEN_FLT x25 = x24 + (-1 * x22);
	const GEN_FLT x26 = x18 + (x11 * x19);
	const GEN_FLT x27 = x16 * lh_qj;
	const GEN_FLT x28 = x19 * lh_qi;
	const GEN_FLT x29 = x28 * lh_qk;
	const GEN_FLT x30 = x29 + (-1 * x27);
	const GEN_FLT x31 = x7 + (x1 * x8);
	const GEN_FLT x32 = (x30 * x31) + (x21 * x10) + (x25 * x26);
	const GEN_FLT x33 = x7 + (x0 * x8);
	const GEN_FLT x34 = x5 * obj_qi;
	const GEN_FLT x35 = x23 * obj_qj;
	const GEN_FLT x36 = x35 + x34;
	const GEN_FLT x37 = (x36 * sensor_y) + (x25 * sensor_x) + obj_pz + (x33 * sensor_z);
	const GEN_FLT x38 = x24 + x22;
	const GEN_FLT x39 = x9 + (-1 * x6);
	const GEN_FLT x40 = (x38 * sensor_z) + (x39 * sensor_y) + (x31 * sensor_x) + obj_px;
	const GEN_FLT x41 = x35 + (-1 * x34);
	const GEN_FLT x42 = x7 + (x2 * x8);
	const GEN_FLT x43 = (x42 * sensor_y) + (x10 * sensor_x) + obj_py + (x41 * sensor_z);
	const GEN_FLT x44 = (x43 * x21) + (x40 * x30) + lh_pz + (x37 * x26);
	const GEN_FLT x45 = x44 * x44;
	const GEN_FLT x46 = 1. / x45;
	const GEN_FLT x47 = x20 + (-1 * x17);
	const GEN_FLT x48 = x16 * lh_qk;
	const GEN_FLT x49 = x28 * lh_qj;
	const GEN_FLT x50 = x49 + x48;
	const GEN_FLT x51 = x18 + (x13 * x19);
	const GEN_FLT x52 = (x51 * x43) + (x50 * x40) + lh_py + (x47 * x37);
	const GEN_FLT x53 = x52 * x46;
	const GEN_FLT x54 = (x50 * x31) + (x51 * x10) + (x47 * x25);
	const GEN_FLT x55 = 1. / x44;
	const GEN_FLT x56 = -1 * x44;
	const GEN_FLT x57 = x52 * x52;
	const GEN_FLT x58 = 2 * (1. / (x45 + x57)) * x45 * atan2(x52, x56) * curve_0;
	const GEN_FLT x59 = x29 + x27;
	const GEN_FLT x60 = x18 + (x12 * x19);
	const GEN_FLT x61 = x49 + (-1 * x48);
	const GEN_FLT x62 = (x61 * x43) + (x60 * x40) + lh_px + (x59 * x37);
	const GEN_FLT x63 = x62 * x46;
	const GEN_FLT x64 = (x60 * x31) + (x61 * x10) + (x59 * x25);
	const GEN_FLT x65 = (x62 * x62) + x45;
	const GEN_FLT x66 = 1. / x65;
	const GEN_FLT x67 = x66 * x45;
	const GEN_FLT x68 = 1. / sqrt(1 + (-1 * x66 * x57 * (tilt_0 * tilt_0)));
	const GEN_FLT x69 = 2 * x62;
	const GEN_FLT x70 = 2 * x44;
	const GEN_FLT x71 = 1.0 / 2.0 * (1. / (x65 * sqrt(x65))) * x52 * tilt_0;
	const GEN_FLT x72 = (1. / sqrt(x65)) * tilt_0;
	const GEN_FLT x73 = (-1 * x68 * ((x72 * x54) + (-1 * ((x70 * x32) + (x64 * x69)) * x71))) +
						(-1 * ((-1 * x64 * x55) + (x63 * x32)) * x67);
	const GEN_FLT x74 =
		sin(1.5707963267949 + (-1 * phase_0) + (-1 * atan2(x62, x56)) + (-1 * asin(x72 * x52)) + gibPhase_0) * gibMag_0;
	const GEN_FLT x75 = (x30 * x39) + (x42 * x21) + (x36 * x26);
	const GEN_FLT x76 = (x50 * x39) + (x47 * x36) + (x51 * x42);
	const GEN_FLT x77 = (x60 * x39) + (x61 * x42) + (x59 * x36);
	const GEN_FLT x78 = (-1 * x68 * ((x72 * x76) + (-1 * ((x70 * x75) + (x77 * x69)) * x71))) +
						(-1 * ((-1 * x77 * x55) + (x75 * x63)) * x67);
	const GEN_FLT x79 = (x30 * x38) + (x41 * x21) + (x33 * x26);
	const GEN_FLT x80 = (x50 * x38) + (x51 * x41) + (x47 * x33);
	const GEN_FLT x81 = (x60 * x38) + (x61 * x41) + (x59 * x33);
	const GEN_FLT x82 = (-1 * x68 * ((x80 * x72) + (-1 * ((x70 * x79) + (x81 * x69)) * x71))) +
						(-1 * ((-1 * x81 * x55) + (x79 * x63)) * x67);
	out[0] = x73 + (((-1 * x54 * x55) + (x53 * x32)) * x58) + (x73 * x74);
	out[1] = x78 + (((-1 * x76 * x55) + (x75 * x53)) * x58) + (x78 * x74);
	out[2] = x82 + (((-1 * x80 * x55) + (x79 * x53)) * x58) + (x82 * x74);
}

// Jacobian of reproject_axis_x wrt [lh_px, lh_py, lh_pz, lh_qi, lh_qj, lh_qk]
static inline void gen_reproject_axis_x_jac_lh_p_axis_angle(FLT *out, const LinmathAxisAnglePose *obj_p,
															const FLT *sensor_pt, const LinmathAxisAnglePose *lh_p,
															const BaseStationCal *bsc0) {
	const GEN_FLT obj_px = (*obj_p).Pos[0];
	const GEN_FLT obj_py = (*obj_p).Pos[1];
	const GEN_FLT obj_pz = (*obj_p).Pos[2];
	const GEN_FLT obj_qi = (*obj_p).AxisAngleRot[0];
	const GEN_FLT obj_qj = (*obj_p).AxisAngleRot[1];
	const GEN_FLT obj_qk = (*obj_p).AxisAngleRot[2];
	const GEN_FLT sensor_x = sensor_pt[0];
	const GEN_FLT sensor_y = sensor_pt[1];
	const GEN_FLT sensor_z = sensor_pt[2];
	const GEN_FLT lh_px = (*lh_p).Pos[0];
	const GEN_FLT lh_py = (*lh_p).Pos[1];
	const GEN_FLT lh_pz = (*lh_p).Pos[2];
	const GEN_FLT lh_qi = (*lh_p).AxisAngleRot[0];
	const GEN_FLT lh_qj = (*lh_p).AxisAngleRot[1];
	const GEN_FLT lh_qk = (*lh_p).AxisAngleRot[2];
	const GEN_FLT phase_0 = (*bsc0).phase;
	const GEN_FLT tilt_0 = (*bsc0).tilt;
	const GEN_FLT curve_0 = (*bsc0).curve;
	const GEN_FLT gibPhase_0 = (*bsc0).gibpha;
	const GEN_FLT gibMag_0 = (*bsc0).gibmag;
	const GEN_FLT ogeeMag_0 = (*bsc0).ogeephase;
	const GEN_FLT ogeePhase_0 = (*bsc0).ogeemag;
	const GEN_FLT x0 = lh_qk * lh_qk;
	const GEN_FLT x1 = lh_qi * lh_qi;
	const GEN_FLT x2 = lh_qj * lh_qj;
	const GEN_FLT x3 = 1e-10 + x2 + x0 + x1;
	const GEN_FLT x4 = sqrt(x3);
	const GEN_FLT x5 = sin(x4);
	const GEN_FLT x6 = (1. / x4) * x5;
	const GEN_FLT x7 = x6 * lh_qj;
	const GEN_FLT x8 = cos(x4);
	const GEN_FLT x9 = 1 + (-1 * x8);
	const GEN_FLT x10 = 1. / x3;
	const GEN_FLT x11 = x9 * x10;
	const GEN_FLT x12 = x11 * lh_qk;
	const GEN_FLT x13 = x12 * lh_qi;
	const GEN_FLT x14 = obj_qk * obj_qk;
	const GEN_FLT x15 = obj_qi * obj_qi;
	const GEN_FLT x16 = obj_qj * obj_qj;
	const GEN_FLT x17 = 1e-10 + x14 + x16 + x15;
	const GEN_FLT x18 = sqrt(x17);
	const GEN_FLT x19 = cos(x18);
	const GEN_FLT x20 = (1. / x17) * (1 + (-1 * x19));
	const GEN_FLT x21 = (1. / x18) * sin(x18);
	const GEN_FLT x22 = x21 * obj_qj;
	const GEN_FLT x23 = x20 * obj_qi;
	const GEN_FLT x24 = x23 * obj_qk;
	const GEN_FLT x25 = x21 * obj_qi;
	const GEN_FLT x26 = x20 * obj_qk * obj_qj;
	const GEN_FLT x27 =
		((x26 + x25) * sensor_y) + ((x24 + (-1 * x22)) * sensor_x) + obj_pz + ((x19 + (x20 * x14)) * sensor_z);
	const GEN_FLT x28 = x21 * obj_qk;
	const GEN_FLT x29 = x23 * obj_qj;
	const GEN_FLT x30 =
		((x29 + (-1 * x28)) * sensor_y) + ((x24 + x22) * sensor_z) + ((x19 + (x20 * x15)) * sensor_x) + obj_px;
	const GEN_FLT x31 =
		((x29 + x28) * sensor_x) + ((x19 + (x20 * x16)) * sensor_y) + obj_py + ((x26 + (-1 * x25)) * sensor_z);
	const GEN_FLT x32 = x6 * lh_qk;
	const GEN_FLT x33 = -1 * x32;
	const GEN_FLT x34 = x11 * lh_qj;
	const GEN_FLT x35 = x34 * lh_qi;
	const GEN_FLT x36 = ((x35 + x33) * x31) + (x30 * (x8 + (x1 * x11))) + lh_px + (x27 * (x13 + x7));
	const GEN_FLT x37 = -1 * x7;
	const GEN_FLT x38 = x6 * lh_qi;
	const GEN_FLT x39 = x34 * lh_qk;
	const GEN_FLT x40 = ((x13 + x37) * x30) + ((x39 + x38) * x31) + lh_pz + (x27 * (x8 + (x0 * x11)));
	const GEN_FLT x41 = x40 * x40;
	const GEN_FLT x42 = x41 + (x36 * x36);
	const GEN_FLT x43 = 1. / x42;
	const GEN_FLT x44 = -1 * x38;
	const GEN_FLT x45 = lh_py + (x31 * (x8 + (x2 * x11))) + ((x35 + x32) * x30) + ((x39 + x44) * x27);
	const GEN_FLT x46 = x45 * x45;
	const GEN_FLT x47 = 1. / sqrt(1 + (-1 * x43 * x46 * (tilt_0 * tilt_0)));
	const GEN_FLT x48 = (1. / (x42 * sqrt(x42))) * x45 * tilt_0;
	const GEN_FLT x49 = x47 * x48;
	const GEN_FLT x50 = (x49 * x36) + (x40 * x43);
	const GEN_FLT x51 = (1. / sqrt(x42)) * tilt_0;
	const GEN_FLT x52 = -1 * x40;
	const GEN_FLT x53 =
		sin(1.5707963267949 + (-1 * phase_0) + (-1 * atan2(x36, x52)) + (-1 * asin(x51 * x45)) + gibPhase_0) * gibMag_0;
	const GEN_FLT x54 = x51 * x47;
	const GEN_FLT x55 = 2 * x40;
	const GEN_FLT x56 = (1. / (x41 + x46)) * atan2(x45, x52) * curve_0;
	const GEN_FLT x57 = 2 * x56;
	const GEN_FLT x58 = (x40 * x49) + (-1 * x43 * x36);
	const GEN_FLT x59 = x8 * x10;
	const GEN_FLT x60 = x1 * x59;
	const GEN_FLT x61 = (1. / (x3 * sqrt(x3))) * x5;
	const GEN_FLT x62 = x1 * x61;
	const GEN_FLT x63 = x61 * lh_qj;
	const GEN_FLT x64 = x63 * lh_qi;
	const GEN_FLT x65 = lh_qj * lh_qi;
	const GEN_FLT x66 = 2 * (1. / (x3 * x3)) * x9;
	const GEN_FLT x67 = x66 * lh_qk;
	const GEN_FLT x68 = (-1 * x67 * x65) + (x64 * lh_qk);
	const GEN_FLT x69 = x68 + x6;
	const GEN_FLT x70 = x0 * x66;
	const GEN_FLT x71 = x0 * x61;
	const GEN_FLT x72 = (x71 * lh_qi) + (-1 * x70 * lh_qi);
	const GEN_FLT x73 = (x62 * lh_qk) + (-1 * x1 * x67);
	const GEN_FLT x74 = x73 + x12;
	const GEN_FLT x75 = x65 * x59;
	const GEN_FLT x76 = x64 + (-1 * x75);
	const GEN_FLT x77 = ((x76 + x74) * x30) + (x31 * (x69 + x60 + (-1 * x62))) + ((x72 + x44) * x27);
	const GEN_FLT x78 = 1. / x41;
	const GEN_FLT x79 = x78 * x45;
	const GEN_FLT x80 = x2 * x61;
	const GEN_FLT x81 = (x80 * lh_qi) + (-1 * x2 * x66 * lh_qi);
	const GEN_FLT x82 = x68 + (-1 * x6);
	const GEN_FLT x83 = (x62 * lh_qj) + (-1 * x1 * x66 * lh_qj);
	const GEN_FLT x84 = x83 + x34;
	const GEN_FLT x85 = x59 * lh_qk;
	const GEN_FLT x86 = x85 * lh_qi;
	const GEN_FLT x87 = x61 * lh_qk * lh_qi;
	const GEN_FLT x88 = (-1 * x87) + x86;
	const GEN_FLT x89 = ((x88 + x84) * x30) + ((x81 + x44) * x31) + (x27 * (x82 + (-1 * x60) + x62));
	const GEN_FLT x90 = 1. / x40;
	const GEN_FLT x91 = x57 * x41;
	const GEN_FLT x92 = x78 * x36;
	const GEN_FLT x93 = x87 + (-1 * x86);
	const GEN_FLT x94 = (-1 * x64) + x75;
	const GEN_FLT x95 = lh_qi * lh_qi * lh_qi;
	const GEN_FLT x96 = x11 * lh_qi;
	const GEN_FLT x97 =
		(((2 * x96) + x44 + (-1 * x66 * x95) + (x61 * x95)) * x30) + ((x93 + x84) * x31) + ((x94 + x74) * x27);
	const GEN_FLT x98 = x41 * x43;
	const GEN_FLT x99 = 2 * x36;
	const GEN_FLT x100 = 1.0 / 2.0 * x48;
	const GEN_FLT x101 = (-1 * x47 * ((x89 * x51) + (-1 * ((x77 * x55) + (x99 * x97)) * x100))) +
						 (-1 * ((-1 * x90 * x97) + (x77 * x92)) * x98);
	const GEN_FLT x102 = (x80 * lh_qk) + (-1 * x2 * x67);
	const GEN_FLT x103 = x102 + x12;
	const GEN_FLT x104 = (x71 * lh_qj) + (-1 * x70 * lh_qj);
	const GEN_FLT x105 = x2 * x59;
	const GEN_FLT x106 = (x30 * (x82 + (-1 * x105) + x80)) + (x31 * (x103 + x94)) + (x27 * (x104 + x37));
	const GEN_FLT x107 = lh_qj * lh_qj * lh_qj;
	const GEN_FLT x108 = x81 + x96;
	const GEN_FLT x109 = x85 * lh_qj;
	const GEN_FLT x110 = x63 * lh_qk;
	const GEN_FLT x111 = (-1 * x110) + x109;
	const GEN_FLT x112 =
		((x111 + x108) * x30) + (((-1 * x66 * x107) + (x61 * x107) + x37 + (2 * x34)) * x31) + (x27 * (x103 + x76));
	const GEN_FLT x113 = x110 + (-1 * x109);
	const GEN_FLT x114 = ((x83 + x37) * x30) + ((x113 + x108) * x31) + (x27 * (x69 + x105 + (-1 * x80)));
	const GEN_FLT x115 = (-1 * x47 * ((x51 * x112) + (-1 * ((x55 * x106) + (x99 * x114)) * x100))) +
						 (-1 * ((-1 * x90 * x114) + (x92 * x106)) * x98);
	const GEN_FLT x116 = x104 + x34;
	const GEN_FLT x117 = lh_qk * lh_qk * lh_qk;
	const GEN_FLT x118 = x72 + x96;
	const GEN_FLT x119 =
		(x31 * (x116 + x88)) + ((x118 + x113) * x30) + (((2 * x12) + (x61 * x117) + x33 + (-1 * x66 * x117)) * x27);
	const GEN_FLT x120 = x0 * x59;
	const GEN_FLT x121 = (x30 * (x69 + (-1 * x71) + x120)) + (x27 * (x116 + x93)) + (x31 * (x102 + x33));
	const GEN_FLT x122 = ((x73 + x33) * x30) + (x31 * (x71 + x82 + (-1 * x120))) + ((x118 + x111) * x27);
	const GEN_FLT x123 = (-1 * x47 * ((x51 * x121) + (-1 * ((x55 * x119) + (x99 * x122)) * x100))) +
						 (-1 * ((-1 * x90 * x122) + (x92 * x119)) * x98);
	out[0] = x50 + (x50 * x53);
	out[1] = (-1 * x54 * x53) + (-1 * x54) + (-1 * x56 * x55);
	out[2] = x58 + (x57 * x45) + (x53 * x58);
	out[3] = (((-1 * x89 * x90) + (x79 * x77)) * x91) + x101 + (x53 * x101);
	out[4] = x115 + (((-1 * x90 * x112) + (x79 * x106)) * x91) + (x53 * x115);
	out[5] = x123 + (((-1 * x90 * x121) + (x79 * x119)) * x91) + (x53 * x123);
}

// Jacobian of reproject_axis_x wrt [phase_0, tilt_0, curve_0, gibPhase_0, gibMag_0, ogeeMag_0, ogeePhase_0]
static inline void gen_reproject_axis_x_jac_bsc0_axis_angle(FLT *out, const LinmathAxisAnglePose *obj_p,
															const FLT *sensor_pt, const LinmathAxisAnglePose *lh_p,
															const BaseStationCal *bsc0) {
	const GEN_FLT obj_px = (*obj_p).Pos[0];
	const GEN_FLT obj_py = (*obj_p).Pos[1];
	const GEN_FLT obj_pz = (*obj_p).Pos[2];
	const GEN_FLT obj_qi = (*obj_p).AxisAngleRot[0];
	const GEN_FLT obj_qj = (*obj_p).AxisAngleRot[1];
	const GEN_FLT obj_qk = (*obj_p).AxisAngleRot[2];
	const GEN_FLT sensor_x = sensor_pt[0];
	const GEN_FLT sensor_y = sensor_pt[1];
	const GEN_FLT sensor_z = sensor_pt[2];
	const GEN_FLT lh_px = (*lh_p).Pos[0];
	const GEN_FLT lh_py = (*lh_p).Pos[1];
	const GEN_FLT lh_pz = (*lh_p).Pos[2];
	const GEN_FLT lh_qi = (*lh_p).AxisAngleRot[0];
	const GEN_FLT lh_qj = (*lh_p).AxisAngleRot[1];
	const GEN_FLT lh_qk = (*lh_p).AxisAngleRot[2];
	const GEN_FLT phase_0 = (*bsc0).phase;
	const GEN_FLT tilt_0 = (*bsc0).tilt;
	const GEN_FLT curve_0 = (*bsc0).curve;
	const GEN_FLT gibPhase_0 = (*bsc0).gibpha;
	const GEN_FLT gibMag_0 = (*bsc0).gibmag;
	const GEN_FLT ogeeMag_0 = (*bsc0).ogeephase;
	const GEN_FLT ogeePhase_0 = (*bsc0).ogeemag;
	const GEN_FLT x0 = lh_qk * lh_qk;
	const GEN_FLT x1 = lh_qi * lh_qi;
	const GEN_FLT x2 = lh_qj * lh_qj;
	const GEN_FLT x3 = 1e-10 + x2 + x0 + x1;
	const GEN_FLT x4 = sqrt(x3);
	const GEN_FLT x5 = (1. / x4) * sin(x4);
	const GEN_FLT x6 = x5 * lh_qi;
	const GEN_FLT x7 = cos(x4);
	const GEN_FLT x8 = (1. / x3) * (1 + (-1 * x7));
	const GEN_FLT x9 = x8 * lh_qk;
	const GEN_FLT x10 = x9 * lh_qj;
	const GEN_FLT x11 = obj_qk * obj_qk;
	const GEN_FLT x12 = obj_qi * obj_qi;
	const GEN_FLT x13 = obj_qj * obj_qj;
	const GEN_FLT x14 = 1e-10 + x13 + x11 + x12;
	const GEN_FLT x15 = sqrt(x14);
	const GEN_FLT x16 = cos(x15);
	const GEN_FLT x17 = (1. / x14) * (1 + (-1 * x16));
	const GEN_FLT x18 = (1. / x15) * sin(x15);
	const GEN_FLT x19 = x18 * obj_qj;
	const GEN_FLT x20 = x17 * obj_qk * obj_qi;
	const GEN_FLT x21 = x18 * obj_qi;
	const GEN_FLT x22 = x17 * obj_qj;
	const GEN_FLT x23 = x22 * obj_qk;
	const GEN_FLT x24 =
		((x23 + x21) * sensor_y) + ((x20 + (-1 * x19)) * sensor_x) + obj_pz + ((x16 + (x11 * x17)) * sensor_z);
	const GEN_FLT x25 = x18 * obj_qk;
	const GEN_FLT x26 = x22 * obj_qi;
	const GEN_FLT x27 =
		((x26 + (-1 * x25)) * sensor_y) + ((x20 + x19) * sensor_z) + ((x16 + (x12 * x17)) * sensor_x) + obj_px;
	const GEN_FLT x28 = x5 * lh_qk;
	const GEN_FLT x29 = x8 * lh_qj * lh_qi;
	const GEN_FLT x30 =
		((x16 + (x13 * x17)) * sensor_y) + ((x26 + x25) * sensor_x) + obj_py + ((x23 + (-1 * x21)) * sensor_z);
	const GEN_FLT x31 = ((x29 + x28) * x27) + lh_py + (x30 * (x7 + (x2 * x8))) + (x24 * (x10 + (-1 * x6)));
	const GEN_FLT x32 = x5 * lh_qj;
	const GEN_FLT x33 = x9 * lh_qi;
	const GEN_FLT x34 = ((x33 + (-1 * x32)) * x27) + lh_pz + (x30 * (x10 + x6)) + (x24 * (x7 + (x0 * x8)));
	const GEN_FLT x35 = ((x29 + (-1 * x28)) * x30) + (x27 * (x7 + (x1 * x8))) + lh_px + ((x33 + x32) * x24);
	const GEN_FLT x36 = (x35 * x35) + (x34 * x34);
	const GEN_FLT x37 = x31 * (1. / sqrt(x36));
	const GEN_FLT x38 = -1 * x34;
	const GEN_FLT x39 =
		1.5707963267949 + (-1 * phase_0) + (-1 * atan2(x35, x38)) + (-1 * asin(x37 * tilt_0)) + gibPhase_0;
	const GEN_FLT x40 = sin(x39) * gibMag_0;
	const GEN_FLT x41 = x37 * (1. / sqrt(1 + (-1 * (x31 * x31) * (1. / x36) * (tilt_0 * tilt_0))));
	out[0] = -1 + (-1 * x40);
	out[1] = (-1 * x40 * x41) + (-1 * x41);
	out[2] = atan2(x31, x38) * atan2(x31, x38);
	out[3] = x40;
	out[4] = -1 * cos(x39);
	out[5] = 0;
	out[6] = 0;
}

static inline FLT gen_reproject_axis_y_axis_angle(const LinmathAxisAnglePose *obj_p, const FLT *sensor_pt,
												  const LinmathAxisAnglePose *lh_p, const BaseStationCal *bsc1) {
	const GEN_FLT obj_px = (*obj_p).Pos[0];
	const GEN_FLT obj_py = (*obj_p).Pos[1];
	const GEN_FLT obj_pz = (*obj_p).Pos[2];
	const GEN_FLT obj_qi = (*obj_p).AxisAngleRot[0];
	const GEN_FLT obj_qj = (*obj_p).AxisAngleRot[1];
	const GEN_FLT obj_qk = (*obj_p).AxisAngleRot[2];
	const GEN_FLT sensor_x = sensor_pt[0];
	const GEN_FLT sensor_y = sensor_pt[1];
	const GEN_FLT sensor_z = sensor_pt[2];
	const GEN_FLT lh_px = (*lh_p).Pos[0];
	const GEN_FLT lh_py = (*lh_p).Pos[1];
	const GEN_FLT lh_pz = (*lh_p).Pos[2];
	const GEN_FLT lh_qi = (*lh_p).AxisAngleRot[0];
	const GEN_FLT lh_qj = (*lh_p).AxisAngleRot[1];
	const GEN_FLT lh_qk = (*lh_p).AxisAngleRot[2];
	const GEN_FLT phase_1 = (*bsc1).phase;
	const GEN_FLT tilt_1 = (*bsc1).tilt;
	const GEN_FLT curve_1 = (*bsc1).curve;
	const GEN_FLT gibPhase_1 = (*bsc1).gibpha;
	const GEN_FLT gibMag_1 = (*bsc1).gibmag;
	const GEN_FLT ogeeMag_1 = (*bsc1).ogeephase;
	const GEN_FLT ogeePhase_1 = (*bsc1).ogeemag;
	const GEN_FLT x0 = lh_qk * lh_qk;
	const GEN_FLT x1 = lh_qi * lh_qi;
	const GEN_FLT x2 = lh_qj * lh_qj;
	const GEN_FLT x3 = 1e-10 + x2 + x0 + x1;
	const GEN_FLT x4 = sqrt(x3);
	const GEN_FLT x5 = (1. / x4) * sin(x4);
	const GEN_FLT x6 = x5 * lh_qj;
	const GEN_FLT x7 = cos(x4);
	const GEN_FLT x8 = (1. / x3) * (1 + (-1 * x7));
	const GEN_FLT x9 = x8 * lh_qk * lh_qi;
	const GEN_FLT x10 = obj_qk * obj_qk;
	const GEN_FLT x11 = obj_qi * obj_qi;
	const GEN_FLT x12 = obj_qj * obj_qj;
	const GEN_FLT x13 = 1e-10 + x12 + x10 + x11;
	const GEN_FLT x14 = sqrt(x13);
	const GEN_FLT x15 = cos(x14);
	const GEN_FLT x16 = (1. / x13) * (1 + (-1 * x15));
	const GEN_FLT x17 = (1. / x14) * sin(x14);
	const GEN_FLT x18 = x17 * obj_qj;
	const GEN_FLT x19 = x16 * obj_qk;
	const GEN_FLT x20 = x19 * obj_qi;
	const GEN_FLT x21 = x17 * obj_qi;
	const GEN_FLT x22 = x19 * obj_qj;
	const GEN_FLT x23 =
		((x22 + x21) * sensor_y) + ((x20 + (-1 * x18)) * sensor_x) + obj_pz + ((x15 + (x10 * x16)) * sensor_z);
	const GEN_FLT x24 = x17 * obj_qk;
	const GEN_FLT x25 = x16 * obj_qj * obj_qi;
	const GEN_FLT x26 =
		((x25 + (-1 * x24)) * sensor_y) + ((x20 + x18) * sensor_z) + ((x15 + (x11 * x16)) * sensor_x) + obj_px;
	const GEN_FLT x27 =
		((x15 + (x12 * x16)) * sensor_y) + obj_py + ((x25 + x24) * sensor_x) + ((x22 + (-1 * x21)) * sensor_z);
	const GEN_FLT x28 = x5 * lh_qk;
	const GEN_FLT x29 = x8 * lh_qj;
	const GEN_FLT x30 = x29 * lh_qi;
	const GEN_FLT x31 = ((x30 + (-1 * x28)) * x27) + lh_px + (x26 * (x7 + (x1 * x8))) + ((x9 + x6) * x23);
	const GEN_FLT x32 = x5 * lh_qi;
	const GEN_FLT x33 = x29 * lh_qk;
	const GEN_FLT x34 = ((x33 + x32) * x27) + ((x9 + (-1 * x6)) * x26) + lh_pz + (x23 * (x7 + (x0 * x8)));
	const GEN_FLT x35 = -1 * x34;
	const GEN_FLT x36 = (x27 * (x7 + (x2 * x8))) + ((x30 + x28) * x26) + lh_py + ((x33 + (-1 * x32)) * x23);
	const GEN_FLT x37 = (-1 * phase_1) + (-1 * asin((1. / sqrt((x36 * x36) + (x34 * x34))) * x31 * tilt_1)) +
						(-1 * atan2(-1 * x36, x35));
	return x37 + ((atan2(x31, x35) * atan2(x31, x35)) * curve_1) +
		   (-1 * cos(1.5707963267949 + x37 + gibPhase_1) * gibMag_1);
}

// Jacobian of reproject_axis_y wrt [obj_px, obj_py, obj_pz, obj_qi, obj_qj, obj_qk]
static inline void gen_reproject_axis_y_jac_obj_p_axis_angle(FLT *out, const LinmathAxisAnglePose *obj_p,
															 const FLT *sensor_pt, const LinmathAxisAnglePose *lh_p,
															 const BaseStationCal *bsc1) {
	const GEN_FLT obj_px = (*obj_p).Pos[0];
	const GEN_FLT obj_py = (*obj_p).Pos[1];
	const GEN_FLT obj_pz = (*obj_p).Pos[2];
	const GEN_FLT obj_qi = (*obj_p).AxisAngleRot[0];
	const GEN_FLT obj_qj = (*obj_p).AxisAngleRot[1];
	const GEN_FLT obj_qk = (*obj_p).AxisAngleRot[2];
	const GEN_FLT sensor_x = sensor_pt[0];
	const GEN_FLT sensor_y = sensor_pt[1];
	const GEN_FLT sensor_z = sensor_pt[2];
	const GEN_FLT lh_px = (*lh_p).Pos[0];
	const GEN_FLT lh_py = (*lh_p).Pos[1];
	const GEN_FLT lh_pz = (*lh_p).Pos[2];
	const GEN_FLT lh_qi = (*lh_p).AxisAngleRot[0];
	const GEN_FLT lh_qj = (*lh_p).AxisAngleRot[1];
	const GEN_FLT lh_qk = (*lh_p).AxisAngleRot[2];
	const GEN_FLT phase_1 = (*bsc1).phase;
	const GEN_FLT tilt_1 = (*bsc1).tilt;
	const GEN_FLT curve_1 = (*bsc1).curve;
	const GEN_FLT gibPhase_1 = (*bsc1).gibpha;
	const GEN_FLT gibMag_1 = (*bsc1).gibmag;
	const GEN_FLT ogeeMag_1 = (*bsc1).ogeephase;
	const GEN_FLT ogeePhase_1 = (*bsc1).ogeemag;
	const GEN_FLT x0 = lh_qk * lh_qk;
	const GEN_FLT x1 = lh_qi * lh_qi;
	const GEN_FLT x2 = lh_qj * lh_qj;
	const GEN_FLT x3 = 1e-10 + x2 + x0 + x1;
	const GEN_FLT x4 = sqrt(x3);
	const GEN_FLT x5 = (1. / x4) * sin(x4);
	const GEN_FLT x6 = x5 * lh_qj;
	const GEN_FLT x7 = cos(x4);
	const GEN_FLT x8 = (1. / x3) * (1 + (-1 * x7));
	const GEN_FLT x9 = x8 * lh_qk * lh_qi;
	const GEN_FLT x10 = x9 + (-1 * x6);
	const GEN_FLT x11 = obj_qk * obj_qk;
	const GEN_FLT x12 = obj_qi * obj_qi;
	const GEN_FLT x13 = obj_qj * obj_qj;
	const GEN_FLT x14 = 1e-10 + x13 + x11 + x12;
	const GEN_FLT x15 = 1. / x14;
	const GEN_FLT x16 = sqrt(x14);
	const GEN_FLT x17 = cos(x16);
	const GEN_FLT x18 = 1 + (-1 * x17);
	const GEN_FLT x19 = x15 * x18;
	const GEN_FLT x20 = sin(x16);
	const GEN_FLT x21 = x20 * (1. / x16);
	const GEN_FLT x22 = x21 * obj_qj;
	const GEN_FLT x23 = -1 * x22;
	const GEN_FLT x24 = x19 * obj_qk;
	const GEN_FLT x25 = x24 * obj_qi;
	const GEN_FLT x26 = x21 * obj_qi;
	const GEN_FLT x27 = x24 * obj_qj;
	const GEN_FLT x28 = ((x27 + x26) * sensor_y) + ((x25 + x23) * sensor_x) + obj_pz + ((x17 + (x11 * x19)) * sensor_z);
	const GEN_FLT x29 = x7 + (x0 * x8);
	const GEN_FLT x30 = x21 * obj_qk;
	const GEN_FLT x31 = -1 * x30;
	const GEN_FLT x32 = x19 * obj_qi;
	const GEN_FLT x33 = x32 * obj_qj;
	const GEN_FLT x34 = ((x33 + x31) * sensor_y) + ((x25 + x22) * sensor_z) + ((x17 + (x12 * x19)) * sensor_x) + obj_px;
	const GEN_FLT x35 = -1 * x26;
	const GEN_FLT x36 = ((x17 + (x13 * x19)) * sensor_y) + ((x33 + x30) * sensor_x) + obj_py + ((x27 + x35) * sensor_z);
	const GEN_FLT x37 = x5 * lh_qi;
	const GEN_FLT x38 = x8 * lh_qj;
	const GEN_FLT x39 = x38 * lh_qk;
	const GEN_FLT x40 = x39 + x37;
	const GEN_FLT x41 = (x40 * x36) + (x34 * x10) + lh_pz + (x28 * x29);
	const GEN_FLT x42 = x41 * x41;
	const GEN_FLT x43 = 1. / x42;
	const GEN_FLT x44 = x9 + x6;
	const GEN_FLT x45 = x7 + (x1 * x8);
	const GEN_FLT x46 = x5 * lh_qk;
	const GEN_FLT x47 = x38 * lh_qi;
	const GEN_FLT x48 = x47 + (-1 * x46);
	const GEN_FLT x49 = (x45 * x34) + (x48 * x36) + lh_px + (x44 * x28);
	const GEN_FLT x50 = x43 * x49;
	const GEN_FLT x51 = 1. / x41;
	const GEN_FLT x52 = -1 * x41;
	const GEN_FLT x53 = x49 * x49;
	const GEN_FLT x54 = 2 * (1. / (x42 + x53)) * x42 * atan2(x49, x52) * curve_1;
	const GEN_FLT x55 = x39 + (-1 * x37);
	const GEN_FLT x56 = x47 + x46;
	const GEN_FLT x57 = x7 + (x2 * x8);
	const GEN_FLT x58 = (x57 * x36) + (x56 * x34) + lh_py + (x55 * x28);
	const GEN_FLT x59 = x58 * x43;
	const GEN_FLT x60 = (x58 * x58) + x42;
	const GEN_FLT x61 = 1. / x60;
	const GEN_FLT x62 = x61 * x42;
	const GEN_FLT x63 = 1. / sqrt(1 + (-1 * x61 * x53 * (tilt_1 * tilt_1)));
	const GEN_FLT x64 = 2 * x58;
	const GEN_FLT x65 = 2 * x41;
	const GEN_FLT x66 = 1.0 / 2.0 * (1. / (x60 * sqrt(x60))) * x49 * tilt_1;
	const GEN_FLT x67 = (1. / sqrt(x60)) * tilt_1;
	const GEN_FLT x68 = (-1 * x63 * ((x67 * x45) + (-1 * ((x65 * x10) + (x64 * x56)) * x66))) +
						(-1 * ((x51 * x56) + (-1 * x59 * x10)) * x62);
	const GEN_FLT x69 =
		sin(1.5707963267949 + (-1 * phase_1) + (-1 * atan2(-1 * x58, x52)) + gibPhase_1 + (-1 * asin(x67 * x49))) *
		gibMag_1;
	const GEN_FLT x70 = (-1 * x63 * ((x67 * x48) + (-1 * ((x65 * x40) + (x64 * x57)) * x66))) +
						(-1 * ((x51 * x57) + (-1 * x59 * x40)) * x62);
	const GEN_FLT x71 = (-1 * x63 * ((x67 * x44) + (-1 * ((x65 * x29) + (x64 * x55)) * x66))) +
						(-1 * ((x51 * x55) + (-1 * x59 * x29)) * x62);
	const GEN_FLT x72 = 2 * (1. / (x14 * x14)) * x18;
	const GEN_FLT x73 = x20 * (1. / (x14 * sqrt(x14)));
	const GEN_FLT x74 = x73 * x13;
	const GEN_FLT x75 = (x74 * obj_qi) + (-1 * x72 * x13 * obj_qi);
	const GEN_FLT x76 = x15 * x17;
	const GEN_FLT x77 = x76 * x12;
	const GEN_FLT x78 = x73 * x12;
	const GEN_FLT x79 = obj_qj * obj_qi;
	const GEN_FLT x80 = x72 * obj_qk;
	const GEN_FLT x81 = x73 * obj_qk;
	const GEN_FLT x82 = x81 * obj_qj;
	const GEN_FLT x83 = (x82 * obj_qi) + (-1 * x80 * x79);
	const GEN_FLT x84 = x83 + (-1 * x21);
	const GEN_FLT x85 = x81 * obj_qi;
	const GEN_FLT x86 = x76 * obj_qk;
	const GEN_FLT x87 = x86 * obj_qi;
	const GEN_FLT x88 = x87 + (-1 * x85);
	const GEN_FLT x89 = x19 * obj_qj;
	const GEN_FLT x90 = (x78 * obj_qj) + (-1 * x72 * x12 * obj_qj);
	const GEN_FLT x91 = x90 + x89;
	const GEN_FLT x92 = ((x91 + x88) * sensor_x) + ((x75 + x35) * sensor_y) + ((x84 + (-1 * x77) + x78) * sensor_z);
	const GEN_FLT x93 = x72 * x11;
	const GEN_FLT x94 = x73 * x11;
	const GEN_FLT x95 = (x94 * obj_qi) + (-1 * x93 * obj_qi);
	const GEN_FLT x96 = x83 + x21;
	const GEN_FLT x97 = x73 * x79;
	const GEN_FLT x98 = x79 * x76;
	const GEN_FLT x99 = (-1 * x98) + x97;
	const GEN_FLT x100 = (x78 * obj_qk) + (-1 * x80 * x12);
	const GEN_FLT x101 = x100 + x24;
	const GEN_FLT x102 = ((x101 + x99) * sensor_x) + ((x95 + x35) * sensor_z) + ((x96 + x77 + (-1 * x78)) * sensor_y);
	const GEN_FLT x103 = obj_qi * obj_qi * obj_qi;
	const GEN_FLT x104 = (-1 * x87) + x85;
	const GEN_FLT x105 = x98 + (-1 * x97);
	const GEN_FLT x106 = (((2 * x32) + (x73 * x103) + x35 + (-1 * x72 * x103)) * sensor_x) +
						 ((x101 + x105) * sensor_z) + ((x91 + x104) * sensor_y);
	const GEN_FLT x107 = (x92 * x40) + (x10 * x106) + (x29 * x102);
	const GEN_FLT x108 = (x45 * x106) + (x92 * x48) + (x44 * x102);
	const GEN_FLT x109 = (x56 * x106) + (x55 * x102) + (x57 * x92);
	const GEN_FLT x110 = (-1 * x63 * ((x67 * x108) + (-1 * ((x65 * x107) + (x64 * x109)) * x66))) +
						 (-1 * ((x51 * x109) + (-1 * x59 * x107)) * x62);
	const GEN_FLT x111 = obj_qj * obj_qj * obj_qj;
	const GEN_FLT x112 = (x74 * obj_qk) + (-1 * x80 * x13);
	const GEN_FLT x113 = x112 + x24;
	const GEN_FLT x114 = x86 * obj_qj;
	const GEN_FLT x115 = x114 + (-1 * x82);
	const GEN_FLT x116 = x75 + x32;
	const GEN_FLT x117 = ((x116 + x115) * sensor_x) +
						 (((2 * x89) + (x73 * x111) + x23 + (-1 * x72 * x111)) * sensor_y) + ((x99 + x113) * sensor_z);
	const GEN_FLT x118 = (x94 * obj_qj) + (-1 * x93 * obj_qj);
	const GEN_FLT x119 = x76 * x13;
	const GEN_FLT x120 =
		((x84 + (-1 * x119) + x74) * sensor_x) + ((x105 + x113) * sensor_y) + ((x118 + x23) * sensor_z);
	const GEN_FLT x121 = (-1 * x114) + x82;
	const GEN_FLT x122 = ((x96 + x119 + (-1 * x74)) * sensor_z) + ((x116 + x121) * sensor_y) + ((x90 + x23) * sensor_x);
	const GEN_FLT x123 = (x10 * x122) + (x40 * x117) + (x29 * x120);
	const GEN_FLT x124 = (x48 * x117) + (x45 * x122) + (x44 * x120);
	const GEN_FLT x125 = (x56 * x122) + (x57 * x117) + (x55 * x120);
	const GEN_FLT x126 = (-1 * x63 * ((x67 * x124) + (-1 * ((x65 * x123) + (x64 * x125)) * x66))) +
						 (-1 * ((x51 * x125) + (-1 * x59 * x123)) * x62);
	const GEN_FLT x127 = x118 + x89;
	const GEN_FLT x128 = x76 * x11;
	const GEN_FLT x129 =
		((x96 + (-1 * x94) + x128) * sensor_x) + ((x112 + x31) * sensor_y) + ((x104 + x127) * sensor_z);
	const GEN_FLT x130 = obj_qk * obj_qk * obj_qk;
	const GEN_FLT x131 = x95 + x32;
	const GEN_FLT x132 = ((x88 + x127) * sensor_y) + ((x121 + x131) * sensor_x) +
						 (((2 * x24) + (-1 * x72 * x130) + x31 + (x73 * x130)) * sensor_z);
	const GEN_FLT x133 =
		((x84 + x94 + (-1 * x128)) * sensor_y) + ((x115 + x131) * sensor_z) + ((x100 + x31) * sensor_x);
	const GEN_FLT x134 = (x10 * x133) + (x40 * x129) + (x29 * x132);
	const GEN_FLT x135 = (x48 * x129) + (x45 * x133) + (x44 * x132);
	const GEN_FLT x136 = (x56 * x133) + (x57 * x129) + (x55 * x132);
	const GEN_FLT x137 = (-1 * x63 * ((x67 * x135) + (-1 * ((x65 * x134) + (x64 * x136)) * x66))) +
						 (-1 * ((x51 * x136) + (-1 * x59 * x134)) * x62);
	out[0] = x68 + (((-1 * x51 * x45) + (x50 * x10)) * x54) + (x68 * x69);
	out[1] = x70 + (((-1 * x51 * x48) + (x50 * x40)) * x54) + (x70 * x69);
	out[2] = x71 + (((-1 * x51 * x44) + (x50 * x29)) * x54) + (x71 * x69);
	out[3] = x110 + (((-1 * x51 * x108) + (x50 * x107)) * x54) + (x69 * x110);
	out[4] = x126 + (((-1 * x51 * x124) + (x50 * x123)) * x54) + (x69 * x126);
	out[5] = x137 + (((-1 * x51 * x135) + (x50 * x134)) * x54) + (x69 * x137);
}

// Jacobian of reproject_axis_y wrt [sensor_x, sensor_y, sensor_z]
static inline void gen_reproject_axis_y_jac_sensor_pt_axis_angle(FLT *out, const LinmathAxisAnglePose *obj_p,
																 const FLT *sensor_pt, const LinmathAxisAnglePose *lh_p,
																 const BaseStationCal *bsc1) {
	const GEN_FLT obj_px = (*obj_p).Pos[0];
	const GEN_FLT obj_py = (*obj_p).Pos[1];
	const GEN_FLT obj_pz = (*obj_p).Pos[2];
	const GEN_FLT obj_qi = (*obj_p).AxisAngleRot[0];
	const GEN_FLT obj_qj = (*obj_p).AxisAngleRot[1];
	const GEN_FLT obj_qk = (*obj_p).AxisAngleRot[2];
	const GEN_FLT sensor_x = sensor_pt[0];
	const GEN_FLT sensor_y = sensor_pt[1];
	const GEN_FLT sensor_z = sensor_pt[2];
	const GEN_FLT lh_px = (*lh_p).Pos[0];
	const GEN_FLT lh_py = (*lh_p).Pos[1];
	const GEN_FLT lh_pz = (*lh_p).Pos[2];
	const GEN_FLT lh_qi = (*lh_p).AxisAngleRot[0];
	const GEN_FLT lh_qj = (*lh_p).AxisAngleRot[1];
	const GEN_FLT lh_qk = (*lh_p).AxisAngleRot[2];
	const GEN_FLT phase_1 = (*bsc1).phase;
	const GEN_FLT tilt_1 = (*bsc1).tilt;
	const GEN_FLT curve_1 = (*bsc1).curve;
	const GEN_FLT gibPhase_1 = (*bsc1).gibpha;
	const GEN_FLT gibMag_1 = (*bsc1).gibmag;
	const GEN_FLT ogeeMag_1 = (*bsc1).ogeephase;
	const GEN_FLT ogeePhase_1 = (*bsc1).ogeemag;
	const GEN_FLT x0 = obj_qk * obj_qk;
	const GEN_FLT x1 = obj_qi * obj_qi;
	const GEN_FLT x2 = obj_qj * obj_qj;
	const GEN_FLT x3 = 1e-10 + x2 + x0 + x1;
	const GEN_FLT x4 = sqrt(x3);
	const GEN_FLT x5 = (1. / x4) * sin(x4);
	const GEN_FLT x6 = x5 * obj_qk;
	const GEN_FLT x7 = cos(x4);
	const GEN_FLT x8 = (1. / x3) * (1 + (-1 * x7));
	const GEN_FLT x9 = x8 * obj_qj * obj_qi;
	const GEN_FLT x10 = x9 + x6;
	const GEN_FLT x11 = lh_qk * lh_qk;
	const GEN_FLT x12 = lh_qi * lh_qi;
	const GEN_FLT x13 = lh_qj * lh_qj;
	const GEN_FLT x14 = 1e-10 + x13 + x11 + x12;
	const GEN_FLT x15 = sqrt(x14);
	const GEN_FLT x16 = (1. / x15) * sin(x15);
	const GEN_FLT x17 = x16 * lh_qi;
	const GEN_FLT x18 = cos(x15);
	const GEN_FLT x19 = (1. / x14) * (1 + (-1 * x18));
	const GEN_FLT x20 = x19 * lh_qk;
	const GEN_FLT x21 = x20 * lh_qj;
	const GEN_FLT x22 = x21 + x17;
	const GEN_FLT x23 = x5 * obj_qj;
	const GEN_FLT x24 = x8 * obj_qk;
	const GEN_FLT x25 = x24 * obj_qi;
	const GEN_FLT x26 = x25 + (-1 * x23);
	const GEN_FLT x27 = x18 + (x11 * x19);
	const GEN_FLT x28 = x16 * lh_qj;
	const GEN_FLT x29 = x20 * lh_qi;
	const GEN_FLT x30 = x29 + (-1 * x28);
	const GEN_FLT x31 = x7 + (x1 * x8);
	const GEN_FLT x32 = (x30 * x31) + (x22 * x10) + (x26 * x27);
	const GEN_FLT x33 = x29 + x28;
	const GEN_FLT x34 = x7 + (x0 * x8);
	const GEN_FLT x35 = x5 * obj_qi;
	const GEN_FLT x36 = x24 * obj_qj;
	const GEN_FLT x37 = x36 + x35;
	const GEN_FLT x38 = (x37 * sensor_y) + (x26 * sensor_x) + obj_pz + (x34 * sensor_z);
	const GEN_FLT x39 = x25 + x23;
	const GEN_FLT x40 = x9 + (-1 * x6);
	const GEN_FLT x41 = (x40 * sensor_y) + (x39 * sensor_z) + (x31 * sensor_x) + obj_px;
	const GEN_FLT x42 = x18 + (x12 * x19);
	const GEN_FLT x43 = x36 + (-1 * x35);
	const GEN_FLT x44 = x7 + (x2 * x8);
	const GEN_FLT x45 = (x44 * sensor_y) + (x10 * sensor_x) + obj_py + (x43 * sensor_z);
	const GEN_FLT x46 = x16 * lh_qk;
	const GEN_FLT x47 = x19 * lh_qj * lh_qi;
	const GEN_FLT x48 = x47 + (-1 * x46);
	const GEN_FLT x49 = (x45 * x48) + (x41 * x42) + lh_px + (x33 * x38);
	const GEN_FLT x50 = (x45 * x22) + (x41 * x30) + lh_pz + (x38 * x27);
	const GEN_FLT x51 = x50 * x50;
	const GEN_FLT x52 = 1. / x51;
	const GEN_FLT x53 = x52 * x49;
	const GEN_FLT x54 = (x48 * x10) + (x42 * x31) + (x33 * x26);
	const GEN_FLT x55 = 1. / x50;
	const GEN_FLT x56 = -1 * x50;
	const GEN_FLT x57 = x49 * x49;
	const GEN_FLT x58 = 2 * (1. / (x51 + x57)) * x51 * atan2(x49, x56) * curve_1;
	const GEN_FLT x59 = x21 + (-1 * x17);
	const GEN_FLT x60 = x47 + x46;
	const GEN_FLT x61 = x18 + (x13 * x19);
	const GEN_FLT x62 = (x61 * x45) + (x60 * x41) + lh_py + (x59 * x38);
	const GEN_FLT x63 = x62 * x52;
	const GEN_FLT x64 = (x60 * x31) + (x61 * x10) + (x59 * x26);
	const GEN_FLT x65 = (x62 * x62) + x51;
	const GEN_FLT x66 = 1. / x65;
	const GEN_FLT x67 = x66 * x51;
	const GEN_FLT x68 = 1. / sqrt(1 + (-1 * x66 * x57 * (tilt_1 * tilt_1)));
	const GEN_FLT x69 = 2 * x62;
	const GEN_FLT x70 = 2 * x50;
	const GEN_FLT x71 = 1.0 / 2.0 * (1. / (x65 * sqrt(x65))) * x49 * tilt_1;
	const GEN_FLT x72 = (1. / sqrt(x65)) * tilt_1;
	const GEN_FLT x73 = (-1 * x68 * ((x72 * x54) + (-1 * ((x70 * x32) + (x64 * x69)) * x71))) +
						(-1 * ((x64 * x55) + (-1 * x63 * x32)) * x67);
	const GEN_FLT x74 =
		sin(1.5707963267949 + (-1 * phase_1) + (-1 * atan2(-1 * x62, x56)) + gibPhase_1 + (-1 * asin(x72 * x49))) *
		gibMag_1;
	const GEN_FLT x75 = (x40 * x30) + (x44 * x22) + (x37 * x27);
	const GEN_FLT x76 = x75 * x52;
	const GEN_FLT x77 = (x40 * x42) + (x44 * x48) + (x33 * x37);
	const GEN_FLT x78 = (x60 * x40) + (x59 * x37) + (x61 * x44);
	const GEN_FLT x79 = (-1 * x68 * ((x72 * x77) + (-1 * ((x70 * x75) + (x78 * x69)) * x71))) +
						(-1 * ((x78 * x55) + (-1 * x76 * x62)) * x67);
	const GEN_FLT x80 = (x30 * x39) + (x43 * x22) + (x34 * x27);
	const GEN_FLT x81 = (x42 * x39) + (x43 * x48) + (x34 * x33);
	const GEN_FLT x82 = (x60 * x39) + (x61 * x43) + (x59 * x34);
	const GEN_FLT x83 = (-1 * x68 * ((x81 * x72) + (-1 * ((x80 * x70) + (x82 * x69)) * x71))) +
						(-1 * ((x82 * x55) + (-1 * x80 * x63)) * x67);
	out[0] = x73 + (((-1 * x54 * x55) + (x53 * x32)) * x58) + (x73 * x74);
	out[1] = (((-1 * x77 * x55) + (x76 * x49)) * x58) + x79 + (x79 * x74);
	out[2] = x83 + (((-1 * x81 * x55) + (x80 * x53)) * x58) + (x83 * x74);
}

// Jacobian of reproject_axis_y wrt [lh_px, lh_py, lh_pz, lh_qi, lh_qj, lh_qk]
static inline void gen_reproject_axis_y_jac_lh_p_axis_angle(FLT *out, const LinmathAxisAnglePose *obj_p,
															const FLT *sensor_pt, const LinmathAxisAnglePose *lh_p,
															const BaseStationCal *bsc1) {
	const GEN_FLT obj_px = (*obj_p).Pos[0];
	const GEN_FLT obj_py = (*obj_p).Pos[1];
	const GEN_FLT obj_pz = (*obj_p).Pos[2];
	const GEN_FLT obj_qi = (*obj_p).AxisAngleRot[0];
	const GEN_FLT obj_qj = (*obj_p).AxisAngleRot[1];
	const GEN_FLT obj_qk = (*obj_p).AxisAngleRot[2];
	const GEN_FLT sensor_x = sensor_pt[0];
	const GEN_FLT sensor_y = sensor_pt[1];
	const GEN_FLT sensor_z = sensor_pt[2];
	const GEN_FLT lh_px = (*lh_p).Pos[0];
	const GEN_FLT lh_py = (*lh_p).Pos[1];
	const GEN_FLT lh_pz = (*lh_p).Pos[2];
	const GEN_FLT lh_qi = (*lh_p).AxisAngleRot[0];
	const GEN_FLT lh_qj = (*lh_p).AxisAngleRot[1];
	const GEN_FLT lh_qk = (*lh_p).AxisAngleRot[2];
	const GEN_FLT phase_1 = (*bsc1).phase;
	const GEN_FLT tilt_1 = (*bsc1).tilt;
	const GEN_FLT curve_1 = (*bsc1).curve;
	const GEN_FLT gibPhase_1 = (*bsc1).gibpha;
	const GEN_FLT gibMag_1 = (*bsc1).gibmag;
	const GEN_FLT ogeeMag_1 = (*bsc1).ogeephase;
	const GEN_FLT ogeePhase_1 = (*bsc1).ogeemag;
	const GEN_FLT x0 = lh_qk * lh_qk;
	const GEN_FLT x1 = lh_qi * lh_qi;
	const GEN_FLT x2 = lh_qj * lh_qj;
	const GEN_FLT x3 = 1e-10 + x2 + x0 + x1;
	const GEN_FLT x4 = sqrt(x3);
	const GEN_FLT x5 = sin(x4);
	const GEN_FLT x6 = (1. / x4) * x5;
	const GEN_FLT x7 = x6 * lh_qj;
	const GEN_FLT x8 = 1. / x3;
	const GEN_FLT x9 = cos(x4);
	const GEN_FLT x10 = 1 + (-1 * x9);
	const GEN_FLT x11 = x8 * x10;
	const GEN_FLT x12 = x11 * lh_qi;
	const GEN_FLT x13 = x12 * lh_qk;
	const GEN_FLT x14 = obj_qk * obj_qk;
	const GEN_FLT x15 = obj_qi * obj_qi;
	const GEN_FLT x16 = obj_qj * obj_qj;
	const GEN_FLT x17 = 1e-10 + x14 + x16 + x15;
	const GEN_FLT x18 = sqrt(x17);
	const GEN_FLT x19 = cos(x18);
	const GEN_FLT x20 = (1. / x17) * (1 + (-1 * x19));
	const GEN_FLT x21 = (1. / x18) * sin(x18);
	const GEN_FLT x22 = x21 * obj_qj;
	const GEN_FLT x23 = x20 * obj_qi;
	const GEN_FLT x24 = x23 * obj_qk;
	const GEN_FLT x25 = x21 * obj_qi;
	const GEN_FLT x26 = x20 * obj_qk * obj_qj;
	const GEN_FLT x27 =
		((x26 + x25) * sensor_y) + ((x24 + (-1 * x22)) * sensor_x) + obj_pz + ((x19 + (x20 * x14)) * sensor_z);
	const GEN_FLT x28 = x21 * obj_qk;
	const GEN_FLT x29 = x23 * obj_qj;
	const GEN_FLT x30 =
		((x29 + (-1 * x28)) * sensor_y) + ((x24 + x22) * sensor_z) + ((x19 + (x20 * x15)) * sensor_x) + obj_px;
	const GEN_FLT x31 =
		((x29 + x28) * sensor_x) + ((x19 + (x20 * x16)) * sensor_y) + obj_py + ((x26 + (-1 * x25)) * sensor_z);
	const GEN_FLT x32 = x6 * lh_qk;
	const GEN_FLT x33 = -1 * x32;
	const GEN_FLT x34 = x12 * lh_qj;
	const GEN_FLT x35 = lh_px + ((x34 + x33) * x31) + (x30 * (x9 + (x1 * x11))) + (x27 * (x13 + x7));
	const GEN_FLT x36 = x35 * x35;
	const GEN_FLT x37 = -1 * x7;
	const GEN_FLT x38 = x6 * lh_qi;
	const GEN_FLT x39 = x11 * lh_qj;
	const GEN_FLT x40 = x39 * lh_qk;
	const GEN_FLT x41 = ((x40 + x38) * x31) + ((x13 + x37) * x30) + lh_pz + (x27 * (x9 + (x0 * x11)));
	const GEN_FLT x42 = x41 * x41;
	const GEN_FLT x43 = -1 * x38;
	const GEN_FLT x44 = ((x34 + x32) * x30) + (x31 * (x9 + (x2 * x11))) + lh_py + ((x40 + x43) * x27);
	const GEN_FLT x45 = (x44 * x44) + x42;
	const GEN_FLT x46 = 1. / x45;
	const GEN_FLT x47 = 1. / sqrt(1 + (-1 * x46 * x36 * (tilt_1 * tilt_1)));
	const GEN_FLT x48 = (1. / sqrt(x45)) * tilt_1;
	const GEN_FLT x49 = x47 * x48;
	const GEN_FLT x50 = 2 * x41;
	const GEN_FLT x51 = -1 * x41;
	const GEN_FLT x52 = (1. / (x42 + x36)) * atan2(x35, x51) * curve_1;
	const GEN_FLT x53 =
		sin(1.5707963267949 + (-1 * phase_1) + gibPhase_1 + (-1 * atan2(-1 * x44, x51)) + (-1 * asin(x48 * x35))) *
		gibMag_1;
	const GEN_FLT x54 = (1. / (x45 * sqrt(x45))) * x35 * tilt_1;
	const GEN_FLT x55 = x54 * x47;
	const GEN_FLT x56 = (x55 * x44) + (-1 * x41 * x46);
	const GEN_FLT x57 = 2 * x52;
	const GEN_FLT x58 = (x55 * x41) + (x44 * x46);
	const GEN_FLT x59 = x8 * x9;
	const GEN_FLT x60 = x1 * x59;
	const GEN_FLT x61 = (1. / (x3 * sqrt(x3))) * x5;
	const GEN_FLT x62 = x1 * x61;
	const GEN_FLT x63 = x61 * lh_qj;
	const GEN_FLT x64 = x63 * lh_qi;
	const GEN_FLT x65 = lh_qk * lh_qi;
	const GEN_FLT x66 = 2 * (1. / (x3 * x3)) * x10;
	const GEN_FLT x67 = x66 * lh_qj;
	const GEN_FLT x68 = (-1 * x67 * x65) + (x64 * lh_qk);
	const GEN_FLT x69 = x68 + x6;
	const GEN_FLT x70 = x66 * lh_qi;
	const GEN_FLT x71 = x0 * x61;
	const GEN_FLT x72 = (x71 * lh_qi) + (-1 * x0 * x70);
	const GEN_FLT x73 = x11 * lh_qk;
	const GEN_FLT x74 = x66 * lh_qk;
	const GEN_FLT x75 = (x62 * lh_qk) + (-1 * x1 * x74);
	const GEN_FLT x76 = x75 + x73;
	const GEN_FLT x77 = x59 * lh_qj * lh_qi;
	const GEN_FLT x78 = x64 + (-1 * x77);
	const GEN_FLT x79 = ((x78 + x76) * x30) + (x31 * (x69 + x60 + (-1 * x62))) + ((x72 + x43) * x27);
	const GEN_FLT x80 = 1. / x42;
	const GEN_FLT x81 = x80 * x35;
	const GEN_FLT x82 = (x62 * lh_qj) + (-1 * x1 * x67);
	const GEN_FLT x83 = x82 + x39;
	const GEN_FLT x84 = x59 * lh_qk;
	const GEN_FLT x85 = x84 * lh_qi;
	const GEN_FLT x86 = x61 * x65;
	const GEN_FLT x87 = x86 + (-1 * x85);
	const GEN_FLT x88 = (-1 * x64) + x77;
	const GEN_FLT x89 = lh_qi * lh_qi * lh_qi;
	const GEN_FLT x90 =
		(((2 * x12) + (-1 * x89 * x66) + x43 + (x89 * x61)) * x30) + ((x87 + x83) * x31) + ((x76 + x88) * x27);
	const GEN_FLT x91 = 1. / x41;
	const GEN_FLT x92 = x57 * x42;
	const GEN_FLT x93 = x80 * x44;
	const GEN_FLT x94 = x2 * x61;
	const GEN_FLT x95 = (x94 * lh_qi) + (-1 * x2 * x70);
	const GEN_FLT x96 = x68 + (-1 * x6);
	const GEN_FLT x97 = (-1 * x86) + x85;
	const GEN_FLT x98 = ((x97 + x83) * x30) + ((x95 + x43) * x31) + (x27 * (x96 + (-1 * x60) + x62));
	const GEN_FLT x99 = x42 * x46;
	const GEN_FLT x100 = 2 * x44;
	const GEN_FLT x101 = 1.0 / 2.0 * x54;
	const GEN_FLT x102 = (-1 * x47 * ((x90 * x48) + (-1 * x101 * ((x79 * x50) + (x98 * x100))))) +
						 (-1 * ((x91 * x98) + (-1 * x79 * x93)) * x99);
	const GEN_FLT x103 = (x94 * lh_qk) + (-1 * x2 * x74);
	const GEN_FLT x104 = x103 + x73;
	const GEN_FLT x105 = (x71 * lh_qj) + (-1 * x0 * x67);
	const GEN_FLT x106 = x2 * x59;
	const GEN_FLT x107 = (x30 * (x96 + (-1 * x106) + x94)) + (x31 * (x88 + x104)) + (x27 * (x105 + x37));
	const GEN_FLT x108 = x95 + x12;
	const GEN_FLT x109 = x84 * lh_qj;
	const GEN_FLT x110 = x63 * lh_qk;
	const GEN_FLT x111 = x110 + (-1 * x109);
	const GEN_FLT x112 = ((x82 + x37) * x30) + ((x111 + x108) * x31) + (x27 * (x69 + x106 + (-1 * x94)));
	const GEN_FLT x113 = lh_qj * lh_qj * lh_qj;
	const GEN_FLT x114 = (-1 * x110) + x109;
	const GEN_FLT x115 =
		((x37 + (-1 * x66 * x113) + (x61 * x113) + (2 * x39)) * x31) + ((x114 + x108) * x30) + (x27 * (x78 + x104));
	const GEN_FLT x116 = (-1 * x47 * ((x48 * x112) + (-1 * x101 * ((x50 * x107) + (x100 * x115))))) +
						 (-1 * ((x91 * x115) + (-1 * x93 * x107)) * x99);
	const GEN_FLT x117 = x105 + x39;
	const GEN_FLT x118 = lh_qk * lh_qk * lh_qk;
	const GEN_FLT x119 = x72 + x12;
	const GEN_FLT x120 =
		((x119 + x111) * x30) + (x31 * (x117 + x97)) + ((x33 + (x61 * x118) + (2 * x73) + (-1 * x66 * x118)) * x27);
	const GEN_FLT x121 = x0 * x59;
	const GEN_FLT x122 = ((x75 + x33) * x30) + (x31 * (x96 + x71 + (-1 * x121))) + ((x119 + x114) * x27);
	const GEN_FLT x123 = (x30 * (x69 + (-1 * x71) + x121)) + (x27 * (x117 + x87)) + (x31 * (x103 + x33));
	const GEN_FLT x124 = (-1 * x47 * ((x48 * x122) + (-1 * x101 * ((x50 * x120) + (x100 * x123))))) +
						 (-1 * ((x91 * x123) + (-1 * x93 * x120)) * x99);
	out[0] = (-1 * x53 * x49) + (-1 * x49) + (-1 * x50 * x52);
	out[1] = x56 + (x53 * x56);
	out[2] = x58 + (x57 * x35) + (x53 * x58);
	out[3] = x102 + (((-1 * x91 * x90) + (x81 * x79)) * x92) + (x53 * x102);
	out[4] = x116 + (((-1 * x91 * x112) + (x81 * x107)) * x92) + (x53 * x116);
	out[5] = x124 + (((-1 * x91 * x122) + (x81 * x120)) * x92) + (x53 * x124);
}

// Jacobian of reproject_axis_y wrt [phase_1, tilt_1, curve_1, gibPhase_1, gibMag_1, ogeeMag_1, ogeePhase_1]
static inline void gen_reproject_axis_y_jac_bsc1_axis_angle(FLT *out, const LinmathAxisAnglePose *obj_p,
															const FLT *sensor_pt, const LinmathAxisAnglePose *lh_p,
															const BaseStationCal *bsc1) {
	const GEN_FLT obj_px = (*obj_p).Pos[0];
	const GEN_FLT obj_py = (*obj_p).Pos[1];
	const GEN_FLT obj_pz = (*obj_p).Pos[2];
	const GEN_FLT obj_qi = (*obj_p).AxisAngleRot[0];
	const GEN_FLT obj_qj = (*obj_p).AxisAngleRot[1];
	const GEN_FLT obj_qk = (*obj_p).AxisAngleRot[2];
	const GEN_FLT sensor_x = sensor_pt[0];
	const GEN_FLT sensor_y = sensor_pt[1];
	const GEN_FLT sensor_z = sensor_pt[2];
	const GEN_FLT lh_px = (*lh_p).Pos[0];
	const GEN_FLT lh_py = (*lh_p).Pos[1];
	const GEN_FLT lh_pz = (*lh_p).Pos[2];
	const GEN_FLT lh_qi = (*lh_p).AxisAngleRot[0];
	const GEN_FLT lh_qj = (*lh_p).AxisAngleRot[1];
	const GEN_FLT lh_qk = (*lh_p).AxisAngleRot[2];
	const GEN_FLT phase_1 = (*bsc1).phase;
	const GEN_FLT tilt_1 = (*bsc1).tilt;
	const GEN_FLT curve_1 = (*bsc1).curve;
	const GEN_FLT gibPhase_1 = (*bsc1).gibpha;
	const GEN_FLT gibMag_1 = (*bsc1).gibmag;
	const GEN_FLT ogeeMag_1 = (*bsc1).ogeephase;
	const GEN_FLT ogeePhase_1 = (*bsc1).ogeemag;
	const GEN_FLT x0 = lh_qk * lh_qk;
	const GEN_FLT x1 = lh_qi * lh_qi;
	const GEN_FLT x2 = lh_qj * lh_qj;
	const GEN_FLT x3 = 1e-10 + x2 + x0 + x1;
	const GEN_FLT x4 = sqrt(x3);
	const GEN_FLT x5 = (1. / x4) * sin(x4);
	const GEN_FLT x6 = x5 * lh_qj;
	const GEN_FLT x7 = cos(x4);
	const GEN_FLT x8 = (1. / x3) * (1 + (-1 * x7));
	const GEN_FLT x9 = x8 * lh_qk;
	const GEN_FLT x10 = x9 * lh_qi;
	const GEN_FLT x11 = obj_qk * obj_qk;
	const GEN_FLT x12 = obj_qi * obj_qi;
	const GEN_FLT x13 = obj_qj * obj_qj;
	const GEN_FLT x14 = 1e-10 + x13 + x11 + x12;
	const GEN_FLT x15 = sqrt(x14);
	const GEN_FLT x16 = cos(x15);
	const GEN_FLT x17 = (1. / x14) * (1 + (-1 * x16));
	const GEN_FLT x18 = (1. / x15) * sin(x15);
	const GEN_FLT x19 = x18 * obj_qj;
	const GEN_FLT x20 = x17 * obj_qk;
	const GEN_FLT x21 = x20 * obj_qi;
	const GEN_FLT x22 = x18 * obj_qi;
	const GEN_FLT x23 = x20 * obj_qj;
	const GEN_FLT x24 =
		((x23 + x22) * sensor_y) + ((x21 + (-1 * x19)) * sensor_x) + obj_pz + ((x16 + (x11 * x17)) * sensor_z);
	const GEN_FLT x25 = x18 * obj_qk;
	const GEN_FLT x26 = x17 * obj_qj * obj_qi;
	const GEN_FLT x27 =
		((x26 + (-1 * x25)) * sensor_y) + ((x21 + x19) * sensor_z) + ((x16 + (x12 * x17)) * sensor_x) + obj_px;
	const GEN_FLT x28 =
		((x26 + x25) * sensor_x) + obj_py + ((x16 + (x13 * x17)) * sensor_y) + ((x23 + (-1 * x22)) * sensor_z);
	const GEN_FLT x29 = x5 * lh_qk;
	const GEN_FLT x30 = x8 * lh_qj * lh_qi;
	const GEN_FLT x31 = (x27 * (x7 + (x1 * x8))) + lh_px + ((x30 + (-1 * x29)) * x28) + (x24 * (x10 + x6));
	const GEN_FLT x32 = x5 * lh_qi;
	const GEN_FLT x33 = x9 * lh_qj;
	const GEN_FLT x34 = (x27 * (x10 + (-1 * x6))) + ((x33 + x32) * x28) + lh_pz + (x24 * (x7 + (x0 * x8)));
	const GEN_FLT x35 = (x28 * (x7 + (x2 * x8))) + ((x30 + x29) * x27) + lh_py + ((x33 + (-1 * x32)) * x24);
	const GEN_FLT x36 = (x35 * x35) + (x34 * x34);
	const GEN_FLT x37 = x31 * (1. / sqrt(x36));
	const GEN_FLT x38 = -1 * x34;
	const GEN_FLT x39 =
		1.5707963267949 + (-1 * phase_1) + (-1 * atan2(-1 * x35, x38)) + gibPhase_1 + (-1 * asin(x37 * tilt_1));
	const GEN_FLT x40 = sin(x39) * gibMag_1;
	const GEN_FLT x41 = x37 * (1. / sqrt(1 + (-1 * (x31 * x31) * (1. / x36) * (tilt_1 * tilt_1))));
	out[0] = -1 + (-1 * x40);
	out[1] = (-1 * x40 * x41) + (-1 * x41);
	out[2] = atan2(x31, x38) * atan2(x31, x38);
	out[3] = x40;
	out[4] = -1 * cos(x39);
	out[5] = 0;
	out[6] = 0;
}

static inline void gen_reproject_gen2(FLT *out, const SurvivePose *obj_p, const FLT *sensor_pt, const SurvivePose *lh_p,
									  const BaseStationCal *bsd) {
	const GEN_FLT obj_px = (*obj_p).Pos[0];
	const GEN_FLT obj_py = (*obj_p).Pos[1];
	const GEN_FLT obj_pz = (*obj_p).Pos[2];
	const GEN_FLT obj_qw = (*obj_p).Rot[0];
	const GEN_FLT obj_qi = (*obj_p).Rot[1];
	const GEN_FLT obj_qj = (*obj_p).Rot[2];
	const GEN_FLT obj_qk = (*obj_p).Rot[3];
	const GEN_FLT sensor_x = sensor_pt[0];
	const GEN_FLT sensor_y = sensor_pt[1];
	const GEN_FLT sensor_z = sensor_pt[2];
	const GEN_FLT lh_px = (*lh_p).Pos[0];
	const GEN_FLT lh_py = (*lh_p).Pos[1];
	const GEN_FLT lh_pz = (*lh_p).Pos[2];
	const GEN_FLT lh_qw = (*lh_p).Rot[0];
	const GEN_FLT lh_qi = (*lh_p).Rot[1];
	const GEN_FLT lh_qj = (*lh_p).Rot[2];
	const GEN_FLT lh_qk = (*lh_p).Rot[3];
	const GEN_FLT phase_0 = bsd[0].phase;
	const GEN_FLT tilt_0 = bsd[0].tilt;
	const GEN_FLT curve_0 = bsd[0].curve;
	const GEN_FLT gibPhase_0 = bsd[0].gibpha;
	const GEN_FLT gibMag_0 = bsd[0].gibmag;
	const GEN_FLT ogeeMag_0 = bsd[0].ogeephase;
	const GEN_FLT ogeePhase_0 = bsd[0].ogeemag;
	const GEN_FLT phase_1 = bsd[1].phase;
	const GEN_FLT tilt_1 = bsd[1].tilt;
	const GEN_FLT curve_1 = bsd[1].curve;
	const GEN_FLT gibPhase_1 = bsd[1].gibpha;
	const GEN_FLT gibMag_1 = bsd[1].gibmag;
	const GEN_FLT ogeeMag_1 = bsd[1].ogeephase;
	const GEN_FLT ogeePhase_1 = bsd[1].ogeemag;
	const GEN_FLT x0 = (obj_qk * sensor_x) + (-1 * obj_qi * sensor_z) + (obj_qw * sensor_y);
	const GEN_FLT x1 = (-1 * obj_qj * sensor_x) + (obj_qw * sensor_z) + (obj_qi * sensor_y);
	const GEN_FLT x2 = (2 * ((x1 * obj_qj) + (-1 * x0 * obj_qk))) + obj_px + sensor_x;
	const GEN_FLT x3 = (obj_qw * sensor_x) + (-1 * obj_qk * sensor_y) + (obj_qj * sensor_z);
	const GEN_FLT x4 = (2 * ((x0 * obj_qi) + (-1 * x3 * obj_qj))) + obj_pz + sensor_z;
	const GEN_FLT x5 = obj_py + (2 * ((x3 * obj_qk) + (-1 * x1 * obj_qi))) + sensor_y;
	const GEN_FLT x6 = (-1 * x5 * lh_qk) + (x2 * lh_qw) + (x4 * lh_qj);
	const GEN_FLT x7 = (x5 * lh_qw) + (-1 * x4 * lh_qi) + (x2 * lh_qk);
	const GEN_FLT x8 = x4 + lh_pz + (2 * ((x7 * lh_qi) + (-1 * x6 * lh_qj)));
	const GEN_FLT x9 = (x4 * lh_qw) + (-1 * x2 * lh_qj) + (x5 * lh_qi);
	const GEN_FLT x10 = lh_px + x2 + (2 * ((x9 * lh_qj) + (-1 * x7 * lh_qk)));
	const GEN_FLT x11 = atan2(-1 * x8, x10);
	const GEN_FLT x12 = 0.523598775598299 + tilt_0;
	const GEN_FLT x13 = (x10 * x10) + (x8 * x8);
	const GEN_FLT x14 = x5 + lh_py + (2 * ((x6 * lh_qk) + (-1 * x9 * lh_qi)));
	const GEN_FLT x15 = x14 * (1. / sqrt(x13));
	const GEN_FLT x16 = x15 * tan(x12);
	const GEN_FLT x17 = (sin((-1 * asin(x16)) + ogeeMag_0 + x11) * ogeePhase_0) + curve_0;
	const GEN_FLT x18 = cos(x12);
	const GEN_FLT x19 = x14 * (1. / sqrt(x13 + (x14 * x14)));
	const GEN_FLT x20 = asin(x19 * (1. / x18));
	const GEN_FLT x21 = 0.0028679863 + (x20 * (-8.0108022e-06 + (-8.0108022e-06 * x20)));
	const GEN_FLT x22 = 5.3685255e-06 + (x20 * x21);
	const GEN_FLT x23 = 0.0076069798 + (x22 * x20);
	const GEN_FLT x24 = asin(
		x16 +
		(x23 * (x20 * x20) * x17 *
		 (1. /
		  (x18 + (-1 * x17 * sin(x12) *
				  ((x20 * (x23 + (x20 * (x22 + (x20 * (x21 + (x20 * (-8.0108022e-06 + (-1.60216044e-05 * x20))))))))) +
				   (x23 * x20)))))));
	const GEN_FLT x25 = 0.523598775598299 + (-1 * tilt_1);
	const GEN_FLT x26 = cos(x25);
	const GEN_FLT x27 = asin((1. / x26) * x19);
	const GEN_FLT x28 = 0.0028679863 + (x27 * (-8.0108022e-06 + (-8.0108022e-06 * x27)));
	const GEN_FLT x29 = 5.3685255e-06 + (x28 * x27);
	const GEN_FLT x30 = 0.0076069798 + (x29 * x27);
	const GEN_FLT x31 = -1 * x15 * tan(x25);
	const GEN_FLT x32 = (sin((-1 * asin(x31)) + ogeeMag_1 + x11) * ogeePhase_1) + curve_1;
	const GEN_FLT x33 =
		(-1 *
		 asin(x31 + (x30 * x32 * (x27 * x27) *
					 (1. / (x26 + (x32 * sin(x25) *
								   ((x27 * (x30 + (x27 * (x29 + (x27 * (x28 + (x27 * (-8.0108022e-06 +
																					  (-1.60216044e-05 * x27))))))))) +
									(x30 * x27)))))))) +
		x11;
	out[0] = -1.5707963267949 + (-1 * x24) + (-1 * sin(x24 + (-1 * gibPhase_0) + (-1 * x11)) * gibMag_0) +
			 (-1 * phase_0) + x11;
	out[1] = -1.5707963267949 + x33 + (-1 * phase_1) + (sin(x33 + gibPhase_1) * gibMag_1);
}

// Jacobian of reproject_gen2 wrt [obj_px, obj_py, obj_pz, obj_qw, obj_qi, obj_qj, obj_qk]
static inline void gen_reproject_gen2_jac_obj_p(FLT *out, const SurvivePose *obj_p, const FLT *sensor_pt,
												const SurvivePose *lh_p, const BaseStationCal *bsd) {
	const GEN_FLT obj_px = (*obj_p).Pos[0];
	const GEN_FLT obj_py = (*obj_p).Pos[1];
	const GEN_FLT obj_pz = (*obj_p).Pos[2];
	const GEN_FLT obj_qw = (*obj_p).Rot[0];
	const GEN_FLT obj_qi = (*obj_p).Rot[1];
	const GEN_FLT obj_qj = (*obj_p).Rot[2];
	const GEN_FLT obj_qk = (*obj_p).Rot[3];
	const GEN_FLT sensor_x = sensor_pt[0];
	const GEN_FLT sensor_y = sensor_pt[1];
	const GEN_FLT sensor_z = sensor_pt[2];
	const GEN_FLT lh_px = (*lh_p).Pos[0];
	const GEN_FLT lh_py = (*lh_p).Pos[1];
	const GEN_FLT lh_pz = (*lh_p).Pos[2];
	const GEN_FLT lh_qw = (*lh_p).Rot[0];
	const GEN_FLT lh_qi = (*lh_p).Rot[1];
	const GEN_FLT lh_qj = (*lh_p).Rot[2];
	const GEN_FLT lh_qk = (*lh_p).Rot[3];
	const GEN_FLT phase_0 = bsd[0].phase;
	const GEN_FLT tilt_0 = bsd[0].tilt;
	const GEN_FLT curve_0 = bsd[0].curve;
	const GEN_FLT gibPhase_0 = bsd[0].gibpha;
	const GEN_FLT gibMag_0 = bsd[0].gibmag;
	const GEN_FLT ogeeMag_0 = bsd[0].ogeephase;
	const GEN_FLT ogeePhase_0 = bsd[0].ogeemag;
	const GEN_FLT phase_1 = bsd[1].phase;
	const GEN_FLT tilt_1 = bsd[1].tilt;
	const GEN_FLT curve_1 = bsd[1].curve;
	const GEN_FLT gibPhase_1 = bsd[1].gibpha;
	const GEN_FLT gibMag_1 = bsd[1].gibmag;
	const GEN_FLT ogeeMag_1 = bsd[1].ogeephase;
	const GEN_FLT ogeePhase_1 = bsd[1].ogeemag;
	const GEN_FLT x0 = 0.523598775598299 + tilt_0;
	const GEN_FLT x1 = cos(x0);
	const GEN_FLT x2 = 1. / x1;
	const GEN_FLT x3 = obj_qw * sensor_x;
	const GEN_FLT x4 = obj_qj * sensor_z;
	const GEN_FLT x5 = obj_qk * sensor_y;
	const GEN_FLT x6 = (-1 * x5) + x3 + x4;
	const GEN_FLT x7 = obj_qk * sensor_x;
	const GEN_FLT x8 = obj_qw * sensor_y;
	const GEN_FLT x9 = obj_qi * sensor_z;
	const GEN_FLT x10 = (-1 * x9) + x7 + x8;
	const GEN_FLT x11 = (2 * ((x10 * obj_qi) + (-1 * x6 * obj_qj))) + obj_pz + sensor_z;
	const GEN_FLT x12 = obj_qw * sensor_z;
	const GEN_FLT x13 = obj_qi * sensor_y;
	const GEN_FLT x14 = obj_qj * sensor_x;
	const GEN_FLT x15 = (-1 * x14) + x12 + x13;
	const GEN_FLT x16 = (2 * ((x6 * obj_qk) + (-1 * x15 * obj_qi))) + obj_py + sensor_y;
	const GEN_FLT x17 = (2 * ((x15 * obj_qj) + (-1 * x10 * obj_qk))) + obj_px + sensor_x;
	const GEN_FLT x18 = (-1 * x17 * lh_qj) + (x11 * lh_qw) + (x16 * lh_qi);
	const GEN_FLT x19 = (-1 * x16 * lh_qk) + (x17 * lh_qw) + (x11 * lh_qj);
	const GEN_FLT x20 = x16 + lh_py + (2 * ((x19 * lh_qk) + (-1 * x18 * lh_qi)));
	const GEN_FLT x21 = x20 * x20;
	const GEN_FLT x22 = (x16 * lh_qw) + (-1 * x11 * lh_qi) + (x17 * lh_qk);
	const GEN_FLT x23 = x11 + lh_pz + (2 * ((x22 * lh_qi) + (-1 * x19 * lh_qj)));
	const GEN_FLT x24 = lh_px + x17 + (2 * ((x18 * lh_qj) + (-1 * x22 * lh_qk)));
	const GEN_FLT x25 = x24 * x24;
	const GEN_FLT x26 = x25 + (x23 * x23);
	const GEN_FLT x27 = x26 + x21;
	const GEN_FLT x28 = 1. / sqrt(x27);
	const GEN_FLT x29 = x20 * x28;
	const GEN_FLT x30 = asin(x2 * x29);
	const GEN_FLT x31 = 8.0108022e-06 * x30;
	const GEN_FLT x32 = -8.0108022e-06 + (-1 * x31);
	const GEN_FLT x33 = 0.0028679863 + (x30 * x32);
	const GEN_FLT x34 = 5.3685255e-06 + (x30 * x33);
	const GEN_FLT x35 = 0.0076069798 + (x30 * x34);
	const GEN_FLT x36 = x30 * x35;
	const GEN_FLT x37 = -8.0108022e-06 + (-1.60216044e-05 * x30);
	const GEN_FLT x38 = x33 + (x30 * x37);
	const GEN_FLT x39 = x34 + (x30 * x38);
	const GEN_FLT x40 = x35 + (x30 * x39);
	const GEN_FLT x41 = (x40 * x30) + x36;
	const GEN_FLT x42 = sin(x0);
	const GEN_FLT x43 = atan2(-1 * x23, x24);
	const GEN_FLT x44 = 1. / sqrt(x26);
	const GEN_FLT x45 = tan(x0);
	const GEN_FLT x46 = x44 * x45;
	const GEN_FLT x47 = x46 * x20;
	const GEN_FLT x48 = (-1 * asin(x47)) + ogeeMag_0 + x43;
	const GEN_FLT x49 = (sin(x48) * ogeePhase_0) + curve_0;
	const GEN_FLT x50 = x42 * x49;
	const GEN_FLT x51 = x1 + (-1 * x50 * x41);
	const GEN_FLT x52 = 1. / x51;
	const GEN_FLT x53 = x30 * x30;
	const GEN_FLT x54 = x53 * x49;
	const GEN_FLT x55 = x54 * x52;
	const GEN_FLT x56 = x47 + (x55 * x35);
	const GEN_FLT x57 = 1. / sqrt(1 + (-1 * (x56 * x56)));
	const GEN_FLT x58 = 1. / x26;
	const GEN_FLT x59 = x58 * x21;
	const GEN_FLT x60 = 1. / sqrt(1 + (-1 * x59 * (x45 * x45)));
	const GEN_FLT x61 = 2 * lh_qj;
	const GEN_FLT x62 = x61 * lh_qi;
	const GEN_FLT x63 = 2 * lh_qk;
	const GEN_FLT x64 = x63 * lh_qw;
	const GEN_FLT x65 = x64 + x62;
	const GEN_FLT x66 = x65 * x44;
	const GEN_FLT x67 = -2 * (lh_qk * lh_qk);
	const GEN_FLT x68 = -2 * (lh_qj * lh_qj);
	const GEN_FLT x69 = 1 + x68 + x67;
	const GEN_FLT x70 = 2 * x24;
	const GEN_FLT x71 = x61 * lh_qw;
	const GEN_FLT x72 = x63 * lh_qi;
	const GEN_FLT x73 = x72 + (-1 * x71);
	const GEN_FLT x74 = 2 * x23;
	const GEN_FLT x75 = (x73 * x74) + (x70 * x69);
	const GEN_FLT x76 = 1.0 / 2.0 * x20;
	const GEN_FLT x77 = x76 * (1. / (x26 * sqrt(x26)));
	const GEN_FLT x78 = x77 * x45;
	const GEN_FLT x79 = (-1 * x78 * x75) + (x66 * x45);
	const GEN_FLT x80 = 1. / x24;
	const GEN_FLT x81 = (1. / x25) * x23;
	const GEN_FLT x82 = x58 * x25;
	const GEN_FLT x83 = ((x81 * x69) + (-1 * x80 * x73)) * x82;
	const GEN_FLT x84 = cos(x48) * ogeePhase_0;
	const GEN_FLT x85 = x84 * (x83 + (-1 * x79 * x60));
	const GEN_FLT x86 = x53 * x52 * x35;
	const GEN_FLT x87 = 2 * x20;
	const GEN_FLT x88 = x75 + (x87 * x65);
	const GEN_FLT x89 = x76 * (1. / (x27 * sqrt(x27)));
	const GEN_FLT x90 = x2 * x89;
	const GEN_FLT x91 = x65 * x28;
	const GEN_FLT x92 = (x2 * x91) + (-1 * x88 * x90);
	const GEN_FLT x93 = x21 * (1. / x27);
	const GEN_FLT x94 = 1. / sqrt(1 + (-1 * (1. / (x1 * x1)) * x93));
	const GEN_FLT x95 = x94 * x40;
	const GEN_FLT x96 = x94 * x39;
	const GEN_FLT x97 = x94 * x32;
	const GEN_FLT x98 = x92 * x97;
	const GEN_FLT x99 = x94 * x37;
	const GEN_FLT x100 = 2.40324066e-05 * x30;
	const GEN_FLT x101 = x94 * x100;
	const GEN_FLT x102 = x94 * x38;
	const GEN_FLT x103 = x94 * x31;
	const GEN_FLT x104 = x94 * x33;
	const GEN_FLT x105 = (x92 * x104) + (x30 * (x98 + (-1 * x92 * x103)));
	const GEN_FLT x106 = x94 * x34;
	const GEN_FLT x107 = (x30 * x105) + (x92 * x106);
	const GEN_FLT x108 = x94 * x35;
	const GEN_FLT x109 = x41 * x42;
	const GEN_FLT x110 = x54 * (1. / (x51 * x51)) * x35;
	const GEN_FLT x111 = 2 * x52 * x49 * x36;
	const GEN_FLT x112 = x94 * x111;
	const GEN_FLT x113 =
		x57 * ((x55 * x107) + (x92 * x112) + (x85 * x86) + x79 +
			   (-1 * x110 *
				((-1 * x85 * x109) +
				 (-1 * x50 *
				  ((x30 * x107) + (x92 * x108) + (x92 * x95) +
				   (x30 * (x107 + (x92 * x96) +
						   (x30 * (x105 + (x30 * (x98 + (-1 * x92 * x101) + (x92 * x99))) + (x92 * x102))))))))));
	const GEN_FLT x114 = cos(gibPhase_0 + (-1 * asin(x56)) + x43) * gibMag_0;
	const GEN_FLT x115 = 1 + (-2 * (lh_qi * lh_qi));
	const GEN_FLT x116 = x115 + x67;
	const GEN_FLT x117 = x62 + (-1 * x64);
	const GEN_FLT x118 = x63 * lh_qj;
	const GEN_FLT x119 = 2 * lh_qi;
	const GEN_FLT x120 = x119 * lh_qw;
	const GEN_FLT x121 = x120 + x118;
	const GEN_FLT x122 = (x74 * x121) + (x70 * x117);
	const GEN_FLT x123 = x122 + (x87 * x116);
	const GEN_FLT x124 = x28 * x116;
	const GEN_FLT x125 = (x2 * x124) + (-1 * x90 * x123);
	const GEN_FLT x126 = x94 * x125;
	const GEN_FLT x127 = x32 * x126;
	const GEN_FLT x128 = (x33 * x126) + (x30 * (x127 + (-1 * x31 * x126)));
	const GEN_FLT x129 = (x30 * x128) + (x34 * x126);
	const GEN_FLT x130 = x77 * x122;
	const GEN_FLT x131 = (-1 * x45 * x130) + (x46 * x116);
	const GEN_FLT x132 = ((x81 * x117) + (-1 * x80 * x121)) * x82;
	const GEN_FLT x133 = x132 + (-1 * x60 * x131);
	const GEN_FLT x134 = x84 * x109;
	const GEN_FLT x135 = x84 * x86;
	const GEN_FLT x136 =
		x57 * (x131 + (x133 * x135) + (x55 * x129) + (x111 * x126) +
			   (-1 * x110 *
				((-1 * x133 * x134) +
				 (-1 * x50 *
				  ((x30 * x129) + (x40 * x126) + (x108 * x125) +
				   (x30 * (x129 + (x96 * x125) +
						   (x30 * (x128 + (x30 * ((-1 * x100 * x126) + (x37 * x126) + x127)) + (x102 * x125))))))))));
	const GEN_FLT x137 = x118 + (-1 * x120);
	const GEN_FLT x138 = x44 * x137;
	const GEN_FLT x139 = x71 + x72;
	const GEN_FLT x140 = x115 + x68;
	const GEN_FLT x141 = (x74 * x140) + (x70 * x139);
	const GEN_FLT x142 = x77 * x141;
	const GEN_FLT x143 = (-1 * x45 * x142) + (x45 * x138);
	const GEN_FLT x144 = ((x81 * x139) + (-1 * x80 * x140)) * x82;
	const GEN_FLT x145 = x144 + (-1 * x60 * x143);
	const GEN_FLT x146 = x141 + (x87 * x137);
	const GEN_FLT x147 = x28 * x137;
	const GEN_FLT x148 = (x2 * x147) + (-1 * x90 * x146);
	const GEN_FLT x149 = x94 * x148;
	const GEN_FLT x150 = x32 * x149;
	const GEN_FLT x151 = (x33 * x149) + (x30 * (x150 + (-1 * x31 * x149)));
	const GEN_FLT x152 = (x30 * x151) + (x34 * x149);
	const GEN_FLT x153 =
		x57 * ((x55 * x152) +
			   (-1 * x110 *
				((-1 * x134 * x145) +
				 (-1 * x50 *
				  ((x30 * x152) + (x108 * x148) +
				   (x30 * (x152 + (x39 * x149) +
						   (x30 * (x151 + (x30 * ((-1 * x100 * x149) + x150 + (x37 * x149))) + (x38 * x149))))) +
				   (x40 * x149))))) +
			   x143 + (x135 * x145) + (x111 * x149));
	const GEN_FLT x154 = 2 * x9;
	const GEN_FLT x155 = 2 * x7;
	const GEN_FLT x156 = x155 + (-1 * x154);
	const GEN_FLT x157 = 2 * x5;
	const GEN_FLT x158 = 2 * x4;
	const GEN_FLT x159 = x158 + (-1 * x157);
	const GEN_FLT x160 = 2 * x14;
	const GEN_FLT x161 = 2 * x13;
	const GEN_FLT x162 = x161 + (-1 * x160);
	const GEN_FLT x163 = (x162 * lh_qj) + (-1 * x156 * lh_qk) + (x159 * lh_qw);
	const GEN_FLT x164 = (x156 * lh_qi) + (x162 * lh_qw) + (-1 * x159 * lh_qj);
	const GEN_FLT x165 = x156 + (x63 * x163) + (-1 * x119 * x164);
	const GEN_FLT x166 = (x159 * lh_qk) + (-1 * x162 * lh_qi) + (x156 * lh_qw);
	const GEN_FLT x167 = x159 + (x61 * x164) + (-1 * x63 * x166);
	const GEN_FLT x168 = (x119 * x166) + x162 + (-1 * x61 * x163);
	const GEN_FLT x169 = (x74 * x168) + (x70 * x167);
	const GEN_FLT x170 = x169 + (x87 * x165);
	const GEN_FLT x171 = x28 * x165;
	const GEN_FLT x172 = (x2 * x171) + (-1 * x90 * x170);
	const GEN_FLT x173 = x97 * x172;
	const GEN_FLT x174 = x94 * x172;
	const GEN_FLT x175 = (x104 * x172) + (x30 * (x173 + (-1 * x31 * x174)));
	const GEN_FLT x176 = (x30 * x175) + (x106 * x172);
	const GEN_FLT x177 = x77 * x169;
	const GEN_FLT x178 = (-1 * x45 * x177) + (x46 * x165);
	const GEN_FLT x179 = ((x81 * x167) + (-1 * x80 * x168)) * x82;
	const GEN_FLT x180 = x179 + (-1 * x60 * x178);
	const GEN_FLT x181 =
		x57 * ((x55 * x176) + (x180 * x135) +
			   (-1 * x110 *
				((-1 * x180 * x134) +
				 (-1 * x50 *
				  ((x108 * x172) + (x95 * x172) + (x30 * x176) +
				   (x30 * (x176 + (x96 * x172) +
						   (x30 * (x175 + (x30 * ((-1 * x100 * x174) + x173 + (x99 * x172))) + (x102 * x172))))))))) +
			   x178 + (x111 * x174));
	const GEN_FLT x182 = 2 * x8;
	const GEN_FLT x183 = x155 + x182 + (-4 * x9);
	const GEN_FLT x184 = 2 * x12;
	const GEN_FLT x185 = x160 + (-4 * x13) + (-1 * x184);
	const GEN_FLT x186 = 2 * obj_qk * sensor_z;
	const GEN_FLT x187 = 2 * obj_qj * sensor_y;
	const GEN_FLT x188 = x187 + x186;
	const GEN_FLT x189 = (x188 * lh_qk) + (-1 * x183 * lh_qi) + (x185 * lh_qw);
	const GEN_FLT x190 = (x183 * lh_qj) + (-1 * x185 * lh_qk) + (x188 * lh_qw);
	const GEN_FLT x191 = x183 + (x119 * x189) + (-1 * x61 * x190);
	const GEN_FLT x192 = (x185 * lh_qi) + (x183 * lh_qw) + (-1 * x188 * lh_qj);
	const GEN_FLT x193 = (x61 * x192) + x188 + (-1 * x63 * x189);
	const GEN_FLT x194 = ((x81 * x193) + (-1 * x80 * x191)) * x82;
	const GEN_FLT x195 = (x63 * x190) + x185 + (-1 * x119 * x192);
	const GEN_FLT x196 = (x74 * x191) + (x70 * x193);
	const GEN_FLT x197 = x89 * (x196 + (x87 * x195));
	const GEN_FLT x198 = x28 * x195;
	const GEN_FLT x199 = (x2 * x198) + (-1 * x2 * x197);
	const GEN_FLT x200 = x97 * x199;
	const GEN_FLT x201 = (x104 * x199) + (x30 * (x200 + (-1 * x103 * x199)));
	const GEN_FLT x202 = (x30 * x201) + (x106 * x199);
	const GEN_FLT x203 = x44 * x195;
	const GEN_FLT x204 = x77 * x196;
	const GEN_FLT x205 = (-1 * x45 * x204) + (x45 * x203);
	const GEN_FLT x206 = x194 + (-1 * x60 * x205);
	const GEN_FLT x207 =
		x57 * (x205 + (x206 * x135) + (x55 * x202) +
			   (-1 * x110 *
				((-1 * x206 * x134) +
				 (-1 * x50 *
				  ((x30 * x202) +
				   (x30 * (x202 + (x96 * x199) +
						   (x30 * (x201 + (x30 * ((-1 * x101 * x199) + x200 + (x99 * x199))) + (x102 * x199))))) +
				   (x108 * x199) + (x95 * x199))))) +
			   (x112 * x199));
	const GEN_FLT x208 = 2 * obj_qi * sensor_x;
	const GEN_FLT x209 = x186 + x208;
	const GEN_FLT x210 = (-4 * x14) + x161 + x184;
	const GEN_FLT x211 = 2 * x3;
	const GEN_FLT x212 = (-4 * x4) + (-1 * x211) + x157;
	const GEN_FLT x213 = (-1 * x209 * lh_qk) + (x212 * lh_qj) + (x210 * lh_qw);
	const GEN_FLT x214 = 2 * ((x209 * lh_qi) + (-1 * x210 * lh_qj) + (x212 * lh_qw));
	const GEN_FLT x215 = x209 + (x63 * x213) + (-1 * x214 * lh_qi);
	const GEN_FLT x216 = (x210 * lh_qk) + (-1 * x212 * lh_qi) + (x209 * lh_qw);
	const GEN_FLT x217 = x210 + (x214 * lh_qj) + (-1 * x63 * x216);
	const GEN_FLT x218 = x212 + (x216 * x119) + (-1 * x61 * x213);
	const GEN_FLT x219 = (x74 * x218) + (x70 * x217);
	const GEN_FLT x220 = x219 + (x87 * x215);
	const GEN_FLT x221 = x28 * x215;
	const GEN_FLT x222 = (x2 * x221) + (-1 * x90 * x220);
	const GEN_FLT x223 = x97 * x222;
	const GEN_FLT x224 = (x222 * x104) + (x30 * (x223 + (-1 * x222 * x103)));
	const GEN_FLT x225 = (x30 * x224) + (x222 * x106);
	const GEN_FLT x226 = x44 * x215;
	const GEN_FLT x227 = (-1 * x78 * x219) + (x45 * x226);
	const GEN_FLT x228 = ((x81 * x217) + (-1 * x80 * x218)) * x82;
	const GEN_FLT x229 = x228 + (-1 * x60 * x227);
	const GEN_FLT x230 =
		x57 * (x227 + (x229 * x135) +
			   (-1 * x110 *
				((-1 * x229 * x134) +
				 (-1 * x50 *
				  ((x30 * x225) +
				   (x30 * (x225 + (x96 * x222) +
						   (x30 * (x224 + (x30 * ((-1 * x222 * x101) + (x99 * x222) + x223)) + (x222 * x102))))) +
				   (x95 * x222) + (x222 * x108))))) +
			   (x55 * x225) + (x222 * x112));
	const GEN_FLT x231 = x158 + x211 + (-4 * x5);
	const GEN_FLT x232 = (-1 * x182) + (-4 * x7) + x154;
	const GEN_FLT x233 = x208 + x187;
	const GEN_FLT x234 = (x233 * lh_qj) + (-1 * x231 * lh_qk) + (x232 * lh_qw);
	const GEN_FLT x235 = (x231 * lh_qi) + (-1 * x232 * lh_qj) + (x233 * lh_qw);
	const GEN_FLT x236 = x231 + (x63 * x234) + (-1 * x235 * x119);
	const GEN_FLT x237 = (x232 * lh_qk) + (x231 * lh_qw) + (-1 * x233 * lh_qi);
	const GEN_FLT x238 = x232 + (x61 * x235) + (-1 * x63 * x237);
	const GEN_FLT x239 = x233 + (x237 * x119) + (-1 * x61 * x234);
	const GEN_FLT x240 = (x74 * x239) + (x70 * x238);
	const GEN_FLT x241 = x240 + (x87 * x236);
	const GEN_FLT x242 = x28 * x236;
	const GEN_FLT x243 = (x2 * x242) + (-1 * x90 * x241);
	const GEN_FLT x244 = x44 * x236;
	const GEN_FLT x245 = x77 * x240;
	const GEN_FLT x246 = (-1 * x45 * x245) + (x45 * x244);
	const GEN_FLT x247 = ((x81 * x238) + (-1 * x80 * x239)) * x82;
	const GEN_FLT x248 = x247 + (-1 * x60 * x246);
	const GEN_FLT x249 = x97 * x243;
	const GEN_FLT x250 = (x243 * x104) + (x30 * (x249 + (-1 * x243 * x103)));
	const GEN_FLT x251 = (x30 * x250) + (x243 * x106);
	const GEN_FLT x252 =
		x57 * ((x55 * x251) + (x243 * x112) + x246 +
			   (-1 * x110 *
				((-1 * x248 * x134) +
				 (-1 * x50 *
				  ((x30 * x251) + (x243 * x108) + (x95 * x243) +
				   (x30 * (x251 + (x96 * x243) +
						   (x30 * (x250 + (x30 * ((-1 * x243 * x101) + x249 + (x99 * x243))) + (x243 * x102))))))))) +
			   (x248 * x135));
	const GEN_FLT x253 = 0.523598775598299 + (-1 * tilt_1);
	const GEN_FLT x254 = cos(x253);
	const GEN_FLT x255 = 1. / x254;
	const GEN_FLT x256 = x89 * x255;
	const GEN_FLT x257 = (x91 * x255) + (-1 * x88 * x256);
	const GEN_FLT x258 = asin(x29 * x255);
	const GEN_FLT x259 = -8.0108022e-06 + (-1.60216044e-05 * x258);
	const GEN_FLT x260 = 8.0108022e-06 * x258;
	const GEN_FLT x261 = -8.0108022e-06 + (-1 * x260);
	const GEN_FLT x262 = 0.0028679863 + (x261 * x258);
	const GEN_FLT x263 = x262 + (x258 * x259);
	const GEN_FLT x264 = 5.3685255e-06 + (x262 * x258);
	const GEN_FLT x265 = x264 + (x263 * x258);
	const GEN_FLT x266 = 0.0076069798 + (x264 * x258);
	const GEN_FLT x267 = x266 + (x265 * x258);
	const GEN_FLT x268 = 1. / sqrt(1 + (-1 * x93 * (1. / (x254 * x254))));
	const GEN_FLT x269 = x268 * x267;
	const GEN_FLT x270 = x268 * x266;
	const GEN_FLT x271 = x268 * x263;
	const GEN_FLT x272 = x268 * x261;
	const GEN_FLT x273 = x272 * x257;
	const GEN_FLT x274 = x268 * x259;
	const GEN_FLT x275 = 2.40324066e-05 * x258;
	const GEN_FLT x276 = x268 * x257;
	const GEN_FLT x277 = x268 * x262;
	const GEN_FLT x278 = (x277 * x257) + (x258 * (x273 + (-1 * x276 * x260)));
	const GEN_FLT x279 = x268 * x265;
	const GEN_FLT x280 = x268 * x264;
	const GEN_FLT x281 = (x280 * x257) + (x278 * x258);
	const GEN_FLT x282 = sin(x253);
	const GEN_FLT x283 = tan(x253);
	const GEN_FLT x284 = x44 * x283;
	const GEN_FLT x285 = -1 * x20 * x284;
	const GEN_FLT x286 = (-1 * asin(x285)) + ogeeMag_1 + x43;
	const GEN_FLT x287 = (sin(x286) * ogeePhase_1) + curve_1;
	const GEN_FLT x288 = x287 * x282;
	const GEN_FLT x289 = 1. / sqrt(1 + (-1 * x59 * (x283 * x283)));
	const GEN_FLT x290 = x77 * x283;
	const GEN_FLT x291 = (x75 * x290) + (-1 * x66 * x283);
	const GEN_FLT x292 = cos(x286) * ogeePhase_1;
	const GEN_FLT x293 = x292 * (x83 + (-1 * x291 * x289));
	const GEN_FLT x294 = x266 * x258;
	const GEN_FLT x295 = (x267 * x258) + x294;
	const GEN_FLT x296 = x295 * x282;
	const GEN_FLT x297 = x254 + (x295 * x288);
	const GEN_FLT x298 = x258 * x258;
	const GEN_FLT x299 = x298 * x287;
	const GEN_FLT x300 = (1. / (x297 * x297)) * x299 * x266;
	const GEN_FLT x301 = 1. / x297;
	const GEN_FLT x302 = x299 * x301;
	const GEN_FLT x303 = 2 * x294 * x287 * x301;
	const GEN_FLT x304 = x298 * x266 * x301;
	const GEN_FLT x305 = x285 + (x266 * x302);
	const GEN_FLT x306 = 1. / sqrt(1 + (-1 * (x305 * x305)));
	const GEN_FLT x307 =
		x83 +
		(-1 * x306 *
		 (x291 + (x293 * x304) + (x276 * x303) +
		  (-1 * x300 *
		   ((x296 * x293) +
			(x288 *
			 ((x281 * x258) +
			  (x258 * (x281 + (x258 * ((x271 * x257) + x278 + (x258 * (x273 + (-1 * x276 * x275) + (x274 * x257))))) +
					   (x279 * x257))) +
			  (x269 * x257) + (x270 * x257))))) +
		  (x281 * x302)));
	const GEN_FLT x308 = cos(gibPhase_1 + (-1 * asin(x305)) + x43) * gibMag_1;
	const GEN_FLT x309 = (x255 * x124) + (-1 * x256 * x123);
	const GEN_FLT x310 = x268 * x303;
	const GEN_FLT x311 = x272 * x309;
	const GEN_FLT x312 = x275 * x268;
	const GEN_FLT x313 = x268 * x260;
	const GEN_FLT x314 = (x277 * x309) + (x258 * (x311 + (-1 * x309 * x313)));
	const GEN_FLT x315 = (x280 * x309) + (x258 * x314);
	const GEN_FLT x316 = (x283 * x130) + (-1 * x284 * x116);
	const GEN_FLT x317 = x132 + (-1 * x289 * x316);
	const GEN_FLT x318 = x296 * x292;
	const GEN_FLT x319 = x292 * x304;
	const GEN_FLT x320 =
		x132 +
		(-1 * x306 *
		 ((x317 * x319) + (x302 * x315) + (x309 * x310) + x316 +
		  (-1 * x300 *
		   ((x317 * x318) +
			(x288 *
			 ((x258 * x315) + (x270 * x309) +
			  (x258 * (x315 + (x258 * (x314 + (x271 * x309) + (x258 * ((-1 * x309 * x312) + (x274 * x309) + x311)))) +
					   (x279 * x309))) +
			  (x269 * x309)))))));
	const GEN_FLT x321 = ((x255 * x147) + (-1 * x256 * x146)) * x268;
	const GEN_FLT x322 = x261 * x321;
	const GEN_FLT x323 = (x262 * x321) + (x258 * (x322 + (-1 * x260 * x321)));
	const GEN_FLT x324 = (x264 * x321) + (x258 * x323);
	const GEN_FLT x325 = (x283 * x142) + (-1 * x283 * x138);
	const GEN_FLT x326 = x144 + (-1 * x289 * x325);
	const GEN_FLT x327 =
		x144 +
		(-1 * x306 *
		 (x325 + (x302 * x324) + (x326 * x319) +
		  (-1 * x300 *
		   ((x326 * x318) +
			(x288 *
			 ((x258 * x324) + (x267 * x321) +
			  (x258 * (x324 + (x258 * (x323 + (x263 * x321) + (x258 * ((-1 * x275 * x321) + x322 + (x259 * x321))))) +
					   (x265 * x321))) +
			  (x266 * x321))))) +
		  (x303 * x321)));
	const GEN_FLT x328 = (x255 * x171) + (-1 * x256 * x170);
	const GEN_FLT x329 = x272 * x328;
	const GEN_FLT x330 = (x277 * x328) + (x258 * (x329 + (-1 * x328 * x313)));
	const GEN_FLT x331 = (x280 * x328) + (x258 * x330);
	const GEN_FLT x332 = (x283 * x177) + (-1 * x284 * x165);
	const GEN_FLT x333 = x179 + (-1 * x289 * x332);
	const GEN_FLT x334 =
		x179 +
		(-1 * x306 *
		 (x332 + (x333 * x319) + (x302 * x331) + (x328 * x310) +
		  (-1 * x300 *
		   ((x333 * x318) +
			(x288 *
			 ((x270 * x328) + (x258 * x331) +
			  (x258 * (x331 + (x258 * (x330 + (x271 * x328) + (x258 * ((-1 * x328 * x312) + x329 + (x274 * x328))))) +
					   (x279 * x328))) +
			  (x269 * x328)))))));
	const GEN_FLT x335 = (x255 * x198) + (-1 * x255 * x197);
	const GEN_FLT x336 = x272 * x335;
	const GEN_FLT x337 = (x277 * x335) + (x258 * (x336 + (-1 * x313 * x335)));
	const GEN_FLT x338 = (x280 * x335) + (x258 * x337);
	const GEN_FLT x339 = (x204 * x283) + (-1 * x203 * x283);
	const GEN_FLT x340 = x194 + (-1 * x289 * x339);
	const GEN_FLT x341 =
		x194 +
		(-1 * x306 *
		 (x339 + (x319 * x340) + (x302 * x338) + (x310 * x335) +
		  (-1 * x300 *
		   ((x318 * x340) +
			(x288 *
			 ((x270 * x335) + (x258 * x338) +
			  (x258 * (x338 + (x258 * (x337 + (x271 * x335) + (x258 * ((-1 * x312 * x335) + x336 + (x274 * x335))))) +
					   (x279 * x335))) +
			  (x269 * x335)))))));
	const GEN_FLT x342 = (x255 * x221) + (-1 * x256 * x220);
	const GEN_FLT x343 = x272 * x342;
	const GEN_FLT x344 = (x277 * x342) + (x258 * (x343 + (-1 * x313 * x342)));
	const GEN_FLT x345 = (x280 * x342) + (x258 * x344);
	const GEN_FLT x346 = (x219 * x290) + (-1 * x283 * x226);
	const GEN_FLT x347 = x228 + (-1 * x289 * x346);
	const GEN_FLT x348 =
		x228 +
		(-1 * x306 *
		 ((x347 * x319) +
		  (-1 * x300 *
		   ((x347 * x318) +
			(x288 * ((x258 * x345) + (x270 * x342) +
					 (x258 * ((x258 * (x344 + (x271 * x342) + (x258 * ((-1 * x312 * x342) + (x274 * x342) + x343)))) +
							  x345 + (x279 * x342))) +
					 (x269 * x342))))) +
		  (x302 * x345) + x346 + (x310 * x342)));
	const GEN_FLT x349 = ((x255 * x242) + (-1 * x256 * x241)) * x268;
	const GEN_FLT x350 = x261 * x349;
	const GEN_FLT x351 = (x262 * x349) + (x258 * (x350 + (-1 * x260 * x349)));
	const GEN_FLT x352 = (x264 * x349) + (x258 * x351);
	const GEN_FLT x353 = (x283 * x245) + (-1 * x283 * x244);
	const GEN_FLT x354 = x247 + (-1 * x289 * x353);
	const GEN_FLT x355 =
		x247 +
		(-1 * x306 *
		 ((x303 * x349) + x353 +
		  (-1 * x300 *
		   ((x354 * x318) +
			(x288 *
			 ((x258 * x352) +
			  (x258 * (x352 + (x258 * (x351 + (x263 * x349) + (x258 * ((-1 * x275 * x349) + x350 + (x259 * x349))))) +
					   (x265 * x349))) +
			  (x266 * x349) + (x267 * x349))))) +
		  (x354 * x319) + (x352 * x302)));
	out[0] = (-1 * x114 * ((-1 * x83) + x113)) + (-1 * x113) + x83;
	out[1] = (-1 * ((-1 * x132) + x136) * x114) + (-1 * x136) + x132;
	out[2] = (-1 * ((-1 * x144) + x153) * x114) + (-1 * x153) + x144;
	out[3] = (-1 * ((-1 * x179) + x181) * x114) + (-1 * x181) + x179;
	out[4] = (-1 * ((-1 * x194) + x207) * x114) + x194 + (-1 * x207);
	out[5] = (-1 * ((-1 * x228) + x230) * x114) + (-1 * x230) + x228;
	out[6] = (-1 * x252) + (-1 * ((-1 * x247) + x252) * x114) + x247;
	out[7] = x307 + (x307 * x308);
	out[8] = x320 + (x308 * x320);
	out[9] = x327 + (x308 * x327);
	out[10] = x334 + (x308 * x334);
	out[11] = x341 + (x308 * x341);
	out[12] = x348 + (x308 * x348);
	out[13] = x355 + (x355 * x308);
}

// Jacobian of reproject_gen2 wrt [sensor_x, sensor_y, sensor_z]
static inline void gen_reproject_gen2_jac_sensor_pt(FLT *out, const SurvivePose *obj_p, const FLT *sensor_pt,
													const SurvivePose *lh_p, const BaseStationCal *bsd) {
	const GEN_FLT obj_px = (*obj_p).Pos[0];
	const GEN_FLT obj_py = (*obj_p).Pos[1];
	const GEN_FLT obj_pz = (*obj_p).Pos[2];
	const GEN_FLT obj_qw = (*obj_p).Rot[0];
	const GEN_FLT obj_qi = (*obj_p).Rot[1];
	const GEN_FLT obj_qj = (*obj_p).Rot[2];
	const GEN_FLT obj_qk = (*obj_p).Rot[3];
	const GEN_FLT sensor_x = sensor_pt[0];
	const GEN_FLT sensor_y = sensor_pt[1];
	const GEN_FLT sensor_z = sensor_pt[2];
	const GEN_FLT lh_px = (*lh_p).Pos[0];
	const GEN_FLT lh_py = (*lh_p).Pos[1];
	const GEN_FLT lh_pz = (*lh_p).Pos[2];
	const GEN_FLT lh_qw = (*lh_p).Rot[0];
	const GEN_FLT lh_qi = (*lh_p).Rot[1];
	const GEN_FLT lh_qj = (*lh_p).Rot[2];
	const GEN_FLT lh_qk = (*lh_p).Rot[3];
	const GEN_FLT phase_0 = bsd[0].phase;
	const GEN_FLT tilt_0 = bsd[0].tilt;
	const GEN_FLT curve_0 = bsd[0].curve;
	const GEN_FLT gibPhase_0 = bsd[0].gibpha;
	const GEN_FLT gibMag_0 = bsd[0].gibmag;
	const GEN_FLT ogeeMag_0 = bsd[0].ogeephase;
	const GEN_FLT ogeePhase_0 = bsd[0].ogeemag;
	const GEN_FLT phase_1 = bsd[1].phase;
	const GEN_FLT tilt_1 = bsd[1].tilt;
	const GEN_FLT curve_1 = bsd[1].curve;
	const GEN_FLT gibPhase_1 = bsd[1].gibpha;
	const GEN_FLT gibMag_1 = bsd[1].gibmag;
	const GEN_FLT ogeeMag_1 = bsd[1].ogeephase;
	const GEN_FLT ogeePhase_1 = bsd[1].ogeemag;
	const GEN_FLT x0 = 0.523598775598299 + tilt_0;
	const GEN_FLT x1 = cos(x0);
	const GEN_FLT x2 = 1. / x1;
	const GEN_FLT x3 = (obj_qw * sensor_x) + (-1 * obj_qk * sensor_y) + (obj_qj * sensor_z);
	const GEN_FLT x4 = (obj_qk * sensor_x) + (-1 * obj_qi * sensor_z) + (obj_qw * sensor_y);
	const GEN_FLT x5 = (2 * ((x4 * obj_qi) + (-1 * x3 * obj_qj))) + obj_pz + sensor_z;
	const GEN_FLT x6 = (-1 * obj_qj * sensor_x) + (obj_qw * sensor_z) + (obj_qi * sensor_y);
	const GEN_FLT x7 = obj_py + (2 * ((x3 * obj_qk) + (-1 * x6 * obj_qi))) + sensor_y;
	const GEN_FLT x8 = obj_px + (2 * ((x6 * obj_qj) + (-1 * x4 * obj_qk))) + sensor_x;
	const GEN_FLT x9 = (-1 * x8 * lh_qj) + (x5 * lh_qw) + (x7 * lh_qi);
	const GEN_FLT x10 = (-1 * x7 * lh_qk) + (x8 * lh_qw) + (x5 * lh_qj);
	const GEN_FLT x11 = x7 + lh_py + (2 * ((x10 * lh_qk) + (-1 * x9 * lh_qi)));
	const GEN_FLT x12 = x11 * x11;
	const GEN_FLT x13 = (-1 * x5 * lh_qi) + (x7 * lh_qw) + (x8 * lh_qk);
	const GEN_FLT x14 = x5 + lh_pz + (2 * ((x13 * lh_qi) + (-1 * x10 * lh_qj)));
	const GEN_FLT x15 = x8 + lh_px + (2 * ((x9 * lh_qj) + (-1 * x13 * lh_qk)));
	const GEN_FLT x16 = x15 * x15;
	const GEN_FLT x17 = x16 + (x14 * x14);
	const GEN_FLT x18 = x17 + x12;
	const GEN_FLT x19 = 1. / sqrt(x18);
	const GEN_FLT x20 = x11 * x19;
	const GEN_FLT x21 = asin(x2 * x20);
	const GEN_FLT x22 = 8.0108022e-06 * x21;
	const GEN_FLT x23 = -8.0108022e-06 + (-1 * x22);
	const GEN_FLT x24 = 0.0028679863 + (x23 * x21);
	const GEN_FLT x25 = 5.3685255e-06 + (x24 * x21);
	const GEN_FLT x26 = 0.0076069798 + (x25 * x21);
	const GEN_FLT x27 = x21 * x26;
	const GEN_FLT x28 = -8.0108022e-06 + (-1.60216044e-05 * x21);
	const GEN_FLT x29 = x24 + (x21 * x28);
	const GEN_FLT x30 = x25 + (x21 * x29);
	const GEN_FLT x31 = x26 + (x30 * x21);
	const GEN_FLT x32 = (x31 * x21) + x27;
	const GEN_FLT x33 = sin(x0);
	const GEN_FLT x34 = atan2(-1 * x14, x15);
	const GEN_FLT x35 = tan(x0);
	const GEN_FLT x36 = 1. / sqrt(x17);
	const GEN_FLT x37 = x36 * x11;
	const GEN_FLT x38 = x35 * x37;
	const GEN_FLT x39 = (-1 * asin(x38)) + ogeeMag_0 + x34;
	const GEN_FLT x40 = (sin(x39) * ogeePhase_0) + curve_0;
	const GEN_FLT x41 = x40 * x33;
	const GEN_FLT x42 = x1 + (-1 * x41 * x32);
	const GEN_FLT x43 = 1. / x42;
	const GEN_FLT x44 = x21 * x21;
	const GEN_FLT x45 = x40 * x44;
	const GEN_FLT x46 = x43 * x45;
	const GEN_FLT x47 = x38 + (x46 * x26);
	const GEN_FLT x48 = 1. / sqrt(1 + (-1 * (x47 * x47)));
	const GEN_FLT x49 = x12 * (1. / x18);
	const GEN_FLT x50 = 1. / sqrt(1 + (-1 * (1. / (x1 * x1)) * x49));
	const GEN_FLT x51 = -2 * (obj_qk * obj_qk);
	const GEN_FLT x52 = 1 + (-2 * (obj_qj * obj_qj));
	const GEN_FLT x53 = x52 + x51;
	const GEN_FLT x54 = 2 * obj_qj;
	const GEN_FLT x55 = x54 * obj_qi;
	const GEN_FLT x56 = 2 * obj_qk;
	const GEN_FLT x57 = x56 * obj_qw;
	const GEN_FLT x58 = x57 + x55;
	const GEN_FLT x59 = x54 * obj_qw;
	const GEN_FLT x60 = x56 * obj_qi;
	const GEN_FLT x61 = x60 + (-1 * x59);
	const GEN_FLT x62 = (x61 * lh_qj) + (x53 * lh_qw) + (-1 * x58 * lh_qk);
	const GEN_FLT x63 = 2 * lh_qk;
	const GEN_FLT x64 = (x58 * lh_qi) + (-1 * x53 * lh_qj) + (x61 * lh_qw);
	const GEN_FLT x65 = 2 * lh_qi;
	const GEN_FLT x66 = x58 + (x63 * x62) + (-1 * x64 * x65);
	const GEN_FLT x67 = 2 * x11;
	const GEN_FLT x68 = 2 * lh_qj;
	const GEN_FLT x69 = (-1 * x61 * lh_qi) + (x53 * lh_qk) + (x58 * lh_qw);
	const GEN_FLT x70 = x53 + (x64 * x68) + (-1 * x63 * x69);
	const GEN_FLT x71 = 2 * x15;
	const GEN_FLT x72 = x61 + (x65 * x69) + (-1 * x62 * x68);
	const GEN_FLT x73 = 2 * x14;
	const GEN_FLT x74 = (x73 * x72) + (x71 * x70);
	const GEN_FLT x75 = 1.0 / 2.0 * x11;
	const GEN_FLT x76 = x75 * (1. / (x18 * sqrt(x18)));
	const GEN_FLT x77 = x76 * (x74 + (x67 * x66));
	const GEN_FLT x78 = x66 * x19;
	const GEN_FLT x79 = (x2 * x78) + (-1 * x2 * x77);
	const GEN_FLT x80 = x79 * x50;
	const GEN_FLT x81 = x80 * x23;
	const GEN_FLT x82 = 2.40324066e-05 * x21;
	const GEN_FLT x83 = (x80 * x24) + (x21 * (x81 + (-1 * x80 * x22)));
	const GEN_FLT x84 = (x83 * x21) + (x80 * x25);
	const GEN_FLT x85 = x50 * x31;
	const GEN_FLT x86 = x66 * x36;
	const GEN_FLT x87 = x75 * (1. / (x17 * sqrt(x17)));
	const GEN_FLT x88 = x87 * x35;
	const GEN_FLT x89 = (-1 * x88 * x74) + (x86 * x35);
	const GEN_FLT x90 = 1. / x17;
	const GEN_FLT x91 = x90 * x12;
	const GEN_FLT x92 = 1. / sqrt(1 + (-1 * x91 * (x35 * x35)));
	const GEN_FLT x93 = 1. / x15;
	const GEN_FLT x94 = x14 * (1. / x16);
	const GEN_FLT x95 = x90 * x16;
	const GEN_FLT x96 = ((x70 * x94) + (-1 * x72 * x93)) * x95;
	const GEN_FLT x97 = x96 + (-1 * x89 * x92);
	const GEN_FLT x98 = cos(x39) * ogeePhase_0;
	const GEN_FLT x99 = x32 * x33;
	const GEN_FLT x100 = x99 * x98;
	const GEN_FLT x101 = (1. / (x42 * x42)) * x45 * x26;
	const GEN_FLT x102 = 2 * x40 * x43 * x27;
	const GEN_FLT x103 = x43 * x44 * x26;
	const GEN_FLT x104 = x98 * x103;
	const GEN_FLT x105 =
		x48 * ((x84 * x46) + x89 +
			   (-1 * x101 *
				((-1 * x97 * x100) +
				 (-1 * x41 *
				  ((x84 * x21) +
				   (x21 * (x84 + (x80 * x30) +
						   (x21 * (x83 + (x21 * ((-1 * x80 * x82) + x81 + (x80 * x28))) + (x80 * x29))))) +
				   (x80 * x26) + (x85 * x79))))) +
			   (x97 * x104) + (x80 * x102));
	const GEN_FLT x106 = cos((-1 * asin(x47)) + gibPhase_0 + x34) * gibMag_0;
	const GEN_FLT x107 = x56 * obj_qj;
	const GEN_FLT x108 = 2 * obj_qw * obj_qi;
	const GEN_FLT x109 = x108 + x107;
	const GEN_FLT x110 = -2 * (obj_qi * obj_qi);
	const GEN_FLT x111 = 1 + x51 + x110;
	const GEN_FLT x112 = x55 + (-1 * x57);
	const GEN_FLT x113 = (x112 * lh_qk) + (-1 * x109 * lh_qi) + (x111 * lh_qw);
	const GEN_FLT x114 = (x109 * lh_qj) + (x112 * lh_qw) + (-1 * x111 * lh_qk);
	const GEN_FLT x115 = x109 + (x65 * x113) + (-1 * x68 * x114);
	const GEN_FLT x116 = (x111 * lh_qi) + (-1 * x112 * lh_qj) + (x109 * lh_qw);
	const GEN_FLT x117 = x112 + (x68 * x116) + (-1 * x63 * x113);
	const GEN_FLT x118 = ((x94 * x117) + (-1 * x93 * x115)) * x95;
	const GEN_FLT x119 = x111 + (x63 * x114) + (-1 * x65 * x116);
	const GEN_FLT x120 = x36 * x119;
	const GEN_FLT x121 = (x73 * x115) + (x71 * x117);
	const GEN_FLT x122 = (-1 * x88 * x121) + (x35 * x120);
	const GEN_FLT x123 = x98 * (x118 + (-1 * x92 * x122));
	const GEN_FLT x124 = x76 * (x121 + (x67 * x119));
	const GEN_FLT x125 = x19 * x119;
	const GEN_FLT x126 = (x2 * x125) + (-1 * x2 * x124);
	const GEN_FLT x127 = x50 * x126;
	const GEN_FLT x128 = x23 * x127;
	const GEN_FLT x129 = (x24 * x127) + (x21 * (x128 + (-1 * x22 * x127)));
	const GEN_FLT x130 = (x21 * x129) + (x25 * x127);
	const GEN_FLT x131 =
		x48 * (x122 +
			   (-1 * x101 *
				((-1 * x99 * x123) +
				 (-1 * x41 *
				  ((x26 * x127) +
				   (x21 * (x130 + (x30 * x127) +
						   (x21 * (x129 + (x21 * ((-1 * x82 * x127) + x128 + (x28 * x127))) + (x29 * x127))))) +
				   (x21 * x130) + (x85 * x126))))) +
			   (x103 * x123) + (x102 * x127) + (x46 * x130));
	const GEN_FLT x132 = x107 + (-1 * x108);
	const GEN_FLT x133 = x59 + x60;
	const GEN_FLT x134 = x52 + x110;
	const GEN_FLT x135 = (x134 * lh_qj) + (-1 * x132 * lh_qk) + (x133 * lh_qw);
	const GEN_FLT x136 = (-1 * x133 * lh_qj) + (x132 * lh_qi) + (x134 * lh_qw);
	const GEN_FLT x137 = (x63 * x135) + x132 + (-1 * x65 * x136);
	const GEN_FLT x138 = x36 * x137;
	const GEN_FLT x139 = (x133 * lh_qk) + (-1 * x134 * lh_qi) + (x132 * lh_qw);
	const GEN_FLT x140 = (x68 * x136) + x133 + (-1 * x63 * x139);
	const GEN_FLT x141 = x134 + (x65 * x139) + (-1 * x68 * x135);
	const GEN_FLT x142 = (x73 * x141) + (x71 * x140);
	const GEN_FLT x143 = (-1 * x88 * x142) + (x35 * x138);
	const GEN_FLT x144 = ((x94 * x140) + (-1 * x93 * x141)) * x95;
	const GEN_FLT x145 = x144 + (-1 * x92 * x143);
	const GEN_FLT x146 = x76 * (x142 + (x67 * x137));
	const GEN_FLT x147 = x19 * x137;
	const GEN_FLT x148 = (x2 * x147) + (-1 * x2 * x146);
	const GEN_FLT x149 = x50 * x148;
	const GEN_FLT x150 = x23 * x149;
	const GEN_FLT x151 = (x24 * x149) + (x21 * (x150 + (-1 * x22 * x149)));
	const GEN_FLT x152 = (x21 * x151) + (x25 * x149);
	const GEN_FLT x153 =
		x48 * ((-1 * x101 *
				((-1 * x100 * x145) +
				 (-1 * x41 *
				  ((x21 * x152) + (x26 * x149) + (x85 * x148) +
				   (x21 * ((x30 * x149) + x152 +
						   (x21 * ((x21 * ((-1 * x82 * x149) + x150 + (x28 * x149))) + x151 + (x29 * x149))))))))) +
			   x143 + (x104 * x145) + (x102 * x149) + (x46 * x152));
	const GEN_FLT x154 = 0.523598775598299 + (-1 * tilt_1);
	const GEN_FLT x155 = cos(x154);
	const GEN_FLT x156 = 1. / sqrt(1 + (-1 * x49 * (1. / (x155 * x155))));
	const GEN_FLT x157 = 1. / x155;
	const GEN_FLT x158 = ((x78 * x157) + (-1 * x77 * x157)) * x156;
	const GEN_FLT x159 = tan(x154);
	const GEN_FLT x160 = -1 * x37 * x159;
	const GEN_FLT x161 = (-1 * asin(x160)) + ogeeMag_1 + x34;
	const GEN_FLT x162 = (sin(x161) * ogeePhase_1) + curve_1;
	const GEN_FLT x163 = asin(x20 * x157);
	const GEN_FLT x164 = 8.0108022e-06 * x163;
	const GEN_FLT x165 = -8.0108022e-06 + (-1 * x164);
	const GEN_FLT x166 = 0.0028679863 + (x165 * x163);
	const GEN_FLT x167 = 5.3685255e-06 + (x166 * x163);
	const GEN_FLT x168 = 0.0076069798 + (x167 * x163);
	const GEN_FLT x169 = x168 * x163;
	const GEN_FLT x170 = -8.0108022e-06 + (-1.60216044e-05 * x163);
	const GEN_FLT x171 = x166 + (x163 * x170);
	const GEN_FLT x172 = x167 + (x163 * x171);
	const GEN_FLT x173 = x168 + (x163 * x172);
	const GEN_FLT x174 = (x163 * x173) + x169;
	const GEN_FLT x175 = sin(x154);
	const GEN_FLT x176 = x162 * x175;
	const GEN_FLT x177 = x155 + (x176 * x174);
	const GEN_FLT x178 = 1. / x177;
	const GEN_FLT x179 = 2 * x169 * x162 * x178;
	const GEN_FLT x180 = x165 * x158;
	const GEN_FLT x181 = 2.40324066e-05 * x163;
	const GEN_FLT x182 = (x166 * x158) + (x163 * (x180 + (-1 * x164 * x158)));
	const GEN_FLT x183 = (x167 * x158) + (x163 * x182);
	const GEN_FLT x184 = x87 * x159;
	const GEN_FLT x185 = (x74 * x184) + (-1 * x86 * x159);
	const GEN_FLT x186 = 1. / sqrt(1 + (-1 * x91 * (x159 * x159)));
	const GEN_FLT x187 = x96 + (-1 * x186 * x185);
	const GEN_FLT x188 = cos(x161) * ogeePhase_1;
	const GEN_FLT x189 = x174 * x175;
	const GEN_FLT x190 = x189 * x188;
	const GEN_FLT x191 = x163 * x163;
	const GEN_FLT x192 = x162 * x191;
	const GEN_FLT x193 = x168 * (1. / (x177 * x177)) * x192;
	const GEN_FLT x194 = x178 * x192;
	const GEN_FLT x195 = x168 * x178 * x191;
	const GEN_FLT x196 = x188 * x195;
	const GEN_FLT x197 = x160 + (x168 * x194);
	const GEN_FLT x198 = 1. / sqrt(1 + (-1 * (x197 * x197)));
	const GEN_FLT x199 =
		x96 +
		(-1 * x198 *
		 ((x187 * x196) + x185 + (x183 * x194) + (x179 * x158) +
		  (-1 * x193 *
		   ((x187 * x190) +
			(x176 *
			 ((x163 * x183) + (x173 * x158) + (x168 * x158) +
			  (x163 * (x183 + (x163 * (x182 + (x171 * x158) + (x163 * ((-1 * x181 * x158) + x180 + (x170 * x158))))) +
					   (x172 * x158)))))))));
	const GEN_FLT x200 = cos((-1 * asin(x197)) + gibPhase_1 + x34) * gibMag_1;
	const GEN_FLT x201 = ((x125 * x157) + (-1 * x124 * x157)) * x156;
	const GEN_FLT x202 = x201 * x165;
	const GEN_FLT x203 = (x201 * x166) + (x163 * (x202 + (-1 * x201 * x164)));
	const GEN_FLT x204 = (x201 * x167) + (x203 * x163);
	const GEN_FLT x205 = (x121 * x184) + (-1 * x120 * x159);
	const GEN_FLT x206 = x188 * (x118 + (-1 * x205 * x186));
	const GEN_FLT x207 =
		x118 +
		(-1 * x198 *
		 (x205 + (x206 * x195) + (x204 * x194) + (x201 * x179) +
		  (-1 * x193 *
		   ((x206 * x189) +
			(x176 *
			 ((x204 * x163) + (x201 * x168) + (x201 * x173) +
			  (x163 * (x204 + (x163 * (x203 + (x201 * x171) + (x163 * ((-1 * x201 * x181) + x202 + (x201 * x170))))) +
					   (x201 * x172)))))))));
	const GEN_FLT x208 = ((x147 * x157) + (-1 * x146 * x157)) * x156;
	const GEN_FLT x209 = x208 * x165;
	const GEN_FLT x210 = (x208 * x166) + (x163 * (x209 + (-1 * x208 * x164)));
	const GEN_FLT x211 = (x208 * x167) + (x210 * x163);
	const GEN_FLT x212 = (x184 * x142) + (-1 * x138 * x159);
	const GEN_FLT x213 = x144 + (-1 * x212 * x186);
	const GEN_FLT x214 =
		x144 +
		(-1 * x198 *
		 (x212 +
		  (-1 * x193 *
		   ((x213 * x190) +
			(x176 *
			 ((x211 * x163) + (x208 * x168) +
			  (x163 * (x211 + (x163 * (x210 + (x208 * x171) + (x163 * (x209 + (-1 * x208 * x181) + (x208 * x170))))) +
					   (x208 * x172))) +
			  (x208 * x173))))) +
		  (x208 * x179) + (x213 * x196) + (x211 * x194)));
	out[0] = (-1 * x106 * ((-1 * x96) + x105)) + (-1 * x105) + x96;
	out[1] = x118 + (-1 * ((-1 * x118) + x131) * x106) + (-1 * x131);
	out[2] = (-1 * ((-1 * x144) + x153) * x106) + (-1 * x153) + x144;
	out[3] = x199 + (x200 * x199);
	out[4] = x207 + (x200 * x207);
	out[5] = x214 + (x214 * x200);
}

// Jacobian of reproject_gen2 wrt [lh_px, lh_py, lh_pz, lh_qw, lh_qi, lh_qj, lh_qk]
static inline void gen_reproject_gen2_jac_lh_p(FLT *out, const SurvivePose *obj_p, const FLT *sensor_pt,
											   const SurvivePose *lh_p, const BaseStationCal *bsd) {
	const GEN_FLT obj_px = (*obj_p).Pos[0];
	const GEN_FLT obj_py = (*obj_p).Pos[1];
	const GEN_FLT obj_pz = (*obj_p).Pos[2];
	const GEN_FLT obj_qw = (*obj_p).Rot[0];
	const GEN_FLT obj_qi = (*obj_p).Rot[1];
	const GEN_FLT obj_qj = (*obj_p).Rot[2];
	const GEN_FLT obj_qk = (*obj_p).Rot[3];
	const GEN_FLT sensor_x = sensor_pt[0];
	const GEN_FLT sensor_y = sensor_pt[1];
	const GEN_FLT sensor_z = sensor_pt[2];
	const GEN_FLT lh_px = (*lh_p).Pos[0];
	const GEN_FLT lh_py = (*lh_p).Pos[1];
	const GEN_FLT lh_pz = (*lh_p).Pos[2];
	const GEN_FLT lh_qw = (*lh_p).Rot[0];
	const GEN_FLT lh_qi = (*lh_p).Rot[1];
	const GEN_FLT lh_qj = (*lh_p).Rot[2];
	const GEN_FLT lh_qk = (*lh_p).Rot[3];
	const GEN_FLT phase_0 = bsd[0].phase;
	const GEN_FLT tilt_0 = bsd[0].tilt;
	const GEN_FLT curve_0 = bsd[0].curve;
	const GEN_FLT gibPhase_0 = bsd[0].gibpha;
	const GEN_FLT gibMag_0 = bsd[0].gibmag;
	const GEN_FLT ogeeMag_0 = bsd[0].ogeephase;
	const GEN_FLT ogeePhase_0 = bsd[0].ogeemag;
	const GEN_FLT phase_1 = bsd[1].phase;
	const GEN_FLT tilt_1 = bsd[1].tilt;
	const GEN_FLT curve_1 = bsd[1].curve;
	const GEN_FLT gibPhase_1 = bsd[1].gibpha;
	const GEN_FLT gibMag_1 = bsd[1].gibmag;
	const GEN_FLT ogeeMag_1 = bsd[1].ogeephase;
	const GEN_FLT ogeePhase_1 = bsd[1].ogeemag;
	const GEN_FLT x0 = (obj_qw * sensor_x) + (-1 * obj_qk * sensor_y) + (obj_qj * sensor_z);
	const GEN_FLT x1 = (obj_qk * sensor_x) + (-1 * obj_qi * sensor_z) + (obj_qw * sensor_y);
	const GEN_FLT x2 = 2 * ((x1 * obj_qi) + (-1 * x0 * obj_qj));
	const GEN_FLT x3 = x2 + obj_pz + sensor_z;
	const GEN_FLT x4 = x3 * lh_qw;
	const GEN_FLT x5 = (-1 * obj_qj * sensor_x) + (obj_qw * sensor_z) + (obj_qi * sensor_y);
	const GEN_FLT x6 = 2 * ((x0 * obj_qk) + (-1 * x5 * obj_qi));
	const GEN_FLT x7 = x6 + obj_py + sensor_y;
	const GEN_FLT x8 = x7 * lh_qi;
	const GEN_FLT x9 = 2 * ((x5 * obj_qj) + (-1 * x1 * obj_qk));
	const GEN_FLT x10 = x9 + obj_px + sensor_x;
	const GEN_FLT x11 = x10 * lh_qj;
	const GEN_FLT x12 = (-1 * x11) + x4 + x8;
	const GEN_FLT x13 = x10 * lh_qw;
	const GEN_FLT x14 = x3 * lh_qj;
	const GEN_FLT x15 = x7 * lh_qk;
	const GEN_FLT x16 = (-1 * x15) + x13 + x14;
	const GEN_FLT x17 = x7 + lh_py + (2 * ((x16 * lh_qk) + (-1 * x12 * lh_qi)));
	const GEN_FLT x18 = 0.523598775598299 + tilt_0;
	const GEN_FLT x19 = cos(x18);
	const GEN_FLT x20 = 1. / x19;
	const GEN_FLT x21 = x17 * x17;
	const GEN_FLT x22 = x7 * lh_qw;
	const GEN_FLT x23 = x10 * lh_qk;
	const GEN_FLT x24 = x3 * lh_qi;
	const GEN_FLT x25 = (-1 * x24) + x22 + x23;
	const GEN_FLT x26 = x3 + lh_pz + (2 * ((x25 * lh_qi) + (-1 * x16 * lh_qj)));
	const GEN_FLT x27 = x10 + lh_px + (2 * ((x12 * lh_qj) + (-1 * x25 * lh_qk)));
	const GEN_FLT x28 = x27 * x27;
	const GEN_FLT x29 = x28 + (x26 * x26);
	const GEN_FLT x30 = x29 + x21;
	const GEN_FLT x31 = 1. / sqrt(x30);
	const GEN_FLT x32 = x31 * x20;
	const GEN_FLT x33 = asin(x32 * x17);
	const GEN_FLT x34 = 8.0108022e-06 * x33;
	const GEN_FLT x35 = -8.0108022e-06 + (-1 * x34);
	const GEN_FLT x36 = 0.0028679863 + (x33 * x35);
	const GEN_FLT x37 = 5.3685255e-06 + (x33 * x36);
	const GEN_FLT x38 = 0.0076069798 + (x33 * x37);
	const GEN_FLT x39 = x33 * x38;
	const GEN_FLT x40 = -8.0108022e-06 + (-1.60216044e-05 * x33);
	const GEN_FLT x41 = x36 + (x40 * x33);
	const GEN_FLT x42 = x37 + (x41 * x33);
	const GEN_FLT x43 = x38 + (x42 * x33);
	const GEN_FLT x44 = (x43 * x33) + x39;
	const GEN_FLT x45 = sin(x18);
	const GEN_FLT x46 = atan2(-1 * x26, x27);
	const GEN_FLT x47 = 1. / sqrt(x29);
	const GEN_FLT x48 = tan(x18);
	const GEN_FLT x49 = x47 * x48;
	const GEN_FLT x50 = x49 * x17;
	const GEN_FLT x51 = (-1 * asin(x50)) + ogeeMag_0 + x46;
	const GEN_FLT x52 = (sin(x51) * ogeePhase_0) + curve_0;
	const GEN_FLT x53 = x52 * x45;
	const GEN_FLT x54 = x19 + (-1 * x53 * x44);
	const GEN_FLT x55 = 1. / x54;
	const GEN_FLT x56 = x33 * x33;
	const GEN_FLT x57 = x52 * x56;
	const GEN_FLT x58 = x57 * x55;
	const GEN_FLT x59 = x50 + (x58 * x38);
	const GEN_FLT x60 = 1. / sqrt(1 + (-1 * (x59 * x59)));
	const GEN_FLT x61 = (1. / (x29 * sqrt(x29))) * x17;
	const GEN_FLT x62 = x61 * x27;
	const GEN_FLT x63 = x62 * x48;
	const GEN_FLT x64 = 1. / (x30 * sqrt(x30));
	const GEN_FLT x65 = x64 * x17;
	const GEN_FLT x66 = x65 * x27;
	const GEN_FLT x67 = (1. / x30) * x21;
	const GEN_FLT x68 = 1. / sqrt(1 + (-1 * x67 * (1. / (x19 * x19))));
	const GEN_FLT x69 = x68 * x20;
	const GEN_FLT x70 = x66 * x69;
	const GEN_FLT x71 = -1 * x70 * x35;
	const GEN_FLT x72 = 2.40324066e-05 * x33;
	const GEN_FLT x73 = (-1 * x70 * x36) + (x33 * (x71 + (x70 * x34)));
	const GEN_FLT x74 = (x73 * x33) + (-1 * x70 * x37);
	const GEN_FLT x75 = 1. / x29;
	const GEN_FLT x76 = x75 * x21;
	const GEN_FLT x77 = 1. / sqrt(1 + (-1 * x76 * (x48 * x48)));
	const GEN_FLT x78 = x75 * x26;
	const GEN_FLT x79 = x78 + (x77 * x63);
	const GEN_FLT x80 = cos(x51) * ogeePhase_0;
	const GEN_FLT x81 = x44 * x45;
	const GEN_FLT x82 = x80 * x81;
	const GEN_FLT x83 = (1. / (x54 * x54)) * x57 * x38;
	const GEN_FLT x84 = x56 * x55 * x38;
	const GEN_FLT x85 = x80 * x84;
	const GEN_FLT x86 = 2 * x17;
	const GEN_FLT x87 = x86 * x64 * x27;
	const GEN_FLT x88 = x52 * x55 * x39;
	const GEN_FLT x89 = x88 * x69;
	const GEN_FLT x90 =
		x60 * ((x85 * x79) + (x74 * x58) + (-1 * x63) + (-1 * x89 * x87) +
			   (-1 * x83 *
				((-1 * x82 * x79) +
				 (-1 * x53 *
				  ((-1 * x70 * x38) +
				   (x33 * (x74 + (-1 * x70 * x42) +
						   (x33 * (x73 + (x33 * ((x70 * x72) + x71 + (-1 * x70 * x40))) + (-1 * x70 * x41))))) +
				   (x74 * x33) + (-1 * x70 * x43))))));
	const GEN_FLT x91 = cos((-1 * asin(x59)) + gibPhase_0 + x46) * gibMag_0;
	const GEN_FLT x92 = x64 * x21;
	const GEN_FLT x93 = x68 * (x32 + (-1 * x92 * x20));
	const GEN_FLT x94 = x93 * x35;
	const GEN_FLT x95 = (x93 * x36) + (x33 * (x94 + (-1 * x93 * x34)));
	const GEN_FLT x96 = (x95 * x33) + (x93 * x37);
	const GEN_FLT x97 = x77 * x49;
	const GEN_FLT x98 = 2 * x88;
	const GEN_FLT x99 =
		x60 *
		((x93 * x98) +
		 (-1 * x83 *
		  ((x82 * x97) + (-1 * x53 *
						  ((x96 * x33) + (x93 * x38) + (x93 * x43) +
						   (x33 * (x96 + (x93 * x42) +
								   (x33 * (x95 + (x33 * ((-1 * x72 * x93) + x94 + (x93 * x40))) + (x93 * x41))))))))) +
		 (-1 * x85 * x97) + x49 + (x58 * x96));
	const GEN_FLT x100 = x65 * x26;
	const GEN_FLT x101 = x69 * x100;
	const GEN_FLT x102 = -1 * x35 * x101;
	const GEN_FLT x103 = (-1 * x36 * x101) + (x33 * (x102 + (x34 * x101)));
	const GEN_FLT x104 = (x33 * x103) + (-1 * x37 * x101);
	const GEN_FLT x105 = 2 * x26;
	const GEN_FLT x106 = x65 * x105;
	const GEN_FLT x107 = x61 * x26;
	const GEN_FLT x108 = x48 * x107;
	const GEN_FLT x109 = x75 * x27;
	const GEN_FLT x110 = -1 * x109;
	const GEN_FLT x111 = x80 * (x110 + (x77 * x108));
	const GEN_FLT x112 =
		x60 *
		((-1 * x83 *
		  ((-1 * x81 * x111) +
		   (-1 * x53 *
			((-1 * x38 * x101) + (-1 * x43 * x101) + (x33 * x104) +
			 (x33 * (x104 + (-1 * x42 * x101) +
					 (x33 * (x103 + (x33 * ((x72 * x101) + x102 + (-1 * x40 * x101))) + (-1 * x41 * x101))))))))) +
		 (x84 * x111) + (x58 * x104) + (-1 * x108) + (-1 * x89 * x106));
	const GEN_FLT x113 = 2 * x24;
	const GEN_FLT x114 = (2 * x23) + (-1 * x113);
	const GEN_FLT x115 = 2 * x15;
	const GEN_FLT x116 = (2 * x14) + (-1 * x115);
	const GEN_FLT x117 = 2 * x27;
	const GEN_FLT x118 = 2 * x11;
	const GEN_FLT x119 = (2 * x8) + (-1 * x118);
	const GEN_FLT x120 = (x105 * x119) + (x116 * x117);
	const GEN_FLT x121 = x120 + (x86 * x114);
	const GEN_FLT x122 = 1.0 / 2.0 * x65;
	const GEN_FLT x123 = x20 * x122;
	const GEN_FLT x124 = x68 * ((x32 * x114) + (-1 * x123 * x121));
	const GEN_FLT x125 = 1.0 / 2.0 * x61;
	const GEN_FLT x126 = x48 * x125;
	const GEN_FLT x127 = (-1 * x120 * x126) + (x49 * x114);
	const GEN_FLT x128 = 1. / x27;
	const GEN_FLT x129 = (1. / x28) * x26;
	const GEN_FLT x130 = x75 * x28;
	const GEN_FLT x131 = ((x116 * x129) + (-1 * x119 * x128)) * x130;
	const GEN_FLT x132 = x131 + (-1 * x77 * x127);
	const GEN_FLT x133 = x35 * x124;
	const GEN_FLT x134 = (x36 * x124) + (x33 * (x133 + (-1 * x34 * x124)));
	const GEN_FLT x135 = (x33 * x134) + (x37 * x124);
	const GEN_FLT x136 =
		x60 * (x127 +
			   (-1 * x83 *
				((-1 * x82 * x132) +
				 (-1 * x53 *
				  ((x38 * x124) + (x33 * x135) + (x43 * x124) +
				   (x33 * (x135 + (x42 * x124) +
						   (x33 * ((x33 * ((-1 * x72 * x124) + x133 + (x40 * x124))) + x134 + (x41 * x124))))))))) +
			   (x58 * x135) + (x98 * x124) + (x85 * x132));
	const GEN_FLT x137 = 2 * x4;
	const GEN_FLT x138 = (-4 * x8) + x118 + (-1 * x137);
	const GEN_FLT x139 = (-1 * obj_pz) + (-1 * sensor_z) + (-1 * x2);
	const GEN_FLT x140 = 2 * lh_qk;
	const GEN_FLT x141 = 2 * lh_qj;
	const GEN_FLT x142 = (x7 * x141) + (-1 * x139 * x140);
	const GEN_FLT x143 = 2 * x22;
	const GEN_FLT x144 = 2 * lh_qi;
	const GEN_FLT x145 = x114 + x143 + (x139 * x144);
	const GEN_FLT x146 = (x105 * x145) + (x117 * x142);
	const GEN_FLT x147 = (-1 * x126 * x146) + (x49 * x138);
	const GEN_FLT x148 = ((x129 * x142) + (-1 * x128 * x145)) * x130;
	const GEN_FLT x149 = x148 + (-1 * x77 * x147);
	const GEN_FLT x150 = x146 + (x86 * x138);
	const GEN_FLT x151 = x68 * ((x32 * x138) + (-1 * x123 * x150));
	const GEN_FLT x152 = x35 * x151;
	const GEN_FLT x153 = (x36 * x151) + (x33 * (x152 + (-1 * x34 * x151)));
	const GEN_FLT x154 = (x33 * x153) + (x37 * x151);
	const GEN_FLT x155 =
		x60 * ((x58 * x154) + x147 + (x85 * x149) +
			   (-1 * x83 *
				((-1 * x82 * x149) +
				 (-1 * x53 *
				  ((x33 * x154) + (x38 * x151) + (x43 * x151) +
				   (x33 * (x154 + (x42 * x151) +
						   (x33 * (x153 + (x33 * ((-1 * x72 * x151) + x152 + (x40 * x151))) + (x41 * x151))))))))) +
			   (x98 * x151));
	const GEN_FLT x156 = 2 * x13;
	const GEN_FLT x157 = (-4 * x14) + (-1 * x156) + x115;
	const GEN_FLT x158 = (-1 * sensor_x) + (-1 * obj_px) + (-1 * x9);
	const GEN_FLT x159 = x119 + (x141 * x158) + x137;
	const GEN_FLT x160 = ((x129 * x159) + (-1 * x128 * x157)) * x130;
	const GEN_FLT x161 = (x3 * x140) + (-1 * x144 * x158);
	const GEN_FLT x162 = (x105 * x157) + (x117 * x159);
	const GEN_FLT x163 = x122 * (x162 + (x86 * x161));
	const GEN_FLT x164 = ((x32 * x161) + (-1 * x20 * x163)) * x68;
	const GEN_FLT x165 = x35 * x164;
	const GEN_FLT x166 = (x36 * x164) + (x33 * (x165 + (-1 * x34 * x164)));
	const GEN_FLT x167 = (x33 * x166) + (x37 * x164);
	const GEN_FLT x168 = (-1 * x126 * x162) + (x49 * x161);
	const GEN_FLT x169 = x160 + (-1 * x77 * x168);
	const GEN_FLT x170 =
		x60 * ((x85 * x169) + (x58 * x167) + x168 +
			   (-1 * x83 *
				((-1 * x82 * x169) +
				 (-1 * x53 *
				  ((x33 * x167) + (x43 * x164) +
				   (x33 * ((x42 * x164) + x167 +
						   (x33 * (x166 + (x33 * ((-1 * x72 * x164) + x165 + (x40 * x164))) + (x41 * x164))))) +
				   (x38 * x164))))) +
			   (x98 * x164));
	const GEN_FLT x171 = (-1 * obj_py) + (-1 * sensor_y) + (-1 * x6);
	const GEN_FLT x172 = (x10 * x144) + (-1 * x171 * x141);
	const GEN_FLT x173 = (-4 * x23) + (-1 * x143) + x113;
	const GEN_FLT x174 = ((x129 * x173) + (-1 * x128 * x172)) * x130;
	const GEN_FLT x175 = x116 + x156 + (x171 * x140);
	const GEN_FLT x176 = (x105 * x172) + (x117 * x173);
	const GEN_FLT x177 = x176 + (x86 * x175);
	const GEN_FLT x178 = x68 * ((x32 * x175) + (-1 * x123 * x177));
	const GEN_FLT x179 = (-1 * x126 * x176) + (x49 * x175);
	const GEN_FLT x180 = x174 + (-1 * x77 * x179);
	const GEN_FLT x181 = x35 * x178;
	const GEN_FLT x182 = (x36 * x178) + (x33 * (x181 + (-1 * x34 * x178)));
	const GEN_FLT x183 = (x33 * x182) + (x37 * x178);
	const GEN_FLT x184 =
		x60 * (x179 + (x58 * x183) +
			   (-1 * x83 *
				((-1 * x82 * x180) +
				 (-1 * x53 *
				  ((x38 * x178) + (x33 * x183) +
				   (x33 * (x183 + (x42 * x178) +
						   (x33 * (x182 + (x33 * ((-1 * x72 * x178) + x181 + (x40 * x178))) + (x41 * x178))))) +
				   (x43 * x178))))) +
			   (x98 * x178) + (x85 * x180));
	const GEN_FLT x185 = 0.523598775598299 + (-1 * tilt_1);
	const GEN_FLT x186 = tan(x185);
	const GEN_FLT x187 = 1. / sqrt(1 + (-1 * x76 * (x186 * x186)));
	const GEN_FLT x188 = x62 * x186;
	const GEN_FLT x189 = x78 + (-1 * x187 * x188);
	const GEN_FLT x190 = x47 * x186;
	const GEN_FLT x191 = -1 * x17 * x190;
	const GEN_FLT x192 = (-1 * asin(x191)) + ogeeMag_1 + x46;
	const GEN_FLT x193 = cos(x192) * ogeePhase_1;
	const GEN_FLT x194 = cos(x185);
	const GEN_FLT x195 = 1. / x194;
	const GEN_FLT x196 = x31 * x195;
	const GEN_FLT x197 = asin(x17 * x196);
	const GEN_FLT x198 = 8.0108022e-06 * x197;
	const GEN_FLT x199 = -8.0108022e-06 + (-1 * x198);
	const GEN_FLT x200 = 0.0028679863 + (x197 * x199);
	const GEN_FLT x201 = 5.3685255e-06 + (x200 * x197);
	const GEN_FLT x202 = 0.0076069798 + (x201 * x197);
	const GEN_FLT x203 = x197 * x197;
	const GEN_FLT x204 = x202 * x197;
	const GEN_FLT x205 = -8.0108022e-06 + (-1.60216044e-05 * x197);
	const GEN_FLT x206 = x200 + (x205 * x197);
	const GEN_FLT x207 = x201 + (x206 * x197);
	const GEN_FLT x208 = x202 + (x207 * x197);
	const GEN_FLT x209 = (x208 * x197) + x204;
	const GEN_FLT x210 = sin(x185);
	const GEN_FLT x211 = (sin(x192) * ogeePhase_1) + curve_1;
	const GEN_FLT x212 = x211 * x210;
	const GEN_FLT x213 = x194 + (x212 * x209);
	const GEN_FLT x214 = 1. / x213;
	const GEN_FLT x215 = x214 * x202 * x203;
	const GEN_FLT x216 = x215 * x193;
	const GEN_FLT x217 = 1. / sqrt(1 + (-1 * x67 * (1. / (x194 * x194))));
	const GEN_FLT x218 = x217 * x195;
	const GEN_FLT x219 = x66 * x218;
	const GEN_FLT x220 = -1 * x219 * x199;
	const GEN_FLT x221 = 2.40324066e-05 * x197;
	const GEN_FLT x222 = (-1 * x219 * x200) + (x197 * (x220 + (x219 * x198)));
	const GEN_FLT x223 = (-1 * x219 * x201) + (x222 * x197);
	const GEN_FLT x224 = x210 * x209;
	const GEN_FLT x225 = x224 * x193;
	const GEN_FLT x226 = x211 * x203;
	const GEN_FLT x227 = (1. / (x213 * x213)) * x202 * x226;
	const GEN_FLT x228 = x214 * x226;
	const GEN_FLT x229 = x211 * x214 * x204;
	const GEN_FLT x230 = x218 * x229;
	const GEN_FLT x231 = x191 + (x202 * x228);
	const GEN_FLT x232 = 1. / sqrt(1 + (-1 * (x231 * x231)));
	const GEN_FLT x233 =
		x78 + (-1 * x232 *
			   ((x223 * x228) +
				(-1 * x227 *
				 ((x225 * x189) + (x212 * ((-1 * x219 * x202) + (x223 * x197) +
										   (x197 * (x223 +
													(x197 * (x222 + (-1 * x219 * x206) +
															 (x197 * ((x219 * x221) + (-1 * x219 * x205) + x220)))) +
													(-1 * x219 * x207))) +
										   (-1 * x219 * x208))))) +
				(-1 * x87 * x230) + (x216 * x189) + x188));
	const GEN_FLT x234 = cos((-1 * asin(x231)) + gibPhase_1 + x46) * gibMag_1;
	const GEN_FLT x235 = x187 * x190;
	const GEN_FLT x236 = x217 * (x196 + (-1 * x92 * x195));
	const GEN_FLT x237 = x236 * x199;
	const GEN_FLT x238 = (x236 * x200) + (x197 * (x237 + (-1 * x236 * x198)));
	const GEN_FLT x239 = (x236 * x201) + (x238 * x197);
	const GEN_FLT x240 = 2 * x229;
	const GEN_FLT x241 =
		x232 *
		((x236 * x240) +
		 (-1 * x227 *
		  ((x235 * x225) +
		   (x212 *
			((x236 * x202) + (x239 * x197) +
			 (x197 * (x239 + (x197 * (x238 + (x236 * x206) + (x197 * ((-1 * x236 * x221) + x237 + (x236 * x205))))) +
					  (x236 * x207))) +
			 (x236 * x208))))) +
		 (-1 * x190) + (x239 * x228) + (x216 * x235));
	const GEN_FLT x242 = x107 * x186;
	const GEN_FLT x243 = x110 + (-1 * x242 * x187);
	const GEN_FLT x244 = x218 * x100;
	const GEN_FLT x245 = -1 * x244 * x199;
	const GEN_FLT x246 = (-1 * x200 * x244) + (x197 * (x245 + (x244 * x198)));
	const GEN_FLT x247 = (-1 * x201 * x244) + (x246 * x197);
	const GEN_FLT x248 =
		x110 + (-1 * x232 *
				((-1 * x227 *
				  ((x225 * x243) + (x212 * ((x247 * x197) + (-1 * x202 * x244) +
											(x197 * (x247 +
													 (x197 * (x246 + (-1 * x206 * x244) +
															  (x197 * ((x221 * x244) + x245 + (-1 * x205 * x244))))) +
													 (-1 * x207 * x244))) +
											(-1 * x208 * x244))))) +
				 (-1 * x230 * x106) + x242 + (x216 * x243) + (x228 * x247)));
	const GEN_FLT x249 = x122 * x195;
	const GEN_FLT x250 = ((x114 * x196) + (-1 * x249 * x121)) * x217;
	const GEN_FLT x251 = x250 * x199;
	const GEN_FLT x252 = (x200 * x250) + (x197 * (x251 + (-1 * x250 * x198)));
	const GEN_FLT x253 = (x201 * x250) + (x252 * x197);
	const GEN_FLT x254 = x125 * x186;
	const GEN_FLT x255 = (x254 * x120) + (-1 * x114 * x190);
	const GEN_FLT x256 = x131 + (-1 * x255 * x187);
	const GEN_FLT x257 =
		x131 +
		(-1 * x232 *
		 ((x216 * x256) + (x253 * x228) + x255 + (x250 * x240) +
		  (-1 * x227 *
		   ((x256 * x225) +
			(x212 *
			 ((x253 * x197) + (x202 * x250) +
			  (x197 * (x253 + (x197 * ((x206 * x250) + x252 + (x197 * (x251 + (-1 * x250 * x221) + (x205 * x250))))) +
					   (x207 * x250))) +
			  (x208 * x250)))))));
	const GEN_FLT x258 = ((x196 * x138) + (-1 * x249 * x150)) * x217;
	const GEN_FLT x259 = x258 * x199;
	const GEN_FLT x260 = (x200 * x258) + (x197 * (x259 + (-1 * x258 * x198)));
	const GEN_FLT x261 = (x201 * x258) + (x260 * x197);
	const GEN_FLT x262 = (x254 * x146) + (-1 * x190 * x138);
	const GEN_FLT x263 = x193 * (x148 + (-1 * x262 * x187));
	const GEN_FLT x264 =
		x148 +
		(-1 * x232 *
		 (x262 + (x215 * x263) + (x261 * x228) +
		  (-1 * x227 *
		   ((x263 * x224) +
			(x212 *
			 ((x261 * x197) + (x202 * x258) +
			  (x197 * (x261 + (x197 * (x260 + (x206 * x258) + (x197 * ((-1 * x258 * x221) + x259 + (x205 * x258))))) +
					   (x207 * x258))) +
			  (x208 * x258))))) +
		  (x258 * x240)));
	const GEN_FLT x265 = ((x161 * x196) + (-1 * x163 * x195)) * x217;
	const GEN_FLT x266 = x265 * x199;
	const GEN_FLT x267 = (x200 * x265) + (x197 * (x266 + (-1 * x265 * x198)));
	const GEN_FLT x268 = (x201 * x265) + (x267 * x197);
	const GEN_FLT x269 = (x254 * x162) + (-1 * x161 * x190);
	const GEN_FLT x270 = x160 + (-1 * x269 * x187);
	const GEN_FLT x271 =
		x160 +
		(-1 * x232 *
		 ((-1 * x227 *
		   ((x270 * x225) +
			(x212 *
			 ((x268 * x197) + (x202 * x265) +
			  (x197 * (x268 + (x197 * (x267 + (x206 * x265) + (x197 * (x266 + (-1 * x265 * x221) + (x205 * x265))))) +
					   (x207 * x265))) +
			  (x208 * x265))))) +
		  x269 + (x265 * x240) + (x216 * x270) + (x268 * x228)));
	const GEN_FLT x272 = ((x175 * x196) + (-1 * x249 * x177)) * x217;
	const GEN_FLT x273 = x272 * x199;
	const GEN_FLT x274 = (x200 * x272) + (x197 * (x273 + (-1 * x272 * x198)));
	const GEN_FLT x275 = (x201 * x272) + (x274 * x197);
	const GEN_FLT x276 = (x254 * x176) + (-1 * x175 * x190);
	const GEN_FLT x277 = x174 + (-1 * x276 * x187);
	const GEN_FLT x278 =
		x174 +
		(-1 * x232 *
		 (x276 + (x216 * x277) + (x275 * x228) + (x272 * x240) +
		  (-1 * x227 *
		   ((x277 * x225) +
			(x212 *
			 ((x275 * x197) + (x202 * x272) +
			  (x197 * (x275 + (x197 * (x274 + (x206 * x272) + (x197 * ((x205 * x272) + (-1 * x272 * x221) + x273)))) +
					   (x207 * x272))) +
			  (x208 * x272)))))));
	out[0] = (-1 * x90) + (-1 * ((-1 * x78) + x90) * x91) + x78;
	out[1] = (-1 * x91 * x99) + (-1 * x99);
	out[2] = (-1 * (x109 + x112) * x91) + (-1 * x112) + x110;
	out[3] = (-1 * ((-1 * x131) + x136) * x91) + (-1 * x136) + x131;
	out[4] = (-1 * ((-1 * x148) + x155) * x91) + (-1 * x155) + x148;
	out[5] = (-1 * ((-1 * x160) + x170) * x91) + x160 + (-1 * x170);
	out[6] = (-1 * ((-1 * x174) + x184) * x91) + x174 + (-1 * x184);
	out[7] = x233 + (x234 * x233);
	out[8] = (-1 * x234 * x241) + (-1 * x241);
	out[9] = x248 + (x234 * x248);
	out[10] = x257 + (x234 * x257);
	out[11] = x264 + (x234 * x264);
	out[12] = x271 + (x234 * x271);
	out[13] = x278 + (x234 * x278);
}

// Jacobian of reproject_gen2 wrt [phase_0, tilt_0, curve_0, gibPhase_0, gibMag_0, ogeeMag_0, ogeePhase_0, phase_1,
// tilt_1, curve_1, gibPhase_1, gibMag_1, ogeeMag_1, ogeePhase_1]
static inline void gen_reproject_gen2_jac_bsd(FLT *out, const SurvivePose *obj_p, const FLT *sensor_pt,
											  const SurvivePose *lh_p, const BaseStationCal *bsd) {
	const GEN_FLT obj_px = (*obj_p).Pos[0];
	const GEN_FLT obj_py = (*obj_p).Pos[1];
	const GEN_FLT obj_pz = (*obj_p).Pos[2];
	const GEN_FLT obj_qw = (*obj_p).Rot[0];
	const GEN_FLT obj_qi = (*obj_p).Rot[1];
	const GEN_FLT obj_qj = (*obj_p).Rot[2];
	const GEN_FLT obj_qk = (*obj_p).Rot[3];
	const GEN_FLT sensor_x = sensor_pt[0];
	const GEN_FLT sensor_y = sensor_pt[1];
	const GEN_FLT sensor_z = sensor_pt[2];
	const GEN_FLT lh_px = (*lh_p).Pos[0];
	const GEN_FLT lh_py = (*lh_p).Pos[1];
	const GEN_FLT lh_pz = (*lh_p).Pos[2];
	const GEN_FLT lh_qw = (*lh_p).Rot[0];
	const GEN_FLT lh_qi = (*lh_p).Rot[1];
	const GEN_FLT lh_qj = (*lh_p).Rot[2];
	const GEN_FLT lh_qk = (*lh_p).Rot[3];
	const GEN_FLT phase_0 = bsd[0].phase;
	const GEN_FLT tilt_0 = bsd[0].tilt;
	const GEN_FLT curve_0 = bsd[0].curve;
	const GEN_FLT gibPhase_0 = bsd[0].gibpha;
	const GEN_FLT gibMag_0 = bsd[0].gibmag;
	const GEN_FLT ogeeMag_0 = bsd[0].ogeephase;
	const GEN_FLT ogeePhase_0 = bsd[0].ogeemag;
	const GEN_FLT phase_1 = bsd[1].phase;
	const GEN_FLT tilt_1 = bsd[1].tilt;
	const GEN_FLT curve_1 = bsd[1].curve;
	const GEN_FLT gibPhase_1 = bsd[1].gibpha;
	const GEN_FLT gibMag_1 = bsd[1].gibmag;
	const GEN_FLT ogeeMag_1 = bsd[1].ogeephase;
	const GEN_FLT ogeePhase_1 = bsd[1].ogeemag;
	const GEN_FLT x0 = (obj_qk * sensor_x) + (-1 * obj_qi * sensor_z) + (obj_qw * sensor_y);
	const GEN_FLT x1 = (-1 * obj_qj * sensor_x) + (obj_qw * sensor_z) + (obj_qi * sensor_y);
	const GEN_FLT x2 = (2 * ((x1 * obj_qj) + (-1 * x0 * obj_qk))) + obj_px + sensor_x;
	const GEN_FLT x3 = (obj_qw * sensor_x) + (-1 * obj_qk * sensor_y) + (obj_qj * sensor_z);
	const GEN_FLT x4 = (2 * ((x0 * obj_qi) + (-1 * x3 * obj_qj))) + obj_pz + sensor_z;
	const GEN_FLT x5 = obj_py + (2 * ((x3 * obj_qk) + (-1 * x1 * obj_qi))) + sensor_y;
	const GEN_FLT x6 = (-1 * x5 * lh_qk) + (x2 * lh_qw) + (x4 * lh_qj);
	const GEN_FLT x7 = (x5 * lh_qw) + (-1 * x4 * lh_qi) + (x2 * lh_qk);
	const GEN_FLT x8 = x4 + lh_pz + (2 * ((x7 * lh_qi) + (-1 * x6 * lh_qj)));
	const GEN_FLT x9 = (x4 * lh_qw) + (-1 * x2 * lh_qj) + (x5 * lh_qi);
	const GEN_FLT x10 = lh_px + x2 + (2 * ((x9 * lh_qj) + (-1 * x7 * lh_qk)));
	const GEN_FLT x11 = atan2(-1 * x8, x10);
	const GEN_FLT x12 = 0.523598775598299 + tilt_0;
	const GEN_FLT x13 = tan(x12);
	const GEN_FLT x14 = x5 + lh_py + (2 * ((x6 * lh_qk) + (-1 * x9 * lh_qi)));
	const GEN_FLT x15 = (x10 * x10) + (x8 * x8);
	const GEN_FLT x16 = (1. / sqrt(x15)) * x14;
	const GEN_FLT x17 = x13 * x16;
	const GEN_FLT x18 = (-1 * asin(x17)) + ogeeMag_0 + x11;
	const GEN_FLT x19 = sin(x18);
	const GEN_FLT x20 = (x19 * ogeePhase_0) + curve_0;
	const GEN_FLT x21 = cos(x12);
	const GEN_FLT x22 = x14 * x14;
	const GEN_FLT x23 = x15 + x22;
	const GEN_FLT x24 = (1. / sqrt(x23)) * x14;
	const GEN_FLT x25 = asin(x24 * (1. / x21));
	const GEN_FLT x26 = 8.0108022e-06 * x25;
	const GEN_FLT x27 = -8.0108022e-06 + (-1 * x26);
	const GEN_FLT x28 = 0.0028679863 + (x25 * x27);
	const GEN_FLT x29 = 5.3685255e-06 + (x25 * x28);
	const GEN_FLT x30 = 0.0076069798 + (x25 * x29);
	const GEN_FLT x31 = x30 * x25;
	const GEN_FLT x32 = -8.0108022e-06 + (-1.60216044e-05 * x25);
	const GEN_FLT x33 = x28 + (x32 * x25);
	const GEN_FLT x34 = x29 + (x33 * x25);
	const GEN_FLT x35 = x30 + (x34 * x25);
	const GEN_FLT x36 = (x35 * x25) + x31;
	const GEN_FLT x37 = sin(x12);
	const GEN_FLT x38 = x37 * x20;
	const GEN_FLT x39 = x36 * x38;
	const GEN_FLT x40 = x21 + (-1 * x39);
	const GEN_FLT x41 = 1. / x40;
	const GEN_FLT x42 = x25 * x25;
	const GEN_FLT x43 = x41 * x42;
	const GEN_FLT x44 = x43 * x30;
	const GEN_FLT x45 = x17 + (x44 * x20);
	const GEN_FLT x46 = 1. / sqrt(1 + (-1 * (x45 * x45)));
	const GEN_FLT x47 = x13 * x13;
	const GEN_FLT x48 = x16 * (1 + x47);
	const GEN_FLT x49 = 1. / (x21 * x21);
	const GEN_FLT x50 = x22 * (1. / x23);
	const GEN_FLT x51 = x49 * x24 * (1. / sqrt(1 + (-1 * x50 * x49)));
	const GEN_FLT x52 = x51 * x37;
	const GEN_FLT x53 = x52 * x27;
	const GEN_FLT x54 = (x52 * x28) + (x25 * (x53 + (-1 * x52 * x26)));
	const GEN_FLT x55 = (x54 * x25) + (x52 * x29);
	const GEN_FLT x56 = cos(x18) * ogeePhase_0;
	const GEN_FLT x57 = x22 * (1. / x15);
	const GEN_FLT x58 = x48 * (1. / sqrt(1 + (-1 * x57 * x47)));
	const GEN_FLT x59 = (1. / (x40 * x40)) * x42 * x30;
	const GEN_FLT x60 = x56 * x44;
	const GEN_FLT x61 =
		x46 * ((-1 * x60 * x58) + (x55 * x43 * x20) + (2 * x51 * x41 * x31 * x38) + x48 +
			   (-1 * x59 * x20 *
				((x58 * x56 * x36 * x37) +
				 (-1 * x38 *
				  ((x25 * (x55 + (x52 * x34) +
						   (x25 * (x54 + (x25 * ((-2.40324066e-05 * x52 * x25) + x53 + (x52 * x32))) + (x52 * x33))))) +
				   (x52 * x35) + (x55 * x25) + (x52 * x30))) +
				 (-1 * x37) + (-1 * x36 * x20 * x21))));
	const GEN_FLT x62 = asin(x45) + (-1 * gibPhase_0) + (-1 * x11);
	const GEN_FLT x63 = cos(x62) * gibMag_0;
	const GEN_FLT x64 = x59 * x39;
	const GEN_FLT x65 = (x64 + x44) * x46;
	const GEN_FLT x66 = x46 * ((x64 * x56) + x60);
	const GEN_FLT x67 = ((x64 * x19) + (x44 * x19)) * x46;
	const GEN_FLT x68 = 0.523598775598299 + (-1 * tilt_1);
	const GEN_FLT x69 = cos(x68);
	const GEN_FLT x70 = asin((1. / x69) * x24);
	const GEN_FLT x71 = 8.0108022e-06 * x70;
	const GEN_FLT x72 = -8.0108022e-06 + (-1 * x71);
	const GEN_FLT x73 = 0.0028679863 + (x70 * x72);
	const GEN_FLT x74 = 5.3685255e-06 + (x70 * x73);
	const GEN_FLT x75 = 0.0076069798 + (x70 * x74);
	const GEN_FLT x76 = x70 * x70;
	const GEN_FLT x77 = sin(x68);
	const GEN_FLT x78 = x70 * x75;
	const GEN_FLT x79 = -8.0108022e-06 + (-1.60216044e-05 * x70);
	const GEN_FLT x80 = x73 + (x70 * x79);
	const GEN_FLT x81 = x74 + (x80 * x70);
	const GEN_FLT x82 = x75 + (x81 * x70);
	const GEN_FLT x83 = (x82 * x70) + x78;
	const GEN_FLT x84 = tan(x68);
	const GEN_FLT x85 = -1 * x84 * x16;
	const GEN_FLT x86 = (-1 * asin(x85)) + ogeeMag_1 + x11;
	const GEN_FLT x87 = sin(x86);
	const GEN_FLT x88 = (x87 * ogeePhase_1) + curve_1;
	const GEN_FLT x89 = x83 * x88;
	const GEN_FLT x90 = x89 * x77;
	const GEN_FLT x91 = x69 + x90;
	const GEN_FLT x92 = 1. / x91;
	const GEN_FLT x93 = x76 * x92;
	const GEN_FLT x94 = x75 * x93;
	const GEN_FLT x95 = cos(x86) * ogeePhase_1;
	const GEN_FLT x96 = x95 * x94;
	const GEN_FLT x97 = x84 * x84;
	const GEN_FLT x98 = x16 * (1 + x97);
	const GEN_FLT x99 = x98 * (1. / sqrt(1 + (-1 * x57 * x97)));
	const GEN_FLT x100 = 1. / (x69 * x69);
	const GEN_FLT x101 = x24 * x100 * (1. / sqrt(1 + (-1 * x50 * x100)));
	const GEN_FLT x102 = x77 * x101;
	const GEN_FLT x103 = -1 * x72 * x102;
	const GEN_FLT x104 = (-1 * x73 * x102) + (x70 * (x103 + (x71 * x102)));
	const GEN_FLT x105 = (-1 * x74 * x102) + (x70 * x104);
	const GEN_FLT x106 = x88 * x77;
	const GEN_FLT x107 = x75 * x76 * (1. / (x91 * x91));
	const GEN_FLT x108 = x85 + (x88 * x94);
	const GEN_FLT x109 = 1. / sqrt(1 + (-1 * (x108 * x108)));
	const GEN_FLT x110 =
		x109 * ((-2 * x78 * x92 * x101 * x106) + (x88 * x93 * x105) + x98 + (-1 * x99 * x96) +
				(-1 * x88 * x107 *
				 ((x106 * ((x70 * x105) +
						   (x70 * (x105 +
								   (x70 * (x104 + (-1 * x80 * x102) +
										   (x70 * ((2.40324066e-05 * x70 * x102) + x103 + (-1 * x79 * x102))))) +
								   (-1 * x81 * x102))) +
						   (-1 * x75 * x102) + (-1 * x82 * x102))) +
				  (-1 * x83 * x77 * x99 * x95) + x77 + (-1 * x89 * x69))));
	const GEN_FLT x111 = (-1 * asin(x108)) + gibPhase_1 + x11;
	const GEN_FLT x112 = cos(x111) * gibMag_1;
	const GEN_FLT x113 = x90 * x107;
	const GEN_FLT x114 = x109 * ((-1 * x113) + x94);
	const GEN_FLT x115 = x109 * ((-1 * x95 * x113) + x96);
	const GEN_FLT x116 = x109 * ((-1 * x87 * x113) + (x87 * x94));
	out[0] = -1;
	out[1] = (-1 * x63 * x61) + (-1 * x61);
	out[2] = (-1 * x63 * x65) + (-1 * x65);
	out[3] = x63;
	out[4] = -1 * sin(x62);
	out[5] = (-1 * x63 * x66) + (-1 * x66);
	out[6] = (-1 * x63 * x67) + (-1 * x67);
	out[7] = 0;
	out[8] = 0;
	out[9] = 0;
	out[10] = 0;
	out[11] = 0;
	out[12] = 0;
	out[13] = 0;
	out[14] = 0;
	out[15] = 0;
	out[16] = 0;
	out[17] = 0;
	out[18] = 0;
	out[19] = 0;
	out[20] = 0;
	out[21] = -1;
	out[22] = (-1 * x110 * x112) + (-1 * x110);
	out[23] = (-1 * x112 * x114) + (-1 * x114);
	out[24] = x112;
	out[25] = sin(x111);
	out[26] = (-1 * x112 * x115) + (-1 * x115);
	out[27] = (-1 * x112 * x116) + (-1 * x116);
}

static inline FLT gen_reproject_axis_x_gen2(const SurvivePose *obj_p, const FLT *sensor_pt, const SurvivePose *lh_p,
											const BaseStationCal *bsc0) {
	const GEN_FLT obj_px = (*obj_p).Pos[0];
	const GEN_FLT obj_py = (*obj_p).Pos[1];
	const GEN_FLT obj_pz = (*obj_p).Pos[2];
	const GEN_FLT obj_qw = (*obj_p).Rot[0];
	const GEN_FLT obj_qi = (*obj_p).Rot[1];
	const GEN_FLT obj_qj = (*obj_p).Rot[2];
	const GEN_FLT obj_qk = (*obj_p).Rot[3];
	const GEN_FLT sensor_x = sensor_pt[0];
	const GEN_FLT sensor_y = sensor_pt[1];
	const GEN_FLT sensor_z = sensor_pt[2];
	const GEN_FLT lh_px = (*lh_p).Pos[0];
	const GEN_FLT lh_py = (*lh_p).Pos[1];
	const GEN_FLT lh_pz = (*lh_p).Pos[2];
	const GEN_FLT lh_qw = (*lh_p).Rot[0];
	const GEN_FLT lh_qi = (*lh_p).Rot[1];
	const GEN_FLT lh_qj = (*lh_p).Rot[2];
	const GEN_FLT lh_qk = (*lh_p).Rot[3];
	const GEN_FLT phase_0 = (*bsc0).phase;
	const GEN_FLT tilt_0 = (*bsc0).tilt;
	const GEN_FLT curve_0 = (*bsc0).curve;
	const GEN_FLT gibPhase_0 = (*bsc0).gibpha;
	const GEN_FLT gibMag_0 = (*bsc0).gibmag;
	const GEN_FLT ogeeMag_0 = (*bsc0).ogeephase;
	const GEN_FLT ogeePhase_0 = (*bsc0).ogeemag;
	const GEN_FLT x0 = (obj_qk * sensor_x) + (-1 * obj_qi * sensor_z) + (obj_qw * sensor_y);
	const GEN_FLT x1 = (-1 * obj_qj * sensor_x) + (obj_qw * sensor_z) + (obj_qi * sensor_y);
	const GEN_FLT x2 = (2 * ((x1 * obj_qj) + (-1 * x0 * obj_qk))) + obj_px + sensor_x;
	const GEN_FLT x3 = (obj_qw * sensor_x) + (-1 * obj_qk * sensor_y) + (obj_qj * sensor_z);
	const GEN_FLT x4 = (2 * ((x0 * obj_qi) + (-1 * x3 * obj_qj))) + obj_pz + sensor_z;
	const GEN_FLT x5 = obj_py + (2 * ((x3 * obj_qk) + (-1 * x1 * obj_qi))) + sensor_y;
	const GEN_FLT x6 = (-1 * x5 * lh_qk) + (x2 * lh_qw) + (x4 * lh_qj);
	const GEN_FLT x7 = (x5 * lh_qw) + (-1 * x4 * lh_qi) + (x2 * lh_qk);
	const GEN_FLT x8 = x4 + lh_pz + (2 * ((x7 * lh_qi) + (-1 * x6 * lh_qj)));
	const GEN_FLT x9 = (x4 * lh_qw) + (-1 * x2 * lh_qj) + (x5 * lh_qi);
	const GEN_FLT x10 = lh_px + x2 + (2 * ((x9 * lh_qj) + (-1 * x7 * lh_qk)));
	const GEN_FLT x11 = atan2(-1 * x8, x10);
	const GEN_FLT x12 = (x10 * x10) + (x8 * x8);
	const GEN_FLT x13 = 0.523598775598299 + tilt_0;
	const GEN_FLT x14 = x5 + lh_py + (2 * ((x6 * lh_qk) + (-1 * x9 * lh_qi)));
	const GEN_FLT x15 = x14 * (1. / sqrt(x12)) * tan(x13);
	const GEN_FLT x16 = (sin((-1 * asin(x15)) + ogeeMag_0 + x11) * ogeePhase_0) + curve_0;
	const GEN_FLT x17 = cos(x13);
	const GEN_FLT x18 = asin(x14 * (1. / x17) * (1. / sqrt(x12 + (x14 * x14))));
	const GEN_FLT x19 = 0.0028679863 + (x18 * (-8.0108022e-06 + (-8.0108022e-06 * x18)));
	const GEN_FLT x20 = 5.3685255e-06 + (x19 * x18);
	const GEN_FLT x21 = 0.0076069798 + (x20 * x18);
	const GEN_FLT x22 = asin(
		x15 +
		(x21 * (x18 * x18) * x16 *
		 (1. /
		  (x17 + (-1 * x16 * sin(x13) *
				  ((x18 * (x21 + (x18 * (x20 + (x18 * (x19 + (x18 * (-8.0108022e-06 + (-1.60216044e-05 * x18))))))))) +
				   (x21 * x18)))))));
	return -1.5707963267949 + (-1 * x22) + (-1 * sin(x22 + (-1 * gibPhase_0) + (-1 * x11)) * gibMag_0) +
		   (-1 * phase_0) + x11;
}

// Jacobian of reproject_axis_x_gen2 wrt [obj_px, obj_py, obj_pz, obj_qw, obj_qi, obj_qj, obj_qk]
static inline void gen_reproject_axis_x_gen2_jac_obj_p(FLT *out, const SurvivePose *obj_p, const FLT *sensor_pt,
													   const SurvivePose *lh_p, const BaseStationCal *bsc0) {
	const GEN_FLT obj_px = (*obj_p).Pos[0];
	const GEN_FLT obj_py = (*obj_p).Pos[1];
	const GEN_FLT obj_pz = (*obj_p).Pos[2];
	const GEN_FLT obj_qw = (*obj_p).Rot[0];
	const GEN_FLT obj_qi = (*obj_p).Rot[1];
	const GEN_FLT obj_qj = (*obj_p).Rot[2];
	const GEN_FLT obj_qk = (*obj_p).Rot[3];
	const GEN_FLT sensor_x = sensor_pt[0];
	const GEN_FLT sensor_y = sensor_pt[1];
	const GEN_FLT sensor_z = sensor_pt[2];
	const GEN_FLT lh_px = (*lh_p).Pos[0];
	const GEN_FLT lh_py = (*lh_p).Pos[1];
	const GEN_FLT lh_pz = (*lh_p).Pos[2];
	const GEN_FLT lh_qw = (*lh_p).Rot[0];
	const GEN_FLT lh_qi = (*lh_p).Rot[1];
	const GEN_FLT lh_qj = (*lh_p).Rot[2];
	const GEN_FLT lh_qk = (*lh_p).Rot[3];
	const GEN_FLT phase_0 = (*bsc0).phase;
	const GEN_FLT tilt_0 = (*bsc0).tilt;
	const GEN_FLT curve_0 = (*bsc0).curve;
	const GEN_FLT gibPhase_0 = (*bsc0).gibpha;
	const GEN_FLT gibMag_0 = (*bsc0).gibmag;
	const GEN_FLT ogeeMag_0 = (*bsc0).ogeephase;
	const GEN_FLT ogeePhase_0 = (*bsc0).ogeemag;
	const GEN_FLT x0 = obj_qw * sensor_x;
	const GEN_FLT x1 = obj_qj * sensor_z;
	const GEN_FLT x2 = obj_qk * sensor_y;
	const GEN_FLT x3 = (-1 * x2) + x0 + x1;
	const GEN_FLT x4 = obj_qk * sensor_x;
	const GEN_FLT x5 = obj_qw * sensor_y;
	const GEN_FLT x6 = obj_qi * sensor_z;
	const GEN_FLT x7 = (-1 * x6) + x4 + x5;
	const GEN_FLT x8 = (2 * ((x7 * obj_qi) + (-1 * x3 * obj_qj))) + obj_pz + sensor_z;
	const GEN_FLT x9 = obj_qw * sensor_z;
	const GEN_FLT x10 = obj_qi * sensor_y;
	const GEN_FLT x11 = obj_qj * sensor_x;
	const GEN_FLT x12 = (-1 * x11) + x9 + x10;
	const GEN_FLT x13 = (2 * ((x3 * obj_qk) + (-1 * x12 * obj_qi))) + obj_py + sensor_y;
	const GEN_FLT x14 = (2 * ((x12 * obj_qj) + (-1 * x7 * obj_qk))) + obj_px + sensor_x;
	const GEN_FLT x15 = (-1 * x14 * lh_qj) + (x8 * lh_qw) + (x13 * lh_qi);
	const GEN_FLT x16 = (-1 * x13 * lh_qk) + (x14 * lh_qw) + (x8 * lh_qj);
	const GEN_FLT x17 = x13 + lh_py + (2 * ((x16 * lh_qk) + (-1 * x15 * lh_qi)));
	const GEN_FLT x18 = 0.523598775598299 + tilt_0;
	const GEN_FLT x19 = cos(x18);
	const GEN_FLT x20 = 1. / x19;
	const GEN_FLT x21 = x17 * x17;
	const GEN_FLT x22 = (-1 * x8 * lh_qi) + (x13 * lh_qw) + (x14 * lh_qk);
	const GEN_FLT x23 = x8 + lh_pz + (2 * ((x22 * lh_qi) + (-1 * x16 * lh_qj)));
	const GEN_FLT x24 = lh_px + x14 + (2 * ((x15 * lh_qj) + (-1 * x22 * lh_qk)));
	const GEN_FLT x25 = x24 * x24;
	const GEN_FLT x26 = x25 + (x23 * x23);
	const GEN_FLT x27 = x26 + x21;
	const GEN_FLT x28 = x20 * (1. / sqrt(x27));
	const GEN_FLT x29 = asin(x28 * x17);
	const GEN_FLT x30 = 8.0108022e-06 * x29;
	const GEN_FLT x31 = -8.0108022e-06 + (-1 * x30);
	const GEN_FLT x32 = 0.0028679863 + (x31 * x29);
	const GEN_FLT x33 = 5.3685255e-06 + (x32 * x29);
	const GEN_FLT x34 = 0.0076069798 + (x33 * x29);
	const GEN_FLT x35 = x34 * x29;
	const GEN_FLT x36 = -8.0108022e-06 + (-1.60216044e-05 * x29);
	const GEN_FLT x37 = x32 + (x36 * x29);
	const GEN_FLT x38 = x33 + (x37 * x29);
	const GEN_FLT x39 = x34 + (x38 * x29);
	const GEN_FLT x40 = (x39 * x29) + x35;
	const GEN_FLT x41 = sin(x18);
	const GEN_FLT x42 = atan2(-1 * x23, x24);
	const GEN_FLT x43 = tan(x18);
	const GEN_FLT x44 = x43 * (1. / sqrt(x26));
	const GEN_FLT x45 = x44 * x17;
	const GEN_FLT x46 = ogeeMag_0 + (-1 * asin(x45)) + x42;
	const GEN_FLT x47 = (sin(x46) * ogeePhase_0) + curve_0;
	const GEN_FLT x48 = x41 * x47;
	const GEN_FLT x49 = x19 + (-1 * x40 * x48);
	const GEN_FLT x50 = 1. / x49;
	const GEN_FLT x51 = x29 * x29;
	const GEN_FLT x52 = x51 * x47;
	const GEN_FLT x53 = x50 * x52;
	const GEN_FLT x54 = x45 + (x53 * x34);
	const GEN_FLT x55 = 1. / sqrt(1 + (-1 * (x54 * x54)));
	const GEN_FLT x56 = 1. / x26;
	const GEN_FLT x57 = 1. / sqrt(1 + (-1 * x56 * (x43 * x43) * x21));
	const GEN_FLT x58 = 2 * lh_qi;
	const GEN_FLT x59 = x58 * lh_qj;
	const GEN_FLT x60 = 2 * lh_qw;
	const GEN_FLT x61 = x60 * lh_qk;
	const GEN_FLT x62 = x61 + x59;
	const GEN_FLT x63 = -2 * (lh_qk * lh_qk);
	const GEN_FLT x64 = -2 * (lh_qj * lh_qj);
	const GEN_FLT x65 = 1 + x64 + x63;
	const GEN_FLT x66 = 2 * x24;
	const GEN_FLT x67 = x60 * lh_qj;
	const GEN_FLT x68 = 2 * lh_qk;
	const GEN_FLT x69 = x68 * lh_qi;
	const GEN_FLT x70 = x69 + (-1 * x67);
	const GEN_FLT x71 = 2 * x23;
	const GEN_FLT x72 = (x71 * x70) + (x65 * x66);
	const GEN_FLT x73 = 1.0 / 2.0 * x17;
	const GEN_FLT x74 = x73 * x43 * (1. / (x26 * sqrt(x26)));
	const GEN_FLT x75 = (-1 * x72 * x74) + (x62 * x44);
	const GEN_FLT x76 = 1. / x24;
	const GEN_FLT x77 = (1. / x25) * x23;
	const GEN_FLT x78 = x56 * x25;
	const GEN_FLT x79 = ((x77 * x65) + (-1 * x70 * x76)) * x78;
	const GEN_FLT x80 = x79 + (-1 * x75 * x57);
	const GEN_FLT x81 = cos(x46) * ogeePhase_0;
	const GEN_FLT x82 = x50 * x51 * x34;
	const GEN_FLT x83 = x81 * x82;
	const GEN_FLT x84 = 1. / sqrt(1 + (-1 * x21 * (1. / x27) * (1. / (x19 * x19))));
	const GEN_FLT x85 = 2 * x17;
	const GEN_FLT x86 = x73 * x20 * (1. / (x27 * sqrt(x27)));
	const GEN_FLT x87 = x84 * ((x62 * x28) + (-1 * x86 * (x72 + (x85 * x62))));
	const GEN_FLT x88 = x87 * x31;
	const GEN_FLT x89 = 2.40324066e-05 * x29;
	const GEN_FLT x90 = (x87 * x32) + (x29 * (x88 + (-1 * x87 * x30)));
	const GEN_FLT x91 = (x90 * x29) + (x87 * x33);
	const GEN_FLT x92 = x40 * x41;
	const GEN_FLT x93 = x81 * x92;
	const GEN_FLT x94 = x52 * (1. / (x49 * x49)) * x34;
	const GEN_FLT x95 = 2 * x50 * x47 * x35;
	const GEN_FLT x96 =
		x55 * (x75 + (x53 * x91) + (x87 * x95) + (x80 * x83) +
			   (-1 * x94 *
				((-1 * x80 * x93) +
				 (-1 * x48 *
				  ((x91 * x29) + (x87 * x34) + (x87 * x39) +
				   (x29 * (x91 + (x87 * x38) +
						   (x29 * (x90 + (x29 * ((-1 * x89 * x87) + x88 + (x87 * x36))) + (x87 * x37))))))))));
	const GEN_FLT x97 = cos((-1 * asin(x54)) + gibPhase_0 + x42) * gibMag_0;
	const GEN_FLT x98 = 1 + (-2 * (lh_qi * lh_qi));
	const GEN_FLT x99 = x98 + x63;
	const GEN_FLT x100 = x59 + (-1 * x61);
	const GEN_FLT x101 = x68 * lh_qj;
	const GEN_FLT x102 = x60 * lh_qi;
	const GEN_FLT x103 = x102 + x101;
	const GEN_FLT x104 = (x71 * x103) + (x66 * x100);
	const GEN_FLT x105 = x84 * ((x99 * x28) + (-1 * x86 * (x104 + (x85 * x99))));
	const GEN_FLT x106 = x31 * x105;
	const GEN_FLT x107 = (x32 * x105) + (x29 * (x106 + (-1 * x30 * x105)));
	const GEN_FLT x108 = (x29 * x107) + (x33 * x105);
	const GEN_FLT x109 = (-1 * x74 * x104) + (x99 * x44);
	const GEN_FLT x110 = ((x77 * x100) + (-1 * x76 * x103)) * x78;
	const GEN_FLT x111 = x110 + (-1 * x57 * x109);
	const GEN_FLT x112 =
		x55 * ((x83 * x111) + (x95 * x105) + x109 + (x53 * x108) +
			   (-1 * x94 *
				((-1 * x93 * x111) +
				 (-1 * x48 *
				  ((x29 * x108) + (x34 * x105) + (x39 * x105) +
				   (x29 * (x108 + (x38 * x105) +
						   (x29 * (x107 + (x29 * ((-1 * x89 * x105) + (x36 * x105) + x106)) + (x37 * x105))))))))));
	const GEN_FLT x113 = x101 + (-1 * x102);
	const GEN_FLT x114 = x67 + x69;
	const GEN_FLT x115 = x98 + x64;
	const GEN_FLT x116 = (x71 * x115) + (x66 * x114);
	const GEN_FLT x117 = (-1 * x74 * x116) + (x44 * x113);
	const GEN_FLT x118 = ((x77 * x114) + (-1 * x76 * x115)) * x78;
	const GEN_FLT x119 = x118 + (-1 * x57 * x117);
	const GEN_FLT x120 = (x28 * x113) + (-1 * x86 * (x116 + (x85 * x113)));
	const GEN_FLT x121 = x84 * x120;
	const GEN_FLT x122 = x31 * x121;
	const GEN_FLT x123 = x84 * x37;
	const GEN_FLT x124 = (x32 * x121) + (x29 * (x122 + (-1 * x30 * x121)));
	const GEN_FLT x125 = (x29 * x124) + (x33 * x121);
	const GEN_FLT x126 =
		x55 * ((x53 * x125) + x117 +
			   (-1 * x94 *
				((-1 * x93 * x119) +
				 (-1 * x48 *
				  ((x29 * x125) + (x34 * x121) +
				   (x29 * ((x38 * x121) + x125 +
						   (x29 * (x124 + (x29 * ((-1 * x89 * x121) + x122 + (x36 * x121))) + (x120 * x123))))) +
				   (x39 * x121))))) +
			   (x83 * x119) + (x95 * x121));
	const GEN_FLT x127 = 2 * x6;
	const GEN_FLT x128 = 2 * x4;
	const GEN_FLT x129 = x128 + (-1 * x127);
	const GEN_FLT x130 = 2 * x2;
	const GEN_FLT x131 = 2 * x1;
	const GEN_FLT x132 = x131 + (-1 * x130);
	const GEN_FLT x133 = 2 * x11;
	const GEN_FLT x134 = 2 * x10;
	const GEN_FLT x135 = x134 + (-1 * x133);
	const GEN_FLT x136 = (-1 * x129 * lh_qk) + (x135 * lh_qj) + (x132 * lh_qw);
	const GEN_FLT x137 = (x129 * lh_qi) + (x135 * lh_qw) + (-1 * x132 * lh_qj);
	const GEN_FLT x138 = x129 + (x68 * x136) + (-1 * x58 * x137);
	const GEN_FLT x139 = 2 * lh_qj;
	const GEN_FLT x140 = (x132 * lh_qk) + (-1 * x135 * lh_qi) + (x129 * lh_qw);
	const GEN_FLT x141 = x132 + (x137 * x139) + (-1 * x68 * x140);
	const GEN_FLT x142 = x135 + (x58 * x140) + (-1 * x136 * x139);
	const GEN_FLT x143 = (x71 * x142) + (x66 * x141);
	const GEN_FLT x144 = (x28 * x138) + (-1 * x86 * (x143 + (x85 * x138)));
	const GEN_FLT x145 = x84 * x144;
	const GEN_FLT x146 = x31 * x145;
	const GEN_FLT x147 = (x32 * x145) + (x29 * (x146 + (-1 * x30 * x145)));
	const GEN_FLT x148 = (x29 * x147) + (x33 * x145);
	const GEN_FLT x149 = (-1 * x74 * x143) + (x44 * x138);
	const GEN_FLT x150 = ((x77 * x141) + (-1 * x76 * x142)) * x78;
	const GEN_FLT x151 = x150 + (-1 * x57 * x149);
	const GEN_FLT x152 =
		x55 * (x149 + (x53 * x148) + (x83 * x151) +
			   (-1 * x94 *
				((-1 * x93 * x151) +
				 (-1 * x48 *
				  ((x34 * x145) + (x39 * x145) + (x29 * x148) +
				   (x29 * (x148 + (x38 * x145) +
						   (x29 * (x147 + (x29 * ((-1 * x89 * x145) + x146 + (x36 * x145))) + (x123 * x144))))))))) +
			   (x95 * x145));
	const GEN_FLT x153 = 2 * x5;
	const GEN_FLT x154 = x153 + x128 + (-4 * x6);
	const GEN_FLT x155 = 2 * x9;
	const GEN_FLT x156 = (-4 * x10) + x133 + (-1 * x155);
	const GEN_FLT x157 = 2 * obj_qk * sensor_z;
	const GEN_FLT x158 = 2 * obj_qj * sensor_y;
	const GEN_FLT x159 = x158 + x157;
	const GEN_FLT x160 = (x159 * lh_qk) + (-1 * x154 * lh_qi) + (x156 * lh_qw);
	const GEN_FLT x161 = 2 * ((x154 * lh_qj) + (-1 * x156 * lh_qk) + (x159 * lh_qw));
	const GEN_FLT x162 = x154 + (x58 * x160) + (-1 * x161 * lh_qj);
	const GEN_FLT x163 = (x156 * lh_qi) + (x154 * lh_qw) + (-1 * x159 * lh_qj);
	const GEN_FLT x164 = x159 + (x163 * x139) + (-1 * x68 * x160);
	const GEN_FLT x165 = ((x77 * x164) + (-1 * x76 * x162)) * x78;
	const GEN_FLT x166 = x156 + (x161 * lh_qk) + (-1 * x58 * x163);
	const GEN_FLT x167 = (x71 * x162) + (x66 * x164);
	const GEN_FLT x168 = (x28 * x166) + (-1 * x86 * (x167 + (x85 * x166)));
	const GEN_FLT x169 = x84 * x168;
	const GEN_FLT x170 = x31 * x169;
	const GEN_FLT x171 = (x32 * x169) + (x29 * (x170 + (-1 * x30 * x169)));
	const GEN_FLT x172 = (x29 * x171) + (x33 * x169);
	const GEN_FLT x173 = (-1 * x74 * x167) + (x44 * x166);
	const GEN_FLT x174 = x165 + (-1 * x57 * x173);
	const GEN_FLT x175 =
		x55 * ((x83 * x174) + (x53 * x172) +
			   (-1 * x94 *
				((-1 * x93 * x174) +
				 (-1 * x48 *
				  ((x29 * x172) + (x34 * x169) +
				   (x29 * (x172 + (x38 * x169) +
						   (x29 * (x171 + (x29 * ((-1 * x89 * x169) + x170 + (x36 * x169))) + (x123 * x168))))) +
				   (x39 * x169))))) +
			   x173 + (x95 * x169));
	const GEN_FLT x176 = 2 * obj_qi * sensor_x;
	const GEN_FLT x177 = x157 + x176;
	const GEN_FLT x178 = x134 + (-4 * x11) + x155;
	const GEN_FLT x179 = 2 * x0;
	const GEN_FLT x180 = (-4 * x1) + (-1 * x179) + x130;
	const GEN_FLT x181 = (x180 * lh_qj) + (-1 * x177 * lh_qk) + (x178 * lh_qw);
	const GEN_FLT x182 = (x177 * lh_qi) + (-1 * x178 * lh_qj) + (x180 * lh_qw);
	const GEN_FLT x183 = x177 + (x68 * x181) + (-1 * x58 * x182);
	const GEN_FLT x184 = (x178 * lh_qk) + (-1 * x180 * lh_qi) + (x177 * lh_qw);
	const GEN_FLT x185 = x178 + (x182 * x139) + (-1 * x68 * x184);
	const GEN_FLT x186 = x180 + (x58 * x184) + (-1 * x181 * x139);
	const GEN_FLT x187 = (x71 * x186) + (x66 * x185);
	const GEN_FLT x188 = (x28 * x183) + (-1 * x86 * (x187 + (x85 * x183)));
	const GEN_FLT x189 = x84 * x188;
	const GEN_FLT x190 = x31 * x189;
	const GEN_FLT x191 = (x32 * x189) + (x29 * (x190 + (-1 * x30 * x189)));
	const GEN_FLT x192 = (x29 * x191) + (x33 * x189);
	const GEN_FLT x193 = (-1 * x74 * x187) + (x44 * x183);
	const GEN_FLT x194 = ((x77 * x185) + (-1 * x76 * x186)) * x78;
	const GEN_FLT x195 = x194 + (-1 * x57 * x193);
	const GEN_FLT x196 =
		x55 * (x193 +
			   (-1 * x94 *
				((-1 * x93 * x195) +
				 (-1 * x48 *
				  ((x29 * x192) + (x39 * x189) +
				   (x29 * (x192 + (x38 * x189) +
						   (x29 * (x191 + (x29 * ((x36 * x189) + (-1 * x89 * x189) + x190)) + (x123 * x188))))) +
				   (x34 * x189))))) +
			   (x53 * x192) + (x83 * x195) + (x95 * x189));
	const GEN_FLT x197 = x131 + x179 + (-4 * x2);
	const GEN_FLT x198 = (-1 * x153) + (-4 * x4) + x127;
	const GEN_FLT x199 = x176 + x158;
	const GEN_FLT x200 = (x199 * lh_qj) + (-1 * x197 * lh_qk) + (x198 * lh_qw);
	const GEN_FLT x201 = (x197 * lh_qi) + (-1 * x198 * lh_qj) + (x199 * lh_qw);
	const GEN_FLT x202 = x197 + (x68 * x200) + (-1 * x58 * x201);
	const GEN_FLT x203 = (x198 * lh_qk) + (x197 * lh_qw) + (-1 * x199 * lh_qi);
	const GEN_FLT x204 = x198 + (x201 * x139) + (-1 * x68 * x203);
	const GEN_FLT x205 = x199 + (x58 * x203) + (-1 * x200 * x139);
	const GEN_FLT x206 = (x71 * x205) + (x66 * x204);
	const GEN_FLT x207 = x84 * ((x28 * x202) + (-1 * x86 * (x206 + (x85 * x202))));
	const GEN_FLT x208 = (-1 * x74 * x206) + (x44 * x202);
	const GEN_FLT x209 = ((x77 * x204) + (-1 * x76 * x205)) * x78;
	const GEN_FLT x210 = x81 * (x209 + (-1 * x57 * x208));
	const GEN_FLT x211 = x31 * x207;
	const GEN_FLT x212 = (x32 * x207) + (x29 * (x211 + (-1 * x30 * x207)));
	const GEN_FLT x213 = (x29 * x212) + (x33 * x207);
	const GEN_FLT x214 =
		x55 * (x208 +
			   (-1 * x94 *
				((-1 * x92 * x210) +
				 (-1 * x48 *
				  ((x29 * x213) + (x39 * x207) + (x34 * x207) +
				   (x29 * (x213 + (x38 * x207) +
						   (x29 * (x212 + (x29 * ((-1 * x89 * x207) + x211 + (x36 * x207))) + (x37 * x207))))))))) +
			   (x53 * x213) + (x95 * x207) + (x82 * x210));
	out[0] = (-1 * x96) + (-1 * ((-1 * x79) + x96) * x97) + x79;
	out[1] = (-1 * ((-1 * x110) + x112) * x97) + (-1 * x112) + x110;
	out[2] = (-1 * ((-1 * x118) + x126) * x97) + (-1 * x126) + x118;
	out[3] = (-1 * ((-1 * x150) + x152) * x97) + (-1 * x152) + x150;
	out[4] = (-1 * ((-1 * x165) + x175) * x97) + x165 + (-1 * x175);
	out[5] = (-1 * ((-1 * x194) + x196) * x97) + (-1 * x196) + x194;
	out[6] = (-1 * ((-1 * x209) + x214) * x97) + (-1 * x214) + x209;
}

// Jacobian of reproject_axis_x_gen2 wrt [sensor_x, sensor_y, sensor_z]
static inline void gen_reproject_axis_x_gen2_jac_sensor_pt(FLT *out, const SurvivePose *obj_p, const FLT *sensor_pt,
														   const SurvivePose *lh_p, const BaseStationCal *bsc0) {
	const GEN_FLT obj_px = (*obj_p).Pos[0];
	const GEN_FLT obj_py = (*obj_p).Pos[1];
	const GEN_FLT obj_pz = (*obj_p).Pos[2];
	const GEN_FLT obj_qw = (*obj_p).Rot[0];
	const GEN_FLT obj_qi = (*obj_p).Rot[1];
	const GEN_FLT obj_qj = (*obj_p).Rot[2];
	const GEN_FLT obj_qk = (*obj_p).Rot[3];
	const GEN_FLT sensor_x = sensor_pt[0];
	const GEN_FLT sensor_y = sensor_pt[1];
	const GEN_FLT sensor_z = sensor_pt[2];
	const GEN_FLT lh_px = (*lh_p).Pos[0];
	const GEN_FLT lh_py = (*lh_p).Pos[1];
	const GEN_FLT lh_pz = (*lh_p).Pos[2];
	const GEN_FLT lh_qw = (*lh_p).Rot[0];
	const GEN_FLT lh_qi = (*lh_p).Rot[1];
	const GEN_FLT lh_qj = (*lh_p).Rot[2];
	const GEN_FLT lh_qk = (*lh_p).Rot[3];
	const GEN_FLT phase_0 = (*bsc0).phase;
	const GEN_FLT tilt_0 = (*bsc0).tilt;
	const GEN_FLT curve_0 = (*bsc0).curve;
	const GEN_FLT gibPhase_0 = (*bsc0).gibpha;
	const GEN_FLT gibMag_0 = (*bsc0).gibmag;
	const GEN_FLT ogeeMag_0 = (*bsc0).ogeephase;
	const GEN_FLT ogeePhase_0 = (*bsc0).ogeemag;
	const GEN_FLT x0 = (obj_qw * sensor_x) + (-1 * obj_qk * sensor_y) + (obj_qj * sensor_z);
	const GEN_FLT x1 = (obj_qk * sensor_x) + (-1 * obj_qi * sensor_z) + (obj_qw * sensor_y);
	const GEN_FLT x2 = (2 * ((x1 * obj_qi) + (-1 * x0 * obj_qj))) + obj_pz + sensor_z;
	const GEN_FLT x3 = (-1 * obj_qj * sensor_x) + (obj_qw * sensor_z) + (obj_qi * sensor_y);
	const GEN_FLT x4 = (2 * ((x0 * obj_qk) + (-1 * x3 * obj_qi))) + obj_py + sensor_y;
	const GEN_FLT x5 = (2 * ((x3 * obj_qj) + (-1 * x1 * obj_qk))) + obj_px + sensor_x;
	const GEN_FLT x6 = (-1 * x5 * lh_qj) + (x2 * lh_qw) + (x4 * lh_qi);
	const GEN_FLT x7 = (-1 * x4 * lh_qk) + (x5 * lh_qw) + (x2 * lh_qj);
	const GEN_FLT x8 = x4 + lh_py + (2 * ((x7 * lh_qk) + (-1 * x6 * lh_qi)));
	const GEN_FLT x9 = 0.523598775598299 + tilt_0;
	const GEN_FLT x10 = cos(x9);
	const GEN_FLT x11 = 1. / x10;
	const GEN_FLT x12 = x8 * x8;
	const GEN_FLT x13 = (-1 * x2 * lh_qi) + (x4 * lh_qw) + (x5 * lh_qk);
	const GEN_FLT x14 = x2 + lh_pz + (2 * ((x13 * lh_qi) + (-1 * x7 * lh_qj)));
	const GEN_FLT x15 = x5 + lh_px + (2 * ((x6 * lh_qj) + (-1 * x13 * lh_qk)));
	const GEN_FLT x16 = x15 * x15;
	const GEN_FLT x17 = x16 + (x14 * x14);
	const GEN_FLT x18 = x17 + x12;
	const GEN_FLT x19 = x11 * (1. / sqrt(x18));
	const GEN_FLT x20 = asin(x8 * x19);
	const GEN_FLT x21 = 8.0108022e-06 * x20;
	const GEN_FLT x22 = -8.0108022e-06 + (-1 * x21);
	const GEN_FLT x23 = 0.0028679863 + (x22 * x20);
	const GEN_FLT x24 = 5.3685255e-06 + (x23 * x20);
	const GEN_FLT x25 = 0.0076069798 + (x24 * x20);
	const GEN_FLT x26 = x25 * x20;
	const GEN_FLT x27 = -8.0108022e-06 + (-1.60216044e-05 * x20);
	const GEN_FLT x28 = x23 + (x20 * x27);
	const GEN_FLT x29 = x24 + (x20 * x28);
	const GEN_FLT x30 = x25 + (x20 * x29);
	const GEN_FLT x31 = (x30 * x20) + x26;
	const GEN_FLT x32 = sin(x9);
	const GEN_FLT x33 = atan2(-1 * x14, x15);
	const GEN_FLT x34 = tan(x9);
	const GEN_FLT x35 = x34 * (1. / sqrt(x17));
	const GEN_FLT x36 = x8 * x35;
	const GEN_FLT x37 = (-1 * asin(x36)) + ogeeMag_0 + x33;
	const GEN_FLT x38 = (sin(x37) * ogeePhase_0) + curve_0;
	const GEN_FLT x39 = x32 * x38;
	const GEN_FLT x40 = x10 + (-1 * x31 * x39);
	const GEN_FLT x41 = 1. / x40;
	const GEN_FLT x42 = x20 * x20;
	const GEN_FLT x43 = x42 * x38;
	const GEN_FLT x44 = x41 * x43;
	const GEN_FLT x45 = x36 + (x44 * x25);
	const GEN_FLT x46 = 1. / sqrt(1 + (-1 * (x45 * x45)));
	const GEN_FLT x47 = 1. / sqrt(1 + (-1 * x12 * (1. / (x10 * x10)) * (1. / x18)));
	const GEN_FLT x48 = -2 * (obj_qk * obj_qk);
	const GEN_FLT x49 = 1 + (-2 * (obj_qj * obj_qj));
	const GEN_FLT x50 = x49 + x48;
	const GEN_FLT x51 = 2 * obj_qi;
	const GEN_FLT x52 = x51 * obj_qj;
	const GEN_FLT x53 = 2 * obj_qw;
	const GEN_FLT x54 = x53 * obj_qk;
	const GEN_FLT x55 = x54 + x52;
	const GEN_FLT x56 = x53 * obj_qj;
	const GEN_FLT x57 = x51 * obj_qk;
	const GEN_FLT x58 = x57 + (-1 * x56);
	const GEN_FLT x59 = 2 * ((x58 * lh_qj) + (x50 * lh_qw) + (-1 * x55 * lh_qk));
	const GEN_FLT x60 = 2 * ((x55 * lh_qi) + (-1 * x50 * lh_qj) + (x58 * lh_qw));
	const GEN_FLT x61 = x55 + (x59 * lh_qk) + (-1 * x60 * lh_qi);
	const GEN_FLT x62 = 2 * x8;
	const GEN_FLT x63 = 2 * ((x50 * lh_qk) + (-1 * x58 * lh_qi) + (x55 * lh_qw));
	const GEN_FLT x64 = x50 + (x60 * lh_qj) + (-1 * x63 * lh_qk);
	const GEN_FLT x65 = 2 * x15;
	const GEN_FLT x66 = x58 + (x63 * lh_qi) + (-1 * x59 * lh_qj);
	const GEN_FLT x67 = 2 * x14;
	const GEN_FLT x68 = (x67 * x66) + (x64 * x65);
	const GEN_FLT x69 = 1.0 / 2.0 * x8;
	const GEN_FLT x70 = x69 * x11 * (1. / (x18 * sqrt(x18)));
	const GEN_FLT x71 = x47 * ((x61 * x19) + (-1 * x70 * (x68 + (x61 * x62))));
	const GEN_FLT x72 = x71 * x22;
	const GEN_FLT x73 = 2.40324066e-05 * x20;
	const GEN_FLT x74 = (x71 * x23) + (x20 * (x72 + (-1 * x71 * x21)));
	const GEN_FLT x75 = (x74 * x20) + (x71 * x24);
	const GEN_FLT x76 = x69 * x34 * (1. / (x17 * sqrt(x17)));
	const GEN_FLT x77 = (-1 * x76 * x68) + (x61 * x35);
	const GEN_FLT x78 = 1. / x17;
	const GEN_FLT x79 = 1. / sqrt(1 + (-1 * x78 * (x34 * x34) * x12));
	const GEN_FLT x80 = 1. / x15;
	const GEN_FLT x81 = x14 * (1. / x16);
	const GEN_FLT x82 = x78 * x16;
	const GEN_FLT x83 = ((x81 * x64) + (-1 * x80 * x66)) * x82;
	const GEN_FLT x84 = x83 + (-1 * x79 * x77);
	const GEN_FLT x85 = cos(x37) * ogeePhase_0;
	const GEN_FLT x86 = x32 * x31;
	const GEN_FLT x87 = x85 * x86;
	const GEN_FLT x88 = (1. / (x40 * x40)) * x43 * x25;
	const GEN_FLT x89 = 2 * x41 * x38 * x26;
	const GEN_FLT x90 = x41 * x42 * x25;
	const GEN_FLT x91 = x85 * x90;
	const GEN_FLT x92 =
		x46 *
		((x75 * x44) + (x84 * x91) +
		 (-1 * x88 *
		  ((-1 * x84 * x87) + (-1 * x39 *
							   ((x71 * x25) + (x75 * x20) +
								(x20 * (x75 + (x71 * x29) +
										(x20 * (x74 + (x20 * ((-1 * x71 * x73) + x72 + (x71 * x27))) + (x71 * x28))))) +
								(x71 * x30))))) +
		 x77 + (x89 * x71));
	const GEN_FLT x93 = cos((-1 * asin(x45)) + gibPhase_0 + x33) * gibMag_0;
	const GEN_FLT x94 = 2 * obj_qk * obj_qj;
	const GEN_FLT x95 = x51 * obj_qw;
	const GEN_FLT x96 = x95 + x94;
	const GEN_FLT x97 = -2 * (obj_qi * obj_qi);
	const GEN_FLT x98 = 1 + x48 + x97;
	const GEN_FLT x99 = x52 + (-1 * x54);
	const GEN_FLT x100 = 2 * ((-1 * x96 * lh_qi) + (x99 * lh_qk) + (x98 * lh_qw));
	const GEN_FLT x101 = 2 * ((x96 * lh_qj) + (x99 * lh_qw) + (-1 * x98 * lh_qk));
	const GEN_FLT x102 = (x100 * lh_qi) + x96 + (-1 * x101 * lh_qj);
	const GEN_FLT x103 = 2 * ((-1 * x99 * lh_qj) + (x98 * lh_qi) + (x96 * lh_qw));
	const GEN_FLT x104 = (x103 * lh_qj) + x99 + (-1 * x100 * lh_qk);
	const GEN_FLT x105 = ((x81 * x104) + (-1 * x80 * x102)) * x82;
	const GEN_FLT x106 = x98 + (x101 * lh_qk) + (-1 * x103 * lh_qi);
	const GEN_FLT x107 = (x67 * x102) + (x65 * x104);
	const GEN_FLT x108 = (-1 * x76 * x107) + (x35 * x106);
	const GEN_FLT x109 = x105 + (-1 * x79 * x108);
	const GEN_FLT x110 = x47 * ((x19 * x106) + (-1 * x70 * (x107 + (x62 * x106))));
	const GEN_FLT x111 = x22 * x110;
	const GEN_FLT x112 = (x23 * x110) + (x20 * (x111 + (-1 * x21 * x110)));
	const GEN_FLT x113 = (x20 * x112) + (x24 * x110);
	const GEN_FLT x114 =
		x46 * ((-1 * x88 *
				((-1 * x87 * x109) +
				 (-1 * x39 *
				  ((x20 * x113) + (x25 * x110) +
				   (x20 * (x113 + (x29 * x110) +
						   (x20 * ((x20 * ((-1 * x73 * x110) + x111 + (x27 * x110))) + x112 + (x28 * x110))))) +
				   (x30 * x110))))) +
			   (x89 * x110) + x108 + (x91 * x109) + (x44 * x113));
	const GEN_FLT x115 = x94 + (-1 * x95);
	const GEN_FLT x116 = x56 + x57;
	const GEN_FLT x117 = x49 + x97;
	const GEN_FLT x118 = 2 * ((-1 * x115 * lh_qk) + (x117 * lh_qj) + (x116 * lh_qw));
	const GEN_FLT x119 = 2 * ((x115 * lh_qi) + (-1 * x116 * lh_qj) + (x117 * lh_qw));
	const GEN_FLT x120 = x115 + (x118 * lh_qk) + (-1 * x119 * lh_qi);
	const GEN_FLT x121 = 2 * ((-1 * x117 * lh_qi) + (x116 * lh_qk) + (x115 * lh_qw));
	const GEN_FLT x122 = x116 + (x119 * lh_qj) + (-1 * x121 * lh_qk);
	const GEN_FLT x123 = (x121 * lh_qi) + x117 + (-1 * x118 * lh_qj);
	const GEN_FLT x124 = (x67 * x123) + (x65 * x122);
	const GEN_FLT x125 = (-1 * x76 * x124) + (x35 * x120);
	const GEN_FLT x126 = ((x81 * x122) + (-1 * x80 * x123)) * x82;
	const GEN_FLT x127 = x85 * (x126 + (-1 * x79 * x125));
	const GEN_FLT x128 = x47 * ((x19 * x120) + (-1 * x70 * (x124 + (x62 * x120))));
	const GEN_FLT x129 = x22 * x128;
	const GEN_FLT x130 = (x23 * x128) + (x20 * (x129 + (-1 * x21 * x128)));
	const GEN_FLT x131 = (x20 * x130) + (x24 * x128);
	const GEN_FLT x132 =
		x46 * (x125 +
			   (-1 * x88 *
				((-1 * x86 * x127) +
				 (-1 * x39 *
				  ((x20 * x131) + (x25 * x128) + (x30 * x128) +
				   (x20 * (x131 + (x29 * x128) +
						   (x20 * (x130 + (x20 * (x129 + (-1 * x73 * x128) + (x27 * x128))) + (x28 * x128))))))))) +
			   (x89 * x128) + (x90 * x127) + (x44 * x131));
	out[0] = (-1 * ((-1 * x83) + x92) * x93) + (-1 * x92) + x83;
	out[1] = (-1 * ((-1 * x105) + x114) * x93) + x105 + (-1 * x114);
	out[2] = (-1 * x132) + (-1 * ((-1 * x126) + x132) * x93) + x126;
}

// Jacobian of reproject_axis_x_gen2 wrt [lh_px, lh_py, lh_pz, lh_qw, lh_qi, lh_qj, lh_qk]
static inline void gen_reproject_axis_x_gen2_jac_lh_p(FLT *out, const SurvivePose *obj_p, const FLT *sensor_pt,
													  const SurvivePose *lh_p, const BaseStationCal *bsc0) {
	const GEN_FLT obj_px = (*obj_p).Pos[0];
	const GEN_FLT obj_py = (*obj_p).Pos[1];
	const GEN_FLT obj_pz = (*obj_p).Pos[2];
	const GEN_FLT obj_qw = (*obj_p).Rot[0];
	const GEN_FLT obj_qi = (*obj_p).Rot[1];
	const GEN_FLT obj_qj = (*obj_p).Rot[2];
	const GEN_FLT obj_qk = (*obj_p).Rot[3];
	const GEN_FLT sensor_x = sensor_pt[0];
	const GEN_FLT sensor_y = sensor_pt[1];
	const GEN_FLT sensor_z = sensor_pt[2];
	const GEN_FLT lh_px = (*lh_p).Pos[0];
	const GEN_FLT lh_py = (*lh_p).Pos[1];
	const GEN_FLT lh_pz = (*lh_p).Pos[2];
	const GEN_FLT lh_qw = (*lh_p).Rot[0];
	const GEN_FLT lh_qi = (*lh_p).Rot[1];
	const GEN_FLT lh_qj = (*lh_p).Rot[2];
	const GEN_FLT lh_qk = (*lh_p).Rot[3];
	const GEN_FLT phase_0 = (*bsc0).phase;
	const GEN_FLT tilt_0 = (*bsc0).tilt;
	const GEN_FLT curve_0 = (*bsc0).curve;
	const GEN_FLT gibPhase_0 = (*bsc0).gibpha;
	const GEN_FLT gibMag_0 = (*bsc0).gibmag;
	const GEN_FLT ogeeMag_0 = (*bsc0).ogeephase;
	const GEN_FLT ogeePhase_0 = (*bsc0).ogeemag;
	const GEN_FLT x0 = (obj_qw * sensor_x) + (-1 * obj_qk * sensor_y) + (obj_qj * sensor_z);
	const GEN_FLT x1 = (obj_qk * sensor_x) + (-1 * obj_qi * sensor_z) + (obj_qw * sensor_y);
	const GEN_FLT x2 = 2 * ((x1 * obj_qi) + (-1 * x0 * obj_qj));
	const GEN_FLT x3 = x2 + obj_pz + sensor_z;
	const GEN_FLT x4 = x3 * lh_qw;
	const GEN_FLT x5 = (-1 * obj_qj * sensor_x) + (obj_qw * sensor_z) + (obj_qi * sensor_y);
	const GEN_FLT x6 = 2 * ((x0 * obj_qk) + (-1 * x5 * obj_qi));
	const GEN_FLT x7 = x6 + obj_py + sensor_y;
	const GEN_FLT x8 = x7 * lh_qi;
	const GEN_FLT x9 = 2 * ((x5 * obj_qj) + (-1 * x1 * obj_qk));
	const GEN_FLT x10 = x9 + obj_px + sensor_x;
	const GEN_FLT x11 = x10 * lh_qj;
	const GEN_FLT x12 = (-1 * x11) + x4 + x8;
	const GEN_FLT x13 = x10 * lh_qw;
	const GEN_FLT x14 = x3 * lh_qj;
	const GEN_FLT x15 = x7 * lh_qk;
	const GEN_FLT x16 = (-1 * x15) + x13 + x14;
	const GEN_FLT x17 = x7 + lh_py + (2 * ((x16 * lh_qk) + (-1 * x12 * lh_qi)));
	const GEN_FLT x18 = 0.523598775598299 + tilt_0;
	const GEN_FLT x19 = cos(x18);
	const GEN_FLT x20 = 1. / x19;
	const GEN_FLT x21 = x17 * x17;
	const GEN_FLT x22 = x7 * lh_qw;
	const GEN_FLT x23 = x10 * lh_qk;
	const GEN_FLT x24 = x3 * lh_qi;
	const GEN_FLT x25 = (-1 * x24) + x22 + x23;
	const GEN_FLT x26 = x3 + lh_pz + (2 * ((x25 * lh_qi) + (-1 * x16 * lh_qj)));
	const GEN_FLT x27 = x10 + lh_px + (2 * ((x12 * lh_qj) + (-1 * x25 * lh_qk)));
	const GEN_FLT x28 = x27 * x27;
	const GEN_FLT x29 = x28 + (x26 * x26);
	const GEN_FLT x30 = x29 + x21;
	const GEN_FLT x31 = (1. / sqrt(x30)) * x20;
	const GEN_FLT x32 = asin(x31 * x17);
	const GEN_FLT x33 = 8.0108022e-06 * x32;
	const GEN_FLT x34 = -8.0108022e-06 + (-1 * x33);
	const GEN_FLT x35 = 0.0028679863 + (x32 * x34);
	const GEN_FLT x36 = 5.3685255e-06 + (x32 * x35);
	const GEN_FLT x37 = 0.0076069798 + (x32 * x36);
	const GEN_FLT x38 = x32 * x37;
	const GEN_FLT x39 = -8.0108022e-06 + (-1.60216044e-05 * x32);
	const GEN_FLT x40 = x35 + (x32 * x39);
	const GEN_FLT x41 = x36 + (x40 * x32);
	const GEN_FLT x42 = x37 + (x41 * x32);
	const GEN_FLT x43 = (x42 * x32) + x38;
	const GEN_FLT x44 = sin(x18);
	const GEN_FLT x45 = atan2(-1 * x26, x27);
	const GEN_FLT x46 = tan(x18);
	const GEN_FLT x47 = x46 * (1. / sqrt(x29));
	const GEN_FLT x48 = x47 * x17;
	const GEN_FLT x49 = (-1 * asin(x48)) + ogeeMag_0 + x45;
	const GEN_FLT x50 = (sin(x49) * ogeePhase_0) + curve_0;
	const GEN_FLT x51 = x50 * x44;
	const GEN_FLT x52 = x19 + (-1 * x51 * x43);
	const GEN_FLT x53 = 1. / x52;
	const GEN_FLT x54 = x32 * x32;
	const GEN_FLT x55 = x50 * x54;
	const GEN_FLT x56 = x53 * x55;
	const GEN_FLT x57 = x48 + (x56 * x37);
	const GEN_FLT x58 = 1. / sqrt(1 + (-1 * (x57 * x57)));
	const GEN_FLT x59 = x27 * x17;
	const GEN_FLT x60 = x46 * (1. / (x29 * sqrt(x29)));
	const GEN_FLT x61 = x60 * x59;
	const GEN_FLT x62 = 1. / sqrt(1 + (-1 * (1. / x30) * x21 * (1. / (x19 * x19))));
	const GEN_FLT x63 = (1. / (x30 * sqrt(x30))) * x20;
	const GEN_FLT x64 = x63 * x59;
	const GEN_FLT x65 = x64 * x62;
	const GEN_FLT x66 = -1 * x65 * x34;
	const GEN_FLT x67 = 2.40324066e-05 * x32;
	const GEN_FLT x68 = x62 * x35;
	const GEN_FLT x69 = (-1 * x64 * x68) + (x32 * (x66 + (x65 * x33)));
	const GEN_FLT x70 = (x69 * x32) + (-1 * x65 * x36);
	const GEN_FLT x71 = x62 * x42;
	const GEN_FLT x72 = 1. / x29;
	const GEN_FLT x73 = 1. / sqrt(1 + (-1 * x72 * (x46 * x46) * x21));
	const GEN_FLT x74 = x72 * x26;
	const GEN_FLT x75 = x74 + (x73 * x61);
	const GEN_FLT x76 = cos(x49) * ogeePhase_0;
	const GEN_FLT x77 = x43 * x44;
	const GEN_FLT x78 = x77 * x76;
	const GEN_FLT x79 = (1. / (x52 * x52)) * x55 * x37;
	const GEN_FLT x80 = x54 * x53 * x37;
	const GEN_FLT x81 = x80 * x76;
	const GEN_FLT x82 = 2 * x17;
	const GEN_FLT x83 = x50 * x53 * x38;
	const GEN_FLT x84 = x83 * x62;
	const GEN_FLT x85 =
		x58 * ((-1 * x82 * x84 * x63 * x27) + (x81 * x75) + (x70 * x56) + (-1 * x61) +
			   (-1 * x79 *
				((-1 * x78 * x75) +
				 (-1 * x51 *
				  ((x70 * x32) +
				   (x32 * (x70 + (-1 * x65 * x41) +
						   (x32 * ((x32 * ((x67 * x65) + x66 + (-1 * x65 * x39))) + x69 + (-1 * x65 * x40))))) +
				   (-1 * x65 * x37) + (-1 * x71 * x64))))));
	const GEN_FLT x86 = cos((-1 * asin(x57)) + gibPhase_0 + x45) * gibMag_0;
	const GEN_FLT x87 = x62 * (x31 + (-1 * x63 * x21));
	const GEN_FLT x88 = x87 * x34;
	const GEN_FLT x89 = (x87 * x35) + (x32 * (x88 + (-1 * x87 * x33)));
	const GEN_FLT x90 = (x89 * x32) + (x87 * x36);
	const GEN_FLT x91 = x73 * x47;
	const GEN_FLT x92 = 2 * x83;
	const GEN_FLT x93 =
		x58 *
		((-1 * x79 *
		  ((x78 * x91) + (-1 * x51 *
						  ((x87 * x37) + (x90 * x32) + (x87 * x42) +
						   (x32 * (x90 + (x87 * x41) +
								   (x32 * (x89 + (x32 * (x88 + (-1 * x87 * x67) + (x87 * x39))) + (x87 * x40))))))))) +
		 (x87 * x92) + (-1 * x81 * x91) + x47 + (x56 * x90));
	const GEN_FLT x94 = x63 * x17;
	const GEN_FLT x95 = x94 * x26;
	const GEN_FLT x96 = x62 * x95;
	const GEN_FLT x97 = -1 * x96 * x34;
	const GEN_FLT x98 = (-1 * x68 * x95) + (x32 * (x97 + (x96 * x33)));
	const GEN_FLT x99 = (x98 * x32) + (-1 * x96 * x36);
	const GEN_FLT x100 = 2 * x26;
	const GEN_FLT x101 = x60 * x17;
	const GEN_FLT x102 = x26 * x101;
	const GEN_FLT x103 = x72 * x27;
	const GEN_FLT x104 = -1 * x103;
	const GEN_FLT x105 = x104 + (x73 * x102);
	const GEN_FLT x106 =
		x58 * ((-1 * x102) + (x81 * x105) +
			   (-1 * x79 *
				((-1 * x78 * x105) +
				 (-1 * x51 *
				  ((-1 * x71 * x95) + (x99 * x32) + (-1 * x96 * x37) +
				   (x32 * (x99 + (-1 * x96 * x41) +
						   (x32 * ((x32 * ((x67 * x96) + x97 + (-1 * x96 * x39))) + x98 + (-1 * x96 * x40))))))))) +
			   (x56 * x99) + (-1 * x84 * x94 * x100));
	const GEN_FLT x107 = 2 * x24;
	const GEN_FLT x108 = (2 * x23) + (-1 * x107);
	const GEN_FLT x109 = 2 * x15;
	const GEN_FLT x110 = (2 * x14) + (-1 * x109);
	const GEN_FLT x111 = 2 * x27;
	const GEN_FLT x112 = 2 * x11;
	const GEN_FLT x113 = (2 * x8) + (-1 * x112);
	const GEN_FLT x114 = (x100 * x113) + (x110 * x111);
	const GEN_FLT x115 = 1.0 / 2.0 * x94;
	const GEN_FLT x116 = x62 * ((x31 * x108) + (-1 * x115 * (x114 + (x82 * x108))));
	const GEN_FLT x117 = 1.0 / 2.0 * x101;
	const GEN_FLT x118 = (-1 * x114 * x117) + (x47 * x108);
	const GEN_FLT x119 = 1. / x27;
	const GEN_FLT x120 = (1. / x28) * x26;
	const GEN_FLT x121 = x72 * x28;
	const GEN_FLT x122 = ((x110 * x120) + (-1 * x113 * x119)) * x121;
	const GEN_FLT x123 = x122 + (-1 * x73 * x118);
	const GEN_FLT x124 = x34 * x116;
	const GEN_FLT x125 = (x35 * x116) + (x32 * (x124 + (-1 * x33 * x116)));
	const GEN_FLT x126 = (x32 * x125) + (x36 * x116);
	const GEN_FLT x127 =
		x58 * (x118 + (x56 * x126) +
			   (-1 * x79 *
				((-1 * x78 * x123) +
				 (-1 * x51 *
				  ((x37 * x116) + (x32 * x126) + (x42 * x116) +
				   (x32 * ((x41 * x116) + x126 +
						   (x32 * ((x32 * ((-1 * x67 * x116) + x124 + (x39 * x116))) + x125 + (x40 * x116))))))))) +
			   (x92 * x116) + (x81 * x123));
	const GEN_FLT x128 = 2 * x4;
	const GEN_FLT x129 = (-4 * x8) + x112 + (-1 * x128);
	const GEN_FLT x130 = (-1 * obj_pz) + (-1 * sensor_z) + (-1 * x2);
	const GEN_FLT x131 = 2 * lh_qk;
	const GEN_FLT x132 = (2 * x7 * lh_qj) + (-1 * x130 * x131);
	const GEN_FLT x133 = 2 * x22;
	const GEN_FLT x134 = 2 * lh_qi;
	const GEN_FLT x135 = x108 + x133 + (x130 * x134);
	const GEN_FLT x136 = (x100 * x135) + (x111 * x132);
	const GEN_FLT x137 = (-1 * x117 * x136) + (x47 * x129);
	const GEN_FLT x138 = ((x120 * x132) + (-1 * x119 * x135)) * x121;
	const GEN_FLT x139 = x138 + (-1 * x73 * x137);
	const GEN_FLT x140 = x62 * ((x31 * x129) + (-1 * x115 * (x136 + (x82 * x129))));
	const GEN_FLT x141 = x34 * x140;
	const GEN_FLT x142 = (x35 * x140) + (x32 * (x141 + (-1 * x33 * x140)));
	const GEN_FLT x143 = (x32 * x142) + (x36 * x140);
	const GEN_FLT x144 =
		x58 * (x137 +
			   (-1 * x79 *
				((-1 * x78 * x139) +
				 (-1 * x51 *
				  ((x37 * x140) + (x42 * x140) + (x32 * x143) +
				   (x32 * (x143 + (x41 * x140) +
						   (x32 * (x142 + (x32 * ((-1 * x67 * x140) + x141 + (x39 * x140))) + (x40 * x140))))))))) +
			   (x56 * x143) + (x81 * x139) + (x92 * x140));
	const GEN_FLT x145 = 2 * x13;
	const GEN_FLT x146 = (-4 * x14) + (-1 * x145) + x109;
	const GEN_FLT x147 = 2 * ((-1 * sensor_x) + (-1 * obj_px) + (-1 * x9));
	const GEN_FLT x148 = x113 + (x147 * lh_qj) + x128;
	const GEN_FLT x149 = ((x120 * x148) + (-1 * x119 * x146)) * x121;
	const GEN_FLT x150 = (x3 * x131) + (-1 * x147 * lh_qi);
	const GEN_FLT x151 = (x100 * x146) + (x111 * x148);
	const GEN_FLT x152 = x62 * ((x31 * x150) + (-1 * x115 * (x151 + (x82 * x150))));
	const GEN_FLT x153 = x34 * x152;
	const GEN_FLT x154 = (x35 * x152) + (x32 * (x153 + (-1 * x33 * x152)));
	const GEN_FLT x155 = (x32 * x154) + (x36 * x152);
	const GEN_FLT x156 = (-1 * x117 * x151) + (x47 * x150);
	const GEN_FLT x157 = x149 + (-1 * x73 * x156);
	const GEN_FLT x158 =
		x58 * (x156 + (x81 * x157) + (x56 * x155) +
			   (-1 * x79 *
				((-1 * x78 * x157) +
				 (-1 * x51 *
				  ((x42 * x152) + (x32 * x155) +
				   (x32 * (x155 + (x41 * x152) +
						   (x32 * ((x32 * ((-1 * x67 * x152) + x153 + (x39 * x152))) + x154 + (x40 * x152))))) +
				   (x37 * x152))))) +
			   (x92 * x152));
	const GEN_FLT x159 = 2 * ((-1 * obj_py) + (-1 * sensor_y) + (-1 * x6));
	const GEN_FLT x160 = (x10 * x134) + (-1 * x159 * lh_qj);
	const GEN_FLT x161 = (-4 * x23) + (-1 * x133) + x107;
	const GEN_FLT x162 = ((x120 * x161) + (-1 * x119 * x160)) * x121;
	const GEN_FLT x163 = x110 + x145 + (x159 * lh_qk);
	const GEN_FLT x164 = (x100 * x160) + (x111 * x161);
	const GEN_FLT x165 = x62 * ((x31 * x163) + (-1 * x115 * (x164 + (x82 * x163))));
	const GEN_FLT x166 = (-1 * x117 * x164) + (x47 * x163);
	const GEN_FLT x167 = x76 * (x162 + (-1 * x73 * x166));
	const GEN_FLT x168 = x34 * x165;
	const GEN_FLT x169 = (x35 * x165) + (x32 * (x168 + (-1 * x33 * x165)));
	const GEN_FLT x170 = (x32 * x169) + (x36 * x165);
	const GEN_FLT x171 =
		x58 * (x166 + (x56 * x170) +
			   (-1 * x79 *
				((-1 * x77 * x167) +
				 (-1 * x51 *
				  ((x32 * x170) + (x37 * x165) +
				   (x32 * (x170 + (x41 * x165) +
						   (x32 * (x169 + (x32 * ((-1 * x67 * x165) + x168 + (x39 * x165))) + (x40 * x165))))) +
				   (x42 * x165))))) +
			   (x92 * x165) + (x80 * x167));
	out[0] = (-1 * x85) + (-1 * ((-1 * x74) + x85) * x86) + x74;
	out[1] = (-1 * x86 * x93) + (-1 * x93);
	out[2] = (-1 * (x103 + x106) * x86) + (-1 * x106) + x104;
	out[3] = (-1 * ((-1 * x122) + x127) * x86) + (-1 * x127) + x122;
	out[4] = (-1 * ((-1 * x138) + x144) * x86) + (-1 * x144) + x138;
	out[5] = (-1 * ((-1 * x149) + x158) * x86) + x149 + (-1 * x158);
	out[6] = (-1 * ((-1 * x162) + x171) * x86) + x162 + (-1 * x171);
}

// Jacobian of reproject_axis_x_gen2 wrt [phase_0, tilt_0, curve_0, gibPhase_0, gibMag_0, ogeeMag_0, ogeePhase_0]
static inline void gen_reproject_axis_x_gen2_jac_bsc0(FLT *out, const SurvivePose *obj_p, const FLT *sensor_pt,
													  const SurvivePose *lh_p, const BaseStationCal *bsc0) {
	const GEN_FLT obj_px = (*obj_p).Pos[0];
	const GEN_FLT obj_py = (*obj_p).Pos[1];
	const GEN_FLT obj_pz = (*obj_p).Pos[2];
	const GEN_FLT obj_qw = (*obj_p).Rot[0];
	const GEN_FLT obj_qi = (*obj_p).Rot[1];
	const GEN_FLT obj_qj = (*obj_p).Rot[2];
	const GEN_FLT obj_qk = (*obj_p).Rot[3];
	const GEN_FLT sensor_x = sensor_pt[0];
	const GEN_FLT sensor_y = sensor_pt[1];
	const GEN_FLT sensor_z = sensor_pt[2];
	const GEN_FLT lh_px = (*lh_p).Pos[0];
	const GEN_FLT lh_py = (*lh_p).Pos[1];
	const GEN_FLT lh_pz = (*lh_p).Pos[2];
	const GEN_FLT lh_qw = (*lh_p).Rot[0];
	const GEN_FLT lh_qi = (*lh_p).Rot[1];
	const GEN_FLT lh_qj = (*lh_p).Rot[2];
	const GEN_FLT lh_qk = (*lh_p).Rot[3];
	const GEN_FLT phase_0 = (*bsc0).phase;
	const GEN_FLT tilt_0 = (*bsc0).tilt;
	const GEN_FLT curve_0 = (*bsc0).curve;
	const GEN_FLT gibPhase_0 = (*bsc0).gibpha;
	const GEN_FLT gibMag_0 = (*bsc0).gibmag;
	const GEN_FLT ogeeMag_0 = (*bsc0).ogeephase;
	const GEN_FLT ogeePhase_0 = (*bsc0).ogeemag;
	const GEN_FLT x0 = (obj_qk * sensor_x) + (-1 * obj_qi * sensor_z) + (obj_qw * sensor_y);
	const GEN_FLT x1 = (-1 * obj_qj * sensor_x) + (obj_qw * sensor_z) + (obj_qi * sensor_y);
	const GEN_FLT x2 = (2 * ((x1 * obj_qj) + (-1 * x0 * obj_qk))) + obj_px + sensor_x;
	const GEN_FLT x3 = (obj_qw * sensor_x) + (-1 * obj_qk * sensor_y) + (obj_qj * sensor_z);
	const GEN_FLT x4 = (2 * ((x0 * obj_qi) + (-1 * x3 * obj_qj))) + obj_pz + sensor_z;
	const GEN_FLT x5 = obj_py + (2 * ((x3 * obj_qk) + (-1 * x1 * obj_qi))) + sensor_y;
	const GEN_FLT x6 = (-1 * x5 * lh_qk) + (x2 * lh_qw) + (x4 * lh_qj);
	const GEN_FLT x7 = (x5 * lh_qw) + (-1 * x4 * lh_qi) + (x2 * lh_qk);
	const GEN_FLT x8 = x4 + lh_pz + (2 * ((x7 * lh_qi) + (-1 * x6 * lh_qj)));
	const GEN_FLT x9 = (x4 * lh_qw) + (-1 * x2 * lh_qj) + (x5 * lh_qi);
	const GEN_FLT x10 = lh_px + x2 + (2 * ((x9 * lh_qj) + (-1 * x7 * lh_qk)));
	const GEN_FLT x11 = atan2(-1 * x8, x10);
	const GEN_FLT x12 = 0.523598775598299 + tilt_0;
	const GEN_FLT x13 = tan(x12);
	const GEN_FLT x14 = (x10 * x10) + (x8 * x8);
	const GEN_FLT x15 = x5 + lh_py + (2 * ((x6 * lh_qk) + (-1 * x9 * lh_qi)));
	const GEN_FLT x16 = x15 * (1. / sqrt(x14));
	const GEN_FLT x17 = x13 * x16;
	const GEN_FLT x18 = (-1 * asin(x17)) + ogeeMag_0 + x11;
	const GEN_FLT x19 = sin(x18);
	const GEN_FLT x20 = (x19 * ogeePhase_0) + curve_0;
	const GEN_FLT x21 = cos(x12);
	const GEN_FLT x22 = x15 * x15;
	const GEN_FLT x23 = x14 + x22;
	const GEN_FLT x24 = (1. / sqrt(x23)) * x15;
	const GEN_FLT x25 = asin(x24 * (1. / x21));
	const GEN_FLT x26 = 8.0108022e-06 * x25;
	const GEN_FLT x27 = -8.0108022e-06 + (-1 * x26);
	const GEN_FLT x28 = 0.0028679863 + (x25 * x27);
	const GEN_FLT x29 = 5.3685255e-06 + (x25 * x28);
	const GEN_FLT x30 = 0.0076069798 + (x25 * x29);
	const GEN_FLT x31 = sin(x12);
	const GEN_FLT x32 = x30 * x25;
	const GEN_FLT x33 = -8.0108022e-06 + (-1.60216044e-05 * x25);
	const GEN_FLT x34 = x28 + (x33 * x25);
	const GEN_FLT x35 = x29 + (x34 * x25);
	const GEN_FLT x36 = x30 + (x35 * x25);
	const GEN_FLT x37 = (x36 * x25) + x32;
	const GEN_FLT x38 = x37 * x20;
	const GEN_FLT x39 = x31 * x38;
	const GEN_FLT x40 = x21 + (-1 * x39);
	const GEN_FLT x41 = 1. / x40;
	const GEN_FLT x42 = x25 * x25;
	const GEN_FLT x43 = x41 * x42;
	const GEN_FLT x44 = x43 * x30;
	const GEN_FLT x45 = x17 + (x44 * x20);
	const GEN_FLT x46 = 1. / sqrt(1 + (-1 * (x45 * x45)));
	const GEN_FLT x47 = x13 * x13;
	const GEN_FLT x48 = x16 * (1 + x47);
	const GEN_FLT x49 = 1. / (x21 * x21);
	const GEN_FLT x50 = x49 * x24 * (1. / sqrt(1 + (-1 * x49 * x22 * (1. / x23))));
	const GEN_FLT x51 = x50 * x31;
	const GEN_FLT x52 = x51 * x27;
	const GEN_FLT x53 = (x51 * x28) + (x25 * (x52 + (-1 * x51 * x26)));
	const GEN_FLT x54 = (x53 * x25) + (x51 * x29);
	const GEN_FLT x55 = x31 * x20;
	const GEN_FLT x56 = cos(x18) * ogeePhase_0;
	const GEN_FLT x57 = x48 * (1. / sqrt(1 + (-1 * x47 * x22 * (1. / x14))));
	const GEN_FLT x58 = (1. / (x40 * x40)) * x42 * x30;
	const GEN_FLT x59 = x56 * x44;
	const GEN_FLT x60 =
		x46 * (x48 + (2 * x50 * x55 * x41 * x32) + (-1 * x57 * x59) + (x54 * x43 * x20) +
			   (-1 * x58 * x20 *
				((x57 * x56 * x31 * x37) +
				 (-1 * x55 *
				  ((x54 * x25) +
				   (x25 * (x54 + (x51 * x35) +
						   (x25 * (x53 + (x25 * ((-2.40324066e-05 * x51 * x25) + x52 + (x51 * x33))) + (x51 * x34))))) +
				   (x51 * x36) + (x51 * x30))) +
				 (-1 * x31) + (-1 * x38 * x21))));
	const GEN_FLT x61 = asin(x45) + (-1 * gibPhase_0) + (-1 * x11);
	const GEN_FLT x62 = cos(x61) * gibMag_0;
	const GEN_FLT x63 = x58 * x39;
	const GEN_FLT x64 = (x63 + x44) * x46;
	const GEN_FLT x65 = x46 * ((x63 * x56) + x59);
	const GEN_FLT x66 = ((x63 * x19) + (x44 * x19)) * x46;
	out[0] = -1;
	out[1] = (-1 * x60 * x62) + (-1 * x60);
	out[2] = (-1 * x64 * x62) + (-1 * x64);
	out[3] = x62;
	out[4] = -1 * sin(x61);
	out[5] = (-1 * x62 * x65) + (-1 * x65);
	out[6] = (-1 * x62 * x66) + (-1 * x66);
}

static inline FLT gen_reproject_axis_y_gen2(const SurvivePose *obj_p, const FLT *sensor_pt, const SurvivePose *lh_p,
											const BaseStationCal *bsc1) {
	const GEN_FLT obj_px = (*obj_p).Pos[0];
	const GEN_FLT obj_py = (*obj_p).Pos[1];
	const GEN_FLT obj_pz = (*obj_p).Pos[2];
	const GEN_FLT obj_qw = (*obj_p).Rot[0];
	const GEN_FLT obj_qi = (*obj_p).Rot[1];
	const GEN_FLT obj_qj = (*obj_p).Rot[2];
	const GEN_FLT obj_qk = (*obj_p).Rot[3];
	const GEN_FLT sensor_x = sensor_pt[0];
	const GEN_FLT sensor_y = sensor_pt[1];
	const GEN_FLT sensor_z = sensor_pt[2];
	const GEN_FLT lh_px = (*lh_p).Pos[0];
	const GEN_FLT lh_py = (*lh_p).Pos[1];
	const GEN_FLT lh_pz = (*lh_p).Pos[2];
	const GEN_FLT lh_qw = (*lh_p).Rot[0];
	const GEN_FLT lh_qi = (*lh_p).Rot[1];
	const GEN_FLT lh_qj = (*lh_p).Rot[2];
	const GEN_FLT lh_qk = (*lh_p).Rot[3];
	const GEN_FLT phase_1 = (*bsc1).phase;
	const GEN_FLT tilt_1 = (*bsc1).tilt;
	const GEN_FLT curve_1 = (*bsc1).curve;
	const GEN_FLT gibPhase_1 = (*bsc1).gibpha;
	const GEN_FLT gibMag_1 = (*bsc1).gibmag;
	const GEN_FLT ogeeMag_1 = (*bsc1).ogeephase;
	const GEN_FLT ogeePhase_1 = (*bsc1).ogeemag;
	const GEN_FLT x0 = (obj_qk * sensor_x) + (-1 * obj_qi * sensor_z) + (obj_qw * sensor_y);
	const GEN_FLT x1 = (-1 * obj_qj * sensor_x) + (obj_qw * sensor_z) + (obj_qi * sensor_y);
	const GEN_FLT x2 = (2 * ((x1 * obj_qj) + (-1 * x0 * obj_qk))) + obj_px + sensor_x;
	const GEN_FLT x3 = (obj_qw * sensor_x) + (-1 * obj_qk * sensor_y) + (obj_qj * sensor_z);
	const GEN_FLT x4 = (2 * ((x0 * obj_qi) + (-1 * x3 * obj_qj))) + obj_pz + sensor_z;
	const GEN_FLT x5 = obj_py + (2 * ((x3 * obj_qk) + (-1 * x1 * obj_qi))) + sensor_y;
	const GEN_FLT x6 = (-1 * x5 * lh_qk) + (x2 * lh_qw) + (x4 * lh_qj);
	const GEN_FLT x7 = (x5 * lh_qw) + (-1 * x4 * lh_qi) + (x2 * lh_qk);
	const GEN_FLT x8 = x4 + lh_pz + (2 * ((x7 * lh_qi) + (-1 * x6 * lh_qj)));
	const GEN_FLT x9 = (x4 * lh_qw) + (-1 * x2 * lh_qj) + (x5 * lh_qi);
	const GEN_FLT x10 = lh_px + x2 + (2 * ((x9 * lh_qj) + (-1 * x7 * lh_qk)));
	const GEN_FLT x11 = atan2(-1 * x8, x10);
	const GEN_FLT x12 = 0.523598775598299 + (-1 * tilt_1);
	const GEN_FLT x13 = cos(x12);
	const GEN_FLT x14 = x5 + lh_py + (2 * ((x6 * lh_qk) + (-1 * x9 * lh_qi)));
	const GEN_FLT x15 = (x10 * x10) + (x8 * x8);
	const GEN_FLT x16 = asin(x14 * (1. / x13) * (1. / sqrt(x15 + (x14 * x14))));
	const GEN_FLT x17 = 0.0028679863 + (x16 * (-8.0108022e-06 + (-8.0108022e-06 * x16)));
	const GEN_FLT x18 = 5.3685255e-06 + (x17 * x16);
	const GEN_FLT x19 = 0.0076069798 + (x18 * x16);
	const GEN_FLT x20 = -1 * (1. / sqrt(x15)) * x14 * tan(x12);
	const GEN_FLT x21 = (sin((-1 * asin(x20)) + ogeeMag_1 + x11) * ogeePhase_1) + curve_1;
	const GEN_FLT x22 =
		(-1 *
		 asin(x20 + (x21 * x19 * (x16 * x16) *
					 (1. / (x13 + (x21 * sin(x12) *
								   ((x16 * (x19 + (x16 * (x18 + (x16 * (x17 + (x16 * (-8.0108022e-06 +
																					  (-1.60216044e-05 * x16))))))))) +
									(x19 * x16)))))))) +
		x11;
	return -1.5707963267949 + x22 + (-1 * phase_1) + (sin(x22 + gibPhase_1) * gibMag_1);
}

// Jacobian of reproject_axis_y_gen2 wrt [obj_px, obj_py, obj_pz, obj_qw, obj_qi, obj_qj, obj_qk]
static inline void gen_reproject_axis_y_gen2_jac_obj_p(FLT *out, const SurvivePose *obj_p, const FLT *sensor_pt,
													   const SurvivePose *lh_p, const BaseStationCal *bsc1) {
	const GEN_FLT obj_px = (*obj_p).Pos[0];
	const GEN_FLT obj_py = (*obj_p).Pos[1];
	const GEN_FLT obj_pz = (*obj_p).Pos[2];
	const GEN_FLT obj_qw = (*obj_p).Rot[0];
	const GEN_FLT obj_qi = (*obj_p).Rot[1];
	const GEN_FLT obj_qj = (*obj_p).Rot[2];
	const GEN_FLT obj_qk = (*obj_p).Rot[3];
	const GEN_FLT sensor_x = sensor_pt[0];
	const GEN_FLT sensor_y = sensor_pt[1];
	const GEN_FLT sensor_z = sensor_pt[2];
	const GEN_FLT lh_px = (*lh_p).Pos[0];
	const GEN_FLT lh_py = (*lh_p).Pos[1];
	const GEN_FLT lh_pz = (*lh_p).Pos[2];
	const GEN_FLT lh_qw = (*lh_p).Rot[0];
	const GEN_FLT lh_qi = (*lh_p).Rot[1];
	const GEN_FLT lh_qj = (*lh_p).Rot[2];
	const GEN_FLT lh_qk = (*lh_p).Rot[3];
	const GEN_FLT phase_1 = (*bsc1).phase;
	const GEN_FLT tilt_1 = (*bsc1).tilt;
	const GEN_FLT curve_1 = (*bsc1).curve;
	const GEN_FLT gibPhase_1 = (*bsc1).gibpha;
	const GEN_FLT gibMag_1 = (*bsc1).gibmag;
	const GEN_FLT ogeeMag_1 = (*bsc1).ogeephase;
	const GEN_FLT ogeePhase_1 = (*bsc1).ogeemag;
	const GEN_FLT x0 = obj_qw * sensor_x;
	const GEN_FLT x1 = obj_qj * sensor_z;
	const GEN_FLT x2 = obj_qk * sensor_y;
	const GEN_FLT x3 = (-1 * x2) + x0 + x1;
	const GEN_FLT x4 = obj_qk * sensor_x;
	const GEN_FLT x5 = obj_qw * sensor_y;
	const GEN_FLT x6 = obj_qi * sensor_z;
	const GEN_FLT x7 = (-1 * x6) + x4 + x5;
	const GEN_FLT x8 = (2 * ((x7 * obj_qi) + (-1 * x3 * obj_qj))) + obj_pz + sensor_z;
	const GEN_FLT x9 = obj_qw * sensor_z;
	const GEN_FLT x10 = obj_qi * sensor_y;
	const GEN_FLT x11 = obj_qj * sensor_x;
	const GEN_FLT x12 = (-1 * x11) + x9 + x10;
	const GEN_FLT x13 = (2 * ((x3 * obj_qk) + (-1 * x12 * obj_qi))) + obj_py + sensor_y;
	const GEN_FLT x14 = (2 * ((x12 * obj_qj) + (-1 * x7 * obj_qk))) + obj_px + sensor_x;
	const GEN_FLT x15 = (-1 * x14 * lh_qj) + (x8 * lh_qw) + (x13 * lh_qi);
	const GEN_FLT x16 = (-1 * x13 * lh_qk) + (x14 * lh_qw) + (x8 * lh_qj);
	const GEN_FLT x17 = x13 + lh_py + (2 * ((x16 * lh_qk) + (-1 * x15 * lh_qi)));
	const GEN_FLT x18 = 0.523598775598299 + (-1 * tilt_1);
	const GEN_FLT x19 = cos(x18);
	const GEN_FLT x20 = 1. / x19;
	const GEN_FLT x21 = x17 * x17;
	const GEN_FLT x22 = (-1 * x8 * lh_qi) + (x13 * lh_qw) + (x14 * lh_qk);
	const GEN_FLT x23 = x8 + lh_pz + (2 * ((x22 * lh_qi) + (-1 * x16 * lh_qj)));
	const GEN_FLT x24 = lh_px + x14 + (2 * ((x15 * lh_qj) + (-1 * x22 * lh_qk)));
	const GEN_FLT x25 = x24 * x24;
	const GEN_FLT x26 = x25 + (x23 * x23);
	const GEN_FLT x27 = x26 + x21;
	const GEN_FLT x28 = x20 * (1. / sqrt(x27));
	const GEN_FLT x29 = asin(x28 * x17);
	const GEN_FLT x30 = -8.0108022e-06 + (-1.60216044e-05 * x29);
	const GEN_FLT x31 = 8.0108022e-06 * x29;
	const GEN_FLT x32 = -8.0108022e-06 + (-1 * x31);
	const GEN_FLT x33 = 0.0028679863 + (x32 * x29);
	const GEN_FLT x34 = x33 + (x30 * x29);
	const GEN_FLT x35 = 5.3685255e-06 + (x33 * x29);
	const GEN_FLT x36 = x35 + (x34 * x29);
	const GEN_FLT x37 = 0.0076069798 + (x35 * x29);
	const GEN_FLT x38 = x37 + (x36 * x29);
	const GEN_FLT x39 = 1. / sqrt(1 + (-1 * x21 * (1. / x27) * (1. / (x19 * x19))));
	const GEN_FLT x40 = 2 * lh_qj;
	const GEN_FLT x41 = x40 * lh_qi;
	const GEN_FLT x42 = 2 * lh_qk;
	const GEN_FLT x43 = x42 * lh_qw;
	const GEN_FLT x44 = x43 + x41;
	const GEN_FLT x45 = 2 * x17;
	const GEN_FLT x46 = -2 * (lh_qk * lh_qk);
	const GEN_FLT x47 = -2 * (lh_qj * lh_qj);
	const GEN_FLT x48 = 1 + x47 + x46;
	const GEN_FLT x49 = 2 * x24;
	const GEN_FLT x50 = 2 * lh_qw;
	const GEN_FLT x51 = x50 * lh_qj;
	const GEN_FLT x52 = x42 * lh_qi;
	const GEN_FLT x53 = x52 + (-1 * x51);
	const GEN_FLT x54 = 2 * x23;
	const GEN_FLT x55 = (x54 * x53) + (x48 * x49);
	const GEN_FLT x56 = 1.0 / 2.0 * x17;
	const GEN_FLT x57 = x56 * x20 * (1. / (x27 * sqrt(x27)));
	const GEN_FLT x58 = x39 * ((x44 * x28) + (-1 * x57 * (x55 + (x44 * x45))));
	const GEN_FLT x59 = x58 * x32;
	const GEN_FLT x60 = 2.40324066e-05 * x29;
	const GEN_FLT x61 = (x58 * x33) + (x29 * (x59 + (-1 * x58 * x31)));
	const GEN_FLT x62 = (x58 * x35) + (x61 * x29);
	const GEN_FLT x63 = sin(x18);
	const GEN_FLT x64 = atan2(-1 * x23, x24);
	const GEN_FLT x65 = tan(x18);
	const GEN_FLT x66 = x65 * (1. / sqrt(x26));
	const GEN_FLT x67 = -1 * x66 * x17;
	const GEN_FLT x68 = (-1 * asin(x67)) + ogeeMag_1 + x64;
	const GEN_FLT x69 = (sin(x68) * ogeePhase_1) + curve_1;
	const GEN_FLT x70 = x63 * x69;
	const GEN_FLT x71 = 1. / x26;
	const GEN_FLT x72 = 1. / sqrt(1 + (-1 * x71 * (x65 * x65) * x21));
	const GEN_FLT x73 = x65 * x56 * (1. / (x26 * sqrt(x26)));
	const GEN_FLT x74 = (x73 * x55) + (-1 * x66 * x44);
	const GEN_FLT x75 = 1. / x24;
	const GEN_FLT x76 = (1. / x25) * x23;
	const GEN_FLT x77 = x71 * x25;
	const GEN_FLT x78 = ((x76 * x48) + (-1 * x75 * x53)) * x77;
	const GEN_FLT x79 = x78 + (-1 * x72 * x74);
	const GEN_FLT x80 = cos(x68) * ogeePhase_1;
	const GEN_FLT x81 = x37 * x29;
	const GEN_FLT x82 = (x38 * x29) + x81;
	const GEN_FLT x83 = x82 * x63;
	const GEN_FLT x84 = x80 * x83;
	const GEN_FLT x85 = x19 + (x82 * x70);
	const GEN_FLT x86 = x29 * x29;
	const GEN_FLT x87 = x86 * x69;
	const GEN_FLT x88 = (1. / (x85 * x85)) * x87 * x37;
	const GEN_FLT x89 = 1. / x85;
	const GEN_FLT x90 = x89 * x87;
	const GEN_FLT x91 = 2 * x81 * x89 * x69;
	const GEN_FLT x92 = x89 * x86 * x37;
	const GEN_FLT x93 = x80 * x92;
	const GEN_FLT x94 = x67 + (x90 * x37);
	const GEN_FLT x95 = 1. / sqrt(1 + (-1 * (x94 * x94)));
	const GEN_FLT x96 =
		x78 + (-1 * x95 *
			   (x74 + (x79 * x93) + (x58 * x91) +
				(-1 * x88 *
				 ((x84 * x79) +
				  (x70 * ((x62 * x29) +
						  (x29 * (x62 + (x29 * (x61 + (x58 * x34) + (x29 * (x59 + (-1 * x60 * x58) + (x58 * x30))))) +
								  (x58 * x36))) +
						  (x58 * x38) + (x58 * x37))))) +
				(x62 * x90)));
	const GEN_FLT x97 = cos((-1 * asin(x94)) + gibPhase_1 + x64) * gibMag_1;
	const GEN_FLT x98 = 1 + (-2 * (lh_qi * lh_qi));
	const GEN_FLT x99 = x98 + x46;
	const GEN_FLT x100 = x41 + (-1 * x43);
	const GEN_FLT x101 = x42 * lh_qj;
	const GEN_FLT x102 = x50 * lh_qi;
	const GEN_FLT x103 = x102 + x101;
	const GEN_FLT x104 = (x54 * x103) + (x49 * x100);
	const GEN_FLT x105 = x39 * ((x99 * x28) + (-1 * x57 * (x104 + (x99 * x45))));
	const GEN_FLT x106 = x32 * x105;
	const GEN_FLT x107 = (x33 * x105) + (x29 * (x106 + (-1 * x31 * x105)));
	const GEN_FLT x108 = (x35 * x105) + (x29 * x107);
	const GEN_FLT x109 = (x73 * x104) + (-1 * x66 * x99);
	const GEN_FLT x110 = ((x76 * x100) + (-1 * x75 * x103)) * x77;
	const GEN_FLT x111 = x110 + (-1 * x72 * x109);
	const GEN_FLT x112 =
		x110 +
		(-1 * x95 *
		 ((x93 * x111) + (x90 * x108) + x109 + (x91 * x105) +
		  (-1 * x88 *
		   ((x84 * x111) +
			(x70 * ((x29 * x108) + (x37 * x105) +
					(x29 * (x108 + (x29 * ((x34 * x105) + x107 + (x29 * ((-1 * x60 * x105) + (x30 * x105) + x106)))) +
							(x36 * x105))) +
					(x38 * x105)))))));
	const GEN_FLT x113 = x101 + (-1 * x102);
	const GEN_FLT x114 = x51 + x52;
	const GEN_FLT x115 = x98 + x47;
	const GEN_FLT x116 = (x54 * x115) + (x49 * x114);
	const GEN_FLT x117 = (x28 * x113) + (-1 * x57 * (x116 + (x45 * x113)));
	const GEN_FLT x118 = x39 * x117;
	const GEN_FLT x119 = x32 * x39;
	const GEN_FLT x120 = x119 * x117;
	const GEN_FLT x121 = x30 * x39;
	const GEN_FLT x122 = (x33 * x118) + (x29 * (x120 + (-1 * x31 * x118)));
	const GEN_FLT x123 = x36 * x39;
	const GEN_FLT x124 = (x35 * x118) + (x29 * x122);
	const GEN_FLT x125 = (x73 * x116) + (-1 * x66 * x113);
	const GEN_FLT x126 = ((x76 * x114) + (-1 * x75 * x115)) * x77;
	const GEN_FLT x127 = x126 + (-1 * x72 * x125);
	const GEN_FLT x128 =
		x126 +
		(-1 * x95 *
		 (x125 + (x90 * x124) + (x93 * x127) +
		  (-1 * x88 *
		   ((x84 * x127) +
			(x70 * ((x29 * x124) + (x38 * x118) +
					(x29 * (x124 + (x29 * (x122 + (x34 * x118) + (x29 * ((-1 * x60 * x118) + x120 + (x117 * x121))))) +
							(x117 * x123))) +
					(x37 * x118))))) +
		  (x91 * x118)));
	const GEN_FLT x129 = 2 * x6;
	const GEN_FLT x130 = 2 * x4;
	const GEN_FLT x131 = x130 + (-1 * x129);
	const GEN_FLT x132 = 2 * x2;
	const GEN_FLT x133 = 2 * x1;
	const GEN_FLT x134 = x133 + (-1 * x132);
	const GEN_FLT x135 = 2 * x11;
	const GEN_FLT x136 = 2 * x10;
	const GEN_FLT x137 = x136 + (-1 * x135);
	const GEN_FLT x138 = (x137 * lh_qj) + (-1 * x131 * lh_qk) + (x134 * lh_qw);
	const GEN_FLT x139 = (x131 * lh_qi) + (x137 * lh_qw) + (-1 * x134 * lh_qj);
	const GEN_FLT x140 = 2 * lh_qi;
	const GEN_FLT x141 = x131 + (x42 * x138) + (-1 * x139 * x140);
	const GEN_FLT x142 = (x134 * lh_qk) + (-1 * x137 * lh_qi) + (x131 * lh_qw);
	const GEN_FLT x143 = x134 + (x40 * x139) + (-1 * x42 * x142);
	const GEN_FLT x144 = x137 + (x140 * x142) + (-1 * x40 * x138);
	const GEN_FLT x145 = (x54 * x144) + (x49 * x143);
	const GEN_FLT x146 = x39 * ((x28 * x141) + (-1 * x57 * (x145 + (x45 * x141))));
	const GEN_FLT x147 = x32 * x146;
	const GEN_FLT x148 = (x33 * x146) + (x29 * (x147 + (-1 * x31 * x146)));
	const GEN_FLT x149 = (x35 * x146) + (x29 * x148);
	const GEN_FLT x150 = (x73 * x145) + (-1 * x66 * x141);
	const GEN_FLT x151 = ((x76 * x143) + (-1 * x75 * x144)) * x77;
	const GEN_FLT x152 = x151 + (-1 * x72 * x150);
	const GEN_FLT x153 =
		x151 +
		(-1 * x95 *
		 (x150 + (x93 * x152) + (x90 * x149) + (x91 * x146) +
		  (-1 * x88 *
		   ((x84 * x152) +
			(x70 * ((x29 * x149) + (x37 * x146) +
					(x29 * (x149 + (x29 * (x148 + (x34 * x146) + (x29 * ((-1 * x60 * x146) + x147 + (x30 * x146))))) +
							(x36 * x146))) +
					(x38 * x146)))))));
	const GEN_FLT x154 = 2 * x9;
	const GEN_FLT x155 = (-4 * x10) + x135 + (-1 * x154);
	const GEN_FLT x156 = 2 * obj_qk * sensor_z;
	const GEN_FLT x157 = 2 * obj_qj * sensor_y;
	const GEN_FLT x158 = x157 + x156;
	const GEN_FLT x159 = 2 * x5;
	const GEN_FLT x160 = x159 + x130 + (-4 * x6);
	const GEN_FLT x161 = (x160 * lh_qj) + (-1 * x155 * lh_qk) + (x158 * lh_qw);
	const GEN_FLT x162 = (x155 * lh_qi) + (x160 * lh_qw) + (-1 * x158 * lh_qj);
	const GEN_FLT x163 = x155 + (x42 * x161) + (-1 * x162 * x140);
	const GEN_FLT x164 = (-1 * x160 * lh_qi) + (x158 * lh_qk) + (x155 * lh_qw);
	const GEN_FLT x165 = x158 + (x40 * x162) + (-1 * x42 * x164);
	const GEN_FLT x166 = x160 + (x164 * x140) + (-1 * x40 * x161);
	const GEN_FLT x167 = (x54 * x166) + (x49 * x165);
	const GEN_FLT x168 = (x28 * x163) + (-1 * x57 * (x167 + (x45 * x163)));
	const GEN_FLT x169 = x39 * x168;
	const GEN_FLT x170 = x119 * x168;
	const GEN_FLT x171 = x33 * x39;
	const GEN_FLT x172 = (x168 * x171) + (x29 * (x170 + (-1 * x31 * x169)));
	const GEN_FLT x173 = (x35 * x169) + (x29 * x172);
	const GEN_FLT x174 = x37 * x39;
	const GEN_FLT x175 = (x73 * x167) + (-1 * x66 * x163);
	const GEN_FLT x176 = ((x76 * x165) + (-1 * x75 * x166)) * x77;
	const GEN_FLT x177 = x80 * (x176 + (-1 * x72 * x175));
	const GEN_FLT x178 =
		x176 +
		(-1 * x95 *
		 (x175 + (x92 * x177) + (x90 * x173) + (x91 * x169) +
		  (-1 * x88 *
		   ((x83 * x177) +
			(x70 * ((x29 * x173) +
					(x29 * (x173 + (x29 * (x172 + (x34 * x169) + (x29 * ((-1 * x60 * x169) + x170 + (x121 * x168))))) +
							(x123 * x168))) +
					(x168 * x174) + (x38 * x169)))))));
	const GEN_FLT x179 = 2 * obj_qi * sensor_x;
	const GEN_FLT x180 = x156 + x179;
	const GEN_FLT x181 = x136 + (-4 * x11) + x154;
	const GEN_FLT x182 = 2 * x0;
	const GEN_FLT x183 = (-4 * x1) + (-1 * x182) + x132;
	const GEN_FLT x184 = (x183 * lh_qj) + (-1 * x180 * lh_qk) + (x181 * lh_qw);
	const GEN_FLT x185 = (x180 * lh_qi) + (-1 * x181 * lh_qj) + (x183 * lh_qw);
	const GEN_FLT x186 = x180 + (x42 * x184) + (-1 * x185 * x140);
	const GEN_FLT x187 = (x181 * lh_qk) + (-1 * x183 * lh_qi) + (x180 * lh_qw);
	const GEN_FLT x188 = x181 + (x40 * x185) + (-1 * x42 * x187);
	const GEN_FLT x189 = x183 + (x187 * x140) + (-1 * x40 * x184);
	const GEN_FLT x190 = (x54 * x189) + (x49 * x188);
	const GEN_FLT x191 = (x28 * x186) + (-1 * x57 * (x190 + (x45 * x186)));
	const GEN_FLT x192 = x39 * x191;
	const GEN_FLT x193 = x119 * x191;
	const GEN_FLT x194 = (x171 * x191) + (x29 * (x193 + (-1 * x31 * x192)));
	const GEN_FLT x195 = (x35 * x192) + (x29 * x194);
	const GEN_FLT x196 = (x73 * x190) + (-1 * x66 * x186);
	const GEN_FLT x197 = ((x76 * x188) + (-1 * x75 * x189)) * x77;
	const GEN_FLT x198 = x197 + (-1 * x72 * x196);
	const GEN_FLT x199 =
		x197 +
		(-1 * x95 *
		 (x196 + (x93 * x198) +
		  (-1 * x88 *
		   ((x84 * x198) +
			(x70 * ((x29 * x195) + (x174 * x191) +
					(x29 * (x195 + (x29 * ((x34 * x192) + x194 + (x29 * ((-1 * x60 * x192) + (x121 * x191) + x193)))) +
							(x123 * x191))) +
					(x38 * x192))))) +
		  (x90 * x195) + (x91 * x192)));
	const GEN_FLT x200 = x182 + x133 + (-4 * x2);
	const GEN_FLT x201 = (-1 * x159) + (-4 * x4) + x129;
	const GEN_FLT x202 = x179 + x157;
	const GEN_FLT x203 = (x202 * lh_qj) + (-1 * x200 * lh_qk) + (x201 * lh_qw);
	const GEN_FLT x204 = (x200 * lh_qi) + (-1 * x201 * lh_qj) + (x202 * lh_qw);
	const GEN_FLT x205 = x200 + (x42 * x203) + (-1 * x204 * x140);
	const GEN_FLT x206 = (x201 * lh_qk) + (x200 * lh_qw) + (-1 * x202 * lh_qi);
	const GEN_FLT x207 = x201 + (x40 * x204) + (-1 * x42 * x206);
	const GEN_FLT x208 = x202 + (x206 * x140) + (-1 * x40 * x203);
	const GEN_FLT x209 = (x54 * x208) + (x49 * x207);
	const GEN_FLT x210 = (x28 * x205) + (-1 * x57 * (x209 + (x45 * x205)));
	const GEN_FLT x211 = x39 * x210;
	const GEN_FLT x212 = x210 * x119;
	const GEN_FLT x213 = (x210 * x171) + (x29 * (x212 + (-1 * x31 * x211)));
	const GEN_FLT x214 = (x35 * x211) + (x29 * x213);
	const GEN_FLT x215 = (x73 * x209) + (-1 * x66 * x205);
	const GEN_FLT x216 = ((x76 * x207) + (-1 * x75 * x208)) * x77;
	const GEN_FLT x217 = x216 + (-1 * x72 * x215);
	const GEN_FLT x218 =
		x216 +
		(-1 * x95 *
		 ((x93 * x217) + (x91 * x211) +
		  (-1 * x88 *
		   ((x84 * x217) +
			(x70 * ((x29 * x214) + (x210 * x174) +
					(x29 * (x214 + (x29 * ((x34 * x211) + x213 + (x29 * ((-1 * x60 * x211) + x212 + (x210 * x121))))) +
							(x210 * x123))) +
					(x38 * x211))))) +
		  x215 + (x90 * x214)));
	out[0] = x96 + (x97 * x96);
	out[1] = x112 + (x97 * x112);
	out[2] = x128 + (x97 * x128);
	out[3] = x153 + (x97 * x153);
	out[4] = x178 + (x97 * x178);
	out[5] = x199 + (x97 * x199);
	out[6] = x218 + (x97 * x218);
}

// Jacobian of reproject_axis_y_gen2 wrt [sensor_x, sensor_y, sensor_z]
static inline void gen_reproject_axis_y_gen2_jac_sensor_pt(FLT *out, const SurvivePose *obj_p, const FLT *sensor_pt,
														   const SurvivePose *lh_p, const BaseStationCal *bsc1) {
	const GEN_FLT obj_px = (*obj_p).Pos[0];
	const GEN_FLT obj_py = (*obj_p).Pos[1];
	const GEN_FLT obj_pz = (*obj_p).Pos[2];
	const GEN_FLT obj_qw = (*obj_p).Rot[0];
	const GEN_FLT obj_qi = (*obj_p).Rot[1];
	const GEN_FLT obj_qj = (*obj_p).Rot[2];
	const GEN_FLT obj_qk = (*obj_p).Rot[3];
	const GEN_FLT sensor_x = sensor_pt[0];
	const GEN_FLT sensor_y = sensor_pt[1];
	const GEN_FLT sensor_z = sensor_pt[2];
	const GEN_FLT lh_px = (*lh_p).Pos[0];
	const GEN_FLT lh_py = (*lh_p).Pos[1];
	const GEN_FLT lh_pz = (*lh_p).Pos[2];
	const GEN_FLT lh_qw = (*lh_p).Rot[0];
	const GEN_FLT lh_qi = (*lh_p).Rot[1];
	const GEN_FLT lh_qj = (*lh_p).Rot[2];
	const GEN_FLT lh_qk = (*lh_p).Rot[3];
	const GEN_FLT phase_1 = (*bsc1).phase;
	const GEN_FLT tilt_1 = (*bsc1).tilt;
	const GEN_FLT curve_1 = (*bsc1).curve;
	const GEN_FLT gibPhase_1 = (*bsc1).gibpha;
	const GEN_FLT gibMag_1 = (*bsc1).gibmag;
	const GEN_FLT ogeeMag_1 = (*bsc1).ogeephase;
	const GEN_FLT ogeePhase_1 = (*bsc1).ogeemag;
	const GEN_FLT x0 = 0.523598775598299 + (-1 * tilt_1);
	const GEN_FLT x1 = cos(x0);
	const GEN_FLT x2 = (obj_qw * sensor_x) + (-1 * obj_qk * sensor_y) + (obj_qj * sensor_z);
	const GEN_FLT x3 = (obj_qk * sensor_x) + (-1 * obj_qi * sensor_z) + (obj_qw * sensor_y);
	const GEN_FLT x4 = obj_pz + (2 * ((x3 * obj_qi) + (-1 * x2 * obj_qj))) + sensor_z;
	const GEN_FLT x5 = (-1 * obj_qj * sensor_x) + (obj_qw * sensor_z) + (obj_qi * sensor_y);
	const GEN_FLT x6 = (2 * ((x2 * obj_qk) + (-1 * x5 * obj_qi))) + obj_py + sensor_y;
	const GEN_FLT x7 = (2 * ((x5 * obj_qj) + (-1 * x3 * obj_qk))) + obj_px + sensor_x;
	const GEN_FLT x8 = (-1 * x7 * lh_qj) + (x4 * lh_qw) + (x6 * lh_qi);
	const GEN_FLT x9 = (x7 * lh_qw) + (-1 * x6 * lh_qk) + (x4 * lh_qj);
	const GEN_FLT x10 = x6 + lh_py + (2 * ((x9 * lh_qk) + (-1 * x8 * lh_qi)));
	const GEN_FLT x11 = x10 * x10;
	const GEN_FLT x12 = (-1 * x4 * lh_qi) + (x6 * lh_qw) + (x7 * lh_qk);
	const GEN_FLT x13 = x4 + lh_pz + (2 * ((x12 * lh_qi) + (-1 * x9 * lh_qj)));
	const GEN_FLT x14 = x7 + lh_px + (2 * ((x8 * lh_qj) + (-1 * x12 * lh_qk)));
	const GEN_FLT x15 = x14 * x14;
	const GEN_FLT x16 = x15 + (x13 * x13);
	const GEN_FLT x17 = x16 + x11;
	const GEN_FLT x18 = 1. / sqrt(1 + (-1 * (1. / (x1 * x1)) * x11 * (1. / x17)));
	const GEN_FLT x19 = -2 * (obj_qj * obj_qj);
	const GEN_FLT x20 = 1 + (-2 * (obj_qk * obj_qk));
	const GEN_FLT x21 = x20 + x19;
	const GEN_FLT x22 = 2 * obj_qi;
	const GEN_FLT x23 = x22 * obj_qj;
	const GEN_FLT x24 = 2 * obj_qw;
	const GEN_FLT x25 = x24 * obj_qk;
	const GEN_FLT x26 = x25 + x23;
	const GEN_FLT x27 = x24 * obj_qj;
	const GEN_FLT x28 = x22 * obj_qk;
	const GEN_FLT x29 = x28 + (-1 * x27);
	const GEN_FLT x30 = (x29 * lh_qj) + (x21 * lh_qw) + (-1 * x26 * lh_qk);
	const GEN_FLT x31 = 2 * lh_qk;
	const GEN_FLT x32 = (x26 * lh_qi) + (-1 * x21 * lh_qj) + (x29 * lh_qw);
	const GEN_FLT x33 = 2 * lh_qi;
	const GEN_FLT x34 = (x30 * x31) + x26 + (-1 * x32 * x33);
	const GEN_FLT x35 = 2 * x10;
	const GEN_FLT x36 = 2 * lh_qj;
	const GEN_FLT x37 = (x21 * lh_qk) + (-1 * x29 * lh_qi) + (x26 * lh_qw);
	const GEN_FLT x38 = x21 + (x32 * x36) + (-1 * x31 * x37);
	const GEN_FLT x39 = 2 * x14;
	const GEN_FLT x40 = x29 + (x33 * x37) + (-1 * x30 * x36);
	const GEN_FLT x41 = 2 * x13;
	const GEN_FLT x42 = (x40 * x41) + (x38 * x39);
	const GEN_FLT x43 = 1. / x1;
	const GEN_FLT x44 = 1.0 / 2.0 * x10;
	const GEN_FLT x45 = x43 * x44 * (1. / (x17 * sqrt(x17)));
	const GEN_FLT x46 = x43 * (1. / sqrt(x17));
	const GEN_FLT x47 = (x46 * x34) + (-1 * x45 * (x42 + (x34 * x35)));
	const GEN_FLT x48 = x47 * x18;
	const GEN_FLT x49 = atan2(-1 * x13, x14);
	const GEN_FLT x50 = tan(x0);
	const GEN_FLT x51 = x50 * (1. / sqrt(x16));
	const GEN_FLT x52 = -1 * x51 * x10;
	const GEN_FLT x53 = (-1 * asin(x52)) + ogeeMag_1 + x49;
	const GEN_FLT x54 = (sin(x53) * ogeePhase_1) + curve_1;
	const GEN_FLT x55 = asin(x46 * x10);
	const GEN_FLT x56 = 8.0108022e-06 * x55;
	const GEN_FLT x57 = -8.0108022e-06 + (-1 * x56);
	const GEN_FLT x58 = 0.0028679863 + (x57 * x55);
	const GEN_FLT x59 = 5.3685255e-06 + (x58 * x55);
	const GEN_FLT x60 = 0.0076069798 + (x55 * x59);
	const GEN_FLT x61 = x60 * x55;
	const GEN_FLT x62 = -8.0108022e-06 + (-1.60216044e-05 * x55);
	const GEN_FLT x63 = x58 + (x62 * x55);
	const GEN_FLT x64 = x59 + (x63 * x55);
	const GEN_FLT x65 = x60 + (x64 * x55);
	const GEN_FLT x66 = (x65 * x55) + x61;
	const GEN_FLT x67 = sin(x0);
	const GEN_FLT x68 = x67 * x54;
	const GEN_FLT x69 = x1 + (x68 * x66);
	const GEN_FLT x70 = 1. / x69;
	const GEN_FLT x71 = 2 * x70 * x61 * x54;
	const GEN_FLT x72 = x57 * x48;
	const GEN_FLT x73 = 2.40324066e-05 * x55;
	const GEN_FLT x74 = x58 * x18;
	const GEN_FLT x75 = (x74 * x47) + (x55 * (x72 + (-1 * x56 * x48)));
	const GEN_FLT x76 = (x59 * x48) + (x75 * x55);
	const GEN_FLT x77 = x50 * x44 * (1. / (x16 * sqrt(x16)));
	const GEN_FLT x78 = (x77 * x42) + (-1 * x51 * x34);
	const GEN_FLT x79 = 1. / x16;
	const GEN_FLT x80 = 1. / sqrt(1 + (-1 * x79 * (x50 * x50) * x11));
	const GEN_FLT x81 = 1. / x14;
	const GEN_FLT x82 = (1. / x15) * x13;
	const GEN_FLT x83 = x79 * x15;
	const GEN_FLT x84 = ((x82 * x38) + (-1 * x81 * x40)) * x83;
	const GEN_FLT x85 = x84 + (-1 * x80 * x78);
	const GEN_FLT x86 = cos(x53) * ogeePhase_1;
	const GEN_FLT x87 = x67 * x66;
	const GEN_FLT x88 = x86 * x87;
	const GEN_FLT x89 = x55 * x55;
	const GEN_FLT x90 = x89 * x54;
	const GEN_FLT x91 = x60 * (1. / (x69 * x69)) * x90;
	const GEN_FLT x92 = x70 * x90;
	const GEN_FLT x93 = x89 * x70 * x60;
	const GEN_FLT x94 = x86 * x93;
	const GEN_FLT x95 = x52 + (x60 * x92);
	const GEN_FLT x96 = 1. / sqrt(1 + (-1 * (x95 * x95)));
	const GEN_FLT x97 =
		x84 + (-1 * x96 *
			   ((x76 * x92) + x78 + (x85 * x94) + (x71 * x48) +
				(-1 * x91 *
				 ((x88 * x85) +
				  (x68 * ((x76 * x55) + (x60 * x48) + (x65 * x48) +
						  (x55 * (x76 + (x55 * (x75 + (x63 * x48) + (x55 * ((-1 * x73 * x48) + x72 + (x62 * x48))))) +
								  (x64 * x48)))))))));
	const GEN_FLT x98 = cos(gibPhase_1 + (-1 * asin(x95)) + x49) * gibMag_1;
	const GEN_FLT x99 = x23 + (-1 * x25);
	const GEN_FLT x100 = -2 * (obj_qi * obj_qi);
	const GEN_FLT x101 = x20 + x100;
	const GEN_FLT x102 = 2 * obj_qk * obj_qj;
	const GEN_FLT x103 = x24 * obj_qi;
	const GEN_FLT x104 = x103 + x102;
	const GEN_FLT x105 = (x104 * lh_qj) + (x99 * lh_qw) + (-1 * x101 * lh_qk);
	const GEN_FLT x106 = (x101 * lh_qi) + (-1 * x99 * lh_qj) + (x104 * lh_qw);
	const GEN_FLT x107 = x101 + (x31 * x105) + (-1 * x33 * x106);
	const GEN_FLT x108 = 2 * ((x99 * lh_qk) + (-1 * x104 * lh_qi) + (x101 * lh_qw));
	const GEN_FLT x109 = x99 + (x36 * x106) + (-1 * x108 * lh_qk);
	const GEN_FLT x110 = x104 + (x108 * lh_qi) + (-1 * x36 * x105);
	const GEN_FLT x111 = (x41 * x110) + (x39 * x109);
	const GEN_FLT x112 = (x46 * x107) + (-1 * x45 * (x111 + (x35 * x107)));
	const GEN_FLT x113 = x18 * x112;
	const GEN_FLT x114 = x57 * x113;
	const GEN_FLT x115 = (x74 * x112) + (x55 * (x114 + (-1 * x56 * x113)));
	const GEN_FLT x116 = (x59 * x113) + (x55 * x115);
	const GEN_FLT x117 = (x77 * x111) + (-1 * x51 * x107);
	const GEN_FLT x118 = ((x82 * x109) + (-1 * x81 * x110)) * x83;
	const GEN_FLT x119 = x86 * (x118 + (-1 * x80 * x117));
	const GEN_FLT x120 =
		x118 +
		(-1 * x96 *
		 ((x93 * x119) + (x92 * x116) + x117 + (x71 * x113) +
		  (-1 * x91 *
		   ((x87 * x119) +
			(x68 * ((x55 * x116) + (x60 * x113) + (x65 * x113) +
					(x55 * (x116 + (x55 * (x115 + (x63 * x113) + (x55 * ((-1 * x73 * x113) + x114 + (x62 * x113))))) +
							(x64 * x113)))))))));
	const GEN_FLT x121 = x102 + (-1 * x103);
	const GEN_FLT x122 = x27 + x28;
	const GEN_FLT x123 = 1 + x100 + x19;
	const GEN_FLT x124 = (x123 * lh_qj) + (-1 * x121 * lh_qk) + (x122 * lh_qw);
	const GEN_FLT x125 = (x121 * lh_qi) + (-1 * x122 * lh_qj) + (x123 * lh_qw);
	const GEN_FLT x126 = x121 + (x31 * x124) + (-1 * x33 * x125);
	const GEN_FLT x127 = (x122 * lh_qk) + (-1 * x123 * lh_qi) + (x121 * lh_qw);
	const GEN_FLT x128 = (x36 * x125) + x122 + (-1 * x31 * x127);
	const GEN_FLT x129 = x123 + (x33 * x127) + (-1 * x36 * x124);
	const GEN_FLT x130 = (x41 * x129) + (x39 * x128);
	const GEN_FLT x131 = (x46 * x126) + (-1 * x45 * (x130 + (x35 * x126)));
	const GEN_FLT x132 = x18 * x131;
	const GEN_FLT x133 = x57 * x132;
	const GEN_FLT x134 = (x74 * x131) + (x55 * (x133 + (-1 * x56 * x132)));
	const GEN_FLT x135 = (x59 * x132) + (x55 * x134);
	const GEN_FLT x136 = (x77 * x130) + (-1 * x51 * x126);
	const GEN_FLT x137 = ((x82 * x128) + (-1 * x81 * x129)) * x83;
	const GEN_FLT x138 = x137 + (-1 * x80 * x136);
	const GEN_FLT x139 =
		x137 + (-1 * x96 *
				(x136 + (x94 * x138) +
				 (-1 * x91 *
				  ((x88 * x138) +
				   (x68 * ((x55 * x135) + (x60 * x132) +
						   (x55 * ((x55 * ((x63 * x132) + x134 + (x55 * ((-1 * x73 * x132) + x133 + (x62 * x132))))) +
								   x135 + (x64 * x132))) +
						   (x65 * x132))))) +
				 (x71 * x132) + (x92 * x135)));
	out[0] = x97 + (x98 * x97);
	out[1] = x120 + (x98 * x120);
	out[2] = x139 + (x98 * x139);
}

// Jacobian of reproject_axis_y_gen2 wrt [lh_px, lh_py, lh_pz, lh_qw, lh_qi, lh_qj, lh_qk]
static inline void gen_reproject_axis_y_gen2_jac_lh_p(FLT *out, const SurvivePose *obj_p, const FLT *sensor_pt,
													  const SurvivePose *lh_p, const BaseStationCal *bsc1) {
	const GEN_FLT obj_px = (*obj_p).Pos[0];
	const GEN_FLT obj_py = (*obj_p).Pos[1];
	const GEN_FLT obj_pz = (*obj_p).Pos[2];
	const GEN_FLT obj_qw = (*obj_p).Rot[0];
	const GEN_FLT obj_qi = (*obj_p).Rot[1];
	const GEN_FLT obj_qj = (*obj_p).Rot[2];
	const GEN_FLT obj_qk = (*obj_p).Rot[3];
	const GEN_FLT sensor_x = sensor_pt[0];
	const GEN_FLT sensor_y = sensor_pt[1];
	const GEN_FLT sensor_z = sensor_pt[2];
	const GEN_FLT lh_px = (*lh_p).Pos[0];
	const GEN_FLT lh_py = (*lh_p).Pos[1];
	const GEN_FLT lh_pz = (*lh_p).Pos[2];
	const GEN_FLT lh_qw = (*lh_p).Rot[0];
	const GEN_FLT lh_qi = (*lh_p).Rot[1];
	const GEN_FLT lh_qj = (*lh_p).Rot[2];
	const GEN_FLT lh_qk = (*lh_p).Rot[3];
	const GEN_FLT phase_1 = (*bsc1).phase;
	const GEN_FLT tilt_1 = (*bsc1).tilt;
	const GEN_FLT curve_1 = (*bsc1).curve;
	const GEN_FLT gibPhase_1 = (*bsc1).gibpha;
	const GEN_FLT gibMag_1 = (*bsc1).gibmag;
	const GEN_FLT ogeeMag_1 = (*bsc1).ogeephase;
	const GEN_FLT ogeePhase_1 = (*bsc1).ogeemag;
	const GEN_FLT x0 = (obj_qk * sensor_x) + (-1 * obj_qi * sensor_z) + (obj_qw * sensor_y);
	const GEN_FLT x1 = (-1 * obj_qj * sensor_x) + (obj_qw * sensor_z) + (obj_qi * sensor_y);
	const GEN_FLT x2 = 2 * ((x1 * obj_qj) + (-1 * x0 * obj_qk));
	const GEN_FLT x3 = x2 + obj_px + sensor_x;
	const GEN_FLT x4 = x3 * lh_qw;
	const GEN_FLT x5 = (obj_qw * sensor_x) + (-1 * obj_qk * sensor_y) + (obj_qj * sensor_z);
	const GEN_FLT x6 = 2 * ((x0 * obj_qi) + (-1 * x5 * obj_qj));
	const GEN_FLT x7 = x6 + obj_pz + sensor_z;
	const GEN_FLT x8 = x7 * lh_qj;
	const GEN_FLT x9 = 2 * ((x5 * obj_qk) + (-1 * x1 * obj_qi));
	const GEN_FLT x10 = x9 + obj_py + sensor_y;
	const GEN_FLT x11 = x10 * lh_qk;
	const GEN_FLT x12 = (-1 * x11) + x4 + x8;
	const GEN_FLT x13 = x10 * lh_qw;
	const GEN_FLT x14 = x3 * lh_qk;
	const GEN_FLT x15 = x7 * lh_qi;
	const GEN_FLT x16 = (-1 * x15) + x13 + x14;
	const GEN_FLT x17 = x7 + lh_pz + (2 * ((x16 * lh_qi) + (-1 * x12 * lh_qj)));
	const GEN_FLT x18 = x7 * lh_qw;
	const GEN_FLT x19 = x10 * lh_qi;
	const GEN_FLT x20 = x3 * lh_qj;
	const GEN_FLT x21 = (-1 * x20) + x18 + x19;
	const GEN_FLT x22 = lh_px + x3 + (2 * ((x21 * lh_qj) + (-1 * x16 * lh_qk)));
	const GEN_FLT x23 = x22 * x22;
	const GEN_FLT x24 = x23 + (x17 * x17);
	const GEN_FLT x25 = 1. / x24;
	const GEN_FLT x26 = 0.523598775598299 + (-1 * tilt_1);
	const GEN_FLT x27 = tan(x26);
	const GEN_FLT x28 = x10 + lh_py + (2 * ((x12 * lh_qk) + (-1 * x21 * lh_qi)));
	const GEN_FLT x29 = x28 * x28;
	const GEN_FLT x30 = 1. / sqrt(1 + (-1 * x25 * x29 * (x27 * x27)));
	const GEN_FLT x31 = x22 * x28;
	const GEN_FLT x32 = (1. / (x24 * sqrt(x24))) * x27;
	const GEN_FLT x33 = x32 * x31;
	const GEN_FLT x34 = x25 * x17;
	const GEN_FLT x35 = x34 + (-1 * x30 * x33);
	const GEN_FLT x36 = atan2(-1 * x17, x22);
	const GEN_FLT x37 = (1. / sqrt(x24)) * x27;
	const GEN_FLT x38 = -1 * x37 * x28;
	const GEN_FLT x39 = (-1 * asin(x38)) + ogeeMag_1 + x36;
	const GEN_FLT x40 = cos(x39) * ogeePhase_1;
	const GEN_FLT x41 = cos(x26);
	const GEN_FLT x42 = 1. / x41;
	const GEN_FLT x43 = x24 + x29;
	const GEN_FLT x44 = x42 * (1. / sqrt(x43));
	const GEN_FLT x45 = asin(x44 * x28);
	const GEN_FLT x46 = 8.0108022e-06 * x45;
	const GEN_FLT x47 = -8.0108022e-06 + (-1 * x46);
	const GEN_FLT x48 = 0.0028679863 + (x45 * x47);
	const GEN_FLT x49 = 5.3685255e-06 + (x45 * x48);
	const GEN_FLT x50 = 0.0076069798 + (x45 * x49);
	const GEN_FLT x51 = x45 * x45;
	const GEN_FLT x52 = x50 * x45;
	const GEN_FLT x53 = -8.0108022e-06 + (-1.60216044e-05 * x45);
	const GEN_FLT x54 = x48 + (x53 * x45);
	const GEN_FLT x55 = x49 + (x54 * x45);
	const GEN_FLT x56 = x50 + (x55 * x45);
	const GEN_FLT x57 = (x56 * x45) + x52;
	const GEN_FLT x58 = sin(x26);
	const GEN_FLT x59 = (sin(x39) * ogeePhase_1) + curve_1;
	const GEN_FLT x60 = x58 * x59;
	const GEN_FLT x61 = x41 + (x60 * x57);
	const GEN_FLT x62 = 1. / x61;
	const GEN_FLT x63 = x62 * x50 * x51;
	const GEN_FLT x64 = x63 * x40;
	const GEN_FLT x65 = 1. / sqrt(1 + (-1 * (1. / (x41 * x41)) * (1. / x43) * x29));
	const GEN_FLT x66 = x42 * (1. / (x43 * sqrt(x43)));
	const GEN_FLT x67 = x66 * x31;
	const GEN_FLT x68 = x67 * x65;
	const GEN_FLT x69 = x65 * x47;
	const GEN_FLT x70 = -1 * x67 * x69;
	const GEN_FLT x71 = 2.40324066e-05 * x45;
	const GEN_FLT x72 = (-1 * x68 * x48) + (x45 * (x70 + (x68 * x46)));
	const GEN_FLT x73 = (-1 * x68 * x49) + (x72 * x45);
	const GEN_FLT x74 = x65 * x50;
	const GEN_FLT x75 = x58 * x57;
	const GEN_FLT x76 = x75 * x40;
	const GEN_FLT x77 = x51 * x59;
	const GEN_FLT x78 = x77 * (1. / (x61 * x61)) * x50;
	const GEN_FLT x79 = x77 * x62;
	const GEN_FLT x80 = 2 * x22;
	const GEN_FLT x81 = x66 * x28;
	const GEN_FLT x82 = x62 * x52 * x59;
	const GEN_FLT x83 = x82 * x65;
	const GEN_FLT x84 = x38 + (x79 * x50);
	const GEN_FLT x85 = 1. / sqrt(1 + (-1 * (x84 * x84)));
	const GEN_FLT x86 =
		x34 +
		(-1 * x85 *
		 ((-1 * x80 * x81 * x83) +
		  (-1 * x78 *
		   ((x76 * x35) +
			(x60 * ((x73 * x45) +
					(x45 * (x73 + (x45 * (x72 + (-1 * x68 * x54) + (x45 * ((x71 * x68) + (-1 * x68 * x53) + x70)))) +
							(-1 * x68 * x55))) +
					(-1 * x74 * x67) + (-1 * x68 * x56))))) +
		  (x64 * x35) + (x73 * x79) + x33));
	const GEN_FLT x87 = cos((-1 * asin(x84)) + gibPhase_1 + x36) * gibMag_1;
	const GEN_FLT x88 = x30 * x37;
	const GEN_FLT x89 = x44 + (-1 * x66 * x29);
	const GEN_FLT x90 = x89 * x65;
	const GEN_FLT x91 = x90 * x47;
	const GEN_FLT x92 = (x90 * x48) + (x45 * (x91 + (-1 * x90 * x46)));
	const GEN_FLT x93 = (x90 * x49) + (x92 * x45);
	const GEN_FLT x94 = 2 * x82;
	const GEN_FLT x95 =
		x85 * ((x79 * x93) + (x90 * x94) +
			   (-1 * x78 *
				((x88 * x76) +
				 (x60 * ((x93 * x45) + (x89 * x74) +
						 (x45 * (x93 + (x45 * (x92 + (x54 * x90) + (x45 * ((-1 * x71 * x90) + x91 + (x53 * x90))))) +
								 (x55 * x90))) +
						 (x56 * x90))))) +
			   (-1 * x37) + (x88 * x64));
	const GEN_FLT x96 = x32 * x28;
	const GEN_FLT x97 = x96 * x17;
	const GEN_FLT x98 = -1 * x25 * x22;
	const GEN_FLT x99 = x98 + (-1 * x97 * x30);
	const GEN_FLT x100 = x81 * x17;
	const GEN_FLT x101 = x65 * x100;
	const GEN_FLT x102 = -1 * x69 * x100;
	const GEN_FLT x103 = (-1 * x48 * x101) + (x45 * (x102 + (x46 * x101)));
	const GEN_FLT x104 = (-1 * x49 * x101) + (x45 * x103);
	const GEN_FLT x105 = 2 * x28;
	const GEN_FLT x106 =
		x98 +
		(-1 * x85 *
		 (x97 + (x64 * x99) + (-1 * x83 * x66 * x17 * x105) +
		  (-1 * x78 *
		   ((x76 * x99) +
			(x60 *
			 ((x45 * (x104 + (x45 * (x103 + (-1 * x54 * x101) + (x45 * ((x71 * x101) + x102 + (-1 * x53 * x101))))) +
					  (-1 * x55 * x101))) +
			  (x45 * x104) + (-1 * x74 * x100) + (-1 * x56 * x101))))) +
		  (x79 * x104)));
	const GEN_FLT x107 = 2 * x15;
	const GEN_FLT x108 = (2 * x14) + (-1 * x107);
	const GEN_FLT x109 = 2 * x11;
	const GEN_FLT x110 = (2 * x8) + (-1 * x109);
	const GEN_FLT x111 = 2 * x20;
	const GEN_FLT x112 = (2 * x19) + (-1 * x111);
	const GEN_FLT x113 = 2 * x17;
	const GEN_FLT x114 = (x112 * x113) + (x80 * x110);
	const GEN_FLT x115 = 1.0 / 2.0 * x81;
	const GEN_FLT x116 = (x44 * x108) + (-1 * x115 * (x114 + (x108 * x105)));
	const GEN_FLT x117 = x65 * x116;
	const GEN_FLT x118 = x47 * x117;
	const GEN_FLT x119 = (x48 * x117) + (x45 * (x118 + (-1 * x46 * x117)));
	const GEN_FLT x120 = (x49 * x117) + (x45 * x119);
	const GEN_FLT x121 = 1.0 / 2.0 * x96;
	const GEN_FLT x122 = (x114 * x121) + (-1 * x37 * x108);
	const GEN_FLT x123 = 1. / x22;
	const GEN_FLT x124 = (1. / x23) * x17;
	const GEN_FLT x125 = x25 * x23;
	const GEN_FLT x126 = ((x110 * x124) + (-1 * x112 * x123)) * x125;
	const GEN_FLT x127 = x40 * (x126 + (-1 * x30 * x122));
	const GEN_FLT x128 =
		x126 +
		(-1 * x85 *
		 (x122 + (x79 * x120) + (x63 * x127) + (x94 * x117) +
		  (-1 * x78 *
		   ((x75 * x127) +
			(x60 * ((x45 * x120) + (x74 * x116) +
					(x45 * (x120 + (x45 * (x119 + (x54 * x117) + (x45 * ((-1 * x71 * x117) + x118 + (x53 * x117))))) +
							(x55 * x117))) +
					(x56 * x117)))))));
	const GEN_FLT x129 = 2 * x18;
	const GEN_FLT x130 = (-4 * x19) + x111 + (-1 * x129);
	const GEN_FLT x131 = 2 * ((-1 * obj_pz) + (-1 * sensor_z) + (-1 * x6));
	const GEN_FLT x132 = 2 * lh_qj;
	const GEN_FLT x133 = (x10 * x132) + (-1 * x131 * lh_qk);
	const GEN_FLT x134 = 2 * x13;
	const GEN_FLT x135 = x108 + x134 + (x131 * lh_qi);
	const GEN_FLT x136 = (x113 * x135) + (x80 * x133);
	const GEN_FLT x137 = (x44 * x130) + (-1 * x115 * (x136 + (x105 * x130)));
	const GEN_FLT x138 = x65 * x137;
	const GEN_FLT x139 = x47 * x138;
	const GEN_FLT x140 = (x48 * x138) + (x45 * (x139 + (-1 * x46 * x138)));
	const GEN_FLT x141 = (x49 * x138) + (x45 * x140);
	const GEN_FLT x142 = (x121 * x136) + (-1 * x37 * x130);
	const GEN_FLT x143 = ((x124 * x133) + (-1 * x123 * x135)) * x125;
	const GEN_FLT x144 = x143 + (-1 * x30 * x142);
	const GEN_FLT x145 =
		x143 +
		(-1 * x85 *
		 ((x64 * x144) +
		  (-1 * x78 *
		   ((x76 * x144) +
			(x60 * ((x45 * x141) +
					(x45 * (x141 + (x45 * ((x54 * x138) + x140 + (x45 * ((-1 * x71 * x138) + x139 + (x53 * x138))))) +
							(x55 * x138))) +
					(x74 * x137) + (x56 * x138))))) +
		  (x79 * x141) + x142 + (x94 * x138)));
	const GEN_FLT x146 = (-1 * obj_px) + (-1 * sensor_x) + (-1 * x2);
	const GEN_FLT x147 = 2 * lh_qi;
	const GEN_FLT x148 = 2 * lh_qk;
	const GEN_FLT x149 = (x7 * x148) + (-1 * x146 * x147);
	const GEN_FLT x150 = x112 + (x132 * x146) + x129;
	const GEN_FLT x151 = 2 * x4;
	const GEN_FLT x152 = (-4 * x8) + (-1 * x151) + x109;
	const GEN_FLT x153 = (x113 * x152) + (x80 * x150);
	const GEN_FLT x154 = (x44 * x149) + (-1 * x115 * (x153 + (x105 * x149)));
	const GEN_FLT x155 = x65 * x154;
	const GEN_FLT x156 = x47 * x155;
	const GEN_FLT x157 = (x48 * x155) + (x45 * (x156 + (-1 * x46 * x155)));
	const GEN_FLT x158 = (x49 * x155) + (x45 * x157);
	const GEN_FLT x159 = (x121 * x153) + (-1 * x37 * x149);
	const GEN_FLT x160 = ((x124 * x150) + (-1 * x123 * x152)) * x125;
	const GEN_FLT x161 = x160 + (-1 * x30 * x159);
	const GEN_FLT x162 =
		x160 +
		(-1 * x85 *
		 ((x64 * x161) +
		  (-1 * x78 *
		   ((x76 * x161) +
			(x60 * ((x45 * x158) + (x74 * x154) +
					(x45 * (x158 + (x45 * (x157 + (x54 * x155) + (x45 * ((-1 * x71 * x155) + x156 + (x53 * x155))))) +
							(x55 * x155))) +
					(x56 * x155))))) +
		  (x94 * x155) + x159 + (x79 * x158)));
	const GEN_FLT x163 = (-1 * obj_py) + (-1 * sensor_y) + (-1 * x9);
	const GEN_FLT x164 = x151 + x110 + (x163 * x148);
	const GEN_FLT x165 = (-1 * x134) + (-4 * x14) + x107;
	const GEN_FLT x166 = (x3 * x147) + (-1 * x163 * x132);
	const GEN_FLT x167 = (x113 * x166) + (x80 * x165);
	const GEN_FLT x168 = (x44 * x164) + (-1 * x115 * (x167 + (x105 * x164)));
	const GEN_FLT x169 = x65 * x168;
	const GEN_FLT x170 = x47 * x169;
	const GEN_FLT x171 = (x48 * x169) + (x45 * (x170 + (-1 * x46 * x169)));
	const GEN_FLT x172 = (x49 * x169) + (x45 * x171);
	const GEN_FLT x173 = (x121 * x167) + (-1 * x37 * x164);
	const GEN_FLT x174 = ((x124 * x165) + (-1 * x123 * x166)) * x125;
	const GEN_FLT x175 = x174 + (-1 * x30 * x173);
	const GEN_FLT x176 =
		x174 +
		(-1 * x85 *
		 ((x79 * x172) + (x94 * x169) + x173 + (x64 * x175) +
		  (-1 * x78 *
		   ((x76 * x175) +
			(x60 * ((x45 * x172) + (x74 * x168) +
					(x45 * (x172 + (x45 * (x171 + (x54 * x169) + (x45 * ((-1 * x71 * x169) + (x53 * x169) + x170)))) +
							(x55 * x169))) +
					(x56 * x169)))))));
	out[0] = x86 + (x86 * x87);
	out[1] = (-1 * x87 * x95) + (-1 * x95);
	out[2] = x106 + (x87 * x106);
	out[3] = x128 + (x87 * x128);
	out[4] = x145 + (x87 * x145);
	out[5] = x162 + (x87 * x162);
	out[6] = x176 + (x87 * x176);
}

// Jacobian of reproject_axis_y_gen2 wrt [phase_1, tilt_1, curve_1, gibPhase_1, gibMag_1, ogeeMag_1, ogeePhase_1]
static inline void gen_reproject_axis_y_gen2_jac_bsc1(FLT *out, const SurvivePose *obj_p, const FLT *sensor_pt,
													  const SurvivePose *lh_p, const BaseStationCal *bsc1) {
	const GEN_FLT obj_px = (*obj_p).Pos[0];
	const GEN_FLT obj_py = (*obj_p).Pos[1];
	const GEN_FLT obj_pz = (*obj_p).Pos[2];
	const GEN_FLT obj_qw = (*obj_p).Rot[0];
	const GEN_FLT obj_qi = (*obj_p).Rot[1];
	const GEN_FLT obj_qj = (*obj_p).Rot[2];
	const GEN_FLT obj_qk = (*obj_p).Rot[3];
	const GEN_FLT sensor_x = sensor_pt[0];
	const GEN_FLT sensor_y = sensor_pt[1];
	const GEN_FLT sensor_z = sensor_pt[2];
	const GEN_FLT lh_px = (*lh_p).Pos[0];
	const GEN_FLT lh_py = (*lh_p).Pos[1];
	const GEN_FLT lh_pz = (*lh_p).Pos[2];
	const GEN_FLT lh_qw = (*lh_p).Rot[0];
	const GEN_FLT lh_qi = (*lh_p).Rot[1];
	const GEN_FLT lh_qj = (*lh_p).Rot[2];
	const GEN_FLT lh_qk = (*lh_p).Rot[3];
	const GEN_FLT phase_1 = (*bsc1).phase;
	const GEN_FLT tilt_1 = (*bsc1).tilt;
	const GEN_FLT curve_1 = (*bsc1).curve;
	const GEN_FLT gibPhase_1 = (*bsc1).gibpha;
	const GEN_FLT gibMag_1 = (*bsc1).gibmag;
	const GEN_FLT ogeeMag_1 = (*bsc1).ogeephase;
	const GEN_FLT ogeePhase_1 = (*bsc1).ogeemag;
	const GEN_FLT x0 = 0.523598775598299 + (-1 * tilt_1);
	const GEN_FLT x1 = cos(x0);
	const GEN_FLT x2 = (obj_qw * sensor_x) + (-1 * obj_qk * sensor_y) + (obj_qj * sensor_z);
	const GEN_FLT x3 = (obj_qk * sensor_x) + (-1 * obj_qi * sensor_z) + (obj_qw * sensor_y);
	const GEN_FLT x4 = obj_pz + (2 * ((x3 * obj_qi) + (-1 * x2 * obj_qj))) + sensor_z;
	const GEN_FLT x5 = (-1 * obj_qj * sensor_x) + (obj_qw * sensor_z) + (obj_qi * sensor_y);
	const GEN_FLT x6 = (2 * ((x2 * obj_qk) + (-1 * x5 * obj_qi))) + obj_py + sensor_y;
	const GEN_FLT x7 = (2 * ((x5 * obj_qj) + (-1 * x3 * obj_qk))) + obj_px + sensor_x;
	const GEN_FLT x8 = (-1 * x7 * lh_qj) + (x4 * lh_qw) + (x6 * lh_qi);
	const GEN_FLT x9 = (x7 * lh_qw) + (-1 * x6 * lh_qk) + (x4 * lh_qj);
	const GEN_FLT x10 = x6 + lh_py + (2 * ((x9 * lh_qk) + (-1 * x8 * lh_qi)));
	const GEN_FLT x11 = x10 * x10;
	const GEN_FLT x12 = (-1 * x4 * lh_qi) + (x6 * lh_qw) + (x7 * lh_qk);
	const GEN_FLT x13 = x4 + lh_pz + (2 * ((x12 * lh_qi) + (-1 * x9 * lh_qj)));
	const GEN_FLT x14 = x7 + lh_px + (2 * ((x8 * lh_qj) + (-1 * x12 * lh_qk)));
	const GEN_FLT x15 = (x14 * x14) + (x13 * x13);
	const GEN_FLT x16 = x15 + x11;
	const GEN_FLT x17 = x10 * (1. / sqrt(x16));
	const GEN_FLT x18 = asin((1. / x1) * x17);
	const GEN_FLT x19 = 8.0108022e-06 * x18;
	const GEN_FLT x20 = -8.0108022e-06 + (-1 * x19);
	const GEN_FLT x21 = 0.0028679863 + (x20 * x18);
	const GEN_FLT x22 = 5.3685255e-06 + (x21 * x18);
	const GEN_FLT x23 = 0.0076069798 + (x22 * x18);
	const GEN_FLT x24 = x18 * x18;
	const GEN_FLT x25 = x23 * x18;
	const GEN_FLT x26 = -8.0108022e-06 + (-1.60216044e-05 * x18);
	const GEN_FLT x27 = x21 + (x26 * x18);
	const GEN_FLT x28 = x22 + (x27 * x18);
	const GEN_FLT x29 = x23 + (x28 * x18);
	const GEN_FLT x30 = (x29 * x18) + x25;
	const GEN_FLT x31 = sin(x0);
	const GEN_FLT x32 = atan2(-1 * x13, x14);
	const GEN_FLT x33 = tan(x0);
	const GEN_FLT x34 = (1. / sqrt(x15)) * x10;
	const GEN_FLT x35 = -1 * x34 * x33;
	const GEN_FLT x36 = (-1 * asin(x35)) + ogeeMag_1 + x32;
	const GEN_FLT x37 = sin(x36);
	const GEN_FLT x38 = (x37 * ogeePhase_1) + curve_1;
	const GEN_FLT x39 = x31 * x38;
	const GEN_FLT x40 = x30 * x39;
	const GEN_FLT x41 = x1 + x40;
	const GEN_FLT x42 = 1. / x41;
	const GEN_FLT x43 = x42 * x24;
	const GEN_FLT x44 = x43 * x23;
	const GEN_FLT x45 = cos(x36) * ogeePhase_1;
	const GEN_FLT x46 = x44 * x45;
	const GEN_FLT x47 = x33 * x33;
	const GEN_FLT x48 = x34 * (1 + x47);
	const GEN_FLT x49 = x48 * (1. / sqrt(1 + (-1 * x47 * (1. / x15) * x11)));
	const GEN_FLT x50 = 1. / (x1 * x1);
	const GEN_FLT x51 = x50 * x17 * (1. / sqrt(1 + (-1 * x50 * x11 * (1. / x16))));
	const GEN_FLT x52 = x51 * x31;
	const GEN_FLT x53 = -1 * x52 * x20;
	const GEN_FLT x54 = (-1 * x52 * x21) + (x18 * (x53 + (x52 * x19)));
	const GEN_FLT x55 = (-1 * x52 * x22) + (x54 * x18);
	const GEN_FLT x56 = (1. / (x41 * x41)) * x24 * x23;
	const GEN_FLT x57 = x35 + (x44 * x38);
	const GEN_FLT x58 = 1. / sqrt(1 + (-1 * (x57 * x57)));
	const GEN_FLT x59 =
		x58 * ((-1 * x46 * x49) + (-2 * x51 * x42 * x39 * x25) + (x55 * x43 * x38) + x48 +
			   (-1 * x56 * x38 *
				((-1 * x45 * x49 * x30 * x31) +
				 (x39 * ((-1 * x52 * x23) + (x55 * x18) +
						 (x18 * (x55 +
								 (x18 * (x54 + (-1 * x52 * x27) +
										 (x18 * ((2.40324066e-05 * x52 * x18) + x53 + (-1 * x52 * x26))))) +
								 (-1 * x52 * x28))) +
						 (-1 * x52 * x29))) +
				 x31 + (-1 * x1 * x30 * x38))));
	const GEN_FLT x60 = (-1 * asin(x57)) + gibPhase_1 + x32;
	const GEN_FLT x61 = cos(x60) * gibMag_1;
	const GEN_FLT x62 = x56 * x40;
	const GEN_FLT x63 = ((-1 * x62) + x44) * x58;
	const GEN_FLT x64 = x58 * ((-1 * x62 * x45) + x46);
	const GEN_FLT x65 = ((-1 * x62 * x37) + (x44 * x37)) * x58;
	out[0] = -1;
	out[1] = (-1 * x61 * x59) + (-1 * x59);
	out[2] = (-1 * x63 * x61) + (-1 * x63);
	out[3] = x61;
	out[4] = sin(x60);
	out[5] = (-1 * x64 * x61) + (-1 * x64);
	out[6] = (-1 * x61 * x65) + (-1 * x65);
}

static inline void gen_reproject(FLT *out, const SurvivePose *obj_p, const FLT *sensor_pt, const SurvivePose *lh_p,
								 const BaseStationCal *bsd) {
	const GEN_FLT obj_px = (*obj_p).Pos[0];
	const GEN_FLT obj_py = (*obj_p).Pos[1];
	const GEN_FLT obj_pz = (*obj_p).Pos[2];
	const GEN_FLT obj_qw = (*obj_p).Rot[0];
	const GEN_FLT obj_qi = (*obj_p).Rot[1];
	const GEN_FLT obj_qj = (*obj_p).Rot[2];
	const GEN_FLT obj_qk = (*obj_p).Rot[3];
	const GEN_FLT sensor_x = sensor_pt[0];
	const GEN_FLT sensor_y = sensor_pt[1];
	const GEN_FLT sensor_z = sensor_pt[2];
	const GEN_FLT lh_px = (*lh_p).Pos[0];
	const GEN_FLT lh_py = (*lh_p).Pos[1];
	const GEN_FLT lh_pz = (*lh_p).Pos[2];
	const GEN_FLT lh_qw = (*lh_p).Rot[0];
	const GEN_FLT lh_qi = (*lh_p).Rot[1];
	const GEN_FLT lh_qj = (*lh_p).Rot[2];
	const GEN_FLT lh_qk = (*lh_p).Rot[3];
	const GEN_FLT phase_0 = bsd[0].phase;
	const GEN_FLT tilt_0 = bsd[0].tilt;
	const GEN_FLT curve_0 = bsd[0].curve;
	const GEN_FLT gibPhase_0 = bsd[0].gibpha;
	const GEN_FLT gibMag_0 = bsd[0].gibmag;
	const GEN_FLT ogeeMag_0 = bsd[0].ogeephase;
	const GEN_FLT ogeePhase_0 = bsd[0].ogeemag;
	const GEN_FLT phase_1 = bsd[1].phase;
	const GEN_FLT tilt_1 = bsd[1].tilt;
	const GEN_FLT curve_1 = bsd[1].curve;
	const GEN_FLT gibPhase_1 = bsd[1].gibpha;
	const GEN_FLT gibMag_1 = bsd[1].gibmag;
	const GEN_FLT ogeeMag_1 = bsd[1].ogeephase;
	const GEN_FLT ogeePhase_1 = bsd[1].ogeemag;
	const GEN_FLT x0 = (obj_qw * sensor_x) + (-1 * obj_qk * sensor_y) + (obj_qj * sensor_z);
	const GEN_FLT x1 = (obj_qk * sensor_x) + (-1 * obj_qi * sensor_z) + (obj_qw * sensor_y);
	const GEN_FLT x2 = (2 * ((x1 * obj_qi) + (-1 * x0 * obj_qj))) + obj_pz + sensor_z;
	const GEN_FLT x3 = (-1 * obj_qj * sensor_x) + (obj_qw * sensor_z) + (obj_qi * sensor_y);
	const GEN_FLT x4 = (2 * ((x0 * obj_qk) + (-1 * x3 * obj_qi))) + obj_py + sensor_y;
	const GEN_FLT x5 = (2 * ((x3 * obj_qj) + (-1 * x1 * obj_qk))) + obj_px + sensor_x;
	const GEN_FLT x6 = (-1 * x5 * lh_qj) + (x2 * lh_qw) + (x4 * lh_qi);
	const GEN_FLT x7 = (-1 * x4 * lh_qk) + (x5 * lh_qw) + (x2 * lh_qj);
	const GEN_FLT x8 = x4 + lh_py + (2 * ((x7 * lh_qk) + (-1 * x6 * lh_qi)));
	const GEN_FLT x9 = (-1 * x2 * lh_qi) + (x4 * lh_qw) + (x5 * lh_qk);
	const GEN_FLT x10 = x2 + lh_pz + (2 * ((x9 * lh_qi) + (-1 * x7 * lh_qj)));
	const GEN_FLT x11 = -1 * x10;
	const GEN_FLT x12 = x10 * x10;
	const GEN_FLT x13 = x5 + lh_px + (2 * ((x6 * lh_qj) + (-1 * x9 * lh_qk)));
	const GEN_FLT x14 = atan2(x13, x11);
	const GEN_FLT x15 = (-1 * phase_0) + (-1 * asin(x8 * (1. / sqrt((x13 * x13) + x12)) * tilt_0)) + (-1 * x14);
	const GEN_FLT x16 =
		(-1 * phase_1) + (-1 * asin(x13 * (1. / sqrt((x8 * x8) + x12)) * tilt_1)) + (-1 * atan2(-1 * x8, x11));
	out[0] =
		x15 + ((atan2(x8, x11) * atan2(x8, x11)) * curve_0) + (-1 * cos(1.5707963267949 + x15 + gibPhase_0) * gibMag_0);
	out[1] = x16 + ((x14 * x14) * curve_1) + (-1 * cos(1.5707963267949 + x16 + gibPhase_1) * gibMag_1);
}

// Jacobian of reproject wrt [obj_px, obj_py, obj_pz, obj_qw, obj_qi, obj_qj, obj_qk]
static inline void gen_reproject_jac_obj_p(FLT *out, const SurvivePose *obj_p, const FLT *sensor_pt,
										   const SurvivePose *lh_p, const BaseStationCal *bsd) {
	const GEN_FLT obj_px = (*obj_p).Pos[0];
	const GEN_FLT obj_py = (*obj_p).Pos[1];
	const GEN_FLT obj_pz = (*obj_p).Pos[2];
	const GEN_FLT obj_qw = (*obj_p).Rot[0];
	const GEN_FLT obj_qi = (*obj_p).Rot[1];
	const GEN_FLT obj_qj = (*obj_p).Rot[2];
	const GEN_FLT obj_qk = (*obj_p).Rot[3];
	const GEN_FLT sensor_x = sensor_pt[0];
	const GEN_FLT sensor_y = sensor_pt[1];
	const GEN_FLT sensor_z = sensor_pt[2];
	const GEN_FLT lh_px = (*lh_p).Pos[0];
	const GEN_FLT lh_py = (*lh_p).Pos[1];
	const GEN_FLT lh_pz = (*lh_p).Pos[2];
	const GEN_FLT lh_qw = (*lh_p).Rot[0];
	const GEN_FLT lh_qi = (*lh_p).Rot[1];
	const GEN_FLT lh_qj = (*lh_p).Rot[2];
	const GEN_FLT lh_qk = (*lh_p).Rot[3];
	const GEN_FLT phase_0 = bsd[0].phase;
	const GEN_FLT tilt_0 = bsd[0].tilt;
	const GEN_FLT curve_0 = bsd[0].curve;
	const GEN_FLT gibPhase_0 = bsd[0].gibpha;
	const GEN_FLT gibMag_0 = bsd[0].gibmag;
	const GEN_FLT ogeeMag_0 = bsd[0].ogeephase;
	const GEN_FLT ogeePhase_0 = bsd[0].ogeemag;
	const GEN_FLT phase_1 = bsd[1].phase;
	const GEN_FLT tilt_1 = bsd[1].tilt;
	const GEN_FLT curve_1 = bsd[1].curve;
	const GEN_FLT gibPhase_1 = bsd[1].gibpha;
	const GEN_FLT gibMag_1 = bsd[1].gibmag;
	const GEN_FLT ogeeMag_1 = bsd[1].ogeephase;
	const GEN_FLT ogeePhase_1 = bsd[1].ogeemag;
	const GEN_FLT x0 = 2 * lh_qj;
	const GEN_FLT x1 = x0 * lh_qw;
	const GEN_FLT x2 = 2 * lh_qi;
	const GEN_FLT x3 = x2 * lh_qk;
	const GEN_FLT x4 = x3 + (-1 * x1);
	const GEN_FLT x5 = obj_qw * sensor_x;
	const GEN_FLT x6 = obj_qj * sensor_z;
	const GEN_FLT x7 = obj_qk * sensor_y;
	const GEN_FLT x8 = (-1 * x7) + x5 + x6;
	const GEN_FLT x9 = obj_qk * sensor_x;
	const GEN_FLT x10 = obj_qw * sensor_y;
	const GEN_FLT x11 = obj_qi * sensor_z;
	const GEN_FLT x12 = (-1 * x11) + x9 + x10;
	const GEN_FLT x13 = (2 * ((x12 * obj_qi) + (-1 * x8 * obj_qj))) + obj_pz + sensor_z;
	const GEN_FLT x14 = obj_qw * sensor_z;
	const GEN_FLT x15 = obj_qi * sensor_y;
	const GEN_FLT x16 = obj_qj * sensor_x;
	const GEN_FLT x17 = x14 + (-1 * x16) + x15;
	const GEN_FLT x18 = (2 * ((x8 * obj_qk) + (-1 * x17 * obj_qi))) + obj_py + sensor_y;
	const GEN_FLT x19 = (2 * ((x17 * obj_qj) + (-1 * x12 * obj_qk))) + obj_px + sensor_x;
	const GEN_FLT x20 = (x13 * lh_qw) + (-1 * x19 * lh_qj) + (x18 * lh_qi);
	const GEN_FLT x21 = (-1 * x18 * lh_qk) + (x19 * lh_qw) + (x13 * lh_qj);
	const GEN_FLT x22 = x18 + lh_py + (2 * ((x21 * lh_qk) + (-1 * x20 * lh_qi)));
	const GEN_FLT x23 = (x18 * lh_qw) + (-1 * x13 * lh_qi) + (x19 * lh_qk);
	const GEN_FLT x24 = x13 + lh_pz + (2 * ((x23 * lh_qi) + (-1 * x21 * lh_qj)));
	const GEN_FLT x25 = x24 * x24;
	const GEN_FLT x26 = 1. / x25;
	const GEN_FLT x27 = x22 * x26;
	const GEN_FLT x28 = x4 * x27;
	const GEN_FLT x29 = x0 * lh_qi;
	const GEN_FLT x30 = 2 * lh_qw;
	const GEN_FLT x31 = x30 * lh_qk;
	const GEN_FLT x32 = x31 + x29;
	const GEN_FLT x33 = 1. / x24;
	const GEN_FLT x34 = x32 * x33;
	const GEN_FLT x35 = -1 * x24;
	const GEN_FLT x36 = x22 * x22;
	const GEN_FLT x37 = x25 + x36;
	const GEN_FLT x38 = 1. / x37;
	const GEN_FLT x39 = x38 * x25;
	const GEN_FLT x40 = 2 * x39 * atan2(x22, x35) * curve_0;
	const GEN_FLT x41 = x19 + lh_px + (2 * ((x20 * lh_qj) + (-1 * x23 * lh_qk)));
	const GEN_FLT x42 = x41 * x26;
	const GEN_FLT x43 = -2 * (lh_qk * lh_qk);
	const GEN_FLT x44 = -2 * (lh_qj * lh_qj);
	const GEN_FLT x45 = 1 + x44 + x43;
	const GEN_FLT x46 = x41 * x41;
	const GEN_FLT x47 = x25 + x46;
	const GEN_FLT x48 = 1. / x47;
	const GEN_FLT x49 = x48 * x25;
	const GEN_FLT x50 = x49 * ((-1 * x45 * x33) + (x4 * x42));
	const GEN_FLT x51 = (1. / sqrt(x47)) * tilt_0;
	const GEN_FLT x52 = 2 * x41;
	const GEN_FLT x53 = 2 * x24;
	const GEN_FLT x54 = x4 * x53;
	const GEN_FLT x55 = 1.0 / 2.0 * (1. / (x47 * sqrt(x47))) * x22 * tilt_0;
	const GEN_FLT x56 = 1. / sqrt(1 + (-1 * x48 * x36 * (tilt_0 * tilt_0)));
	const GEN_FLT x57 = (-1 * x56 * ((-1 * x55 * (x54 + (x52 * x45))) + (x51 * x32))) + (-1 * x50);
	const GEN_FLT x58 = atan2(x41, x35);
	const GEN_FLT x59 =
		sin(1.5707963267949 + (-1 * x58) + gibPhase_0 + (-1 * phase_0) + (-1 * asin(x51 * x22))) * gibMag_0;
	const GEN_FLT x60 = x0 * lh_qk;
	const GEN_FLT x61 = x30 * lh_qi;
	const GEN_FLT x62 = x61 + x60;
	const GEN_FLT x63 = x62 * x27;
	const GEN_FLT x64 = 1 + (-2 * (lh_qi * lh_qi));
	const GEN_FLT x65 = x64 + x43;
	const GEN_FLT x66 = x65 * x33;
	const GEN_FLT x67 = x29 + (-1 * x31);
	const GEN_FLT x68 = ((-1 * x67 * x33) + (x62 * x42)) * x49;
	const GEN_FLT x69 = x62 * x53;
	const GEN_FLT x70 = (-1 * x56 * ((-1 * x55 * (x69 + (x67 * x52))) + (x65 * x51))) + (-1 * x68);
	const GEN_FLT x71 = x64 + x44;
	const GEN_FLT x72 = x71 * x27;
	const GEN_FLT x73 = x60 + (-1 * x61);
	const GEN_FLT x74 = x73 * x33;
	const GEN_FLT x75 = x1 + x3;
	const GEN_FLT x76 = ((-1 * x75 * x33) + (x71 * x42)) * x49;
	const GEN_FLT x77 = x71 * x53;
	const GEN_FLT x78 = (-1 * x56 * ((-1 * x55 * (x77 + (x75 * x52))) + (x73 * x51))) + (-1 * x76);
	const GEN_FLT x79 = 2 * x16;
	const GEN_FLT x80 = 2 * x15;
	const GEN_FLT x81 = x80 + (-1 * x79);
	const GEN_FLT x82 = 2 * x11;
	const GEN_FLT x83 = 2 * x9;
	const GEN_FLT x84 = x83 + (-1 * x82);
	const GEN_FLT x85 = 2 * x7;
	const GEN_FLT x86 = 2 * x6;
	const GEN_FLT x87 = x86 + (-1 * x85);
	const GEN_FLT x88 = (x87 * lh_qk) + (-1 * x81 * lh_qi) + (x84 * lh_qw);
	const GEN_FLT x89 = (x81 * lh_qj) + (-1 * x84 * lh_qk) + (x87 * lh_qw);
	const GEN_FLT x90 = x81 + (x2 * x88) + (-1 * x0 * x89);
	const GEN_FLT x91 = x90 * x27;
	const GEN_FLT x92 = 2 * lh_qk;
	const GEN_FLT x93 = (x84 * lh_qi) + (x81 * lh_qw) + (-1 * x87 * lh_qj);
	const GEN_FLT x94 = x84 + (x89 * x92) + (-1 * x2 * x93);
	const GEN_FLT x95 = x94 * x33;
	const GEN_FLT x96 = x87 + (x0 * x93) + (-1 * x88 * x92);
	const GEN_FLT x97 = ((-1 * x96 * x33) + (x90 * x42)) * x49;
	const GEN_FLT x98 = x53 * x90;
	const GEN_FLT x99 = (-1 * x56 * ((-1 * x55 * (x98 + (x52 * x96))) + (x51 * x94))) + (-1 * x97);
	const GEN_FLT x100 = 2 * x10;
	const GEN_FLT x101 = x100 + x83 + (-4 * x11);
	const GEN_FLT x102 = 2 * x14;
	const GEN_FLT x103 = (-4 * x15) + x79 + (-1 * x102);
	const GEN_FLT x104 = 2 * obj_qk * sensor_z;
	const GEN_FLT x105 = 2 * obj_qj * sensor_y;
	const GEN_FLT x106 = x105 + x104;
	const GEN_FLT x107 = (x106 * lh_qk) + (-1 * x101 * lh_qi) + (x103 * lh_qw);
	const GEN_FLT x108 = (-1 * x103 * lh_qk) + (x101 * lh_qj) + (x106 * lh_qw);
	const GEN_FLT x109 = x101 + (x2 * x107) + (-1 * x0 * x108);
	const GEN_FLT x110 = x26 * x109;
	const GEN_FLT x111 = x22 * x110;
	const GEN_FLT x112 = (x101 * lh_qw) + (x103 * lh_qi) + (-1 * x106 * lh_qj);
	const GEN_FLT x113 = x103 + (x92 * x108) + (-1 * x2 * x112);
	const GEN_FLT x114 = x33 * x113;
	const GEN_FLT x115 = x106 + (x0 * x112) + (-1 * x92 * x107);
	const GEN_FLT x116 = ((-1 * x33 * x115) + (x41 * x110)) * x49;
	const GEN_FLT x117 = x53 * x109;
	const GEN_FLT x118 = (-1 * x56 * ((-1 * x55 * (x117 + (x52 * x115))) + (x51 * x113))) + (-1 * x116);
	const GEN_FLT x119 = 2 * x5;
	const GEN_FLT x120 = (-4 * x6) + (-1 * x119) + x85;
	const GEN_FLT x121 = 2 * obj_qi * sensor_x;
	const GEN_FLT x122 = x104 + x121;
	const GEN_FLT x123 = x80 + (-4 * x16) + x102;
	const GEN_FLT x124 = (x123 * lh_qk) + (-1 * x120 * lh_qi) + (x122 * lh_qw);
	const GEN_FLT x125 = (x120 * lh_qj) + (-1 * x122 * lh_qk) + (x123 * lh_qw);
	const GEN_FLT x126 = x120 + (x2 * x124) + (-1 * x0 * x125);
	const GEN_FLT x127 = x27 * x126;
	const GEN_FLT x128 = (x122 * lh_qi) + (-1 * x123 * lh_qj) + (x120 * lh_qw);
	const GEN_FLT x129 = x122 + (x92 * x125) + (-1 * x2 * x128);
	const GEN_FLT x130 = x33 * x129;
	const GEN_FLT x131 = x123 + (x0 * x128) + (-1 * x92 * x124);
	const GEN_FLT x132 = ((-1 * x33 * x131) + (x42 * x126)) * x49;
	const GEN_FLT x133 = x53 * x126;
	const GEN_FLT x134 = (-1 * x56 * ((-1 * x55 * (x133 + (x52 * x131))) + (x51 * x129))) + (-1 * x132);
	const GEN_FLT x135 = x86 + x119 + (-4 * x7);
	const GEN_FLT x136 = x121 + x105;
	const GEN_FLT x137 = (-1 * x100) + (-4 * x9) + x82;
	const GEN_FLT x138 = (x137 * lh_qk) + (x135 * lh_qw) + (-1 * x136 * lh_qi);
	const GEN_FLT x139 = (x136 * lh_qj) + (-1 * x135 * lh_qk) + (x137 * lh_qw);
	const GEN_FLT x140 = x136 + (x2 * x138) + (-1 * x0 * x139);
	const GEN_FLT x141 = x27 * x140;
	const GEN_FLT x142 = (x135 * lh_qi) + (-1 * x137 * lh_qj) + (x136 * lh_qw);
	const GEN_FLT x143 = x135 + (x92 * x139) + (-1 * x2 * x142);
	const GEN_FLT x144 = x33 * x143;
	const GEN_FLT x145 = x137 + (x0 * x142) + (-1 * x92 * x138);
	const GEN_FLT x146 = ((-1 * x33 * x145) + (x42 * x140)) * x49;
	const GEN_FLT x147 = x53 * x140;
	const GEN_FLT x148 = (-1 * x56 * ((-1 * x55 * (x147 + (x52 * x145))) + (x51 * x143))) + (-1 * x146);
	const GEN_FLT x149 = 1. / sqrt(1 + (-1 * x46 * x38 * (tilt_1 * tilt_1)));
	const GEN_FLT x150 = (1. / sqrt(x37)) * tilt_1;
	const GEN_FLT x151 = 2 * x22;
	const GEN_FLT x152 = 1.0 / 2.0 * x41 * (1. / (x37 * sqrt(x37))) * tilt_1;
	const GEN_FLT x153 =
		(-1 * x149 * ((-1 * x152 * (x54 + (x32 * x151))) + (x45 * x150))) + (-1 * (x34 + (-1 * x28)) * x39);
	const GEN_FLT x154 =
		sin(1.5707963267949 + (-1 * phase_1) + (-1 * atan2(-1 * x22, x35)) + gibPhase_1 + (-1 * asin(x41 * x150))) *
		gibMag_1;
	const GEN_FLT x155 = 2 * x58 * curve_1;
	const GEN_FLT x156 =
		(-1 * x149 * ((-1 * x152 * (x69 + (x65 * x151))) + (x67 * x150))) + (-1 * (x66 + (-1 * x63)) * x39);
	const GEN_FLT x157 =
		(-1 * x149 * ((-1 * x152 * (x77 + (x73 * x151))) + (x75 * x150))) + (-1 * (x74 + (-1 * x72)) * x39);
	const GEN_FLT x158 =
		(-1 * x149 * ((-1 * x152 * (x98 + (x94 * x151))) + (x96 * x150))) + (-1 * (x95 + (-1 * x91)) * x39);
	const GEN_FLT x159 =
		(-1 * x149 * ((-1 * x152 * (x117 + (x113 * x151))) + (x115 * x150))) + (-1 * (x114 + (-1 * x111)) * x39);
	const GEN_FLT x160 =
		(-1 * x149 * ((-1 * x152 * (x133 + (x129 * x151))) + (x131 * x150))) + (-1 * (x130 + (-1 * x127)) * x39);
	const GEN_FLT x161 =
		(-1 * x149 * ((-1 * x152 * (x147 + (x143 * x151))) + (x145 * x150))) + (-1 * (x144 + (-1 * x141)) * x39);
	out[0] = x57 + (((-1 * x34) + x28) * x40) + (x57 * x59);
	out[1] = x70 + (((-1 * x66) + x63) * x40) + (x70 * x59);
	out[2] = x78 + (((-1 * x74) + x72) * x40) + (x78 * x59);
	out[3] = x99 + (((-1 * x95) + x91) * x40) + (x59 * x99);
	out[4] = (((-1 * x114) + x111) * x40) + x118 + (x59 * x118);
	out[5] = x134 + (((-1 * x130) + x127) * x40) + (x59 * x134);
	out[6] = x148 + (((-1 * x144) + x141) * x40) + (x59 * x148);
	out[7] = x153 + (x153 * x154) + (x50 * x155);
	out[8] = (x154 * x156) + x156 + (x68 * x155);
	out[9] = (x76 * x155) + x157 + (x154 * x157);
	out[10] = (x154 * x158) + x158 + (x97 * x155);
	out[11] = x159 + (x154 * x159) + (x116 * x155);
	out[12] = x160 + (x160 * x154) + (x132 * x155);
	out[13] = x161 + (x161 * x154) + (x146 * x155);
}

// Jacobian of reproject wrt [sensor_x, sensor_y, sensor_z]
static inline void gen_reproject_jac_sensor_pt(FLT *out, const SurvivePose *obj_p, const FLT *sensor_pt,
											   const SurvivePose *lh_p, const BaseStationCal *bsd) {
	const GEN_FLT obj_px = (*obj_p).Pos[0];
	const GEN_FLT obj_py = (*obj_p).Pos[1];
	const GEN_FLT obj_pz = (*obj_p).Pos[2];
	const GEN_FLT obj_qw = (*obj_p).Rot[0];
	const GEN_FLT obj_qi = (*obj_p).Rot[1];
	const GEN_FLT obj_qj = (*obj_p).Rot[2];
	const GEN_FLT obj_qk = (*obj_p).Rot[3];
	const GEN_FLT sensor_x = sensor_pt[0];
	const GEN_FLT sensor_y = sensor_pt[1];
	const GEN_FLT sensor_z = sensor_pt[2];
	const GEN_FLT lh_px = (*lh_p).Pos[0];
	const GEN_FLT lh_py = (*lh_p).Pos[1];
	const GEN_FLT lh_pz = (*lh_p).Pos[2];
	const GEN_FLT lh_qw = (*lh_p).Rot[0];
	const GEN_FLT lh_qi = (*lh_p).Rot[1];
	const GEN_FLT lh_qj = (*lh_p).Rot[2];
	const GEN_FLT lh_qk = (*lh_p).Rot[3];
	const GEN_FLT phase_0 = bsd[0].phase;
	const GEN_FLT tilt_0 = bsd[0].tilt;
	const GEN_FLT curve_0 = bsd[0].curve;
	const GEN_FLT gibPhase_0 = bsd[0].gibpha;
	const GEN_FLT gibMag_0 = bsd[0].gibmag;
	const GEN_FLT ogeeMag_0 = bsd[0].ogeephase;
	const GEN_FLT ogeePhase_0 = bsd[0].ogeemag;
	const GEN_FLT phase_1 = bsd[1].phase;
	const GEN_FLT tilt_1 = bsd[1].tilt;
	const GEN_FLT curve_1 = bsd[1].curve;
	const GEN_FLT gibPhase_1 = bsd[1].gibpha;
	const GEN_FLT gibMag_1 = bsd[1].gibmag;
	const GEN_FLT ogeeMag_1 = bsd[1].ogeephase;
	const GEN_FLT ogeePhase_1 = bsd[1].ogeemag;
	const GEN_FLT x0 = 2 * obj_qj;
	const GEN_FLT x1 = x0 * obj_qw;
	const GEN_FLT x2 = 2 * obj_qk;
	const GEN_FLT x3 = x2 * obj_qi;
	const GEN_FLT x4 = x3 + (-1 * x1);
	const GEN_FLT x5 = x0 * obj_qi;
	const GEN_FLT x6 = x2 * obj_qw;
	const GEN_FLT x7 = x6 + x5;
	const GEN_FLT x8 = -2 * (obj_qk * obj_qk);
	const GEN_FLT x9 = -2 * (obj_qj * obj_qj);
	const GEN_FLT x10 = 1 + x9 + x8;
	const GEN_FLT x11 = (x10 * lh_qk) + (-1 * x4 * lh_qi) + (x7 * lh_qw);
	const GEN_FLT x12 = 2 * lh_qi;
	const GEN_FLT x13 = (x4 * lh_qj) + (x10 * lh_qw) + (-1 * x7 * lh_qk);
	const GEN_FLT x14 = 2 * lh_qj;
	const GEN_FLT x15 = x4 + (x12 * x11) + (-1 * x14 * x13);
	const GEN_FLT x16 = (obj_qw * sensor_x) + (-1 * obj_qk * sensor_y) + (obj_qj * sensor_z);
	const GEN_FLT x17 = (obj_qk * sensor_x) + (-1 * obj_qi * sensor_z) + (obj_qw * sensor_y);
	const GEN_FLT x18 = (2 * ((x17 * obj_qi) + (-1 * x16 * obj_qj))) + obj_pz + sensor_z;
	const GEN_FLT x19 = (-1 * obj_qj * sensor_x) + (obj_qw * sensor_z) + (obj_qi * sensor_y);
	const GEN_FLT x20 = obj_py + (2 * ((x16 * obj_qk) + (-1 * x19 * obj_qi))) + sensor_y;
	const GEN_FLT x21 = obj_px + (2 * ((x19 * obj_qj) + (-1 * x17 * obj_qk))) + sensor_x;
	const GEN_FLT x22 = (-1 * x21 * lh_qj) + (x18 * lh_qw) + (x20 * lh_qi);
	const GEN_FLT x23 = (-1 * x20 * lh_qk) + (x21 * lh_qw) + (x18 * lh_qj);
	const GEN_FLT x24 = x20 + lh_py + (2 * ((x23 * lh_qk) + (-1 * x22 * lh_qi)));
	const GEN_FLT x25 = (-1 * x18 * lh_qi) + (x20 * lh_qw) + (x21 * lh_qk);
	const GEN_FLT x26 = x18 + lh_pz + (2 * ((x25 * lh_qi) + (-1 * x23 * lh_qj)));
	const GEN_FLT x27 = x26 * x26;
	const GEN_FLT x28 = 1. / x27;
	const GEN_FLT x29 = x24 * x28;
	const GEN_FLT x30 = x29 * x15;
	const GEN_FLT x31 = 2 * lh_qk;
	const GEN_FLT x32 = (x7 * lh_qi) + (-1 * x10 * lh_qj) + (x4 * lh_qw);
	const GEN_FLT x33 = x7 + (x31 * x13) + (-1 * x32 * x12);
	const GEN_FLT x34 = 1. / x26;
	const GEN_FLT x35 = x34 * x33;
	const GEN_FLT x36 = -1 * x26;
	const GEN_FLT x37 = x24 * x24;
	const GEN_FLT x38 = x27 + x37;
	const GEN_FLT x39 = 1. / x38;
	const GEN_FLT x40 = x39 * x27;
	const GEN_FLT x41 = 2 * x40 * atan2(x24, x36) * curve_0;
	const GEN_FLT x42 = x21 + lh_px + (2 * ((x22 * lh_qj) + (-1 * x25 * lh_qk)));
	const GEN_FLT x43 = x42 * x28;
	const GEN_FLT x44 = x10 + (x32 * x14) + (-1 * x31 * x11);
	const GEN_FLT x45 = x42 * x42;
	const GEN_FLT x46 = x27 + x45;
	const GEN_FLT x47 = 1. / x46;
	const GEN_FLT x48 = x47 * x27;
	const GEN_FLT x49 = ((-1 * x44 * x34) + (x43 * x15)) * x48;
	const GEN_FLT x50 = 1. / sqrt(1 + (-1 * x47 * x37 * (tilt_0 * tilt_0)));
	const GEN_FLT x51 = (1. / sqrt(x46)) * tilt_0;
	const GEN_FLT x52 = 2 * x42;
	const GEN_FLT x53 = 2 * x26;
	const GEN_FLT x54 = x53 * x15;
	const GEN_FLT x55 = 1.0 / 2.0 * (1. / (x46 * sqrt(x46))) * x24 * tilt_0;
	const GEN_FLT x56 = (-1 * x50 * ((-1 * x55 * (x54 + (x52 * x44))) + (x51 * x33))) + (-1 * x49);
	const GEN_FLT x57 = atan2(x42, x36);
	const GEN_FLT x58 =
		sin(1.5707963267949 + (-1 * phase_0) + (-1 * x57) + gibPhase_0 + (-1 * asin(x51 * x24))) * gibMag_0;
	const GEN_FLT x59 = x2 * obj_qj;
	const GEN_FLT x60 = 2 * obj_qw * obj_qi;
	const GEN_FLT x61 = x60 + x59;
	const GEN_FLT x62 = 1 + (-2 * (obj_qi * obj_qi));
	const GEN_FLT x63 = x62 + x8;
	const GEN_FLT x64 = x5 + (-1 * x6);
	const GEN_FLT x65 = (x64 * lh_qk) + (-1 * x61 * lh_qi) + (x63 * lh_qw);
	const GEN_FLT x66 = (x61 * lh_qj) + (x64 * lh_qw) + (-1 * x63 * lh_qk);
	const GEN_FLT x67 = x61 + (x65 * x12) + (-1 * x66 * x14);
	const GEN_FLT x68 = x67 * x29;
	const GEN_FLT x69 = (x63 * lh_qi) + (-1 * x64 * lh_qj) + (x61 * lh_qw);
	const GEN_FLT x70 = x63 + (x66 * x31) + (-1 * x69 * x12);
	const GEN_FLT x71 = x70 * x34;
	const GEN_FLT x72 = (x69 * x14) + x64 + (-1 * x65 * x31);
	const GEN_FLT x73 = ((-1 * x72 * x34) + (x67 * x43)) * x48;
	const GEN_FLT x74 = x67 * x53;
	const GEN_FLT x75 = (-1 * x50 * ((-1 * x55 * (x74 + (x72 * x52))) + (x70 * x51))) + (-1 * x73);
	const GEN_FLT x76 = x62 + x9;
	const GEN_FLT x77 = x59 + (-1 * x60);
	const GEN_FLT x78 = x1 + x3;
	const GEN_FLT x79 = (x78 * lh_qk) + (-1 * x76 * lh_qi) + (x77 * lh_qw);
	const GEN_FLT x80 = (-1 * x77 * lh_qk) + (x76 * lh_qj) + (x78 * lh_qw);
	const GEN_FLT x81 = x76 + (x79 * x12) + (-1 * x80 * x14);
	const GEN_FLT x82 = x81 * x29;
	const GEN_FLT x83 = (x77 * lh_qi) + (-1 * x78 * lh_qj) + (x76 * lh_qw);
	const GEN_FLT x84 = (x80 * x31) + x77 + (-1 * x83 * x12);
	const GEN_FLT x85 = x84 * x34;
	const GEN_FLT x86 = x78 + (x83 * x14) + (-1 * x79 * x31);
	const GEN_FLT x87 = ((-1 * x86 * x34) + (x81 * x43)) * x48;
	const GEN_FLT x88 = x81 * x53;
	const GEN_FLT x89 = (-1 * x50 * ((-1 * x55 * (x88 + (x86 * x52))) + (x84 * x51))) + (-1 * x87);
	const GEN_FLT x90 = 1. / sqrt(1 + (-1 * x45 * x39 * (tilt_1 * tilt_1)));
	const GEN_FLT x91 = (1. / sqrt(x38)) * tilt_1;
	const GEN_FLT x92 = 2 * x24;
	const GEN_FLT x93 = 1.0 / 2.0 * x42 * (1. / (x38 * sqrt(x38))) * tilt_1;
	const GEN_FLT x94 = (-1 * x90 * ((-1 * x93 * (x54 + (x92 * x33))) + (x91 * x44))) + (-1 * (x35 + (-1 * x30)) * x40);
	const GEN_FLT x95 =
		sin(1.5707963267949 + (-1 * phase_1) + (-1 * atan2(-1 * x24, x36)) + gibPhase_1 + (-1 * asin(x91 * x42))) *
		gibMag_1;
	const GEN_FLT x96 = 2 * x57 * curve_1;
	const GEN_FLT x97 = (-1 * x90 * ((-1 * x93 * (x74 + (x70 * x92))) + (x72 * x91))) + (-1 * (x71 + (-1 * x68)) * x40);
	const GEN_FLT x98 = (-1 * x90 * ((-1 * x93 * (x88 + (x84 * x92))) + (x86 * x91))) + (-1 * (x85 + (-1 * x82)) * x40);
	out[0] = x56 + (((-1 * x35) + x30) * x41) + (x58 * x56);
	out[1] = x75 + (((-1 * x71) + x68) * x41) + (x75 * x58);
	out[2] = x89 + (((-1 * x85) + x82) * x41) + (x89 * x58);
	out[3] = x94 + (x95 * x94) + (x96 * x49);
	out[4] = x97 + (x97 * x95) + (x73 * x96);
	out[5] = (x98 * x95) + x98 + (x87 * x96);
}

// Jacobian of reproject wrt [lh_px, lh_py, lh_pz, lh_qw, lh_qi, lh_qj, lh_qk]
static inline void gen_reproject_jac_lh_p(FLT *out, const SurvivePose *obj_p, const FLT *sensor_pt,
										  const SurvivePose *lh_p, const BaseStationCal *bsd) {
	const GEN_FLT obj_px = (*obj_p).Pos[0];
	const GEN_FLT obj_py = (*obj_p).Pos[1];
	const GEN_FLT obj_pz = (*obj_p).Pos[2];
	const GEN_FLT obj_qw = (*obj_p).Rot[0];
	const GEN_FLT obj_qi = (*obj_p).Rot[1];
	const GEN_FLT obj_qj = (*obj_p).Rot[2];
	const GEN_FLT obj_qk = (*obj_p).Rot[3];
	const GEN_FLT sensor_x = sensor_pt[0];
	const GEN_FLT sensor_y = sensor_pt[1];
	const GEN_FLT sensor_z = sensor_pt[2];
	const GEN_FLT lh_px = (*lh_p).Pos[0];
	const GEN_FLT lh_py = (*lh_p).Pos[1];
	const GEN_FLT lh_pz = (*lh_p).Pos[2];
	const GEN_FLT lh_qw = (*lh_p).Rot[0];
	const GEN_FLT lh_qi = (*lh_p).Rot[1];
	const GEN_FLT lh_qj = (*lh_p).Rot[2];
	const GEN_FLT lh_qk = (*lh_p).Rot[3];
	const GEN_FLT phase_0 = bsd[0].phase;
	const GEN_FLT tilt_0 = bsd[0].tilt;
	const GEN_FLT curve_0 = bsd[0].curve;
	const GEN_FLT gibPhase_0 = bsd[0].gibpha;
	const GEN_FLT gibMag_0 = bsd[0].gibmag;
	const GEN_FLT ogeeMag_0 = bsd[0].ogeephase;
	const GEN_FLT ogeePhase_0 = bsd[0].ogeemag;
	const GEN_FLT phase_1 = bsd[1].phase;
	const GEN_FLT tilt_1 = bsd[1].tilt;
	const GEN_FLT curve_1 = bsd[1].curve;
	const GEN_FLT gibPhase_1 = bsd[1].gibpha;
	const GEN_FLT gibMag_1 = bsd[1].gibmag;
	const GEN_FLT ogeeMag_1 = bsd[1].ogeephase;
	const GEN_FLT ogeePhase_1 = bsd[1].ogeemag;
	const GEN_FLT x0 = (-1 * obj_qj * sensor_x) + (obj_qw * sensor_z) + (obj_qi * sensor_y);
	const GEN_FLT x1 = (obj_qw * sensor_x) + (-1 * obj_qk * sensor_y) + (obj_qj * sensor_z);
	const GEN_FLT x2 = 2 * ((x1 * obj_qk) + (-1 * x0 * obj_qi));
	const GEN_FLT x3 = x2 + obj_py + sensor_y;
	const GEN_FLT x4 = x3 * lh_qw;
	const GEN_FLT x5 = (obj_qk * sensor_x) + (-1 * obj_qi * sensor_z) + (obj_qw * sensor_y);
	const GEN_FLT x6 = 2 * ((x0 * obj_qj) + (-1 * x5 * obj_qk));
	const GEN_FLT x7 = x6 + obj_px + sensor_x;
	const GEN_FLT x8 = x7 * lh_qk;
	const GEN_FLT x9 = 2 * ((x5 * obj_qi) + (-1 * x1 * obj_qj));
	const GEN_FLT x10 = x9 + obj_pz + sensor_z;
	const GEN_FLT x11 = x10 * lh_qi;
	const GEN_FLT x12 = (-1 * x11) + x4 + x8;
	const GEN_FLT x13 = x10 * lh_qw;
	const GEN_FLT x14 = x3 * lh_qi;
	const GEN_FLT x15 = x7 * lh_qj;
	const GEN_FLT x16 = (-1 * x15) + x13 + x14;
	const GEN_FLT x17 = x7 + lh_px + (2 * ((x16 * lh_qj) + (-1 * x12 * lh_qk)));
	const GEN_FLT x18 = x17 * x17;
	const GEN_FLT x19 = x7 * lh_qw;
	const GEN_FLT x20 = x10 * lh_qj;
	const GEN_FLT x21 = x3 * lh_qk;
	const GEN_FLT x22 = (-1 * x21) + x19 + x20;
	const GEN_FLT x23 = x10 + lh_pz + (2 * ((x12 * lh_qi) + (-1 * x22 * lh_qj)));
	const GEN_FLT x24 = x23 * x23;
	const GEN_FLT x25 = x24 + x18;
	const GEN_FLT x26 = 1. / x25;
	const GEN_FLT x27 = x23 * x26;
	const GEN_FLT x28 = x3 + lh_py + (2 * ((x22 * lh_qk) + (-1 * x16 * lh_qi)));
	const GEN_FLT x29 = x28 * x28;
	const GEN_FLT x30 = 1. / sqrt(1 + (-1 * x29 * x26 * (tilt_0 * tilt_0)));
	const GEN_FLT x31 = (1. / (x25 * sqrt(x25))) * x28 * tilt_0;
	const GEN_FLT x32 = x30 * x31;
	const GEN_FLT x33 = (x32 * x17) + x27;
	const GEN_FLT x34 = (1. / sqrt(x25)) * tilt_0;
	const GEN_FLT x35 = -1 * x23;
	const GEN_FLT x36 = atan2(x17, x35);
	const GEN_FLT x37 =
		sin(1.5707963267949 + (-1 * phase_0) + (-1 * x36) + gibPhase_0 + (-1 * asin(x34 * x28))) * gibMag_0;
	const GEN_FLT x38 = x30 * x34;
	const GEN_FLT x39 = x24 + x29;
	const GEN_FLT x40 = 1. / x39;
	const GEN_FLT x41 = x40 * x23;
	const GEN_FLT x42 = 2 * atan2(x28, x35) * curve_0;
	const GEN_FLT x43 = x40 * x28;
	const GEN_FLT x44 = x26 * x17;
	const GEN_FLT x45 = (x32 * x23) + (-1 * x44);
	const GEN_FLT x46 = 2 * x15;
	const GEN_FLT x47 = (2 * x14) + (-1 * x46);
	const GEN_FLT x48 = 1. / x24;
	const GEN_FLT x49 = x48 * x28;
	const GEN_FLT x50 = x47 * x49;
	const GEN_FLT x51 = 1. / x23;
	const GEN_FLT x52 = 2 * x11;
	const GEN_FLT x53 = (2 * x8) + (-1 * x52);
	const GEN_FLT x54 = x53 * x51;
	const GEN_FLT x55 = x40 * x24;
	const GEN_FLT x56 = x55 * x42;
	const GEN_FLT x57 = x48 * x17;
	const GEN_FLT x58 = 2 * x21;
	const GEN_FLT x59 = (2 * x20) + (-1 * x58);
	const GEN_FLT x60 = x24 * x26;
	const GEN_FLT x61 = ((-1 * x51 * x59) + (x57 * x47)) * x60;
	const GEN_FLT x62 = 2 * x17;
	const GEN_FLT x63 = 2 * x23;
	const GEN_FLT x64 = x63 * x47;
	const GEN_FLT x65 = 1.0 / 2.0 * x31;
	const GEN_FLT x66 = (-1 * x30 * ((-1 * x65 * (x64 + (x62 * x59))) + (x53 * x34))) + (-1 * x61);
	const GEN_FLT x67 = 2 * x4;
	const GEN_FLT x68 = (-1 * obj_pz) + (-1 * sensor_z) + (-1 * x9);
	const GEN_FLT x69 = 2 * lh_qi;
	const GEN_FLT x70 = x53 + x67 + (x68 * x69);
	const GEN_FLT x71 = x70 * x49;
	const GEN_FLT x72 = 2 * x13;
	const GEN_FLT x73 = (-4 * x14) + x46 + (-1 * x72);
	const GEN_FLT x74 = x73 * x51;
	const GEN_FLT x75 = 2 * lh_qk;
	const GEN_FLT x76 = 2 * lh_qj;
	const GEN_FLT x77 = (x3 * x76) + (-1 * x75 * x68);
	const GEN_FLT x78 = ((-1 * x77 * x51) + (x70 * x57)) * x60;
	const GEN_FLT x79 = x70 * x63;
	const GEN_FLT x80 = (-1 * x30 * ((-1 * x65 * (x79 + (x77 * x62))) + (x73 * x34))) + (-1 * x78);
	const GEN_FLT x81 = 2 * x19;
	const GEN_FLT x82 = (-4 * x20) + (-1 * x81) + x58;
	const GEN_FLT x83 = x82 * x49;
	const GEN_FLT x84 = 2 * ((-1 * sensor_x) + (-1 * obj_px) + (-1 * x6));
	const GEN_FLT x85 = (x75 * x10) + (-1 * x84 * lh_qi);
	const GEN_FLT x86 = x85 * x51;
	const GEN_FLT x87 = x47 + (x84 * lh_qj) + x72;
	const GEN_FLT x88 = ((-1 * x87 * x51) + (x82 * x57)) * x60;
	const GEN_FLT x89 = x82 * x63;
	const GEN_FLT x90 = (-1 * x30 * ((-1 * x65 * (x89 + (x87 * x62))) + (x85 * x34))) + (-1 * x88);
	const GEN_FLT x91 = (-1 * sensor_y) + (-1 * obj_py) + (-1 * x2);
	const GEN_FLT x92 = (x7 * x69) + (-1 * x76 * x91);
	const GEN_FLT x93 = x92 * x49;
	const GEN_FLT x94 = x59 + x81 + (x75 * x91);
	const GEN_FLT x95 = x51 * x94;
	const GEN_FLT x96 = (-4 * x8) + (-1 * x67) + x52;
	const GEN_FLT x97 = ((-1 * x51 * x96) + (x57 * x92)) * x60;
	const GEN_FLT x98 = x63 * x92;
	const GEN_FLT x99 = (-1 * x30 * ((-1 * x65 * (x98 + (x62 * x96))) + (x94 * x34))) + (-1 * x97);
	const GEN_FLT x100 = 1. / sqrt(1 + (-1 * x40 * x18 * (tilt_1 * tilt_1)));
	const GEN_FLT x101 = (1. / sqrt(x39)) * tilt_1;
	const GEN_FLT x102 = x101 * x100;
	const GEN_FLT x103 =
		sin(1.5707963267949 + (-1 * phase_1) + (-1 * atan2(-1 * x28, x35)) + gibPhase_1 + (-1 * asin(x17 * x101))) *
		gibMag_1;
	const GEN_FLT x104 = 2 * x36 * curve_1;
	const GEN_FLT x105 = (1. / (x39 * sqrt(x39))) * x17 * tilt_1;
	const GEN_FLT x106 = x100 * x105;
	const GEN_FLT x107 = (x28 * x106) + (-1 * x41);
	const GEN_FLT x108 = (x23 * x106) + x43;
	const GEN_FLT x109 = 2 * x28;
	const GEN_FLT x110 = 1.0 / 2.0 * x105;
	const GEN_FLT x111 =
		(-1 * x100 * ((-1 * x110 * (x64 + (x53 * x109))) + (x59 * x101))) + (-1 * (x54 + (-1 * x50)) * x55);
	const GEN_FLT x112 =
		(-1 * x100 * ((-1 * x110 * (x79 + (x73 * x109))) + (x77 * x101))) + (-1 * (x74 + (-1 * x71)) * x55);
	const GEN_FLT x113 =
		(-1 * x100 * ((-1 * x110 * (x89 + (x85 * x109))) + (x87 * x101))) + (-1 * (x86 + (-1 * x83)) * x55);
	const GEN_FLT x114 =
		(-1 * x100 * ((-1 * x110 * (x98 + (x94 * x109))) + (x96 * x101))) + (-1 * (x95 + (-1 * x93)) * x55);
	out[0] = x33 + (x33 * x37);
	out[1] = (-1 * x38 * x37) + (-1 * x38) + (-1 * x41 * x42);
	out[2] = (x42 * x43) + x45 + (x45 * x37);
	out[3] = (((-1 * x54) + x50) * x56) + x66 + (x66 * x37);
	out[4] = x80 + (((-1 * x74) + x71) * x56) + (x80 * x37);
	out[5] = (((-1 * x86) + x83) * x56) + x90 + (x90 * x37);
	out[6] = x99 + (((-1 * x95) + x93) * x56) + (x99 * x37);
	out[7] = (-1 * x102) + (-1 * x103 * x102) + (-1 * x27 * x104);
	out[8] = x107 + (x103 * x107);
	out[9] = x108 + (x103 * x108) + (x44 * x104);
	out[10] = x111 + (x103 * x111) + (x61 * x104);
	out[11] = x112 + (x103 * x112) + (x78 * x104);
	out[12] = x113 + (x103 * x113) + (x88 * x104);
	out[13] = x114 + (x103 * x114) + (x97 * x104);
}

// Jacobian of reproject wrt [phase_0, tilt_0, curve_0, gibPhase_0, gibMag_0, ogeeMag_0, ogeePhase_0, phase_1, tilt_1,
// curve_1, gibPhase_1, gibMag_1, ogeeMag_1, ogeePhase_1]
static inline void gen_reproject_jac_bsd(FLT *out, const SurvivePose *obj_p, const FLT *sensor_pt,
										 const SurvivePose *lh_p, const BaseStationCal *bsd) {
	const GEN_FLT obj_px = (*obj_p).Pos[0];
	const GEN_FLT obj_py = (*obj_p).Pos[1];
	const GEN_FLT obj_pz = (*obj_p).Pos[2];
	const GEN_FLT obj_qw = (*obj_p).Rot[0];
	const GEN_FLT obj_qi = (*obj_p).Rot[1];
	const GEN_FLT obj_qj = (*obj_p).Rot[2];
	const GEN_FLT obj_qk = (*obj_p).Rot[3];
	const GEN_FLT sensor_x = sensor_pt[0];
	const GEN_FLT sensor_y = sensor_pt[1];
	const GEN_FLT sensor_z = sensor_pt[2];
	const GEN_FLT lh_px = (*lh_p).Pos[0];
	const GEN_FLT lh_py = (*lh_p).Pos[1];
	const GEN_FLT lh_pz = (*lh_p).Pos[2];
	const GEN_FLT lh_qw = (*lh_p).Rot[0];
	const GEN_FLT lh_qi = (*lh_p).Rot[1];
	const GEN_FLT lh_qj = (*lh_p).Rot[2];
	const GEN_FLT lh_qk = (*lh_p).Rot[3];
	const GEN_FLT phase_0 = bsd[0].phase;
	const GEN_FLT tilt_0 = bsd[0].tilt;
	const GEN_FLT curve_0 = bsd[0].curve;
	const GEN_FLT gibPhase_0 = bsd[0].gibpha;
	const GEN_FLT gibMag_0 = bsd[0].gibmag;
	const GEN_FLT ogeeMag_0 = bsd[0].ogeephase;
	const GEN_FLT ogeePhase_0 = bsd[0].ogeemag;
	const GEN_FLT phase_1 = bsd[1].phase;
	const GEN_FLT tilt_1 = bsd[1].tilt;
	const GEN_FLT curve_1 = bsd[1].curve;
	const GEN_FLT gibPhase_1 = bsd[1].gibpha;
	const GEN_FLT gibMag_1 = bsd[1].gibmag;
	const GEN_FLT ogeeMag_1 = bsd[1].ogeephase;
	const GEN_FLT ogeePhase_1 = bsd[1].ogeemag;
	const GEN_FLT x0 = (obj_qk * sensor_x) + (-1 * obj_qi * sensor_z) + (obj_qw * sensor_y);
	const GEN_FLT x1 = (-1 * obj_qj * sensor_x) + (obj_qw * sensor_z) + (obj_qi * sensor_y);
	const GEN_FLT x2 = (2 * ((x1 * obj_qj) + (-1 * x0 * obj_qk))) + obj_px + sensor_x;
	const GEN_FLT x3 = (obj_qw * sensor_x) + (-1 * obj_qk * sensor_y) + (obj_qj * sensor_z);
	const GEN_FLT x4 = (2 * ((x0 * obj_qi) + (-1 * x3 * obj_qj))) + obj_pz + sensor_z;
	const GEN_FLT x5 = obj_py + (2 * ((x3 * obj_qk) + (-1 * x1 * obj_qi))) + sensor_y;
	const GEN_FLT x6 = (-1 * x5 * lh_qk) + (x2 * lh_qw) + (x4 * lh_qj);
	const GEN_FLT x7 = (x5 * lh_qw) + (-1 * x4 * lh_qi) + (x2 * lh_qk);
	const GEN_FLT x8 = x4 + lh_pz + (2 * ((x7 * lh_qi) + (-1 * x6 * lh_qj)));
	const GEN_FLT x9 = x8 * x8;
	const GEN_FLT x10 = (x4 * lh_qw) + (-1 * x2 * lh_qj) + (x5 * lh_qi);
	const GEN_FLT x11 = x2 + lh_px + (2 * ((x10 * lh_qj) + (-1 * x7 * lh_qk)));
	const GEN_FLT x12 = x11 * x11;
	const GEN_FLT x13 = x12 + x9;
	const GEN_FLT x14 = lh_py + x5 + (2 * ((x6 * lh_qk) + (-1 * x10 * lh_qi)));
	const GEN_FLT x15 = x14 * (1. / sqrt(x13));
	const GEN_FLT x16 = -1 * x8;
	const GEN_FLT x17 = atan2(x11, x16);
	const GEN_FLT x18 = 1.5707963267949 + gibPhase_0 + (-1 * phase_0) + (-1 * x17) + (-1 * asin(x15 * tilt_0));
	const GEN_FLT x19 = sin(x18) * gibMag_0;
	const GEN_FLT x20 = x14 * x14;
	const GEN_FLT x21 = x15 * (1. / sqrt(1 + (-1 * x20 * (1. / x13) * (tilt_0 * tilt_0))));
	const GEN_FLT x22 = x20 + x9;
	const GEN_FLT x23 = (1. / sqrt(x22)) * x11;
	const GEN_FLT x24 =
		1.5707963267949 + (-1 * atan2(-1 * x14, x16)) + gibPhase_1 + (-1 * phase_1) + (-1 * asin(x23 * tilt_1));
	const GEN_FLT x25 = sin(x24) * gibMag_1;
	const GEN_FLT x26 = x23 * (1. / sqrt(1 + (-1 * (1. / x22) * x12 * (tilt_1 * tilt_1))));
	out[0] = -1 + (-1 * x19);
	out[1] = (-1 * x21 * x19) + (-1 * x21);
	out[2] = atan2(x14, x16) * atan2(x14, x16);
	out[3] = x19;
	out[4] = -1 * cos(x18);
	out[5] = 0;
	out[6] = 0;
	out[7] = 0;
	out[8] = 0;
	out[9] = 0;
	out[10] = 0;
	out[11] = 0;
	out[12] = 0;
	out[13] = 0;
	out[14] = 0;
	out[15] = 0;
	out[16] = 0;
	out[17] = 0;
	out[18] = 0;
	out[19] = 0;
	out[20] = 0;
	out[21] = -1 + (-1 * x25);
	out[22] = (-1 * x26) + (-1 * x25 * x26);
	out[23] = x17 * x17;
	out[24] = x25;
	out[25] = -1 * cos(x24);
	out[26] = 0;
	out[27] = 0;
}

static inline FLT gen_reproject_axis_x(const SurvivePose *obj_p, const FLT *sensor_pt, const SurvivePose *lh_p,
									   const BaseStationCal *bsc0) {
	const GEN_FLT obj_px = (*obj_p).Pos[0];
	const GEN_FLT obj_py = (*obj_p).Pos[1];
	const GEN_FLT obj_pz = (*obj_p).Pos[2];
	const GEN_FLT obj_qw = (*obj_p).Rot[0];
	const GEN_FLT obj_qi = (*obj_p).Rot[1];
	const GEN_FLT obj_qj = (*obj_p).Rot[2];
	const GEN_FLT obj_qk = (*obj_p).Rot[3];
	const GEN_FLT sensor_x = sensor_pt[0];
	const GEN_FLT sensor_y = sensor_pt[1];
	const GEN_FLT sensor_z = sensor_pt[2];
	const GEN_FLT lh_px = (*lh_p).Pos[0];
	const GEN_FLT lh_py = (*lh_p).Pos[1];
	const GEN_FLT lh_pz = (*lh_p).Pos[2];
	const GEN_FLT lh_qw = (*lh_p).Rot[0];
	const GEN_FLT lh_qi = (*lh_p).Rot[1];
	const GEN_FLT lh_qj = (*lh_p).Rot[2];
	const GEN_FLT lh_qk = (*lh_p).Rot[3];
	const GEN_FLT phase_0 = (*bsc0).phase;
	const GEN_FLT tilt_0 = (*bsc0).tilt;
	const GEN_FLT curve_0 = (*bsc0).curve;
	const GEN_FLT gibPhase_0 = (*bsc0).gibpha;
	const GEN_FLT gibMag_0 = (*bsc0).gibmag;
	const GEN_FLT ogeeMag_0 = (*bsc0).ogeephase;
	const GEN_FLT ogeePhase_0 = (*bsc0).ogeemag;
	const GEN_FLT x0 = (obj_qw * sensor_x) + (-1 * obj_qk * sensor_y) + (obj_qj * sensor_z);
	const GEN_FLT x1 = (obj_qk * sensor_x) + (-1 * obj_qi * sensor_z) + (obj_qw * sensor_y);
	const GEN_FLT x2 = (2 * ((x1 * obj_qi) + (-1 * x0 * obj_qj))) + obj_pz + sensor_z;
	const GEN_FLT x3 = (-1 * obj_qj * sensor_x) + (obj_qw * sensor_z) + (obj_qi * sensor_y);
	const GEN_FLT x4 = (2 * ((x0 * obj_qk) + (-1 * x3 * obj_qi))) + obj_py + sensor_y;
	const GEN_FLT x5 = (2 * ((x3 * obj_qj) + (-1 * x1 * obj_qk))) + obj_px + sensor_x;
	const GEN_FLT x6 = (-1 * x5 * lh_qj) + (x2 * lh_qw) + (x4 * lh_qi);
	const GEN_FLT x7 = (-1 * x4 * lh_qk) + (x5 * lh_qw) + (x2 * lh_qj);
	const GEN_FLT x8 = x4 + lh_py + (2 * ((x7 * lh_qk) + (-1 * x6 * lh_qi)));
	const GEN_FLT x9 = (-1 * x2 * lh_qi) + (x4 * lh_qw) + (x5 * lh_qk);
	const GEN_FLT x10 = x2 + lh_pz + (2 * ((x9 * lh_qi) + (-1 * x7 * lh_qj)));
	const GEN_FLT x11 = -1 * x10;
	const GEN_FLT x12 = x5 + lh_px + (2 * ((x6 * lh_qj) + (-1 * x9 * lh_qk)));
	const GEN_FLT x13 =
		(-1 * asin((1. / sqrt((x12 * x12) + (x10 * x10))) * x8 * tilt_0)) + (-1 * phase_0) + (-1 * atan2(x12, x11));
	return x13 + ((atan2(x8, x11) * atan2(x8, x11)) * curve_0) +
		   (-1 * cos(1.5707963267949 + x13 + gibPhase_0) * gibMag_0);
}

// Jacobian of reproject_axis_x wrt [obj_px, obj_py, obj_pz, obj_qw, obj_qi, obj_qj, obj_qk]
static inline void gen_reproject_axis_x_jac_obj_p(FLT *out, const SurvivePose *obj_p, const FLT *sensor_pt,
												  const SurvivePose *lh_p, const BaseStationCal *bsc0) {
	const GEN_FLT obj_px = (*obj_p).Pos[0];
	const GEN_FLT obj_py = (*obj_p).Pos[1];
	const GEN_FLT obj_pz = (*obj_p).Pos[2];
	const GEN_FLT obj_qw = (*obj_p).Rot[0];
	const GEN_FLT obj_qi = (*obj_p).Rot[1];
	const GEN_FLT obj_qj = (*obj_p).Rot[2];
	const GEN_FLT obj_qk = (*obj_p).Rot[3];
	const GEN_FLT sensor_x = sensor_pt[0];
	const GEN_FLT sensor_y = sensor_pt[1];
	const GEN_FLT sensor_z = sensor_pt[2];
	const GEN_FLT lh_px = (*lh_p).Pos[0];
	const GEN_FLT lh_py = (*lh_p).Pos[1];
	const GEN_FLT lh_pz = (*lh_p).Pos[2];
	const GEN_FLT lh_qw = (*lh_p).Rot[0];
	const GEN_FLT lh_qi = (*lh_p).Rot[1];
	const GEN_FLT lh_qj = (*lh_p).Rot[2];
	const GEN_FLT lh_qk = (*lh_p).Rot[3];
	const GEN_FLT phase_0 = (*bsc0).phase;
	const GEN_FLT tilt_0 = (*bsc0).tilt;
	const GEN_FLT curve_0 = (*bsc0).curve;
	const GEN_FLT gibPhase_0 = (*bsc0).gibpha;
	const GEN_FLT gibMag_0 = (*bsc0).gibmag;
	const GEN_FLT ogeeMag_0 = (*bsc0).ogeephase;
	const GEN_FLT ogeePhase_0 = (*bsc0).ogeemag;
	const GEN_FLT x0 = 2 * lh_qj;
	const GEN_FLT x1 = x0 * lh_qw;
	const GEN_FLT x2 = 2 * lh_qk;
	const GEN_FLT x3 = x2 * lh_qi;
	const GEN_FLT x4 = x3 + (-1 * x1);
	const GEN_FLT x5 = obj_qw * sensor_x;
	const GEN_FLT x6 = obj_qj * sensor_z;
	const GEN_FLT x7 = obj_qk * sensor_y;
	const GEN_FLT x8 = (-1 * x7) + x5 + x6;
	const GEN_FLT x9 = obj_qk * sensor_x;
	const GEN_FLT x10 = obj_qw * sensor_y;
	const GEN_FLT x11 = obj_qi * sensor_z;
	const GEN_FLT x12 = (-1 * x11) + x9 + x10;
	const GEN_FLT x13 = (2 * ((x12 * obj_qi) + (-1 * x8 * obj_qj))) + obj_pz + sensor_z;
	const GEN_FLT x14 = obj_qw * sensor_z;
	const GEN_FLT x15 = obj_qi * sensor_y;
	const GEN_FLT x16 = obj_qj * sensor_x;
	const GEN_FLT x17 = x14 + (-1 * x16) + x15;
	const GEN_FLT x18 = (2 * ((x8 * obj_qk) + (-1 * x17 * obj_qi))) + obj_py + sensor_y;
	const GEN_FLT x19 = (2 * ((x17 * obj_qj) + (-1 * x12 * obj_qk))) + obj_px + sensor_x;
	const GEN_FLT x20 = (x13 * lh_qw) + (-1 * x19 * lh_qj) + (x18 * lh_qi);
	const GEN_FLT x21 = (-1 * x18 * lh_qk) + (x19 * lh_qw) + (x13 * lh_qj);
	const GEN_FLT x22 = x18 + lh_py + (2 * ((x21 * lh_qk) + (-1 * x20 * lh_qi)));
	const GEN_FLT x23 = (x18 * lh_qw) + (-1 * x13 * lh_qi) + (x19 * lh_qk);
	const GEN_FLT x24 = x13 + lh_pz + (2 * ((x23 * lh_qi) + (-1 * x21 * lh_qj)));
	const GEN_FLT x25 = x24 * x24;
	const GEN_FLT x26 = 1. / x25;
	const GEN_FLT x27 = x22 * x26;
	const GEN_FLT x28 = 2 * lh_qi;
	const GEN_FLT x29 = x28 * lh_qj;
	const GEN_FLT x30 = x2 * lh_qw;
	const GEN_FLT x31 = x30 + x29;
	const GEN_FLT x32 = 1. / x24;
	const GEN_FLT x33 = x22 * x22;
	const GEN_FLT x34 = -1 * x24;
	const GEN_FLT x35 = 2 * (1. / (x25 + x33)) * x25 * atan2(x22, x34) * curve_0;
	const GEN_FLT x36 = x19 + lh_px + (2 * ((x20 * lh_qj) + (-1 * x23 * lh_qk)));
	const GEN_FLT x37 = x36 * x26;
	const GEN_FLT x38 = -2 * (lh_qk * lh_qk);
	const GEN_FLT x39 = -2 * (lh_qj * lh_qj);
	const GEN_FLT x40 = 1 + x39 + x38;
	const GEN_FLT x41 = x25 + (x36 * x36);
	const GEN_FLT x42 = 1. / x41;
	const GEN_FLT x43 = x42 * x25;
	const GEN_FLT x44 = (1. / sqrt(x41)) * tilt_0;
	const GEN_FLT x45 = 2 * x36;
	const GEN_FLT x46 = 2 * x24;
	const GEN_FLT x47 = 1.0 / 2.0 * (1. / (x41 * sqrt(x41))) * x22 * tilt_0;
	const GEN_FLT x48 = 1. / sqrt(1 + (-1 * x42 * x33 * (tilt_0 * tilt_0)));
	const GEN_FLT x49 = (-1 * x48 * ((-1 * x47 * ((x4 * x46) + (x40 * x45))) + (x44 * x31))) +
						(-1 * x43 * ((-1 * x40 * x32) + (x4 * x37)));
	const GEN_FLT x50 =
		sin(1.5707963267949 + (-1 * phase_0) + (-1 * atan2(x36, x34)) + gibPhase_0 + (-1 * asin(x44 * x22))) * gibMag_0;
	const GEN_FLT x51 = x2 * lh_qj;
	const GEN_FLT x52 = x28 * lh_qw;
	const GEN_FLT x53 = x52 + x51;
	const GEN_FLT x54 = x53 * x26;
	const GEN_FLT x55 = 1 + (-2 * (lh_qi * lh_qi));
	const GEN_FLT x56 = x55 + x38;
	const GEN_FLT x57 = x29 + (-1 * x30);
	const GEN_FLT x58 = (-1 * x48 * ((-1 * ((x53 * x46) + (x57 * x45)) * x47) + (x56 * x44))) +
						(-1 * ((-1 * x57 * x32) + (x54 * x36)) * x43);
	const GEN_FLT x59 = x55 + x39;
	const GEN_FLT x60 = x51 + (-1 * x52);
	const GEN_FLT x61 = x1 + x3;
	const GEN_FLT x62 = (-1 * x48 * ((-1 * ((x59 * x46) + (x61 * x45)) * x47) + (x60 * x44))) +
						(-1 * ((-1 * x61 * x32) + (x59 * x37)) * x43);
	const GEN_FLT x63 = 2 * x16;
	const GEN_FLT x64 = 2 * x15;
	const GEN_FLT x65 = x64 + (-1 * x63);
	const GEN_FLT x66 = 2 * x11;
	const GEN_FLT x67 = 2 * x9;
	const GEN_FLT x68 = x67 + (-1 * x66);
	const GEN_FLT x69 = 2 * x7;
	const GEN_FLT x70 = 2 * x6;
	const GEN_FLT x71 = x70 + (-1 * x69);
	const GEN_FLT x72 = (x71 * lh_qk) + (-1 * x65 * lh_qi) + (x68 * lh_qw);
	const GEN_FLT x73 = (x65 * lh_qj) + (-1 * x68 * lh_qk) + (x71 * lh_qw);
	const GEN_FLT x74 = x65 + (x72 * x28) + (-1 * x0 * x73);
	const GEN_FLT x75 = (x68 * lh_qi) + (x65 * lh_qw) + (-1 * x71 * lh_qj);
	const GEN_FLT x76 = (x2 * x73) + x68 + (-1 * x75 * x28);
	const GEN_FLT x77 = x71 + (x0 * x75) + (-1 * x2 * x72);
	const GEN_FLT x78 = (-1 * x48 * ((-1 * ((x74 * x46) + (x77 * x45)) * x47) + (x76 * x44))) +
						(-1 * ((-1 * x77 * x32) + (x74 * x37)) * x43);
	const GEN_FLT x79 = 2 * x10;
	const GEN_FLT x80 = x79 + x67 + (-4 * x11);
	const GEN_FLT x81 = 2 * x14;
	const GEN_FLT x82 = (-4 * x15) + x63 + (-1 * x81);
	const GEN_FLT x83 = 2 * obj_qk * sensor_z;
	const GEN_FLT x84 = 2 * obj_qj * sensor_y;
	const GEN_FLT x85 = x84 + x83;
	const GEN_FLT x86 = (x85 * lh_qk) + (-1 * x80 * lh_qi) + (x82 * lh_qw);
	const GEN_FLT x87 = (x80 * lh_qj) + (-1 * x82 * lh_qk) + (x85 * lh_qw);
	const GEN_FLT x88 = x80 + (x86 * x28) + (-1 * x0 * x87);
	const GEN_FLT x89 = x88 * x26;
	const GEN_FLT x90 = (x82 * lh_qi) + (x80 * lh_qw) + (-1 * x85 * lh_qj);
	const GEN_FLT x91 = x82 + (x2 * x87) + (-1 * x90 * x28);
	const GEN_FLT x92 = (x0 * x90) + x85 + (-1 * x2 * x86);
	const GEN_FLT x93 = (-1 * x48 * ((-1 * ((x88 * x46) + (x92 * x45)) * x47) + (x91 * x44))) +
						(-1 * ((-1 * x92 * x32) + (x89 * x36)) * x43);
	const GEN_FLT x94 = 2 * x5;
	const GEN_FLT x95 = (-1 * x94) + (-4 * x6) + x69;
	const GEN_FLT x96 = 2 * obj_qi * sensor_x;
	const GEN_FLT x97 = x83 + x96;
	const GEN_FLT x98 = x64 + (-4 * x16) + x81;
	const GEN_FLT x99 = (-1 * x95 * lh_qi) + (x98 * lh_qk) + (x97 * lh_qw);
	const GEN_FLT x100 = (x95 * lh_qj) + (-1 * x97 * lh_qk) + (x98 * lh_qw);
	const GEN_FLT x101 = x95 + (x99 * x28) + (-1 * x0 * x100);
	const GEN_FLT x102 = (x97 * lh_qi) + (-1 * x98 * lh_qj) + (x95 * lh_qw);
	const GEN_FLT x103 = x97 + (x2 * x100) + (-1 * x28 * x102);
	const GEN_FLT x104 = x98 + (x0 * x102) + (-1 * x2 * x99);
	const GEN_FLT x105 = (-1 * x48 * ((-1 * ((x46 * x101) + (x45 * x104)) * x47) + (x44 * x103))) +
						 (-1 * ((-1 * x32 * x104) + (x37 * x101)) * x43);
	const GEN_FLT x106 = x70 + x94 + (-4 * x7);
	const GEN_FLT x107 = x96 + x84;
	const GEN_FLT x108 = (-1 * x79) + (-4 * x9) + x66;
	const GEN_FLT x109 = (x108 * lh_qk) + (x106 * lh_qw) + (-1 * x107 * lh_qi);
	const GEN_FLT x110 = (x107 * lh_qj) + (-1 * x106 * lh_qk) + (x108 * lh_qw);
	const GEN_FLT x111 = x107 + (x28 * x109) + (-1 * x0 * x110);
	const GEN_FLT x112 = (x106 * lh_qi) + (-1 * x108 * lh_qj) + (x107 * lh_qw);
	const GEN_FLT x113 = x106 + (x2 * x110) + (-1 * x28 * x112);
	const GEN_FLT x114 = x108 + (x0 * x112) + (-1 * x2 * x109);
	const GEN_FLT x115 = (-1 * x48 * ((-1 * ((x46 * x111) + (x45 * x114)) * x47) + (x44 * x113))) +
						 (-1 * ((-1 * x32 * x114) + (x37 * x111)) * x43);
	out[0] = x49 + (x35 * ((-1 * x32 * x31) + (x4 * x27))) + (x50 * x49);
	out[1] = x58 + (((-1 * x56 * x32) + (x54 * x22)) * x35) + (x50 * x58);
	out[2] = (((-1 * x60 * x32) + (x59 * x27)) * x35) + x62 + (x62 * x50);
	out[3] = x78 + (((-1 * x76 * x32) + (x74 * x27)) * x35) + (x78 * x50);
	out[4] = x93 + (((-1 * x91 * x32) + (x89 * x22)) * x35) + (x50 * x93);
	out[5] = x105 + (((-1 * x32 * x103) + (x27 * x101)) * x35) + (x50 * x105);
	out[6] = (((-1 * x32 * x113) + (x27 * x111)) * x35) + x115 + (x50 * x115);
}

// Jacobian of reproject_axis_x wrt [sensor_x, sensor_y, sensor_z]
static inline void gen_reproject_axis_x_jac_sensor_pt(FLT *out, const SurvivePose *obj_p, const FLT *sensor_pt,
													  const SurvivePose *lh_p, const BaseStationCal *bsc0) {
	const GEN_FLT obj_px = (*obj_p).Pos[0];
	const GEN_FLT obj_py = (*obj_p).Pos[1];
	const GEN_FLT obj_pz = (*obj_p).Pos[2];
	const GEN_FLT obj_qw = (*obj_p).Rot[0];
	const GEN_FLT obj_qi = (*obj_p).Rot[1];
	const GEN_FLT obj_qj = (*obj_p).Rot[2];
	const GEN_FLT obj_qk = (*obj_p).Rot[3];
	const GEN_FLT sensor_x = sensor_pt[0];
	const GEN_FLT sensor_y = sensor_pt[1];
	const GEN_FLT sensor_z = sensor_pt[2];
	const GEN_FLT lh_px = (*lh_p).Pos[0];
	const GEN_FLT lh_py = (*lh_p).Pos[1];
	const GEN_FLT lh_pz = (*lh_p).Pos[2];
	const GEN_FLT lh_qw = (*lh_p).Rot[0];
	const GEN_FLT lh_qi = (*lh_p).Rot[1];
	const GEN_FLT lh_qj = (*lh_p).Rot[2];
	const GEN_FLT lh_qk = (*lh_p).Rot[3];
	const GEN_FLT phase_0 = (*bsc0).phase;
	const GEN_FLT tilt_0 = (*bsc0).tilt;
	const GEN_FLT curve_0 = (*bsc0).curve;
	const GEN_FLT gibPhase_0 = (*bsc0).gibpha;
	const GEN_FLT gibMag_0 = (*bsc0).gibmag;
	const GEN_FLT ogeeMag_0 = (*bsc0).ogeephase;
	const GEN_FLT ogeePhase_0 = (*bsc0).ogeemag;
	const GEN_FLT x0 = (obj_qw * sensor_x) + (-1 * obj_qk * sensor_y) + (obj_qj * sensor_z);
	const GEN_FLT x1 = (obj_qk * sensor_x) + (-1 * obj_qi * sensor_z) + (obj_qw * sensor_y);
	const GEN_FLT x2 = (2 * ((x1 * obj_qi) + (-1 * x0 * obj_qj))) + obj_pz + sensor_z;
	const GEN_FLT x3 = (-1 * obj_qj * sensor_x) + (obj_qw * sensor_z) + (obj_qi * sensor_y);
	const GEN_FLT x4 = (2 * ((x0 * obj_qk) + (-1 * x3 * obj_qi))) + obj_py + sensor_y;
	const GEN_FLT x5 = (2 * ((x3 * obj_qj) + (-1 * x1 * obj_qk))) + obj_px + sensor_x;
	const GEN_FLT x6 = (-1 * x5 * lh_qj) + (x2 * lh_qw) + (x4 * lh_qi);
	const GEN_FLT x7 = (-1 * x4 * lh_qk) + (x5 * lh_qw) + (x2 * lh_qj);
	const GEN_FLT x8 = x4 + lh_py + (2 * ((x7 * lh_qk) + (-1 * x6 * lh_qi)));
	const GEN_FLT x9 = 2 * obj_qw;
	const GEN_FLT x10 = x9 * obj_qj;
	const GEN_FLT x11 = 2 * obj_qi;
	const GEN_FLT x12 = x11 * obj_qk;
	const GEN_FLT x13 = x12 + (-1 * x10);
	const GEN_FLT x14 = x11 * obj_qj;
	const GEN_FLT x15 = x9 * obj_qk;
	const GEN_FLT x16 = x15 + x14;
	const GEN_FLT x17 = -2 * (obj_qj * obj_qj);
	const GEN_FLT x18 = 1 + (-2 * (obj_qk * obj_qk));
	const GEN_FLT x19 = x18 + x17;
	const GEN_FLT x20 = (x19 * lh_qk) + (-1 * x13 * lh_qi) + (x16 * lh_qw);
	const GEN_FLT x21 = 2 * lh_qi;
	const GEN_FLT x22 = (x13 * lh_qj) + (x19 * lh_qw) + (-1 * x16 * lh_qk);
	const GEN_FLT x23 = 2 * lh_qj;
	const GEN_FLT x24 = x13 + (x20 * x21) + (-1 * x22 * x23);
	const GEN_FLT x25 = (-1 * x2 * lh_qi) + (x4 * lh_qw) + (x5 * lh_qk);
	const GEN_FLT x26 = x2 + lh_pz + (2 * ((x25 * lh_qi) + (-1 * x7 * lh_qj)));
	const GEN_FLT x27 = x26 * x26;
	const GEN_FLT x28 = 1. / x27;
	const GEN_FLT x29 = x24 * x28;
	const GEN_FLT x30 = 2 * lh_qk;
	const GEN_FLT x31 = (x16 * lh_qi) + (-1 * x19 * lh_qj) + (x13 * lh_qw);
	const GEN_FLT x32 = (x30 * x22) + x16 + (-1 * x31 * x21);
	const GEN_FLT x33 = 1. / x26;
	const GEN_FLT x34 = x8 * x8;
	const GEN_FLT x35 = -1 * x26;
	const GEN_FLT x36 = 2 * (1. / (x27 + x34)) * x27 * atan2(x8, x35) * curve_0;
	const GEN_FLT x37 = lh_px + x5 + (2 * ((x6 * lh_qj) + (-1 * x25 * lh_qk)));
	const GEN_FLT x38 = x19 + (x31 * x23) + (-1 * x30 * x20);
	const GEN_FLT x39 = x27 + (x37 * x37);
	const GEN_FLT x40 = 1. / x39;
	const GEN_FLT x41 = x40 * x27;
	const GEN_FLT x42 = 1. / sqrt(1 + (-1 * x40 * x34 * (tilt_0 * tilt_0)));
	const GEN_FLT x43 = (1. / sqrt(x39)) * tilt_0;
	const GEN_FLT x44 = 2 * x37;
	const GEN_FLT x45 = 2 * x26;
	const GEN_FLT x46 = 1.0 / 2.0 * x8 * (1. / (x39 * sqrt(x39))) * tilt_0;
	const GEN_FLT x47 = (-1 * x42 * ((-1 * ((x45 * x24) + (x44 * x38)) * x46) + (x43 * x32))) +
						(-1 * ((-1 * x33 * x38) + (x37 * x29)) * x41);
	const GEN_FLT x48 =
		sin(1.5707963267949 + (-1 * phase_0) + (-1 * atan2(x37, x35)) + gibPhase_0 + (-1 * asin(x8 * x43))) * gibMag_0;
	const GEN_FLT x49 = 2 * obj_qk * obj_qj;
	const GEN_FLT x50 = x9 * obj_qi;
	const GEN_FLT x51 = x50 + x49;
	const GEN_FLT x52 = -2 * (obj_qi * obj_qi);
	const GEN_FLT x53 = x18 + x52;
	const GEN_FLT x54 = x14 + (-1 * x15);
	const GEN_FLT x55 = (x54 * lh_qk) + (-1 * x51 * lh_qi) + (x53 * lh_qw);
	const GEN_FLT x56 = (x51 * lh_qj) + (x54 * lh_qw) + (-1 * x53 * lh_qk);
	const GEN_FLT x57 = x51 + (x55 * x21) + (-1 * x56 * x23);
	const GEN_FLT x58 = x8 * x28;
	const GEN_FLT x59 = (x53 * lh_qi) + (-1 * x54 * lh_qj) + (x51 * lh_qw);
	const GEN_FLT x60 = (x56 * x30) + x53 + (-1 * x59 * x21);
	const GEN_FLT x61 = x37 * x28;
	const GEN_FLT x62 = x54 + (x59 * x23) + (-1 * x55 * x30);
	const GEN_FLT x63 = (-1 * x42 * ((-1 * ((x57 * x45) + (x62 * x44)) * x46) + (x60 * x43))) +
						(-1 * ((-1 * x62 * x33) + (x61 * x57)) * x41);
	const GEN_FLT x64 = 1 + x52 + x17;
	const GEN_FLT x65 = x49 + (-1 * x50);
	const GEN_FLT x66 = x10 + x12;
	const GEN_FLT x67 = (-1 * x64 * lh_qi) + (x66 * lh_qk) + (x65 * lh_qw);
	const GEN_FLT x68 = (x64 * lh_qj) + (-1 * x65 * lh_qk) + (x66 * lh_qw);
	const GEN_FLT x69 = (x67 * x21) + x64 + (-1 * x68 * x23);
	const GEN_FLT x70 = (x65 * lh_qi) + (-1 * x66 * lh_qj) + (x64 * lh_qw);
	const GEN_FLT x71 = x65 + (x68 * x30) + (-1 * x70 * x21);
	const GEN_FLT x72 = x66 + (x70 * x23) + (-1 * x67 * x30);
	const GEN_FLT x73 = (-1 * x42 * ((-1 * ((x69 * x45) + (x72 * x44)) * x46) + (x71 * x43))) +
						(-1 * ((-1 * x72 * x33) + (x61 * x69)) * x41);
	out[0] = (x36 * ((-1 * x32 * x33) + (x8 * x29))) + x47 + (x47 * x48);
	out[1] = x63 + (((-1 * x60 * x33) + (x58 * x57)) * x36) + (x63 * x48);
	out[2] = x73 + (((-1 * x71 * x33) + (x69 * x58)) * x36) + (x73 * x48);
}

// Jacobian of reproject_axis_x wrt [lh_px, lh_py, lh_pz, lh_qw, lh_qi, lh_qj, lh_qk]
static inline void gen_reproject_axis_x_jac_lh_p(FLT *out, const SurvivePose *obj_p, const FLT *sensor_pt,
												 const SurvivePose *lh_p, const BaseStationCal *bsc0) {
	const GEN_FLT obj_px = (*obj_p).Pos[0];
	const GEN_FLT obj_py = (*obj_p).Pos[1];
	const GEN_FLT obj_pz = (*obj_p).Pos[2];
	const GEN_FLT obj_qw = (*obj_p).Rot[0];
	const GEN_FLT obj_qi = (*obj_p).Rot[1];
	const GEN_FLT obj_qj = (*obj_p).Rot[2];
	const GEN_FLT obj_qk = (*obj_p).Rot[3];
	const GEN_FLT sensor_x = sensor_pt[0];
	const GEN_FLT sensor_y = sensor_pt[1];
	const GEN_FLT sensor_z = sensor_pt[2];
	const GEN_FLT lh_px = (*lh_p).Pos[0];
	const GEN_FLT lh_py = (*lh_p).Pos[1];
	const GEN_FLT lh_pz = (*lh_p).Pos[2];
	const GEN_FLT lh_qw = (*lh_p).Rot[0];
	const GEN_FLT lh_qi = (*lh_p).Rot[1];
	const GEN_FLT lh_qj = (*lh_p).Rot[2];
	const GEN_FLT lh_qk = (*lh_p).Rot[3];
	const GEN_FLT phase_0 = (*bsc0).phase;
	const GEN_FLT tilt_0 = (*bsc0).tilt;
	const GEN_FLT curve_0 = (*bsc0).curve;
	const GEN_FLT gibPhase_0 = (*bsc0).gibpha;
	const GEN_FLT gibMag_0 = (*bsc0).gibmag;
	const GEN_FLT ogeeMag_0 = (*bsc0).ogeephase;
	const GEN_FLT ogeePhase_0 = (*bsc0).ogeemag;
	const GEN_FLT x0 = (-1 * obj_qj * sensor_x) + (obj_qw * sensor_z) + (obj_qi * sensor_y);
	const GEN_FLT x1 = (obj_qw * sensor_x) + (-1 * obj_qk * sensor_y) + (obj_qj * sensor_z);
	const GEN_FLT x2 = 2 * ((x1 * obj_qk) + (-1 * x0 * obj_qi));
	const GEN_FLT x3 = x2 + obj_py + sensor_y;
	const GEN_FLT x4 = x3 * lh_qw;
	const GEN_FLT x5 = (obj_qk * sensor_x) + (-1 * obj_qi * sensor_z) + (obj_qw * sensor_y);
	const GEN_FLT x6 = 2 * ((x0 * obj_qj) + (-1 * x5 * obj_qk));
	const GEN_FLT x7 = x6 + obj_px + sensor_x;
	const GEN_FLT x8 = x7 * lh_qk;
	const GEN_FLT x9 = 2 * ((x5 * obj_qi) + (-1 * x1 * obj_qj));
	const GEN_FLT x10 = x9 + obj_pz + sensor_z;
	const GEN_FLT x11 = x10 * lh_qi;
	const GEN_FLT x12 = (-1 * x11) + x4 + x8;
	const GEN_FLT x13 = x10 * lh_qw;
	const GEN_FLT x14 = x3 * lh_qi;
	const GEN_FLT x15 = x7 * lh_qj;
	const GEN_FLT x16 = (-1 * x15) + x13 + x14;
	const GEN_FLT x17 = x7 + lh_px + (2 * ((x16 * lh_qj) + (-1 * x12 * lh_qk)));
	const GEN_FLT x18 = x7 * lh_qw;
	const GEN_FLT x19 = x10 * lh_qj;
	const GEN_FLT x20 = x3 * lh_qk;
	const GEN_FLT x21 = (-1 * x20) + x18 + x19;
	const GEN_FLT x22 = x10 + lh_pz + (2 * ((x12 * lh_qi) + (-1 * x21 * lh_qj)));
	const GEN_FLT x23 = x22 * x22;
	const GEN_FLT x24 = x23 + (x17 * x17);
	const GEN_FLT x25 = 1. / x24;
	const GEN_FLT x26 = x3 + lh_py + (2 * ((x21 * lh_qk) + (-1 * x16 * lh_qi)));
	const GEN_FLT x27 = x26 * x26;
	const GEN_FLT x28 = 1. / sqrt(1 + (-1 * x25 * x27 * (tilt_0 * tilt_0)));
	const GEN_FLT x29 = (1. / (x24 * sqrt(x24))) * x26 * tilt_0;
	const GEN_FLT x30 = x28 * x29;
	const GEN_FLT x31 = (x30 * x17) + (x25 * x22);
	const GEN_FLT x32 = (1. / sqrt(x24)) * tilt_0;
	const GEN_FLT x33 = -1 * x22;
	const GEN_FLT x34 =
		sin(1.5707963267949 + (-1 * phase_0) + (-1 * atan2(x17, x33)) + gibPhase_0 + (-1 * asin(x32 * x26))) * gibMag_0;
	const GEN_FLT x35 = x32 * x28;
	const GEN_FLT x36 = 2 * x22;
	const GEN_FLT x37 = (1. / (x23 + x27)) * atan2(x26, x33) * curve_0;
	const GEN_FLT x38 = 2 * x37;
	const GEN_FLT x39 = (x30 * x22) + (-1 * x25 * x17);
	const GEN_FLT x40 = 2 * x15;
	const GEN_FLT x41 = (2 * x14) + (-1 * x40);
	const GEN_FLT x42 = 1. / x23;
	const GEN_FLT x43 = x42 * x26;
	const GEN_FLT x44 = 1. / x22;
	const GEN_FLT x45 = 2 * x11;
	const GEN_FLT x46 = (2 * x8) + (-1 * x45);
	const GEN_FLT x47 = x38 * x23;
	const GEN_FLT x48 = x42 * x17;
	const GEN_FLT x49 = 2 * x20;
	const GEN_FLT x50 = (2 * x19) + (-1 * x49);
	const GEN_FLT x51 = x25 * x23;
	const GEN_FLT x52 = 2 * x17;
	const GEN_FLT x53 = 1.0 / 2.0 * x29;
	const GEN_FLT x54 = (-1 * x28 * ((-1 * ((x41 * x36) + (x50 * x52)) * x53) + (x46 * x32))) +
						(-1 * ((-1 * x50 * x44) + (x41 * x48)) * x51);
	const GEN_FLT x55 = 2 * x4;
	const GEN_FLT x56 = (-1 * obj_pz) + (-1 * sensor_z) + (-1 * x9);
	const GEN_FLT x57 = 2 * lh_qi;
	const GEN_FLT x58 = x46 + x55 + (x57 * x56);
	const GEN_FLT x59 = 2 * x13;
	const GEN_FLT x60 = (-4 * x14) + x40 + (-1 * x59);
	const GEN_FLT x61 = 2 * lh_qk;
	const GEN_FLT x62 = 2 * lh_qj;
	const GEN_FLT x63 = (x3 * x62) + (-1 * x61 * x56);
	const GEN_FLT x64 = (-1 * x28 * ((-1 * ((x58 * x36) + (x63 * x52)) * x53) + (x60 * x32))) +
						(-1 * ((-1 * x63 * x44) + (x58 * x48)) * x51);
	const GEN_FLT x65 = 2 * x18;
	const GEN_FLT x66 = (-4 * x19) + (-1 * x65) + x49;
	const GEN_FLT x67 = (-1 * sensor_x) + (-1 * obj_px) + (-1 * x6);
	const GEN_FLT x68 = (x61 * x10) + (-1 * x67 * x57);
	const GEN_FLT x69 = x41 + (x62 * x67) + x59;
	const GEN_FLT x70 = (-1 * x28 * ((-1 * ((x66 * x36) + (x69 * x52)) * x53) + (x68 * x32))) +
						(-1 * ((-1 * x69 * x44) + (x66 * x48)) * x51);
	const GEN_FLT x71 = (-1 * sensor_y) + (-1 * obj_py) + (-1 * x2);
	const GEN_FLT x72 = (x7 * x57) + (-1 * x71 * x62);
	const GEN_FLT x73 = x65 + x50 + (x71 * x61);
	const GEN_FLT x74 = (-4 * x8) + (-1 * x55) + x45;
	const GEN_FLT x75 = (-1 * x28 * ((-1 * ((x72 * x36) + (x74 * x52)) * x53) + (x73 * x32))) +
						(-1 * ((-1 * x74 * x44) + (x72 * x48)) * x51);
	out[0] = x31 + (x31 * x34);
	out[1] = (-1 * x34 * x35) + (-1 * x35) + (-1 * x36 * x37);
	out[2] = x39 + (x38 * x26) + (x34 * x39);
	out[3] = x54 + (((-1 * x44 * x46) + (x41 * x43)) * x47) + (x54 * x34);
	out[4] = x64 + (((-1 * x60 * x44) + (x58 * x43)) * x47) + (x64 * x34);
	out[5] = x70 + (((-1 * x68 * x44) + (x66 * x43)) * x47) + (x70 * x34);
	out[6] = x75 + (((-1 * x73 * x44) + (x72 * x43)) * x47) + (x75 * x34);
}

// Jacobian of reproject_axis_x wrt [phase_0, tilt_0, curve_0, gibPhase_0, gibMag_0, ogeeMag_0, ogeePhase_0]
static inline void gen_reproject_axis_x_jac_bsc0(FLT *out, const SurvivePose *obj_p, const FLT *sensor_pt,
												 const SurvivePose *lh_p, const BaseStationCal *bsc0) {
	const GEN_FLT obj_px = (*obj_p).Pos[0];
	const GEN_FLT obj_py = (*obj_p).Pos[1];
	const GEN_FLT obj_pz = (*obj_p).Pos[2];
	const GEN_FLT obj_qw = (*obj_p).Rot[0];
	const GEN_FLT obj_qi = (*obj_p).Rot[1];
	const GEN_FLT obj_qj = (*obj_p).Rot[2];
	const GEN_FLT obj_qk = (*obj_p).Rot[3];
	const GEN_FLT sensor_x = sensor_pt[0];
	const GEN_FLT sensor_y = sensor_pt[1];
	const GEN_FLT sensor_z = sensor_pt[2];
	const GEN_FLT lh_px = (*lh_p).Pos[0];
	const GEN_FLT lh_py = (*lh_p).Pos[1];
	const GEN_FLT lh_pz = (*lh_p).Pos[2];
	const GEN_FLT lh_qw = (*lh_p).Rot[0];
	const GEN_FLT lh_qi = (*lh_p).Rot[1];
	const GEN_FLT lh_qj = (*lh_p).Rot[2];
	const GEN_FLT lh_qk = (*lh_p).Rot[3];
	const GEN_FLT phase_0 = (*bsc0).phase;
	const GEN_FLT tilt_0 = (*bsc0).tilt;
	const GEN_FLT curve_0 = (*bsc0).curve;
	const GEN_FLT gibPhase_0 = (*bsc0).gibpha;
	const GEN_FLT gibMag_0 = (*bsc0).gibmag;
	const GEN_FLT ogeeMag_0 = (*bsc0).ogeephase;
	const GEN_FLT ogeePhase_0 = (*bsc0).ogeemag;
	const GEN_FLT x0 = (obj_qk * sensor_x) + (-1 * obj_qi * sensor_z) + (obj_qw * sensor_y);
	const GEN_FLT x1 = (-1 * obj_qj * sensor_x) + (obj_qw * sensor_z) + (obj_qi * sensor_y);
	const GEN_FLT x2 = (2 * ((x1 * obj_qj) + (-1 * x0 * obj_qk))) + obj_px + sensor_x;
	const GEN_FLT x3 = (obj_qw * sensor_x) + (-1 * obj_qk * sensor_y) + (obj_qj * sensor_z);
	const GEN_FLT x4 = (2 * ((x0 * obj_qi) + (-1 * x3 * obj_qj))) + obj_pz + sensor_z;
	const GEN_FLT x5 = obj_py + (2 * ((x3 * obj_qk) + (-1 * x1 * obj_qi))) + sensor_y;
	const GEN_FLT x6 = (-1 * x5 * lh_qk) + (x2 * lh_qw) + (x4 * lh_qj);
	const GEN_FLT x7 = (x5 * lh_qw) + (-1 * x4 * lh_qi) + (x2 * lh_qk);
	const GEN_FLT x8 = x4 + lh_pz + (2 * ((x7 * lh_qi) + (-1 * x6 * lh_qj)));
	const GEN_FLT x9 = (x4 * lh_qw) + (-1 * x2 * lh_qj) + (x5 * lh_qi);
	const GEN_FLT x10 = lh_px + x2 + (2 * ((x9 * lh_qj) + (-1 * x7 * lh_qk)));
	const GEN_FLT x11 = (x10 * x10) + (x8 * x8);
	const GEN_FLT x12 = x5 + lh_py + (2 * ((x6 * lh_qk) + (-1 * x9 * lh_qi)));
	const GEN_FLT x13 = x12 * (1. / sqrt(x11));
	const GEN_FLT x14 = -1 * x8;
	const GEN_FLT x15 =
		1.5707963267949 + (-1 * phase_0) + (-1 * atan2(x10, x14)) + gibPhase_0 + (-1 * asin(x13 * tilt_0));
	const GEN_FLT x16 = sin(x15) * gibMag_0;
	const GEN_FLT x17 = x13 * (1. / sqrt(1 + (-1 * (x12 * x12) * (1. / x11) * (tilt_0 * tilt_0))));
	out[0] = -1 + (-1 * x16);
	out[1] = (-1 * x17 * x16) + (-1 * x17);
	out[2] = atan2(x12, x14) * atan2(x12, x14);
	out[3] = x16;
	out[4] = -1 * cos(x15);
	out[5] = 0;
	out[6] = 0;
}

static inline FLT gen_reproject_axis_y(const SurvivePose *obj_p, const FLT *sensor_pt, const SurvivePose *lh_p,
									   const BaseStationCal *bsc1) {
	const GEN_FLT obj_px = (*obj_p).Pos[0];
	const GEN_FLT obj_py = (*obj_p).Pos[1];
	const GEN_FLT obj_pz = (*obj_p).Pos[2];
	const GEN_FLT obj_qw = (*obj_p).Rot[0];
	const GEN_FLT obj_qi = (*obj_p).Rot[1];
	const GEN_FLT obj_qj = (*obj_p).Rot[2];
	const GEN_FLT obj_qk = (*obj_p).Rot[3];
	const GEN_FLT sensor_x = sensor_pt[0];
	const GEN_FLT sensor_y = sensor_pt[1];
	const GEN_FLT sensor_z = sensor_pt[2];
	const GEN_FLT lh_px = (*lh_p).Pos[0];
	const GEN_FLT lh_py = (*lh_p).Pos[1];
	const GEN_FLT lh_pz = (*lh_p).Pos[2];
	const GEN_FLT lh_qw = (*lh_p).Rot[0];
	const GEN_FLT lh_qi = (*lh_p).Rot[1];
	const GEN_FLT lh_qj = (*lh_p).Rot[2];
	const GEN_FLT lh_qk = (*lh_p).Rot[3];
	const GEN_FLT phase_1 = (*bsc1).phase;
	const GEN_FLT tilt_1 = (*bsc1).tilt;
	const GEN_FLT curve_1 = (*bsc1).curve;
	const GEN_FLT gibPhase_1 = (*bsc1).gibpha;
	const GEN_FLT gibMag_1 = (*bsc1).gibmag;
	const GEN_FLT ogeeMag_1 = (*bsc1).ogeephase;
	const GEN_FLT ogeePhase_1 = (*bsc1).ogeemag;
	const GEN_FLT x0 = (-1 * obj_qj * sensor_x) + (obj_qw * sensor_z) + (obj_qi * sensor_y);
	const GEN_FLT x1 = (obj_qw * sensor_x) + (-1 * obj_qk * sensor_y) + (obj_qj * sensor_z);
	const GEN_FLT x2 = (2 * ((x1 * obj_qk) + (-1 * x0 * obj_qi))) + obj_py + sensor_y;
	const GEN_FLT x3 = (obj_qk * sensor_x) + (-1 * obj_qi * sensor_z) + (obj_qw * sensor_y);
	const GEN_FLT x4 = (2 * ((x0 * obj_qj) + (-1 * x3 * obj_qk))) + obj_px + sensor_x;
	const GEN_FLT x5 = (2 * ((x3 * obj_qi) + (-1 * x1 * obj_qj))) + obj_pz + sensor_z;
	const GEN_FLT x6 = (-1 * x5 * lh_qi) + (x2 * lh_qw) + (x4 * lh_qk);
	const GEN_FLT x7 = (-1 * x4 * lh_qj) + (x5 * lh_qw) + (x2 * lh_qi);
	const GEN_FLT x8 = x4 + lh_px + (2 * ((x7 * lh_qj) + (-1 * x6 * lh_qk)));
	const GEN_FLT x9 = (-1 * x2 * lh_qk) + (x4 * lh_qw) + (x5 * lh_qj);
	const GEN_FLT x10 = x5 + lh_pz + (2 * ((x6 * lh_qi) + (-1 * x9 * lh_qj)));
	const GEN_FLT x11 = -1 * x10;
	const GEN_FLT x12 = x2 + lh_py + (2 * ((x9 * lh_qk) + (-1 * x7 * lh_qi)));
	const GEN_FLT x13 = (-1 * phase_1) + (-1 * asin((1. / sqrt((x12 * x12) + (x10 * x10))) * x8 * tilt_1)) +
						(-1 * atan2(-1 * x12, x11));
	return x13 + ((atan2(x8, x11) * atan2(x8, x11)) * curve_1) +
		   (-1 * cos(1.5707963267949 + x13 + gibPhase_1) * gibMag_1);
}

// Jacobian of reproject_axis_y wrt [obj_px, obj_py, obj_pz, obj_qw, obj_qi, obj_qj, obj_qk]
static inline void gen_reproject_axis_y_jac_obj_p(FLT *out, const SurvivePose *obj_p, const FLT *sensor_pt,
												  const SurvivePose *lh_p, const BaseStationCal *bsc1) {
	const GEN_FLT obj_px = (*obj_p).Pos[0];
	const GEN_FLT obj_py = (*obj_p).Pos[1];
	const GEN_FLT obj_pz = (*obj_p).Pos[2];
	const GEN_FLT obj_qw = (*obj_p).Rot[0];
	const GEN_FLT obj_qi = (*obj_p).Rot[1];
	const GEN_FLT obj_qj = (*obj_p).Rot[2];
	const GEN_FLT obj_qk = (*obj_p).Rot[3];
	const GEN_FLT sensor_x = sensor_pt[0];
	const GEN_FLT sensor_y = sensor_pt[1];
	const GEN_FLT sensor_z = sensor_pt[2];
	const GEN_FLT lh_px = (*lh_p).Pos[0];
	const GEN_FLT lh_py = (*lh_p).Pos[1];
	const GEN_FLT lh_pz = (*lh_p).Pos[2];
	const GEN_FLT lh_qw = (*lh_p).Rot[0];
	const GEN_FLT lh_qi = (*lh_p).Rot[1];
	const GEN_FLT lh_qj = (*lh_p).Rot[2];
	const GEN_FLT lh_qk = (*lh_p).Rot[3];
	const GEN_FLT phase_1 = (*bsc1).phase;
	const GEN_FLT tilt_1 = (*bsc1).tilt;
	const GEN_FLT curve_1 = (*bsc1).curve;
	const GEN_FLT gibPhase_1 = (*bsc1).gibpha;
	const GEN_FLT gibMag_1 = (*bsc1).gibmag;
	const GEN_FLT ogeeMag_1 = (*bsc1).ogeephase;
	const GEN_FLT ogeePhase_1 = (*bsc1).ogeemag;
	const GEN_FLT x0 = 2 * lh_qj;
	const GEN_FLT x1 = x0 * lh_qw;
	const GEN_FLT x2 = 2 * lh_qk;
	const GEN_FLT x3 = x2 * lh_qi;
	const GEN_FLT x4 = x3 + (-1 * x1);
	const GEN_FLT x5 = obj_qw * sensor_x;
	const GEN_FLT x6 = obj_qj * sensor_z;
	const GEN_FLT x7 = obj_qk * sensor_y;
	const GEN_FLT x8 = (-1 * x7) + x5 + x6;
	const GEN_FLT x9 = obj_qk * sensor_x;
	const GEN_FLT x10 = obj_qw * sensor_y;
	const GEN_FLT x11 = obj_qi * sensor_z;
	const GEN_FLT x12 = (-1 * x11) + x9 + x10;
	const GEN_FLT x13 = (2 * ((x12 * obj_qi) + (-1 * x8 * obj_qj))) + obj_pz + sensor_z;
	const GEN_FLT x14 = obj_qw * sensor_z;
	const GEN_FLT x15 = obj_qi * sensor_y;
	const GEN_FLT x16 = obj_qj * sensor_x;
	const GEN_FLT x17 = x14 + (-1 * x16) + x15;
	const GEN_FLT x18 = (2 * ((x8 * obj_qk) + (-1 * x17 * obj_qi))) + obj_py + sensor_y;
	const GEN_FLT x19 = (2 * ((x17 * obj_qj) + (-1 * x12 * obj_qk))) + obj_px + sensor_x;
	const GEN_FLT x20 = (x13 * lh_qw) + (-1 * x19 * lh_qj) + (x18 * lh_qi);
	const GEN_FLT x21 = (-1 * x18 * lh_qk) + (x19 * lh_qw) + (x13 * lh_qj);
	const GEN_FLT x22 = x18 + lh_py + (2 * ((x21 * lh_qk) + (-1 * x20 * lh_qi)));
	const GEN_FLT x23 = (x18 * lh_qw) + (-1 * x13 * lh_qi) + (x19 * lh_qk);
	const GEN_FLT x24 = x13 + lh_pz + (2 * ((x23 * lh_qi) + (-1 * x21 * lh_qj)));
	const GEN_FLT x25 = x24 * x24;
	const GEN_FLT x26 = 1. / x25;
	const GEN_FLT x27 = x22 * x26;
	const GEN_FLT x28 = x0 * lh_qi;
	const GEN_FLT x29 = x2 * lh_qw;
	const GEN_FLT x30 = x29 + x28;
	const GEN_FLT x31 = 1. / x24;
	const GEN_FLT x32 = x25 + (x22 * x22);
	const GEN_FLT x33 = 1. / x32;
	const GEN_FLT x34 = x33 * x25;
	const GEN_FLT x35 = x19 + lh_px + (2 * ((x20 * lh_qj) + (-1 * x23 * lh_qk)));
	const GEN_FLT x36 = x35 * x35;
	const GEN_FLT x37 = 1. / sqrt(1 + (-1 * x33 * x36 * (tilt_1 * tilt_1)));
	const GEN_FLT x38 = -2 * (lh_qk * lh_qk);
	const GEN_FLT x39 = -2 * (lh_qj * lh_qj);
	const GEN_FLT x40 = 1 + x39 + x38;
	const GEN_FLT x41 = (1. / sqrt(x32)) * tilt_1;
	const GEN_FLT x42 = 2 * x22;
	const GEN_FLT x43 = 2 * x24;
	const GEN_FLT x44 = 1.0 / 2.0 * (1. / (x32 * sqrt(x32))) * x35 * tilt_1;
	const GEN_FLT x45 = (-1 * x37 * ((-1 * x44 * ((x4 * x43) + (x42 * x30))) + (x40 * x41))) +
						(-1 * x34 * ((x30 * x31) + (-1 * x4 * x27)));
	const GEN_FLT x46 = -1 * x24;
	const GEN_FLT x47 =
		sin(1.5707963267949 + (-1 * phase_1) + (-1 * atan2(-1 * x22, x46)) + gibPhase_1 + (-1 * asin(x41 * x35))) *
		gibMag_1;
	const GEN_FLT x48 = x35 * x26;
	const GEN_FLT x49 = 2 * (1. / (x25 + x36)) * x25 * atan2(x35, x46) * curve_1;
	const GEN_FLT x50 = x2 * lh_qj;
	const GEN_FLT x51 = 2 * lh_qi;
	const GEN_FLT x52 = x51 * lh_qw;
	const GEN_FLT x53 = x52 + x50;
	const GEN_FLT x54 = 1 + (-2 * (lh_qi * lh_qi));
	const GEN_FLT x55 = x54 + x38;
	const GEN_FLT x56 = x28 + (-1 * x29);
	const GEN_FLT x57 = (-1 * x37 * ((-1 * ((x53 * x43) + (x55 * x42)) * x44) + (x56 * x41))) +
						(-1 * ((x55 * x31) + (-1 * x53 * x27)) * x34);
	const GEN_FLT x58 = x54 + x39;
	const GEN_FLT x59 = x1 + x3;
	const GEN_FLT x60 = x50 + (-1 * x52);
	const GEN_FLT x61 = (-1 * x37 * ((-1 * ((x58 * x43) + (x60 * x42)) * x44) + (x59 * x41))) +
						(-1 * ((x60 * x31) + (-1 * x58 * x27)) * x34);
	const GEN_FLT x62 = 2 * x16;
	const GEN_FLT x63 = 2 * x15;
	const GEN_FLT x64 = x63 + (-1 * x62);
	const GEN_FLT x65 = 2 * x11;
	const GEN_FLT x66 = 2 * x9;
	const GEN_FLT x67 = x66 + (-1 * x65);
	const GEN_FLT x68 = 2 * x7;
	const GEN_FLT x69 = 2 * x6;
	const GEN_FLT x70 = x69 + (-1 * x68);
	const GEN_FLT x71 = (x70 * lh_qk) + (-1 * x64 * lh_qi) + (x67 * lh_qw);
	const GEN_FLT x72 = (x64 * lh_qj) + (-1 * x67 * lh_qk) + (x70 * lh_qw);
	const GEN_FLT x73 = x64 + (x71 * x51) + (-1 * x0 * x72);
	const GEN_FLT x74 = (x67 * lh_qi) + (x64 * lh_qw) + (-1 * x70 * lh_qj);
	const GEN_FLT x75 = x67 + (x2 * x72) + (-1 * x74 * x51);
	const GEN_FLT x76 = x70 + (x0 * x74) + (-1 * x2 * x71);
	const GEN_FLT x77 = (-1 * x37 * ((-1 * ((x73 * x43) + (x75 * x42)) * x44) + (x76 * x41))) +
						(-1 * ((x75 * x31) + (-1 * x73 * x27)) * x34);
	const GEN_FLT x78 = 2 * x10;
	const GEN_FLT x79 = x78 + x66 + (-4 * x11);
	const GEN_FLT x80 = 2 * x14;
	const GEN_FLT x81 = (-4 * x15) + x62 + (-1 * x80);
	const GEN_FLT x82 = 2 * obj_qk * sensor_z;
	const GEN_FLT x83 = 2 * obj_qj * sensor_y;
	const GEN_FLT x84 = x83 + x82;
	const GEN_FLT x85 = (-1 * x79 * lh_qi) + (x84 * lh_qk) + (x81 * lh_qw);
	const GEN_FLT x86 = (x79 * lh_qj) + (-1 * x81 * lh_qk) + (x84 * lh_qw);
	const GEN_FLT x87 = x79 + (x85 * x51) + (-1 * x0 * x86);
	const GEN_FLT x88 = (x81 * lh_qi) + (x79 * lh_qw) + (-1 * x84 * lh_qj);
	const GEN_FLT x89 = x81 + (x2 * x86) + (-1 * x88 * x51);
	const GEN_FLT x90 = (x0 * x88) + x84 + (-1 * x2 * x85);
	const GEN_FLT x91 = (-1 * x37 * ((-1 * ((x87 * x43) + (x89 * x42)) * x44) + (x90 * x41))) +
						(-1 * ((x89 * x31) + (-1 * x87 * x27)) * x34);
	const GEN_FLT x92 = 2 * x5;
	const GEN_FLT x93 = (-1 * x92) + (-4 * x6) + x68;
	const GEN_FLT x94 = 2 * obj_qi * sensor_x;
	const GEN_FLT x95 = x82 + x94;
	const GEN_FLT x96 = x63 + (-4 * x16) + x80;
	const GEN_FLT x97 = (x96 * lh_qk) + (-1 * x93 * lh_qi) + (x95 * lh_qw);
	const GEN_FLT x98 = (x93 * lh_qj) + (-1 * x95 * lh_qk) + (x96 * lh_qw);
	const GEN_FLT x99 = x93 + (x51 * x97) + (-1 * x0 * x98);
	const GEN_FLT x100 = (x95 * lh_qi) + (-1 * x96 * lh_qj) + (x93 * lh_qw);
	const GEN_FLT x101 = x95 + (x2 * x98) + (-1 * x51 * x100);
	const GEN_FLT x102 = (x0 * x100) + x96 + (-1 * x2 * x97);
	const GEN_FLT x103 = (-1 * x37 * ((-1 * x44 * ((x99 * x43) + (x42 * x101))) + (x41 * x102))) +
						 (-1 * x34 * ((x31 * x101) + (-1 * x99 * x27)));
	const GEN_FLT x104 = x69 + x92 + (-4 * x7);
	const GEN_FLT x105 = x94 + x83;
	const GEN_FLT x106 = (-4 * x9) + (-1 * x78) + x65;
	const GEN_FLT x107 = (x106 * lh_qk) + (x104 * lh_qw) + (-1 * x105 * lh_qi);
	const GEN_FLT x108 = (x105 * lh_qj) + (-1 * x104 * lh_qk) + (x106 * lh_qw);
	const GEN_FLT x109 = x105 + (x51 * x107) + (-1 * x0 * x108);
	const GEN_FLT x110 = 2 * ((x104 * lh_qi) + (-1 * x106 * lh_qj) + (x105 * lh_qw));
	const GEN_FLT x111 = x104 + (x2 * x108) + (-1 * x110 * lh_qi);
	const GEN_FLT x112 = (x110 * lh_qj) + x106 + (-1 * x2 * x107);
	const GEN_FLT x113 = (-1 * x37 * ((-1 * ((x43 * x109) + (x42 * x111)) * x44) + (x41 * x112))) +
						 (-1 * ((x31 * x111) + (-1 * x27 * x109)) * x34);
	out[0] = (x45 * x47) + x45 + (x49 * ((-1 * x40 * x31) + (x4 * x48)));
	out[1] = x57 + (x57 * x47) + (((-1 * x56 * x31) + (x53 * x48)) * x49);
	out[2] = (((-1 * x59 * x31) + (x58 * x48)) * x49) + x61 + (x61 * x47);
	out[3] = x77 + (x77 * x47) + (((-1 * x76 * x31) + (x73 * x48)) * x49);
	out[4] = x91 + (x91 * x47) + (((-1 * x90 * x31) + (x87 * x48)) * x49);
	out[5] = (x47 * x103) + x103 + (x49 * ((-1 * x31 * x102) + (x99 * x48)));
	out[6] = x113 + (x47 * x113) + (((-1 * x31 * x112) + (x48 * x109)) * x49);
}

// Jacobian of reproject_axis_y wrt [sensor_x, sensor_y, sensor_z]
static inline void gen_reproject_axis_y_jac_sensor_pt(FLT *out, const SurvivePose *obj_p, const FLT *sensor_pt,
													  const SurvivePose *lh_p, const BaseStationCal *bsc1) {
	const GEN_FLT obj_px = (*obj_p).Pos[0];
	const GEN_FLT obj_py = (*obj_p).Pos[1];
	const GEN_FLT obj_pz = (*obj_p).Pos[2];
	const GEN_FLT obj_qw = (*obj_p).Rot[0];
	const GEN_FLT obj_qi = (*obj_p).Rot[1];
	const GEN_FLT obj_qj = (*obj_p).Rot[2];
	const GEN_FLT obj_qk = (*obj_p).Rot[3];
	const GEN_FLT sensor_x = sensor_pt[0];
	const GEN_FLT sensor_y = sensor_pt[1];
	const GEN_FLT sensor_z = sensor_pt[2];
	const GEN_FLT lh_px = (*lh_p).Pos[0];
	const GEN_FLT lh_py = (*lh_p).Pos[1];
	const GEN_FLT lh_pz = (*lh_p).Pos[2];
	const GEN_FLT lh_qw = (*lh_p).Rot[0];
	const GEN_FLT lh_qi = (*lh_p).Rot[1];
	const GEN_FLT lh_qj = (*lh_p).Rot[2];
	const GEN_FLT lh_qk = (*lh_p).Rot[3];
	const GEN_FLT phase_1 = (*bsc1).phase;
	const GEN_FLT tilt_1 = (*bsc1).tilt;
	const GEN_FLT curve_1 = (*bsc1).curve;
	const GEN_FLT gibPhase_1 = (*bsc1).gibpha;
	const GEN_FLT gibMag_1 = (*bsc1).gibmag;
	const GEN_FLT ogeeMag_1 = (*bsc1).ogeephase;
	const GEN_FLT ogeePhase_1 = (*bsc1).ogeemag;
	const GEN_FLT x0 = (obj_qw * sensor_x) + (-1 * obj_qk * sensor_y) + (obj_qj * sensor_z);
	const GEN_FLT x1 = (obj_qk * sensor_x) + (-1 * obj_qi * sensor_z) + (obj_qw * sensor_y);
	const GEN_FLT x2 = (2 * ((x1 * obj_qi) + (-1 * x0 * obj_qj))) + obj_pz + sensor_z;
	const GEN_FLT x3 = (-1 * obj_qj * sensor_x) + (obj_qw * sensor_z) + (obj_qi * sensor_y);
	const GEN_FLT x4 = (2 * ((x0 * obj_qk) + (-1 * x3 * obj_qi))) + obj_py + sensor_y;
	const GEN_FLT x5 = (2 * ((x3 * obj_qj) + (-1 * x1 * obj_qk))) + obj_px + sensor_x;
	const GEN_FLT x6 = (-1 * x5 * lh_qj) + (x2 * lh_qw) + (x4 * lh_qi);
	const GEN_FLT x7 = (-1 * x4 * lh_qk) + (x5 * lh_qw) + (x2 * lh_qj);
	const GEN_FLT x8 = x4 + lh_py + (2 * ((x7 * lh_qk) + (-1 * x6 * lh_qi)));
	const GEN_FLT x9 = 2 * obj_qw;
	const GEN_FLT x10 = x9 * obj_qj;
	const GEN_FLT x11 = 2 * obj_qi;
	const GEN_FLT x12 = x11 * obj_qk;
	const GEN_FLT x13 = x12 + (-1 * x10);
	const GEN_FLT x14 = x11 * obj_qj;
	const GEN_FLT x15 = x9 * obj_qk;
	const GEN_FLT x16 = x15 + x14;
	const GEN_FLT x17 = -2 * (obj_qk * obj_qk);
	const GEN_FLT x18 = 1 + (-2 * (obj_qj * obj_qj));
	const GEN_FLT x19 = x18 + x17;
	const GEN_FLT x20 = (x19 * lh_qk) + (-1 * x13 * lh_qi) + (x16 * lh_qw);
	const GEN_FLT x21 = 2 * lh_qi;
	const GEN_FLT x22 = (x13 * lh_qj) + (x19 * lh_qw) + (-1 * x16 * lh_qk);
	const GEN_FLT x23 = 2 * lh_qj;
	const GEN_FLT x24 = x13 + (x20 * x21) + (-1 * x22 * x23);
	const GEN_FLT x25 = (-1 * x2 * lh_qi) + (x4 * lh_qw) + (x5 * lh_qk);
	const GEN_FLT x26 = x2 + lh_pz + (2 * ((x25 * lh_qi) + (-1 * x7 * lh_qj)));
	const GEN_FLT x27 = x26 * x26;
	const GEN_FLT x28 = 1. / x27;
	const GEN_FLT x29 = x24 * x28;
	const GEN_FLT x30 = 2 * lh_qk;
	const GEN_FLT x31 = (x16 * lh_qi) + (-1 * x19 * lh_qj) + (x13 * lh_qw);
	const GEN_FLT x32 = (x30 * x22) + x16 + (-1 * x31 * x21);
	const GEN_FLT x33 = 1. / x26;
	const GEN_FLT x34 = x27 + (x8 * x8);
	const GEN_FLT x35 = 1. / x34;
	const GEN_FLT x36 = x35 * x27;
	const GEN_FLT x37 = lh_px + x5 + (2 * ((x6 * lh_qj) + (-1 * x25 * lh_qk)));
	const GEN_FLT x38 = x37 * x37;
	const GEN_FLT x39 = 1. / sqrt(1 + (-1 * x35 * x38 * (tilt_1 * tilt_1)));
	const GEN_FLT x40 = x19 + (x31 * x23) + (-1 * x30 * x20);
	const GEN_FLT x41 = (1. / sqrt(x34)) * tilt_1;
	const GEN_FLT x42 = 2 * x8;
	const GEN_FLT x43 = 2 * x26;
	const GEN_FLT x44 = 1.0 / 2.0 * (1. / (x34 * sqrt(x34))) * x37 * tilt_1;
	const GEN_FLT x45 = (-1 * x39 * ((-1 * ((x43 * x24) + (x42 * x32)) * x44) + (x40 * x41))) +
						(-1 * x36 * ((x32 * x33) + (-1 * x8 * x29)));
	const GEN_FLT x46 = -1 * x26;
	const GEN_FLT x47 =
		sin(1.5707963267949 + (-1 * phase_1) + (-1 * atan2(-1 * x8, x46)) + gibPhase_1 + (-1 * asin(x41 * x37))) *
		gibMag_1;
	const GEN_FLT x48 = 2 * (1. / (x27 + x38)) * x27 * atan2(x37, x46) * curve_1;
	const GEN_FLT x49 = 2 * obj_qk * obj_qj;
	const GEN_FLT x50 = x9 * obj_qi;
	const GEN_FLT x51 = x50 + x49;
	const GEN_FLT x52 = -2 * (obj_qi * obj_qi);
	const GEN_FLT x53 = 1 + x17 + x52;
	const GEN_FLT x54 = x14 + (-1 * x15);
	const GEN_FLT x55 = (x54 * lh_qk) + (-1 * x51 * lh_qi) + (x53 * lh_qw);
	const GEN_FLT x56 = (x51 * lh_qj) + (x54 * lh_qw) + (-1 * x53 * lh_qk);
	const GEN_FLT x57 = x51 + (x55 * x21) + (-1 * x56 * x23);
	const GEN_FLT x58 = x8 * x28;
	const GEN_FLT x59 = (x53 * lh_qi) + (-1 * x54 * lh_qj) + (x51 * lh_qw);
	const GEN_FLT x60 = (x56 * x30) + x53 + (-1 * x59 * x21);
	const GEN_FLT x61 = x54 + (x59 * x23) + (-1 * x55 * x30);
	const GEN_FLT x62 = (-1 * x39 * ((-1 * ((x57 * x43) + (x60 * x42)) * x44) + (x61 * x41))) +
						(-1 * ((x60 * x33) + (-1 * x58 * x57)) * x36);
	const GEN_FLT x63 = x37 * x28;
	const GEN_FLT x64 = x18 + x52;
	const GEN_FLT x65 = x49 + (-1 * x50);
	const GEN_FLT x66 = x10 + x12;
	const GEN_FLT x67 = (-1 * x64 * lh_qi) + (x66 * lh_qk) + (x65 * lh_qw);
	const GEN_FLT x68 = (x64 * lh_qj) + (-1 * x65 * lh_qk) + (x66 * lh_qw);
	const GEN_FLT x69 = (x67 * x21) + x64 + (-1 * x68 * x23);
	const GEN_FLT x70 = (x65 * lh_qi) + (-1 * x66 * lh_qj) + (x64 * lh_qw);
	const GEN_FLT x71 = x65 + (x68 * x30) + (-1 * x70 * x21);
	const GEN_FLT x72 = x66 + (x70 * x23) + (-1 * x67 * x30);
	const GEN_FLT x73 = (-1 * x39 * ((-1 * ((x69 * x43) + (x71 * x42)) * x44) + (x72 * x41))) +
						(-1 * ((x71 * x33) + (-1 * x69 * x58)) * x36);
	out[0] = x45 + (x45 * x47) + (((-1 * x40 * x33) + (x37 * x29)) * x48);
	out[1] = x62 + (x62 * x47) + (((-1 * x61 * x33) + (x63 * x57)) * x48);
	out[2] = x73 + (x73 * x47) + (((-1 * x72 * x33) + (x63 * x69)) * x48);
}

// Jacobian of reproject_axis_y wrt [lh_px, lh_py, lh_pz, lh_qw, lh_qi, lh_qj, lh_qk]
static inline void gen_reproject_axis_y_jac_lh_p(FLT *out, const SurvivePose *obj_p, const FLT *sensor_pt,
												 const SurvivePose *lh_p, const BaseStationCal *bsc1) {
	const GEN_FLT obj_px = (*obj_p).Pos[0];
	const GEN_FLT obj_py = (*obj_p).Pos[1];
	const GEN_FLT obj_pz = (*obj_p).Pos[2];
	const GEN_FLT obj_qw = (*obj_p).Rot[0];
	const GEN_FLT obj_qi = (*obj_p).Rot[1];
	const GEN_FLT obj_qj = (*obj_p).Rot[2];
	const GEN_FLT obj_qk = (*obj_p).Rot[3];
	const GEN_FLT sensor_x = sensor_pt[0];
	const GEN_FLT sensor_y = sensor_pt[1];
	const GEN_FLT sensor_z = sensor_pt[2];
	const GEN_FLT lh_px = (*lh_p).Pos[0];
	const GEN_FLT lh_py = (*lh_p).Pos[1];
	const GEN_FLT lh_pz = (*lh_p).Pos[2];
	const GEN_FLT lh_qw = (*lh_p).Rot[0];
	const GEN_FLT lh_qi = (*lh_p).Rot[1];
	const GEN_FLT lh_qj = (*lh_p).Rot[2];
	const GEN_FLT lh_qk = (*lh_p).Rot[3];
	const GEN_FLT phase_1 = (*bsc1).phase;
	const GEN_FLT tilt_1 = (*bsc1).tilt;
	const GEN_FLT curve_1 = (*bsc1).curve;
	const GEN_FLT gibPhase_1 = (*bsc1).gibpha;
	const GEN_FLT gibMag_1 = (*bsc1).gibmag;
	const GEN_FLT ogeeMag_1 = (*bsc1).ogeephase;
	const GEN_FLT ogeePhase_1 = (*bsc1).ogeemag;
	const GEN_FLT x0 = (-1 * obj_qj * sensor_x) + (obj_qw * sensor_z) + (obj_qi * sensor_y);
	const GEN_FLT x1 = (obj_qw * sensor_x) + (-1 * obj_qk * sensor_y) + (obj_qj * sensor_z);
	const GEN_FLT x2 = 2 * ((x1 * obj_qk) + (-1 * x0 * obj_qi));
	const GEN_FLT x3 = x2 + obj_py + sensor_y;
	const GEN_FLT x4 = x3 * lh_qw;
	const GEN_FLT x5 = (obj_qk * sensor_x) + (-1 * obj_qi * sensor_z) + (obj_qw * sensor_y);
	const GEN_FLT x6 = 2 * ((x0 * obj_qj) + (-1 * x5 * obj_qk));
	const GEN_FLT x7 = x6 + obj_px + sensor_x;
	const GEN_FLT x8 = x7 * lh_qk;
	const GEN_FLT x9 = 2 * ((x5 * obj_qi) + (-1 * x1 * obj_qj));
	const GEN_FLT x10 = x9 + obj_pz + sensor_z;
	const GEN_FLT x11 = x10 * lh_qi;
	const GEN_FLT x12 = (-1 * x11) + x4 + x8;
	const GEN_FLT x13 = x10 * lh_qw;
	const GEN_FLT x14 = x3 * lh_qi;
	const GEN_FLT x15 = x7 * lh_qj;
	const GEN_FLT x16 = (-1 * x15) + x13 + x14;
	const GEN_FLT x17 = x7 + lh_px + (2 * ((x16 * lh_qj) + (-1 * x12 * lh_qk)));
	const GEN_FLT x18 = x7 * lh_qw;
	const GEN_FLT x19 = x10 * lh_qj;
	const GEN_FLT x20 = x3 * lh_qk;
	const GEN_FLT x21 = (-1 * x20) + x18 + x19;
	const GEN_FLT x22 = x10 + lh_pz + (2 * ((x12 * lh_qi) + (-1 * x21 * lh_qj)));
	const GEN_FLT x23 = x22 * x22;
	const GEN_FLT x24 = x3 + lh_py + (2 * ((x21 * lh_qk) + (-1 * x16 * lh_qi)));
	const GEN_FLT x25 = (x24 * x24) + x23;
	const GEN_FLT x26 = (1. / sqrt(x25)) * tilt_1;
	const GEN_FLT x27 = -1 * x22;
	const GEN_FLT x28 =
		sin(1.5707963267949 + gibPhase_1 + (-1 * phase_1) + (-1 * atan2(-1 * x24, x27)) + (-1 * asin(x26 * x17))) *
		gibMag_1;
	const GEN_FLT x29 = 1. / x25;
	const GEN_FLT x30 = x17 * x17;
	const GEN_FLT x31 = 1. / sqrt(1 + (-1 * x30 * x29 * (tilt_1 * tilt_1)));
	const GEN_FLT x32 = x31 * x26;
	const GEN_FLT x33 = 2 * x22;
	const GEN_FLT x34 = (1. / (x23 + x30)) * atan2(x17, x27) * curve_1;
	const GEN_FLT x35 = (1. / (x25 * sqrt(x25))) * x17 * tilt_1;
	const GEN_FLT x36 = x31 * x35;
	const GEN_FLT x37 = (x36 * x24) + (-1 * x22 * x29);
	const GEN_FLT x38 = (x36 * x22) + (x24 * x29);
	const GEN_FLT x39 = 2 * x34;
	const GEN_FLT x40 = 2 * x15;
	const GEN_FLT x41 = (2 * x14) + (-1 * x40);
	const GEN_FLT x42 = 1. / x23;
	const GEN_FLT x43 = x42 * x24;
	const GEN_FLT x44 = 1. / x22;
	const GEN_FLT x45 = 2 * x11;
	const GEN_FLT x46 = (2 * x8) + (-1 * x45);
	const GEN_FLT x47 = x23 * x29;
	const GEN_FLT x48 = 2 * x20;
	const GEN_FLT x49 = (2 * x19) + (-1 * x48);
	const GEN_FLT x50 = 2 * x24;
	const GEN_FLT x51 = 1.0 / 2.0 * x35;
	const GEN_FLT x52 = (-1 * x31 * ((-1 * ((x41 * x33) + (x50 * x46)) * x51) + (x49 * x26))) +
						(-1 * ((x44 * x46) + (-1 * x41 * x43)) * x47);
	const GEN_FLT x53 = x42 * x17;
	const GEN_FLT x54 = x39 * x23;
	const GEN_FLT x55 = 2 * x4;
	const GEN_FLT x56 = (-1 * obj_pz) + (-1 * sensor_z) + (-1 * x9);
	const GEN_FLT x57 = 2 * lh_qi;
	const GEN_FLT x58 = x46 + x55 + (x57 * x56);
	const GEN_FLT x59 = 2 * x13;
	const GEN_FLT x60 = (-4 * x14) + x40 + (-1 * x59);
	const GEN_FLT x61 = 2 * lh_qk;
	const GEN_FLT x62 = 2 * lh_qj;
	const GEN_FLT x63 = (x3 * x62) + (-1 * x61 * x56);
	const GEN_FLT x64 = (-1 * x31 * ((-1 * ((x58 * x33) + (x60 * x50)) * x51) + (x63 * x26))) +
						(-1 * ((x60 * x44) + (-1 * x58 * x43)) * x47);
	const GEN_FLT x65 = 2 * x18;
	const GEN_FLT x66 = (-1 * x65) + (-4 * x19) + x48;
	const GEN_FLT x67 = (-1 * sensor_x) + (-1 * obj_px) + (-1 * x6);
	const GEN_FLT x68 = (x61 * x10) + (-1 * x67 * x57);
	const GEN_FLT x69 = x41 + (x62 * x67) + x59;
	const GEN_FLT x70 = (-1 * x31 * ((-1 * ((x66 * x33) + (x68 * x50)) * x51) + (x69 * x26))) +
						(-1 * ((x68 * x44) + (-1 * x66 * x43)) * x47);
	const GEN_FLT x71 = (-1 * sensor_y) + (-1 * obj_py) + (-1 * x2);
	const GEN_FLT x72 = (x7 * x57) + (-1 * x71 * x62);
	const GEN_FLT x73 = x49 + x65 + (x71 * x61);
	const GEN_FLT x74 = (-4 * x8) + (-1 * x55) + x45;
	const GEN_FLT x75 = (-1 * x31 * ((-1 * ((x72 * x33) + (x73 * x50)) * x51) + (x74 * x26))) +
						(-1 * ((x73 * x44) + (-1 * x72 * x43)) * x47);
	out[0] = (-1 * x32) + (-1 * x32 * x28) + (-1 * x34 * x33);
	out[1] = x37 + (x37 * x28);
	out[2] = x38 + (x38 * x28) + (x39 * x17);
	out[3] = x52 + (x52 * x28) + (((-1 * x44 * x49) + (x53 * x41)) * x54);
	out[4] = x64 + (x64 * x28) + (((-1 * x63 * x44) + (x53 * x58)) * x54);
	out[5] = x70 + (x70 * x28) + (((-1 * x69 * x44) + (x66 * x53)) * x54);
	out[6] = x75 + (x75 * x28) + (((-1 * x74 * x44) + (x72 * x53)) * x54);
}

// Jacobian of reproject_axis_y wrt [phase_1, tilt_1, curve_1, gibPhase_1, gibMag_1, ogeeMag_1, ogeePhase_1]
static inline void gen_reproject_axis_y_jac_bsc1(FLT *out, const SurvivePose *obj_p, const FLT *sensor_pt,
												 const SurvivePose *lh_p, const BaseStationCal *bsc1) {
	const GEN_FLT obj_px = (*obj_p).Pos[0];
	const GEN_FLT obj_py = (*obj_p).Pos[1];
	const GEN_FLT obj_pz = (*obj_p).Pos[2];
	const GEN_FLT obj_qw = (*obj_p).Rot[0];
	const GEN_FLT obj_qi = (*obj_p).Rot[1];
	const GEN_FLT obj_qj = (*obj_p).Rot[2];
	const GEN_FLT obj_qk = (*obj_p).Rot[3];
	const GEN_FLT sensor_x = sensor_pt[0];
	const GEN_FLT sensor_y = sensor_pt[1];
	const GEN_FLT sensor_z = sensor_pt[2];
	const GEN_FLT lh_px = (*lh_p).Pos[0];
	const GEN_FLT lh_py = (*lh_p).Pos[1];
	const GEN_FLT lh_pz = (*lh_p).Pos[2];
	const GEN_FLT lh_qw = (*lh_p).Rot[0];
	const GEN_FLT lh_qi = (*lh_p).Rot[1];
	const GEN_FLT lh_qj = (*lh_p).Rot[2];
	const GEN_FLT lh_qk = (*lh_p).Rot[3];
	const GEN_FLT phase_1 = (*bsc1).phase;
	const GEN_FLT tilt_1 = (*bsc1).tilt;
	const GEN_FLT curve_1 = (*bsc1).curve;
	const GEN_FLT gibPhase_1 = (*bsc1).gibpha;
	const GEN_FLT gibMag_1 = (*bsc1).gibmag;
	const GEN_FLT ogeeMag_1 = (*bsc1).ogeephase;
	const GEN_FLT ogeePhase_1 = (*bsc1).ogeemag;
	const GEN_FLT x0 = (obj_qk * sensor_x) + (-1 * obj_qi * sensor_z) + (obj_qw * sensor_y);
	const GEN_FLT x1 = (-1 * obj_qj * sensor_x) + (obj_qw * sensor_z) + (obj_qi * sensor_y);
	const GEN_FLT x2 = (2 * ((x1 * obj_qj) + (-1 * x0 * obj_qk))) + obj_px + sensor_x;
	const GEN_FLT x3 = (obj_qw * sensor_x) + (-1 * obj_qk * sensor_y) + (obj_qj * sensor_z);
	const GEN_FLT x4 = (2 * ((x0 * obj_qi) + (-1 * x3 * obj_qj))) + obj_pz + sensor_z;
	const GEN_FLT x5 = obj_py + (2 * ((x3 * obj_qk) + (-1 * x1 * obj_qi))) + sensor_y;
	const GEN_FLT x6 = (-1 * x5 * lh_qk) + (x2 * lh_qw) + (x4 * lh_qj);
	const GEN_FLT x7 = (x5 * lh_qw) + (-1 * x4 * lh_qi) + (x2 * lh_qk);
	const GEN_FLT x8 = x4 + lh_pz + (2 * ((x7 * lh_qi) + (-1 * x6 * lh_qj)));
	const GEN_FLT x9 = (x4 * lh_qw) + (-1 * x2 * lh_qj) + (x5 * lh_qi);
	const GEN_FLT x10 = x5 + lh_py + (2 * ((x6 * lh_qk) + (-1 * x9 * lh_qi)));
	const GEN_FLT x11 = (x10 * x10) + (x8 * x8);
	const GEN_FLT x12 = lh_px + x2 + (2 * ((x9 * lh_qj) + (-1 * x7 * lh_qk)));
	const GEN_FLT x13 = x12 * (1. / sqrt(x11));
	const GEN_FLT x14 = -1 * x8;
	const GEN_FLT x15 =
		1.5707963267949 + (-1 * phase_1) + (-1 * atan2(-1 * x10, x14)) + gibPhase_1 + (-1 * asin(x13 * tilt_1));
	const GEN_FLT x16 = sin(x15) * gibMag_1;
	const GEN_FLT x17 = x13 * (1. / sqrt(1 + (-1 * (x12 * x12) * (1. / x11) * (tilt_1 * tilt_1))));
	out[0] = -1 + (-1 * x16);
	out[1] = (-1 * x17) + (-1 * x17 * x16);
	out[2] = atan2(x12, x14) * atan2(x12, x14);
	out[3] = x16;
	out[4] = -1 * cos(x15);
	out[5] = 0;
	out[6] = 0;
}
