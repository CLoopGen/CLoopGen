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
    u_int limit = mat->m;
    for (i = 0; i < limit; i += 2) {
        if (i + 1 < limit) {
            vec->ve[i] = mat->me[i][col];
            vec->ve[i + 1] = mat->me[i + 1][col];
        } else {
            vec->ve[i] = mat->me[i][col];
        }
    }
}
