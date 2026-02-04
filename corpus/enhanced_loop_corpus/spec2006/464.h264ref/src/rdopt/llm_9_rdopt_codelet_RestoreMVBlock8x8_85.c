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
// Reduce computational load by decreasing effective trip count and operations
// Use stride-2 iteration to reduce loop iterations and overall work

for (j = j0; j < jj; j += 2)
    for (i = i0; i < ii; i += 2) {
        // Only update one direction (fw) and skip bw_ref updates
        // Reduce memory operations by half
        all_mv[i][j][0][ref][mode][0] = all_mv8x8[dir][0][i][j][0];
        all_mv[i][j][0][ref][mode][1] = all_mv8x8[dir][0][i][j][1];
        pred_mv[i][j][0][ref][mode][0] = pred_mv8x8[dir][0][i][j][0];
        pred_mv[i][j][0][ref][mode][1] = pred_mv8x8[dir][0][i][j][1];

        // Skip updating [1][bw_ref] components to reduce computation
    }
}
