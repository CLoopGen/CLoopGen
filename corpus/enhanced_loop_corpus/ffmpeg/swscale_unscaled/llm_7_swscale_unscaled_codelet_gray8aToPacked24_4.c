#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern uint8_t *dst;
extern int num_pixels;
extern  uint8_t *palette;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < num_pixels; i++) {
        int scaled_index = i << 1;
        uint8_t src_val = src[scaled_index];
        int palette_base = src_val * 4;
        // Introduce temporary variables to create intra-loop dependencies (WAW and RAW)
        uint8_t temp_r = palette[palette_base + 0];
        uint8_t temp_g = palette[palette_base + 1];
        uint8_t temp_b = palette[palette_base + 2];
        // Sequential writes with artificial dependency chain
        dst[0] = temp_r;
        dst[1] = temp_g;
        dst[2] = temp_b;
        // Update dst after use – creates WAR hazard potential if parallelized
        dst += 3;
    }
}
