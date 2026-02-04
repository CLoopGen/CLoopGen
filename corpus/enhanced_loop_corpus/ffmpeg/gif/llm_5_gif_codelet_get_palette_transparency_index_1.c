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
    transparent_color_index = 0;
    smallest_alpha = 255;
    for (i = 0; i < 256; i += 4) {
        const uint32_t v0 = palette[i + 0];
        const uint32_t v1 = palette[i + 1];
        const uint32_t v2 = palette[i + 2];
        const uint32_t v3 = palette[i + 3];

        const uint8_t a0 = v0 >> 24;
        const uint8_t a1 = v1 >> 24;
        const uint8_t a2 = v2 >> 24;
        const uint8_t a3 = v3 >> 24;

        if (a0 < smallest_alpha) {
            smallest_alpha = a0;
            transparent_color_index = i + 0;
        }
        if (a1 < smallest_alpha) {
            smallest_alpha = a1;
            transparent_color_index = i + 1;
        }
        if (a2 < smallest_alpha) {
            smallest_alpha = a2;
            transparent_color_index = i + 2;
        }
        if (a3 < smallest_alpha) {
            smallest_alpha = a3;
            transparent_color_index = i + 3;
        }
    }
}
