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
    // Variant 1: Strided memory access (step by 2, then handle remainder)
    smallest_alpha = 255;
    transparent_color_index = 0;
    const unsigned int step = 2;
    const unsigned int limit = 256 - (256 % step);

    for (i = 0; i < limit; i += step) {
        const uint32_t v1 = palette[i];
        const uint32_t v2 = palette[i + 1];

        uint8_t alpha1 = v1 >> 24;
        uint8_t alpha2 = v2 >> 24;

        if (alpha1 < smallest_alpha) {
            smallest_alpha = alpha1;
            transparent_color_index = i;
        }
        if (alpha2 < smallest_alpha) {
            smallest_alpha = alpha2;
            transparent_color_index = i + 1;
        }
    }

    // Handle any remaining elements (in this case, possibly one at index 255 if unaligned)
    for (; i < 256; i++) {
        const uint32_t v = palette[i];
        if (v >> 24 < smallest_alpha) {
            smallest_alpha = v >> 24;
            transparent_color_index = i;
        }
    }
}
