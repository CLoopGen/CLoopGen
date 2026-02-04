#include <stdio.h>

typedef long BLASLONG;

extern float *b;
extern BLASLONG ii;
extern float *a01;
extern float *a02;
extern float *a03;
extern float *a04;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ii = 0; ii < 2; ii++) {
    float sum1 = *(a01 + 0) + *(a01 + 1);
    float sum2 = *(a02 + 0) + *(a02 + 1);
    float sum3 = *(a03 + 0) + *(a03 + 1);
    float sum4 = *(a04 + 0) + *(a04 + 1);
    b[0] = sum1 * sum2;
    b[1] = sum3 * sum4;
    b[2] = sum1 + sum3;
    b[3] = sum2 + sum4;
    a01 += 4;
    a02 += 4;
    a03 += 4;
    a04 += 4;
    b += 4;
}
}
