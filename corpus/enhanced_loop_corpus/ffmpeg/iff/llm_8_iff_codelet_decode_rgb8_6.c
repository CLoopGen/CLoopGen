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
    // Variant 1: Increased computational intensity with unrolled loop (factor of 2)
    // Also reduces trip count by processing two pixels per iteration when possible
    int remaining = length;
    for (i = 0; i < length && remaining > 0; i++) {
        // First pixel
        *(uint32_t *)(dst + y * linesize + x * sizeof(uint32_t)) = pixel;
        x += 1;
        remaining -= 1;
        
        // Adjust coordinates if crossing width boundary
        if (x >= width) {
            y += 1;
            if (y >= height)
                return;
            x = 0;
        }
        
        // Second pixel (unrolled)
        if (remaining > 1) {
            *(uint32_t *)(dst + y * linesize + x * sizeof(uint32_t)) = pixel;
            x += 1;
            remaining -= 1;

            if (x >= width) {
                y += 1;
                if (y >= height)
                    return;
                x = 0;
            }
        }
    }
}
