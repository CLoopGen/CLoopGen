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
    for (y = 0; y < 8; ++y) {
        if (y != 4) {
            for (x = 0; x < 8; ++x) {
                dst[x] = (src[17 + x] + src[33 + x] + 1) >> 1;
            }
        } else {
            for (x = 0; x < 8; ++x) {
                dst[x] = src[17 + x];
            }
        }
        dst += stride;
    }
}
