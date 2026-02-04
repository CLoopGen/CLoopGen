#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
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
            int i = outer * 2 + inner;
            *((uint64_t *)block) = (((const union unaligned_64 *)(pixels))->l);
            *((uint64_t *)(block + 4 * sizeof(uint16_t))) = (((const union unaligned_64 *)(pixels + 4 * sizeof(uint16_t)))->l);
            pixels += line_size;
            block += line_size;
        }
    }
    if (h % 2 != 0) {
        int i = h - 1;
        *((uint64_t *)block) = (((const union unaligned_64 *)(pixels))->l);
        *((uint64_t *)(block + 4 * sizeof(uint16_t))) = (((const union unaligned_64 *)(pixels + 4 * sizeof(uint16_t)))->l);
    }
}
