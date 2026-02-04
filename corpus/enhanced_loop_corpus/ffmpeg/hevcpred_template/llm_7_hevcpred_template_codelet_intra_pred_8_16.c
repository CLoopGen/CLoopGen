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
        local_pix = pix + i; // Introduce RAW dependency on loop index i; eliminates potential loop-carried dependence on shared state
        (((union unaligned_32 *)(left + i))->l) = local_pix;
    } // Each iteration computes value independently, increasing parallelism potential (no loop-carried dep)
}
