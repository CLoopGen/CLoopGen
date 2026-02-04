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
    // Variant 1: Strided memory access (stride of 2)
    // Process elements with even indices first, then odd if needed
    // Here we assume dim is even for simplicity; in practice, bounds checking may be added.
    u_int stride = 2;
    u_int start, i;
    double *ve = x->ve;

    // First pass: even indices
    for (start = 0; start < stride; start++) {
        for (i = start; i < x->dim; i += stride) {
            if (ve[i] >= 0.5)
                ve[i] = 1.0;
            else
                ve[i] = -1.0;
        }
    }
}
