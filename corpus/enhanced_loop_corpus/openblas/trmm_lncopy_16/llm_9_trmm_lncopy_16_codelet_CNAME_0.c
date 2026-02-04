#include <stdio.h>

typedef long BLASLONG;

extern float *b;
extern BLASLONG ii;
extern float *a01;
extern float *a02;
extern float *a03;
extern float *a04;
extern float *a05;
extern float *a06;
extern float *a07;
extern float *a08;
extern float *a09;
extern float *a10;
extern float *a11;
extern float *a12;
extern float *a13;
extern float *a14;
extern float *a15;
extern float *a16;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ii = 0; ii < 8; ii++) {
    float sum1 = 0.0f, sum2 = 0.0f;
    for (BLASLONG j = 0; j < 16; j++) {
        sum1 += *(a01 + j) * *(a02 + j);
        sum2 += *(a03 + j) * *(a04 + j);
    }
    b[0] = sum1;
    b[1] = sum2;

    a01 += 16; a02 += 16; a03 += 16; a04 += 16;
    a05 += 16; a06 += 16; a07 += 16; a08 += 16;
    a09 += 16; a10 += 16; a11 += 16; a12 += 16;
    a13 += 16; a14 += 16; a15 += 16; a16 += 16;

    b += 2;
}
}
