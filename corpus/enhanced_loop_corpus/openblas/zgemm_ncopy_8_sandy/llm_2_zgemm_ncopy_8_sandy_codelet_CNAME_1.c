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
    BLASLONG base_dest = i * 32;
    dest0[base_dest + 0] = src0[0];
    dest0[base_dest + 1] = src0[1];
    dest0[base_dest + 2] = src1[0];
    dest0[base_dest + 3] = src1[1];
    dest0[base_dest + 4] = src2[0];
    dest0[base_dest + 5] = src2[1];
    dest0[base_dest + 6] = src3[0];
    dest0[base_dest + 7] = src3[1];
    dest0[base_dest + 8] = src0[2];
    dest0[base_dest + 9] = src0[3];
    dest0[base_dest + 10] = src1[2];
    dest0[base_dest + 11] = src1[3];
    dest0[base_dest + 12] = src2[2];
    dest0[base_dest + 13] = src2[3];
    dest0[base_dest + 14] = src3[2];
    dest0[base_dest + 15] = src3[3];
    dest0[base_dest + 16] = src0[4];
    dest0[base_dest + 17] = src0[5];
    dest0[base_dest + 18] = src1[4];
    dest0[base_dest + 19] = src1[5];
    dest0[base_dest + 20] = src2[4];
    dest0[base_dest + 21] = src2[5];
    dest0[base_dest + 22] = src3[4];
    dest0[base_dest + 23] = src3[5];
    dest0[base_dest + 24] = src0[6];
    dest0[base_dest + 25] = src0[7];
    dest0[base_dest + 26] = src1[6];
    dest0[base_dest + 27] = src1[7];
    dest0[base_dest + 28] = src2[6];
    dest0[base_dest + 29] = src2[7];
    dest0[base_dest + 30] = src3[6];
    dest0[base_dest + 31] = src3[7];
    src0 += 8;
    src1 += 8;
    src2 += 8;
    src3 += 8;
}
}
