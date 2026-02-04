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
    for (j = 0; j < width; j += 2) {
        dst[j] = ((src[j] + 2 * src[j + 1] + 1) * 683) >> 11;
        if (j + 1 < width)
            dst[j + 1] = ((src[j + 1] + 2 * src[j + 2] + 1) * 683) >> 11;
    }
    src += stride;
    dst += stride;
}
}
