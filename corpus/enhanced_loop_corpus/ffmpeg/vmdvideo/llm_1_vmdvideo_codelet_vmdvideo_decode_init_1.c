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
    for (i = 0; i < 64; i++) {
        for (int j = 0; j < 4; j++) {
            int index = i * 4 + j;
            r = raw_palette[palette_index++] * 4;
            g = raw_palette[palette_index++] * 4;
            b = raw_palette[palette_index++] * 4;
            palette32[index] = 255U << 24 | (r << 16) | (g << 8) | (b);
            palette32[index] |= palette32[index] >> 6 & 197379;
        }
    }
}
