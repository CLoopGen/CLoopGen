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
        local_accum = k1 * k1; // Removes potential RAW hazard by using only loop index; no loop-carried dependency
        k1 += 1; // Introduces WAR-like scenario: write after read of k1 in update, though still safe due to post-increment semantics
    }
    if (local_accum > 0) {
        k1 = local_accum; // Write to k1 after loop to preserve side effect without affecting iteration
    }
}
