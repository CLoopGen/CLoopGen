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

extern MAT *C;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access pattern using a flattened base array
    // Assuming the matrix is stored in row-major order in C->base
    double *base = C->base;
    u_int m = C->m;
    for (i = 0; i < m; i++) {
        u_int idx = i * (m + 1); // Access diagonal elements as if in consecutive layout
        base[idx] = base[idx] - 1.0;
    }
}
