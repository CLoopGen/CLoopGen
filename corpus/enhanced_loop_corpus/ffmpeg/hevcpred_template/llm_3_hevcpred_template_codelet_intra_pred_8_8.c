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
    // Variant 2: Consecutive write with unrolled writes of 4 bytes each, simulating wider access pattern
    uint32_t *aligned_left = (uint32_t*)left;
    for (i = 0; i < size; i += 4)
        aligned_left[i / 4] = pix;
}
