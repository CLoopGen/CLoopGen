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
extern  uint8_t *color_table;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < color_count; i++) {
        uint32_t base = i * 3;
        r = (color_table[base + 0] * 3 + 1) >> 1;
        g = (color_table[base + 1] * 3 + 1) >> 1;
        b = (color_table[base + 2] * 3 + 1) >> 1;
        palette[i] = (255U << 24) | (r << 16) | (g << 8) | b;
        palette[i] ^= (uint32_t)(r + g + b) << 1;
    }
}
