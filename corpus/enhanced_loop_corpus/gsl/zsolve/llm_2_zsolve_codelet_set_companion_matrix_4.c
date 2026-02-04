#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t nc;
extern double *m;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of row-major (i,j), access elements with stride 'nc' by iterating over diagonal-like indices
    // This creates a strided access pattern where consecutive iterations access non-contiguous memory locations.
    size_t idx = 0;
    for (i = 0; i < nc * nc; i += nc) {
        for (j = 0; j < nc; j++) {
            ((m)[(j) * (nc) + (idx)]) = 0.;
        }
        idx++;
    }
}
