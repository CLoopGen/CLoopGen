#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    u_int dim;
    u_int max_dim;
    double *ve;
} VEC;

extern VEC *x;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double *ve = x->ve;
    u_int dim = x->dim;
    double prev = 0.0;
    for (i = 0; i < dim; i++) {
        ve[i] = 1. + prev;
        prev = ve[i];
    }
}
