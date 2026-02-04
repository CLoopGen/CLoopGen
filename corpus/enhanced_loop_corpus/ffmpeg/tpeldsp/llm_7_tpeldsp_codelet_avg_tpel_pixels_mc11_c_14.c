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
        uint8_t local_accum[256]; 
        int w = width < 256 ? width : 256;
        for (j = 0; j < w; j++) {
            int val = (4 * temp_src[j] + 3 * temp_src[j + 1] + 3 * temp_src[j + stride] + 2 * temp_src[j + stride + 1] + 6);
            local_accum[j] = (val * 2731) >> 15;
        }
        for (j = 0; j < w; j++) {
            temp_dst[j] = (temp_dst[j] + local_accum[j] + 1) >> 1;
        }
        temp_src += stride;
        temp_dst += stride;
    }
}
