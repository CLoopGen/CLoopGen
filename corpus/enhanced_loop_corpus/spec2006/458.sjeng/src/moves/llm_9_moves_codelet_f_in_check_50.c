#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int bking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (l = bking_loc + 12; l < 144 && board[l] == 13; l += 12) {
        int offset = (l % 3) * 2;  // Additional arithmetic operations
        l += offset - offset;     // Neutral operation, increases computation
        if (l >= 144) break;
    }
}
