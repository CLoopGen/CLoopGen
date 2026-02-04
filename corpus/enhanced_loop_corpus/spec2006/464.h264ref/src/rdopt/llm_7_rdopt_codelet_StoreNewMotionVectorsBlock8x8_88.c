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
    // Variant 2: Eliminate data dependencies by unrolling and parallelizing independent operations
    // Remove any potential loop-carried dependencies by accessing disjoint memory locations per iteration
    // Also split the assignments into two separate loops to decouple dependencies between all_mv and pred_mv

    // First loop: handle all_mv updates independently
    for (j = j0; j < jj; j++) {
        for (i = i0; i < ii; i++) {
            int temp0 = all_mv[i][j][0][fw_ref][mode][0];
            int temp1 = all_mv[i][j][0][fw_ref][mode][1];
            all_mv8x8[dir][0][i][j][0] = temp0;
            all_mv8x8[dir][0][i][j][1] = temp1;
        }
    }

    // Second loop: handle pred_mv updates independently (no dependency on first loop writes)
    for (j = j0; j < jj; j++) {
        for (i = i0; i < ii; i++) {
            int temp0 = pred_mv[i][j][0][fw_ref][mode][0];
            int temp1 = pred_mv[i][j][0][fw_ref][mode][1];
            pred_mv8x8[dir][0][i][j][0] = temp0;
            pred_mv8x8[dir][0][i][j][1] = temp1;
        }
    }
}
