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
    // Variant 1: Consecutive memory access by transposing the loop order
    // Instead of accessing C[ldc*i + j] which may skip elements due to ldc stride,
    // we reorganize to access consecutive blocks when possible, assuming ldc is large.
    // We still maintain the same logical iteration space (i <= j) but access column-major style.

    for (j = 0; j < N; j++) {
        for (i = 0; i <= j; i++) {
            C[ldc * i + j] *= beta;
        }
    }
}
