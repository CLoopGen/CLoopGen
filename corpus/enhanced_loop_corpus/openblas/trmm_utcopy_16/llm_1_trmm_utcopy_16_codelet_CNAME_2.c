#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG lda;
extern float *b;
extern BLASLONG ii;
extern float *a01;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ii = 0; ii < 64; ii++) {
    b[0] = *(a01 + 0);
    a01 += 1;
    b += 1;
}
}
