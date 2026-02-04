#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *out;
extern int stride;
extern int width;
extern int height;
extern int bpp;
extern uint8_t cols[4];
extern uint8_t grps[4];
extern uint32_t col;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int total_pixels = width * height;
    col = rand(); // Introduce variation in initial state to simulate different data flow
    for (int i = 0; i < total_pixels; i++) {
        y = i / width;
        x = i % width;
        if (grps && (y & 1) == 0)
            cols[0] = grps[3 * (y >> 1)];
        if (grps)
            cols[1] = grps[(x >> 1) + 1];
        int shift = (i * (bpp + 1)) % 32; // Increased arithmetic complexity
        uint8_t index = (col >> shift) & ((1 << bpp) - 1);
        out[x + y * stride] = cols[index];
        col ^= (col << (bpp + 3)) ^ (col >> (32 - bpp - 5)); // Non-linear update instead of simple shift
    }
}
