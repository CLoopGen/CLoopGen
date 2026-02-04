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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ii = 0; ii < i; ii++) {
        for (BLASLONG j = 0; j < 4; j++) {
            b[j] = a01[j];
        }
        a01 += lda;
        a02 += lda;
        a03 += lda;
        a04 += lda;
        b += 4;
    }
}
