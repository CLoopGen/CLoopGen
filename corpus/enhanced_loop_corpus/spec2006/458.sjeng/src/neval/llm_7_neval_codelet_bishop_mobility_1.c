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
    int local_m[4] = {0};
    for (diridx = 0; diridx < 4; diridx++) {
        int current = square + dir[diridx];
        for (l = current; board[l] == 13; l += dir[diridx]) {
            local_m[diridx]++;
        }
    }
    for (int i = 0; i < 4; i++) {
        m += local_m[i];
    }
}
