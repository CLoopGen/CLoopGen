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
    // Variant 1: Consecutive memory access with unrolled write pattern
    // Instead of writing one 64-bit value every 4 elements (strided by 2 in 16-bit units),
    // we reorganize to write two consecutive 64-bit values, increasing spatial locality.
    for (i = 0; i < (2 * size); i += 8) {
        if (i + 4 < (2 * size)) {
            ((union unaligned_64 *)(left + i    ))->l = pix;
            ((union unaligned_64 *)(left + i + 4))->l = pix;
        } else {
            ((union unaligned_64 *)(left + i    ))->l = pix;
        }
    }
}
