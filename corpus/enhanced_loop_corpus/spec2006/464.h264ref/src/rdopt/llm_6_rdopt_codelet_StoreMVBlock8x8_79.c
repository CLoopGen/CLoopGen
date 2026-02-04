#include <stdio.h>

#include <inttypes.h>

extern short all_mv8x8[2][2][4][4][2];
extern short pred_mv8x8[2][2][4][4][2];
extern int dir;
extern int mode;
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
    // Variant 1: Introduce loop-carried dependence by making each iteration depend on the previous one (WAW and RAW)
    // This creates a sequential dependency across 'i' iterations, forcing execution order.
    short temp_val[2] = {0, 0};
    for (j = j0; j < jj; j++) {
        for (i = i0; i < ii; i++) {
            // Artificially introduce dependency: current value depends on prior iteration
            all_mv8x8[dir][0][i][j][0] = all_mv[i][j][0][ref][mode][0] + temp_val[0];
            all_mv8x8[dir][0][i][j][1] = all_mv[i][j][0][ref][mode][1] + temp_val[1];
            pred_mv8x8[dir][0][i][j][0] = pred_mv[i][j][0][ref][mode][0] + all_mv8x8[dir][0][i][j][0];
            pred_mv8x8[dir][0][i][j][1] = pred_mv[i][j][0][ref][mode][1] + all_mv8x8[dir][0][i][j][1];

            // Update temp_val to carry forward last written values (creates WAW/RAW loop-carried dep)
            temp_val[0] = all_mv8x8[dir][0][i][j][0];
            temp_val[1] = all_mv8x8[dir][0][i][j][1];
        }
    }
}
