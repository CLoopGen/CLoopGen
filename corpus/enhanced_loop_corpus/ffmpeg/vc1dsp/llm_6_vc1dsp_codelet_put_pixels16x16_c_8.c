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
    for (i = 0; i < 16; i++) {
        uint32_t temp1 = ((const union unaligned_32 *)(p))->l;
        uint32_t temp2 = ((const union unaligned_32 *)(p + 4))->l;
        uint32_t temp3 = ((const union unaligned_32 *)(p + 8))->l;
        uint32_t temp4 = ((const union unaligned_32 *)(p + 12))->l;

        ((union unaligned_32 *)b)->l = temp1;
        ((union unaligned_32 *)(b + 4))->l = temp2;
        ((union unaligned_32 *)(b + 8))->l = temp3;
        ((union unaligned_32 *)(b + 12))->l = temp4;

        p += line_size;
        b += line_size;
    }
}
