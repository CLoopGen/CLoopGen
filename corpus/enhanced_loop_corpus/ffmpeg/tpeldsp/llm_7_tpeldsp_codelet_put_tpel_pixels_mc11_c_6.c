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
        for (j = width - 1; j >= 0; j--) {
            int offset = j;
            dst[offset] = ((4 * src[offset] + 3 * src[offset + 1] + 3 * src[offset + stride] + 2 * src[offset + stride + 1] + 6) * 2731) >> 15;
        }
        src += stride;
        dst += stride;
    }
}
