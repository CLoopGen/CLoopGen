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
BLASLONG offset = 0;
for (i = 0; i < row / 4; i += 1) {
    dest0[offset + 0] = src0[0];
    dest0[offset + 1] = src0[1];
    dest0[offset + 2] = src1[0];
    dest0[offset + 3] = src1[1];
    dest0[offset + 4] = src2[0];
    dest0[offset + 5] = src2[1];
    dest0[offset + 6] = src3[0];
    dest0[offset + 7] = src3[1];
    dest0[offset + 8] = src0[2];
    dest0[offset + 9] = src0[3];
    dest0[offset + 10] = src1[2];
    dest0[offset + 11] = src1[3];
    dest0[offset + 12] = src2[2];
    dest0[offset + 13] = src2[3];
    dest0[offset + 14] = src3[2];
    dest0[offset + 15] = src3[3];
    dest0[offset + 16] = src0[4];
    dest0[offset + 17] = src0[5];
    dest0[offset + 18] = src1[4];
    dest0[offset + 19] = src1[5];
    dest0[offset + 20] = src2[4];
    dest0[offset + 21] = src2[5];
    dest0[offset + 22] = src3[4];
    dest0[offset + 23] = src3[5];
    dest0[offset + 24] = src0[6];
    dest0[offset + 25] = src0[7];
    dest0[offset + 26] = src1[6];
    dest0[offset + 27] = src1[7];
    dest0[offset + 28] = src2[6];
    dest0[offset + 29] = src2[7];
    dest0[offset + 30] = src3[6];
    dest0[offset + 31] = src3[7];

    src0 = src0 + 8;
    src1 = src1 + 8;
    src2 = src2 + 8;
    src3 = src3 + 8;
    offset += (4 << 3);
}
}
