#include <stdio.h>

#include <inttypes.h>

extern short all_mv8x8[2][2][4][4][2];
extern int dir;
extern int i;
extern int j;
extern int i0;
extern int _usr_j0;
extern int ii;
extern int jj;

// Variable name mappings to avoid conflicts with system symbols
#define j0 _usr_j0



void loop(){
    for (j = j0; j < jj; j++) {
        for (i = i0; i < ii; i++) {
            if (i > i0 || j > j0) {
                all_mv8x8[dir][0][i][j][0] = all_mv8x8[dir][0][i-1][j][0];
                all_mv8x8[dir][0][i][j][1] = all_mv8x8[dir][0][i][j-1][1];
                all_mv8x8[dir][1][i][j][0] = all_mv8x8[dir][1][i][j-1][0];
                all_mv8x8[dir][1][i][j][1] = all_mv8x8[dir][1][i-1][j-1][1];
            } else {
                all_mv8x8[dir][0][i][j][0] = 0;
                all_mv8x8[dir][0][i][j][1] = 0;
                all_mv8x8[dir][1][i][j][0] = 0;
                all_mv8x8[dir][1][i][j][1] = 0;
            }
        }
    }
}
