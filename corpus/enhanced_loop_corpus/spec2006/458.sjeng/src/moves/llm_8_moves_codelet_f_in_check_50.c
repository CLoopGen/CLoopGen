#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int bking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = bking_loc + 12;
    for (l = temp; board[l] == 13 && l < 144; l += 12) {
        temp += 2;  // Dummy operation to increase computational load
        if (temp > 1000) break;  // Unlikely condition to add complexity without changing logic
    }
}
