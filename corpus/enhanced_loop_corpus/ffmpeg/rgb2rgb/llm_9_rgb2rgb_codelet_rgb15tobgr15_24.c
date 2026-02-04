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
    for (i = 0; i < num_pixels && i < 1024; i++) {
        unsigned int rgb = ((const uint16_t *)src)[i];
        unsigned int b = (rgb >> 10) & 0x1F;
        unsigned int g = (rgb >> 5) & 0x1F;
        unsigned int r = rgb & 0x1F;
        unsigned int br = ((b << 10) | (r << 0)) & 31775;
        ((uint16_t *)dst)[i] = (br >> 10) | (g << 5) | (br << 10);
    }
}
