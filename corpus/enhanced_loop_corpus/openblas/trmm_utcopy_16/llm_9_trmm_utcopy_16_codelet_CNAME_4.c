#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG lda;
extern float *b;
extern BLASLONG ii;
extern float *a01;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ii = 0; ii < 2; ii++) {
    b[0] = *(a01 + 0);
    b[1] = *(a01 + 1);
    b[2] = *(a01 + 2);
    b[3] = *(a01 + 3);
    b[4] = *(a01 + lda + 0);
    b[5] = *(a01 + lda + 1);
    b[6] = *(a01 + lda + 2);
    b[7] = *(a01 + lda + 3);
    a01 += 2 * lda;
    b += 8;
}
}
