#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};


extern uint8_t *block;
extern  uint8_t *pixels;
extern ptrdiff_t line_size;
extern int h;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < h; i++) {
        uint32_t val = ((const union unaligned_32 *)(pixels))->l;
        val = (val << 8) | (val >> 24); // Simple byte swap-like operation to increase arithmetic intensity
        *((uint32_t *)block) = val;
        for (j = 1; j < 4; j++) { // Introduce inner computational loop
            val ^= (val << j) ^ (val >> (32 - j));
        }
        pixels += line_size;
        block += line_size;
    }
}
