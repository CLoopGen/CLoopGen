#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  float beta;
extern float *C;
extern  int ldc;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by transposing the iteration order
    // We now iterate column-major within the lower triangular part to achieve consecutive access in C
    for (j = 0; j < N; j++) {
        for (i = j; i < N; i++) {
            C[ldc * i + j] *= beta;
        }
    }
}
