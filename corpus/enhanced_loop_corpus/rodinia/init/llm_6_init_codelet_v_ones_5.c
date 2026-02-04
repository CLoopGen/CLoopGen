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
    for (i = 0; i < dim; i += 2) {
        if (i + 1 < dim) {
            ve[i] = 1.;
            ve[i + 1] = 1.;
        } else {
            ve[i] = 1.;
        }
    }
}
