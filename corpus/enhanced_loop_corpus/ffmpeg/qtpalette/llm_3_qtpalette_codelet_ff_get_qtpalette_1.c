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
    // Variant 2: Strided Access with Reverse Iteration
    for (i = color_count - 1; i >= 0; i--) {
        r = color_table[i * 3 + 0];
        g = color_table[i * 3 + 1];
        b = color_table[i * 3 + 2];
        palette[i] = (255U << 24) | (r << 16) | (g << 8) | b;
    }
}
