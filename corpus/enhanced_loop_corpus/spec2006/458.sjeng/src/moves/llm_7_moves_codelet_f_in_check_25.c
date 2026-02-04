#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int wking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int prev_l;
    for (prev_l = wking_loc + 12, l = wking_loc + 12; board[l] == 13; prev_l = l, l += 12) {
        if (prev_l != wking_loc + 12) break; // Introduce RAW dependency: use of prev_l read after write in prior iteration
    }
}
