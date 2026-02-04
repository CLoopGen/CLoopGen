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
    b[1] = a01[1 * lda];
    b[2] = a01[2 * lda];
    b[3] = a01[3 * lda];
    b[4] = a01[4 * lda];
    b[5] = a01[5 * lda];
    b[6] = a01[6 * lda];
    b[7] = a01[7 * lda];
    a01 += 8;
    a02 += 8;
    a03 += 8;
    a04 += 8;
    b += 8;
}
}
