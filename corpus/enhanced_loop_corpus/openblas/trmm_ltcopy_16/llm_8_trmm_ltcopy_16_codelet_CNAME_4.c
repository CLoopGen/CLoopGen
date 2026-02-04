#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG lda;
extern float *b;
extern BLASLONG ii;
extern float *a01;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
BLASLONG jj;
for (ii = 0; ii < 8; ii++) {
    for (jj = 0; jj < 4; jj++) {
        b[jj] = *(a01 + jj) + 1.0f;
    }
    a01 += lda;
    b += 4;
}
}
