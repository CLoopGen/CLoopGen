#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int wking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = 11;
    int limit = wking_loc + 11 * 8; // Maximum of 8 iterations to bound complexity
    for (l = wking_loc + step; board[l] == 13 && l < limit; l += step) {
        board[l + 1] * board[l - 1]; // Dummy arithmetic to increase computational intensity
    }
}
