#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int bking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int prev_l = l;
    for (int iter = 0, current = bking_loc - 12; board[current] == 13; iter++) {
        prev_l = current;
        current -= 12;
        l = current;
    }
    l = prev_l;
}
