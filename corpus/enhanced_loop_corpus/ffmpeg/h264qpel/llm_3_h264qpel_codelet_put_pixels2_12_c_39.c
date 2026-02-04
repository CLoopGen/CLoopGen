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
    uint8_t *p = pixels + i;
    uint8_t *b = block + i;
    for (int j = 0; j < h; j++) {
        *((uint32_t *)b) = (((const union unaligned_32 *)(p + j * line_size))->l);
        b += line_size;
    }
    pixels += 1;
    block += 1;
}
}
