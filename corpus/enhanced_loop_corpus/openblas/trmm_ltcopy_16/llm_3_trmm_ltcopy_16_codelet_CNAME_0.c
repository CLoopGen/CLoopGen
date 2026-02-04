#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG lda;
extern float *b;
extern BLASLONG ii;
extern float *a01;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
BLASLONG index = 0;
for (ii = 0; ii < 16; ii++) {
    // Consecutive write to b, but gather elements from a01 with increasing stride
    b[0]  = a01[0 * lda];
    b[1]  = a01[1 * lda];
    b[2]  = a01[2 * lda];
    b[3]  = a01[3 * lda];
    b[4]  = a01[4 * lda];
    b[5]  = a01[5 * lda];
    b[6]  = a01[6 * lda];
    b[7]  = a01[7 * lda];
    b[8]  = a01[8 * lda];
    b[9]  = a01[9 * lda];
    b[10] = a01[10 * lda];
    b[11] = a01[11 * lda];
    b[12] = a01[12 * lda];
    b[13] = a01[13 * lda];
    b[14] = a01[14 * lda];
    b[15] = a01[15 * lda];
    a01 += 1;
    b += 16;
}
}
