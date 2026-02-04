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

extern MAT *mat;
extern VEC *vec;
extern u_int row;
extern u_int _usr_j0;
extern u_int j;
extern u_int lim;

// Variable name mappings to avoid conflicts with system symbols
#define j0 _usr_j0



void loop(){
    // Variant 1: Consecutive memory access by flattening the 2D matrix into a 1D layout
    // Assuming row-major order: mat->me[row][j] maps to base[row * max_n + j]
    double *dst = mat->base + row * mat->max_n + j0;
    double *src = vec->ve + j0;
    u_int count = lim - j0;
    for (u_int i = 0; i < count; i++) {
        dst[i] = src[i];
    }
}
