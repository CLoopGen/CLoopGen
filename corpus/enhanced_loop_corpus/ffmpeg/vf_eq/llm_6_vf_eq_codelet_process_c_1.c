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
    uint8_t temp;
    for (y = 0; y < h; y++) {
        for (x = 0; x < w; x++) {
            pel = src[y * src_stride + x];
            pel = ((pel * contrast) >> 12) + brightness;
            temp = (-pel) >> 31;
            if (pel & ~255)
                pel = temp;
            dst[y * dst_stride + x] = (uint8_t)pel;
        }
    }
}
