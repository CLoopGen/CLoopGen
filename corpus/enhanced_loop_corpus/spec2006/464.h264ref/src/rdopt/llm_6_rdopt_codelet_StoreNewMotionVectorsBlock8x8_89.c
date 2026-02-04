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
    // Variant 1: Introduce loop-carried WAW (Write-After-Write) dependency by splitting writes and reordering operations
    // This variant introduces artificial sequential dependence by writing to a temporary location first,
    // then copying in a subsequent independent loop. The second loop now carries a dependence on the first.
    int temp[4][4][2];
    
    for (j = j0; j < jj; j++)
        for (i = i0; i < ii; i++) {
            temp[i][j][0] = 0;
            temp[i][j][1] = 0;
        }

    for (j = j0; j < jj; j++)
        for (i = i0; i < ii; i++) {
            all_mv8x8[dir][0][i][j][0] = temp[i][j][0];
            all_mv8x8[dir][0][i][j][1] = temp[i][j][1];
        }
}
