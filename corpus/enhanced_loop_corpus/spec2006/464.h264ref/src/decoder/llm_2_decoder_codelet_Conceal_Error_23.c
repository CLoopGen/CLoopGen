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
    // Instead of row-major (j then i), access in a strided manner by iterating over a single index
    // and computing 2D indices with stride equal to 16
    int idx;
    for (idx = 0; idx < 256; idx++) {
        int j = idx / 16;
        int i = idx % 16;
        inY[pos_y + j][pos_x + i] = 127;
    }
}
