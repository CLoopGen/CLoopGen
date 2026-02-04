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
    uint32_t a, b;

    a = (((const union unaligned_32 *)(pixels))->l);
    b = (((const union unaligned_32 *)(pixels + 1))->l);
    l1 = (a & 50529027UL) + (b & 50529027UL);
    h1 = ((a & 4244438268UL) >> 2) + ((b & 4244438268UL) >> 2);

    if (((l0 + l1) & 1)) {
        *((uint32_t *)block) = h0 + h1 + ((((l0 + l1) >> 2) & 252645135UL) ^ 16843009UL);
    } else {
        *((uint32_t *)block) = h0 + h1 + (((l0 + l1) >> 2) & 252645135UL);
    }

    pixels += line_size;
    block += line_size;

    if (i * 2 % 4 == 0) {
        a = (((const union unaligned_32 *)(pixels))->l);
        b = (((const union unaligned_32 *)(pixels + 1))->l);
        l0 = (a & 50529027UL) + (b & 50529027UL) + 33686018UL;
        h0 = ((a & 4244438268UL) >> 2) + ((b & 4244438268UL) >> 2);
        *((uint32_t *)block) = h0 + h1 + (((l0 + l1) >> 2) & 252645135UL);
    } else {
        l0 += 16843009UL;
        h0 += 1052688UL;
        *((uint32_t *)block) = h0 + h1;
    }

    pixels += line_size;
    block += line_size;
}
}
