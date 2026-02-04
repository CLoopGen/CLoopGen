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
    int h, w;
    for (h = 0; h < height; h++) {
        for (w = 0; w < width; w++) {
            dst1[w] = src[2 * w + 0];
            dst2[w] = src[2 * w + 1];
        }
        src += srcStride;
        dst1 += dst1Stride;
        dst2 += dst2Stride;
    }
}
