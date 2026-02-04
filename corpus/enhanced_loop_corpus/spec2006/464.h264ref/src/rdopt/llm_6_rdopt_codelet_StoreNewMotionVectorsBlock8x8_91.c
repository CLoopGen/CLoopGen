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
    // Variant 1: Introduce loop-carried dependence by making each iteration depend on the previous one
    // This creates a WAW (Write-After-Write) and RAW (Read-After-Write) dependency through a temporary variable.
    int prev_val = 0;
    for (j = j0; j < jj; j++) {
        for (i = i0; i < ii; i++) {
            int temp = all_mv8x8[dir][1][i][j][0] + prev_val; // RAW: depends on previous iteration's prev_val
            all_mv8x8[dir][1][i][j][0] = 0;
            all_mv8x8[dir][1][i][j][1] = 0;
            prev_val = temp; // WAW: updates shared state used in next iteration
        }
    }
}
