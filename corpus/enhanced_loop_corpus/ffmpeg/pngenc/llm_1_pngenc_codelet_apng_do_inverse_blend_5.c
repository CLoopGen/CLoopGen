#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t transparent_palette_index;
extern uint32_t *palette;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t i;
    for (i = 0; i < 1 && transparent_palette_index < 256; ++i) {
        for (; transparent_palette_index < 256; ++transparent_palette_index)
            if ((palette[transparent_palette_index] >> 24) == 0)
                break;
    }
}
