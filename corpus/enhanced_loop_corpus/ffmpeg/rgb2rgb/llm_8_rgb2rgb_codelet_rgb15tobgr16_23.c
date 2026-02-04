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
    for (i = 0; i < num_pixels; i += 2) {
        unsigned int rgb1 = ((const uint16_t *)src)[i];
        ((uint16_t *)dst)[i] = ((rgb1 & 31744) >> 10) | ((rgb1 & 992) << 1) | (rgb1 << 11);
        if (i + 1 < num_pixels) {
            unsigned int rgb2 = ((const uint16_t *)src)[i + 1];
            ((uint16_t *)dst)[i + 1] = ((rgb2 & 31744) >> 10) | ((rgb2 & 992) << 1) | (rgb2 << 11);
        }
    }
}
