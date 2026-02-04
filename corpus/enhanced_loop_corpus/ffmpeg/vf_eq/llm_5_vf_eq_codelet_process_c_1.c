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
    for (x = 0; x < w; x++) {
        int src_val = src[y * src_stride + x];
        pel = (src_val * contrast) >> 12;
        pel += brightness;

        if (pel >= 0 && pel <= 255) {
            dst[y * dst_stride + x] = pel;
        } else if (pel < 0) {
            dst[y * dst_stride + x] = 0;
        } else {
            dst[y * dst_stride + x] = 255;
        }
    }
}
}
