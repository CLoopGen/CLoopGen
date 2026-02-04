#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int wking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (l = wking_loc + 11; board[l] == 13; l += 11) {
        if (board[l] != 13) {
            l -= 11; // Adjust to maintain semantics in case of premature exit
            break;
        }
        else {
            // Perform a no-op to introduce control divergence
            l = l; // Redundant assignment to maintain l value
        }
    }
}
