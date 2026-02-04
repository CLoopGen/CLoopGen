#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int bking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access with Offset Unrolling
    int temp = bking_loc + 12;
    for (l = temp; board[l] == 13; ) {
        l += 12;
        // Simulate consecutive access pattern by prefetching next candidate
        if (l < 144 && board[l] != 13) break;
    }
}
