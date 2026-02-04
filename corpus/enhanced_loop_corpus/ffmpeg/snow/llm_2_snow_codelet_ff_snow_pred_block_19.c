#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t stride;
extern int b_h;
extern int y;
extern  unsigned int color4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by unrolling and reordering accesses to be sequential in memory
    uint8_t *base = dst;
    for (y = 0; y < b_h; y++) {
        uint8_t *row = &base[y * stride];
        for (int x = 0; x < 32; x += 4) {
            *(uint32_t *)&row[x] = color4;
        }
    }
}
