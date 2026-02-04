#include <stdio.h>

#include <inttypes.h>

extern int squaresize[4];
extern int nsquares[4];
extern int j;
extern int dir;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access pattern
    // Instead of sequential dir index, use a fixed stride (e.g., +2 with modulo wrap)
    int stride = 2;
    for (int idx = 0; idx < 4; idx += stride) {
        int dir = idx % 4;  // Ensure within bounds
        if (squaresize[dir] == j && nsquares[dir] > 1)
            break;
    }
}
