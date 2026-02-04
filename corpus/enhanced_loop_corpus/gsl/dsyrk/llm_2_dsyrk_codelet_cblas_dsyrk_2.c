#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  double beta;
extern double *C;
extern  int ldc;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing C[ldc * i + j] in row-major order, we modify the access pattern
    // to stride through memory with a fixed increment across rows for improved cache behavior
    // under certain conditions. Here, we reverse the inner loop to traverse from N-1 down to i,
    // creating a backward strided access.

    for (i = 0; i < N; i++) {
        for (j = N - 1; j >= i; j--) {
            C[ldc * i + j] *= beta;
        }
    }
}
