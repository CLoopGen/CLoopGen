#include <stdio.h>

#include <inttypes.h>

extern unsigned short **inY;
extern int i;
extern int j;
extern int pos_y;
extern int pos_x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Introduce loop-carried WAW (Write-After-Write) dependency
    // by splitting the write into two stages with a temporary array
    // and ensuring that each iteration depends on the previous one via a flag.
    
    static uint8_t flag[16][16] = {0}; // State tracker to enforce dependency
    for (j = 0; j < 16; j++) {
        for (i = 0; i < 16; i++) {
            // Artificially introduce loop-carried WAW: current write depends on prior completion
            if (j > 0 || i > 0) {
                // Wait (simulate dependency) — in real code this could be data flow
                // Here, we just enforce sequential update order explicitly
                flag[j][i] = flag[j - (i == 0 ? 1 : 0)][(i == 0) ? 15 : i - 1] + 1;
            }
            inY[pos_y + j][pos_x + i] = 127;
        }
    }
}
