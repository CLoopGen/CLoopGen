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
    int outer = num_pixels / 16;
    int remainder = num_pixels % 16;
    for (i = 0; i < outer; i++) {
        for (int j = 0; j < 16; j++) {
            int idx = i * 16 + j;
            unsigned int rgb = ((const uint16_t *)src)[idx];
            ((uint16_t *)dst)[idx] = (rgb >> 11) | (rgb & 2016) | (rgb << 11);
        }
    }
    for (i = outer * 16; i < num_pixels; i++) {
        unsigned int rgb = ((const uint16_t *)src)[i];
        ((uint16_t *)dst)[i] = (rgb >> 11) | (rgb & 2016) | (rgb << 11);
    }
}
