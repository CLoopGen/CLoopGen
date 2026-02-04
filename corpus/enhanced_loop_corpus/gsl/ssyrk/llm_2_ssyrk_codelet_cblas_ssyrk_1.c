#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern float *C;
extern  int ldc;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by transposing the iteration order
    // We traverse column-major but rewrite to access C in a more sequential pattern when possible.
    // Since original accesses lower triangular part, we reverse j-loop and use pointer arithmetic for stride-1 access.

    float *base;
    int i, j;
    for (j = 0; j < N; j++) {
        base = &C[ldc * j + j];  // Start at diagonal element (j,j)
        for (i = j; i < N; i++) {
            *base = 0.0f;
            base += ldc;  // Move down the column: strided access with stride `ldc`
        }
    }
}
