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

extern u_int col;
extern MAT *mat;
extern VEC *vec;
extern u_int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double *base_ptr = mat->base;
    u_int offset = col;
    u_int rows = mat->m;
    u_int width = mat->max_n;
    for (i = 0; i < rows; i++) {
        vec->ve[i] = base_ptr[i * width + offset];
    }
}
