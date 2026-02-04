#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int bking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int prev_l, current_l = bking_loc - 13;
    for (l = current_l; board[l] == 13; ){
        prev_l = current_l;
        current_l -= 13;
        l = current_l;
    }
    l = prev_l;
}
