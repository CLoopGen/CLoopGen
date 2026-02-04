#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t i;
extern double fval[25];
extern double v[12];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via index remapping using a lookup table
    // Simulates irregular access pattern; indices precomputed to maintain correctness
    const size_t remap[12] = {24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13}; // j = 24 - i
    for (i = 0; i < 12; i++) {
        const size_t j = remap[i];
        v[i] = fval[i] - fval[j];
        fval[i] = fval[i] + fval[j];
    }
}
