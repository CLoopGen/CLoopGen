#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int c;
extern int s;
extern uint32_t *factor1;
extern uint32_t *factor2;
extern  uint8_t dv100_qstep[16];
extern  uint16_t *iweight1;
extern  uint16_t *iweight2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect (Indexed) Memory Access Pattern
    // Use an index mapping table to access iweight1 and iweight2 indirectly,
    // simulating non-sequential or permuted access patterns.
    // Define a simple indirect index map (reversed order for variation)
    uint8_t idx_map[64];
    for (int j = 0; j < 64; j++) {
        idx_map[j] = 63 - j; // reverse indexing
    }
    for (c = 0; c < 4; c++) {
        for (s = 0; s < 16; s++) {
            uint32_t scale = dv100_qstep[s] << (c + 9);
            for (i = 0; i < 64; i++) {
                int mapped_idx = idx_map[i]; // indirect access via lookup
                *factor1++ = scale * iweight1[mapped_idx];
                *factor2++ = scale * iweight2[mapped_idx];
            }
        }
    }
}
