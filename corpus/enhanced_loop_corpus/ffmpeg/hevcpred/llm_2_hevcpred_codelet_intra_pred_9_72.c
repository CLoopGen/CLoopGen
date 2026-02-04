#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint16_t *top;
extern uint16_t *filtered_top;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with reversed indexing pattern
    // Instead of accessing top[-1] and top[63] repeatedly, we simulate a shift in base pointer
    // and use consecutive increasing indices for filtered_top.
    uint16_t *base_top = top + 63;  // Shift base to avoid negative index
    for (i = 0; i < 63; i++) {
        filtered_top[i] = ((64 - (i + 1)) * base_top[-64] + (i + 1) * base_top[0] + 32) >> 6;
    }
}
