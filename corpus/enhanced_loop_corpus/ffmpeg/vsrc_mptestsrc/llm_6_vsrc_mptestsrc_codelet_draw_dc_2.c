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
    uint8_t temp_color = color;
    for (y = 0; y < h; y++) {
        uint8_t *row = &dst[y * dst_linesize];
        for (x = 0; x < w; x++) {
            row[x] = temp_color;
        }
    }
}
