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
    // Variant 1: Introduce loop-carried dependence by making each iteration depend on the previous one (WAW and RAW)
    // This creates a sequential dependency across 'i' iterations by using a temporary accumulation.
    unsigned short temp;
    for (j = 0; j < 16; j++) {
        temp = 0; // Reset per row
        for (i = 0; i < 16; i++) {
            // Introduce artificial RAW and WAW: current write depends on prior read and write
            temp = refY[ref_inx][pos_y + j][pos_x + i] + temp;
            inY[pos_y + j][pos_x + i] = temp; // Now each write depends on previous iteration
        }
    }
}
