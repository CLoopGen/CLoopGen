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
    int index_src, index_dst;
    for (y = 0; y < h; y++) {
        index_src = y * src_stride;
        index_dst = y * dst_stride;
        for (x = 0; x < w; x++) {
            pel = ((src[index_src + x] * contrast) >> 12) + brightness;
            if (pel & ~255)
                pel = (-pel) >> 31;
            dst[index_dst + x] = pel;
        }
    }
}
