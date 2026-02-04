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
extern int i_max;
extern double max_val;
extern double tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2)
    for (i = 1; i < x->dim; i += 2) {
        tmp = x->ve[i];
        if (tmp > max_val) {
            max_val = tmp;
            i_max = i;
        }
    }
    // Handle potential last odd index if dim is even and greater than 1
    if ((x->dim % 2) == 0 && (x->dim - 1) > 1) {
        i = x->dim - 1;
        tmp = x->ve[i];
        if (tmp > max_val) {
            max_val = tmp;
            i_max = i;
        }
    }
}
