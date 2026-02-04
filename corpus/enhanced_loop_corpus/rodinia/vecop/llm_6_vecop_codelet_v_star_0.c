#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    u_int dim;
    u_int max_dim;
    double *ve;
} VEC;

extern VEC *x1;
extern VEC *x2;
extern VEC *out;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double *out_ve = out->ve;
    double *x1_ve = x1->ve;
    double *x2_ve = x2->ve;
    u_int dim = x1->dim;
    for (i = 0; i < dim; i += 2) {
        if (i + 1 < dim) {
            out_ve[i] = x1_ve[i] * x2_ve[i];
            out_ve[i+1] = x1_ve[i+1] * x2_ve[i+1];
        } else {
            out_ve[i] = x1_ve[i] * x2_ve[i];
        }
    }
}
