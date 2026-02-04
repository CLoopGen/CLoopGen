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

extern MAT *TMP;
extern VEC *x;
extern VEC *b;
extern double c;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < x->dim; i++) {
    c = b->ve[b->dim - 1];
    for (j = b->dim - 2; j >= 0; j--) {
        c = c * x->ve[i] + b->ve[j];
    }
    TMP->me[i][i] = c;
}
}
