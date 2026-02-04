#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t transparent_palette_index;
extern uint32_t *palette;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 4th element first, then handle remainder)
    size_t stride = 4;
    size_t i;
    // First pass: check indices with stride
    for (i = 0; i < 256; i += stride) {
        if (palette[i] >> 24 == 0) {
            transparent_palette_index = i;
            return;
        }
    }
    // Second pass: fill in the gaps with sequential access if not found in strided
    for (transparent_palette_index = 1; transparent_palette_index < 256; ++transparent_palette_index) {
        if (transparent_palette_index % stride == 0) continue; // skip already checked
        if (palette[transparent_palette_index] >> 24 == 0)
            break;
    }
}
