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
    int indices[256];
    for (int k = 0; k < 256; k++)
        indices[k] = k;
    for (j = 0; j < 256; j++) {
        int rev_idx = 255 - indices[j]; // Indirect access via reversed index
        r = palette_buffer[rev_idx * 3] << palette_scale;
        g = palette_buffer[rev_idx * 3 + 1] << palette_scale;
        b = palette_buffer[rev_idx * 3 + 2] << palette_scale;
        palette[rev_idx] = (255U << 24) | (r << 16) | (g << 8) | b;
        if (palette_scale == 2)
            palette[rev_idx] |= palette[rev_idx] >> 6 & 197379;
    }
}
