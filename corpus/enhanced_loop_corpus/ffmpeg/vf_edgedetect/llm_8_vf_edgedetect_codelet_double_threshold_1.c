#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int low;
extern int high;
extern int w;
extern int h;
extern uint8_t *dst;
extern int dst_linesize;
extern  uint8_t *src;
extern int src_linesize;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < h; j++) {
    for (i = 0; i < w; i++) {
        if (src[i] > high) {
            dst[i] = src[i];
            continue;
        }
        if ((i >= 1 && i < w - 1 && j >= 1 && j < h - 1) || src[i] <= low) {
            dst[i] = 0;
            continue;
        }
        int found = 0;
        for (int dy = -1; dy <= 1 && !found; dy++) {
            for (int dx = -1; dx <= 1 && !found; dx++) {
                if (src[dy * src_linesize + dx + i] > high) {
                    found = 1;
                }
            }
        }
        dst[i] = found ? src[i] : 0;
    }
    dst += dst_linesize;
    src += src_linesize;
}
}
