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
    for (j = j0; j < lim; j++) {
        mat->me[row][j] = vec->ve[j];
        if (j == row) {
            break;
        }
    }
}
