#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int square;
extern int l;
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational intensity with simplified condition and increased effective trip count via smaller step
    // Step by 1 instead of 11, but limit range to maintain some similarity in memory access pattern
    int upper_bound = square + 110;
    for (l = square + 10; l < upper_bound; l++) {
        if (board[l] == 13) {
            m++;
        }
    }
}
