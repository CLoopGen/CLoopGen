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

extern MAT *A;
extern VEC *out;
extern int i;
extern MAT *tmp;
extern VEC *b;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < A->m - 1; i++) {
        if (tmp->me[i][i] >= 0.0) {
            out->ve[i] = tmp->me[i][i];
        } else {
            continue;
        }
        b->ve[i] = tmp->me[i][i + 1];
    }
}
