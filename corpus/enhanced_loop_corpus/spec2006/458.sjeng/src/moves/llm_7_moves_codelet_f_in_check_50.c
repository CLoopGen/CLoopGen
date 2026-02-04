#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int bking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int prev_l = bking_loc;
    for (int offset = 12; board[prev_l + offset] == 13; offset += 12) {
        l = prev_l + offset;
        prev_l = l;
    }
    l = prev_l + 12;
}
