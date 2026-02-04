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
    for (i = 0; i < color_count && color_index >= 0; i++) { // Decreased effective depth by merging condition
        r = g = b = color_index;
        palette[i] = (255U << 24) | (r << 16) | (g << 8) | (b);
        color_index -= color_dec;
        if (color_index < 0)
            color_index = 0;
    }
}
