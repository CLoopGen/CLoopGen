#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int bking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided access with positive increment (reverse traversal using different stride pattern)
    int temp = bking_loc + 11;
    for (l = temp; board[l] == 13; l += 11)
        ;
}
