#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};


extern int i;
extern int size;
extern uint16_t *top;
extern uint64_t pix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < (2 * size); i += 8) { // Increase step to reduce iterations and remove potential WAW hazards
        if (i + 4 < (2 * size)) {
            ((((union unaligned_64 *)(top + i))->l) = pix); // Independent writes with no intra-loop dependencies
            ((((union unaligned_64 *)(top + i + 4))->l) = pix);
        }
    }
    // Handle any remaining element if (2*size) is not divisible by 8
    if (i < (2 * size)) {
        ((((union unaligned_64 *)(top + i))->l) = pix);
    }
}
