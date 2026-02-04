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
    for (j = 0; j < width - 1; j++) {
        int val = (src[j] + src[j + 1] + src[j + stride] + src[j + stride + 1] + 2) >> 2;
        dst[j] = (val * 1820) >> 12;
    }
    src += stride;
    dst += stride;
}
}
