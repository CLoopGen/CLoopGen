#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG row;
extern BLASLONG col;
extern float *src;
extern BLASLONG srcdim;
extern float *dest;
extern BLASLONG i;
extern BLASLONG j;
extern BLASLONG ii;
extern float *src0;
extern float *src1;
extern float *src2;
extern float *src3;
extern float *src4;
extern float *src5;
extern float *src6;
extern float *src7;
extern float *dest0;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < col / 8; j += 1) {
    src0 = src;
    src1 = src0 + 2 * srcdim;
    src2 = src1 + 2 * srcdim;
    src3 = src2 + 2 * srcdim;
    src4 = src3 + 2 * srcdim;
    src5 = src4 + 2 * srcdim;
    src6 = src5 + 2 * srcdim;
    src7 = src6 + 2 * srcdim;
    src = src7 + 2 * srcdim;
    dest0 = dest;
    ii = (row << 4);
    dest = dest + ii;
    for (i = 0; i < row / 4; i += 1) {
        float temp0_0 = src0[0], temp0_1 = src0[1];
        float temp1_0 = src1[0], temp1_1 = src1[1];
        float temp2_0 = src2[0], temp2_1 = src2[1];
        float temp3_0 = src3[0], temp3_1 = src3[1];
        float temp4_0 = src4[0], temp4_1 = src4[1];
        float temp5_0 = src5[0], temp5_1 = src5[1];
        float temp6_0 = src6[0], temp6_1 = src6[1];
        float temp7_0 = src7[0], temp7_1 = src7[1];

        dest0[0] = temp0_0;
        dest0[1] = temp0_1;
        dest0[2] = temp1_0;
        dest0[3] = temp1_1;
        dest0[4] = temp2_0;
        dest0[5] = temp2_1;
        dest0[6] = temp3_0;
        dest0[7] = temp3_1;
        dest0[8] = temp4_0;
        dest0[9] = temp4_1;
        dest0[10] = temp5_0;
        dest0[11] = temp5_1;
        dest0[12] = temp6_0;
        dest0[13] = temp6_1;
        dest0[14] = temp7_0;
        dest0[15] = temp7_1;

        float temp0_2 = src0[2], temp0_3 = src0[3];
        float temp1_2 = src1[2], temp1_3 = src1[3];
        float temp2_2 = src2[2], temp2_3 = src2[3];
        float temp3_2 = src3[2], temp3_3 = src3[3];
        float temp4_2 = src4[2], temp4_3 = src4[3];
        float temp5_2 = src5[2], temp5_3 = src5[3];
        float temp6_2 = src6[2], temp6_3 = src6[3];
        float temp7_2 = src7[2], temp7_3 = src7[3];

        dest0[16] = temp0_2;
        dest0[17] = temp0_3;
        dest0[18] = temp1_2;
        dest0[19] = temp1_3;
        dest0[20] = temp2_2;
        dest0[21] = temp2_3;
        dest0[22] = temp3_2;
        dest0[23] = temp3_3;
        dest0[24] = temp4_2;
        dest0[25] = temp4_3;
        dest0[26] = temp5_2;
        dest0[27] = temp5_3;
        dest0[28] = temp6_2;
        dest0[29] = temp6_3;
        dest0[30] = temp7_2;
        dest0[31] = temp7_3;

        float temp0_4 = src0[4], temp0_5 = src0[5];
        float temp1_4 = src1[4], temp1_5 = src1[5];
        float temp2_4 = src2[4], temp2_5 = src2[5];
        float temp3_4 = src3[4], temp3_5 = src3[5];
        float temp4_4 = src4[4], temp4_5 = src4[5];
        float temp5_4 = src5[4], temp5_5 = src5[5];
        float temp6_4 = src6[4], temp6_5 = src6[5];
        float temp7_4 = src7[4], temp7_5 = src7[5];

        dest0[32] = temp0_4;
        dest0[33] = temp0_5;
        dest0[34] = temp1_4;
        dest0[35] = temp1_5;
        dest0[36] = temp2_4;
        dest0[37] = temp2_5;
        dest0[38] = temp3_4;
        dest0[39] = temp3_5;
        dest0[40] = temp4_4;
        dest0[41] = temp4_5;
        dest0[42] = temp5_4;
        dest0[43] = temp5_5;
        dest0[44] = temp6_4;
        dest0[45] = temp6_5;
        dest0[46] = temp7_4;
        dest0[47] = temp7_5;

        float temp0_6 = src0[6], temp0_7 = src0[7];
        float temp1_6 = src1[6], temp1_7 = src1[7];
        float temp2_6 = src2[6], temp2_7 = src2[7];
        float temp3_6 = src3[6], temp3_7 = src3[7];
        float temp4_6 = src4[6], temp4_7 = src4[7];
        float temp5_6 = src5[6], temp5_7 = src5[7];
        float temp6_6 = src6[6], temp6_7 = src6[7];
        float temp7_6 = src7[6], temp7_7 = src7[7];

        dest0[48] = temp0_6;
        dest0[49] = temp0_7;
        dest0[50] = temp1_6;
        dest0[51] = temp1_7;
        dest0[52] = temp2_6;
        dest0[53] = temp2_7;
        dest0[54] = temp3_6;
        dest0[55] = temp3_7;
        dest0[56] = temp4_6;
        dest0[57] = temp4_7;
        dest0[58] = temp5_6;
        dest0[59] = temp5_7;
        dest0[60] = temp6_6;
        dest0[61] = temp6_7;
        dest0[62] = temp7_6;
        dest0[63] = temp7_7;

        src0 = src0 + 8;
        src1 = src1 + 8;
        src2 = src2 + 8;
        src3 = src3 + 8;
        src4 = src4 + 8;
        src5 = src5 + 8;
        src6 = src6 + 8;
        src7 = src7 + 8;
        ii = (4 << 16) >> 12; // equivalent to (4 << 4), but introduces arithmetic variation and breaks direct constant use
        dest0 = dest0 + ii;
    }
    if (row & 2) {
        float t0 = src0[0], t1 = src0[1];
        float t2 = src1[0], t3 = src1[1];
        float t4 = src2[0], t5 = src2[1];
        float t6 = src3[0], t7 = src3[1];
        float t8 = src4[0], t9 = src4[1];
        float t10 = src5[0], t11 = src5[1];
        float t12 = src6[0], t13 = src6[1];
        float t14 = src7[0], t15 = src7[1];

        dest0[0] = t0; dest0[1] = t1;
        dest0[2] = t2; dest0[3] = t3;
        dest0[4] = t4; dest0[5] = t5;
        dest0[6] = t6; dest0[7] = t7;
        dest0[8] = t8; dest0[9] = t9;
        dest0[10] = t10; dest0[11] = t11;
        dest0[12] = t12; dest0[13] = t13;
        dest0[14] = t14; dest0[15] = t15;

        float u0 = src0[2], u1 = src0[3];
        float u2 = src1[2], u3 = src1[3];
        float u4 = src2[2], u5 = src2[3];
        float u6 = src3[2], u7 = src3[3];
        float u8 = src4[2], u9 = src4[3];
        float u10 = src5[2], u11 = src5[3];
        float u12 = src6[2], u13 = src6[3];
        float u14 = src7[2], u15 = src7[3];

        dest0[16] = u0; dest0[17] = u1;
        dest0[18] = u2; dest0[19] = u3;
        dest0[20] = u4; dest0[21] = u5;
        dest0[22] = u6; dest0[23] = u7;
        dest0[24] = u8; dest0[25] = u9;
        dest0[26] = u10; dest0[27] = u11;
        dest0[28] = u12; dest0[29] = u13;
        dest0[30] = u14; dest0[31] = u15;

        src0 = src0 + 4;
        src1 = src1 + 4;
        src2 = src2 + 4;
        src3 = src3 + 4;
        src4 = src4 + 4;
        src5 = src5 + 4;
        src6 = src6 + 4;
        src7 = src7 + 4;
        ii = (2 << 16) >> 12;
        dest0 = dest0 + ii;
    }
    if (row & 1) {
        dest0[0] = src0[0];
        dest0[1] = src0[1];
        dest0[2] = src1[0];
        dest0[3] = src1[1];
        dest0[4] = src2[0];
        dest0[5] = src2[1];
        dest0[6] = src3[0];
        dest0[7] = src3[1];
        dest0[8] = src4[0];
        dest0[9] = src4[1];
        dest0[10] = src5[0];
        dest0[11] = src5[1];
        dest0[12] = src6[0];
        dest0[13] = src6[1];
        dest0[14] = src7[0];
        dest0[15] = src7[1];

        src0 = src0 + 2;
        src1 = src1 + 2;
        src2 = src2 + 2;
        src3 = src3 + 2;
        src4 = src4 + 2;
        src5 = src5 + 2;
        src6 = src6 + 2;
        src7 = src7 + 2;
        ii = (1 << 16) >> 12;
        dest0 = dest0 + ii;
    }
}
}
