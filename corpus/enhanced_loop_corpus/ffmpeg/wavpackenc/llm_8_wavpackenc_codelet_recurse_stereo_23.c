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
    for (i = 0; i < 11; i += 2) {
        uint32_t val1 = term_bits[i];
        if (val1 && val1 < local_best_bits) {
            local_best_bits = val1;
            best_term = i - 3;
        }
        if (i + 1 < 22) {
            uint32_t val2 = term_bits[i + 1];
            if (val2 && val2 < local_best_bits) {
                local_best_bits = val2;
                best_term = (i + 1) - 3;
            }
        }
    }
}
