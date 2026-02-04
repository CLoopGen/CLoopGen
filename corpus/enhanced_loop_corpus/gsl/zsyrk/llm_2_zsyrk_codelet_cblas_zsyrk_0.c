#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern void *C;
extern  int ldc;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by flattening the 2D index into a linear traversal
    // We calculate the starting offset for each row and write two doubles consecutively
    int base_idx;
    double *c_ptr = (double *)C;
    for (i = 0; i < N; i++) {
        for (j = i; j < N; j++) {
            base_idx = 2 * (ldc * i + j);  // Linearized index in the flattened array
            c_ptr[base_idx]     = 0.0;
            c_ptr[base_idx + 1] = 0.0;
        }
    }
}
