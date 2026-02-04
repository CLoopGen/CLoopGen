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
    uint8_t *temp_block = block;
    uint8_t *temp_pixels = pixels;
    uint64_t cache1, cache2;
    for (i = 0; i < h; i++) {
        cache1 = ((const union unaligned_64 *)(temp_pixels))->l;
        cache2 = ((const union unaligned_64 *)(temp_pixels + 8))->l;
        *((uint64_t *)temp_block) = cache1;
        *((uint64_t *)(temp_block + 8)) = cache2;
        temp_pixels += line_size;
        temp_block += line_size;
    }
}
