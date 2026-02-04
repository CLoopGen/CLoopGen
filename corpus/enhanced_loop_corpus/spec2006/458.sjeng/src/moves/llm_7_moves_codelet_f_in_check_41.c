#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int bking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int next_index = bking_loc + 13;
    for (l = next_index; board[l] == 13; next_index = l, l = next_index + 13)
        ;
    // Eliminate direct loop-carried dependency on l by using an intermediate variable
    // Introduce WAR-like pattern: next_index is read and then written in the update
}
