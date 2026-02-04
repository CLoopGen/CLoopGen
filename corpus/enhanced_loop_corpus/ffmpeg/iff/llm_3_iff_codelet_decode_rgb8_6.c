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
    // Variant 2: Strided memory access with fixed row stride
    // We change access pattern to use a strided step based on linesize,
    // simulating a scenario where rows are accessed with gaps (e.g., image padding).
    // Here, we still write one pixel at a time but use linesize as a fixed stride.
    for (i = 0; i < length; i++) {
        int offset = y * linesize + x * sizeof(uint32_t);
        *(uint32_t *)(dst + offset) = pixel;
        x += 1;
        if (x >= width) {
            y += 1;
            if (y >= height)
                return;
            x = 0;
        }
    }
}
