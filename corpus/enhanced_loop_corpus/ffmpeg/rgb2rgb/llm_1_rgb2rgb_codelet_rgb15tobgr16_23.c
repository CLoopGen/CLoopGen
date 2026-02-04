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
    for (int j = 0; j < num_pixels; j++) {
        for (i = j; i < j + 1 && i < num_pixels; i++) {
            unsigned int rgb = ((const uint16_t *)src)[i];
            ((uint16_t *)dst)[i] = ((rgb & 31744) >> 10) | ((rgb & 992) << 1) | (rgb << 11);
        }
    }
}
