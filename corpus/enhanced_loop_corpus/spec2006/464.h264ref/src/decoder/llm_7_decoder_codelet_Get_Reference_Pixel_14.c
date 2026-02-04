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
    result = 0;
    int prev_pres_y = 0;
    for (y = -2; y < 4; y++) {
        pres_y = ((maxold_y < y_pos + y) ? maxold_y : y_pos + y);
        if (pres_y < 0) pres_y = 0;
        int coef_index = y + 2;
        // Introduce artificial loop-carried dependence via reuse of previous pres_y
        if (y > -2) {
            result += imY[pres_y][pres_x] * COEF[coef_index] + imY[prev_pres_y][pres_x] * 1;
        } else {
            result += imY[pres_y][pres_x] * COEF[coef_index];
        }
        prev_pres_y = pres_y;
    }
}
