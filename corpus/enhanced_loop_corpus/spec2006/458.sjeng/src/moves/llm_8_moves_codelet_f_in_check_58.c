#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int bking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (l = bking_loc - 1; board[l] == 13 && (l % 2 == 0 || board[l-1] != 13); l -= (l % 3 == 0 ? 2 : 1)) {
        if (board[l - 1] == 13) {
            l--; // Extra decrement under condition to increase arithmetic and conditional checks
        }
    }
}
