#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint16_t left_sum[2][8];
extern uint16_t top_sum[2][8];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with reversed iteration and stride of 2 (simulating non-unit stride pattern)
    // Access elements in reverse order with artificial stride-like indexing for data variation
    for (i = 7; i >= 0; i--) {
        int idx = (i * 2) & 14; // creates a strided index: 14, 12, 10, ..., 0 (within bounds [0..14])
        top_sum[0][idx >> 1] += (top_sum[1][idx >> 1] * 181 + 128) >> 8;
        left_sum[0][idx >> 1] += (left_sum[1][idx >> 1] * 181 + 128) >> 8;
    }
}
