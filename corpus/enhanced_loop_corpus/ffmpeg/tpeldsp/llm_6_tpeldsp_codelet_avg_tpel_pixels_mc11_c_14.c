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
            int val = (4 * temp_src[j] + 3 * temp_src[j + 1] + 3 * temp_src[j + stride] + 2 * temp_src[j + stride + 1] + 6);
            int filtered = (val * 2731) >> 15;
            temp_dst[j] = (temp_dst[j] + filtered + 1) >> 1;
        }
        if (width > 0) {
            int edge_val = (4 * temp_src[width - 1] + 3 * temp_src[width - 1] + 3 * temp_src[width - 1 + stride] + 2 * temp_src[width - 1 + stride] + 6);
            int edge_filtered = (edge_val * 2731) >> 15;
            temp_dst[width - 1] = (temp_dst[width - 1] + edge_filtered + 1) >> 1;
        }
        temp_src += stride;
        temp_dst += stride;
    }
}
