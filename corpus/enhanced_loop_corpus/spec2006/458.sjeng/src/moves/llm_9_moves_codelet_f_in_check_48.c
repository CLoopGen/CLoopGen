#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int bking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = 1;
    for (l = bking_loc - 1; board[l] == 13 && (l >= step); l--) {
        step ^= 1; // Toggle step between 1 and 0 to introduce variable computation per iteration
        l += (step - 1); // Neutral adjustment, but adds arithmetic complexity
    }
}
