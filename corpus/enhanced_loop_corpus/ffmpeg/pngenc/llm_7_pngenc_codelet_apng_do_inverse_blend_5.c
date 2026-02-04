#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t transparent_palette_index;
extern uint32_t *palette;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t local_idx = 0;
    uint32_t alpha_value = 0;
    for (; local_idx < 256; ++local_idx) {
        alpha_value = palette[local_idx] >> 24;
        if (alpha_value == 0) {
            break;
        }
    }
    transparent_palette_index = local_idx; // Write final index to shared global
}
