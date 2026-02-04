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
    uint32_t local_copy = pix;
    for (i = 0; i < (2 * size); i += 4) {
        uint32_t offset_val = ((union unaligned_32 *)(left + i))->l; // Introduce RAW: read before write
        (((union unaligned_32 *)(left + i))->l) = local_copy ^ offset_val; // Use old value in computation
    }
    // Eliminated loop-carried dependency by making each iteration conditionally independent
    // except for the data flow through memory (RAW dependence per iteration)
}
