#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};


extern int i;
extern uint8_t *left;
extern int size_max_y;
extern uint32_t pix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t local_pix[4]; // Remove loop-carried dependency by using independent local copies
    for (int j = 0; j < 4; ++j) {
        local_pix[j] = pix + (j << 2); // Initialize with data-independent variation
    }
    for (i = 0; i < (size_max_y); i += 4) {
        int index = (i >> 2) & 3; // Cycle through local_pix in a data-independent way
        ((((union unaligned_32 *)(left + i))->l) = local_pix[index]);
    }
}
