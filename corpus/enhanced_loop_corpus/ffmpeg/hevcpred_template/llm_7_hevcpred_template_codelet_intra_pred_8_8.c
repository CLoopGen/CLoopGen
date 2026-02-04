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
    uint32_t local_pix[2] = {pix, pix ^ 0xFFFFFFFF};
    for (i = 0; i < (size); i += 8) { // Increase step to reduce iterations and enable independent writes
        if (i + 4 < size) {
            (((union unaligned_32 *)(left + i))->l) = local_pix[0];       // No dependency between these two stores
            (((union unaligned_32 *)(left + i + 4))->l) = local_pix[1];   // Independent (non-loop-carried) data access
        }
    }
    // Handle leftover elements if size is not multiple of 8
    for (; i < (size); i += 4) {
        (((union unaligned_32 *)(left + i))->l) = pix;
    }
}
