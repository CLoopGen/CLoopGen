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
    for (i = 1; i < 22; i += 2) {
        uint32_t term1 = term_bits[i - 1];
        uint32_t term2 = term_bits[i];
        int update_index = -1;
        if (term1 && term1 < temp_local_best) {
            temp_local_best = term1;
            update_index = i - 1;
        }
        if (term2 && term2 < temp_local_best) {
            temp_local_best = term2;
            update_index = i;
        }
        if (update_index != -1) {
            best_term = update_index - 3;
        }
    }
    if (term_bits[0] && term_bits[0] < local_best_bits) {
        local_best_bits = term_bits[0];
        best_term = 0 - 3;
    }
    local_best_bits = temp_local_best;
}
