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
for (y = 0; y < b_h; y++) {
    if (y < b_h / 2) {
        *(uint32_t *)&dst[0 + y * stride] = color4;
    } else {
        *(uint32_t *)&dst[8 + y * stride] = color4;
        continue;
    }
    *(uint32_t *)&dst[4 + y * stride] = color4;
}
}
