#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int wking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int prev_l = wking_loc;
    for (l = wking_loc - 12; board[l] == 13; ) {
        prev_l = l;
        l -= 12;
        board[prev_l] = board[prev_l]; // Artificial WAW dependency: self-assignment to prevent optimization
    }
}
