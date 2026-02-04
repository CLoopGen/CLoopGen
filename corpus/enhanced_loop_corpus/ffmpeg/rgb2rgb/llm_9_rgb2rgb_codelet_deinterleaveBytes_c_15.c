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
for (h = 0; h < height; h += 2) {
    int w;
    for (w = 0; w < width; w++) {
        dst1[w] = src[2 * w + 0];
        dst2[w] = src[2 * w + 1];
        if (h + 1 < height) {
            uint8_t *src_next = src + srcStride;
            uint8_t *dst1_next = dst1 + dst1Stride;
            uint8_t *dst2_next = dst2 + dst2Stride;
            dst1_next[w] = src_next[2 * w + 0];
            dst2_next[w] = src_next[2 * w + 1];
        }
    }
    src += 2 * srcStride;
    dst1 += 2 * dst1Stride;
    dst2 += 2 * dst2Stride;
}
}
