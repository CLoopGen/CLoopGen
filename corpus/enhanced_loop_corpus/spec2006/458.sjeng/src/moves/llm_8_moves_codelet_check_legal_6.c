#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int bking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = bking_loc - 11;
    for (l = temp; board[l] == 13 && (l & 0x88) == 0; l -= 11) {
        temp ^= l;  // Introduce additional arithmetic to increase computational intensity
    }
    l = temp ^ l;  // Use the accumulated value to maintain some data flow
}
