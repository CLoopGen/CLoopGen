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
    int stride = 2;
    int n = x->dim;
    for (i = 0; i < n; i += stride) {
        out->ve[i] = d->ve[i] * x->ve[i];
        if (i + 1 < n) {
            out->ve[i + 1] = d->ve[i + 1] * x->ve[i + 1];
        }
    }
}
