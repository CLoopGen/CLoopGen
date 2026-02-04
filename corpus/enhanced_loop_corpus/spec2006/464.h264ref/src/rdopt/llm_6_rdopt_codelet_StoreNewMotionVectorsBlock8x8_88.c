#include <stdio.h>

#include <inttypes.h>

extern short all_mv8x8[2][2][4][4][2];
extern short pred_mv8x8[2][2][4][4][2];
extern int dir;
extern int mode;
extern int fw_ref;
extern int i;
extern int j;
extern int i0;
extern int _usr_j0;
extern int ii;
extern int jj;
extern short ******all_mv;
extern short ******pred_mv;

// Variable name mappings to avoid conflicts with system symbols
#define j0 _usr_j0



void loop(){
    // Variant 1: Introduce loop-carried dependence by making each iteration depend on the previous one
    // This creates a WAW (Write-After-Write) and potential RAW (Read-After-Write) dependency across iterations
    short prev_all[2] = {0, 0};
    short prev_pred[2] = {0, 0};

    for (j = j0; j < jj; j++) {
        for (i = i0; i < ii; i++) {
            // Now current write depends on previous iteration's result
            all_mv8x8[dir][0][i][j][0] = all_mv[i][j][0][fw_ref][mode][0] + prev_all[0];
            all_mv8x8[dir][0][i][j][1] = all_mv[i][j][0][fw_ref][mode][1] + prev_all[1];
            pred_mv8x8[dir][0][i][j][0] = pred_mv[i][j][0][fw_ref][mode][0] + prev_pred[0];
            pred_mv8x8[dir][0][i][j][1] = pred_mv[i][j][0][fw_ref][mode][1] + prev_pred[1];

            // Update previous values to create loop-carried dependency
            prev_all[0] = all_mv8x8[dir][0][i][j][0];
            prev_all[1] = all_mv8x8[dir][0][i][j][1];
            prev_pred[0] = pred_mv8x8[dir][0][i][j][0];
            prev_pred[1] = pred_mv8x8[dir][0][i][j][1];
        }
    }
}
