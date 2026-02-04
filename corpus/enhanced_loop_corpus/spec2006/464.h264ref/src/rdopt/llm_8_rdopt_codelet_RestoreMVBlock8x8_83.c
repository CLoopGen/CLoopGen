#include <stdio.h>

#include <inttypes.h>

extern short all_mv8x8[2][2][4][4][2];
extern short pred_mv8x8[2][2][4][4][2];
extern int dir;
extern int mode;
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
    // Variant 1: Increased computational intensity by unrolling the inner loop and increasing arithmetic operations
    // Loop unroll factor of 2 applied to inner loop, with trip count adjusted accordingly
    int i_inner;
    for (j = j0; j < jj; j++) {
        i = i0;
        // Unrolled by 2: process two iterations per loop cycle
        for (; i <= ii - 2; i += 2) {
            // First iteration of unroll
            all_mv[i][j][0][ref][mode][0] = all_mv8x8[dir][0][i][j][0] + pred_mv8x8[dir][0][i][j][0];
            all_mv[i][j][0][ref][mode][1] = all_mv8x8[dir][0][i][j][1] + pred_mv8x8[dir][0][i][j][1];
            pred_mv[i][j][0][ref][mode][0] = pred_mv8x8[dir][0][i][j][0] ^ all_mv8x8[dir][0][i][j][0];
            pred_mv[i][j][0][ref][mode][1] = pred_mv8x8[dir][0][i][j][1] ^ all_mv8x8[dir][0][i][j][1];

            // Second iteration of unroll
            all_mv[i+1][j][0][ref][mode][0] = all_mv8x8[dir][0][i+1][j][0] + pred_mv8x8[dir][0][i+1][j][0];
            all_mv[i+1][j][0][ref][mode][1] = all_mv8x8[dir][0][i+1][j][1] + pred_mv8x8[dir][0][i+1][j][1];
            pred_mv[i+1][j][0][ref][mode][0] = pred_mv8x8[dir][0][i+1][j][0] ^ all_mv8x8[dir][0][i+1][j][0];
            pred_mv[i+1][j][0][ref][mode][1] = pred_mv8x8[dir][0][i+1][j][1] ^ all_mv8x8[dir][0][i+1][j][1];
        }
        // Handle remaining iteration if any
        for (; i < ii; i++) {
            all_mv[i][j][0][ref][mode][0] = all_mv8x8[dir][0][i][j][0];
            all_mv[i][j][0][ref][mode][1] = all_mv8x8[dir][0][i][j][1];
            pred_mv[i][j][0][ref][mode][0] = pred_mv8x8[dir][0][i][j][0];
            pred_mv[i][j][0][ref][mode][1] = pred_mv8x8[dir][0][i][j][1];
        }
    }
}
