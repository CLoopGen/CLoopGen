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
        int val = src[j] + 2 * src[j + stride];
        if (val > 0)
            dst[j] = (val + 1) * 683 >> 11;
        else
            dst[j] = 0;
    }
    src += stride;
    dst += stride;
}
}
