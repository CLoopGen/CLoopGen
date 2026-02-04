#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint32_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using a predefined index map
    // Introduces non-sequential, indirect addressing via an index array
    static const int index_map[4] = {1, 3, 5, 7}; // Odd indices for indirect access
    for (i = 0; i < 4; i++) {
        int idx = index_map[i];          // Indirect access through lookup table
        int reverse_idx = 7 - idx;       // Corresponding mirrored index
        src[idx] = ((src[idx] << 16) | (src[idx] >> 16)) ^ src[reverse_idx];
    }
}
