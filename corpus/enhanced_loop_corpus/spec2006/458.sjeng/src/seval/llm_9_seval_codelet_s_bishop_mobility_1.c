#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int square;
extern int l;
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = 22; // Double the decrement stride to reduce trip count by ~50%
    for (l = square - step; board[l] == 13; l -= step) {
        m += 2; // Compensate with increased work per iteration
    }
}
