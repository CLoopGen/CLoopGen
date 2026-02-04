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
    // Variant 2: Strided memory access — traverse vertically first across rows for each column offset
    for (int x = 0; x < 32; x += 4) {
        for (y = 0; y < b_h; y++) {
            *(uint32_t *)&dst[x + y * stride] = color4;
        }
    }
}
