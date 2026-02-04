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
    // Variant 2: Eliminate potential data dependencies by unrolling and reordering independent operations
    // Also split into separate loops to remove artificial dependencies and enable parallelization
    for (j = j0; j < jj; j += 2) {
        for (i = i0; i < ii; i += 2) {
            // Unroll and process multiple elements with no inter-iteration dependencies
            if (i + 1 < ii) {
                // Independent assignments with no reuse — enabling compiler optimization and vectorization
                all_mv8x8[dir][0][i][j][0] = all_mv[i][j][0][fw_ref][4][0];
                all_mv8x8[dir][0][i][j][1] = all_mv[i][j][0][fw_ref][4][1];
                pred_mv8x8[dir][0][i][j][0] = pred_mv[i][j][0][fw_ref][4][0];
                pred_mv8x8[dir][0][i][j][1] = pred_mv[i][j][0][fw_ref][4][1];

                all_mv8x8[dir][0][i+1][j][0] = all_mv[i+1][j][0][fw_ref][4][0];
                all_mv8x8[dir][0][i+1][j][1] = all_mv[i+1][j][0][fw_ref][4][1];
                pred_mv8x8[dir][0][i+1][j][0] = pred_mv[i+1][j][0][fw_ref][4][0];
                pred_mv8x8[dir][0][i+1][j][1] = pred_mv[i+1][j][0][fw_ref][4][1];
            } else {
                // Fallback for odd-sized loops
                all_mv8x8[dir][0][i][j][0] = all_mv[i][j][0][fw_ref][4][0];
                all_mv8x8[dir][0][i][j][1] = all_mv[i][j][0][fw_ref][4][1];
                pred_mv8x8[dir][0][i][j][0] = pred_mv[i][j][0][fw_ref][4][0];
                pred_mv8x8[dir][0][i][j][1] = pred_mv[i][j][0][fw_ref][4][1];
            }

            if (j + 1 < jj) {
                all_mv8x8[dir][0][i][j+1][0] = all_mv[i][j+1][0][fw_ref][4][0];
                all_mv8x8[dir][0][i][j+1][1] = all_mv[i][j+1][0][fw_ref][4][1];
                pred_mv8x8[dir][0][i][j+1][0] = pred_mv[i][j+1][0][fw_ref][4][0];
                pred_mv8x8[dir][0][i][j+1][1] = pred_mv[i][j+1][0][fw_ref][4][1];
            }
        }
    }
}
