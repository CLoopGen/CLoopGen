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
    for (int outer = 0; outer < h / 2; outer++) {
        for (int inner = 0; inner < 2; inner++) {
            int idx = outer * 2 + inner;
            if (idx >= h) break;
            *((uint32_t *)block) = (((const union unaligned_32 *)(pixels))->l);
            *((uint32_t *)(block + 4 * sizeof(uint8_t))) = (((const union unaligned_32 *)(pixels + 4 * sizeof(uint8_t)))->l);
            pixels += line_size;
            block += line_size;
        }
    }
}
