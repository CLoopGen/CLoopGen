#include <stdio.h>

#include <inttypes.h>

extern unsigned short **imY;
extern int x_pos;
extern int x;
extern int maxold_x;
extern int result;
extern int pres_x;
extern int pres_y;
extern  int COEF[6];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access (unrolled and restructured for spatial locality)
    int base_x = x_pos - 2;
    int temp_result = 0;
    // Ensure bounds are respected while accessing consecutive elements
    for (int offset = 0; offset < 6; offset++) {
        int x_val = base_x + offset;
        int bounded_x = (x_val < 0) ? 0 : ((x_val > maxold_x) ? maxold_x : x_val);
        temp_result += imY[pres_y][bounded_x] * COEF[offset];
    }
    result += temp_result;
}
