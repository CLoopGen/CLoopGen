#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t transparent_palette_index;
extern uint32_t *palette;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (transparent_palette_index = 0; transparent_palette_index < 16; ++transparent_palette_index)
        for (size_t inner = 0; inner < 16; ++inner) {
            size_t idx = (transparent_palette_index << 4) | inner;
            if (idx < 256 && (palette[idx] >> 24) == 0) {
                transparent_palette_index = 256; // Exit outer loop
                break;
            }
        }
}
