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
    for (y = 0; y < h; y += 2) {
        uint16_t *src1 = src;
        uint16_t *src2 = src + linesize;
        for (x = 0; x < w; x++) {
            histogram[src1[x]] += 1;
            histogram[src2[x]] += 1;
        }
        src += 2 * linesize;
        y++;
    }
}
