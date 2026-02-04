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

extern MAT *U;
extern VEC *x;
extern VEC *out;
extern double sum;
extern int i;
extern int j;
extern int limit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int k;
for (i = limit - 1; i >= 0; i--) {
    sum = 0.;
    for (j = 0; j <= i; j++) {
        for (k = 0; k < 1; k++) {
            sum += U->me[j][i] * x->ve[j];
        }
    }
    out->ve[i] = sum;
}
}
