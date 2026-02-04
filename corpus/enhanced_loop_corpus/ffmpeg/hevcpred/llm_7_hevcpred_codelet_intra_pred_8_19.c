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
    uint32_t local_pix[8]; // Introduce multiple independent accumulators to remove WAW dependencies
    int j;
    for (j = 0; j < 8; ++j) {
        local_pix[j] = pix ^ (j * 0x1F); // Initialize independent values
    }
    for (i = 0; i < (size); i += 4) {
        int idx = (i / 4) % 8;
        (((union unaligned_32 *)(left + size + i))->l) = local_pix[idx]; // No loop-carried dependency
    }
}
