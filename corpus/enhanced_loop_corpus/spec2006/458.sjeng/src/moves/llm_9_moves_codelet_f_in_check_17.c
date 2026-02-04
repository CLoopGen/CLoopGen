#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int wking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = 13;
    for (l = wking_loc - step; board[l] == 13 && l > step; l -= step)
        __builtin_prefetch(&board[l - step], 0, 1);
}
