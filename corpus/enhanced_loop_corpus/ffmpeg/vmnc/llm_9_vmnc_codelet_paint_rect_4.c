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
extern uint32_t *dst2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < h; j += 2) {
    uint8_t *dst_row = dst;
    for (i = 0; i < w; i++) {
        dst2 = (uint32_t *)dst_row;
        dst2[i] = color;
        if (j + 1 < h) {
            uint8_t *next_row = dst_row + stride;
            dst2 = (uint32_t *)next_row;
            dst2[i] = color;
        }
    }
    dst += 2 * stride;
}
}
