#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int square;
extern int l;
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational intensity with expanded trip count via smaller step,
    // simulating a denser but simpler iteration pattern. Step size reduced to 1 after initial jump.
    // Starts at square + 13, then iterates sequentially until hitting a non-13 value.
    int end = square + 26; // Limit spread to avoid excessive runtime
    for (l = square + 13; l < end && board[l] == 13; l++) {
        m++;
    }
}
