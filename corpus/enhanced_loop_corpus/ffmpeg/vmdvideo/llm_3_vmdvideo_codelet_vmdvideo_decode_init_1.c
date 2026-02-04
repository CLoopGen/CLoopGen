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
    unsigned char* rp = raw_palette;
    for (i = 0; i < 256; i++) {
        r = rp[3*i + 0] * 4;
        g = rp[3*i + 1] * 4;
        b = rp[3*i + 2] * 4;
        uint32_t pixel = (255U << 24) | ((uint32_t)r << 16) | ((uint32_t)g << 8) | (uint32_t)b;
        pixel |= pixel >> 6 & 197379;
        palette32[i] = pixel;
    }
}
