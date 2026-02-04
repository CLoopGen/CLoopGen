#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};


extern int i;
extern int size;
extern uint8_t *top;
extern uint32_t pix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with full width write unrolling
    // Instead of writing one 32-bit value every 4 bytes, we assume alignment allows consecutive writes.
    // We process two 32-bit values per iteration, effectively writing 8 bytes each time.
    for (i = 0; i < (2 * size); i += 8) {
        if (i + 4 < (2 * size)) {
            ((union unaligned_32 *)(top + i))->l = pix;
            ((union unaligned_32 *)(top + i + 4))->l = pix;
        } else {
            ((union unaligned_32 *)(top + i))->l = pix;
        }
    }
}
