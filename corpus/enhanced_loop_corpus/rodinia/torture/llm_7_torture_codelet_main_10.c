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
    double s1_val = s1;
    for (j = 0; j < C->n; j++) {
        double wj = (w->ve[j]) * s1_val;
        for (i = 0; i < C->m; i++) {
            (C->me[i][j] = (C->me[i][j]) + (w->ve[i]) * wj);
        }
    }
}
