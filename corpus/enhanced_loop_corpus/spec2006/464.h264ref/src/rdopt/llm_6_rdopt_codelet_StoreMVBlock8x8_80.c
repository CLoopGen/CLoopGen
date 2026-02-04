#include <stdio.h>

#include <inttypes.h>

extern short all_mv8x8[2][2][4][4][2];
extern short pred_mv8x8[2][2][4][4][2];
extern int dir;
extern int mode;
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
    // Variant 1: Introduce loop-carried WAW dependency by accumulating values instead of direct assignment
    short temp_val_0 = 0, temp_val_1 = 0;
    for (j = j0; j < jj; j++)
        for (i = i0; i < ii; i++) {
            // Accumulate values across iterations (introduces loop-carried WAW dependency on temp variables)
            temp_val_0 += all_mv[i][j][1][bw_ref][mode][0];
            temp_val_1 += all_mv[i][j][1][bw_ref][mode][1];
            all_mv8x8[dir][1][i][j][0] = temp_val_0;
            all_mv8x8[dir][1][i][j][1] = temp_val_1;
            pred_mv8x8[dir][1][i][j][0] = pred_mv[i][j][1][bw_ref][mode][0];
            pred_mv8x8[dir][1][i][j][1] = pred_mv[i][j][1][bw_ref][mode][1];
        }
}
