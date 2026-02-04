#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG lda;
extern float *b;
extern BLASLONG i;
extern BLASLONG ii;
extern float *a01;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ii = 0; ii < i; ii++) {
    b[0] = a01[0 * lda];
    b[1] = a01[1 * lda];
    b[2] = a01[2 * lda];
    b[3] = a01[3 * lda];
    a01 += 4;
    b += 4;
}
}
