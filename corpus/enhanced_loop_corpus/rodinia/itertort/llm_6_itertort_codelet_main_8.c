#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    u_int dim;
    u_int max_dim;
    double *ve;
} VEC;

extern VEC *xn;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < xn->dim; i++) {
        if (i == 0)
            xn->ve[i] = 0;
        else
            xn->ve[i] = xn->ve[i-1] + 1;
    }
}
