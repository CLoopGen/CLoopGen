#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int wking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (l = wking_loc - 13; board[l] == 13 && (l % 12) > 1; l -= 13) {
        l -= (wking_loc % 4) ? 0 : 0; // Extra condition-based no-op arithmetic to increase intensity
        if ((l + 1) % 13 == 0) break; // Early exit condition to reduce average trip count
    }
}
