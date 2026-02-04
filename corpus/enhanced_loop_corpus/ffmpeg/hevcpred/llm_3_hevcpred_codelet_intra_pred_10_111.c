#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};


extern int i;
extern int size;
extern uint16_t *left;
extern uint64_t pix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with increased stride
    // Access memory with a larger stride (skip one 64-bit unit each time)
    // This creates a strided access pattern that may simulate non-contiguous data layout or tiling effects.
    const int stride = 8;  // Process every 8th element (16 bytes apart in uint16_t array)
    for (i = 0; i < (2 * size); i += stride) {
        if (i < (2 * size) - 3) {  // Ensure at least 4 elements remain
            ((union unaligned_64 *)(left + i))->l = pix;
        }
    }
}
