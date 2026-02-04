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
    // Variant 2: Consecutive write of individual bytes instead of packed 32-bit write
    for (i = 0; i < (size); i += 4) {
        left[i]     = (uint8_t)(pix >> 0);
        left[i + 1] = (uint8_t)(pix >> 8);
        left[i + 2] = (uint8_t)(pix >> 16);
        left[i + 3] = (uint8_t)(pix >> 24);
    }
}
