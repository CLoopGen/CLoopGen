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
for (i = 0; i < h * 2; i++) {
    int index = i / 2;
    uint8_t *current_pixel = pixels + index * line_size;
    uint8_t *current_block = block + index * line_size;
    *((uint16_t *)current_block) = (((const union unaligned_16 *)current_pixel)->l);
}
}
