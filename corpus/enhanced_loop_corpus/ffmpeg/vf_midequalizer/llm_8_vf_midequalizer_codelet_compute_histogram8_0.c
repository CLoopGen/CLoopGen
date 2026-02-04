#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern ptrdiff_t linesize;
extern int w;
extern int h;
extern float *histogram;
extern int y;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < h; y += 2) {
    for (x = 0; x < w; x += 2) {
        histogram[src[x]] += 1;
        if (x + 1 < w) {
            histogram[src[x + 1]] += 1;
        }
    }
    src += linesize * 2;
}
}
