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
for (j = 0; j < row / 8; j += 1) {
    src0 = src;
    src1 = src0 + 2 * srcdim;
    src2 = src1 + 2 * srcdim;
    src3 = src2 + 2 * srcdim;
    src = src3 + 4 * srcdim;
    dest0 = dest;
    ii = (8 << 4);
    dest = dest + ii;
    for (i = 0; i < col / 16; i += 1) {
        for (BLASLONG k = 0; k < 8; k++) {
            dest0[k]           = src0[k];
            dest0[k + 8]       = src0[k + 8];
            dest0[k + 16]      = src1[k];
            dest0[k + 24]      = src1[k + 8];
            dest0[k + 32]      = src2[k];
            dest0[k + 40]      = src2[k + 8];
            dest0[k + 48]      = src3[k];
            dest0[k + 56]      = src3[k + 8];
        }
        src0 = src0 + 16;
        src1 = src1 + 16;
        src2 = src2 + 16;
        src3 = src3 + 16;
        ii = (row << 4);
        dest0 = dest0 + ii;
    }
    if (col & 8) {
        for (BLASLONG k = 0; k < 8; k++) {
            dest0[k]      = src0[k];
            dest0[k + 8]  = src1[k];
            dest0[k + 16] = src2[k];
            dest0[k + 24] = src3[k];
        }
        src0 = src0 + 8;
        src1 = src1 + 8;
        src2 = src2 + 8;
        src3 = src3 + 8;
        dest0 = dest0 + 32;
    }
    if (col & 4) {
        dest4[0] = src0[0]; dest4[1] = src0[1]; dest4[2] = src0[2]; dest4[3] = src0[3];
        dest4[4] = src1[0]; dest4[5] = src1[1]; dest4[6] = src1[2]; dest4[7] = src1[3];
        dest4[8] = src2[0]; dest4[9] = src2[1]; dest4[10] = src2[2]; dest4[11] = src2[3];
        dest4[12] = src3[0]; dest4[13] = src3[1]; dest4[14] = src3[2]; dest4[15] = src3[3];
        src0 = src0 + 4;
        src1 = src1 + 4;
        src2 = src2 + 4;
        src3 = src3 + 4;
        dest4 = dest4 + 16;
    }
    if (col & 2) {
        dest2[0] = src0[0]; dest2[1] = src0[1];
        dest2[2] = src1[0]; dest2[3] = src1[1];
        dest2[4] = src2[0]; dest2[5] = src2[1];
        dest2[6] = src3[0]; dest2[7] = src3[1];
        src0 = src0 + 2;
        src1 = src1 + 2;
        src2 = src2 + 2;
        src3 = src3 + 2;
        dest2 = dest2 + 8;
    }
    if (col & 1) {
        dest1[0] = src0[0];
        dest1[1] = src1[0];
        dest1[2] = src2[0];
        dest1[3] = src3[0];
        src0++;
        src1++;
        src2++;
        src3++;
        dest1 += 4;
    }
}
}
