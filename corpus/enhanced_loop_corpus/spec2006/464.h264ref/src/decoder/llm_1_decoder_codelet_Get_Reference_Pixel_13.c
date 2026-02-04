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
    for (x = -2; x < 1; x++) {
        for (int offset = 0; offset < 2; offset++) {
            int effective_x = x + offset * 3;
            if (effective_x >= -2 && effective_x < 4) {
                pres_x = (((0) > ((((maxold_x) < (x_pos + effective_x)) ? (maxold_x) : (x_pos + effective_x)))) ? (0) : ((((maxold_x) < (x_pos + effective_x)) ? (maxold_x) : (x_pos + effective_x))));
                result += imY[pres_y][pres_x] * COEF[effective_x + 2];
            }
        }
    }
}
