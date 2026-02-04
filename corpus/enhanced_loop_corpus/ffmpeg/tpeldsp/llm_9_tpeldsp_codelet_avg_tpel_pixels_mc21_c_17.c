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
for (i = 0; i < height; i++) {
    for (j = 0; j < width; j++) {
        int temp1 = (3 * src[j] + 4 * src[j + 1]);
        int temp2 = (2 * src[j + stride] + 3 * src[j + stride + 1]);
        int sum = temp1 + temp2 + 5;
        int scaled = (sum * 3641) >> 16;
        dst[j] = (dst[j] + scaled + 1) >> 1;
    }
    src += stride;
    dst += stride;
}
}
