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
    // Variant 1: Change memory access pattern to strided access by unrolling and accessing every second element
    // First handle even indices, then odd indices to create a strided access pattern
    int ii, jj;
    for (ii = 0; ii < N; ii++) {
        for (jj = 0; jj <= ii; jj += 2) {
            C[ldc * ii + jj] *= beta;
        }
        for (jj = 1; jj <= ii; jj += 2) {
            C[ldc * ii + jj] *= beta;
        }
    }
}
