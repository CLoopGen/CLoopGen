#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int wking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (l = wking_loc - 11; board[l] == 13; l -= 11) {
        if (board[l] != 13) {
            // This condition is logically redundant due to loop guard, but introduces control path
            break;
        }
        // Proceed normally — no-op to maintain structure
    }
}
