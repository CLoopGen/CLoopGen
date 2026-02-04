#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int lmax;
extern double *result_array;
extern int ell;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element in two passes)
    int stride = 2;
    // First pass: even indices
    for (ell = 0; ell <= lmax; ell += stride)
        result_array[ell] = 0.;
    // Second pass: odd indices
    for (ell = 1; ell <= lmax; ell += stride)
        result_array[ell] = 0.;
}
