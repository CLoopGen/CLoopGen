#include <stdio.h>

#include <inttypes.h>

extern unsigned short **inY;
extern unsigned short ***refY;
extern int i;
extern int j;
extern int ref_inx;
extern int pos_y;
extern int pos_x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Introduce loop-carried dependence by eliminating parallelism
    // Sequential update introduces WAW (Write-After-Write) and RAW (Read-After-Write) dependencies
    // Elements are updated in row-major order with a single loop, creating loop-carried dependency
    int idx;
    for (idx = 0; idx < 256; idx++) {
        int j = idx / 16;
        int i = idx % 16;
        inY[pos_y + j][pos_x + i] = refY[ref_inx][pos_y + j][pos_x + i];
        // Artificially introduce a dependency: each write affects the next read via inY
        if (idx > 0) {
            // Use previous value to create RAW/WAW chain
            inY[pos_y + j][pos_x + i] += inY[pos_y + (idx-1)/16][pos_x + (idx-1)%16] & 0xFFFF;
        }
    }
}
