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
    // Access memory with a larger stride (e.g., every 8th element)
    // This increases cache line skipping and creates a more scattered access pattern.
    // Still maintains total count within safe bounds by adjusting loop limit.
    for (i = 0; i < (4 * size); i += 8) {
        if (i + 3 < (uint32_t)(2 * size)) {  // Prevent overflow beyond original bound
            (((union unaligned_64 *)(left + i))->l) = (pix);
        }
    }
}
