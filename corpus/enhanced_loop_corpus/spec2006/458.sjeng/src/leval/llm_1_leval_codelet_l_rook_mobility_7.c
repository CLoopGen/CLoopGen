#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int square;
extern int l;
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int outer_l = square + 12; outer_l < 144 && board[outer_l] == 13; outer_l += 12) {
        l = outer_l;
        m++;
        break;
    }
}
