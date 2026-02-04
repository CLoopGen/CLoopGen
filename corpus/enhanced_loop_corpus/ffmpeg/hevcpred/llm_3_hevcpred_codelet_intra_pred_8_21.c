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
    // Variant 2: Consecutive memory access writing two aligned 32-bit stores in sequence
    for (i = 0; i < (2 * size); i += 8) {
        ((((union unaligned_32 *)(left + i + 0))->l) = (pix));
        ((((union unaligned_32 *)(left + i + 4))->l) = (pix));
    }
}
