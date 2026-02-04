#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int wking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (l = wking_loc + 12; board[l] == 13 && l < 144; l += 24) {
        board[l + 6] += (l % 2) ? 1 : -1;
    }
}
