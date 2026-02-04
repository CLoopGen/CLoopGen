#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};


extern int i;
extern uint16_t *left;
extern int size_max_y;
extern uint64_t pix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t local_pix[4];
    // Eliminate potential aliasing and create independent computations
    for (int j = 0; j < 4; ++j) {
        local_pix[j] = pix ^ (0x2222222222222222ULL * j); // Independent computation, no loop-carried dep
    }
    for (i = 0; i < (size_max_y); i += 4) {
        ((union unaligned_64 *)(left + i))->l = local_pix[i % 4]; // Use precomputed values; no RAW/WAR/WAW across iterations
    }
}
