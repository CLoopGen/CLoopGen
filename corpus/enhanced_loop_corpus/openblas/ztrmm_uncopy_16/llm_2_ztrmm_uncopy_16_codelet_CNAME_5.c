#include <stdio.h>

typedef long BLASLONG;

extern float *b;
extern BLASLONG i;
extern BLASLONG ii;
extern float *a01;
extern float *a02;
extern float *a03;
extern float *a04;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ii = 0; ii < i; ii++) {
    float *src1 = a01 + ii * 2;
    float *src2 = a02 + ii * 2;
    float *src3 = a03 + ii * 2;
    float *src4 = a04 + ii * 2;
    float *dst = b + ii * 8;
    dst[0] = src1[0];
    dst[1] = src1[1];
    dst[2] = src2[0];
    dst[3] = src2[1];
    dst[4] = src3[0];
    dst[5] = src3[1];
    dst[6] = src4[0];
    dst[7] = src4[1];
}
}
