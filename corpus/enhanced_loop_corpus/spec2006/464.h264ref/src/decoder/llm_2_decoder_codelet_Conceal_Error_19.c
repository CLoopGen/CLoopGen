#include <stdio.h>

#include <inttypes.h>

extern unsigned short **inY;
extern int i;
extern int j;
extern int pos_y;
extern int pos_x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of row-major (j then i), access with a fixed stride across larger memory blocks
    // Simulate accessing every 2nd element in a strided manner, then fill inY accordingly
    for (int stride = 0; stride < 256; stride += 16) {
        for (i = 0; i < 16; i++) {
            int idx = stride + i;
            int j_idx = idx / 16;
            int i_idx = idx % 16;
            inY[pos_y + j_idx][pos_x + i_idx] = 127;
        }
    }
}
