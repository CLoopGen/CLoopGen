#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG lda;
extern float *b;
extern BLASLONG ii;
extern float *ao1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ii = 0; ii < 3; ii++) {
    b[0] = *(ao1 + 0) + *(ao1 + 6);
    b[1] = *(ao1 + 1) + *(ao1 + 7);
    b[2] = *(ao1 + 2) + *(ao1 + 8);
    b[3] = *(ao1 + 3) + *(ao1 + 9);
    b[4] = *(ao1 + 4) + *(ao1 + 10);
    b[5] = *(ao1 + 5) + *(ao1 + 11);
    ao1 += lda;
    b += 6;
}
}
