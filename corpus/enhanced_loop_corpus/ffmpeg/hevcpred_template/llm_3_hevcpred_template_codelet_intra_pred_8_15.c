#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};


extern int i;
extern int size;
extern uint8_t *left;
extern uint32_t pix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with increasing stride pattern
    // Access elements in a strided manner: step by 8, but still within bounds
    // This creates a non-unit stride access pattern, reducing total iterations
    int stride = 8;
    int limit = (2 * size);
    for (i = 0; i < limit; i += stride) {
        int effective_idx = i % limit; // Wrap-around to stay within bounds
        (((union unaligned_32 *)(left + effective_idx))->l) = pix;
    }
}
