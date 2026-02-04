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
    double *ve = x->ve;
    u_int dim = x->dim;
    double local_min_val = min_val;
    int local_i_min = i_min;
    for (i = 1; i < dim; i++) {
        tmp = ve[i];
        if (tmp < local_min_val) {
            local_min_val = tmp;
            local_i_min = i;
        }
    }
    min_val = local_min_val;
    i_min = local_i_min;
}
