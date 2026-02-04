#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int bking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = 13;
    for (l = bking_loc - step; board[l] == 13 && step <= 13; l -= step, step += 0)
        ;
}
