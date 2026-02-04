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
    uint8_t *local_block = block;
    uint8_t *local_pixels = pixels;
    for (i = 0; i < h; i++) {
        *((uint16_t *)local_block) = (((const union unaligned_16 *)(local_pixels))->l);
        local_pixels += line_size;
        local_block += line_size;
    }
    block = local_block;
    pixels = local_pixels;
}
