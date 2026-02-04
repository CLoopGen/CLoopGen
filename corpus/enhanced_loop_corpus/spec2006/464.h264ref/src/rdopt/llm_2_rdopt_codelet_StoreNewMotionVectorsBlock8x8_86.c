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
    // Variant 1: Consecutive memory access by flattening the inner loop into a single dimension
    // This exploits spatial locality by accessing adjacent memory locations sequentially
    int idx;
    int base_offset = dir * 2 * 4 * 4 * 2 + 0; // all_mv8x8[dir][0] start offset
    int stride_8x8 = 4 * 4 * 2; // each [i][j][2] block has 32 elements (4*4*2)
    for (idx = 0; idx < (ii - i0) * (jj - j0); idx++) {
        int i = i0 + idx / (jj - j0);
        int j = j0 + idx % (jj - j0);
        
        short* p0 = &all_mv8x8[dir][0][i][j][0];
        short* p1 = &all_mv8x8[dir][1][i][j][0];
        
        p0[0] = 0; p0[1] = 0;
        p1[0] = 0; p1[1] = 0;
    }
}
