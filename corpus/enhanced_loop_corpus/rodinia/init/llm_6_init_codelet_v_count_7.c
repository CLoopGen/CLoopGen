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
    for (i = 0; i < dim; i++) {
        ve[i] = (double)i;
        if (i > 0)
            ve[i] += ve[i-1]; // Introduce RAW dependency: each element depends on previous
    }
}
