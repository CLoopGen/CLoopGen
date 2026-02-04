#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern double *C;
extern  int ldc;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by transposing the iteration order
    // Instead of row-major partial triangle, we use column-major-like access
    // to improve spatial locality in column direction
    for (j = 0; j < N; j++) {
        for (i = j; i < N; i++) {
            C[ldc * i + j] = 0.;
        }
    }
}
