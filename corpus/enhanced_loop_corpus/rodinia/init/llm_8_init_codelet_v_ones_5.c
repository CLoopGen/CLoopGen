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
    for (i = 0; i < x->dim; i += 2) {
        if (i < x->dim) x->ve[i] = 1.;
        if (i + 1 < x->dim) x->ve[i + 1] = 1.;
    }
}
