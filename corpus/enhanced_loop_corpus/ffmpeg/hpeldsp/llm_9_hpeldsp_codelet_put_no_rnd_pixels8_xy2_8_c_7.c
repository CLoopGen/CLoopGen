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
    int i;
    uint32_t prev_l = 0, prev_h = 0;
    for (i = 0; i < h; i++) {
        const uint32_t a = (((const union unaligned_32 *)(pixels + i * line_size))->l);
        const uint32_t b = (((const union unaligned_32 *)(pixels + i * line_size + 1))->l);
        uint32_t l_curr = (a & 50529027UL) + (b & 50529027UL);
        uint32_t h_curr = ((a & 4244438268UL) >> 2) + ((b & 4244438268UL) >> 2);
        if (i > 0) {
            uint32_t combined_low = (prev_l + l_curr) >> 2;
            uint32_t output = prev_h + h_curr + (combined_low & 252645135UL);
            *((uint32_t *)(block + (i - 1) * line_size)) = output;
        }
        prev_l = l_curr + 16843009UL;
        prev_h = h_curr;
    }
    if (h > 0) {
        *((uint32_t *)(block + (h - 1) * line_size)) = prev_h + prev_h + ((prev_l >> 2) & 252645135UL);
    }
    block += line_size * h;
    pixels += 4;
}
}
