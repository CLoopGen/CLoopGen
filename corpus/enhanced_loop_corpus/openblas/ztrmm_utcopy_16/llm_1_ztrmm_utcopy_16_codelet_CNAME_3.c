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
        for (BLASLONG k = 0; k < 4; k++) {
            for (BLASLONG j = 0; j < 4; j++) {
                b[k * 4 + j] = a01[k * 4 + j];
            }
        }
        a01 += lda;
        a02 += lda;
        a03 += lda;
        a04 += lda;
        a05 += lda;
        a06 += lda;
        a07 += lda;
        a08 += lda;
        b += 16;
    }
}
