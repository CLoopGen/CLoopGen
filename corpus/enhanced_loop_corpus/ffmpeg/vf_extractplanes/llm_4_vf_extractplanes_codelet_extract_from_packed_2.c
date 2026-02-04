#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int dst_linesize;
extern  uint8_t *src;
extern int src_linesize;
extern int width;
extern int height;
extern int depth;
extern int step;
extern int comp;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < height; y++) {
    if (depth == 1) {
        for (x = 0; x < width; x++)
            dst[x] = src[x * step + comp];
    } else if (depth == 2) {
        for (x = 0; x < width; x++) {
            dst[x * 2] = src[x * step + comp * 2];
            dst[x * 2 + 1] = src[x * step + comp * 2 + 1];
        }
    }
    dst += dst_linesize;
    src += src_linesize;
}
}
