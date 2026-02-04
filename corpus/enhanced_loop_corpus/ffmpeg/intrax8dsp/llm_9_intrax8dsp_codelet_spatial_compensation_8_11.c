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
for (y = 0; y < 4; y++) {
    for (x = 0; x < 4; x++) {
        dst[x*2] = (src[(0) + 7 - y*2] + src[(8) + 7 - y*2] + 1) >> 1;
        dst[x*2+1] = (src[(0) + 7 - y*2 - 1] + src[(8) + 7 - y*2 - 1] + 1) >> 1;
    }
    dst += stride * 2;
}
}
