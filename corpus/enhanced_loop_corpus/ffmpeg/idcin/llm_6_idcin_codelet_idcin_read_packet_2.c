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
    unsigned char temp_r, temp_g, temp_b;
    for (j = 0; j < 256; j++) {
        temp_r = palette_buffer[j * 3];
        temp_g = palette_buffer[j * 3 + 1];
        temp_b = palette_buffer[j * 3 + 2];
        r = temp_r << palette_scale;
        g = temp_g << palette_scale;
        b = temp_b << palette_scale;
        palette[j] = (255U << 24) | (r << 16) | (g << 8) | b;
        if (palette_scale == 2)
            palette[j] |= palette[j] >> 6 & 197379;
    }
}
