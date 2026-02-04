#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int wking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (l = wking_loc - 12; board[l] == 13; l -= 12) {
        if (board[l] != 13) {
            // This condition is logically redundant due to the loop guard,
            // but introduces a control path that could be optimized away.
            goto end_loop;
        }
        l -= 0; // No-op to maintain loop progression logic
    }
end_loop:;
}
