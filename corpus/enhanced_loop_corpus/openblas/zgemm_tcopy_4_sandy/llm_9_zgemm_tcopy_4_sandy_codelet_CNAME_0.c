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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < row / 2; j += 1) {
    src0 = src;
    src1 = src0 + 2 * srcdim;
    src = src1 + 2 * srcdim;
    src = src + 2 * srcdim;
    dest0 = dest;
    ii = (2 << 3);
    dest = dest + ii;
    for (i = 0; i < col / 2; i += 1) {
        dest0[0] = src0[0];
        dest0[1] = src0[1];
        dest0[2] = src0[2];
        dest0[3] = src0[3];
        dest0[4] = src1[0];
        dest0[5] = src1[1];
        dest0[6] = src1[2];
        dest0[7] = src1[3];
        src0 = src0 + 4;
        src1 = src1 + 4;
        ii = (row << 2);
        dest0 = dest0 + ii;
    }
    if (col & 1) {
        dest1[0] = src0[0];
        dest1[1] = src0[1];
        dest1[2] = src1[0];
        dest1[3] = src1[1];
        src0 = src0 + 2;
        src1 = src1 + 2;
        dest1 = dest1 + 4;
    }
}
}
