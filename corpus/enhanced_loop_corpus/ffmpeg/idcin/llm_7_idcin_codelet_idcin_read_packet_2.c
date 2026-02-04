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
    int i_prev = -1;
    for (i = 0; i < 256; i++) {
        r = palette_buffer[i * 3] << palette_scale;
        g = palette_buffer[i * 3 + 1] << palette_scale;
        b = palette_buffer[i * 3 + 2] << palette_scale;
        palette[i] = (255U << 24) | (r << 16) | (g << 8) | b;
        if (palette_scale == 2 && i > 0) {
            palette[i] |= (palette[i_prev] >> 4) & 197379;
        }
        i_prev = i;
    }
}
