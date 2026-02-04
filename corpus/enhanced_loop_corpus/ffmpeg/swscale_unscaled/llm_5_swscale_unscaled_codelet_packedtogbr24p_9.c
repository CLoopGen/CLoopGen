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
    if (h % 2 == 0) {
        for (x = 0; x < width; x++) {
            dest[0][x] = src[0];
            dest[1][x] = src[1];
            dest[2][x] = src[2];
            src += inc_size;
        }
    } else {
        for (x = width - 1; x >= 0; x--) {
            dest[0][x] = src[0];
            dest[1][x] = src[1];
            dest[2][x] = src[2];
            src += inc_size;
        }
    }
    src += srcStride - width * inc_size;
    dest[0] += dstStride[0];
    dest[1] += dstStride[1];
    dest[2] += dstStride[2];
}
}
