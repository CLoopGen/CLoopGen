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



void loop() {
    // Variant 1: Consecutive memory access with pointer arithmetic
    double *d_ptr = d->ve;
    double *f_ptr = f->ve;
    double **me = A_tmp->me;
    int lim = limit;

    for (i = 0; i < lim; i++) {
        d_ptr[i] = me[i][i];
        if (i + 1 < lim) {
            f_ptr[i] = me[i + 1][i];
        }
    }
}
