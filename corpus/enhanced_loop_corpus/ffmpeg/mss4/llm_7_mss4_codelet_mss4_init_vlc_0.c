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



void loop(){
    uint8_t local_bits[16];
    uint16_t local_codes[162];
    int local_idx = idx;
    int local_prefix = prefix;
    int local_max_bits = max_bits;

    for (i = 0; i < 16; i++) {
        int current_len = lens[i];
        int bit_val = i + 1;
        for (j = 0; j < current_len; j++) {
            local_bits[local_idx] = bit_val;
            local_codes[local_idx] = local_prefix++;
            local_idx++;
        }
        local_max_bits = bit_val;
        local_prefix <<= 1;
    }

    // Write back to global state
    for (i = 0; i < local_idx - idx; i++) {
        bits[idx + i] = local_bits[idx + i];
        codes[idx + i] = local_codes[idx + i];
    }
    idx = local_idx;
    prefix = local_prefix;
    max_bits = local_max_bits;
}
