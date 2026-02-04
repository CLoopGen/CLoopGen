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
for (j = 0; j < col / 2; j += 1) {
    src0 = src;
    src1 = src0 + 2 * srcdim;
    src2 = src1 + 2 * srcdim;
    src3 = src2 + 2 * srcdim;
    src = src3 + 2 * srcdim;
    dest0 = dest;
    ii = (row << 2); // Reduced stride due to lower unrolling
    dest = dest + ii;
    for (i = 0; i < row / 2; i += 1) {
        dest0[0] = src0[0];
        dest0[1] = src0[1];
        dest0[2] = src1[0];
        dest0[3] = src1[1];
        dest0[4] = src2[0];
        dest0[5] = src2[1];
        dest0[6] = src3[0];
        dest0[7] = src3[1];
        src0 = src0 + 2;
        src1 = src1 + 2;
        src2 = src2 + 2;
        src3 = src3 + 2;
        ii = (1 << 2);
        dest0 = dest0 + ii;
    }
    if (row & 1) {
        dest0[0] = src0[0];
        dest0[1] = src1[0];
        dest0[2] = src2[0];
        dest0[3] = src3[0];
        ii = (1 << 2);
        dest0 = dest0 + ii;
    }
}
}
