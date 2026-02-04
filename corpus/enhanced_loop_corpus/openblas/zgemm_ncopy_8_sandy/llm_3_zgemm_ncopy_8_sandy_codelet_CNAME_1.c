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
BLASLONG stride = 2;
for (i = 0; i < row / 4; i += 1) {
    BLASLONG offset = i * 16;
    for (BLASLONG j = 0; j < 8; j++) {
        dest0[offset + j * stride + 0] = src0[j];
        dest0[offset + j * stride + 1] = src1[j];
        dest0[offset + j * stride + 16] = src2[j];
        dest0[offset + j * stride + 17] = src3[j];
    }
    src0 += 8;
    src1 += 8;
    src2 += 8;
    src3 += 8;
}
}
