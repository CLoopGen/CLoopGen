#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG lda;
extern float *b;
extern BLASLONG ii;
extern float *ao1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ii = 0; ii < 1; ii++) {
    b[0] = *(ao1 + 0) + *(ao1 + 1);
    b[1] = *(ao1 + 2) - *(ao1 + 3);
    b[2] = *(ao1 + 4) * *(ao1 + 5);
    b[3] = *(ao1 + 6) / ( *(ao1 + 7) != 0.0f ? *(ao1 + 7) : 1.0f );
    ao1 += lda;
    b += 4;
}
}
