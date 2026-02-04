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
    // Variant 2: Strided memory access with increased stride (access every other 4-element block)
    int stride = 8; // Access every 8th element, skipping 4 each time
    for (i = 0; i < (2 * size); i += stride) {
        if (i <= 2 * size - 4) {
            (((union unaligned_64 *)(left + i))->l) = pix;
        }
    }
}
