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
int j_start = j0;
int j_end = jj;
int i_start = i0;
int i_step = 1;
int j_step = 1;

for (j = j_start; j < j_end; j += j_step)
    for (i = i_start; i < ii; i += i_step) {
        // Unroll the inner loop by a factor of 2 to increase computational intensity
        if (i + 0 < ii) {
            all_mv[i+0][j][0][ref][mode][0] = all_mv8x8[dir][0][i+0][j][0];
            all_mv[i+0][j][0][ref][mode][1] = all_mv8x8[dir][0][i+0][j][1];
            pred_mv[i+0][j][0][ref][mode][0] = pred_mv8x8[dir][0][i+0][j][0];
            pred_mv[i+0][j][0][ref][mode][1] = pred_mv8x8[dir][0][i+0][j][1];
            all_mv[i+0][j][1][bw_ref][mode][0] = all_mv8x8[dir][1][i+0][j][0];
            all_mv[i+0][j][1][bw_ref][mode][1] = all_mv8x8[dir][1][i+0][j][1];
            pred_mv[i+0][j][1][bw_ref][mode][0] = pred_mv8x8[dir][1][i+0][j][0];
            pred_mv[i+0][j][1][bw_ref][mode][1] = pred_mv8x8[dir][1][i+0][j][1];
        }
        if (i + 1 < ii) {
            all_mv[i+1][j][0][ref][mode][0] = all_mv8x8[dir][0][i+1][j][0];
            all_mv[i+1][j][0][ref][mode][1] = all_mv8x8[dir][0][i+1][j][1];
            pred_mv[i+1][j][0][ref][mode][0] = pred_mv8x8[dir][0][i+1][j][0];
            pred_mv[i+1][j][0][ref][mode][1] = pred_mv8x8[dir][0][i+1][j][1];
            all_mv[i+1][j][1][bw_ref][mode][0] = all_mv8x8[dir][1][i+1][j][0];
            all_mv[i+1][j][1][bw_ref][mode][1] = all_mv8x8[dir][1][i+1][j][1];
            pred_mv[i+1][j][1][bw_ref][mode][0] = pred_mv8x8[dir][1][i+1][j][0];
            pred_mv[i+1][j][1][bw_ref][mode][1] = pred_mv8x8[dir][1][i+1][j][1];
        }
    }
}
