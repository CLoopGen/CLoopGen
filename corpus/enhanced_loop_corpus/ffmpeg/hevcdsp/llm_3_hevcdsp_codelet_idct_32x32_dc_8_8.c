#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *coeffs;
extern int i;
extern int j;
extern int coeff;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive Memory Access with Linear Indexing (flattened loop for sequential writes)
    int idx;
    for (idx = 0; idx < 1024; idx++) {
        coeffs[idx] = coeff;
    }
}
