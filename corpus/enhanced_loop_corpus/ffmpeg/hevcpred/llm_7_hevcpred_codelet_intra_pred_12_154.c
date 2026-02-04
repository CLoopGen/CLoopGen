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
    uint64_t local_pix[2];
    local_pix[0] = pix;
    local_pix[1] = pix ^ 0xAAAAAAAAAAAAAAAAULL; // Introduce independent data variation

    for (i = 0; i < (2 * size); i += 8) { // Double step to allow two writes without dependency
        if (i + 4 < 2 * size) {
            (((union unaligned_64 *)(left + i + 0))->l) = local_pix[0]; // No loop-carried dependency
            (((union unaligned_64 *)(left + i + 4))->l) = local_pix[1]; // Independent store, breaks WAW/RAW across iterations
        }
    }
}
