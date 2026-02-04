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
    for (i = 0; i < h; i++) {
        if (i % 2 == 0) {
            *((uint64_t *)block) = (((const union unaligned_64 *)(pixels))->l);
        } else {
            pixels += line_size;
            continue;
        }
        *((uint64_t *)(block + 4 * sizeof(uint16_t))) = (((const union unaligned_64 *)(pixels + 4 * sizeof(uint16_t)))->l);
        block += line_size;
        pixels += line_size;
    }
}
