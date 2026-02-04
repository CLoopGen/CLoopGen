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
    // Flattened loop: reduced nesting by combining indices manually (assuming ii and jj are small and fixed bounds)
    int total_iterations = (ii - i0) * (jj - j0);
    for (int idx = 0; idx < total_iterations; idx++) {
        int i_local = i0 + idx / (jj - j0);  // Recover row index
        int j_local = j0 + idx % (jj - j0);  // Recover column index
        all_mv8x8[dir][1][i_local][j_local][0] = all_mv[i_local][j_local][1][bw_ref][mode][0];
        all_mv8x8[dir][1][i_local][j_local][1] = all_mv[i_local][j_local][1][bw_ref][mode][1];
        pred_mv8x8[dir][1][i_local][j_local][0] = pred_mv[i_local][j_local][1][bw_ref][mode][0];
        pred_mv8x8[dir][1][i_local][j_local][1] = pred_mv[i_local][j_local][1][bw_ref][mode][1];
    }
}
