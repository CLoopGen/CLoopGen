#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG lda;
extern float *b;
extern BLASLONG ii;
extern float *a01;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
float *b_orig = b;
for (ii = 0; ii < 4; ii++) {
    b_orig[0] = *(a01 + 0);
    b_orig[1] = *(a01 + 1);
    b_orig[2] = *(a01 + 2);
    b_orig[3] = *(a01 + 3);
    a01 += lda;
    b_orig += 4;
}
}
