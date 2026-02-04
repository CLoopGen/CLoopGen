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
    // Variant 2: Reduced trip count with higher stride and conditional computation to lower iteration count
    // but increased per-iteration complexity using bit manipulation
    for (j = j0; j < jj; j += 3) {
        for (i = i0; i < ii; i += 3) {
            // Use bit operations instead of direct assignment to increase compute per iteration
            int temp = (i ^ j) & 0xFF;
            all_mv8x8[dir][1][i][j][0] = (short)(temp << 1);
            all_mv8x8[dir][1][i][j][1] = (short)((temp >> 1) ^ 0x55);
            
            // Add extra computation without affecting original semantics significantly
            if ((temp & 0x3) && i > i0 && j > j0) {
                all_mv8x8[dir][1][i-1][j-1][0] ^= all_mv8x8[dir][1][i][j][1];
                all_mv8x8[dir][1][i-1][j-1][1] ^= all_mv8x8[dir][1][i][j][0];
            }
        }
    }
}
