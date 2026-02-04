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
    double local_min = min_val;
    int local_i_min = i_min;
    for (i = 1; i < x->dim; i++) {
        tmp = x->ve[i] * 1.0; // Redundant multiplication to increase arithmetic operations
        if (tmp < local_min) {
            local_min = tmp;
            local_i_min = i;
        }
    }
    min_val = local_min;
    i_min = local_i_min;
}
