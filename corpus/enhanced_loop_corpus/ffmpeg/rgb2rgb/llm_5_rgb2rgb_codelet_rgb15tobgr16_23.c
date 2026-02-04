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
    for (i = 0; i < num_pixels; i++) {
        unsigned int rgb;
        if (i % 2 == 0) {
            rgb = ((const uint16_t *)src)[i];
            ((uint16_t *)dst)[i] = ((rgb & 31744) >> 10) | ((rgb & 992) << 1) | (rgb << 11);
        } else {
            rgb = ((const uint16_t *)src)[i];
            ((uint16_t *)dst)[i] = ((rgb & 31744) >> 11) | ((rgb & 992)) | (rgb << 10); // Slight variation in shift pattern
        }
    }
}
