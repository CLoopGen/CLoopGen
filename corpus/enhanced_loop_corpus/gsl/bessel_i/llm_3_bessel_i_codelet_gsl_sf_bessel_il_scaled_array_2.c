#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int lmax;
extern double *result_array;
extern int ell;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with stride 2, processing every second element
    // First pass: handle odd indices in descending order
    for (int ell = (lmax % 2 == 1) ? lmax : lmax - 1; ell >= 1; ell -= 2) {
        result_array[ell] = 0.;
    }
    // Second pass: handle even indices in descending order
    for (int ell = (lmax % 2 == 0) ? lmax : lmax - 1; ell >= 2; ell -= 2) {
        result_array[ell] = 0.;
    }
}
