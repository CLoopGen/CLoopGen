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
    // Loop unroll factor of 2 applied to inner loop, with trip count adjustment
    int j_inc = 2;
    for (j = j0; j < jj - (jj % j_inc); j += j_inc) {
        for (i = i0; i < ii; i++) {
            // First element of unrolled pair
            all_mv8x8[dir][1][i][j][0] = all_mv[i][j][1][bw_ref][mode][0] + pred_mv[i][j][1][bw_ref][mode][1];
            all_mv8x8[dir][1][i][j][1] = all_mv[i][j][1][bw_ref][mode][1] - pred_mv[i][j][1][bw_ref][mode][0];
            pred_mv8x8[dir][1][i][j][0] = pred_mv[i][j][1][bw_ref][mode][0] ^ all_mv[i][j][1][bw_ref][mode][1];
            pred_mv8x8[dir][1][i][j][1] = pred_mv[i][j][1][bw_ref][mode][1] & all_mv[i][j][1][bw_ref][mode][0];

            // Second element of unrolled pair
            all_mv8x8[dir][1][i][j+1][0] = all_mv[i][j+1][1][bw_ref][mode][0] + pred_mv[i][j+1][1][bw_ref][mode][1];
            all_mv8x8[dir][1][i][j+1][1] = all_mv[i][j+1][1][bw_ref][mode][1] - pred_mv[i][j+1][1][bw_ref][mode][0];
            pred_mv8x8[dir][1][i][j+1][0] = pred_mv[i][j+1][1][bw_ref][mode][0] ^ all_mv[i][j+1][1][bw_ref][mode][1];
            pred_mv8x8[dir][1][i][j+1][1] = pred_mv[i][j+1][1][bw_ref][mode][1] & all_mv[i][j+1][1][bw_ref][mode][0];
        }
    }
    // Handle remainder iterations
    for (; j < jj; j++) {
        for (i = i0; i < ii; i++) {
            all_mv8x8[dir][1][i][j][0] = all_mv[i][j][1][bw_ref][mode][0];
            all_mv8x8[dir][1][i][j][1] = all_mv[i][j][1][bw_ref][mode][1];
            pred_mv8x8[dir][1][i][j][0] = pred_mv[i][j][1][bw_ref][mode][0];
            pred_mv8x8[dir][1][i][j][1] = pred_mv[i][j][1][bw_ref][mode][1];
        }
    }
}
