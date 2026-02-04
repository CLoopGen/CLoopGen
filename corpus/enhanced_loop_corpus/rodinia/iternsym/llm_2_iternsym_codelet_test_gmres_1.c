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

extern int i;
extern MAT *R1;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by flattening the 2D array access into a 1D pattern
    // Assuming row-major layout and that R1->me is mapped to contiguous memory via R1->base
    double *base = R1->base;
    u_int max_n = R1->max_n;
    for (j = 0; j <= i; j++) {
        u_int idx = j * (max_n + 1); // Diagonal elements in flattened form: j * stride + j = j*(n+1)
        base[idx] -= 1.;
    }
}
