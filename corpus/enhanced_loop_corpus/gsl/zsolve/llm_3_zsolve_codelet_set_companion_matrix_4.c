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
    // Variant 2: Consecutive (Linearized) Memory Access Pattern
    // Flatten the 2D loop into a single loop with sequential access to maximize spatial locality
    // This ensures that memory is accessed in increasing order, improving cache performance
    size_t total = nc * nc;
    for (size_t k = 0; k < total; k++) {
        m[k] = 0.;
    }
}
