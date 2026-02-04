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
extern float *dest1;
extern float *dest2;
extern float *dest4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < row / 2; j += 2) {
    src0 = src;
    src1 = src0 + srcdim;
    src2 = src1 + srcdim;
    src3 = src2 + srcdim;
    src = src3 + 2 * srcdim;
    dest0 = dest;
    ii = (2 << 5);
    dest = dest + ii;
    for (i = 0; i < col / 4; i += 1) {
        BLASLONG offset = i * 16;
        dest0[offset +  0] = src0[0]; dest0[offset +  1] = src0[1];
        dest0[offset +  2] = src0[2]; dest0[offset +  3] = src0[3];
        dest0[offset +  4] = src1[0]; dest0[offset +  5] = src1[1];
        dest0[offset +  6] = src1[2]; dest0[offset +  7] = src1[3];
        dest0[offset +  8] = src2[0]; dest0[offset +  9] = src2[1];
        dest0[offset + 10] = src2[2]; dest0[offset + 11] = src2[3];
        dest0[offset + 12] = src3[0]; dest0[offset + 13] = src3[1];
        dest0[offset + 14] = src3[2]; dest0[offset + 15] = src3[3];

        dest0[offset + 16] = src0[4]; dest0[offset + 17] = src0[5];
        dest0[offset + 18] = src0[6]; dest0[offset + 19] = src0[7];
        dest0[offset + 20] = src1[4]; dest0[offset + 21] = src1[5];
        dest0[offset + 22] = src1[6]; dest0[offset + 23] = src1[7];
        dest0[offset + 24] = src2[4]; dest0[offset + 25] = src2[5];
        dest0[offset + 26] = src2[6]; dest0[offset + 27] = src2[7];
        dest0[offset + 28] = src3[4]; dest0[offset + 29] = src3[5];
        dest0[offset + 30] = src3[6]; dest0[offset + 31] = src3[7];
    }
    if (col & 2) {
        BLASLONG base = (col / 4) * 16;
        dest0[base + 0] = src0[8]; dest0[base + 1] = src0[9];
        dest0[base + 2] = src1[8]; dest0[base + 3] = src1[9];
        dest0[base + 4] = src2[8]; dest0[base + 5] = src2[9];
        dest0[base + 6] = src3[8]; dest0[base + 7] = src3[9];
    }
    if (col & 1) {
        BLASLONG base = (col / 4) * 16 + ((col & 2) ? 8 : 0);
        dest0[base + 0] = src0[10];
        dest0[base + 1] = src1[10];
        dest0[base + 2] = src2[10];
        dest0[base + 3] = src3[10];
    }
    src0 += 11; src1 += 11; src2 += 11; src3 += 11;
}
}
