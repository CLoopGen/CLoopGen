#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG lda;
extern float *b;
extern BLASLONG ii;
extern float *ao1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float *local_b = b;
    const BLASLONG local_lda = lda;
    for (ii = 0; ii < 2; ii++) {
        *(local_b + 0) = *(ao1 + 0);
        *(local_b + 1) = *(ao1 + 1);
        *(local_b + 2) = *(ao1 + 2);
        *(local_b + 3) = *(ao1 + 3);

        ao1 += local_lda;
        local_b += 4;
    }
    b = local_b;
}
