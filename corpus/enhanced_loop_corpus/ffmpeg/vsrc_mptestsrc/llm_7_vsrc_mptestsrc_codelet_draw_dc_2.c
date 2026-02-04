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
    int index = 0;
    int total_elements = w * h;
    uint8_t local_color = color;
    for (y = 0; y < h; y++) {
        for (x = 0; x < w; x++) {
            index = y * dst_linesize + x;
            dst[index] = local_color;
        }
    }
}
