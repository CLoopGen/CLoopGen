#include <stdio.h>

#include <inttypes.h>

extern short all_mv8x8[2][2][4][4][2];
extern short pred_mv8x8[2][2][4][4][2];
extern int dir;
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
    // Variant 1: Introduce loop-carried dependency (WAW and RAW) by making each iteration depend on the previous one
    short temp_i = 0, temp_j = 0;
    for (j = j0; j < jj; j++) {
        for (i = i0; i < ii; i++) {
            // Create a WAW and RAW dependency: current write depends on prior read/write
            all_mv8x8[dir][0][i][j][0] = all_mv[i][j][0][fw_ref][4][0] + temp_i;
            all_mv8x8[dir][0][i][j][1] = all_mv[i][j][0][fw_ref][4][1] + temp_j;
            pred_mv8x8[dir][0][i][j][0] = pred_mv[i][j][0][fw_ref][4][0] + all_mv8x8[dir][0][i][j][0];
            pred_mv8x8[dir][0][i][j][1] = pred_mv[i][j][0][fw_ref][4][1] + all_mv8x8[dir][0][i][j][1];

            // Update temp values that will be used in next iteration (loop-carried dependency)
            temp_i = all_mv8x8[dir][0][i][j][0];
            temp_j = all_mv8x8[dir][0][i][j][1];
        }
    }
}
