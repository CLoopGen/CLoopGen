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
    for (i = 0; i < h; i++) {
        uint32_t temp1 = ((const union unaligned_32 *)(p))->l;
        uint32_t temp2 = ((const union unaligned_32 *)(p + 4))->l;
        *((uint32_t *)b) = temp1;
        *((uint32_t *)(b + 4)) = temp2;
        p += line_size;
        b += line_size;
    }
}
