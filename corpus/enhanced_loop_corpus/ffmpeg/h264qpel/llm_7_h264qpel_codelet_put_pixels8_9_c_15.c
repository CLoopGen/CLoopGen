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
    uint8_t *p = pixels;
    uint8_t *b = block;
    uint64_t prev_temp = 0;
    for (i = 0; i < h; i++) {
        uint64_t temp1 = ((const union unaligned_64 *)(p))->l ^ prev_temp;
        uint64_t temp2 = ((const union unaligned_64 *)(p + 4 * sizeof(uint16_t)))->l;
        *((uint64_t *)b) = temp1;
        *((uint64_t *)(b + 4 * sizeof(uint16_t))) = temp2;
        prev_temp = temp1;
        p += line_size;
        b += line_size;
    }
}
