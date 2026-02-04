#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int wking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int prev_l = wking_loc;
    int curr_l;
    for (curr_l = wking_loc - 12; board[curr_l] == 13; ) {
        curr_l -= 12;
        prev_l = curr_l;
    }
    l = prev_l;
}
