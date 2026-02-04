#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG lda;
extern float *b;
extern BLASLONG ii;
extern float *ao1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
float *b_local = b;
for (ii = 0; ii < 6; ii++) {
    b_local[0] = *(ao1 + 0);
    b_local[1] = *(ao1 + 1);
    b_local[2] = *(ao1 + 2);
    b_local[3] = *(ao1 + 3);
    b_local[4] = *(ao1 + 4);
    b_local[5] = *(ao1 + 5);

    ao1 += lda;
    b_local += 6;
}
b += 36; 
}
