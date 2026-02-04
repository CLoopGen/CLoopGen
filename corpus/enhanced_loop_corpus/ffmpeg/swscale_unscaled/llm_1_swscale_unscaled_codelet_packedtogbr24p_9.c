#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int srcStride;
extern int dstStride[];
extern int srcSliceH;
extern int inc_size;
extern int width;
extern uint8_t *dest[3];
extern int x;
extern int h;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (h = 0; h < srcSliceH; h++) {
    for (x = 0; x < width; x++) {
        int plane;
        for (plane = 0; plane < 3; plane++) {
            dest[plane][x] = src[plane];
        }
        src += inc_size;
    }
    src += srcStride - width * inc_size;
    for (int plane = 0; plane < 3; plane++) {
        dest[plane] += dstStride[plane];
    }
}
}
