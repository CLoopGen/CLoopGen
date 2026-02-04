#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG lda;
extern float *b;
extern BLASLONG ii;
extern float *ao1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    BLASLONG jj, kk;
    for (ii = 0; ii < 2; ii++) {
        for (jj = 0; jj < 3; jj++) {
            for (kk = 0; kk < 6; kk++) {
                b[kk] = *(ao1 + kk);
            }
            ao1 += lda;
            b += 6;
        }
    }
}
