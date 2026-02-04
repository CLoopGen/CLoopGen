#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  double alpha;
extern double *X;
extern  int incX;
extern int i;
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access (assuming incX was originally non-unit)
    // We modify the access pattern to ensure X is accessed consecutively by reindexing
    int base_index = ix; // Assume ix initially points to the correct starting offset
    for (i = 0; i < N; i++) {
        X[base_index + i] *= alpha;
    }
    // Update ix to reflect final position as in original: ix += N * incX
    ix = base_index + N;
}
