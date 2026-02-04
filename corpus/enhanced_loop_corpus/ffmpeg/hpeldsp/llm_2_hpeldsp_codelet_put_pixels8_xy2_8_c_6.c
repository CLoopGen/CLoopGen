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
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < 2; j++) {
    int i;
    const uint32_t a = (((const union unaligned_32 *)(pixels))->l);
    const uint32_t b = (((const union unaligned_32 *)(pixels + 1))->l);
    uint32_t l0 = (a & 50529027UL) + (b & 50529027UL) + 33686018UL;
    uint32_t h0 = ((a & 4244438268UL) >> 2) + ((b & 4244438268UL) >> 2);
    uint32_t l1, h1;
    pixels += line_size;
    for (i = 0; i < h; i += 2) {
        uint32_t a_next = (((const union unaligned_32 *)(pixels))->l);
        uint32_t b_next = (((const union unaligned_32 *)(pixels + 1))->l);
        l1 = (a_next & 50529027UL) + (b_next & 50529027UL);
        h1 = ((a_next & 4244438268UL) >> 2) + ((b_next & 4244438268UL) >> 2);
        *((uint32_t *)block) = h0 + h1 + (((l0 + l1) >> 2) & 252645135UL);
        
        pixels += line_size;
        block += line_size;

        a_next = (((const union unaligned_32 *)(pixels))->l);
        b_next = (((const union unaligned_32 *)(pixels + 1))->l);
        l0 = (a_next & 50529027UL) + (b_next & 50529027UL) + 33686018UL;
        h0 = ((a_next & 4244438268UL) >> 2) + ((b_next & 4244438268UL) >> 2);
        *((uint32_t *)block) = h0 + h1 + (((l0 + l1) >> 2) & 252645135UL);

        pixels += line_size;
        block += line_size;
    }
    pixels += 4 - line_size * (h + 1);
    block += 4 - line_size * h;
}
}
