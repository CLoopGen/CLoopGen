#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    u_int dim;
    u_int max_dim;
    double *ve;
} VEC;

typedef struct {
    u_int m;
    u_int n;
    u_int max_m;
    u_int max_n;
    u_int max_size;
    double **me;
    double *base;
} MAT;

extern VEC *d;
extern VEC *f;
extern int i;
extern int limit;
extern MAT *A_tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with array base pointer arithmetic
    double *d_ve = d->ve;
    double *f_ve = f->ve;
    double **me = A_tmp->me;
    for (i = 0; i < limit; i++) {
        d_ve[i] = me[i][i];
        if (i + 1 < limit) {
            f_ve[i] = me[i][i + 1];
        }
    }
}
