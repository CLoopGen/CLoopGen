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
        int current_dir = dir[diridx];
        int temp = square + current_dir;
        if (board[temp] == 13) {
            for (l = temp; board[l] == 13; l += current_dir)
                m++;
        }
    }
}
