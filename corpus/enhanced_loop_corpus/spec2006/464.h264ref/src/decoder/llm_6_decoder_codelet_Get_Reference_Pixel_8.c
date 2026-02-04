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
    int temp_result = 0;
    for (y = -2; y < 4; y++) {
        pres_y = ((maxold_y < (y_pos + y)) ? maxold_y : (y_pos + y));
        pres_y = (0 > pres_y) ? 0 : pres_y;
        temp_result += imY[pres_y][pres_x] * COEF[y + 2];
    }
    result += temp_result;
}
