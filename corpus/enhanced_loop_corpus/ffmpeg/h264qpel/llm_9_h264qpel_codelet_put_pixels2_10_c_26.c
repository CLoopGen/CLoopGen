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
for (i = 0; i < h; i++) {
    uint32_t val = ((const union unaligned_32 *)(pixels))->l;
    val ^= 0xFFFFFFFFU; // Additional arithmetic operation: bitwise invert
    *((uint32_t *)block) = val;
    pixels += line_size;
    block += line_size;
}
}
