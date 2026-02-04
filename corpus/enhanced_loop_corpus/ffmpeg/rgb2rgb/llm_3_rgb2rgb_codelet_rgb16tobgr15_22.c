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
    const uint16_t *src16 = (const uint16_t *)src;
    uint16_t *dst16 = (uint16_t *)dst;
    for (i = num_pixels - 1; i >= 0; i--) {
        unsigned int rgb = src16[i];
        dst16[i] = (rgb >> 11) | ((rgb & 1984) >> 1) | ((rgb & 31) << 10);
    }
}
