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
    // Variant 2: Eliminate apparent dependencies by using local temporaries and unrolling the inner loop twice
    // Reduces loop-carried dependencies and exposes independent memory operations
    int stride = 2;
    int ii_aligned = ii - (ii - i0) % stride;

    for (j = j0; j < jj; j++) {
        for (i = i0; i < ii_aligned; i += stride) {
            // Process two iterations independently to break potential WAR/WAW chains
            short val0_0 = all_mv[i][j][1][bw_ref][mode][0];
            short val0_1 = all_mv[i][j][1][bw_ref][mode][1];
            short val1_0 = all_mv[i+1][j][1][bw_ref][mode][0];
            short val1_1 = all_mv[i+1][j][1][bw_ref][mode][1];

            short pval0_0 = pred_mv[i][j][1][bw_ref][mode][0];
            short pval0_1 = pred_mv[i][j][1][bw_ref][mode][1];
            short pval1_0 = pred_mv[i+1][j][1][bw_ref][mode][0];
            short pval1_1 = pred_mv[i+1][j][1][bw_ref][mode][1];

            all_mv8x8[dir][1][i][j][0] = val0_0;
            all_mv8x8[dir][1][i][j][1] = val0_1;
            all_mv8x8[dir][1][i+1][j][0] = val1_0;
            all_mv8x8[dir][1][i+1][j][1] = val1_1;

            pred_mv8x8[dir][1][i][j][0] = pval0_0;
            pred_mv8x8[dir][1][i][j][1] = pval0_1;
            pred_mv8x8[dir][1][i+1][j][0] = pval1_0;
            pred_mv8x8[dir][1][i+1][j][1] = pval1_1;
        }
        // Handle remaining iteration if any
        for (; i < ii; i++) {
            all_mv8x8[dir][1][i][j][0] = all_mv[i][j][1][bw_ref][mode][0];
            all_mv8x8[dir][1][i][j][1] = all_mv[i][j][1][bw_ref][mode][1];
            pred_mv8x8[dir][1][i][j][0] = pred_mv[i][j][1][bw_ref][mode][0];
            pred_mv8x8[dir][1][i][j][1] = pred_mv[i][j][1][bw_ref][mode][1];
        }
    }
}
