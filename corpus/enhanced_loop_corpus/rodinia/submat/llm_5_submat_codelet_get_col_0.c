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
    u_int m_val = mat->m;
    u_int col_val = col;
    double **me_ptr = mat->me;
    double *ve_ptr = vec->ve;
    for (i = 0; i < m_val; i++) {
        if (me_ptr[i] != NULL)
            ve_ptr[i] = me_ptr[i][col_val];
    }
}
