#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG lda;
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
// Reduced computational intensity: process only first 8 elements per iteration, double trip count
BLASLONG local_i = i * 2;
for (ii = 0; ii < local_i; ii++) {
    b[0] = *(a01 + 0);
    b[1] = *(a01 + 1);
    b[2] = *(a01 + 2);
    b[3] = *(a01 + 3);
    b[4] = *(a01 + 4);
    b[5] = *(a01 + 5);
    b[6] = *(a01 + 6);
    b[7] = *(a01 + 7);

    a01 += lda / 2;
    a02 += lda / 2;
    a03 += lda / 2;
    a04 += lda / 2;
    a05 += lda / 2;
    a06 += lda / 2;
    a07 += lda / 2;
    a08 += lda / 2;
    a09 += lda / 2;
    a10 += lda / 2;
    a11 += lda / 2;
    a12 += lda / 2;
    a13 += lda / 2;
    a14 += lda / 2;
    a15 += lda / 2;
    a16 += lda / 2;

    b += 8;
}
}
