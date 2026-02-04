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
    for (j = j0; j < jj; j++) {
        for (i = i0; i < ii; i++) {
            // Introduce artificial loop-carried dependency on 'i' to create WAW and RAW dependencies
            if (i > i0 || j > j0) {
                all_mv8x8[dir][0][i][j][0] = all_mv8x8[dir][0][i-1 >= i0 ? i-1 : i][j-1 >= j0 ? j-1 : j][0];
                pred_mv8x8[dir][0][i][j][0] = pred_mv8x8[dir][0][i-1 >= i0 ? i-1 : i][j-1 >= j0 ? j-1 : j][0];
            }
            // Base assignments with modified indexing order to break natural dependencies
            all_mv8x8[dir][0][i][j][1] = all_mv[i][j][0][ref][mode][1];
            pred_mv8x8[dir][0][i][j][1] = pred_mv[i][j][0][ref][mode][1];
            all_mv8x8[dir][1][i][j][0] = all_mv[i][j][1][bw_ref][mode][0];
            all_mv8x8[dir][1][i][j][1] = all_mv[i][j][1][bw_ref][mode][1];
            pred_mv8x8[dir][1][i][j][0] = pred_mv[i][j][1][bw_ref][mode][0];
            pred_mv8x8[dir][1][i][j][1] = pred_mv[i][j][1][bw_ref][mode][1];
        }
    }
}
