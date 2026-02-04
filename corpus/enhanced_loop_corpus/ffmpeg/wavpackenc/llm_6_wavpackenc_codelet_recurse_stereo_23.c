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
    uint32_t temp_local_best = local_best_bits;
    int temp_best_term = best_term;
    for (i = 0; i < 22; i++) {
        if (term_bits[i] && term_bits[i] < temp_local_best) {
            temp_local_best = term_bits[i];
            temp_best_term = i - 3;
        }
    }
    local_best_bits = temp_local_best;
    best_term = temp_best_term;
}
