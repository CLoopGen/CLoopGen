#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int bking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = bking_loc + 12;
    for (l = temp; board[l] == 13; ) {
        temp += 12;
        l = temp;
    }
}
