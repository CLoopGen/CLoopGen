#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float is_table[2][16];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with step size of 2 (access every other element)
    for (i = 7; i < 16; i += 2) {
        is_table[0][i] = is_table[1][i] = 0.0f;
        // Handle remaining index if needed, but since we start at odd and step by 2,
        // and range is 7..15, we cover 7,9,11,13,15 — all valid.
    }
    // Finalize any missed index due to stride (if required for completeness),
    // but original loop sets all from 7 to 15. So use a second pass for even indices in range.
    for (i = 8; i < 16; i += 2) {
        is_table[0][i] = is_table[1][i] = 0.0f;
    }
}
