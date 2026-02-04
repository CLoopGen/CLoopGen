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
    int total_pixels = height * width;
    int idx;
    uint8_t *src_temp = src;
    uint8_t *dst1_temp = dst1;
    uint8_t *dst2_temp = dst2;

    for (idx = 0; idx < total_pixels; idx++) {
        int h = idx / width;
        int w = idx % width;
        dst1_temp[w] = src_temp[2 * w + 0];
        dst2_temp[w] = src_temp[2 * w + 1];

        if (w == width - 1) {
            src_temp += srcStride;
            dst1_temp += dst1Stride;
            dst2_temp += dst2Stride;
        }
    }
}
