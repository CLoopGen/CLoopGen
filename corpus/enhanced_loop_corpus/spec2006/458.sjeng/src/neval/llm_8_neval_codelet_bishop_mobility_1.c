#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int square;
extern int l;
extern int m;
extern int diridx;
extern  int dir[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (diridx = 0; diridx < 4; diridx++) {
        int step = dir[diridx];
        for (l = square + step; board[l] == 13 && (l += step, m++, 1); l += step) {
            if (l >= 100) break;
        }
    }
}
