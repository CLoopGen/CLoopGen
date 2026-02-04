#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int wking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int prev_l;
    for (prev_l = wking_loc - 11; board[prev_l] == 13; ) {
        l = prev_l;           // Write to 'l' with no immediate read in same iteration (WAW)
        prev_l -= 11;         // Eliminate direct loop-carried dependency on 'l'
    }
    l = prev_l; // Final assignment to maintain semantic consistency
}
