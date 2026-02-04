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
    const uint32_t a_init = (((const union unaligned_32 *)(pixels))->l);
    const uint32_t b_init = (((const union unaligned_32 *)(pixels + 1))->l);
    uint32_t l0 = (a_init & 50529027UL) + (b_init & 50529027UL) + 16843009UL;
    uint32_t h0 = ((a_init & 4244438268UL) >> 2) + ((b_init & 4244438268UL) >> 2);
    pixels += line_size;
    for (i = 0; i < h; i += 2) {
        uint32_t a = (((const union unaligned_32 *)(pixels))->l);
        uint32_t b = (((const union unaligned_32 *)(pixels + 1))->l);
        uint32_t l1 = (a & 50529027UL) + (b & 50529027UL);
        uint32_t h1 = ((a & 4244438268UL) >> 2) + ((b & 4244438268UL) >> 2);
        uint32_t result1 = h0 + h1 + (((l0 + l1) >> 2) & 252645135UL);
        pixels += line_size;
        block += line_size;
        a = (((const union unaligned_32 *)(pixels))->l);
        b = (((const union unaligned_32 *)(pixels + 1))->l);
        uint32_t l0_next = (a & 50529027UL) + (b & 50529027UL) + 16843009UL;
        uint32_t h0_next = ((a & 4244438268UL) >> 2) + ((b & 4244438268UL) >> 2);
        uint32_t result2 = h0_next + h1 + (((l0_next + l1) >> 2) & 252645135UL);
        *((uint32_t *)block) = result2;
        pixels += line_size;
        block += line_size;
        l0 = l0_next;
        h0 = h0_next;
        *((uint32_t *)(block - line_size)) = result1;
    }
    pixels += 4 - line_size * (h + 1);
    block += 4 - line_size * h;
}
}
