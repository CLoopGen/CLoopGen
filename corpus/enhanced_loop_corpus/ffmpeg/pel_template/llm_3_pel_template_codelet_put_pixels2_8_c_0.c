#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_16 {
    uint16_t l;
};


extern uint8_t *block;
extern  uint8_t *pixels;
extern ptrdiff_t line_size;
extern int h;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
ptrdiff_t step = 2;
for (i = 0; i < h; i += step) {
    if (i + 1 < h) {
        *((uint16_t *)block) = (((const union unaligned_16 *)(pixels))->l);
        pixels += line_size;
        block += line_size;
        *((uint16_t *)block) = (((const union unaligned_16 *)(pixels))->l);
        pixels += line_size;
        block += line_size;
    } else {
        *((uint16_t *)block) = (((const union unaligned_16 *)(pixels))->l);
        pixels += line_size;
        block += line_size;
    }
}
}
