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
    // Variant 1: Increased computational intensity by unrolling the inner loop and increasing arithmetic operations
    // Loop unroll factor of 2 applied to the inner loop (i-loop), with trip count adjusted accordingly
    int i_end = ii - (ii - i0) % 2; // Make sure we don't exceed bounds after unrolling
    for (j = j0; j < jj; j++) {
        for (i = i0; i < i_end; i += 2) {
            // First iteration of unrolled loop
            all_mv[i][j][1][bw_ref][mode][0] = all_mv8x8[dir][1][i][j][0] + (all_mv8x8[dir][1][i][j][0] >> 1);
            all_mv[i][j][1][bw_ref][mode][1] = all_mv8x8[dir][1][i][j][1] - (all_mv8x8[dir][1][i][j][1] >> 2);
            pred_mv[i][j][1][bw_ref][mode][0] = pred_mv8x8[dir][1][i][j][0] + (pred_mv8x8[dir][1][i][j][0] >> 1);
            pred_mv[i][j][1][bw_ref][mode][1] = pred_mv8x8[dir][1][i][j][1] - (pred_mv8x8[dir][1][i][j][1] >> 2);

            // Second iteration of unrolled loop
            all_mv[i+1][j][1][bw_ref][mode][0] = all_mv8x8[dir][1][i+1][j][0] + (all_mv8x8[dir][1][i+1][j][0] >> 1);
            all_mv[i+1][j][1][bw_ref][mode][1] = all_mv8x8[dir][1][i+1][j][1] - (all_mv8x8[dir][1][i+1][j][1] >> 2);
            pred_mv[i+1][j][1][bw_ref][mode][0] = pred_mv8x8[dir][1][i+1][j][0] + (pred_mv8x8[dir][1][i+1][j][0] >> 1);
            pred_mv[i+1][j][1][bw_ref][mode][1] = pred_mv8x8[dir][1][i+1][j][1] - (pred_mv8x8[dir][1][i+1][j][1] >> 2);
        }
        // Handle remaining iteration if any
        if (i < ii) {
            all_mv[i][j][1][bw_ref][mode][0] = all_mv8x8[dir][1][i][j][0] + (all_mv8x8[dir][1][i][j][0] >> 1);
            all_mv[i][j][1][bw_ref][mode][1] = all_mv8x8[dir][1][i][j][1] - (all_mv8x8[dir][1][i][j][1] >> 2);
            pred_mv[i][j][1][bw_ref][mode][0] = pred_mv8x8[dir][1][i][j][0] + (pred_mv8x8[dir][1][i][j][0] >> 1);
            pred_mv[i][j][1][bw_ref][mode][1] = pred_mv8x8[dir][1][i][j][1] - (pred_mv8x8[dir][1][i][j][1] >> 2);
        }
    }
}
