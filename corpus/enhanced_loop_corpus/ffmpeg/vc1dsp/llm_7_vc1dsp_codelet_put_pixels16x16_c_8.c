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
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t *p = pixels;
    uint8_t *b = block;
    uint32_t prev_value = 0;

    for (i = 0; i < 16; i++) {
        uint32_t val1 = ((const union unaligned_32 *)(p))->l ^ prev_value;
        uint32_t val2 = ((const union unaligned_32 *)(p + 4))->l;
        uint32_t val3 = ((const union unaligned_32 *)(p + 8))->l;
        uint32_t val4 = ((const union unaligned_32 *)(p + 12))->l;

        ((union unaligned_32 *)b)->l = val1;
        ((union unaligned_32 *)(b + 4))->l = val2;
        ((union unaligned_32 *)(b + 8))->l = val3;
        ((union unaligned_32 *)(b + 12))->l = val4;

        prev_value = val1; // Introduce loop-carried dependence (WAW and RAW)
        p += line_size;
        b += line_size;
    }
}
