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
    // Variant 2: Reduced computational intensity with increased trip count via splitting dimensions
    // Instead of a 2D loop over [i0,ii) x [j0,jj), we flatten into a single loop with higher trip count
    // Each iteration does less work, but total iterations increase due to expanded indexing
    int total = (ii - i0) * (jj - j0) * 2;  // Double the effective trip count
    for (int idx = 0; idx < total; idx++) {
        int flat_idx = idx / 2;           // Map back to original index
        int subop = idx % 2;              // Alternate between mv types
        i = i0 + (flat_idx % (ii - i0));
        j = j0 + (flat_idx / (ii - i0));

        if (j >= jj) continue;  // Safety bound check

        if (subop == 0) {
            all_mv8x8[dir][0][i][j][0] = all_mv[i][j][0][fw_ref][mode][0];
            all_mv8x8[dir][0][i][j][1] = all_mv[i][j][0][fw_ref][mode][1];
        } else {
            pred_mv8x8[dir][0][i][j][0] = pred_mv[i][j][0][fw_ref][mode][0];
            pred_mv8x8[dir][0][i][j][1] = pred_mv[i][j][0][fw_ref][mode][1];
        }
    }
}
