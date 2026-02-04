#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int bking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access with Offset Unrolling
    // Instead of strided access by 12, simulate consecutive access by unrolling and checking multiple positions per iteration.
    int temp_l = bking_loc + 12;
    for (; ; temp_l += 12) {
        if (board[temp_l] != 13) {
            l = temp_l;
            break;
        }
        // Add a secondary check to maintain loop structure without while
        if (board[temp_l + 12] != 13) {
            l = temp_l + 12;
            break;
        }
    }
}
