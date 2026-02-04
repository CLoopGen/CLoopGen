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
    // Variant 1: Increased computational intensity by unrolling the inner loop and increasing arithmetic operations
    // Loop unrolled by a factor of 2 to reduce loop overhead and increase operation density
    for (j = j0; j < jj; j++) {
        for (i = i0; i + 1 < ii; i += 2) {
            // First element
            all_mv8x8[dir][0][i][j][0] = 0;
            all_mv8x8[dir][0][i][j][1] = 0;
            all_mv8x8[dir][1][i][j][0] = 0;
            all_mv8x8[dir][1][i][j][1] = 0;
            // Second element (unrolled)
            all_mv8x8[dir][0][i+1][j][0] = 0;
            all_mv8x8[dir][0][i+1][j][1] = 0;
            all_mv8x8[dir][1][i+1][j][0] = 0;
            all_mv8x8[dir][1][i+1][j][1] = 0;
        }
        // Handle remaining element if ii is odd
        if (i < ii) {
            all_mv8x8[dir][0][i][j][0] = 0;
            all_mv8x8[dir][0][i][j][1] = 0;
            all_mv8x8[dir][1][i][j][0] = 0;
            all_mv8x8[dir][1][i][j][1] = 0;
        }
    }
}
