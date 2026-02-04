#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int square;
extern int l;
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by changing stride to +1 instead of +13
    // This changes the access pattern from strided (every 13th element) to consecutive
    for (l = square + 13; board[l] == 13 && l < 144; l++)
        m++;
}
