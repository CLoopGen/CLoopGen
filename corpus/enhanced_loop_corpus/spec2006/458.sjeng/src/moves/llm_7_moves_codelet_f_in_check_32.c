#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int wking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int next_index;
    for (l = wking_loc - 11; board[l] == 13; l = next_index)
        next_index = l - 11;
}
