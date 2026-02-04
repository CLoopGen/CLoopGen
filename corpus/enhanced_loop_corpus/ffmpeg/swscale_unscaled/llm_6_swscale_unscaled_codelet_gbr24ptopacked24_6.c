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
        uint8_t val0 = src[0][x];
        uint8_t val1 = src[1][x];
        uint8_t val2 = src[2][x];
        *dest++ = val0;
        *dest++ = val1;
        *dest++ = val2;
    }
    for (i = 0; i < 3; i++)
        src[i] += srcStride[i];
}
}
