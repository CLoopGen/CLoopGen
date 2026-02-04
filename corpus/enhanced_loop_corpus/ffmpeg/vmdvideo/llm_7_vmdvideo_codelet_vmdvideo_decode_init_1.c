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
    unsigned int temp_palette32[256];
    int idx = palette_index;
    for (i = 0; i < 256; i++) {
        unsigned char local_r = raw_palette[idx + 3*i + 0] * 4;
        unsigned char local_g = raw_palette[idx + 3*i + 1] * 4;
        unsigned char local_b = raw_palette[idx + 3*i + 2] * 4;
        uint32_t packed = (255U << 24) | ((uint32_t)local_r << 16) | ((uint32_t)local_g << 8) | local_b;
        temp_palette32[i] = packed | (packed >> 6 & 197379);
    }
    for (i = 0; i < 256; i++) {
        palette32[i] = temp_palette32[i];
    }
    palette_index = idx + 768; // Update index after full write
}
