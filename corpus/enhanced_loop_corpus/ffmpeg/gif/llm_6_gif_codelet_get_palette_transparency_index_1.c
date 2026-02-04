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
    uint32_t local_palette[256];
    for (i = 0; i < 256; i++) {
        local_palette[i] = palette[i]; // Introduce temporary array to break direct dependency on global in evaluation
    }
    smallest_alpha = 255;
    transparent_color_index = 0;
    for (i = 0; i < 256; i++) {
        const uint32_t v = local_palette[i];
        const uint8_t alpha = v >> 24;
        if (alpha < smallest_alpha) {
            smallest_alpha = alpha;
            transparent_color_index = i;
        }
    }
}
