#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern uint8_t *dst;
extern int num_pixels;
extern  uint8_t *palette;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < num_pixels; i++) {
    if ((src[i] & 1) == 0) {
        dst[0] = palette[src[i] * 4 + 0];
        dst[1] = palette[src[i] * 4 + 1];
        dst[2] = palette[src[i] * 4 + 2];
    } else {
        dst[0] = 0;
        dst[1] = 0;
        dst[2] = 0;
    }
    dst += 3;
}
}
