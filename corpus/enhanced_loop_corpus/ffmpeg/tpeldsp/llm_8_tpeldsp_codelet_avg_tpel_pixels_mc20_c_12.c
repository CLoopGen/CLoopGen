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
for (i = 0; i < height; i += 2) {
    for (j = 0; j < width; j++) {
        int temp1 = src[j] + 2 * src[j + 1];
        int temp2 = (temp1 + 1) * 683;
        int approx = (temp2 >> 11);
        dst[j] = (dst[j] + approx + 1) >> 1;
    }
    for (j = 0; j < width; j++) {
        int temp1 = src[j + stride] + 2 * src[j + stride + 1];
        int temp2 = (temp1 + 1) * 683;
        int approx = (temp2 >> 11);
        dst[j + stride] = (dst[j + stride] + approx + 1) >> 1;
    }
    src += 2 * stride;
    dst += 2 * stride;
}
}
