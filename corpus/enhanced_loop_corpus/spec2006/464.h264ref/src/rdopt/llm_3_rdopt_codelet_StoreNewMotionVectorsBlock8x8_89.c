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
    // Variant 2: Column-Major Consecutive Memory Access Pattern
    // Reverse loop order to prioritize column-major traversal, improving spatial locality
    // in column-wise data layouts. This creates more consecutive memory writes
    // in the inner loop by fixing j and varying i consecutively.
    for (i = i0; i < ii; i++)
        for (j = j0; j < jj; j++) {
            all_mv8x8[dir][0][i][j][0] = 0;
            all_mv8x8[dir][0][i][j][1] = 0;
        }
}
