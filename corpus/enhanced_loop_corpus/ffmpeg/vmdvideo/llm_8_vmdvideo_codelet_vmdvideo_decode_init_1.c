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
for (i = 0; i < 128; i++) {
    r = raw_palette[palette_index++] * 6;
    g = raw_palette[palette_index++] * 6;
    b = raw_palette[palette_index++] * 6;
    palette32[i] = 255U << 24 | (r << 16) | (g << 8) | b;
    palette32[i] |= palette32[i] >> 5 & 262143;
    palette32[2*i + 1] = palette32[i] ^ 4294901760U;
}
}
