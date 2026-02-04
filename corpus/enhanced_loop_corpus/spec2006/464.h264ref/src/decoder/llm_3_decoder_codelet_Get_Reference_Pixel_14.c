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
    // Variant 2: Strided Memory Access with Reverse Coefficient Order
    // Access imY with a fixed stride pattern and reverse the coefficient mapping
    int stride = 2; // Access every second valid y value (simulate strided access pattern)
    int coeff_index;
    for (y = -2; y < 4; y += stride) {
        pres_y = ((0 > ((maxold_y < (y_pos + y)) ? maxold_y : (y_pos + y))) ? 0 : ((maxold_y < (y_pos + y)) ? maxold_y : (y_pos + y)));
        coeff_index = (y + 2); // Original coefficient index
        result += imY[pres_y][pres_x] * COEF[5 - coeff_index]; // Reverse coefficient order
        // Handle intermediate y values in unrolled fashion to maintain semantics
        if (y + 1 < 4 && stride == 2) {
            int y_next = y + 1;
            int pres_y_next = ((0 > ((maxold_y < (y_pos + y_next)) ? maxold_y : (y_pos + y_next))) ? 0 : ((maxold_y < (y_pos + y_next)) ? maxold_y : (y_pos + y_next)));
            result += imY[pres_y_next][pres_x] * COEF[5 - (y_next + 2)];
        }
    }
}
