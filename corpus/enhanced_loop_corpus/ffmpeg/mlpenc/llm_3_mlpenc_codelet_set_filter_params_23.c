#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t coefs[32][32];
extern int32_t *fcoeff;
extern unsigned int i;
extern int order;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index mapping array
    uint32_t indices[32];
    for (uint32_t j = 0; j < order; j++) {
        indices[j] = j; // Identity mapping, could be randomized or reordered in practice
    }
    for (i = 0; i < order; i++) {
        uint32_t idx = indices[i]; // Simulate indirect access pattern
        fcoeff[idx] = coefs[order - 1][idx];
    }
}
