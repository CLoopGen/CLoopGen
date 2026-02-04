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
        int offset1 = y * stride;
        int offset2 = (y + 1) * stride;
        if (y + 1 < b_h) {
            *(uint32_t *)&dst[0 + offset1] = color4;
            *(uint32_t *)&dst[4 + offset1] = color4;
            *(uint32_t *)&dst[0 + offset2] = color4;
            *(uint32_t *)&dst[4 + offset2] = color4;
        } else {
            *(uint32_t *)&dst[0 + offset1] = color4;
            *(uint32_t *)&dst[4 + offset1] = color4;
        }
    }
}
