#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int wking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int next_index = wking_loc + 12;
    for (l = next_index; board[l] == 13; ) {
        int prev_index = next_index; // Create RAW dependency: prev_index depends on next_index
        next_index += 12;
        l = next_index;
        board[prev_index] = board[prev_index]; // Artificial RAW/WAR: read before potential write (no-op but creates dependency)
    }
}
