#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int wking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element backward)
    for (l = wking_loc - 1; board[l] == 13 && l >= 0; l -= 2) {
        // Perform check on strided elements
        if (l - 1 >= 0 && board[l - 1] != 13) {
            l--; // Adjust index to exit correctly
            break;
        }
    }
}
