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
for (i = 0; i < h; i++) {
    *((uint16_t *)block) = (((const union unaligned_16 *)(pixels))->l);
    if (i % 2 == 0) {
        pixels += line_size;
        block += line_size;
    } else {
        pixels += line_size + 1;
        block += line_size + 1;
    }
}
}
