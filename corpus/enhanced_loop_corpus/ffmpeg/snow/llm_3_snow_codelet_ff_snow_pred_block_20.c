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
    // Variant 2: Unrolled consecutive write per row using byte pointer with incremental addressing
    for (y = 0; y < b_h; y++) {
        uint8_t *row = &dst[y * stride];
        for (int x = 0; x < 16; x += 4) {
            *(uint32_t*)&row[x] = color4;
        }
    }
}
