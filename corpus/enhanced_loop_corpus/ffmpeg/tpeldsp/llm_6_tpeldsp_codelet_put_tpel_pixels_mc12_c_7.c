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
    uint8_t *temp_dst = dst;
    uint8_t *temp_src = src;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width - 1; j++) {
            int val = (3 * temp_src[j] + 2 * temp_src[j + 1] + 
                       4 * temp_src[j + stride] + 3 * temp_src[j + stride + 1] + 6);
            temp_dst[j] = (val * 2731) >> 15;
        }
        if (width > 0) {
            int j = width - 1;
            temp_dst[j] = ((3 * temp_src[j] + 2 * temp_src[j] + 
                            4 * temp_src[j + stride] + 3 * temp_src[j + stride] + 6) * 2731) >> 15;
        }
        temp_src += stride;
        temp_dst += stride;
    }
}
