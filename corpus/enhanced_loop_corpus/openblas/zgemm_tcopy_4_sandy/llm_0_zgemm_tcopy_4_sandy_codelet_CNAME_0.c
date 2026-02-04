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
for (j = 0; j < row / 4; j += 1) {
    src0 = src;
    src1 = src0 + 2 * srcdim;
    src2 = src1 + 2 * srcdim;
    src3 = src2 + 2 * srcdim;
    src = src3 + 2 * srcdim;
    dest0 = dest;
    ii = (4 << 3);
    dest = dest + ii;
    for (i = 0; i < col / 4; i += 1) {
        for (BLASLONG k = 0; k < 8; k++) {
            dest0[k] = src0[k];
            dest0[k + 8] = src1[k];
            dest0[k + 16] = src2[k];
            dest0[k + 24] = src3[k];
        }
        src0 = src0 + 8;
        src1 = src1 + 8;
        src2 = src2 + 8;
        src3 = src3 + 8;
        ii = (row << 3);
        dest0 = dest0 + ii;
    }
    if (col & 2) {
        for (BLASLONG k = 0; k < 4; k++) {
            dest2[k] = src0[k];
            dest2[k + 4] = src1[k];
            dest2[k + 8] = src2[k];
            dest2[k + 12] = src3[k];
        }
        src0 = src0 + 4;
        src1 = src1 + 4;
        src2 = src2 + 4;
        src3 = src3 + 4;
        dest2 = dest2 + 16;
    }
    if (col & 1) {
        dest1[0] = src0[0];
        dest1[1] = src0[1];
        dest1[2] = src1[0];
        dest1[3] = src1[1];
        dest1[4] = src2[0];
        dest1[5] = src2[1];
        dest1[6] = src3[0];
        dest1[7] = src3[1];
        src0 = src0 + 2;
        src1 = src1 + 2;
        src2 = src2 + 2;
        src3 = src3 + 2;
        dest1 = dest1 + 8;
    }
}
}
