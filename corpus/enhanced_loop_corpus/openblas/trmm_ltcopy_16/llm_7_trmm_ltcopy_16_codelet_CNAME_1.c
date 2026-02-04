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
float *local_b = b;
BLASLONG local_ii = 0;

for (ii = 0; ii < i; ii++) {
    *(local_b + 0)  = *(a01 + 0);
    *(local_b + 1)  = *(a01 + 1);
    *(local_b + 2)  = *(a01 + 2);
    *(local_b + 3)  = *(a01 + 3);
    *(local_b + 4)  = *(a01 + 4);
    *(local_b + 5)  = *(a01 + 5);
    *(local_b + 6)  = *(a01 + 6);
    *(local_b + 7)  = *(a01 + 7);
    *(local_b + 8)  = *(a01 + 8);
    *(local_b + 9)  = *(a01 + 9);
    *(local_b + 10) = *(a01 + 10);
    *(local_b + 11) = *(a01 + 11);
    *(local_b + 12) = *(a01 + 12);
    *(local_b + 13) = *(a01 + 13);
    *(local_b + 14) = *(a01 + 14);
    *(local_b + 15) = *(a01 + 15);

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

    local_b += 16;
    local_ii++;
}

b = local_b;
ii = local_ii;
}
