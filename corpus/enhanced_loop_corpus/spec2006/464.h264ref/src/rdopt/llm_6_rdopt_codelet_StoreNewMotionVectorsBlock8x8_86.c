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
    int temp0, temp1, temp2, temp3;
    for (j = j0; j < jj; j++)
        for (i = i0; i < ii; i++) {
            temp0 = 0;
            temp1 = 0;
            temp2 = 0;
            temp3 = 0;
            all_mv8x8[dir][0][i][j][0] = temp0;
            all_mv8x8[dir][0][i][j][1] = temp1;
            all_mv8x8[dir][1][i][j][0] = temp2;
            all_mv8x8[dir][1][i][j][1] = temp3;
        }
}
