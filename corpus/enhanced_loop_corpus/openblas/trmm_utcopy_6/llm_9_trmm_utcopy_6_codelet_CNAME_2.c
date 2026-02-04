#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG lda;
extern float *b;
extern BLASLONG ii;
extern float *ao1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ii = 0; ii < 1; ii++) {
    b[0] = *(ao1 + 0) + *(ao1 + 4) + *(ao1 + 8) + *(ao1 + 12);
    b[1] = *(ao1 + 1) + *(ao1 + 5) + *(ao1 + 9) + *(ao1 + 13);
    b[2] = *(ao1 + 2) + *(ao1 + 6) + *(ao1 + 10) + *(ao1 + 14);
    b[3] = *(ao1 + 3) + *(ao1 + 7) + *(ao1 + 11) + *(ao1 + 15);
    b += 4;
}
}
