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
    uint32_t *base;
    for (y = 0; y < b_h; y++) {
        base = (uint32_t *)&dst[y * stride];
        base[0] = color4;
        base[1] = color4;
        base[2] = color4;
        base[3] = color4;
    }
}
