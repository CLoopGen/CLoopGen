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
    for (j = j0; j < jj; j++)
        for (i = i0; i < ii; i++) {
            // Introduce temporary variables to break direct data dependencies
            short temp_all_x = all_mv[i][j][0][ref][4][0];
            short temp_all_y = all_mv[i][j][0][ref][4][1];
            short temp_pred_x = pred_mv[i][j][0][ref][4][0];
            short temp_pred_y = pred_mv[i][j][0][ref][4][1];

            // Write to output arrays using temporaries, eliminating potential RAW hazards
            all_mv8x8[dir][0][i][j][0] = temp_all_x;
            all_mv8x8[dir][0][i][j][1] = temp_all_y;
            pred_mv8x8[dir][0][i][j][0] = temp_pred_x;
            pred_mv8x8[dir][0][i][j][1] = temp_pred_y;
        }
}
