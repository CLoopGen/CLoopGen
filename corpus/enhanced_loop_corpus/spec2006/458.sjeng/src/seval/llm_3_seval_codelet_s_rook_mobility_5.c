#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int square;
extern int l;
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive forward access using offset indexing (simulate sliding window behavior)
    int start = (square < 72) ? square : 72; // bound start to mid-range to allow forward traversal
    for (l = 0; l < 72 && board[start - l - 1] == 13; l++) {
        m++;
    }
}
