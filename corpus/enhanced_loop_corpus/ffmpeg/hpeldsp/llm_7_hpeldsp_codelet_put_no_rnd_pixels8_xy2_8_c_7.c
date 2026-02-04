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
    uint32_t prev_l = 0, prev_h = 0;
    for (i = 0; i < h + 1; i++) {
        uint32_t a = (((const union unaligned_32 *)(pixels))->l);
        uint32_t b = (((const union unaligned_32 *)(pixels + 1))->l);
        uint32_t l_curr = (a & 50529027UL) + (b & 50529027UL);
        uint32_t h_curr = ((a & 4244438268UL) >> 2) + ((b & 4244438268UL) >> 2);
        if (i > 0) {
            uint32_t combined_l = (prev_l + l_curr + 16843009UL);
            uint32_t avg_l = (combined_l >> 2) & 252645135UL;
            *((uint32_t *)block) = prev_h + h_curr + avg_l;
            block += line_size;
        }
        prev_l = l_curr;
        prev_h = h_curr;
        pixels += line_size;
    }
    pixels += 4 - line_size * (h + 1);
    block += 4 - line_size * h;
}
}
