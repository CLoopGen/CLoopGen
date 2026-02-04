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
        for (BLASLONG k = 0; k < 4; k++) {
            BLASLONG offset = k * 2;
            dest0[0 + k*16] = src0[offset];
            dest0[1 + k*16] = src0[offset+1];
            dest0[2 + k*16] = src1[offset];
            dest0[3 + k*16] = src1[offset+1];
            dest0[4 + k*16] = src2[offset];
            dest0[5 + k*16] = src2[offset+1];
            dest0[6 + k*16] = src3[offset];
            dest0[7 + k*16] = src3[offset+1];
            dest0[8 + k*16] = src4[offset];
            dest0[9 + k*16] = src4[offset+1];
            dest0[10 + k*16] = src5[offset];
            dest0[11 + k*16] = src5[offset+1];
            dest0[12 + k*16] = src6[offset];
            dest0[13 + k*16] = src6[offset+1];
            dest0[14 + k*16] = src7[offset];
            dest0[15 + k*16] = src7[offset+1];
        }
        src0 += 8;
        src1 += 8;
        src2 += 8;
        src3 += 8;
        src4 += 8;
        src5 += 8;
        src6 += 8;
        src7 += 8;
        dest0 += 64;
    }
    if (row & 2) {
        for (BLASLONG k = 0; k < 2; k++) {
            BLASLONG offset = k * 2;
            dest0[0 + k*16] = src0[offset];
            dest0[1 + k*16] = src0[offset+1];
            dest0[2 + k*16] = src1[offset];
            dest0[3 + k*16] = src1[offset+1];
            dest0[4 + k*16] = src2[offset];
            dest0[5 + k*16] = src2[offset+1];
            dest0[6 + k*16] = src3[offset];
            dest0[7 + k*16] = src3[offset+1];
            dest0[8 + k*16] = src4[offset];
            dest0[9 + k*16] = src4[offset+1];
            dest0[10 + k*16] = src5[offset];
            dest0[11 + k*16] = src5[offset+1];
            dest0[12 + k*16] = src6[offset];
            dest0[13 + k*16] = src6[offset+1];
            dest0[14 + k*16] = src7[offset];
            dest0[15 + k*16] = src7[offset+1];
        }
        src0 += 4;
        src1 += 4;
        src2 += 4;
        src3 += 4;
        src4 += 4;
        src5 += 4;
        src6 += 4;
        src7 += 4;
        dest0 += 32;
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
        src0 += 2;
        src1 += 2;
        src2 += 2;
        src3 += 2;
        src4 += 2;
        src5 += 2;
        src6 += 2;
        src7 += 2;
        dest0 += 16;
    }
}
}
