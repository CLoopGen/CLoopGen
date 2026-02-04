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
    double *mat_row = mat->me[row];
    double *vec_e = vec->ve;
    u_int unroll_factor = 4;
    u_int remainder = (lim - j0) % unroll_factor;
    
    for (j = j0; j < j0 + remainder; j++) {
        mat_row[j] = vec_e[j];
    }
    
    for (; j <= lim - unroll_factor; j += unroll_factor) {
        mat_row[j]     = vec_e[j];
        mat_row[j+1]   = vec_e[j+1];
        mat_row[j+2]   = vec_e[j+2];
        mat_row[j+3]   = vec_e[j+3];
    }
    
    for (; j < lim; j++) {
        mat_row[j] = vec_e[j];
    }
}
