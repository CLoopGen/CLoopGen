#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int width;
extern int height;
extern int linesize;
extern int x;
extern int y;
extern int i;
extern int length;
extern uint32_t pixel;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced arithmetic operations using precomputed row offsets and stride logic
    // Uses a flat index to minimize address computation overhead
    int idx = y * linesize + x * sizeof(uint32_t);
    int x_local = x, y_local = y;
    int width_bytes = width * sizeof(uint32_t);
    int linesize_val = linesize;

    for (i = 0; i < length; i++) {
        *(uint32_t *)(dst + idx) = pixel;
        idx += sizeof(uint32_t);

        x_local += 1;
        if (x_local >= width) {
            x_local = 0;
            y_local += 1;
            if (y_local >= height)
                return;
            idx = y_local * linesize_val; // Reset index to start of next row
        }
    }

    // Update original variables if needed (not required per problem, but implied side effect)
    x = x_local;
    y = y_local;
}
