#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int wking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access (unrolled and accessed with +1 stride)
    int temp = wking_loc + 11;
    for (; board[temp] == 13 && board[temp + 1] == 13; temp += 2) {
        // Simulate strided logic using consecutive checks
        if (board[temp] != 13) break;
        l = temp;
        temp -= 1; // Adjust to maintain pattern
    }
    l = temp - ((temp > wking_loc + 11) ? 2 : 0);
}
