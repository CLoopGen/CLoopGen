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
float *b_local = b;
const BLASLONG stride = lda;
for (ii = 0; ii < i; ii++) {
    *(b_local + 0) = a01[0];
    *(b_local + 1) = a02[0];
    *(b_local + 2) = a03[0];
    *(b_local + 3) = a04[0];
    *(b_local + 4) = a01[1];
    *(b_local + 5) = a02[1];
    *(b_local + 6) = a03[1];
    *(b_local + 7) = a04[1];
    a01 += stride;
    a02 += stride;
    a03 += stride;
    a04 += stride;
    b_local += 8;
}
}
