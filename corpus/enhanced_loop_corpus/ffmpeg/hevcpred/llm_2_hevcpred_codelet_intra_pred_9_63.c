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
    // Instead of writing one 64-bit value every 4 indices, write two consecutive 64-bit values
    // assuming pix contains repeated patterns or can be split logically.
    uint64_t pix_lo = pix & 0xFFFFFFFFULL;
    uint64_t pix_hi = (pix >> 32) & 0xFFFFFFFFULL;
    for (i = 0; i < (2 * size); i += 8) {
        ((((union unaligned_64 *)(left + i + 0))->l) = ((pix_lo << 32) | pix_lo));
        ((((union unaligned_64 *)(left + i + 4))->l) = ((pix_hi << 32) | pix_hi));
    }
}
