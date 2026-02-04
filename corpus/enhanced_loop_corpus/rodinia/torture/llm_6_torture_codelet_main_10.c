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

extern VEC *w;
extern MAT *C;
extern double s1;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double s1_local = s1;
    double *w_ve = w->ve;
    double **me = C->me;
    int m = C->m;
    int n = C->n;
    for (i = 0; i < m; i++) {
        double wi = w_ve[i] * s1_local;
        for (j = 0; j < n; j++) {
            me[i][j] = me[i][j] + wi * w_ve[j];
        }
    }
}
