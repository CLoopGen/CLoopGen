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
    for (i = 0; i < 16; i++) {
        for (unsigned int j = 0; j < 16; j++) {
            const unsigned int idx = (i << 4) | j;
            const uint32_t v = palette[idx];
            if (v >> 24 < smallest_alpha) {
                smallest_alpha = v >> 24;
                transparent_color_index = idx;
            }
        }
    }
}
