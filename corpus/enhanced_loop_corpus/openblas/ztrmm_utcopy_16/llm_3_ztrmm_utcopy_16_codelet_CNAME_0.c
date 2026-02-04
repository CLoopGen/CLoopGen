#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG lda;
extern float *b;
extern BLASLONG ii;
extern float *a01;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ii = 0; ii < 16; ii++) {
    b[ 0] = *(a01 + 0*lda);
    b[ 1] = *(a01 + 1*lda);
    b[ 2] = *(a01 + 2*lda);
    b[ 3] = *(a01 + 3*lda);
    b[ 4] = *(a01 + 4*lda);
    b[ 5] = *(a01 + 5*lda);
    b[ 6] = *(a01 + 6*lda);
    b[ 7] = *(a01 + 7*lda);
    b[ 8] = *(a01 + 8*lda);
    b[ 9] = *(a01 + 9*lda);
    b[10] = *(a01 + 10*lda);
    b[11] = *(a01 + 11*lda);
    b[12] = *(a01 + 12*lda);
    b[13] = *(a01 + 13*lda);
    b[14] = *(a01 + 14*lda);
    b[15] = *(a01 + 15*lda);
    b[16] = *(a01 + 16*lda);
    b[17] = *(a01 + 17*lda);
    b[18] = *(a01 + 18*lda);
    b[19] = *(a01 + 19*lda);
    b[20] = *(a01 + 20*lda);
    b[21] = *(a01 + 21*lda);
    b[22] = *(a01 + 22*lda);
    b[23] = *(a01 + 23*lda);
    b[24] = *(a01 + 24*lda);
    b[25] = *(a01 + 25*lda);
    b[26] = *(a01 + 26*lda);
    b[27] = *(a01 + 27*lda);
    b[28] = *(a01 + 28*lda);
    b[29] = *(a01 + 29*lda);
    b[30] = *(a01 + 30*lda);
    b[31] = *(a01 + 31*lda);
    a01 += 1;
    b += 32;
}
}
