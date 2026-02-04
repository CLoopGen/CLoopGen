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
    for (j = j0; j < jj; j++)
        for (i = i0; i < ii; i++) {
            short temp_all_00 = all_mv[i][j][0][ref][mode][0];
            short temp_all_01 = all_mv[i][j][0][ref][mode][1];
            short temp_pred_00 = pred_mv[i][j][0][ref][mode][0];
            short temp_pred_01 = pred_mv[i][j][0][ref][mode][1];
            short temp_all_10 = all_mv[i][j][1][bw_ref][mode][0];
            short temp_all_11 = all_mv[i][j][1][bw_ref][mode][1];
            short temp_pred_10 = pred_mv[i][j][1][bw_ref][mode][0];
            short temp_pred_11 = pred_mv[i][j][1][bw_ref][mode][1];

            all_mv8x8[dir][0][i][j][0] = temp_all_00;
            all_mv8x8[dir][0][i][j][1] = temp_all_01;
            pred_mv8x8[dir][0][i][j][0] = temp_pred_00;
            pred_mv8x8[dir][0][i][j][1] = temp_pred_01;
            all_mv8x8[dir][1][i][j][0] = temp_all_10;
            all_mv8x8[dir][1][i][j][1] = temp_all_11;
            pred_mv8x8[dir][1][i][j][0] = temp_pred_10;
            pred_mv8x8[dir][1][i][j][1] = temp_pred_11;
        }
}
