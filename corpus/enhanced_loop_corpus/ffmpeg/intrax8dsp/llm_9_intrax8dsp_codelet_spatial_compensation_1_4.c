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
        dst[x*2]     = src[17 + ((2*y + x + 2) < 16 ? (2*y + x + 2) : 15)];
        dst[x*2 + 1] = src[17 + ((2*y + x + 3) < 16 ? (2*y + x + 3) : 15)];
    }
    for (x = 0; x < 4; x++) {
        dst[stride/2 + x*2]     = src[17 + ((2*y + x + 4) < 16 ? (2*y + x + 4) : 15)];
        dst[stride/2 + x*2 + 1] = src[17 + ((2*y + x + 5) < 16 ? (2*y + x + 5) : 15)];
    }
    dst += stride * 2;
}
}
