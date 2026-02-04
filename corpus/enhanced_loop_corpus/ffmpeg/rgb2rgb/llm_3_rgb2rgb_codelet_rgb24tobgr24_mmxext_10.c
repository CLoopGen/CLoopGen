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
    // Variant 2: Indirect memory access via index array (simulated with arithmetic)
    // Use precomputed effective indices to achieve the same data movement
    // This models indirect or gather-style access patterns.
    for (i = 0; i < src_size; i += 3) {
        const unsigned int idx0 = i + 0;
        const unsigned int idx1 = i + 1;
        const unsigned int idx2 = i + 2;
        register uint8_t x = src[idx2];      // src[i+2]
        dst[idx0] = x;                       // dst[i+0] = src[i+2]
        dst[idx1] = src[idx1];               // dst[i+1] = src[i+1]
        dst[idx2] = src[idx0];               // dst[i+2] = src[i+0]
    }
}
