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
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t *temp_block = block;
    uint8_t *temp_pixels = pixels;
    uint32_t prev_value = 0;
    for (i = 0; i < 8; i++) {
        uint32_t current = ((const union unaligned_32 *)temp_pixels)->l;
        ((union unaligned_32 *)temp_block)->l = current ^ prev_value;
        ((union unaligned_32 *)(temp_block + 4))->l = ((const union unaligned_32 *)(temp_pixels + 4))->l;
        prev_value = current;
        temp_pixels += line_size;
        temp_block += line_size;
    }
}
