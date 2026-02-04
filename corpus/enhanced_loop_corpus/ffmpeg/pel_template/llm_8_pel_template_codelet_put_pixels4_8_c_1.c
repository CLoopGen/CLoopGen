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
        if (i + 1 < h) {
            ((uint32_t *)block)[0] = ((const union unaligned_32 *)(pixels))->l;
            ((uint32_t *)block)[1] = ((const union unaligned_32 *)(pixels + line_size))->l;
            pixels += 2 * line_size;
            block += 2 * line_size;
        } else {
            ((uint32_t *)block)[0] = ((const union unaligned_32 *)(pixels))->l;
            pixels += line_size;
            block += line_size;
        }
    }
}
