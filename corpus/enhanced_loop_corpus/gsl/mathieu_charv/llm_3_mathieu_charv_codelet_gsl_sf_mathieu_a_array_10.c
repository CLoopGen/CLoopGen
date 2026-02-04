#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int even_order;
extern unsigned int ii;
extern double *dd;
extern double *ee;
extern double *zz;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with fixed step through precomputed indices
    for (ii = 1; ii < even_order - 1; ii++) {
        int base_idx = ii * (even_order + 1); // Stride modified by combining row and column progression
        zz[base_idx - 1] = ee[ii];
        zz[base_idx]     = dd[ii];
        zz[base_idx + 1] = ee[ii + 1];
    }
}
