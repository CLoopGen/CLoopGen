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
        for (w = 0; w < width - 1; w++) {
            dst1[w + 1] = src[2 * w + 0];  // Introduce RAW dependency: dst1[w+1] depends on current src index
            dst2[w] = src[2 * w + 1];
        }
        if (width > 0) {
            dst1[0] = src[0];  // Break potential loop-carried dependency by resetting base
            dst2[width - 1] = src[2 * width - 1];
        }
        src += srcStride;
        dst1 += dst1Stride;
        dst2 += dst2Stride;
    }
}
