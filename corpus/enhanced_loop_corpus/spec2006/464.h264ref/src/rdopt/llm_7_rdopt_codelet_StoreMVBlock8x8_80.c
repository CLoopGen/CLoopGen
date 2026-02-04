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
    // Variant 2: Eliminate apparent dependencies by using temporary private arrays and unroll-like pattern
    // This reduces loop-carried dependencies and enables potential vectorization
    short local_all[4][4][2] __attribute__((aligned(32))); // Assume ii-i0 <= 4, jj-j0 <= 4
    short local_pred[4][4][2] __attribute__((aligned(32)));

    for (j = j0; j < jj; j++)
        for (i = i0; i < ii; i++) {
            // Remove immediate data flow to global arrays by storing locally first (eliminates RAW/WAR in loop body)
            local_all[i - i0][j - j0][0] = all_mv[i][j][1][bw_ref][mode][0];
            local_all[i - i0][j - j0][1] = all_mv[i][j][1][bw_ref][mode][1];
            local_pred[i - i0][j - j0][0] = pred_mv[i][j][1][bw_ref][mode][0];
            local_pred[i - i0][j - j0][1] = pred_mv[i][j][1][bw_ref][mode][1];
        }

    // Now write back to global arrays in a separate loop (breaks combined read-write dependency in single loop)
    for (j = j0; j < jj; j++)
        for (i = i0; i < ii; i++) {
            all_mv8x8[dir][1][i][j][0] = local_all[i - i0][j - j0][0];
            all_mv8x8[dir][1][i][j][1] = local_all[i - i0][j - j0][1];
            pred_mv8x8[dir][1][i][j][0] = local_pred[i - i0][j - j0][0];
            pred_mv8x8[dir][1][i][j][1] = local_pred[i - i0][j - j0][1];
        }
}
