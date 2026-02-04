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
    uint32_t a1 = (((const union unaligned_32 *)(pixels))->l);
    uint32_t b1 = (((const union unaligned_32 *)(pixels + 1))->l);
    l1 = (a1 & 50529027UL) + (b1 & 50529027UL);
    h1 = ((a1 & 4244438268UL) >> 2) + ((b1 & 4244438268UL) >> 2);
    
    uint32_t a2 = (((const union unaligned_32 *)(pixels + line_size))->l);
    uint32_t b2 = (((const union unaligned_32 *)(pixels + line_size + 1))->l);
    l0 = (a2 & 50529027UL) + (b2 & 50529027UL) + 33686018UL;
    h0 = ((a2 & 4244438268UL) >> 2) + ((b2 & 4244438268UL) >> 2);

    uint32_t temp1 = h0 + h1 + (((l0 + l1) >> 2) & 252645135UL);
    *((uint32_t *)block) = temp1;
    *((uint32_t *)(block + line_size)) = temp1;

    pixels += line_size * 2;
    block += line_size * 2;
}
}
