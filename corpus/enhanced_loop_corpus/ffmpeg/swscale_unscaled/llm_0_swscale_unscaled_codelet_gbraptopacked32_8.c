#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src[];
extern int srcStride[];
extern uint8_t *dst;
extern int dstStride;
extern int srcSliceH;
extern int alpha_first;
extern int width;
extern int x;
extern int h;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (h = 0; h < srcSliceH; h++) {
    uint8_t *dest = dst + dstStride * h;
    if (alpha_first) {
        x = 0;
        for (; x < width; x++) {
            dest[4*x + 0] = src[3][x];
            dest[4*x + 1] = src[0][x];
            dest[4*x + 2] = src[1][x];
            dest[4*x + 3] = src[2][x];
        }
    } else {
        x = 0;
        for (; x < width; x++) {
            dest[4*x + 0] = src[0][x];
            dest[4*x + 1] = src[1][x];
            dest[4*x + 2] = src[2][x];
            dest[4*x + 3] = src[3][x];
        }
    }
    for (i = 0; i < 4; i++)
        src[i] += srcStride[i];
}
}
