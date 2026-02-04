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
for (i = 0; i < 128; i++) {
    int idx = i * 2;
    r = palette_buffer[idx * 3] << palette_scale;
    g = palette_buffer[idx * 3 + 1] << palette_scale;
    b = palette_buffer[idx * 3 + 2] << palette_scale;
    uint32_t rgb1 = (255U << 24) | (r << 16) | (g << 8) | b;
    if (palette_scale == 2) {
        rgb1 |= rgb1 >> 6 & 197379;
    }

    r = palette_buffer[(idx + 1) * 3] << palette_scale;
    g = palette_buffer[(idx + 1) * 3 + 1] << palette_scale;
    b = palette_buffer[(idx + 1) * 3 + 2] << palette_scale;
    uint32_t rgb2 = (255U << 24) | (r << 16) | (g << 8) | b;
    if (palette_scale == 2) {
        rgb2 |= rgb2 >> 6 & 197379;
    }

    palette[idx] = rgb1;
    palette[idx + 1] = rgb2;
}
}
