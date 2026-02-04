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
    // Variant 2: Reverse indirect access using an index map (simulated via reverse order)
    int *indices = (int*)alloca(color_count * sizeof(int));
    for (int j = 0; j < color_count; j++) {
        indices[j] = color_count - 1 - j; // reverse mapping
    }
    for (i = 0; i < color_count; i++) {
        r = g = b = color_index;
        palette[indices[i]] = (255U << 24) | (r << 16) | (g << 8) | b;
        color_index -= color_dec;
        if (color_index < 0)
            color_index = 0;
    }
}
