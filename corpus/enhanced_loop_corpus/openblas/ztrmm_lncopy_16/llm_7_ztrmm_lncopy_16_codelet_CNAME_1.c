#include <stdio.h>

typedef long BLASLONG;

extern float *b;
extern BLASLONG i;
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
for (ii = 0; ii < i / 4; ii++) {
    for (BLASLONG j = 0; j < 8; j++) {
        b[j*4+0] = *(a01 + 0);
        b[j*4+1] = *(a01 + 1);
        b[j*4+2] = *(a02 + 0);
        b[j*4+3] = *(a02 + 1);
        a01 += 2;
        a02 += 2;

        b[j*4+0] *= 1.0f;
        b[j*4+1] *= 1.0f;
        b[j*4+2] *= 1.0f;
        b[j*4+3] *= 1.0f;

        a03 += 2;
        a04 += 2;
        a05 += 2;
        a06 += 2;
        a07 += 2;
        a08 += 2;
        a09 += 2;
        a10 += 2;
        a11 += 2;
        a12 += 2;
        a13 += 2;
        a14 += 2;
        a15 += 2;
        a16 += 2;
        b += 4;
    }
}
}
