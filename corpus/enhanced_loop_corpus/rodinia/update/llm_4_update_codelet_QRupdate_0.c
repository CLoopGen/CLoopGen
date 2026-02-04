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
extern VEC *u;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = R->m - 1; k >= 0; k--) {
    if (u->ve[k] != 0.) {
        break;
    } else {
        continue;
    }
}
}
