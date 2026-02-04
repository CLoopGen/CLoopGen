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
    for (i = 0; i < x->dim; i += 2) {
        if (i + 1 < x->dim) {
            out->ve[i] = d->ve[i] * x->ve[i];
            out->ve[i+1] = d->ve[i+1] * x->ve[i+1];
        } else {
            out->ve[i] = d->ve[i] * x->ve[i];
        }
    }
}
