#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int wking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int prev_l;
    for (prev_l = wking_loc + 1, l = wking_loc + 1; board[l] == 13; prev_l = l, l += 1) {
        // Introduce RAW dependency: `prev_l` used in update expression depends on previous `l`
        if (board[prev_l] != 13) break;
    }
}
