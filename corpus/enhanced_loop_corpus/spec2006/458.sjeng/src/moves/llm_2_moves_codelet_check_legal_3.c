#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int bking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element, but maintain logic equivalence by checking bounds and adjusting step)
    int stride = 2;
    for (l = bking_loc + 1; l < 144 && board[l] == 13; l += stride) {
        // Ensure we don't skip past the condition prematurely; check intermediate elements if needed
        int next = l + 1;
        if (next < 144 && board[next] != 13) {
            l = next;
            break;
        }
    }
    // Adjust final value of l to match original semantics (point to first non-13 or out-of-bound)
    while (l < 144 && board[l] == 13) {
        l++;
    }
}
