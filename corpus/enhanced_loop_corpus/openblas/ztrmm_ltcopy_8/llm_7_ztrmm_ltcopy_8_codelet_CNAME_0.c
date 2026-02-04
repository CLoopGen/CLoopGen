#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG lda;
extern float *b;
extern BLASLONG ii;
extern float *a01;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float *local_b = b;
    float *local_a01 = a01;
    BLASLONG local_lda = lda;
    for (ii = 0; ii < 8; ii++) {
        *(local_b + 0)  = *(local_a01 + 0 * local_lda);
        *(local_b + 1)  = *(local_a01 + 1 * local_lda);
        *(local_b + 2)  = *(local_a01 + 2 * local_lda);
        *(local_b + 3)  = *(local_a01 + 3 * local_lda);
        *(local_b + 4)  = *(local_a01 + 4 * local_lda);
        *(local_b + 5)  = *(local_a01 + 5 * local_lda);
        *(local_b + 6)  = *(local_a01 + 6 * local_lda);
        *(local_b + 7)  = *(local_a01 + 7 * local_lda);
        *(local_b + 8)  = *(local_a01 + 8 * local_lda);
        *(local_b + 9)  = *(local_a01 + 9 * local_lda);
        *(local_b + 10) = *(local_a01 + 10 * local_lda);
        *(local_b + 11) = *(local_a01 + 11 * local_lda);
        *(local_b + 12) = *(local_a01 + 12 * local_lda);
        *(local_b + 13) = *(local_a01 + 13 * local_lda);
        *(local_b + 14) = *(local_a01 + 14 * local_lda);
        *(local_b + 15) = *(local_a01 + 15 * local_lda);
        local_a01++;
        local_b += 16;
    }
    b = local_b;
    a01 = local_a01;
}
