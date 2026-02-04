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
    for (y = 0; y < 16; y++) {
        int offset = (8 + 8 + 1) + 1 + y;
        for (x = 0; x < 4; x++) {
            dst[x] = src[offset + x * 2];
        }
        dst += stride / 2;
    }
}
