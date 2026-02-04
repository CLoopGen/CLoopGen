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
    uint8_t *b1 = block;
    for (int j = 0; j < 8; j += 4) { // Consecutive 32-bit writes in a tight inner loop
        ((uint32_t*)(b1 + j))[0] = ((const union unaligned_32*)(p1 + j))->l;
    }
    pixels += line_size;
    block += line_size;
}
}
