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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with loop unrolling and sequential pixel loading
    uint8_t *p = pixels;
    uint8_t *b = block;
    int i;
    for (i = 0; i < h; i++) {
        // Unroll two iterations and access pixels consecutively in wider chunks
        const union unaligned_32 *px0 = (const union unaligned_32 *)(p);
        const union unaligned_32 *px1 = (const union unaligned_32 *)(p + 4);
        ((union unaligned_32 *)b)->l = px0->l;
        ((union unaligned_32 *)(b + 4))->l = px1->l;
        
        p += line_size;
        b += line_size;
    }
}
