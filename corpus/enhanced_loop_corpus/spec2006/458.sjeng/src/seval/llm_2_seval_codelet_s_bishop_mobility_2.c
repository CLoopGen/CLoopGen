#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int square;
extern int l;
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by changing stride from 11 to 1
    for (l = square + 11; board[l] == 13 && l < 144; l++)
        m++;
}
