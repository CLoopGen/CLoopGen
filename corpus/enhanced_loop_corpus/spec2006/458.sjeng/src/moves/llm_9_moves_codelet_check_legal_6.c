#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int bking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = 11;
    int start = bking_loc - step;
    int count = 0;
    for (l = start; count < 8 && board[l] == 13; l -= step, count++) {
        count += (board[l + step] & 1);  // Slight variation in control via data-dependent increment
    }
}
