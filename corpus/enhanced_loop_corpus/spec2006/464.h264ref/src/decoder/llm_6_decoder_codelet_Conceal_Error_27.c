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
    // Variant 1: Introduce loop-carried dependence by making each iteration depend on the previous one (WAW + RAW)
    // This creates a sequential dependency across 'i' iterations by using a temporary accumulation that carries forward.
    unsigned short temp = 0;
    for (j = 0; j < 16; j++) {
        temp = 0; // Reset per row
        for (i = 0; i < 16; i++) {
            // Introduce artificial WAW and RAW: write then read temp, carried across i
            temp = refY[ref_inx][pos_y + j][pos_x + i] + temp; // Accumulate
            inY[pos_y + j][pos_x + i] = temp; // Dependence on prior write to temp
        }
    }
}
