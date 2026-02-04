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
    // This creates a sequential dependency across 'i' by using a temporary accumulation that carries forward.
    unsigned short temp = 0;
    for (j = 0; j < 16; j++) {
        for (i = 0; i < 16; i++) {
            temp = refY[ref_inx][pos_y + j][pos_x + i] + temp; // RAW: uses previous temp
            inY[pos_y + j][pos_x + i] = temp; // WAW: temp is overwritten, and write to inY now depends on order
        }
    }
}
