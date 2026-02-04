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
    if (width > 0) {
        j = 0;
        dst[j] = ((2 * src[j] + src[j + 1] + 1) * 683) >> 11;
        for (j = 1; j < width - 1; j++)
            dst[j] = ((2 * src[j] + src[j + 1] + 1) * 683) >> 11;
        if (width > 1)
            dst[j] = ((2 * src[j] + src[j + 1] + 1) * 683) >> 11;
    }
    src += stride;
    dst += stride;
}
}
