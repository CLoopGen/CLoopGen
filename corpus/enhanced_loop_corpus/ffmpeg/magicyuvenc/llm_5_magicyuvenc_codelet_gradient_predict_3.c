#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern uint8_t *dst;
extern ptrdiff_t stride;
extern int width;
extern int height;
extern int left;
extern int top;
extern int lefttop;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j < height; j++) {
    top = src[-stride];
    left = src[0] - top;
    dst[0] = left;
    for (i = 1; i < width; i++) {
        top = src[i - stride];
        lefttop = src[i - (stride + 1)];
        left = src[i - 1];
        int diff = (src[i] - top) - left + lefttop;
        if (diff > 128) {
            dst[i] = 255;
        } else if (diff < -128) {
            dst[i] = 0;
        } else {
            dst[i] = diff + 128;
        }
    }
    dst += width;
    src += stride;
}
}
