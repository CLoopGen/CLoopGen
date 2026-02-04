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
    // Variant 2: Consecutive (linearized) memory access via base pointer
    // Assuming `base` is a flattened representation of the matrix stored row-major
    // We directly access diagonal elements using known indexing: i * (max_n) + i = i*(max_n+1)
    // This changes access from 2D array to 1D consecutive layout with indirect index calculation
    for (i = 0; i < D->m; i++) {
        u_int idx = i * (D->max_n + 1); // Diagonal element in linearized form
        (D->base[idx] = (D->base[idx] - 1.));
    }
}
