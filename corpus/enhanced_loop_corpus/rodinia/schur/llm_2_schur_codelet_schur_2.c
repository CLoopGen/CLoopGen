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
extern int i;
extern int j;
extern double **A_me;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by flattening the 2D array into a 1D pattern
    // Assuming row-major order and that A->base points to contiguous data
    double *base = A->base;
    u_int m = A->m;
    for (i = 0; i < m; i++) {
        int bound = i - 1;
        for (j = 0; j < bound; j++) {
            base[i * m + j] = 0.0;
        }
    }
}
