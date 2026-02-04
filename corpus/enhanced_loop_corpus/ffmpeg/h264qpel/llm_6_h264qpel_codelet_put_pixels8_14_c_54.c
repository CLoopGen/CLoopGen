#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
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
        uint64_t temp1 = ((const union unaligned_64 *)(local_pixels))->l;
        uint64_t temp2 = ((const union unaligned_64 *)(local_pixels + 8))->l;
        *((uint64_t *)local_block) = temp1;
        *((uint64_t *)(local_block + 8)) = temp2;
        local_pixels += line_size;
        local_block += line_size;
    }
}
