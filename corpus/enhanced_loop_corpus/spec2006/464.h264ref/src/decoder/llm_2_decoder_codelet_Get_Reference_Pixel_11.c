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
for (x = -2; x < 4; x++) {
    result = 0;
    pres_x = (maxold_x < x_pos + x) ? maxold_x : x_pos + x;
    pres_x = (pres_x < 0) ? 0 : pres_x;
    int base_y = y_pos - 2;
    for (y = 0; y < 6; y++) {
        int current_y = base_y + y;
        pres_y = (current_y < 0) ? 0 : ((current_y < maxold_y) ? current_y : maxold_y);
        if (pres_y == maxold_y) pres_y = maxold_y - 1;
        result += imY[pres_y][pres_x] * COEF[y];
    }
    tmp_res[x + 2] = result;
}
}
