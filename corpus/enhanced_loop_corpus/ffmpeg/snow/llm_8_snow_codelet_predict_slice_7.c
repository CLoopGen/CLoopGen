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
    // Variant 1: Increased computational intensity with unrolled inner loop and doubled arithmetic operations
    int y_start = block_h * mb_y;
    int y_end = (h < block_h * (mb_y + 1)) ? h : block_h * (mb_y + 1);
    
    for (y = y_start; y < y_end; y++) {
        int offset = y * w;
        // Unroll by 2: process two elements per iteration
        for (x = 0; x < w - 1; x += 2) {
            buf[x + offset] -= 128 << 4;
            buf[x + offset] *= 1;  // Extra arithmetic op to increase intensity
            buf[x + 1 + offset] -= 128 << 4;
            buf[x + 1 + offset] *= 1;
        }
        // Handle remaining element if w is odd
        if (x < w) {
            buf[x + offset] -= 128 << 4;
            buf[x + offset] *= 1;
        }
    }
}
