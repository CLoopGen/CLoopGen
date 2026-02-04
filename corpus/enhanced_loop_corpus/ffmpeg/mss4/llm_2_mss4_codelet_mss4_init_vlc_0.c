#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *lens;
extern uint8_t bits[162];
extern uint16_t codes[162];
extern int i;
extern int j;
extern int prefix;
extern int max_bits;
extern int idx;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access with stride of 2 (unrolling-like pattern)
    // Access bits and codes with a fixed stride, simulating non-unit stride access
    // We assume idx increases by 1 each time, but write to every 2nd location
    for (i = 0; i < 16; i++) {
        for (j = 0; j < lens[i]; j++) {
            int target_idx = idx * 2;  // Strided access: write to even indices
            if (target_idx + 1 < 324) {  // Safe bound check for 162*2
                bits[target_idx] = i + 1;
                codes[target_idx] = prefix++;
                max_bits = i + 1;
                idx++;
            }
        }
        prefix <<= 1;
    }
}
