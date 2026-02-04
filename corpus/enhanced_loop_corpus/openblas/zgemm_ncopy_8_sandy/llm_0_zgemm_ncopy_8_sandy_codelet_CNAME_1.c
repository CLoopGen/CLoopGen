#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG row;
extern BLASLONG i;
extern BLASLONG ii;
extern float *src0;
extern float *src1;
extern float *src2;
extern float *src3;
extern float *dest0;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < row / 4; i += 1) {
    for (BLASLONG j = 0; j < 4; j++) {
        dest0[8*j + 0] = src0[2*j + 0];
        dest0[8*j + 1] = src0[2*j + 1];
        dest0[8*j + 2] = src1[2*j + 0];
        dest0[8*j + 3] = src1[2*j + 1];
        dest0[8*j + 4] = src2[2*j + 0];
        dest0[8*j + 5] = src2[2*j + 1];
        dest0[8*j + 6] = src3[2*j + 0];
        dest0[8*j + 7] = src3[2*j + 1];
    }
    src0 = src0 + 8;
    src1 = src1 + 8;
    src2 = src2 + 8;
    src3 = src3 + 8;
    ii = (4 << 3);
    dest0 = dest0 + ii;
}
}
