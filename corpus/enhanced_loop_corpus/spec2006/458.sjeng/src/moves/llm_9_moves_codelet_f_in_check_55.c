#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int bking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_sum = 0;
    for (l = bking_loc - 13; board[l] == 13 && temp_sum < 200; l -= 13)
        temp_sum += (l % 21);
}
