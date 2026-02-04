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
        float temp0[8], temp1[8], temp2[8], temp3[8];
        for (ii = 0; ii < 8; ii++) {
            temp0[ii] = src0[ii];
            temp1[ii] = src1[ii];
            temp2[ii] = src2[ii];
            temp3[ii] = src3[ii];
        }
        for (ii = 0; ii < 8; ii++) {
            dest0[ii] = temp0[ii];
            dest0[ii + 8] = temp1[ii];
            dest0[ii + 16] = temp2[ii];
            dest0[ii + 24] = temp3[ii];
        }
        src0 = src0 + 8;
        src1 = src1 + 8;
        src2 = src2 + 8;
        src3 = src3 + 8;
        ii = (row << 3);
        dest0 = dest0 + ii;
    }
    if (col & 2) {
        float temp0[4], temp1[4], temp2[4], temp3[4];
        for (ii = 0; ii < 4; ii++) {
            temp0[ii] = src0[ii];
            temp1[ii] = src1[ii];
            temp2[ii] = src2[ii];
            temp3[ii] = src3[ii];
        }
        for (ii = 0; ii < 4; ii++) {
            dest2[ii] = temp0[ii];
            dest2[ii + 4] = temp1[ii];
            dest2[ii + 8] = temp2[ii];
            dest2[ii + 12] = temp3[ii];
        }
        src0 = src0 + 4;
        src1 = src1 + 4;
        src2 = src2 + 4;
        src3 = src3 + 4;
        dest2 = dest2 + 16;
    }
    if (col & 1) {
        float temp0[2], temp1[2], temp2[2], temp3[2];
        for (ii = 0; ii < 2; ii++) {
            temp0[ii] = src0[ii];
            temp1[ii] = src1[ii];
            temp2[ii] = src2[ii];
            temp3[ii] = src3[ii];
        }
        dest1[0] = temp0[0]; dest1[1] = temp0[1];
        dest1[2] = temp1[0]; dest1[3] = temp1[1];
        dest1[4] = temp2[0]; dest1[5] = temp2[1];
        dest1[6] = temp3[0]; dest1[7] = temp3[1];
        src0 = src0 + 2;
        src1 = src1 + 2;
        src2 = src2 + 2;
        src3 = src3 + 2;
        dest1 = dest1 + 8;
    }
}
}
