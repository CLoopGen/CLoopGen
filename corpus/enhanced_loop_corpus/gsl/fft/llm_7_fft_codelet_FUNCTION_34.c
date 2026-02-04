#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t k1;
extern  size_t product_1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t local_accum = 0;
    for (k1 = 0; k1 < product_1; k1++) {
        local_accum = k1 * 2; // Removes potential loop-carried dependency; each iteration independent (no carry-over in computation)
        k1 += 1; // Introduces RAW hazard: use of k1 before potential increment; also modifies loop variable within body
    }
}
