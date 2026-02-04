#include <stdio.h>

typedef long BLASLONG;

extern BLASLONG lda;
extern float *b;
extern BLASLONG ii;
extern float *ao1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ii = 0; ii < 2; ii++) {
    // Variant 1: Consecutive memory access with array indexing and pointer arithmetic fused
    float *src = ao1;
    b[0] = src[0];
    b[1] = src[1];
    b[2] = src[2];
    b[3] = src[3];
    ao1 += lda;
    b += 4;
}
}
