#include <stdio.h>

#include <inttypes.h>

extern unsigned short **imY;
extern int y_pos;
extern int x_pos;
extern int x;
extern int y;
extern int maxold_x;
extern int maxold_y;
extern int result;
extern int pres_x;
extern int pres_y;
extern int tmp_res[6];
extern  int COEF[6];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_accum[6] = {0}; // Local accumulation to modify data dependency pattern
    for (y = -2; y < 4; y++) {
        pres_y = ((0 > ((maxold_y < y_pos + y) ? maxold_y : y_pos + y)) ? 0 : ((maxold_y < y_pos + y) ? maxold_y : y_pos + y));
        for (x = -2; x < 4; x++) {
            pres_x = ((0 > ((maxold_x < x_pos + x) ? maxold_x : x_pos + x)) ? 0 : ((maxold_x < x_pos + x) ? maxold_x : x_pos + x));
            temp_accum[y + 2] += imY[pres_y][pres_x] * COEF[x + 2];
        }
    }
    // Eliminate loop-carried dependency by decoupling write-back
    for (int i = 0; i < 6; i++) {
        tmp_res[i] = temp_accum[i];
    }
}
