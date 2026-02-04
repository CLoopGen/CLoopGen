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

extern MAT *R;
extern VEC *v;
extern int j;
extern double temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int k, factor = 4;
    int unroll_factor = (R->n + factor - 1) / factor;
    for (k = 0; k < unroll_factor; k++) {
        int idx = k * factor;
        if (idx < R->n) R->me[0][idx] += temp * v->ve[idx];
        if (idx + 1 < R->n) R->me[0][idx + 1] += temp * v->ve[idx + 1];
        if (idx + 2 < R->n) R->me[0][idx + 2] += temp * v->ve[idx + 2];
        if (idx + 3 < R->n) R->me[0][idx + 3] += temp * v->ve[idx + 3];
    }
}
