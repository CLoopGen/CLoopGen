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
for (i = 0; i < 256; i++) {
    r = raw_palette[palette_index++] * 4;
    g = raw_palette[palette_index++] * 4;
    b = raw_palette[palette_index++] * 4;
    unsigned int temp = 255U << 24 | (r << 16) | (g << 8) | (b);
    if (temp & 0x800000) {
        palette32[i] = temp | (temp >> 6 & 197379);
    } else {
        palette32[i] = temp ^ 0x00808080;
    }
}
}
