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
    // Variant 1: Increased computational intensity with unrolled inner operations and doubled trip count effect
    for (j = j0; j < jj; j++) {
        for (i = i0; i < ii; i += 2) {  // Adjusted step to influence effective trip count
            // First iteration of potential unroll
            if (i + 0 < ii) {
                all_mv8x8[dir][0][i+0][j][0] = all_mv[i+0][j][0][ref][4][0] + 1;
                all_mv8x8[dir][0][i+0][j][1] = all_mv[i+0][j][0][ref][4][1] - 1;
                pred_mv8x8[dir][0][i+0][j][0] = pred_mv[i+0][j][0][ref][4][0] + 1;
                pred_mv8x8[dir][0][i+0][j][1] = pred_mv[i+0][j][0][ref][4][1] - 1;
            }
            // Second (unrolled) iteration
            if (i + 1 < ii) {
                all_mv8x8[dir][0][i+1][j][0] = all_mv[i+1][j][0][ref][4][0] + 1;
                all_mv8x8[dir][0][i+1][j][1] = all_mv[i+1][j][0][ref][4][1] - 1;
                pred_mv8x8[dir][0][i+1][j][0] = pred_mv[i+1][j][0][ref][4][0] + 1;
                pred_mv8x8[dir][0][i+1][j][1] = pred_mv[i+1][j][0][ref][4][1] - 1;
            }
        }
    }
}
