#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int bking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int prev_l = bking_loc + 11;
    int next_l;
    for (l = prev_l; board[l] == 13; prev_l = next_l) {
        next_l = l + 11;
        l = next_l;
    }
}
