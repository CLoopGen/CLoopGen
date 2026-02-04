#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG row;
extern BLASLONG i;
extern BLASLONG ii;
extern float *src0;
extern float *src1;
extern float *dest0;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < row / 8; i += 1) {
    dest0[0] = src0[0];
    dest0[1] = src0[1];
    dest0[2] = src1[0];
    dest0[3] = src1[1];
    dest0[4] = src0[2];
    dest0[5] = src0[3];
    dest0[6] = src1[2];
    dest0[7] = src1[3];
    dest0[8] = src0[4];
    dest0[9] = src0[5];
    dest0[10] = src1[4];
    dest0[11] = src1[5];
    dest0[12] = src0[6];
    dest0[13] = src0[7];
    dest0[14] = src1[6];
    dest0[15] = src1[7];
    dest0[16] = src0[8];
    dest0[17] = src0[9];
    dest0[18] = src1[8];
    dest0[19] = src1[9];
    dest0[20] = src0[10];
    dest0[21] = src0[11];
    dest0[22] = src1[10];
    dest0[23] = src1[11];
    dest0[24] = src0[12];
    dest0[25] = src0[13];
    dest0[26] = src1[12];
    dest0[27] = src1[13];
    dest0[28] = src0[14];
    dest0[29] = src0[15];
    dest0[30] = src1[14];
    dest0[31] = src1[15];
    src0 = src0 + 16;
    src1 = src1 + 16;
    ii = (8 << 2);
    dest0 = dest0 + ii;
}
}
