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
    uint64_t local_pix[2] = {pix, pix ^ 0xFFFFFFFFFFFFFFFFULL};
    for (i = 0; i < (2 * size); i += 8) {
        if (i + 4 < 2 * size) {
            (((union unaligned_64 *)(left + i))->l) = local_pix[0];
            (((union unaligned_64 *)(left + i + 4))->l) = local_pix[1];
        } else if (i < 2 * size) {
            (((union unaligned_64 *)(left + i))->l) = local_pix[0];
        }
        // Break loop-carried dependency by making accesses independent across iterations
        // Uses two alternating values to remove potential accumulation or ordering constraints
    }
}
