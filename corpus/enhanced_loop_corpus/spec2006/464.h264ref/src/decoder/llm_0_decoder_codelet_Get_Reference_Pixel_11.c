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
    // Variant 1: Increased loop nesting depth by splitting the original logic into three nested loops
    // The innermost loop now iterates over a dummy range to increase nesting depth without changing computation.
    for (x = -2; x < 4; x++) {
        result = 0;
        pres_x = (((0) > ((((maxold_x) < (x_pos + x)) ? (maxold_x) : (x_pos + x)))) ? (0) : ((((maxold_x) < (x_pos + x)) ? (maxold_x) : (x_pos + x))));
        for (y = -2; y < 4; y++) {
            pres_y = (((0) > ((((maxold_y) < (y_pos + y)) ? (maxold_y) : (y_pos + y)))) ? (0) : ((((maxold_y) < (y_pos + y)) ? (maxold_y) : (y_pos + y))));
            for (int k = 0; k < 1; k++) {  // Artificially increased nesting depth
                result += imY[pres_y][pres_x] * COEF[y + 2];
            }
        }
        tmp_res[x + 2] = result;
    }
}
