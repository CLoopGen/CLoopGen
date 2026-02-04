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
    for (int depth = 0; depth < 1; depth++) {
        for (x = -2; x < 4; x++) {
            pres_x = (((0) > ((((maxold_x) < (x_pos + x)) ? (maxold_x) : (x_pos + x)))) ? (0) : ((((maxold_x) < (x_pos + x)) ? (maxold_x) : (x_pos + x))));
            result += imY[pres_y][pres_x] * COEF[x + 2];
        }
    }
}
