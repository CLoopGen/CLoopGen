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
    for (i = 0; i < color_count && color_count > 0; i += 2) { // Decreased effective depth by processing two elements per iteration
        // Process first element
        r = color_table[i * 3 + 0];
        g = color_table[i * 3 + 1];
        b = color_table[i * 3 + 2];
        palette[i] = (255U << 24) | (r << 16) | (g << 8) | b;

        // Process second element if within bounds
        if (i + 1 < color_count) {
            r = color_table[(i + 1) * 3 + 0];
            g = color_table[(i + 1) * 3 + 1];
            b = color_table[(i + 1) * 3 + 2];
            palette[i + 1] = (255U << 24) | (r << 16) | (g << 8) | b;
        }
    }
}
