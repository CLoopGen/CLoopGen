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
    for (y = -1; y < 3; y++) {
        pres_y = (maxold_y < y_pos + y) ? maxold_y : y_pos + y;
        if (pres_y < 0) pres_y = 0;
        result += imY[pres_y][pres_x] * COEF[y + 2];
    }
}
