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

extern VEC *v;
extern VEC *w;
extern MAT *B;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (B->m == 0 || B->n == 0) return;
    for (i = 0; i < B->m; i++) {
        double wi = (w)->ve[i];
        for (j = 0; j < B->n; j++) {
            (B)->me[i][j] += wi * (v)->ve[j];
        }
    }
}
