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
        r = color_table[i * 3 + 0];
        g = color_table[i * 3 + 1];
        b = color_table[i * 3 + 2];
        if (r || g || b) { // Skip setting palette entry if all components are zero
            palette[i] = (255U << 24) | (r << 16) | (g << 8) | b;
        }
    }
}
