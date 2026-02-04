#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int lmax;
extern double *jl_x;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element in two passes)
    int stride = 2;
    for (j = 0; j <= lmax; j += stride)
        jl_x[j] = 0.;
    for (j = 1; j <= lmax; j += stride)
        jl_x[j] = 0.;
}
