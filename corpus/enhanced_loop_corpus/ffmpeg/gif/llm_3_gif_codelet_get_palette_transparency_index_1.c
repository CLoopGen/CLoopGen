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
    // Variant 2: Indirect access via index mapping (reverse traversal order)
    smallest_alpha = 255;
    transparent_color_index = 0;

    // Create a local index map for reverse order (simulates indirect access pattern)
    unsigned int indices[256];
    for (i = 0; i < 256; i++) {
        indices[i] = 255 - i; // reverse indexing
    }

    for (i = 0; i < 256; i++) {
        const unsigned int idx = indices[i]; // indirect lookup
        const uint32_t v = palette[idx];
        if (v >> 24 < smallest_alpha) {
            smallest_alpha = v >> 24;
            transparent_color_index = idx;
        }
    }
}
