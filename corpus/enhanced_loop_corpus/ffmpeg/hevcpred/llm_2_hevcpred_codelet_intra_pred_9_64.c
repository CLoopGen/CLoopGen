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
    // Variant 1: Consecutive memory access with unrolled writes
    // Instead of writing one 64-bit value every 4 elements (strided by 2 uint16_t),
    // we write two consecutive 64-bit values, effectively covering 8 uint16_t per iteration.
    for (i = 0; i < (2 * size); i += 8) {
        if (i + 4 <= (2 * size)) {
            (((union unaligned_64 *)(left + i))->l) = pix;
            (((union unaligned_64 *)(left + i + 4))->l) = pix;
        } else if (i < (2 * size)) {
            (((union unaligned_64 *)(left + i))->l) = pix;
        }
    }
}
