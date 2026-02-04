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
    for (diridx = 0; diridx < 2; diridx++) {
        for (int offset = 0; offset < 2; offset++) {
            int temp_dir = dir[diridx * 2 + offset];
            for (l = square + temp_dir; board[l] == 13; l += temp_dir) {
                m++;
            }
        }
    }
}
