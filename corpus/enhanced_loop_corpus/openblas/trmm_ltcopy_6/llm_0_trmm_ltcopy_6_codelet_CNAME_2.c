#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG lda;
extern float *b;
extern BLASLONG ii;
extern float *ao1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ii = 0; ii < 2; ii++) {
    for (BLASLONG j = 0; j < 4; j++) {
        b[j] = *(ao1 + j);
    }
    ao1 += lda;
    b += 4;
}
}
