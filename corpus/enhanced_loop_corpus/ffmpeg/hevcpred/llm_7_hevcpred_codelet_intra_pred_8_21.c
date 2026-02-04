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
    uint32_t local_pix[2] = {pix, pix ^ 0xFFFFFFFF}; // Split data into two independent values
    int stride = 8;
    // Unroll the loop by factor of 2 to remove some data dependencies and enable parallel stores
    for (i = 0; i < (2 * size); i += stride) {
        if (i + 4 < (2 * size)) {
            (((union unaligned_32 *)(left + i))->l) = local_pix[0];
            (((union unaligned_32 *)(left + i + 4))->l) = local_pix[1];
        } else if (i < (2 * size)) {
            (((union unaligned_32 *)(left + i))->l) = local_pix[0];
        }
    }
}
