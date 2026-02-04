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
        if (i + 1 < x->dim) {
            if (((x)->ve[i]) >= 0.5)
                ((x)->ve[i] = (1.));
            else
                ((x)->ve[i] = (-1.));
            if (((x)->ve[i+1]) >= 0.5)
                ((x)->ve[i+1] = (1.));
            else
                ((x)->ve[i+1] = (-1.));
        } else {
            if (((x)->ve[i]) >= 0.5)
                ((x)->ve[i] = (1.));
            else
                ((x)->ve[i] = (-1.));
        }
    }
}
