#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int wking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access (unrolled and accessed with stride of 1)
    int temp = wking_loc + 13;
    for (l = temp; board[l] == 13; ) {
        l++;
        if (board[l] != 13) break;
        l++;
        if (board[l] != 13) break;
        l++;
        if (board[l] != 13) break;
        l += 10; // Adjust to maintain approximate original stride pattern over unrolled steps
    }
}
