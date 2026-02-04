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
    double **me = B->me;
    double *ve_v = v->ve;
    double *ve_w = w->ve;
    int m = B->m;
    int n = B->n;
    for (i = 0; i < m; i++) {
        double wi = ve_w[i];
        for (j = 0; j < n; j++) {
            me[i][j] = me[i][j] + wi * ve_v[j];
        }
    }
}
