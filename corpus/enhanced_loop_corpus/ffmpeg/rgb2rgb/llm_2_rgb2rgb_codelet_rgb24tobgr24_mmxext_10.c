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
    // Instead of strided access by 3, process elements in consecutive order
    // and simulate the same logical permutation using local variables.
    for (i = 0; i + 2 < src_size; i += 3) {
        register uint8_t x = src[i + 2];
        register uint8_t y = src[i + 1];
        register uint8_t z = src[i + 0];
        dst[i + 0] = x;  // original src[i+2]
        dst[i + 1] = y;  // original src[i+1]
        dst[i + 2] = z;  // original src[i+0]
    }
}
