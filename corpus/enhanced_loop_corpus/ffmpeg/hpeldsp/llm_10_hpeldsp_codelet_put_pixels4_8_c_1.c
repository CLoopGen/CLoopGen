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
    ptrdiff_t local_line_size = line_size;
    int local_h = h;
    for (i = 0; i < local_h; i++) {
        *((uint32_t *)local_block) = ((const union unaligned_32 *)(local_pixels))->l;
        local_pixels += local_line_size;
        local_block += local_line_size;
    }
    block = local_block;
    pixels = local_pixels - local_line_size * local_h;
}
