#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint16_t *src;
extern ptrdiff_t linesize;
extern int w;
extern int h;
extern float *histogram;
extern int y;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = 0; y < h; y++) {
        uint16_t *src_row = src + y * (linesize / sizeof(uint16_t));
        for (x = 0; x < w; x++) {
            histogram[src_row[x]] += 1;
        }
    }
}
