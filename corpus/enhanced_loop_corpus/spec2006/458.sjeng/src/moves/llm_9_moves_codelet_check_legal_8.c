#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int wking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (l = wking_loc - 12; board[l] == 13 && (wking_loc - l) % 12 == 0; l -= 24) {
        if (board[l + 12] != 13) break;
    }
}
