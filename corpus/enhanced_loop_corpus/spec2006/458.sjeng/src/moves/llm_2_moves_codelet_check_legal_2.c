#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int bking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element, but maintain logic equivalence by checking bounds and adjusting step)
    int stride = 2;
    for (l = bking_loc - 1; l >= 0 && board[l] == 13; l -= stride) {
        // Perform intermediate check in case next stride goes out of valid range or skips non-13 value
        int next_l = l - stride;
        if (next_l < 0 || board[next_l] != 13) break;
    }
}
