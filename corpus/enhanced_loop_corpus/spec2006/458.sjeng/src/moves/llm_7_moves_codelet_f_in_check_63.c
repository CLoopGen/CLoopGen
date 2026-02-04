#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int bking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int next_index = bking_loc + 13;
    for (l = next_index; board[l] == 13; ) {
        l = next_index;
        next_index += 13;
    }
}
