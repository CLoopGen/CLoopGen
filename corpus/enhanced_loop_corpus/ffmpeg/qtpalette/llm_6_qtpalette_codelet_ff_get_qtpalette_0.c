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
    uint32_t temp_r, temp_g, temp_b;
    for (i = 0; i < color_count; i++) {
        temp_r = color_index;
        temp_g = temp_r;
        temp_b = temp_g;
        palette[i] = (255U << 24) | (temp_r << 16) | (temp_g << 8) | temp_b;
        color_index -= color_dec;
        if (color_index < 0)
            color_index = 0;
    }
}
