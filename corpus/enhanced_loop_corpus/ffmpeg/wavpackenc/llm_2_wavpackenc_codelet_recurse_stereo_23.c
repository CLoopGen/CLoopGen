#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t term_bits[22];
extern uint32_t local_best_bits;
extern int best_term;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolled to process two elements per iteration
    local_best_bits = 0xFFFFFFFF; // Ensure we start with a high value for comparison
    best_term = -3; // Default in case no valid term is found
    for (i = 0; i < 22; i += 2) {
        int idx = i;
        if (idx < 22 && term_bits[idx] && term_bits[idx] < local_best_bits) {
            local_best_bits = term_bits[idx];
            best_term = idx - 3;
        }
        idx = i + 1;
        if (idx < 22 && term_bits[idx] && term_bits[idx] < local_best_bits) {
            local_best_bits = term_bits[idx];
            best_term = idx - 3;
        }
    }
}
