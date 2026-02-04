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
for (y = 0; y < h; y += 2) {
    for (x = 0; x < w; x++) {
        int valid_y = y;
        int idx = valid_y * src_stride + x;
        pel = ((src[idx] * contrast) >> 12) + brightness;
        pel = (pel & ~255) ? (-pel >> 31) : pel;
        dst[idx] = pel;
        if (y + 1 < h) {
            int idx2 = (y + 1) * src_stride + x;
            int pel2 = ((src[idx2] * contrast) >> 12) + brightness;
            pel2 = (pel2 & ~255) ? (-pel2 >> 31) : pel2;
            dst[idx2] = pel2;
        }
    }
}
}
