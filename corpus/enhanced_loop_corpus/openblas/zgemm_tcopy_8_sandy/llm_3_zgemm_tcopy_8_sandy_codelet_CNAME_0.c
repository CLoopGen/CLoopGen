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
        BLASLONG offset = 0;
        for (BLASLONG vec = 0; vec < 16; vec++) {
            dest0[offset++] = *(src0++);
            dest0[offset++] = *(src1++);
            dest0[offset++] = *(src2++);
            dest0[offset++] = *(src3++);
        }
        src0 += 0; // No change needed — already incremented
        src1 += 0;
        src2 += 0;
        src3 += 0;
        ii = (row << 4);
        dest0 += ii;
    }
    if (col & 4) {
        BLASLONG offset4 = 0;
        for (BLASLONG vec = 0; vec < 8; vec++) {
            dest4[offset4++] = *(src0++);
            dest4[offset4++] = *(src1++);
            dest4[offset4++] = *(src2++);
            dest4[offset4++] = *(src3++);
        }
        dest4 += 32;
    }
    if (col & 2) {
        BLASLONG offset2 = 0;
        for (BLASLONG vec = 0; vec < 4; vec++) {
            dest2[offset2++] = *(src0++);
            dest2[offset2++] = *(src1++);
            dest2[offset2++] = *(src2++);
            dest2[offset2++] = *(src3++);
        }
        dest2 += 16;
    }
    if (col & 1) {
        BLASLONG offset1 = 0;
        for (BLASLONG vec = 0; vec < 2; vec++) {
            dest1[offset1++] = *(src0++);
            dest1[offset1++] = *(src1++);
            dest1[offset1++] = *(src2++);
            dest1[offset1++] = *(src3++);
        }
        dest1 += 8;
    }
}
}
