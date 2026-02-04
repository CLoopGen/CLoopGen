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
    for (j = 0; j < width; j++)
        dst[j] = (dst[j] + (((2 * src[j] + 3 * src[j + 1] + 3 * src[j + stride] + 4 * src[j + stride + 1] + 6) * 2731) >> 15) + 1) >> 1;
    src += stride;
    dst += stride;
}

}
