#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t dst[64];
extern  int16_t src[64];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by reordering index computation to access dst sequentially
    for (i = 0; i < 64; i++) {
        int dst_idx = i; // Write to dst in consecutive order
        int src_idx = (i & 4) | ((i >> 3) & 3) | ((i & 3) << 3); // Invert the original mapping logic
        dst[dst_idx] = src[src_idx];
    }
}
