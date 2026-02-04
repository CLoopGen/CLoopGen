#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern uint8_t *dst;
extern ptrdiff_t stride;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = 0; y < 8; y++) {
        if (y % 2 == 0) {
            for (x = 0; x < 8; x++)
                dst[x] = (src[15 - y] * y + src[17 + x] * (8 - y) + 4) >> 3;
        } else {
            for (x = 0; x < 8; x++)
                dst[x] = (src[15 - y] * (y + 1) + src[17 + x] * (7 - y) + 4) >> 3;
        }
        dst += stride;
    }
}
