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
        if (y < h) {
            pel = ((src[y * src_stride + x] * contrast) >> 12) + brightness;
            if (pel & ~255)
                pel = (-pel) >> 31;
            dst[y * dst_stride + x] = pel;
        }
        if (y + 1 < h) {
            pel = ((src[(y + 1) * src_stride + x] * contrast) >> 12) + brightness;
            if (pel & ~255)
                pel = (-pel) >> 31;
            dst[(y + 1) * dst_stride + x] = pel;
        }
    }
}
}
