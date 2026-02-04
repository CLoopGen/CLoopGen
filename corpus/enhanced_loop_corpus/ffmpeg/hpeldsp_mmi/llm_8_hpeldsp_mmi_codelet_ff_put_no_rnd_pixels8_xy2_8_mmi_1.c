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
    uint32_t l0 = (a & 50529027UL) + (b & 50529027UL) + 16843009UL;
    uint32_t h0 = ((a & 4244438268UL) >> 2) + ((b & 4244438268UL) >> 2);
    uint32_t l1, h1;
    pixels += line_size;
    for (i = 0; i < h; i += 4) {
        for (int k = 0; k < 2 && (i + 2*k) < h; k++) {
            uint32_t a1 = (((const union unaligned_32 *)(pixels))->l);
            uint32_t b1 = (((const union unaligned_32 *)(pixels + 1))->l);
            l1 = (a1 & 50529027UL) + (b1 & 50529027UL);
            h1 = ((a1 & 4244438268UL) >> 2) + ((b1 & 4244438268UL) >> 2);
            *((uint32_t *)block) = h0 + h1 + (((l0 + l1) >> 2) & 252645135UL);
            pixels += line_size;
            block += line_size;

            if (i + 2*k + 1 < h) {
                uint32_t a2 = (((const union unaligned_32 *)(pixels))->l);
                uint32_t b2 = (((const union unaligned_32 *)(pixels + 1))->l);
                uint32_t l2 = (a2 & 50529027UL) + (b2 & 50529027UL) + 16843009UL;
                uint32_t h2 = ((a2 & 4244438268UL) >> 2) + ((b2 & 4244438268UL) >> 2);
                *((uint32_t *)block) = h2 + h1 + (((l2 + l1) >> 2) & 252645135UL);
                pixels += line_size;
                block += line_size;
                l0 = l2; h0 = h2;
            }
        }
    }
    pixels += 4 - line_size * (h + 1);
    block += 4 - line_size * h;
}
}
