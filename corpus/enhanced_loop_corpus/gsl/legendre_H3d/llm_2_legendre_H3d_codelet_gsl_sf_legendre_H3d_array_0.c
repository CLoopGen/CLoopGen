#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int lmax;
extern double *result_array;
extern int ell;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (int ell = 0; ell <= lmax; ell += 2)
        result_array[ell] = 0.;
    // Handle odd indices if lmax is odd
    for (int ell = 1; ell <= lmax; ell += 2)
        result_array[ell] = 0.;
}
