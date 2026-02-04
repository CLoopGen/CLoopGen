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
    // Variant 2: Strided Memory Access Pattern with Reverse Traversal
    // Change access pattern to stride backwards through the array with same step size
    // This alters temporal and spatial access patterns, potentially affecting cache behavior.
    register uint8_t x;
    for (i = src_size - (src_size % 3); i > 0; i -= 3) {
        x = src[i - 1];
        dst[i - 1] = src[i - 3];
        dst[i - 2] = src[i - 2];
        dst[i - 3] = x;
    }
}
