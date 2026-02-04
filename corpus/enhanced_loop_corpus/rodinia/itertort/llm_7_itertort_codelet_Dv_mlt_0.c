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
    double temp = 0.0;
    u_int dim = x->dim;
    for (i = 0; i < dim; i++) {
        temp = d->ve[i] * x->ve[i];
        out->ve[i] = temp;
    }
}
