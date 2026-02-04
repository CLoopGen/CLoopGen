#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int square;
extern int l;
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int prev_l = square + 12;
    for (l = square + 12; board[l] == 13; ) {
        m++;
        prev_l = l;
        l += 12;
        if (board[prev_l] != board[l - 12]) break;
    }
}
