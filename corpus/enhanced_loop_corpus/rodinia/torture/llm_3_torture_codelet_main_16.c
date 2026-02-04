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
    // Variant 2: Consecutive linear memory access using flattened base array
    // Assume the matrix data is also accessible via a contiguous 'base' array
    // Map 2D diagonal indices (i,i) into 1D index assuming row-major layout: index = i * max_n + i
    u_int m = D->m;
    u_int max_n = D->max_n;
    double *base = D->base;
    for (i = 0; i < m; i++) {
        u_int idx = i * (max_n + 1);  // because (i * max_n + i) = i*(max_n + 1)
        base[idx] = base[idx] - 1.;
    }
}
