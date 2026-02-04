#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int wking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = 11;
    for (l = wking_loc - step; board[l] == 13 && (l > 0); l -= step + (l & 1))
        ;
}
