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
    // Variant 2: Consecutive byte-wise write instead of 32-bit unaligned write
    // Simulates a more sequential and fine-grained access pattern
    for (i = 0; i < (size_max_y); i += 4) {
        left[i]     = (uint8_t)(pix >> 0);
        left[i + 1] = (uint8_t)(pix >> 8);
        left[i + 2] = (uint8_t)(pix >> 16);
        left[i + 3] = (uint8_t)(pix >> 24);
    }
}
