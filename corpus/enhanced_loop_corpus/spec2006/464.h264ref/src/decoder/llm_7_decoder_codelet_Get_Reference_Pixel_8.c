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
    int local_COEF[6];
    for (int i = 0; i < 6; i++) {
        local_COEF[i] = COEF[i];
    }
    int temp_result = 0;
    for (y = -2; y < 4; y++) {
        int idx = y + 2;
        int current_pres_y = (y_pos + y);
        if (current_pres_y > maxold_y) current_pres_y = maxold_y;
        if (current_pres_y < 0) current_pres_y = 0;
        temp_result += imY[current_pres_y][pres_x] * local_COEF[idx];
    }
    result = temp_result;
}
