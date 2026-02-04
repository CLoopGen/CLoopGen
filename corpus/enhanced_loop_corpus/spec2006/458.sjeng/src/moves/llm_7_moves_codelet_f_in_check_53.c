#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int bking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int prev_l;
    for (prev_l = bking_loc - 1, l = bking_loc - 1; board[l] == 13; prev_l = l, l -= 1)
        ; // Add loop-carried dependence using prev_l to track prior index (RAW: read after write)
}
