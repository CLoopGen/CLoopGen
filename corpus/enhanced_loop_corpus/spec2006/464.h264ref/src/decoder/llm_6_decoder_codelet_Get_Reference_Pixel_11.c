#include <stdio.h>

#include <inttypes.h>

extern unsigned short **imY;
extern int y_pos;
extern int x_pos;
extern int x;
extern int y;
extern int maxold_x;
extern int maxold_y;
extern int result;
extern int pres_x;
extern int pres_y;
extern int tmp_res[6];
extern  int COEF[6];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_result[6] = {0}; // Local accumulation to enable reordering
    for (x = -2; x < 4; x++) {
        result = 0;
        pres_x = (x_pos + x < 0) ? 0 : ((x_pos + x > maxold_x) ? maxold_x : x_pos + x);
        for (y = -2; y < 4; y++) {
            pres_y = (y_pos + y < 0) ? 0 : ((y_pos + y > maxold_y) ? maxold_y : y_pos + y);
            result += imY[pres_y][pres_x] * COEF[y + 2];
        }
        temp_result[x + 2] = result; // Break WAW dependency on tmp_res
    }
    // Eliminate loop-carried dependency by writing all at once
    for (int i = 0; i < 6; i++) {
        tmp_res[i] = temp_result[i];
    }
}
