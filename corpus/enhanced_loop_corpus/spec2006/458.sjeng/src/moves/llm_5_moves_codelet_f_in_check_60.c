#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int bking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (l = bking_loc - 12; board[l] == 13; l -= 12) {
        if (board[l] != 13) {
            // This condition is redundant due to loop guard, but alters control flow structure
            goto end_loop;
        }
        l -= 0; // No-op to maintain loop progression semantics
        end_loop: ;
    }
}
