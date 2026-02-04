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
    for (int k = 0; k < 2; k++) {
        for (j = j0; j < jj; j++) {
            for (i = i0; i < ii; i++) {
                all_mv8x8[dir][1][i][j][k] = 0;
            }
        }
    }
}
