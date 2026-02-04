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
    // Variant 1: Consecutive Memory Access via Pointer Arithmetic
    // Instead of repeated 2D array indexing, use a pointer to traverse imY rows consecutively
    unsigned short *base_ptr = imY[pres_y]; // Fixed base row (pres_y unchanged in loop)
    int coeff_offset = 0;
    for (y = -2; y < 4; y++) {
        pres_y = ((0 > ((maxold_y < (y_pos + y)) ? maxold_y : (y_pos + y))) ? 0 : ((maxold_y < (y_pos + y)) ? maxold_y : (y_pos + y)));
        result += *(imY[pres_y] + pres_x) * COEF[coeff_offset];
        coeff_offset++;
    }
}
