#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern uint8_t *dst1;
extern uint8_t *dst2;
extern int width;
extern int height;
extern int srcStride;
extern int dst1Stride;
extern int dst2Stride;
extern int h;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (h = 0; h < height; h++) {
    int w;
    // Change memory access pattern to strided: process every 4th element first, then offsets
    for (int offset = 0; offset < 2; offset++) {
        for (w = offset; w < width; w += 2) {
            dst1[w] = src[2 * w + 0];
            dst2[w] = src[2 * w + 1];
        }
    }
    src += srcStride;
    dst1 += dst1Stride;
    dst2 += dst2Stride;
}
}
