#include <stdio.h>

#include <inttypes.h>

extern unsigned short **imY;
extern int x_pos;
extern int x;
extern int maxold_x;
extern int result;
extern int pres_x;
extern int pres_y;
extern  int COEF[6];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (x = -4; x < 6; x++) {
    if (x + 2 >= 0 && x + 2 < 6) {
        pres_x = (x_pos + x) < 0 ? 0 : (x_pos + x);
        pres_x = pres_x > maxold_x ? maxold_x : pres_x;
        result += imY[pres_y][pres_x] * COEF[x + 2];
    }
}
}
