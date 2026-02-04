#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG row;
extern BLASLONG i;
extern BLASLONG ii;
extern float *src0;
extern float *src1;
extern float *src2;
extern float *src3;
extern float *dest0;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < row / 4; i += 1) {
    float temp0_0 = src0[0], temp0_1 = src0[1], temp0_2 = src0[2], temp0_3 = src0[3];
    float temp0_4 = src0[4], temp0_5 = src0[5], temp0_6 = src0[6], temp0_7 = src0[7];
    float temp1_0 = src1[0], temp1_1 = src1[1], temp1_2 = src1[2], temp1_3 = src1[3];
    float temp1_4 = src1[4], temp1_5 = src1[5], temp1_6 = src1[6], temp1_7 = src1[7];
    float temp2_0 = src2[0], temp2_1 = src2[1], temp2_2 = src2[2], temp2_3 = src2[3];
    float temp2_4 = src2[4], temp2_5 = src2[5], temp2_6 = src2[6], temp2_7 = src2[7];
    float temp3_0 = src3[0], temp3_1 = src3[1], temp3_2 = src3[2], temp3_3 = src3[3];
    float temp3_4 = src3[4], temp3_5 = src3[5], temp3_6 = src3[6], temp3_7 = src3[7];

    dest0[0] = temp0_0;
    dest0[1] = temp0_1;
    dest0[2] = temp1_0;
    dest0[3] = temp1_1;
    dest0[4] = temp2_0;
    dest0[5] = temp2_1;
    dest0[6] = temp3_0;
    dest0[7] = temp3_1;
    dest0[8] = temp0_2;
    dest0[9] = temp0_3;
    dest0[10] = temp1_2;
    dest0[11] = temp1_3;
    dest0[12] = temp2_2;
    dest0[13] = temp2_3;
    dest0[14] = temp3_2;
    dest0[15] = temp3_3;
    dest0[16] = temp0_4;
    dest0[17] = temp0_5;
    dest0[18] = temp1_4;
    dest0[19] = temp1_5;
    dest0[20] = temp2_4;
    dest0[21] = temp2_5;
    dest0[22] = temp3_4;
    dest0[23] = temp3_5;
    dest0[24] = temp0_6;
    dest0[25] = temp0_7;
    dest0[26] = temp1_6;
    dest0[27] = temp1_7;
    dest0[28] = temp2_6;
    dest0[29] = temp2_7;
    dest0[30] = temp3_6;
    dest0[31] = temp3_7;

    src0 = src0 + 8;
    src1 = src1 + 8;
    src2 = src2 + 8;
    src3 = src3 + 8;
    ii = (4 << 3);
    dest0 = dest0 + ii;
}
}
