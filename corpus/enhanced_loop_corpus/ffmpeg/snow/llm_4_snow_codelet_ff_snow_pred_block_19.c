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
    if (b_h <= 0) return;
    for (y = 0; y < b_h; y++) {
        uint8_t *row = &dst[y * stride];
        *(uint32_t *)(row + 0) = color4;
        *(uint32_t *)(row + 4) = color4;
        *(uint32_t *)(row + 8) = color4;
        *(uint32_t *)(row + 12) = color4;
        *(uint32_t *)(row + 16) = color4;
        *(uint32_t *)(row + 20) = color4;
        *(uint32_t *)(row + 24) = color4;
        *(uint32_t *)(row + 28) = color4;
    }
}
