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
        for (j = 0; j < width - 1; j++) {
            uint8_t pred = (src[j+1] + 2 * src[j + 1 + stride] + 1) * 683;
            dst[j] = (dst[j] + ((pred >> 11) + 1)) >> 1;
        }
        if (width > 0) {
            dst[width - 1] = (dst[width - 1] + (((src[width - 1] + 2 * src[width - 1 + stride] + 1) * 683) >> 11) + 1) >> 1;
        }
        src += stride;
        dst += stride;
    }
}
