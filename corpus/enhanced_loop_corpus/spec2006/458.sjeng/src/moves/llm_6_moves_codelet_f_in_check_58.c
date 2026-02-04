#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int bking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = bking_loc - 1;
    for (l = temp; board[l] == 13; ) {
        temp = l - 1;
        l = temp;
        if (board[l] != 13) break;
    }
}
