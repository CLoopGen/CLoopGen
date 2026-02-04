#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG lda;
extern float *b;
extern BLASLONG ii;
extern float *a01;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ii = 0; ii < 16; ii++) {
        BLASLONG offset = ii * lda;
        for (BLASLONG jj = 0; jj < 16; jj++) {
            b[jj] = *(a01 + offset + jj);
        }
        b += 16;
    }
}
