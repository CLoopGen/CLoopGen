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
extern int bottom_left_size;
extern uint32_t pix;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    uint32_t local_pix[2] = {pix, pix ^ 0xFFFFFFFF};
    for (i = 0; i < (size - bottom_left_size); i += 8) { // Double the step to reduce iterations and avoid overlapping writes
        if (i % 8 == 0) {
            (((union unaligned_32 *)(left + size + bottom_left_size + i))->l) = local_pix[0];
        } else {
            (((union unaligned_32 *)(left + size + bottom_left_size + i))->l) = local_pix[1];
        }
        // Eliminate potential WAW hazards by spacing out stores; no loop-carried dependency
    }
}
