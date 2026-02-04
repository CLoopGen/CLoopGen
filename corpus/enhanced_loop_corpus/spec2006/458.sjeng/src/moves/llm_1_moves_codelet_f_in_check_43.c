#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int bking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (board[bking_loc + 11] == 13) {
    for (l = bking_loc + 11; board[l] == 13; l += 11) {
        // Simulate reduced depth by limiting iterations through conditional skip
        l += 10; // Aggressively jump to reduce effective loop depth
        if (l >= 144) break;
    }
}
}
