#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    u_int dim;
    u_int max_dim;
    double *ve;
} VEC;

extern VEC *d;
extern VEC *x;
extern VEC *out;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double *out_ve = out->ve;
    double *d_ve = d->ve;
    double *x_ve = x->ve;
    u_int dim = x->dim;
    for (i = 0; i < dim; i++) {
        out_ve[i] = d_ve[i] * x_ve[i];
    }
}
