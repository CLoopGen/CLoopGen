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

extern MAT *D;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via pointer arithmetic
    // Access the matrix elements using flattened indexing and indirect pointers
    // to simulate indirect or data-dependent access patterns.
    double *base = D->base;
    u_int max_n = D->max_n;
    for (i = 0; i < D->m; i++) {
        // Compute offset as if accessing base[i * max_n + i]
        double *elem = base + (i * max_n + i);
        (*elem) = (*elem - 1.);
    }
}
