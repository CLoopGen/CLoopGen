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
    uint64_t local_pix[4];
    // Precompute values to remove direct loop-carried dependencies and increase parallelism
    for (int j = 0; j < 4; ++j) {
        local_pix[j] = pix + j; // Independent computation, no loop-carried dep
    }
    for (i = 0; i < (size); i += 4) {
        ((((union unaligned_64 *)(top + i))->l) = local_pix[i % 4]); // Use precomputed, data-independent mapping
    }
}
