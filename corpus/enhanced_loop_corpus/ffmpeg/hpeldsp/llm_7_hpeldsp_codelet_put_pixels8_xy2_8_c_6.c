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
    uint32_t l_prev = (a_start & 50529027UL) + (b_start & 50529027UL) + 33686018UL;
    uint32_t h_prev = ((a_start & 4244438268UL) >> 2) + ((b_start & 4244438268UL) >> 2);
    pixels += line_size;
    uint32_t temp_buffer[2] = {0}; 
    for (i = 0; i < h; i += 2) {
        uint32_t a1 = (((const union unaligned_32 *)(pixels))->l);
        uint32_t b1 = (((const union unaligned_32 *)(pixels + 1))->l);
        uint32_t l_curr1 = (a1 & 50529027UL) + (b1 & 50529027UL);
        uint32_t h_curr1 = ((a1 & 4244438268UL) >> 2) + ((b1 & 4244438268UL) >> 2);
        pixels += line_size;
        uint32_t a2 = (((const union unaligned_32 *)(pixels))->l);
        uint32_t b2 = (((const union unaligned_32 *)(pixels + 1))->l);
        uint32_t l_curr2 = (a2 & 50529027UL) + (b2 & 50529027UL) + 33686018UL;
        uint32_t h_curr2 = ((a2 & 4244438268UL) >> 2) + ((b2 & 4244438268UL) >> 2);
        pixels += line_size;
        temp_buffer[0] = h_prev + h_curr1 + (((l_prev + l_curr1) >> 2) & 252645135UL);
        temp_buffer[1] = h_curr2 + h_curr1 + (((l_curr2 + l_curr1) >> 2) & 252645135UL);
        *((uint32_t *)block) = temp_buffer[0];
        block += line_size;
        *((uint32_t *)block) = temp_buffer[1];
        block += line_size;
        l_prev = l_curr2;
        h_prev = h_curr2;
    }
    pixels += 4 - line_size * (h + 1);
    block += 4 - line_size * h;
}
}
