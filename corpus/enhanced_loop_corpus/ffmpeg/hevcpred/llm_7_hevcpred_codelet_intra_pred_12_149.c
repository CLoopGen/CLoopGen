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
    for (i = 0; i < (2 * size); i += 4) {
        int idx = (i >> 2) & 1; // Alternating access pattern to remove direct sequential dependency
        (((union unaligned_64 *)(left + i))->l) = local_pix[idx];
        // Eliminate potential WAW hazards by using two independent values written in round-robin fashion
    }
}
