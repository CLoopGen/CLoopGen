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
    int temp = 0;
    for (x = -2; x < 4; x++) {
        int idx = x + 2;
        int access_x = (x_pos + x);
        if (access_x > maxold_x) access_x = maxold_x;
        if (access_x < 0) access_x = 0;
        temp += imY[pres_y][access_x] * local_COEF[idx];
    }
    result = temp;
}
