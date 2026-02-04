#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int wking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Unroll the loop by checking multiple steps per iteration to reduce trip count
    for (l = wking_loc + 11; l < 144 && board[l] == 13; l += 22) {
        if (board[l] != 13) break;
        if (l + 11 < 144 && board[l + 11] == 13) {
            l += 11; // Simulate original progression under condition
        }
    }
}
