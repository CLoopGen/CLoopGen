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
    int i, k;
    const uint32_t a_start = (((const union unaligned_32 *)(pixels))->l);
    const uint32_t b_start = (((const union unaligned_32 *)(pixels + 1))->l);
    uint32_t prev_l = (a_start & 50529027UL) + (b_start & 50529027UL) + 16843009UL;
    uint32_t prev_h = ((a_start & 4244438268UL) >> 2) + ((b_start & 4244438268UL) >> 2);
    pixels += line_size;

    // Introduce deeper nesting: outer controls pair processing, inner handles individual steps
    for (i = 0; i < h; i += 4) {
        for (k = 0; k < 2 && (i + 2*k) < h; k++) {
            uint32_t a, b, l_curr, h_curr;

            a = (((const union unaligned_32 *)(pixels))->l);
            b = (((const union unaligned_32 *)(pixels + 1))->l);
            l_curr = (a & 50529027UL) + (b & 50529027UL);
            h_curr = ((a & 4244438268UL) >> 2) + ((b & 4244438268UL) >> 2);

            *((uint32_t *)block) = prev_h + h_curr + (((prev_l + l_curr) >> 2) & 252645135UL);
            pixels += line_size;
            block += line_size;

            if ((i + 2*k + 1) < h) {
                a = (((const union unaligned_32 *)(pixels))->l);
                b = (((const union unaligned_32 *)(pixels + 1))->l);
                prev_l = (a & 50529027UL) + (b & 50529027UL) + 16843009UL;
                prev_h = ((a & 4244438268UL) >> 2) + ((b & 4244438268UL) >> 2);
                *((uint32_t *)block) = prev_h + h_curr + (((prev_l + l_curr) >> 2) & 252645135UL);
                pixels += line_size;
                block += line_size;
            }
        }
    }
    pixels += 4 - line_size * (h + 1);
    block += 4 - line_size * h;
}
}
