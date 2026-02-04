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
    // Variant 1: Increased computational intensity with additional arithmetic operations and unrolled inner loop
    for (j = j0; j < jj; j += 2) {
        for (i = i0; i < ii; i += 2) {
            // Unroll 2x2 block and add dummy arithmetic to increase computation per iteration
            int val = (i * j) % 32;
            all_mv8x8[dir][0][i][j][0] = val;
            all_mv8x8[dir][0][i][j][1] = -val;
            if (i + 1 < ii) {
                all_mv8x8[dir][0][i+1][j][0] = val + 1;
                all_mv8x8[dir][0][i+1][j][1] = -(val + 1);
            }
            if (j + 1 < jj) {
                all_mv8x8[dir][0][i][j+1][0] = val + 2;
                all_mv8x8[dir][0][i][j+1][1] = -(val + 2);
            }
            if (i + 1 < ii && j + 1 < jj) {
                all_mv8x8[dir][0][i+1][j+1][0] = val + 3;
                all_mv8x8[dir][0][i+1][j+1][1] = -(val + 3);
            }
        }
    }
}
