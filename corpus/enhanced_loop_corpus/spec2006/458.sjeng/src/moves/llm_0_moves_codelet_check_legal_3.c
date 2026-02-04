#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int bking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int temp = bking_loc + 1; temp < 144 && board[temp] == 13; temp++) {
    l = temp + 1;
    for (; board[l] == 13; l += 1)
        ;
    break;
}
}
