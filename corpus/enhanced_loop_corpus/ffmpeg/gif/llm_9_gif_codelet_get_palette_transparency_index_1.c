#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint32_t *palette;
extern int transparent_color_index;
extern unsigned int i;
extern unsigned int smallest_alpha;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    smallest_alpha = 255;
    transparent_color_index = -1;
    for (i = 1; i <= 256; i++) {
        const uint32_t v = palette[256 - i];
        const uint8_t alpha = (uint8_t)(v >> 24);
        const uint8_t mask = -(alpha < smallest_alpha);
        smallest_alpha = (smallest_alpha & ~mask) | (alpha & mask);
        transparent_color_index = (transparent_color_index & ~mask) | ((256 - i) & mask);
    }
}
