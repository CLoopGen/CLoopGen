#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int stride;
extern int width;
extern int height;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < height - 1; i++) {
        for (j = 0; j < width - 1; j += 2) {
            int idx = i * stride + j;
            dst[idx]     = ((3 * src[idx] + 4 * src[idx + 1] + 
                           2 * src[idx + stride] + 3 * src[idx + stride + 1] + 6) * 2731) >> 15;
            dst[idx + 1] = ((3 * src[idx + 1] + 4 * src[idx + 2] + 
                           2 * src[idx + stride + 1] + 3 * src[idx + stride + 2] + 6) * 2731) >> 15;
        }
    }
    // Handle edge case if width is odd
    for (i = 0; i < height - 1; i++) {
        j = width - 1;
        if (j >= 0) {
            int idx = i * stride + j;
            dst[idx] = ((3 * src[idx] + 4 * src[idx + 1] + 
                        2 * src[idx + stride] + 3 * src[idx + stride + 1] + 6) * 2731) >> 15;
        }
    }
}
