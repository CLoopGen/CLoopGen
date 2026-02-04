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
    // Variant 2: Reduced computational intensity with decreased trip count and simplified access pattern
    // Reduce effective work by iterating every other element and skipping one dimension
    // Only process half the data in both i and j dimensions

    for (j = j0; j < jj; j += 2) {
        for (i = i0; i < ii; i += 2) {
            // Skip bw_ref path entirely, only copy forward reference motion vectors
            all_mv8x8[dir][0][i][j][0] = all_mv[i][j][0][ref][mode][0];
            all_mv8x8[dir][0][i][j][1] = all_mv[i][j][0][ref][mode][1];
            pred_mv8x8[dir][0][i][j][0] = pred_mv[i][j][0][ref][mode][0];
            pred_mv8x8[dir][0][i][j][1] = pred_mv[i][j][0][ref][mode][1];

            // Leave backward component untouched (assume initialized elsewhere)
            // This reduces total memory operations by 50%
        }
    }

    // No need for handling remainder since we're intentionally subsampling
}
