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
    uint32_t local_pix;
    for (i = 0; i < (2 * size); i += 4) {
        local_pix = pix + (i + 4 < 2 * size ? (((union unaligned_32 *)(left + i + 4))->l) : 0);
        // Remove WAW and WAR hazards by using a local copy; introduce artificial RAW dependency on future memory (speculative load)
        (((union unaligned_32 *)(left + i))->l) = local_pix;
    }
}
