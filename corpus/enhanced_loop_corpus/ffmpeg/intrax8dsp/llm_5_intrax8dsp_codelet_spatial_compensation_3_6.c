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
        for (x = 0; x < 8; x++) {
            if (x < 4) {
                dst[x] = src[(8 + 8 + 1) + ((y + 1) >> 1) + x];
            } else {
                dst[x] = src[(8 + 8 + 1) + ((y + 1) >> 1) + (7 - x)];
            }
        }
        dst += stride;
    }
}
