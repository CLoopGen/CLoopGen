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
    int j;
    for (j = 0; j < (int)color_count; j++) {
        uint32_t local_index = color_index;
        r = local_index;
        g = local_index;
        b = local_index;
        palette[j] = (255U << 24) | (r << 16) | (g << 8) | b;
        color_index -= color_dec;
        if (color_index < 0) {
            color_index = 0;
        }
    }
}
