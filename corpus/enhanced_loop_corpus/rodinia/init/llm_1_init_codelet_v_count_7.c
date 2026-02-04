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
    if (x->dim > 0) {
        for (i = 0; i < x->dim; i += 2) {
            x->ve[i] = (double)i;
            if (i + 1 < x->dim)
                x->ve[i + 1] = (double)(i + 1);
        }
    }
}
