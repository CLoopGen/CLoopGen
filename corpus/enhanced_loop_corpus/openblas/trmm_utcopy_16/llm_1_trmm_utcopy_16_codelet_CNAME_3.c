#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG lda;
extern float *b;
extern BLASLONG i;
extern BLASLONG ii;
extern float *a01;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (i > 0) {
        for (ii = 0; ii < i; ii++) {
            for (BLASLONG k = 0; k < 2; k++) {
                for (BLASLONG j = 0; j < 4; j++) {
                    b[j + k*4] = *(a01 + j + k*4);
                }
            }
            a01 += lda;
            b += 8;
        }
    }
}
