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
    max_val = x->ve[0];
    i_max = 0;
    for (i = 1; i < x->dim; i += 2) {
        double tmp1 = x->ve[i];
        double tmp2 = (i + 1 < x->dim) ? x->ve[i + 1] : tmp1;
        if (tmp1 > tmp2) {
            if (tmp1 > max_val) {
                max_val = tmp1;
                i_max = i;
            }
        } else {
            if (tmp2 > max_val) {
                max_val = tmp2;
                i_max = i + 1;
            }
        }
    }
}
