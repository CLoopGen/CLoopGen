#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t transparent_palette_index;
extern uint32_t *palette;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via index array (simulates irregular access pattern)
    size_t indices[256];
    // Precompute indirect access order (reversed order in this case)
    for (size_t i = 0; i < 256; ++i) {
        indices[i] = 255 - i;
    }
    // Traverse using the indirection array
    for (size_t j = 0; j < 256; ++j) {
        transparent_palette_index = indices[j];
        if (palette[transparent_palette_index] >> 24 == 0)
            break;
    }
}
