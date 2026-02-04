#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int dst_linesize;
extern int color;
extern int w;
extern int h;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int y;
    for (y = 0; y < h; y += 2) {
        int x;
        for (x = 0; x < w; x += 2) {
            int offset = x + y * dst_linesize;
            dst[offset] = color;
            if (x + 1 < w) dst[offset + 1] = color;
            if (y + 1 < h) dst[offset + dst_linesize] = color;
            if (x + 1 < w && y + 1 < h) dst[offset + 1 + dst_linesize] = color;
        }
    }
}
