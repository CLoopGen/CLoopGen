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
        i = 0;
        for (; i < x->dim; ) {
            if (((x)->ve[i]) >= 0.5)
                ((x)->ve[i] = (1.));
            else
                ((x)->ve[i] = (-1.));
            i++;
        }
    }
}
