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
    // Variant 2: Reduced computational intensity with collapsed nested loops and reduced trip count via stride
    // Use a single loop with stride 2 on both dimensions to reduce total iterations by ~75%
    int idx = 0;
    int total_j = (jj - j0 + 1) / 2;
    int total_i = (ii - i0 + 1) / 2;

    for (idx = 0; idx < total_i * total_j; idx++) {
        int i = i0 + 2 * (idx / total_j);
        int j = j0 + 2 * (idx % total_j);

        // Only update every 2nd element, reducing memory operations and arithmetic
        all_mv8x8[dir][1][i][j][0] = all_mv[i][j][1][bw_ref][mode][0];
        all_mv8x8[dir][1][i][j][1] = all_mv[i][j][1][bw_ref][mode][1];
        pred_mv8x8[dir][1][i][j][0] = pred_mv[i][j][1][bw_ref][mode][0];
        pred_mv8x8[dir][1][i][j][1] = pred_mv[i][j][1][bw_ref][mode][1];
    }
}
