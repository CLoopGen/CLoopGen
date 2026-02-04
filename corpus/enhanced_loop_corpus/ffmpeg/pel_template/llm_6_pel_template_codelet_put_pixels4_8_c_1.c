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
    uint8_t *local_block = block;
    uint8_t *local_pixels = pixels;
    for (i = 0; i < h; i++) {
        uint32_t temp = ((const union unaligned_32 *)(local_pixels))->l;
        *((uint32_t *)local_block) = temp;
        local_pixels += line_size;
        local_block += line_size;
    }
    block = local_block;
    pixels = local_pixels;
}
