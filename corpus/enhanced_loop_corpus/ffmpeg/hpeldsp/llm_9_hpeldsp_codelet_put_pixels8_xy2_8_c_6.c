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
for (j = 0; j < 1; j++) {
    int i, k;
    const uint32_t a_init = (((const union unaligned_32 *)(pixels))->l);
    const uint32_t b_init = (((const union unaligned_32 *)(pixels + 1))->l);
    uint32_t l0 = (a_init & 50529027UL) + (b_init & 50529027UL) + 33686018UL;
    uint32_t h0 = ((a_init & 4244438268UL) >> 2) + ((b_init & 4244438268UL) >> 2);
    pixels += line_size;
    for (i = 0; i < h; i += 4) {
        for (k = 0; k < 4 && (i + k) < h; k++) {
            uint32_t a = (((const union unaligned_32 *)(pixels + k * line_size))->l);
            uint32_t b = (((const union unaligned_32 *)(pixels + k * line_size + 1))->l);
            uint32_t l1 = (a & 50529027UL) + (b & 50529027UL);
            uint32_t h1 = ((a & 4244438268UL) >> 2) + ((b & 4244438268UL) >> 2);
            *((uint32_t *)(block + k * line_size)) = h0 + h1 + (((l0 + l1) >> 2) & 252645135UL);
        }
        pixels += 4 * line_size;
        block += 4 * line_size;
        if (i + 4 < h) {
            uint32_t a = (((const union unaligned_32 *)(pixels))->l);
            uint32_t b = (((const union unaligned_32 *)(pixels + 1))->l);
            l0 = (a & 50529027UL) + (b & 50529027UL) + 33686018UL;
            h0 = ((a & 4244438268UL) >> 2) + ((b & 4244438268UL) >> 2);
        }
    }
    pixels += 4 - line_size * h;
    block += 4 - line_size * h;
}
}
