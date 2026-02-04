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
        if (y % 2 == 0) {
            *(uint32_t *)&dst[0 + y * stride] = color4;
        } else {
            continue;
        }
    }
}
