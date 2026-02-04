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
    uint8_t *p = pixels;
    uint8_t *b = block;
    uint32_t prev_value = 0;
    for (i = 0; i < h; i++) {
        uint32_t curr = ((const union unaligned_32 *)(p))->l;
        *((uint32_t *)b) = curr ^ prev_value;
        *((uint32_t *)(b + 4)) = ((const union unaligned_32 *)(p + 4))->l;
        prev_value = curr;
        p += line_size;
        b += line_size;
    }
}
