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
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of accessing imY[pres_y][pres_x] with varying pres_x, we precompute a consecutive window
    // around x_pos and access elements in increasing order to improve cache locality.
    int base_x = (x_pos - 2 > 0) ? x_pos - 2 : 0;
    int limit_x = ((maxold_x) < (x_pos + 3)) ? (x_pos + 3) : maxold_x;
    int adjusted_start = (base_x == 0) ? -2 + base_x - (x_pos - 2) : -2;

    result = 0; // Reset result for clean accumulation
    for (x = adjusted_start; x < 4; x++) {
        int offset = x + 2;
        int effective_x = base_x + offset;
        if (effective_x >= 0 && effective_x < limit_x) {
            pres_x = effective_x;
            result += imY[pres_y][pres_x] * COEF[offset];
        }
    }
}
