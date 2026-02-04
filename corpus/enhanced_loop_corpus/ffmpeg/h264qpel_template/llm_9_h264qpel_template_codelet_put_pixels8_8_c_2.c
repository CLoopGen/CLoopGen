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
    uint8_t *p1 = pixels;
    uint8_t *p2 = pixels + 4;
    uint8_t *b1 = block;
    uint8_t *b2 = block + 4;
    *((uint32_t *)b1) = (((const union unaligned_32 *)p1)->l);
    *((uint32_t *)b2) = (((const union unaligned_32 *)p2)->l);
    pixels += line_size;
    block += line_size;
    // Additional arithmetic to increase computational intensity
    uintptr_t addr_xor = (uintptr_t)p1 ^ (uintptr_t)p2 ^ (uintptr_t)b1 ^ (uintptr_t)b2;
    addr_xor += (addr_xor >> 8);
    (void)addr_xor; // Prevent unused variable warning
}
}
