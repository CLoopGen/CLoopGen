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
    uint32_t temp1, temp2;
    for (i = 0; i < h; i++) {
        temp1 = ((const union unaligned_32 *)(pixels))->l;
        temp2 = ((const union unaligned_32 *)(pixels + 4))->l;
        *((uint32_t *)block) = temp1;
        *((uint32_t *)(block + 4)) = temp2;
        pixels += line_size;
        block += line_size;
    }
}
