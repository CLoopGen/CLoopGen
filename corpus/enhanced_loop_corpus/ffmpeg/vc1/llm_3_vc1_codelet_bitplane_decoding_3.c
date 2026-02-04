#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern int y;
extern uint8_t invert;
extern uint8_t *planep;
extern int width;
extern int height;
extern int stride;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with transposed traversal order
    // We change the loop nesting to iterate over columns first (x), then rows (y)
    // This creates a strided access pattern across `planep` due to non-consecutive row accesses

    if (width <= 1 || height <= 1) return;

    for (x = 1; x < width; x++) {
        for (y = 1; y < height; y++) {
            uint8_t *current = planep + y * stride + x;
            uint8_t *left = current - 1;
            uint8_t *above = current - stride;

            if (*left != *above)
                *current ^= invert;
            else
                *current ^= *left;
        }
    }
}
