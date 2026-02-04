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
    const uint32_t a_start = (((const union unaligned_32 *)(pixels))->l);
    const uint32_t b_start = (((const union unaligned_32 *)(pixels + 1))->l);
    uint32_t prev_l = (a_start & 50529027UL) + (b_start & 50529027UL) + 33686018UL;
    uint32_t prev_h = ((a_start & 4244438268UL) >> 2) + ((b_start & 4244438268UL) >> 2);
    pixels += line_size;
    uint32_t speculative_l = prev_l, speculative_h = prev_h;
    for (i = 0; i < h; i += 2) {
        uint32_t a1 = (((const union unaligned_32 *)(pixels))->l);
        uint32_t b1 = (((const union unaligned_32 *)(pixels + 1))->l);
        uint32_t curr_l = (a1 & 50529027UL) + (b1 & 50529027UL);
        uint32_t curr_h = ((a1 & 4244438268UL) >> 2) + ((b1 & 4244438268UL) >> 2);
        uint32_t combined_l_shifted = ((speculative_l + curr_l) >> 2) & 252645135UL;
        uint32_t output1 = speculative_h + curr_h + combined_l_shifted;
        *((uint32_t *)block) = output1;
        pixels += line_size;
        block += line_size;
        uint32_t a2 = (((const union unaligned_32 *)(pixels))->l);
        uint32_t b2 = (((const union unaligned_32 *)(pixels + 1))->l);
        speculative_l = (a2 & 50529027UL) + (b2 & 50529027UL) + 33686018UL;
        speculative_h = ((a2 & 4244438268UL) >> 2) + ((b2 & 4244438268UL) >> 2);
        uint32_t output2 = speculative_h + curr_h + combined_l_shifted;
        *((uint32_t *)block) = output2;
        pixels += line_size;
        block += line_size;
    }
    pixels += 4 - line_size * (h + 1);
    block += 4 - line_size * h;
}
}
