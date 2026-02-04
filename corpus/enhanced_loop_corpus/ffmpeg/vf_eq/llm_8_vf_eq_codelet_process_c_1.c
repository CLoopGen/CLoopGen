#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int dst_stride;
extern  uint8_t *src;
extern int src_stride;
extern int w;
extern int h;
extern int x;
extern int y;
extern int pel;
extern int contrast;
extern int brightness;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < h; y++) {
    for (x = 0; x < w; x += 2) {
        int idx1 = y * src_stride + x;
        int idx2 = (x + 1 < w) ? idx1 + 1 : idx1;
        int pel1 = ((src[idx1] * contrast) >> 12) + brightness;
        int pel2 = ((src[idx2] * contrast) >> 12) + brightness;
        pel1 = (pel1 & ~255) ? ((-pel1) >> 31) : pel1;
        pel2 = (pel2 & ~255) ? ((-pel2) >> 31) : pel2;
        dst[idx1] = pel1;
        if (x + 1 < w) dst[idx2] = pel2;
    }
}
}
