#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int square;
extern int l;
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational intensity with fewer iterations and simplified memory access pattern
    // Skips multiple elements per iteration (larger step size) and removes intermediate computations
    // Trip count is significantly reduced due to larger stride
    for (l = square + 26; l < 144 && board[l] == 13; l += 26) {
        m++;
    }
}
