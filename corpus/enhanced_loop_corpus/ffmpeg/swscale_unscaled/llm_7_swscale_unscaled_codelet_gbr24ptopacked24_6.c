#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src[];
extern int srcStride[];
extern uint8_t *dst;
extern int dstStride;
extern int srcSliceH;
extern int width;
extern int x;
extern int h;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (h = 0; h < srcSliceH; h++) {
    uint8_t *dest = dst + dstStride * h;
    for (x = 0; x < width; x++) {
        dest[0] = src[0][x];
        dest[1] = src[1][x];
        dest[2] = src[2][x];
        dest += 3;
    }
    src[0] += srcStride[0];
    src[1] += srcStride[1];
    src[2] += srcStride[2];
}
}
