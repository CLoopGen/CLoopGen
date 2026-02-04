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
        for (BLASLONG j = 0; j < 16; j++) {
            b[j] = *(a01 + j);
        }
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
