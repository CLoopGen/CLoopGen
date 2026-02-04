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
    uint32_t a0 = (((const union unaligned_32 *)(pixels))->l);
    uint32_t b0 = (((const union unaligned_32 *)(pixels + 1))->l);
    uint32_t a1 = (((const union unaligned_32 *)(pixels + line_size))->l);
    uint32_t b1 = (((const union unaligned_32 *)(pixels + line_size + 1))->l);

    l1 = (a0 & 50529027UL) + (b0 & 50529027UL);
    h1 = ((a0 & 4244438268UL) >> 2) + ((b0 & 4244438268UL) >> 2);
    l0 = (a1 & 50529027UL) + (b1 & 50529027UL) + 33686018UL;
    h0 = ((a1 & 4244438268UL) >> 2) + ((b1 & 4244438268UL) >> 2);

    *((uint32_t *)block) = h0 + h1 + (((l0 + l1) >> 2) & 252645135UL);
    *((uint32_t *)(block + line_size)) = h0 + h1 + (((l0 + l1) >> 2) & 252645135UL);

    pixels += 2 * line_size;
    block += 2 * line_size;
}
}
