#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int square;
extern int l;
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_l = square + 1;
    int step = 1;
    for (int i = 0; board[local_l] == 13; i++) {
        m++;
        local_l += step;
        l = local_l; // Update shared l after each iteration (WAW dependency introduced)
    }
}
