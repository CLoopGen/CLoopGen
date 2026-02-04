#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    u_int dim;
    u_int max_dim;
    double *ve;
} VEC;

extern VEC *a;
extern VEC *b;
extern VEC *a2;
extern VEC *b2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (i = 0; i < (a2->dim - 1) / 2; i++) {
        a2->ve[2*i] = a->ve[2*i + 1];
        b2->ve[2*i] = b->ve[2*i + 1];
    }
}
