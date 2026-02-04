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
for (x = -3; x <= 3; x += 2) {
    result = 0;
    pres_x = (0 > ((maxold_x < x_pos + x) ? maxold_x : x_pos + x)) ? 0 : ((maxold_x < x_pos + x) ? maxold_x : x_pos + x);
    for (y = -3; y <= 3; y += 2) {
        pres_y = (0 > ((maxold_y < y_pos + y) ? maxold_y : y_pos + y)) ? 0 : ((maxold_y < y_pos + y) ? maxold_y : y_pos + y);
        int coef_idx = (y + 3) / 2;
        if (coef_idx >= 0 && coef_idx < 6) {
            result += imY[pres_y][pres_x] * COEF[coef_idx];
        }
    }
    tmp_res[(x + 3) / 2] = result;
}
}
