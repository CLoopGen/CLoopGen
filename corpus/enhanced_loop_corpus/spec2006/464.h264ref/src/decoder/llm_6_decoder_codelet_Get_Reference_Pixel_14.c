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
    for (int i = 0; i < 6; i++) {
        int y_val = i - 2;
        int local_pres_y = ((0) > ((maxold_y < y_pos + y_val) ? maxold_y : y_pos + y_val)) ? 0 : ((maxold_y < y_pos + y_val) ? maxold_y : y_pos + y_val);
        temp_result += imY[local_pres_y][pres_x] * COEF[i];
    }
    result += temp_result;
}
