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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ii = 0; ii < i; ii++) {
    if (ii >= i / 2) {
        b[0] = *(a08 + 0);
        b[1] = *(a08 + 1);
        b[2] = *(a08 + 2);
        b[3] = *(a08 + 3);
        b[4] = *(a08 + 4);
        b[5] = *(a08 + 5);
        b[6] = *(a08 + 6);
        b[7] = *(a08 + 7);
        a08 += lda;
    } else {
        b[0] = *(a01 + 0);
        b[1] = *(a01 + 1);
        b[2] = *(a01 + 2);
        b[3] = *(a01 + 3);
        b[4] = *(a01 + 4);
        b[5] = *(a01 + 5);
        b[6] = *(a01 + 6);
        b[7] = *(a01 + 7);
        a01 += lda;
    }
    a02 += lda;
    a03 += lda;
    a04 += lda;
    a05 += lda;
    a06 += lda;
    a07 += lda;
    b += 8;
}
}
