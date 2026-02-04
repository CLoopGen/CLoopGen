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
for (int outer = 0; outer < b_h; outer += 8) {
    for (int inner = 0; inner < 8; inner++) {
        y = outer + inner;
        if (y >= b_h) break;
        *(uint32_t *)&dst[0 + y * stride] = color4;
        *(uint32_t *)&dst[4 + y * stride] = color4;
        *(uint32_t *)&dst[8 + y * stride] = color4;
        *(uint32_t *)&dst[12 + y * stride] = color4;
        *(uint32_t *)&dst[16 + y * stride] = color4;
        *(uint32_t *)&dst[20 + y * stride] = color4;
        *(uint32_t *)&dst[24 + y * stride] = color4;
        *(uint32_t *)&dst[28 + y * stride] = color4;
    }
}
}
