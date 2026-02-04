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
    for (int outer = -2; outer < 4; outer += 6) {
        for (y = outer; y < outer + 6 && y < 4; y++) {
            pres_y = ((0 > ((maxold_y < (y_pos + y)) ? maxold_y : (y_pos + y))) ? 0 : ((maxold_y < (y_pos + y)) ? maxold_y : (y_pos + y)));
            result += imY[pres_y][pres_x] * COEF[y + 2];
        }
    }
}
