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
    uint8_t temp;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width - 1; j++) {
            temp = (src[j] + 2 * src[j + 1] + 1) * 683;
            dst[j] = (dst[j] + (temp >> 11) + 1) >> 1;
        }
        if (j == width - 1) {
            dst[j] = (dst[j] + (((src[j] + 2 * src[j] + 1) * 683) >> 11) + 1) >> 1;
        }
        src += stride;
        dst += stride;
    }
}
