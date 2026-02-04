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
extern int i_min;
extern double min_val;
extern double tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2)
    for (i = 1; i < x->dim; i += 2) {
        tmp = x->ve[i];
        if (tmp < min_val) {
            min_val = tmp;
            i_min = i;
        }
    }
    // Handle the last element if dimension is even and greater than 1
    if (x->dim > 1 && (x->dim % 2) == 0) {
        i = x->dim - 1;
        tmp = x->ve[i];
        if (tmp < min_val) {
            min_val = tmp;
            i_min = i;
        }
    }
}
