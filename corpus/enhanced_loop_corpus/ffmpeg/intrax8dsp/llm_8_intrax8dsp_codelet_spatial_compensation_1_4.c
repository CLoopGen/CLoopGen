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
for (y = 0; y < 16; y += 2) {
    for (x = 0; x < 8; x++) {
        int index = 2 * y + x + 3;
        if (index > 15) index = 15;
        dst[x] = src[17 + index];
    }
    dst += stride;
}
}
