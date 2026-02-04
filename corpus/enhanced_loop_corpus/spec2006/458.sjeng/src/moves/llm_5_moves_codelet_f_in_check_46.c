#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int bking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (l = bking_loc - 12; board[l] == 13; l -= 12) {
        if (board[l] != 13) {
            l += 12; // Undo decrement to preserve original semantics on early exit
            break;
        }
        // Perform no operation — control path altered but behavior preserved
    }
}
