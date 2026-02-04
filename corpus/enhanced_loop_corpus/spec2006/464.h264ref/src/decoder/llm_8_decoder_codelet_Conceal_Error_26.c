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
int j_start = 0;
int j_end = 8; // Reduced trip count to decrease computational intensity
for (j = j_start; j < j_end; j++) {
    for (i = 0; i < 16; i += 2) { // Increased step size to reduce iterations
        inY[pos_y + j][pos_x + i] = refY[ref_inx][pos_y + j][pos_x + i];
        // Unrolled one iteration manually to maintain some operation count
        if (i + 1 < 16) {
            inY[pos_y + j][pos_x + i + 1] = refY[ref_inx][pos_y + j][pos_x + i + 1];
        }
    }
}
}
