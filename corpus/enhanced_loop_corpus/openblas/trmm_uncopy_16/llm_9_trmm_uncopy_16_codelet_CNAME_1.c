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
// Reduce effective trip count and increase arithmetic per iteration
// Introduce scaling operation to increase computational intensity
float scale1 = 1.1f, scale2 = 0.9f;

for (ii = 0; ii < i; ii++) {
    b[0]  = *(a01 + 0) * scale1 + *(a01 + 1) * scale2;
    b[1]  = *(a02 + 0) * scale1 + *(a02 + 1) * scale2;
    b[2]  = *(a03 + 0) * scale1 + *(a03 + 1) * scale2;
    b[3]  = *(a04 + 0) * scale1 + *(a04 + 1) * scale2;
    b[4]  = *(a05 + 0) * scale1 + *(a05 + 1) * scale2;
    b[5]  = *(a06 + 0) * scale1 + *(a06 + 1) * scale2;
    b[6]  = *(a07 + 0) * scale1 + *(a07 + 1) * scale2;
    b[7]  = *(a08 + 0) * scale1 + *(a08 + 1) * scale2;
    b[8]  = *(a09 + 0) * scale1 + *(a09 + 1) * scale2;
    b[9]  = *(a10 + 0) * scale1 + *(a10 + 1) * scale2;
    b[10] = *(a11 + 0) * scale1 + *(a11 + 1) * scale2;
    b[11] = *(a12 + 0) * scale1 + *(a12 + 1) * scale2;
    b[12] = *(a13 + 0) * scale1 + *(a13 + 1) * scale2;
    b[13] = *(a14 + 0) * scale1 + *(a14 + 1) * scale2;
    b[14] = *(a15 + 0) * scale1 + *(a15 + 1) * scale2;
    b[15] = *(a16 + 0) * scale1 + *(a16 + 1) * scale2;

    a01 += 2; a02 += 2; a03 += 2; a04 += 2;
    a05 += 2; a06 += 2; a07 += 2; a08 += 2;
    a09 += 2; a10 += 2; a11 += 2; a12 += 2;
    a13 += 2; a14 += 2; a15 += 2; a16 += 2;
    b += 16;
}
}
