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

    BLASLONG unroll_factor_i = col / 8;
    BLASLONG remainder_cols = col & 7;
    BLASLONG vector_steps = unroll_factor_i;

    for (i = 0; i < vector_steps; i++) {
        for (BLASLONG inner = 0; inner < 16; inner++) {
            BLASLONG offset = inner * 4;
            dest0[offset + 0] = src0[inner];
            dest0[offset + 1] = src1[inner];
            dest0[offset + 2] = src2[inner];
            dest0[offset + 3] = src3[inner];
        }
        src0 += 16;
        src1 += 16;
        src2 += 16;
        src3 += 16;
        ii = (row << 4);
        dest0 += ii;
    }

    if (remainder_cols >= 4) {
        for (BLASLONG inner = 0; inner < 8; inner++) {
            BLASLONG offset = inner * 4;
            dest4[offset + 0] = src0[inner];
            dest4[offset + 1] = src1[inner];
            dest4[offset + 2] = src2[inner];
            dest4[offset + 3] = src3[inner];
        }
        src0 += 8;
        src1 += 8;
        src2 += 8;
        src3 += 8;
        dest4 += 32;
        remainder_cols -= 4;
    }
    if (remainder_cols >= 2) {
        for (BLASLONG inner = 0; inner < 4; inner++) {
            BLASLONG offset = inner * 4;
            dest2[offset + 0] = src0[inner];
            dest2[offset + 1] = src1[inner];
            dest2[offset + 2] = src2[inner];
            dest2[offset + 3] = src3[inner];
        }
        src0 += 4;
        src1 += 4;
        src2 += 4;
        src3 += 4;
        dest2 += 16;
        remainder_cols -= 2;
    }
    if (remainder_cols >= 1) {
        for (BLASLONG inner = 0; inner < 2; inner++) {
            BLASLONG offset = inner * 4;
            dest1[offset + 0] = src0[inner];
            dest1[offset + 1] = src1[inner];
            dest1[offset + 2] = src2[inner];
            dest1[offset + 3] = src3[inner];
        }
        src0 += 2;
        src1 += 2;
        src2 += 2;
        src3 += 2;
        dest1 += 8;
    }
}
}
