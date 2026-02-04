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
    const uint16_t *s = (const uint16_t *)src;
    uint16_t *d = (uint16_t *)dst;
    for (i = 0; i < num_pixels; i++) {
        unsigned int rgb = s[i];
        d[i] = (rgb >> 11) | (rgb & 2016) | (rgb << 11);
    }
}
