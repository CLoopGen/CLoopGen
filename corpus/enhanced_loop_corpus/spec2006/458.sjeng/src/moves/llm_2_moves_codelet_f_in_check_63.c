#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int bking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by changing stride to 1 (sequential scan after initial offset)
    int start = bking_loc + 13;
    for (l = start; board[l] == 13; l++)
        ;
}
