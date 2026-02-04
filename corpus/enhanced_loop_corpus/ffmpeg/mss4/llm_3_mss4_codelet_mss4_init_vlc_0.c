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
    // Variant 2: Indirect memory access using an index remapping table
    // Use a precomputed permutation array to access bits and codes indirectly
    // Simulate scattered writes via an offset map
    static uint16_t offset_map[162];
    if (offset_map[0] == 0) {
        // Initialize a simple indirect mapping: reverse layout for variation
        for (int k = 0; k < 162; k++) {
            offset_map[k] = (161 - k);  // Reverse indexing
        }
    }

    for (i = 0; i < 16; i++) {
        for (j = 0; j < lens[i]; j++) {
            int mapped_idx = offset_map[idx];  // Indirect access through map
            bits[mapped_idx] = i + 1;
            codes[mapped_idx] = prefix++;
            max_bits = i + 1;
            idx++;
        }
        prefix <<= 1;
    }
}
