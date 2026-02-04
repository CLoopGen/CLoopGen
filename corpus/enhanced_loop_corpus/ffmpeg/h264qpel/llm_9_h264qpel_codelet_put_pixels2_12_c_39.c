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
    if (h > 0) {
        *((uint32_t *)block) = (((const union unaligned_32 *)(pixels))->l);
        if (h % 2 == 1) {
            pixels += line_size;
            block += line_size;
        }
        for (i = h % 2; i < h; i += 2) {
            uint32_t val1 = ((const union unaligned_32 *)(pixels))->l;
            uint32_t val2 = ((const union unaligned_32 *)(pixels + line_size))->l;
            *((uint32_t *)block) = val1 ^ val2; // Additional arithmetic: XOR blend
            pixels += 2 * line_size;
            block += 2 * line_size;
        }
    }
}
