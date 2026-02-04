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
extern int bottom_left_size;
extern uint32_t pix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access using a temporary pointer with incremental assignment
    uint32_t *ptr = (uint32_t *)(left + size + bottom_left_size);
    for (i = 0; i < (size - bottom_left_size); i += 4) {
        ptr[i / 4] = pix;
    }
}
