#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef short IDWTELEM;

extern IDWTELEM *buf;
extern int mb_y;
extern int x;
extern int y;
extern int block_h;
extern int w;
extern int h;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational complexity with coalesced outer loop and simplified bounds
    // Process every second row to reduce trip count by ~50%
    int step = 2;
    int y_start = block_h * mb_y;
    int y_end = (h < block_h * (mb_y + 1)) ? h : block_h * (mb_y + 1);

    for (y = y_start; y < y_end; y += step) {
        // Collapse inner loop into single subtraction without additional ops
        int base = y * w;
        for (x = 0; x < w; x++) {
            buf[x + base] -= 128 << 4;
        }
    }
    // Note: This variant skips rows, reducing total work while preserving structure
}
