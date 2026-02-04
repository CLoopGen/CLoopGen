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
        uint32_t a_curr = (((const union unaligned_32 *)(pixels))->l);
        uint32_t b_curr = (((const union unaligned_32 *)(pixels + 1))->l);
        uint32_t l1 = (a_curr & 50529027UL) + (b_curr & 50529027UL);
        uint32_t h1 = ((a_curr & 4244438268UL) >> 2) + ((b_curr & 4244438268UL) >> 2);
        uint32_t temp_sum = h0 + h1 + (((l0 + l1) >> 2) & 252645135UL);
        *((uint32_t *)block) = temp_sum;
        pixels += line_size;
        block += line_size;
        uint32_t a_next = (((const union unaligned_32 *)(pixels))->l);
        uint32_t b_next = (((const union unaligned_32 *)(pixels + 1))->l);
        uint32_t l0_new = (a_next & 50529027UL) + (b_next & 50529027UL) + 16843009UL;
        uint32_t h0_new = ((a_next & 4244438268UL) >> 2) + ((b_next & 4244438268UL) >> 2);
        *((uint32_t *)block) = h0_new + h1 + (((l0_new + l1) >> 2) & 252645135UL);
        pixels += line_size;
        block += line_size;
        l0 = l0_new;
        h0 = h0_new;
    }
    pixels += 4 - line_size * (h + 1);
    block += 4 - line_size * h;
}
}
