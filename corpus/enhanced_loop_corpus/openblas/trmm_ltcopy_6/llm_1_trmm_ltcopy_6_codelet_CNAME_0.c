#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG lda;
extern float *b;
extern BLASLONG ii;
extern float *ao1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ii = 0; ii < 3; ii++) {
    for (BLASLONG k = 0; k < 2; k++) {
        b[0] = *(ao1 + 0);
        b[1] = *(ao1 + 1);
        b[2] = *(ao1 + 2);
        b[3] = *(ao1 + 3);
        b[4] = *(ao1 + 4);
        b[5] = *(ao1 + 5);
        ao1 += lda;
        b += 6;
    }
}
}
