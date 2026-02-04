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
for (ii = 0; ii < i; ii++) {
    b[ 0] = a01[0 * lda];
    b[ 1] = a02[0 * lda];
    b[ 2] = a03[0 * lda];
    b[ 3] = a04[0 * lda];
    b[ 4] = a05[0 * lda];
    b[ 5] = a06[0 * lda];
    b[ 6] = a07[0 * lda];
    b[ 7] = a08[0 * lda];
    b[ 8] = a09[0 * lda];
    b[ 9] = a10[0 * lda];
    b[10] = a11[0 * lda];
    b[11] = a12[0 * lda];
    b[12] = a13[0 * lda];
    b[13] = a14[0 * lda];
    b[14] = a15[0 * lda];
    b[15] = a16[0 * lda];
    a01 += lda;
    a02 += lda;
    a03 += lda;
    a04 += lda;
    a05 += lda;
    a06 += lda;
    a07 += lda;
    a08 += lda;
    a09 += lda;
    a10 += lda;
    a11 += lda;
    a12 += lda;
    a13 += lda;
    a14 += lda;
    a15 += lda;
    a16 += lda;
    b += 16;
}
}
