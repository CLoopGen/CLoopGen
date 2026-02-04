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
    for (i = 21; i >= 0; i--) {
        if (term_bits[i] != 0) {
            uint32_t temp = local_best_bits - term_bits[i];
            if ((int32_t)temp > 0) {
                local_best_bits = term_bits[i];
                best_term = i - 3;
            }
        }
    }
}
