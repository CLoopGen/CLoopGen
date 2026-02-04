#include <stdio.h>

#include <inttypes.h>

extern short all_mv8x8[2][2][4][4][2];
extern short pred_mv8x8[2][2][4][4][2];
extern int dir;
extern int ref;
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
    short prev_val_i = 0, prev_val_j = 0;
    for (j = j0; j < jj; j++) {
        for (i = i0; i < ii; i++) {
            // Use result from previous write to create loop-carried dependency
            all_mv[i][j][0][ref][4][0] = all_mv8x8[dir][0][i][j][0] + prev_val_i;
            all_mv[i][j][0][ref][4][1] = all_mv8x8[dir][0][i][j][1] + prev_val_j;
            pred_mv[i][j][0][ref][4][0] = pred_mv8x8[dir][0][i][j][0] + all_mv[i][j][0][ref][4][0];
            pred_mv[i][j][0][ref][4][1] = pred_mv8x8[dir][0][i][j][1] + all_mv[i][j][0][ref][4][1];

            // Update "previous" values to be used in next iteration (carried dependency)
            prev_val_i = all_mv[i][j][0][ref][4][0];
            prev_val_j = all_mv[i][j][0][ref][4][1];
        }
    }
}
