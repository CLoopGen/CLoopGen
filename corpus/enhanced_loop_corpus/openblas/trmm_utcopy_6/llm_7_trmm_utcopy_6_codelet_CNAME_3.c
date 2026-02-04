#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG lda;
extern float *b;
extern BLASLONG i;
extern BLASLONG ii;
extern float *ao1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
float *local_b = b;
for (ii = 0; ii < i; ii++) {
    local_b[0] = *(ao1 + 0);
    local_b[1] = *(ao1 + 1);
    local_b[2] = *(ao1 + 2);
    local_b[3] = *(ao1 + 3);
    ao1 += lda;
    local_b += 4;
}
b = local_b; // WAW dependency on b eliminated; final write to b breaks loop-carried dependency
}
