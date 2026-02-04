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
for (h = 0; h < srcSliceH; h += 2) {
    for (x = 0; x < width; x++) {
        uint8_t *dest1 = dst + dstStride * (h + 0);
        uint8_t *dest2 = dst + dstStride * (h + 1);

        dest1 += 3 * x;
        *dest1++ = src[0][x];
        *dest1++ = src[1][x];
        *dest1++ = src[2][x];

        if (h + 1 < srcSliceH) {
            dest2 += 3 * x;
            *dest2++ = src[0][x];
            *dest2++ = src[1][x];
            *dest2++ = src[2][x];
        }
    }
    for (i = 0; i < 3; i++) {
        src[i] += srcStride[i];
        if (h + 1 < srcSliceH)
            src[i] += srcStride[i];
    }
}
}
