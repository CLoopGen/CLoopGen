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
    // Variant 2: Consecutive (Linearized) Memory Access Pattern
    // Flatten the 2D iteration into a single loop to ensure consecutive memory access
    // This improves spatial locality assuming row-major layout
    int idx;
    for (idx = 0; idx < 256; idx++) {
        int flat_j = idx / 16;  // Row index
        int flat_i = idx % 16;  // Column index
        inY[pos_y + flat_j][pos_x + flat_i] = refY[ref_inx][pos_y + flat_j][pos_x + flat_i];
    }
}
