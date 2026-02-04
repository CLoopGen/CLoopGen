#include <stdio.h>

#include <inttypes.h>

extern unsigned short **imY;
extern int y_pos;
extern int y;
extern int maxold_y;
extern int result;
extern int pres_x;
extern int pres_y;
extern  int COEF[6];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access (unrolled with sequential access pattern)
    // We precompute pres_y values and access imY in a more predictable, consecutive manner.
    int temp_pres_y[6];
    for (int i = -2; i < 4; i++) {
        temp_pres_y[i + 2] = (((0) > ((((maxold_y) < (y_pos + i)) ? (maxold_y) : (y_pos + i)))) ? (0) : ((((maxold_y) < (y_pos + i)) ? (maxold_y) : (y_pos + i))));
    }
    // Now perform accesses in increasing order of memory (assuming row-major, consecutive rows)
    for (int i = 0; i < 6; i++) {
        pres_x = pres_x; // preserve original pres_x usage
        result += imY[temp_pres_y[i]][pres_x] * COEF[i];
    }
}
