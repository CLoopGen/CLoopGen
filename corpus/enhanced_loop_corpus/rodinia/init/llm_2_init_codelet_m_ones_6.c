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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by flattening the 2D array into a 1D sequential access
    // Since me[i][j] is accessed row-wise and assuming row-major order, we can traverse consecutively
    double *base = A->base;
    u_int size = A->m * A->n;
    for (i = 0; i < size; i++) {
        base[i] = 1.;
    }
}
