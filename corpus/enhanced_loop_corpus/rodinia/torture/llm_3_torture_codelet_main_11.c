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

extern MAT *A;
extern MAT *C;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Use consecutive row-major linearization via base pointer (consecutive access)
    // Flatten the 2D access into a single loop assuming row-major layout and use base array
    // Assumes base is precomputed as a flattened version of the upper triangle or full matrix
    double *base_A = A->base;
    double *base_C = C->base;
    u_int n = A->max_n; // assumed physical width for stride

    for (i = 0; i < A->m; i++)
        for (j = i + 1; j < A->n; j++) {
            u_int idx = i * n + j; // linear index for consecutive layout
            base_A[idx] = 0.;
            base_C[idx] = 0.;
        }
}
