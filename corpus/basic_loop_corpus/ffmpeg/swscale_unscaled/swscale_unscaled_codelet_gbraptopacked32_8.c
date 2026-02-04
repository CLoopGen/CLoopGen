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
        for (x = 0; x < width; x++) {
            *dest++ = src[3][x];
            *dest++ = src[0][x];
            *dest++ = src[1][x];
            *dest++ = src[2][x];
        }
    } else {
        for (x = 0; x < width; x++) {
            *dest++ = src[0][x];
            *dest++ = src[1][x];
            *dest++ = src[2][x];
            *dest++ = src[3][x];
        }
    }
    for (i = 0; i < 4; i++)
        src[i] += srcStride[i];
}

}
