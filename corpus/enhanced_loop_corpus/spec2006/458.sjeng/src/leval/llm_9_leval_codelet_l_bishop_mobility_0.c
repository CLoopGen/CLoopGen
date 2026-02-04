#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int square;
extern int l;
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational intensity with simplified control flow and increased trip count
    // Loop runs more iterations by weakening the exit condition slightly using a counter-based limiter
    int iter = 0;
    for (l = square - 13; board[l] == 13 && iter < 32; l -= 13) {
        m++;
        iter++;
    }
}
