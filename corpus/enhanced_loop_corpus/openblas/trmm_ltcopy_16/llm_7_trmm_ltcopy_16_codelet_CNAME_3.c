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
    float *a1, *a2, *a3, *a4, *a5, *a6, *a7, *a8;
    for (ii = 0; ii < i; ii++) {
        a1 = a01 + ii * lda;
        a2 = a02 + ii * lda;
        a3 = a03 + ii * lda;
        a4 = a04 + ii * lda;
        a5 = a05 + ii * lda;
        a6 = a06 + ii * lda;
        a7 = a07 + ii * lda;
        a8 = a08 + ii * lda;

        b[0] = a1[0]; b[1] = a1[1];
        b[2] = a2[0]; b[3] = a2[1];
        b[4] = a3[0]; b[5] = a3[1];
        b[6] = a4[0]; b[7] = a4[1];

        b += 8;
        a01 += lda; a02 += lda; a03 += lda; a04 += lda;
        a05 += lda; a06 += lda; a07 += lda; a08 += lda;
    }
}
