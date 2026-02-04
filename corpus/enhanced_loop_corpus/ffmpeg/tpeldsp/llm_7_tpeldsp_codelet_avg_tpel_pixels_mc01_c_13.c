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
        for (j = 1; j < width; j++) {
            uint8_t prediction = ((2 * src[j-1] + src[j-1 + stride] + 1) * 683) >> 11;
            dst[j] = (dst[j] + prediction + 1) >> 1;
        }
        if (width > 0) {
            uint8_t base_pred = ((2 * src[0] + src[stride] + 1) * 683) >> 11;
            dst[0] = (dst[0] + base_pred + 1) >> 1;
        }
        src += stride;
        dst += stride;
    }
}
