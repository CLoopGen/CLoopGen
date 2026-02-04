#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int bking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int prev_l = bking_loc;
    int current_l;
    for (int i = 0; i < 10; ++i) {
        current_l = prev_l - 12;
        if (board[current_l] != 13) break;
        prev_l = current_l;
    }
    l = prev_l - 12;
}
