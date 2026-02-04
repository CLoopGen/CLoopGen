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
    // Variant 2: Strided Memory Access
    // Instead of accessing imY with computed pres_y in natural order, use a strided access pattern
    // Here we simulate stride-2 access by processing every other element first, then the rest.
    // This changes spatial locality and may affect cache behavior.

    // First pass: process y indices with even offset (relative to base -2)
    for (y = -2; y < 4; y += 2) {
        pres_y = (((0) > ((((maxold_y) < (y_pos + y)) ? (maxold_y) : (y_pos + y)))) ? (0) : ((((maxold_y) < (y_pos + y)) ? (maxold_y) : (y_pos + y))));
        result += imY[pres_y][pres_x] * COEF[y + 2];
    }
    // Second pass: process remaining (odd offsets)
    for (y = -1; y < 4; y += 2) {
        pres_y = (((0) > ((((maxold_y) < (y_pos + y)) ? (maxold_y) : (y_pos + y)))) ? (0) : ((((maxold_y) < (y_pos + y)) ? (maxold_y) : (y_pos + y))));
        result += imY[pres_y][pres_x] * COEF[y + 2];
    }
}
