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
    // Variant 2: Consecutive 32-bit writes using byte offset progression with full 4-byte coverage
    for (i = 0; i < (2 * size); i += 4) {
        ((union unaligned_32 *)(left + i))->l = pix;
        // Ensure all 4 bytes are touched consecutively (redundant but emphasizes byte-level consecutive access)
        left[i]     = (uint8_t)(pix >> 0);
        left[i + 1] = (uint8_t)(pix >> 8);
        left[i + 2] = (uint8_t)(pix >> 16);
        left[i + 3] = (uint8_t)(pix >> 24);
    }
}
