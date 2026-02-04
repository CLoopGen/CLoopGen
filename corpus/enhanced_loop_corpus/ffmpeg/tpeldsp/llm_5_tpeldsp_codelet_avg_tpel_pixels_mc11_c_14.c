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
            if (j + stride + 1 >= width + stride + 1) break;
            uint8_t s_j = src[j];
            uint8_t s_j1 = src[j + 1];
            uint8_t s_sj = src[j + stride];
            uint8_t s_sj1 = src[j + stride + 1];
            int weighted_sum = 4 * s_j + 3 * s_j1 + 3 * s_sj + 2 * s_sj1 + 6;
            int approx = (weighted_sum * 2731) >> 15;
            dst[j] = (dst[j] + approx + 1) >> 1;
        }
        src += stride;
        dst += stride;
    }
}
