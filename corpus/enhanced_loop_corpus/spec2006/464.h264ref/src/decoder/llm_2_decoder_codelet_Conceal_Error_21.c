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
    // Variant 1: Consecutive (linearized) memory access using pointer arithmetic
    unsigned short *inY_base = &inY[pos_y][pos_x];
    unsigned short *refY_base = &refY[ref_inx][pos_y][pos_x];
    for (int idx = 0; idx < 256; idx++) {
        inY_base[idx] = refY_base[idx];
    }
}
