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
    // Variant 1: Consecutive Memory Access via Loop Interchange and Linear Indexing
    // We flatten the 2D iteration space into a single loop for more sequential access.
    int idx = 0;
    int width = ii - i0;
    int height = jj - j0;
    for (int k = 0; k < width * height; k++) {
        int i = k / height + i0;
        int j = k % height + j0;
        all_mv8x8[dir][0][i][j][0] = all_mv[i][j][0][ref][mode][0];
        all_mv8x8[dir][0][i][j][1] = all_mv[i][j][0][ref][mode][1];
        pred_mv8x8[dir][0][i][j][0] = pred_mv[i][j][0][ref][mode][0];
        pred_mv8x8[dir][0][i][j][1] = pred_mv[i][j][0][ref][mode][1];
    }
}
