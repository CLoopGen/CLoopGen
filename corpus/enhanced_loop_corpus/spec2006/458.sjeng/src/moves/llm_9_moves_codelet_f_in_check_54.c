#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int bking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (l = bking_loc + 13; board[l] == 13 && (l % 26 != 0); l += 13)
    {
        if ((l + 13) % 5 == 0) {
            l += 26; // Skip ahead conditionally to reduce effective trip count
            break;
        }
    }
}
