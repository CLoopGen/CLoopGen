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
    for (y = -3; y < 5; y += 2) {
        int temp_val = y_pos + y;
        pres_y = (temp_val > maxold_y) ? maxold_y : temp_val;
        pres_y = (pres_y < 0) ? 0 : pres_y;
        result += imY[pres_y][pres_x] * COEF[y + 3];
    }
}
