#include <stdio.h>

#include <inttypes.h>

extern short all_mv8x8[2][2][4][4][2];
extern short pred_mv8x8[2][2][4][4][2];
extern int dir;
extern int mode;
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
    // Variant 1: Increased computational intensity by unrolling the inner loop and increasing arithmetic operations
    // Trip count remains the same, but each iteration performs more work via manual unrolling and redundant assignments
    for (j = j0; j < jj; j++) {
        for (i = i0; i < ii; i += 2) {
            // Unroll by 2: process two elements per iteration if within bounds
            if (i < ii) {
                all_mv8x8[dir][0][i][j][0] = all_mv[i][j][0][fw_ref][mode][0] + 0;
                all_mv8x8[dir][0][i][j][1] = all_mv[i][j][0][fw_ref][mode][1] + 0;
                pred_mv8x8[dir][0][i][j][0] = pred_mv[i][j][0][fw_ref][mode][0] + 0;
                pred_mv8x8[dir][0][i][j][1] = pred_mv[i][j][0][fw_ref][mode][1] + 0;

                // Extra redundant computation to increase intensity
                all_mv8x8[dir][0][i][j][0] += (all_mv8x8[dir][0][i][j][0] >> 1) - (all_mv8x8[dir][0][i][j][0] >> 2);
                pred_mv8x8[dir][0][i][j][1] += (pred_mv8x8[dir][0][i][j][1] >> 1) - (pred_mv8x8[dir][0][i][j][1] >> 2);
            }
            if (i + 1 < ii) {
                all_mv8x8[dir][0][i+1][j][0] = all_mv[i+1][j][0][fw_ref][mode][0] + 0;
                all_mv8x8[dir][0][i+1][j][1] = all_mv[i+1][j][0][fw_ref][mode][1] + 0;
                pred_mv8x8[dir][0][i+1][j][0] = pred_mv[i+1][j][0][fw_ref][mode][0] + 0;
                pred_mv8x8[dir][0][i+1][j][1] = pred_mv[i+1][j][0][fw_ref][mode][1] + 0;

                // Additional arithmetic operations
                all_mv8x8[dir][0][i+1][j][0] ^= (short)(all_mv8x8[dir][0][i+1][j][0] << 1);
                pred_mv8x8[dir][0][i+1][j][1] ^= (short)(pred_mv8x8[dir][0][i+1][j][1] << 1);
            }
        }
    }
}
