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
extern uint32_t l0;
extern uint32_t h0;
extern uint32_t l1;
extern uint32_t h1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h; i += 4) {
    uint32_t a = (((const union unaligned_32 *)(pixels))->l);
    uint32_t b = (((const union unaligned_32 *)(pixels + 1))->l);
    l1 = (a & 50529027UL) + (b & 50529027UL);
    h1 = ((a & 4244438268UL) >> 2) + ((b & 4244438268UL) >> 2);
    *((uint32_t *)block) = h0 + h1 + (((l0 + l1) >> 2) & 252645135UL);
    pixels += line_size;
    block += line_size;

    a = (((const union unaligned_32 *)(pixels))->l);
    b = (((const union unaligned_32 *)(pixels + 1))->l);
    l0 = (a & 50529027UL) + (b & 50529027UL) + 33686018UL;
    h0 = ((a & 4244438268UL) >> 2) + ((b & 4244438268UL) >> 2);
    *((uint32_t *)block) = h0 + h1 + (((l0 + l1) >> 2) & 252645135UL);
    pixels += line_size;
    block += line_size;

    if (i + 2 < h) {
        a = (((const union unaligned_32 *)(pixels))->l);
        b = (((const union unaligned_32 *)(pixels + 1))->l);
        uint32_t l2 = (a & 50529027UL) + (b & 50529027UL);
        uint32_t h2 = ((a & 4244438268UL) >> 2) + ((b & 4244438268UL) >> 2);
        *((uint32_t *)block) = h0 + h2 + (((l0 + l2) >> 2) & 252645135UL);
        pixels += line_size;
        block += line_size;

        a = (((const union unaligned_32 *)(pixels))->l);
        b = (((const union unaligned_32 *)(pixels + 1))->l);
        uint32_t l3 = (a & 50529027UL) + (b & 50529027UL) + 33686018UL;
        uint32_t h3 = ((a & 4244438268UL) >> 2) + ((b & 4244438268UL) >> 2);
        *((uint32_t *)block) = h3 + h2 + (((l3 + l2) >> 2) & 252645135UL);
        pixels += line_size;
        block += line_size;
    }
}
}
