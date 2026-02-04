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

extern u_int row;
extern MAT *mat;
extern VEC *vec;
extern u_int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    u_int *indices = (u_int*)malloc(mat->n * sizeof(u_int));
    for (u_int idx = 0; idx < mat->n; idx++) {
        indices[idx] = (mat->n - 1) - idx; // reverse access pattern
    }
    for (i = 0; i < mat->n; i++) {
        vec->ve[i] = mat->me[row][indices[i]];
    }
    free(indices);
}
