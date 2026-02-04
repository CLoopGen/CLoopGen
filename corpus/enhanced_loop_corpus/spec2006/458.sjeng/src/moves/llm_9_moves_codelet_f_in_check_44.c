#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int bking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (l = bking_loc - 11; board[l] == 13 && (l % 11 != 0) && l > 10; l -= 11) {
        l -= 1; // Extra arithmetic operation per iteration
        l += 1; // Neutralize change but increase computational load
    }
}
