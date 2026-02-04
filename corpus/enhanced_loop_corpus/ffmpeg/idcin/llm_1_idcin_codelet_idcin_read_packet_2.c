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
for (i = 0; i < 64; i++) {
    for (int j = 0; j < 4; j++) {
        int idx = i * 4 + j;
        r = palette_buffer[idx * 3] << palette_scale;
        g = palette_buffer[idx * 3 + 1] << palette_scale;
        b = palette_buffer[idx * 3 + 2] << palette_scale;
        palette[idx] = (255U << 24) | (r << 16) | (g << 8) | (b);
        if (palette_scale == 2)
            palette[idx] |= palette[idx] >> 6 & 197379;
    }
}
}
