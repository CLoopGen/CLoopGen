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
for (x = -1; x < 3; x++) {
    result = 0;
    pres_x = (0 > ((maxold_x < x_pos + x) ? maxold_x : x_pos + x)) ? 0 : ((maxold_x < x_pos + x) ? maxold_x : x_pos + x);
    for (y = -1; y < 3; y++) {
        pres_y = (0 > ((maxold_y < y_pos + y) ? maxold_y : y_pos + y)) ? 0 : ((maxold_y < y_pos + y) ? maxold_y : y_pos + y);
        result += imY[pres_y][pres_x] * COEF[y + 1];
    }
    tmp_res[x + 1] = result;
}
}
