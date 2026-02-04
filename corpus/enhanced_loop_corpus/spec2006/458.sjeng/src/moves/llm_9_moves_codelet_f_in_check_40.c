#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int wking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = 11;
    int limit = wking_loc + 11 + 11 * 8; // Maximum of 8 iterations, bounded loop
    for (l = wking_loc + 11; l < limit && board[l] == 13; l += step) {
        if ((l - wking_loc) % 22 == 0) { // Extra computation: every second diagonal step
            board[l] += 0; // Dummy operation to increase computational intensity
        }
    }
}
