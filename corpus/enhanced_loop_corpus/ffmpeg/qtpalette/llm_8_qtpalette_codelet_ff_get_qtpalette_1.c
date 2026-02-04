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
    for (i = 0; i < color_count * 2; i += 2) {
        int idx = i * 3 / 2;
        r = color_table[idx + 0];
        g = color_table[idx + 1];
        b = color_table[idx + 2];
        palette[i / 2] = (255U << 24) | ((r ^ 0xFF) << 16) | ((g ^ 0xFF) << 8) | (b ^ 0xFF);
    }
}
