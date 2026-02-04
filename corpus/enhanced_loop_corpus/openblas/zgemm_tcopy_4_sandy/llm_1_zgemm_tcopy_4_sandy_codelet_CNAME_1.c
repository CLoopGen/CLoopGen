#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG row;
extern BLASLONG col;
extern BLASLONG i;
extern BLASLONG ii;
extern float *src0;
extern float *src1;
extern float *dest0;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < col / 4; i += 1) {
    for (BLASLONG unroll_factor = 0; unroll_factor < 2; unroll_factor++) {
        BLASLONG offset = unroll_factor * 4;
        dest0[offset + 0] = src0[offset + 0];
        dest0[offset + 1] = src0[offset + 1];
        dest0[offset + 2] = src0[offset + 2];
        dest0[offset + 3] = src0[offset + 3];
        dest0[offset + 8] = src1[offset + 0];
        dest0[offset + 9] = src1[offset + 1];
        dest0[offset + 10] = src1[offset + 2];
        dest0[offset + 11] = src1[offset + 3];
    }
    src0 = src0 + 8;
    src1 = src1 + 8;
    ii = (row << 3);
    dest0 = dest0 + ii;
}
}
