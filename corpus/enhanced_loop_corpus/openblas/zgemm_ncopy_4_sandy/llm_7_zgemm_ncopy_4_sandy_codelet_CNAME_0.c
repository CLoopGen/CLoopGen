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
extern float *dest0;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < col / 4; j += 1) {
    src0 = src;
    src1 = src0 + 2 * srcdim;
    src2 = src1 + 2 * srcdim;
    src3 = src2 + 2 * srcdim;
    src = src3 + 2 * srcdim;
    dest0 = dest;
    ii = (row << 3);
    dest = dest + ii;
    for (i = 0; i < row / 4; i += 1) {
        float temp0, temp1, temp2, temp3;
        temp0 = src0[0]; temp1 = src0[1];
        temp2 = src1[0]; temp3 = src1[1];
        dest0[0] = temp0;
        dest0[1] = temp1;
        dest0[2] = temp2;
        dest0[3] = temp3;
        temp0 = src2[0]; temp1 = src2[1];
        temp2 = src3[0]; temp3 = src3[1];
        dest0[4] = temp0;
        dest0[5] = temp1;
        dest0[6] = temp2;
        dest0[7] = temp3;
        temp0 = src0[2]; temp1 = src0[3];
        temp2 = src1[2]; temp3 = src1[3];
        dest0[8] = temp0;
        dest0[9] = temp1;
        dest0[10] = temp2;
        dest0[11] = temp3;
        temp0 = src2[2]; temp1 = src2[3];
        temp2 = src3[2]; temp3 = src3[3];
        dest0[12] = temp0;
        dest0[13] = temp1;
        dest0[14] = temp2;
        dest0[15] = temp3;
        temp0 = src0[4]; temp1 = src0[5];
        temp2 = src1[4]; temp3 = src1[5];
        dest0[16] = temp0;
        dest0[17] = temp1;
        dest0[18] = temp2;
        dest0[19] = temp3;
        temp0 = src2[4]; temp1 = src2[5];
        temp2 = src3[4]; temp3 = src3[5];
        dest0[20] = temp0;
        dest0[21] = temp1;
        dest0[22] = temp2;
        dest0[23] = temp3;
        temp0 = src0[6]; temp1 = src0[7];
        temp2 = src1[6]; temp3 = src1[7];
        dest0[24] = temp0;
        dest0[25] = temp1;
        dest0[26] = temp2;
        dest0[27] = temp3;
        temp0 = src2[6]; temp1 = src2[7];
        temp2 = src3[6]; temp3 = src3[7];
        dest0[28] = temp0;
        dest0[29] = temp1;
        dest0[30] = temp2;
        dest0[31] = temp3;
        src0 = src0 + 8;
        src1 = src1 + 8;
        src2 = src2 + 8;
        src3 = src3 + 8;
        ii = (4 << 3);
        dest0 = dest0 + ii;
    }
    if (row & 2) {
        float temp0, temp1, temp2, temp3;
        temp0 = src0[0]; temp1 = src0[1];
        temp2 = src1[0]; temp3 = src1[1];
        dest0[0] = temp0;
        dest0[1] = temp1;
        dest0[2] = temp2;
        dest0[3] = temp3;
        temp0 = src2[0]; temp1 = src2[1];
        temp2 = src3[0]; temp3 = src3[1];
        dest0[4] = temp0;
        dest0[5] = temp1;
        dest0[6] = temp2;
        dest0[7] = temp3;
        temp0 = src0[2]; temp1 = src0[3];
        temp2 = src1[2]; temp3 = src1[3];
        dest0[8] = temp0;
        dest0[9] = temp1;
        dest0[10] = temp2;
        dest0[11] = temp3;
        temp0 = src2[2]; temp1 = src2[3];
        temp2 = src3[2]; temp3 = src3[3];
        dest0[12] = temp0;
        dest0[13] = temp1;
        dest0[14] = temp2;
        dest0[15] = temp3;
        src0 = src0 + 4;
        src1 = src1 + 4;
        src2 = src2 + 4;
        src3 = src3 + 4;
        ii = (2 << 3);
        dest0 = dest0 + ii;
    }
    if (row & 1) {
        float temp0, temp1, temp2, temp3;
        temp0 = src0[0]; temp1 = src0[1];
        temp2 = src1[0]; temp3 = src1[1];
        dest0[0] = temp0;
        dest0[1] = temp1;
        dest0[2] = temp2;
        dest0[3] = temp3;
        temp0 = src2[0]; temp1 = src2[1];
        temp2 = src3[0]; temp3 = src3[1];
        dest0[4] = temp0;
        dest0[5] = temp1;
        dest0[6] = temp2;
        dest0[7] = temp3;
        src0 = src0 + 2;
        src1 = src1 + 2;
        src2 = src2 + 2;
        src3 = src3 + 2;
        ii = (1 << 3);
        dest0 = dest0 + ii;
    }
}
}
