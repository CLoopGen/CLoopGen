#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern int pos;
extern uint8_t *alpha;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index map (simulated via reversed order)
    int index_map[256];
    for (int j = 0; j < 256; j++) {
        index_map[j] = 255 - j; // Reverse mapping
    }
    for (i = 0; i < 256; i++) {
        int mapped_idx = index_map[i];
        alpha[mapped_idx] = 255 - buf[pos + mapped_idx];
    }
}
