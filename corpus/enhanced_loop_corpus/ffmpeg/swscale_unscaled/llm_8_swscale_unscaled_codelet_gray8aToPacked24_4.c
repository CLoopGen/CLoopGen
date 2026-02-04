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
for (i = 0; i < num_pixels; i += 2) {
    int idx1 = src[i << 1] * 4;
    int idx2 = (i + 1 < num_pixels) ? src[(i + 1) << 1] * 4 : idx1;
    dst[0] = palette[idx1 + 0];
    dst[1] = palette[idx1 + 1];
    dst[2] = palette[idx1 + 2];
    dst += 3;
    if (i + 1 < num_pixels) {
        dst[0] = palette[idx2 + 0];
        dst[1] = palette[idx2 + 1];
        dst[2] = palette[idx2 + 2];
        dst += 3;
    }
}
}
