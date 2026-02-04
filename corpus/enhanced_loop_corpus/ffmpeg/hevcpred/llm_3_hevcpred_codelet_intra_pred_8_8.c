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
    // Variant 2: Strided memory access — write every 8 bytes instead of consecutive 4-byte blocks
    // This creates a strided pattern with stride of 2 (skip one 32-bit word each time)
    uint8_t *base = left + size + bottom_left_size;
    for (i = 0; i < (size - bottom_left_size); i += 8) {  // Step by 8 bytes → strided access
        (((union unaligned_32 *)(base + i))->l) = pix;
    }
}
