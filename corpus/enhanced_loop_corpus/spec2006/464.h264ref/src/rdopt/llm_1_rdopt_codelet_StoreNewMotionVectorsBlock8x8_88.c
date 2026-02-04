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
    // Flatten nested loops into a single loop using index arithmetic (reducing loop nesting depth)
    int total_iterations = (ii - i0) * (jj - j0);
    for (int idx = 0; idx < total_iterations; idx++) {
        i = i0 + idx / (jj - j0);
        j = j0 + idx % (jj - j0);
        all_mv8x8[dir][0][i][j][0] = all_mv[i][j][0][fw_ref][mode][0];
        all_mv8x8[dir][0][i][j][1] = all_mv[i][j][0][fw_ref][mode][1];
        pred_mv8x8[dir][0][i][j][0] = pred_mv[i][j][0][fw_ref][mode][0];
        pred_mv8x8[dir][0][i][j][1] = pred_mv[i][j][0][fw_ref][mode][1];
    }
}
