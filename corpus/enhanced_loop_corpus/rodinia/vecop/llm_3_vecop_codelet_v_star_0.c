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
    // Variant 2: Reverse consecutive memory access (traverse from end to start)
    for (i = x1->dim - 1; i >= 0; i--)
        out->ve[i] = x1->ve[i] * x2->ve[i];
}
