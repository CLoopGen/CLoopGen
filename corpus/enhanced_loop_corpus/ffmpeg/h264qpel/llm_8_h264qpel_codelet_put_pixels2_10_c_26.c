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
for (i = 0; i < h; i += 2) {
    *((uint32_t *)block) = (((const union unaligned_32 *)(pixels))->l);
    block += line_size;
    pixels += line_size;
    if (i + 1 < h) {
        *((uint32_t *)(block + line_size)) = (((const union unaligned_32 *)(pixels + line_size))->l);
    }
}
}
