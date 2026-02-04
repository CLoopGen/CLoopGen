#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int wking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int prev_l = wking_loc;
    int next_l = wking_loc - 13;
    for (; board[next_l] == 13; ) {
        prev_l = next_l;
        next_l -= 13;
    }
    l = prev_l;
}
