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
        uint8_t *p1 = pixels;
        uint8_t *p2 = pixels + line_size;
        uint32_t a = ((const union unaligned_32 *)(p1))->l;
        uint32_t b = ((const union unaligned_32 *)(p1 + 1))->l;
        uint32_t c = ((const union unaligned_32 *)(p2))->l;
        uint32_t d = ((const union unaligned_32 *)(p2 + 1))->l;

        l1 = (a & 50529027UL) + (b & 50529027UL);
        h1 = ((a & 4244438268UL) >> 2) + ((b & 4244438268UL) >> 2);

        *((uint32_t *)block) = h0 + h1 + (((l0 + l1) >> 2) & 252645135UL);
        
        block += line_size;

        l0 = (c & 50529027UL) + (d & 50529027UL) + 33686018UL;
        h0 = ((c & 4244438268UL) >> 2) + ((d & 4244438268UL) >> 2);

        *((uint32_t *)block) = h0 + h1 + (((l0 + l1) >> 2) & 252645135UL);

        pixels += 2 * line_size;
        block += line_size;
    }
}
