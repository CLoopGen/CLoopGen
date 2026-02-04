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
for (i = 0; i < h; i++) {
    uint8_t *p = pixels;
    uint8_t *b = block;
    *((uint32_t *)b) = (((const union unaligned_32 *)(p))->l);
    *((uint32_t *)(b + 4)) = (((const union unaligned_32 *)(p + 4))->l);
    *((uint32_t *)(b + 8)) = (((const union unaligned_32 *)(p + 8))->l);
    *((uint32_t *)(b + 12)) = (((const union unaligned_32 *)(p + 12))->l);
    pixels += line_size;
    block += line_size;
}
}
