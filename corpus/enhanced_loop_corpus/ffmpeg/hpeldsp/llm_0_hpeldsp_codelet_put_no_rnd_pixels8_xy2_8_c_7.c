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
        uint32_t a, b, l1, h1;

        // First iteration of original inner logic
        a = (((const union unaligned_32 *)(pixels))->l);
        b = (((const union unaligned_32 *)(pixels + 1))->l);
        l1 = (a & 50529027UL) + (b & 50529027UL);
        h1 = ((a & 4244438268UL) >> 2) + ((b & 4244438268UL) >> 2);
        *((uint32_t *)block) = h0 + h1 + (((l0 + l1) >> 2) & 252645135UL);
        pixels += line_size;
        block += line_size;

        // Second part unrolled into same loop body
        if (i + 2 <= h) {
            a = (((const union unaligned_32 *)(pixels))->l);
            b = (((const union unaligned_32 *)(pixels + 1))->l);
            uint32_t next_l0 = (a & 50529027UL) + (b & 50529027UL) + 16843009UL;
            uint32_t next_h0 = ((a & 4244438268UL) >> 2) + ((b & 4244438268UL) >> 2);
            *((uint32_t *)block) = next_h0 + h1 + (((next_l0 + l1) >> 2) & 252645135UL);
            pixels += line_size;
            block += line_size;

            // Update for next outer iteration
            l0 = next_l0;
            h0 = next_h0;
        }
    }
    pixels += 4 - line_size * (h + 1);
    block += 4 - line_size * h;
}
}
