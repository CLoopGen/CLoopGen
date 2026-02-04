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
    b[0] = *(a01 + 0);
    b[1] = *(a01 + 1);
    b[2] = *(a02 + 0);
    b[3] = *(a02 + 1);
    b[4] = *(a03 + 0);
    b[5] = *(a03 + 1);
    b[6] = *(a04 + 0);
    b[7] = *(a04 + 1);
    b[8] = *(a05 + 0);
    b[9] = *(a05 + 1);
    b[10] = *(a06 + 0);
    b[11] = *(a06 + 1);
    b[12] = *(a07 + 0);
    b[13] = *(a07 + 1);
    b[14] = *(a08 + 0);
    b[15] = *(a08 + 1);
    a01 += 2;
    a02 += 2;
    a03 += 2;
    a04 += 2;
    a05 += 2;
    a06 += 2;
    a07 += 2;
    a08 += 2;
    b += 16;

    // Unrolled second half of original loop in same iteration
    b[0] = *(a09 + 0);
    b[1] = *(a09 + 1);
    b[2] = *(a10 + 0);
    b[3] = *(a10 + 1);
    b[4] = *(a11 + 0);
    b[5] = *(a11 + 1);
    b[6] = *(a12 + 0);
    b[7] = *(a12 + 1);
    b[8] = *(a13 + 0);
    b[9] = *(a13 + 1);
    b[10] = *(a14 + 0);
    b[11] = *(a14 + 1);
    b[12] = *(a15 + 0);
    b[13] = *(a15 + 1);
    b[14] = *(a16 + 0);
    b[15] = *(a16 + 1);
    a09 += 2;
    a10 += 2;
    a11 += 2;
    a12 += 2;
    a13 += 2;
    a14 += 2;
    a15 += 2;
    a16 += 2;
    b += 16;
}
}
