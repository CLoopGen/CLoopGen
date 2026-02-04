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
    for (i = 0; i < 22; i += 2) {
        for (int j = i; j < i + 2 && j < 22; j++)
            if (term_bits[j] && term_bits[j] < local_best_bits) {
                local_best_bits = term_bits[j];
                best_term = j - 3;
            }
    }
}
