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
        dst[j] = (dst[j] + (((src[j] + 2 * src[j + stride] + 1) * 683) >> 11) + 1) >> 1;
    }
    src += stride;
    dst += stride;
}
}
