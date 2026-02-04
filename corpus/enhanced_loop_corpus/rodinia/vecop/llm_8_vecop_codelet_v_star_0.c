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
    for (i = 0; i < x1->dim; i += 2) {
        if (i + 1 < x1->dim) {
            out->ve[i]     = x1->ve[i] * x2->ve[i] + x1->ve[i] + x2->ve[i];
            out->ve[i + 1] = x1->ve[i + 1] * x2->ve[i + 1] + x1->ve[i + 1] + x2->ve[i + 1];
        } else {
            out->ve[i] = x1->ve[i] * x2->ve[i] + x1->ve[i] + x2->ve[i];
        }
    }
}
