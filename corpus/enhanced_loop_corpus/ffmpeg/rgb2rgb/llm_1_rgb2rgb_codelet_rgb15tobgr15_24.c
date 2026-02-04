#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern uint8_t *dst;
extern int i;
extern int num_pixels;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int outer_start = 0;
    int outer_end = num_pixels / 2;
    int remainder = num_pixels % 2;

    for (i = outer_start; i < outer_end; i++) {
        int idx1 = 2 * i;
        int idx2 = 2 * i + 1;
        unsigned int rgb1 = ((const uint16_t *)src)[idx1];
        unsigned int br1 = rgb1 & 31775;
        ((uint16_t *)dst)[idx1] = (br1 >> 10) | (rgb1 & 992) | (br1 << 10);

        if (idx2 < num_pixels) {
            unsigned int rgb2 = ((const uint16_t *)src)[idx2];
            unsigned int br2 = rgb2 & 31775;
            ((uint16_t *)dst)[idx2] = (br2 >> 10) | (rgb2 & 992) | (br2 << 10);
        }
    }

    if (remainder) {
        int last_idx = num_pixels - 1;
        unsigned int rgb = ((const uint16_t *)src)[last_idx];
        unsigned int br = rgb & 31775;
        ((uint16_t *)dst)[last_idx] = (br >> 10) | (rgb & 992) | (br << 10);
    }
}
