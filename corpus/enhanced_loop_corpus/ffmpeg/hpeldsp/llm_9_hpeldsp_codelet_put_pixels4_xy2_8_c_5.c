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
extern int i;
extern uint32_t l0;
extern uint32_t h0;
extern uint32_t l1;
extern uint32_t h1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h; i += 2) {
    const uint32_t mask_low = 50529027UL;
    const uint32_t mask_high = 4244438268UL;
    const uint32_t shift = 2;
    const uint32_t result_mask = 252645135UL;
    const uint32_t offset = 33686018UL;

    uint32_t a = ((const union unaligned_32 *)(pixels))->l;
    uint32_t b = ((const union unaligned_32 *)(pixels + 1))->l;

    uint32_t al = a & mask_low;
    uint32_t ah = (a & mask_high) >> shift;
    uint32_t bl = b & mask_low;
    uint32_t bh = (b & mask_high) >> shift;

    l1 = al + bl;
    h1 = ah + bh;

    uint32_t sum_l = (l0 + l1) >> shift;
    uint32_t result = h0 + h1 + (sum_l & result_mask);

    *((uint32_t *)block) = result;

    pixels += line_size;
    block += line_size;

    a = ((const union unaligned_32 *)(pixels))->l;
    b = ((const union unaligned_32 *)(pixels + 1))->l;

    al = a & mask_low;
    ah = (a & mask_high) >> shift;
    bl = b & mask_low;
    bh = (b & mask_high) >> shift;

    l0 = al + bl + offset;
    h0 = ah + bh;

    sum_l = (l0 + l1) >> shift;
    result = h0 + h1 + (sum_l & result_mask);

    *((uint32_t *)block) = result;

    pixels += line_size;
    block += line_size;
}
}
