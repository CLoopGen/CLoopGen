#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern uint8_t *dst;
extern int src_size;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with reordering
    // Instead of strided access by 3, process elements in groups of 3 with sequential indexing
    // This improves spatial locality and may benefit from prefetching
    for (i = 0; i < src_size - 2; i += 3) {
        register uint8_t temp = src[i + 2];
        dst[i]     = temp;
        dst[i + 1] = src[i + 1];
        dst[i + 2] = src[i];
    }
    // Handle leftover elements if src_size is not divisible by 3
    for (; i < src_size; i++) {
        dst[i] = src[i];
    }
}
