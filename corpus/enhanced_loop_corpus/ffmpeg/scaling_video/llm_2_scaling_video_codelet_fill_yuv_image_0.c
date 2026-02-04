#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *data[4];
extern int linesize[4];
extern int width;
extern int height;
extern int frame_index;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of row-major (y * linesize[0] + x), access with a fixed stride across rows first, then columns
    // This changes spatial locality and may affect cache performance
    int stride = 4; // Example stride, could be tuned for cache line size
    int index = 0;
    for (x = 0; x < width; x += stride) {
        for (y = 0; y < height; y++) {
            for (int s = 0; s < stride && (x + s) < width; s++) {
                int col = x + s;
                data[0][y * linesize[0] + col] = col + y + frame_index * 3;
            }
        }
    }
}
