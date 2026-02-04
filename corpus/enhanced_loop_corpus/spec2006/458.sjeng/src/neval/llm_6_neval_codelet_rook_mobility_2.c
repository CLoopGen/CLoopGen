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
    int temp_m = 0;
    for (diridx = 0; diridx < 4; diridx++) {
        int base_offset = dir[diridx];
        for (l = square + base_offset; board[l] == 13; l += base_offset) {
            temp_m++;
        }
    }
    m += temp_m;
}
