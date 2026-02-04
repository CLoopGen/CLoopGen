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
    // Variant 1: Consecutive memory access with unrolled accumulation
    // Instead of writing pix every 4 bytes, we process two aligned 32-bit stores consecutively
    for (i = 0; i < (2 * size); i += 8) {
        if (i + 4 <= (2 * size)) {
            (((union unaligned_32 *)(left + i))->l) = pix;
            (((union unaligned_32 *)(left + i + 4))->l) = pix;
        } else if (i < (2 * size)) {
            (((union unaligned_32 *)(left + i))->l) = pix;
        }
    }
}
