#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern unsigned int *palette32;
extern int palette_index;
extern unsigned char r;
extern unsigned char g;
extern unsigned char b;
extern unsigned char *raw_palette;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_index = palette_index;
    for (i = 0; i < 256; i++) {
        r = raw_palette[local_index++] * 4;
        g = raw_palette[local_index++] * 4;
        b = raw_palette[local_index++] * 4;
        uint32_t temp_r = r << 16;
        uint32_t temp_g = g << 8;
        uint32_t temp_b = b;
        uint32_t pixel = 255U << 24 | temp_r | temp_g | temp_b;
        pixel |= pixel >> 6 & 197379;
        palette32[i] = pixel;
    }
    palette_index = local_index; // Update only once after loop
}
