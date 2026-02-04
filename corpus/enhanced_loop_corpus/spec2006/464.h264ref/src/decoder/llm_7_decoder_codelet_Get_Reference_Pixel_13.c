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
    int local_COEF[6];
    for (int i = 0; i < 6; i++) {
        local_COEF[i] = COEF[i];
    }
    int acc = 0;
    for (x = -2; x < 4; x++) {
        int idx = x + 2;
        int temp_x = (x_pos + x);
        if (temp_x > maxold_x) temp_x = maxold_x;
        if (temp_x < 0) temp_x = 0;
        acc += imY[pres_y][temp_x] * local_COEF[idx];
    }
    result = acc;
}
