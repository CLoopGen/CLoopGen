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
    // Variant 2: Indirect array access using an index map (simulating irregular access pattern)
    int index_map[22];
    // Create a reversed access pattern: process from last to first element
    for (int j = 0; j < 22; j++) {
        index_map[j] = 21 - j; // Reverse order: 21, 20, ..., 0
    }

    local_best_bits = 0xFFFFFFFF; // Initialize to maximum value
    best_term = -3;

    for (i = 0; i < 22; i++) {
        int idx = index_map[i]; // Indirect access via mapping
        if (term_bits[idx] && term_bits[idx] < local_best_bits) {
            local_best_bits = term_bits[idx];
            best_term = idx - 3;
        }
    }
}
