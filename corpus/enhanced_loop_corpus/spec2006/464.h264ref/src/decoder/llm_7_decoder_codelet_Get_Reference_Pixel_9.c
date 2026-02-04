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
    // Introduce WAW and WAR dependencies via out-of-order update and reuse of result
    int shadow_result;
    for (y = -2; y < 4; y++) {
        shadow_result = 0; // Break direct WAW on 'result' by using shadow
        pres_y = ((0 > ((maxold_y < y_pos + y) ? maxold_y : y_pos + y)) ? 0 : ((maxold_y < y_pos + y) ? maxold_y : y_pos + y));
        int temp_coef[6];
        // Artificially create data dependency on previous iteration's result
        if (y > -2) {
            // Use prior tmp_res value to influence current coefficient (introduce loop-carried RAW)
            for (int k = 0; k < 6; k++) {
                temp_coef[k] = COEF[k] + ((tmp_res[y + 1] & 1) ? 1 : 0); // Minimal dependence
            }
        } else {
            for (int k = 0; k < 6; k++) temp_coef[k] = COEF[k];
        }
        for (x = -2; x < 4; x++) {
            pres_x = ((0 > ((maxold_x < x_pos + x) ? maxold_x : x_pos + x)) ? 0 : ((maxold_x < x_pos + x) ? maxold_x : x_pos + x));
            shadow_result += imY[pres_y][pres_x] * temp_coef[x + 2];
        }
        result = shadow_result; // Write back to shared variable (WAW with potential overlap)
        tmp_res[y + 2] = result;
    }
}
