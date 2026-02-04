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
    uint32_t local_pix = pix;
    for (i = 0; i < (2 * size); i += 4) {
        uint32_t offset = i;
        // Remove potential WAW and WAR hazards by using local temporaries and reordering independent operations
        ((union unaligned_32 *)(top + offset))->l = local_pix;
        // Add independent computation to break spurious dependencies
        offset += 4;
        if (offset < (2 * size)) {
            ((union unaligned_32 *)(top + offset))->l = local_pix;
        }
        i = offset; // Skip ahead, effectively unrolling by 2 with no loop-carried dependency
    }
}
