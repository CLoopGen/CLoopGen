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
    for (i = 0; i < 22; i++) {
        uint32_t t = term_bits[i];
        if (t && t < local_best_bits) {
            local_best_bits = t;
            best_term = i - 3;
        }
        if (t && t == local_best_bits && i > best_term + 3) {
            best_term = i - 3;
        }
    }
}
