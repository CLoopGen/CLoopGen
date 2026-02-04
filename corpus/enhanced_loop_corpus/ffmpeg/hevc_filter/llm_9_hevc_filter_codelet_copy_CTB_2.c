#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int width;
extern int height;
extern ptrdiff_t stride_dst;
extern ptrdiff_t stride_src;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j += 4) {
            dst[j]     = src[j];
            if (j + 1 < width) dst[j + 1] = src[j + 1];
            if (j + 2 < width) dst[j + 2] = src[j + 2];
            if (j + 3 < width) dst[j + 3] = src[j + 3];
        }
        dst += stride_dst;
        src += stride_src;
    }
}
