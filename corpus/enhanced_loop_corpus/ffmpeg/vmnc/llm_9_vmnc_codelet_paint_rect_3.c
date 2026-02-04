#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int w;
extern int h;
extern int color;
extern int stride;
extern int i;
extern int j;
extern uint16_t *dst2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < h; j += 2) {
    uint8_t *dst_row = dst;
    for (i = 0; i < w; i++) {
        ((uint16_t *)dst_row)[i] = color;
        if (j + 1 < h)
            ((uint16_t *)(dst_row + stride))[i] = color;
    }
    dst += 2 * stride;
}
}
