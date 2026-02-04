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
        if (i + 1 < num_pixels) {
            unsigned int rgb0 = ((const uint16_t *)src)[i];
            unsigned int rgb1 = ((const uint16_t *)src)[i + 1];
            ((uint16_t *)dst)[i] = ((rgb0 & 31744) >> 10) | ((rgb0 & 992) << 1) | (rgb0 << 11);
            ((uint16_t *)dst)[i + 1] = ((rgb1 & 31744) >> 10) | ((rgb1 & 992) << 1) | (rgb1 << 11);
        } else {
            unsigned int rgb = ((const uint16_t *)src)[i];
            ((uint16_t *)dst)[i] = ((rgb & 31744) >> 10) | ((rgb & 992) << 1) | (rgb << 11);
        }
    }
}
