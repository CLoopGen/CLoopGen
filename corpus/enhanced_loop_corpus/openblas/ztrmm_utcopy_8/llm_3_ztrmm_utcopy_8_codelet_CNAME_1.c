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
    b[0]  = a01[0*lda];
    b[1]  = a02[0*lda];
    b[2]  = a03[0*lda];
    b[3]  = a04[0*lda];
    b[4]  = a05[0*lda];
    b[5]  = a06[0*lda];
    b[6]  = a07[0*lda];
    b[7]  = a08[0*lda];
    b[8]  = a01[1*lda];
    b[9]  = a02[1*lda];
    b[10] = a03[1*lda];
    b[11] = a04[1*lda];
    b[12] = a05[1*lda];
    b[13] = a06[1*lda];
    b[14] = a07[1*lda];
    b[15] = a08[1*lda];
    a01 += 2 * lda;
    a02 += 2 * lda;
    a03 += 2 * lda;
    a04 += 2 * lda;
    a05 += 2 * lda;
    a06 += 2 * lda;
    a07 += 2 * lda;
    a08 += 2 * lda;
    b += 16;
}
}
