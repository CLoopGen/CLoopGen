#include <stdio.h>

#include <inttypes.h>

extern short all_mv8x8[2][2][4][4][2];
extern short pred_mv8x8[2][2][4][4][2];
extern int dir;
extern int mode;
extern int ref;
extern int bw_ref;
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
    // This creates a WAW (Write-After-Write) and RAW (Read-After-Write) dependency across iterations
    short temp_val[2][2] = {{0}}; // Local state to carry forward values

    for (j = j0; j < jj; j++) {
        for (i = i0; i < ii; i++) {
            // Use value from previous iteration (i-1 or j-1) to create loop-carried dependence
            int prev_i = (i > i0) ? i - 1 : i0;
            int prev_j = (j > j0) ? j - 1 : j0;

            // Carry over a transformed value from previous iteration to create RAW/WAW
            all_mv[i][j][0][ref][mode][0] = all_mv8x8[dir][0][i][j][0] + temp_val[0][0];
            all_mv[i][j][0][ref][mode][1] = all_mv8x8[dir][0][i][j][1] + temp_val[0][1];
            pred_mv[i][j][0][ref][mode][0] = pred_mv8x8[dir][0][i][j][0] + temp_val[1][0];
            pred_mv[i][j][0][ref][mode][1] = pred_mv8x8[dir][0][i][j][1] + temp_val[1][1];

            all_mv[i][j][1][bw_ref][mode][0] = all_mv8x8[dir][1][i][j][0] + temp_val[0][0];
            all_mv[i][j][1][bw_ref][mode][1] = all_mv8x8[dir][1][i][j][1] + temp_val[0][1];
            pred_mv[i][j][1][bw_ref][mode][0] = pred_mv8x8[dir][1][i][j][0] + temp_val[1][0];
            pred_mv[i][j][1][bw_ref][mode][1] = pred_mv8x8[dir][1][i][j][1] + temp_val[1][1];

            // Update temp_val with current written values (WAW on temp_val)
            temp_val[0][0] = all_mv8x8[dir][0][i][j][0];
            temp_val[0][1] = all_mv8x8[dir][0][i][j][1];
            temp_val[1][0] = pred_mv8x8[dir][0][i][j][0];
            temp_val[1][1] = pred_mv8x8[dir][0][i][j][1];
        }
    }
}
