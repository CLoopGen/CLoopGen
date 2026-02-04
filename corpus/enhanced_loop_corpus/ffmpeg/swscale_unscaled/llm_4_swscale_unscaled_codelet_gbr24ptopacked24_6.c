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
        x = 0;
        if (width > 0) {
            do {
                *dest++ = src[0][x];
                *dest++ = src[1][x];
                *dest++ = src[2][x];
                x++;
            } while (x < width);
        }
        for (i = 0; i < 3; i++)
            src[i] += srcStride[i];
    }
}
