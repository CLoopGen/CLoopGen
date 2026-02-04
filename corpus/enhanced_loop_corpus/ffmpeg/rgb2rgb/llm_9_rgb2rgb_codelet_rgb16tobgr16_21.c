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
        const uint16_t *s = (const uint16_t *)src;
        uint16_t *d = (uint16_t *)dst;
        unsigned int r = (s[i] >> 11) & 0x1F;
        unsigned int g = (s[i] >> 5) & 0x3F;
        unsigned int b = s[i] & 0x1F;
        d[i] = (b << 11) | (g << 5) | r;
    }
}
