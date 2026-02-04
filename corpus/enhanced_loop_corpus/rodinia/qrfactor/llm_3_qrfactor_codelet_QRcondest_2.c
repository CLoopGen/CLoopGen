#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    u_int m;
    u_int n;
    u_int max_m;
    u_int max_n;
    u_int max_size;
    double **me;
    double *base;
} MAT;

typedef struct {
    u_int dim;
    u_int max_dim;
    double *ve;
} VEC;

extern MAT *QR;
extern VEC *y;
extern double sum;
extern int i;
extern int j;
extern int limit;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect Memory Access via Index Array
    // Introduce an index array to access elements indirectly, changing the access pattern
    // from direct sequential to indirect. This simulates scenarios with non-unit strides or scatter/gather.

    int *indices = (int*)malloc(limit * sizeof(int));
    if (!indices) return; // Handle allocation failure

    // Initialize index map (identity mapping, but allows for reordering later if needed)
    for (int idx = 0; idx < limit; idx++) {
        indices[idx] = idx;
    }

    for (i = 0; i < limit; i++) {
        sum = 0.;
        // Use indirect addressing: access elements via the index array
        for (j = 0; j < i; j++) {
            int idx_j = indices[j]; // Indirect access to j-th element
            sum -= QR->me[idx_j][i] * y->ve[idx_j];
        }
        sum -= (sum < 0.) ? 1. : -1.;
        y->ve[i] = sum / QR->me[i][i];
    }

    free(indices);
}
