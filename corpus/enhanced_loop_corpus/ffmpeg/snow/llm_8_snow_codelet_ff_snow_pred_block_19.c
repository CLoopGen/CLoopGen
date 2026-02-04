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
    for (y = 0; y < b_h; y += 2) {
        if (y + 1 < b_h) {
            // Process two rows per iteration to increase computational intensity
            *(uint32_t *)&dst[0  + y * stride] = color4;
            *(uint32_t *)&dst[4  + y * stride] = color4;
            *(uint32_t *)&dst[8  + y * stride] = color4;
            *(uint32_t *)&dst[12 + y * stride] = color4;
            *(uint32_t *)&dst[16 + y * stride] = color4;
            *(uint32_t *)&dst[20 + y * stride] = color4;
            *(uint32_t *)&dst[24 + y * stride] = color4;
            *(uint32_t *)&dst[28 + y * stride] = color4;

            *(uint32_t *)&dst[0  + (y+1) * stride] = color4;
            *(uint32_t *)&dst[4  + (y+1) * stride] = color4;
            *(uint32_t *)&dst[8  + (y+1) * stride] = color4;
            *(uint32_t *)&dst[12 + (y+1) * stride] = color4;
            *(uint32_t *)&dst[16 + (y+1) * stride] = color4;
            *(uint32_t *)&dst[20 + (y+1) * stride] = color4;
            *(uint32_t *)&dst[24 + (y+1) * stride] = color4;
            *(uint32_t *)&dst[28 + (y+1) * stride] = color4;
        } else {
            // Handle odd b_h: last row if exists
            *(uint32_t *)&dst[0  + y * stride] = color4;
            *(uint32_t *)&dst[4  + y * stride] = color4;
            *(uint32_t *)&dst[8  + y * stride] = color4;
            *(uint32_t *)&dst[12 + y * stride] = color4;
            *(uint32_t *)&dst[16 + y * stride] = color4;
            *(uint32_t *)&dst[20 + y * stride] = color4;
            *(uint32_t *)&dst[24 + y * stride] = color4;
            *(uint32_t *)&dst[28 + y * stride] = color4;
        }
    }
}
