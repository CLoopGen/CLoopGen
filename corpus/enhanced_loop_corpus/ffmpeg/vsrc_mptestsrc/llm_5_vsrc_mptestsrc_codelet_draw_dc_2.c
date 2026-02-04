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
    for (y = 0; y < h; y++) {
        for (x = 0; x < w; x++) {
            if ((x + y) % 2 == 0) {
                dst[x + y * dst_linesize] = color;
            } else {
                dst[x + y * dst_linesize] = color ^ 0xFF;
            }
        }
    }
}
