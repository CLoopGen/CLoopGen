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
    // Variant 1: Consecutive Memory Access Pattern
    // Reorder nested loops to access memory consecutively by swapping i and j,
    // promoting spatial locality and better cache utilization.
    for (i = i0; i < ii; i++)
        for (j = j0; j < jj; j++) {
            int idx = (i - i0) * (jj - j0) + (j - j0); // Linear index for consecutive pattern
            short* dst_all_x = &all_mv8x8[dir][0][i][j][0];
            short* dst_all_y = &all_mv8x8[dir][0][i][j][1];
            short* dst_pred_x = &pred_mv8x8[dir][0][i][j][0];
            short* dst_pred_y = &pred_mv8x8[dir][0][i][j][1];
            
            short src_all_x = all_mv[i][j][0][fw_ref][mode][0];
            short src_all_y = all_mv[i][j][0][fw_ref][mode][1];
            short src_pred_x = pred_mv[i][j][0][fw_ref][mode][0];
            short src_pred_y = pred_mv[i][j][0][fw_ref][mode][1];

            dst_all_x[0] = src_all_x;
            dst_all_y[0] = src_all_y;
            dst_pred_x[0] = src_pred_x;
            dst_pred_y[0] = src_pred_y;
        }
}
