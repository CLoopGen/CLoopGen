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
        uint8_t val1 = (i < height) ? ((2 * src[j] + src[j + 1] + 1) * 683) >> 11 : 0;
        uint8_t val2 = (i + 1 < height) ? ((2 * (src[stride + j]) + src[stride + j + 1] + 1) * 683) >> 11 : 0;
        if (i < height) dst[j] = val1;
        if (i + 1 < height) dst[stride + j] = val2;
    }
    src += 2 * stride;
    dst += 2 * stride;
}
}
