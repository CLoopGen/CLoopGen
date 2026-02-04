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
    // Variant 2: Eliminate apparent dependencies by unrolling and reordering accesses to break sequential patterns
    // This reduces loop-carried dependencies by decoupling adjacent writes and introducing independent updates
    int stride = 2;
    // Ensure we don't exceed bounds with unrolling
    int ii_unroll = ii - (ii - i0) % stride;
    int jj_unroll = jj - (jj - j0) % stride;

    for (j = j0; j < jj_unroll; j += stride)
        for (i = i0; i < ii_unroll; i += stride) {
            // Unroll i dimension
            for (int di = 0; di < stride; di++)
                for (int dj = 0; dj < stride; dj++) {
                    int idx_i = i + di;
                    int idx_j = j + dj;
                    // Independent assignments with no inter-iteration data flow
                    all_mv[idx_i][idx_j][1][bw_ref][mode][0] = all_mv8x8[dir][1][idx_i][idx_j][0];
                    all_mv[idx_i][idx_j][1][bw_ref][mode][1] = all_mv8x8[dir][1][idx_i][idx_j][1];
                    pred_mv[idx_i][idx_j][1][bw_ref][mode][0] = pred_mv8x8[dir][1][idx_i][idx_j][0];
                    pred_mv[idx_i][idx_j][1][bw_ref][mode][1] = pred_mv8x8[dir][1][idx_i][idx_j][1];
                }
        }

    // Handle remaining elements not covered by unrolling
    for (j = jj_unroll; j < jj; j++)
        for (i = i0; i < ii; i++) {
            all_mv[i][j][1][bw_ref][mode][0] = all_mv8x8[dir][1][i][j][0];
            all_mv[i][j][1][bw_ref][mode][1] = all_mv8x8[dir][1][i][j][1];
            pred_mv[i][j][1][bw_ref][mode][0] = pred_mv8x8[dir][1][i][j][0];
            pred_mv[i][j][1][bw_ref][mode][1] = pred_mv8x8[dir][1][i][j][1];
        }

    for (j = j0; j < jj_unroll; j++)
        for (i = ii_unroll; i < ii; i++) {
            all_mv[i][j][1][bw_ref][mode][0] = all_mv8x8[dir][1][i][j][0];
            all_mv[i][j][1][bw_ref][mode][1] = all_mv8x8[dir][1][i][j][1];
            pred_mv[i][j][1][bw_ref][mode][0] = pred_mv8x8[dir][1][i][j][0];
            pred_mv[i][j][1][bw_ref][mode][1] = pred_mv8x8[dir][1][i][j][1];
        }
}
