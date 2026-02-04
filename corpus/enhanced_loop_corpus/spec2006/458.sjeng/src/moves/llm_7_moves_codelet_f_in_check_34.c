#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int wking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int prev_l = wking_loc;
    for (l = wking_loc + 1; board[l] == 13; prev_l = l, l++) {
        // Introduce RAW (read-after-write) dependency: 'prev_l' is read in next iteration's update
        // Loop-carried dependency via 'prev_l': current value of 'l' saved for potential use (even if unused here)
    }
    // This adds a data dependency chain across iterations through 'prev_l'
}
