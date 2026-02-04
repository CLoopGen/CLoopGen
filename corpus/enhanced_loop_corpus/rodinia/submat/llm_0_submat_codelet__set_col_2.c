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
extern u_int col;
extern u_int i0;
extern u_int i;
extern u_int lim;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (u_int j = 0; j < 1; j++)
        for (i = i0; i < lim; i++)
            mat->me[i][col] = vec->ve[i];
}
