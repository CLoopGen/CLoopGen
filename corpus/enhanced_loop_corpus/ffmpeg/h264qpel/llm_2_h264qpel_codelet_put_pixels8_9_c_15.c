#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
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
        const union unaligned_64 *u0 = (const union unaligned_64 *)(p);
        const union unaligned_64 *u1 = (const union unaligned_64 *)(p + 8);
        ((union unaligned_64 *)b)->l = u0->l;
        ((union unaligned_64 *)(b + 8))->l = u1->l;
        p += line_size;
        b += line_size;
    }
}
