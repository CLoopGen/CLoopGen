#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t transparent_palette_index;
extern uint32_t *palette;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (transparent_palette_index = 0; transparent_palette_index < 512; transparent_palette_index += 2)
        if (transparent_palette_index < 256 && ((palette[transparent_palette_index] >> 24) & 1) == 0 && (palette[transparent_palette_index] >> 25) == 0)
            break;
}
