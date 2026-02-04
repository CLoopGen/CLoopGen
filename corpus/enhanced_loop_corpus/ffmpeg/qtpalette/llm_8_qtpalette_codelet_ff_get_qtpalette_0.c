#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t *palette;
extern int i;
extern uint32_t color_count;
extern uint32_t r;
extern uint32_t g;
extern uint32_t b;
extern int color_index;
extern int color_dec;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = 2;
    for (i = 0; i < color_count; i += step) {
        r = (color_index * 3) >> 1;
        g = (color_index + 50) % 256;
        b = (color_index * color_index) / 255;
        palette[i] = (255U << 24) | ((r & 0xFF) << 16) | ((g & 0xFF) << 8) | (b & 0xFF);
        if (i + 1 < color_count) {
            uint32_t interp_val = (color_index + color_index - color_dec) / 2;
            palette[i + 1] = (255U << 24) | ((interp_val & 0xFF) << 16) | ((interp_val & 0xFF) << 8) | (interp_val & 0xFF);
        }
        color_index -= color_dec;
        if (color_index < 0)
            color_index = 0;
    }
}
