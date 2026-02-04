#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    u_int dim;
    u_int max_dim;
    double *ve;
} VEC;

extern VEC *u;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2)
    for (i = 0; i < u->dim; i += 2) {
        if (((u)->ve[i]) < 0 || (i < u->dim - 1 && ((u)->ve[i + 1]) > ((u)->ve[i])))
            break;
    }
}
