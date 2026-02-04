#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG lda;
extern float *b;
extern BLASLONG ii;
extern float *a01;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ii = 0; ii < 16; ii++) {
        for (BLASLONG j = 0; j < 32; j++) {
            b[j] = *(a01 + j);
        }
        a01 += lda;
        b += 32;
    }
}
