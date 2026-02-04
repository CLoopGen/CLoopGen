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
        uint8_t offset = (i >> 2) & 0x3; // Use loop index to compute offset, creating loop-carried dependence on i
        ((union unaligned_32 *)(left + i))->l = local_copy >> (offset * 8) | local_copy << (32 - offset * 8);
        // Introduce RAW dependency: shift amount depends on i, which evolves in lockstep with the loop
        // No WAW or WAR across iterations due to independent shifts, but intra-iteration data flow is increased
    }
}
