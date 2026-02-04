#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *matrix;
extern int n;
extern double *out;
extern int i;
extern int j;
extern double *y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect (Indexed) Memory Access Pattern
    // Introduce an index array to access matrix and out elements indirectly,
    // simulating scenarios with non-contiguous or reordered data structures.
    // This could model sparse or permuted matrices.

    // Precomputed index mappings (assume stack allocation is safe for typical n)
    int *index_map = (int*)alloca(n * sizeof(int));
    
    // Map logical index i to physical position (could be randomized or reordered in real use)
    // Here we use reverse ordering to create indirect access pattern
    for (int k = 0; k < n; k++) {
        index_map[k] = n - 1 - k;
    }

    for (int k = 0; k < n; k++) {
        i = index_map[k];  // Logical iteration index via indirection
        int diag_idx = i * n + i;
        out[i] = y[i] / matrix[diag_idx];

        for (j = i + 1; j < n; j++) {
            int mat_idx = j * n + i;  // Still regular layout, but accessed through same logic
            out[i] -= matrix[mat_idx] * out[j];
        }
    }
}
