#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int palette_scale;
extern unsigned char r;
extern unsigned char g;
extern unsigned char b;
extern unsigned char palette_buffer[768];
extern uint32_t palette[256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (j = 0; j < 256; j++) {
        int idx = j * 3;
        r = palette_buffer[idx] << palette_scale;
        g = palette_buffer[idx + 1] << palette_scale;
        b = palette_buffer[idx + 2] << palette_scale;
        palette[j] = (255U << 24) | (r << 16) | (g << 8) | b;
        if (palette_scale == 2)
            palette[j] |= palette[j] >> 6 & 197379;
    }
}
