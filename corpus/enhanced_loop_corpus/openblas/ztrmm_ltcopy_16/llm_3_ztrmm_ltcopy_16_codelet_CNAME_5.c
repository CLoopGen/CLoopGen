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
    b[0] = a01[0 * lda];
    b[1] = a02[0 * lda];
    b[2] = a03[0 * lda];
    b[3] = a04[0 * lda];
    b[4] = a01[1 * lda];
    b[5] = a02[1 * lda];
    b[6] = a03[1 * lda];
    b[7] = a04[1 * lda];
    a01 += 2 * lda;
    a02 += 2 * lda;
    a03 += 2 * lda;
    a04 += 2 * lda;
    b += 8;
}
}
