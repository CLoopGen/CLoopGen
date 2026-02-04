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
    uint8_t *local_dst = dst;
    uint8_t *local_src = src;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width - 1; j++) {
            int temp = ((3 * local_src[j] + 2 * local_src[j + 1] + 
                        4 * local_src[j + stride] + 3 * local_src[j + stride + 1] + 6) * 2731) >> 15;
            local_dst[j] = (local_dst[j] + temp + 1) >> 1;
        }
        if (j == width - 1) {
            int temp = ((3 * local_src[j] + 2 * local_src[j] + 
                        4 * local_src[j + stride] + 3 * local_src[j + stride] + 6) * 2731) >> 15;
            local_dst[j] = (local_dst[j] + temp + 1) >> 1;
        }
        local_src += stride;
        local_dst += stride;
    }
}
