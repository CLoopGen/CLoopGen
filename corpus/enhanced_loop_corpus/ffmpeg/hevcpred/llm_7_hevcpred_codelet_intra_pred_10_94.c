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
extern int bottom_left_size;
extern uint64_t pix;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Eliminate loop-carried dependencies entirely; make each iteration independent
    // Unroll the loop partially and operate on multiple indices without chaining
    int limit = (size - bottom_left_size) & ~3; // Ensure multiple of 4
    for (i = 0; i < limit; i += 8) { // Double step to allow two independent writes
        uint64_t local_pix1 = pix ^ i;      // Break dependency on prior iterations using loop index
        uint64_t local_pix2 = pix ^ (i + 4);
        if (i < limit) {
            (((union unaligned_64 *)(left + size + bottom_left_size + i))->l) = local_pix1;
        }
        if (i + 4 < limit) {
            (((union unaligned_64 *)(left + size + bottom_left_size + i + 4))->l) = local_pix2;
        }
    }
    // Handle remaining elements if any (original loop step was 4, so up to 4 left)
    for (; i < (size - bottom_left_size); i += 4) {
        (((union unaligned_64 *)(left + size + bottom_left_size + i))->l) = pix;
    }
}
