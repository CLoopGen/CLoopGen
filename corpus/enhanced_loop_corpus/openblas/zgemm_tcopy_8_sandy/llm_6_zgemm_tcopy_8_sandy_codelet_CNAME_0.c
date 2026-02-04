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
for (j = 0; j < row / 4; j += 1) {
    src0 = src;
    src1 = src0 + 2 * srcdim;
    src2 = src1 + 2 * srcdim;
    src3 = src2 + 2 * srcdim;
    src = src3 + 2 * srcdim;
    dest0 = dest;
    ii = (4 << 4);
    dest = dest + ii;
    for (i = 0; i < col / 8; i += 1) {
        float temp0[16], temp1[16], temp2[16], temp3[16];
        for (int k = 0; k < 16; k++) {
            temp0[k] = src0[k];
            temp1[k] = src1[k];
            temp2[k] = src2[k];
            temp3[k] = src3[k];
        }
        for (int k = 0; k < 16; k++) {
            dest0[k]       = temp0[k];
            dest0[k + 16]  = temp1[k];
            dest0[k + 32]  = temp2[k];
            dest0[k + 48]  = temp3[k];
        }
        src0 += 16;
        src1 += 16;
        src2 += 16;
        src3 += 16;
        ii = (row << 4);
        dest0 = dest0 + ii;
    }
    if (col & 4) {
        float temp0[8], temp1[8], temp2[8], temp3[8];
        for (int k = 0; k < 8; k++) {
            temp0[k] = src0[k];
            temp1[k] = src1[k];
            temp2[k] = src2[k];
            temp3[k] = src3[k];
        }
        for (int k = 0; k < 8; k++) {
            dest4[k]      = temp0[k];
            dest4[k + 8]  = temp1[k];
            dest4[k + 16] = temp2[k];
            dest4[k + 24] = temp3[k];
        }
        src0 += 8;
        src1 += 8;
        src2 += 8;
        src3 += 8;
        dest4 += 32;
    }
    if (col & 2) {
        float temp0[4], temp1[4], temp2[4], temp3[4];
        for (int k = 0; k < 4; k++) {
            temp0[k] = src0[k];
            temp1[k] = src1[k];
            temp2[k] = src2[k];
            temp3[k] = src3[k];
        }
        for (int k = 0; k < 4; k++) {
            dest2[k]      = temp0[k];
            dest2[k + 4]  = temp1[k];
            dest2[k + 8]  = temp2[k];
            dest2[k + 12] = temp3[k];
        }
        src0 += 4;
        src1 += 4;
        src2 += 4;
        src3 += 4;
        dest2 += 16;
    }
    if (col & 1) {
        float temp0[2], temp1[2], temp2[2], temp3[2];
        for (int k = 0; k < 2; k++) {
            temp0[k] = src0[k];
            temp1[k] = src1[k];
            temp2[k] = src2[k];
            temp3[k] = src3[k];
        }
        for (int k = 0; k < 2; k++) {
            dest1[k]      = temp0[k];
            dest1[k + 2]  = temp1[k];
            dest1[k + 4]  = temp2[k];
            dest1[k + 6]  = temp3[k];
        }
        src0 += 2;
        src1 += 2;
        src2 += 2;
        src3 += 2;
        dest1 += 8;
    }
}
}
