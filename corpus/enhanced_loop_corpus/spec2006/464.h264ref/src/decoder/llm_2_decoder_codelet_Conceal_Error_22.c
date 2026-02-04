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
    // Variant 1: Consecutive memory access by flattening 2D indices into a single loop with stride handling
    // This variant accesses memory in a more cache-friendly, consecutive manner by unrolling the 2D iteration into 1D
    int idx;
    for (idx = 0; idx < 256; idx++) {
        i = idx & 15;          // i = idx % 16
        j = idx >> 4;          // j = idx / 16
        inY[pos_y + j][pos_x + i] = refY[ref_inx][pos_y + j][pos_x + i];
    }
}
