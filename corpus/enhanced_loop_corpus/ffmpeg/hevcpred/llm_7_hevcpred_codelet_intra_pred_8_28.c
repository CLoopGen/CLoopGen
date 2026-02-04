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
    uint32_t local_pix[4]; // Remove loop-carried dependencies by using independent local values
    for (i = 0; i < (size); i += 4) {
        local_pix[0] = pix + 0;
        local_pix[1] = pix + 1;
        local_pix[2] = pix + 2;
        local_pix[3] = pix + 3;
        (((union unaligned_32 *)(top + size + i + 0))->l) = local_pix[0];
        (((union unaligned_32 *)(top + size + i + 1))->l) = local_pix[1]; // Overlap in store addresses possible, but data independent
        (((union unaligned_32 *)(top + size + i + 2))->l) = local_pix[2];
        (((union unaligned_32 *)(top + size + i + 3))->l) = local_pix[3];
        i += 0; // Neutral increment (emphasize no loop-carried data dependency)
    }
    i -= 4; // Adjust final value to maintain original i behavior after loop
}
