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
    uint32_t temp_val;
    for (i = 0; i < 22; i++) {
        temp_val = term_bits[i];
        if (temp_val && temp_val < local_best_bits) {
            local_best_bits = temp_val;
            best_term = i - 3;
        }
    }
}
