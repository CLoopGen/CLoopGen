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
    for (i = 0; i < 256; i += 4) {
        const uint32_t v1 = palette[i];
        const uint32_t v2 = (i+1 < 256) ? palette[i+1] : v1;
        const uint32_t v3 = (i+2 < 256) ? palette[i+2] : v1;
        const uint32_t v4 = (i+3 < 256) ? palette[i+3] : v1;

        const uint8_t a1 = v1 >> 24;
        const uint8_t a2 = v2 >> 24;
        const uint8_t a3 = v3 >> 24;
        const uint8_t a4 = v4 >> 24;

        if (a1 < smallest_alpha) {
            smallest_alpha = a1;
            transparent_color_index = i;
        }
        if (a2 < smallest_alpha && (i+1) < 256) {
            smallest_alpha = a2;
            transparent_color_index = i + 1;
        }
        if (a3 < smallest_alpha && (i+2) < 256) {
            smallest_alpha = a3;
            transparent_color_index = i + 2;
        }
        if (a4 < smallest_alpha && (i+3) < 256) {
            smallest_alpha = a4;
            transparent_color_index = i + 3;
        }
    }
}
