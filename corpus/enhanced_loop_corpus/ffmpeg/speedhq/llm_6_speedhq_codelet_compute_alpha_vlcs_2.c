#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t run_code[134];
extern uint8_t run_bits[134];
extern int16_t run_symbols[134];
extern int entry;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Introduce loop-carried dependency (WAW and RAW) by making each iteration depend on the previous one
    // We maintain correctness by ensuring entry is updated in a way that preserves sequential access
    int temp_entry = entry;
    for (i = 0; i < 4; ++i) {
        run_code[temp_entry] = (i << 2) | 1;
        run_bits[temp_entry] = 4;
        run_symbols[temp_entry] = i + 1;
        temp_entry++;  // Local update to create write-after-write dependency with delayed global update
    }
    entry = temp_entry;  // Single update to entry after loop (eliminates per-iteration WAW on 'entry')
}
