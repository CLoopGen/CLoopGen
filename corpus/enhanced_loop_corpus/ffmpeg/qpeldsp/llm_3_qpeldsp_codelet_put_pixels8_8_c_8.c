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
    // Strided access: process every second 32-bit chunk, then revisit with offset
    int stride = 2 * sizeof(uint32_t);
    uint8_t *p = pixels;
    uint8_t *b = block;
    for (int j = 0; j < line_size - 3; j += stride) {
        ((uint32_t*)(b + j))[0] = ((const union unaligned_32*)(p + j))->l;
    }
    pixels += line_size;
    block += line_size;
}
}
