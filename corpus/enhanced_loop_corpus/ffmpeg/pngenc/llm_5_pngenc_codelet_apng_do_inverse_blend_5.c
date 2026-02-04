#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t transparent_palette_index;
extern uint32_t *palette;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (transparent_palette_index = 0; transparent_palette_index < 256 && (palette[transparent_palette_index] >> 24) != 0; ++transparent_palette_index) {
    }
}
