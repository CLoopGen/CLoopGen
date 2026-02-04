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
        unsigned int rgb = s[i * 2 % num_pixels]; // Strided and wrapped access pattern
        unsigned int br = rgb & 31775;
        d[i * 2 % num_pixels] = (br >> 10) | (rgb & 992) | (br << 10);
    }
}
