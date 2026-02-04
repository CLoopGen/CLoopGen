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
    for (int j = 0; j < 22; j++) {
        index_map[j] = 21 - j; // Reverse order access: process from last to first element
    }
    local_best_bits = 0xFFFFFFFF;
    best_term = -3;
    for (i = 0; i < 22; i++) {
        int mapped_idx = index_map[i];
        if (term_bits[mapped_idx] && term_bits[mapped_idx] < local_best_bits) {
            local_best_bits = term_bits[mapped_idx];
            best_term = mapped_idx - 3;
        }
    }
}
