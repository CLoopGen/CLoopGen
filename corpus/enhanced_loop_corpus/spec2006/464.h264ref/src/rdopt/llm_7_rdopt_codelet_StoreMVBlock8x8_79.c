#include <stdio.h>

#include <inttypes.h>

extern short all_mv8x8[2][2][4][4][2];
extern short pred_mv8x8[2][2][4][4][2];
extern int dir;
extern int mode;
extern int ref;
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
    // Variant 2: Eliminate potential dependencies by using local temporaries and reordering operations
    // Remove any false dependencies and allow compiler more freedom to optimize/unroll/vectorize
    for (j = j0; j < jj; j++) {
        for (i = i0; i < ii; i++) {
            // Use local temporaries to load input data once (reduces redundant accesses)
            short mv_x = all_mv[i][j][0][ref][mode][0];
            short mv_y = all_mv[i][j][0][ref][mode][1];
            short pmv_x = pred_mv[i][j][0][ref][mode][0];
            short pmv_y = pred_mv[i][j][0][ref][mode][1];

            // Store into output arrays without interference
            all_mv8x8[dir][0][i][j][0] = mv_x;
            all_mv8x8[dir][0][i][j][1] = mv_y;
            pred_mv8x8[dir][0][i][j][0] = pmv_x;
            pred_mv8x8[dir][0][i][j][1] = pmv_y;
        }
    }
}
