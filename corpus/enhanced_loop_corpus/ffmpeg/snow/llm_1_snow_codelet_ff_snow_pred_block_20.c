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
    for (int z = 0; z < b_h * 4; z++) {
        int y = z / 4;
        int offset = (z % 4) * 4;
        *(uint32_t *)&dst[offset + y * stride] = color4;
    }
}
